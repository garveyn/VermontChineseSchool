#include "header.h"

/*
Author: Michael English
*/
void displayMessage(int code)
{
	cout << MSG[code] << endl;
}

/*
Author: Michael English
*/
void welcome()
{
	cout << "Welcome to Vermont Chinese School" << endl;
	cout << endl;
}

/*
Author: Michael English
*/
void mainMenu()
{
	cout << endl;
	cout << "Course operations: C" << endl;
	cout << "Teacher operations: T" << endl;
	cout << "Student operations: S" << endl;
	cout << "Log out: L" << endl;
	cout << "Shut down: Q" << endl;
	cout << endl;
}

/*
Author: Michael English
*/
char getChoice()
{
	string input;
	bool valid = false;

	do
	{
		cout << "Enter your choice: ";
		getline(cin, input);

		if (input.length() != 1)
		{
			displayMessage(INVALID_SELECTION);
		}
		else if (!isalpha(input[0]))
		{
			displayMessage(INVALID_SELECTION);
		}
		else
		{
			valid = true;
		}
	} while (!valid);

	char choice = input[0];

	return choice;
}

/*
Author: Michael English
*/
void courseMenu()
{
	cout << endl;
	cout << "Add Course: A" << endl;
	cout << "Remove Course: R" << endl;
	cout << "Update Course Information: U" << endl;
	cout << "Display Course Information: D" << endl;
	cout << "Back to main menu: B" << endl;
	cout << "Log out: L" << endl;
	cout << "Shut down: Q" << endl;
	cout << endl;
}

/*
Author: Michael English
*/
bool processCourseChoice(char choice, Course* courses, LinkedList teachers, int numberOfCourses)
{
	Course tmp;
	switch (choice)
	{
	case 'A':
	case 'a':
		addCourse(courses, teachers, numberOfCourses);
		break;
	case 'R':
	case 'r':
		tmp = searchCourse(courses, numberOfCourses);
		if (tmp.getCourseName() == COURSE_TO_DELETE)
		removeCourse(tmp, courses, numberOfCourses);
		break;
	case 'U':
	case 'u':
		tmp = searchCourse(courses, numberOfCourses);
		updateCourse(tmp, courses, teachers, numberOfCourses);
		break;
	case 'D':
	case 'd':
		tmp = searchCourse(courses, numberOfCourses);
		cout << tmp;
		break;
	case 'B':
	case 'b':
	case 'L':
	case 'l':
	case 'Q':
	case 'q':
		return false;
	default:
		displayMessage(INVALID_SELECTION);
		break;
	}
	
	return true;
}

/*
Author: Michael English - edited by Talon Birns
*/
void teacherMenu()
{
	cout << endl;
	cout << "Search Teacher: S" << endl;
	cout << "Back to main menu: B" << endl;
	cout << "Log out: L" << endl;
	cout << "Shut down: Q" << endl;
	cout << endl;
	//still need add, remove, update
}

/*
Author: Michael English - edited by Talon Birns
*/
bool processTeacherChoice(char choice, LinkedList& teachers)
{
	string tempName;
	switch (choice)
	{
	case 'S':
	case 's':
		cout << "What is the name of the teacher you wish to search? " << endl;
		getline(cin, tempName);
		teachers.searchPrintTeacherName(tempName);
		break;
	case 'B':
	case 'b':
	case 'L':
	case 'l':
	case 'Q':
	case 'q':
		return false;
	default:
		displayMessage(INVALID_SELECTION);
		break;
	}

	return true;
}

/*
Author: Michael English
*/
void studentMenu()
{
	cout << endl;
	cout << "Search Student: S" << endl;
	cout << "Update Student: U" << endl;
	cout << "Contact All Students: C" << endl;
	cout << "Back to main menu: B" << endl;
	cout << "Log out: L" << endl;
	cout << "Shut down: Q" << endl;
	cout << endl;
}

bool processStudentChoice(char choice, Course *courses, LinkedList teachers, int numberOfCourses)
{
	string tempName;

	switch (choice)
	{
	case 'S':
	case 's':
		cout << "What is the name of the student you wish to find? " << endl;
		getline(cin, tempName);
		courses->searchStudentName(tempName);
		break;

	case 'U':
	case 'u':
		courses->updateStudent();
		break;

	case 'C':
	case 'c':
		for (int i = 0; i < numberOfCourses; i++)
		{
			courses[i];
		}

	case 'B':
	case 'b':
	case 'L':
	case 'l':
	case 'Q':
	case 'q':
		return false;
	default:
		displayMessage(INVALID_SELECTION);
		break;
	}

	return true;
}

void loadTeacher(LinkedList& teachers)
{
	ifstream fin;
	Teacher temp;
	fin.open(TEACHER_FILE);
	if (!fin.fail())
	{
		while (!fin.eof())
		{
			fin >> temp;
			if (temp.getName() == "") // incase the last line is blank
			{
				break;
			}
			teachers.addTeacher(temp);
		}
	}
	else
	{
		cout << "Teacher File not found." << endl;
	}
}

int getNumberOfCourses()
{
	int numberOfCourses = 0;
	ifstream fin;
	string courseName;
	fin.open(COURSE_NAMES_FILE);

	if (!fin.fail())
	{
		while (!fin.eof())
		{
			getline(fin, courseName);
			numberOfCourses++;
		}
	}
	else
		cout << endl << "No Course Name data file found.";

	return numberOfCourses;
}

void loadCourse(Course* courses, int numberOfCourses) //Rosser
{
	Course tmp;
	ifstream fin, finName;
	string garbage, courseName;

	fin.open(COURSE_NAMES_FILE);

	if (!fin.fail())
	{
		for (int i = 0; i < numberOfCourses; i++)
		{
			getline(fin, courseName);
			courseName = "./data/" + courseName + ".txt";

			finName.open(courseName);

			if (!finName.fail())
			{
				finName >> tmp;
				courses[i] = tmp;
			}

			finName.close();
		}
	}
	else
	{
		cout << endl << "No courseName data file found." << endl;
	}

	fin.close();

}

void storeTeacher(LinkedList& teachers)
{
	ofstream fout;
	fout.open(TEACHER_FILE);
	for (int i = 0; i < teachers.getCount(); i++)
	{
		fout << teachers.getTeacherFromIndex(i);
	}
}

void storeCourse(Course* courses, int numberOfCourses)
{
	Course tmp;
	ifstream fin;
	ofstream fout;
	string garbage, courseName;

	fin.open(COURSE_NAMES_FILE);

	if (!fin.fail())
	{
		for (int i = 0; i < numberOfCourses; i++)
		{
			getline(fin, courseName);
			courseName = "./data/" + courseName + ".txt";

			fout.open(courseName);

			if (!fout.fail())
			{
				fout << courses[i];
			}

			fout.close();
		}
	}
	else
	{
		cout << endl << "No courseName data file found.";
	}

	fin.close();

}

/*
Author: Michael English
*/
void loadUser(string users[])
{
	ifstream fin;
	fin.open(USER_FILE.c_str());

	if (!fin.fail())
	{
		string username, password;
		int count = 0;

		fin >> username >> password;

		while (count < NUMBER_OF_USERS * 2)
		{
			users[count] = username;
			users[count + 1] = password;

			fin >> username >> password;

			count += 2;
		}
	}

	fin.close();
}

/*
Author: Michael English
*/
bool login(string users[])
{
	string username, password;
	bool valid = false;

	do
	{
		cout << "Username: ";
		cin >> username;

		cout << "Password: ";
		cin >> password;
		cin.ignore();

		if (username == users[0] && password == users[1])
		{
			valid = true;
		}
		else if (username == users[2] && password == users[3])
		{
			bool exit = false;

			do
			{
				cout << endl;
				cout << "Change principle username and password: P" << endl;
				cout << "Change administrator username and password: A" << endl;
				cout << "Log out: L" << endl;
				cout << "Shut down: Q" << endl;
				cout << endl;

				char choice = getChoice();

				switch (choice)
				{
				case 'P':
				case 'p':
					changePrinciple(users);
					break;
				case 'A':
				case 'a':
					changeAdministrator(users);
					break;
				case 'L':
				case 'l':
					exit = true;
					break;
				case 'Q':
				case 'q':
					return false;
				default:
					displayMessage(INVALID_SELECTION);
					break;
				}
			} while (!exit);
		}
		else
		{
			displayMessage(INVALID_LOGIN);
		}

	} while (!valid);

	return true;
}

/*
Author: Michael English
*/
void changePrinciple(string users[])
{
	string newUsername, newPassword;

	cout << "New username: ";
	cin >> newUsername;

	cout << "New password: ";
	cin >> newPassword;
	cin.ignore();

	users[0] = newUsername;
	users[1] = newPassword;
}

/*
Author: Michael English
*/
void changeAdministrator(string users[])
{
	string newUsername, newPassword;

	cout << "New username: ";
	cin >> newUsername;

	cout << "New password: ";
	cin >> newPassword;
	cin.ignore();

	users[2] = newUsername;
	users[3] = newPassword;
}

/*
Author: Michael English
*/
void storeUser(string users[])
{
	ofstream fout;
	fout.open(USER_FILE.c_str());

	for (int i = 0; i < NUMBER_OF_USERS * 2; i += 2)
	{
		fout << users[i] << " " << users[i + 1] << endl;
	}

	fout.close();
}

void addCourse(Course * courses, LinkedList teachers, int & courseInArray)
{
	Course tempCourse;
	Student tempStudent, tempStudentArr[STUDENTS_PER_COURSE];
	string teacher;

	do
	{
		cout << endl << "Please enter the teacher's name: ";
		getline(cin, teacher);

	} while (!teachers.doesTeacherExist(teacher));

	tempCourse.setTeacher(teacher);
	cout << "Please enter the information for the Course you would like to add." << endl;
	cin >> tempCourse; //gets the course information

	tempCourse.setArrayOfStudents(tempStudentArr); //sets the temporary array of students to mStudents

	courseInArray++; // increases the number of courses we have

	expandCourseArray(courses, courseInArray); //makes the array of courses bigger to fit the new course

	for (int j = 0; j < courseInArray; j++) //this goes to the end of the now bigger array
	{
		if (j == courseInArray)
		{
			courses[j] = tempCourse; // sets the new course to the last position in the array.
		}
	}


}


Course searchCourse(Course * courses, int coursesInArray)
{
	cout << "What is the course name you would like to seach? " << endl;
	string answer;
	Course temp;
	getline(cin, answer);
	bool  checker = true;
	for (int i = 0; i < coursesInArray; i++)
	{
		if (courses[i] == answer)
		{
			temp = courses[i];
			checker = false;
		}
	}
	if (checker)
	{
		cout << "The course does not exist " << endl;
		temp.setCourseName(COURSE_TO_DELETE);
	}

	return temp;
}


void removeCourse(Course courseToRemove, Course * courses, int &coursesInArray)
{
	for (int i = 0; i < coursesInArray; i++)
	{
		if (courses[i] == courseToRemove)
		{
			courses[i].setCourseName(COURSE_TO_DELETE);
			coursesInArray--;
			courses = shrinkCourseArray(courses, coursesInArray);
		}
	}
}

void updateCourse(Course courseToUpdate, Course* courses, LinkedList teachers, int coursesInArray)
{
	string originalName, newValue, junk;
	bool continueOn;
	char choice;

	do
	{
		continueOn = false;

		cout << "Which would you like to update? (you can come back to this screen)" << endl
			<< "  n. Course Name" << endl
			<< "  t. Course Teacher" << endl
			<< "  x. Nothing else" << endl << endl
			<< "Choice: ";

		cin >> choice;
		getline(cin, junk);

		switch (choice)
		{
		case 'n':
		case 'N':
			cout << "Please enter a new name for " << courseToUpdate.getCourseName() << ": ";
			getline(cin, newValue);
			courseToUpdate.setCourseName(newValue);
			break;
		case 't':
		case 'T':
			cout << "Please enter a new teacher name for " << courseToUpdate.getCourseName() << ": ";
			getline(cin, newValue);
			if (teachers.doesTeacherExist(newValue))
				courseToUpdate.setCourseName(newValue);
			else
				cout << "This teacher does not exsist...";
			break;
		case 'x':
		case 'X':
			continueOn = true;
			break;
		default:
			cout << "Invalid choice..." << endl;
			break;
		}
	} while (!continueOn);
}

Course* shrinkCourseArray(Course* courses, int numberOfCourses)
{
	Course *newCourses;
	newCourses = new Course[numberOfCourses];

	int i = 0, j = 0;
	for (i = 0; i < numberOfCourses + 1; i++)
	{
		if (!(courses[i] == COURSE_TO_DELETE))
		{
			newCourses[j] = courses[i];
			j++;
		}		
	}
	

	return newCourses;
}

Course* expandCourseArray(Course* courses, int numberOfCourses)
{
	Course *newCourses;
	newCourses = new Course[numberOfCourses];

	int i;
	for (i = 0; i < numberOfCourses - 1; i++)
	{
			newCourses[i] = courses[i];
	}

	return newCourses;
}

void snowDay(Course* courses, int coursesInArray, LinkedList teachers)
{
	
}

void pause()
{
	system("pause");
}

void clearScreen()
{
	system("CLS");
}