#include "course.h"


Course::Course()
{

}

Course::Course(string courseName, string teacher, int studentCount)
{
	mCourseName = courseName;
	mTeacher = teacher;
	mStudentCount = studentCount;
}

Course::~Course()
{

}


int Course::getStudentCount()
{
	return mStudentCount;
}

string Course::getCourseName()
{
	return mCourseName;
}

string Course::getTeacher()
{
	return mTeacher;
}




void Course::setArrayOfStudents(Student newStudentArray[STUDENTS_PER_COURSE])
{
	//just make sure that if you're adding a student, you increment mStudentCount first -T
	for (int u = 0; u < STUDENTS_PER_COURSE; u++)
	{
		mStudents[u] = newStudentArray[u];
	}
}

void Course::setStudentCount(int newValue)
{
	mStudentCount = newValue;
}

void Course::setCourseName(string newValue)
{
	mCourseName = newValue;
}

void Course::setTeacher(string newValue)
{
	newValue = mTeacher; //We're assuming that this has already been validated - Talon (wrote this)
}

void Course::searchStudentName(string name) //T
{
	//just print off the names and ID's of all students you find. This will be followed up by search by ID to confirm
	//this function will loop through single course, front end calls the loop of all courses

	Student tempArray[STUDENTS_PER_COURSE]; //if we have over 30 students with the same name, something is wrong.
	int tempCounter = 0;



	for (int t = 0; t <= mStudentCount; t++)
	{
		if (name == mStudents[t].getName())
		{
			tempArray[tempCounter] = mStudents[t];
			tempCounter++;
		}
		if (t == mStudentCount && tempCounter == 0) //if we reach the end of the array and don't find a matching name.
		{
			cout << "I'm sorry, but no student was found who matches that description." << endl;
		}
	}

	if (tempCounter != 0)
	{
		cout << "These are the students found with the same name: \n";
		for (int m = 0; m < tempCounter; m++)
		{
			cout << tempArray[m].getName() << "\n" << tempArray[m].getID() << endl;
		}
	}


}

void Course::displayAllStudents()
{

}


bool Course::operator==(Course rhs)
{
	return mCourseName == rhs.mCourseName;
}

bool Course::operator==(string rhs)
{
	return mCourseName == rhs;
}

bool operator==(string lhs, Course rhs)
{
	return lhs == rhs.mCourseName;
}

void Course::operator=(Course rhs)
{
	mCourseName = rhs.mCourseName;
	mTeacher = rhs.mTeacher;
	mStudentCount = rhs.mStudentCount;
	for (int i = 0; i < STUDENTS_PER_COURSE; i++)
	{
		mStudents[i] = rhs.mStudents[i];
	}
}

ifstream& operator >> (ifstream& input, Course& course) //Talon
{
	string trash, courseName, teacher;
	int studentCount;
	Student student[STUDENTS_PER_COURSE];

	getline(input, courseName);
	getline(input, teacher);
	input >> studentCount;

	if (studentCount > 30)//if statement for over 30 don't do the for loop - T
	{
		cout << "I'm sorry, but there are too many students in this course. Please contact your systems administrator." << endl;
	}
	else
	{
		getline(input, trash);
		for (int k = 0; k < studentCount; k++) //reads in all the students for the course
		{
			input >> student[k];
		}
	}

	course = Course(courseName, teacher, studentCount); //sets up the new course with all it's info.
	course.setArrayOfStudents(student);

	return input;
}

istream& operator >> (istream& input, Course &course)
{
	string junk, courseName, teacher;
	int studentCount;
	Student students[STUDENTS_PER_COURSE];
	cout << endl << "Please enter the name of the course: ";
	getline(input, courseName);
	course.setCourseName(courseName);

	cout << endl << "Please enter the teacher's name: ";
	getline(input, teacher);
	course.setTeacher(teacher);

	cout << endl << "Please enter the number of students in the course: ";
	input >> studentCount;
	getline(input, junk);
	course.setStudentCount(studentCount);


	for (int i = 0; i < studentCount; i++)
	{
		input >> students[i];
	}

	return input;

}



ostream& operator<<(ostream& output, Course course)
{
	output << course.mCourseName << "\n" << course.mTeacher << "\n" << course.mStudentCount << "\n";

	for (int j = 0; j < course.mStudentCount; j++)
	{
		output << course.mStudents[j] << "\n";
	}

	return output;
}

ofstream& operator <<(ofstream& output, Course course)
{

	output << course.mCourseName << endl
		<< course.mTeacher << endl
		<< course.mStudentCount << endl;

	for (int j = 0; j < course.mStudentCount; j++)
	{
		output << course.mStudents[j];
	}

	return output;
}


void Course::deleteStudent()
{
	Student tmp;
	string studentName, studentID;

	cout << endl << "Please enter the name of the student to be deleted: ";
	getline(cin, studentName);

	searchStudentName(studentName);

	//validate for studentID and name
	do
	{
		cout << endl << "Please enter the ID for the student to be deleted: ";
		getline(cin, studentID);

		tmp = searchStudentID(studentID);

		if (tmp == "-1")
			cout << "Error, ID not found!";

		if (tmp.getName() != studentName || tmp.getID() != studentID)
			cout << "Error, student name and ID do not correspond!";

	} while (tmp == "-1" || (tmp.getName() != studentName || tmp.getID() != studentID));


	for (int i = 0; i < STUDENTS_PER_COURSE; i++)
	{
		if (studentID == mStudents[i] && studentName == mStudents[i])
		{

			for (int j = i; j < STUDENTS_PER_COURSE - 1; j++)
			{
				mStudents[j] = mStudents[j + 1];
			}

			cout << endl << "Student found and was deleted successfully!";
		}
	}

	return;
}

Student Course::searchStudentID(string searchKey)
{
	Student studentFound;
	studentFound.setID("-1");

	for (int i = 0; i < STUDENTS_PER_COURSE; i++)
	{
		if (searchKey == mStudents[i])
			studentFound = mStudents[i];
	}

	return studentFound;
}

Student Course::addStudent()
{
	Student newStudent;
	cout << "Please enter the information for the new student " << endl;
	cin >> newStudent;
	mStudentCount++;
	mStudents[mStudentCount] = newStudent;
	return newStudent;
}

Student Course::updateStudent()
{
	string name, id, junk;
	Student studentToModify;
	bool continueOn;
	char choice;

	do
	{
		continueOn = true;

		cout << "Please enter the name of the student you wish to modify: ";
		getline(cin, name);
		cout << endl;

		searchStudentName(name);

		cout << endl << endl << "Enter ID of the correct student to modify: ";
		getline(cin, id);

		studentToModify = searchStudentID(id);

		if (studentToModify == "-1")
		{
			cout << "ID entered is not valid..." << endl; // What is the error code system? 
			continueOn = false;
		}
	} while (!continueOn); // this assumes now that the correct student has been found. 

	do
	{
		continueOn = false;

		cout << "Which would you like to update? (you can come back to this screen)" << endl
			<< "  n. Student's name" << endl
			<< "  p. Student's Phone number" << endl
			<< "  e. Student's Email" << endl
			<< "  c. Emergency Contact's info" << endl
			<< "  x. Nothing else" << endl << endl
			<< "Choice: ";

		cin >> choice;
		getline(cin, junk);

		switch (choice)
		{
		case 'n':
		case 'p':
		case 'e':
		case 'c':
		case 'N':
		case 'P':
		case 'E':
		case 'C':
			updateStudentBackend(choice, studentToModify);
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

	return studentToModify;
}


void Course::updateStudentBackend(char choice, Student& studentToModify)
{
	string newValue;
	emergencyContact tmp;
	switch (choice)
	{
	case 'n':
	case 'N':
		cout << "Please enter a new name for " << studentToModify.getName() << ": ";
		getline(cin, newValue);
		studentToModify.setName(newValue);
		break;
	case 'p':
	case 'P':
		cout << "Please enter a new phone number for " << studentToModify.getName() << ": ";
		getline(cin, newValue);
		studentToModify.setPhoneNum(newValue);
		break;
	case 'e':
	case 'E':
		cout << "Please enter a new email for " << studentToModify.getName() << ": ";
		getline(cin, newValue);
		studentToModify.setEmail(newValue);
		break;
	case 'c':
	case 'C':
		tmp = studentToModify.getEMC();
		cout << "Please enter a new emergency contact for " << studentToModify.getName() << "." << endl
			<< "  Current info  " << endl
			<< "    EC Name: " << tmp.mEMCName << endl
			<< "    EC Phone Number: " << tmp.mEMCPhone << endl
			<< "    EC Relation: " << tmp.mEMCRelations << endl << endl;

		cout << "Enter new name: ";
		getline(cin, tmp.mEMCName);

		cout << "Enter new phone number: ";
		getline(cin, tmp.mEMCPhone);

		cout << "Enter new relation: ";
		getline(cin, tmp.mEMCRelations);

		studentToModify.setEMC(tmp); // this needs to work
		break;
	}
	cout << "Information updated..." << endl;
}
