#include "header.h"

/*
Author: Michael English
*/
int main()
{
	LinkedList teachers;	// because of unknown number of substitute teachers
	loadTeacher(teachers);
	
	Course *courses;
	int numberOfCourses = getNumberOfCourses();
	courses = new Course [numberOfCourses];
	loadCourse(courses, numberOfCourses);
	
	string users [NUMBER_OF_USERS * 2];	// multiplied by 2 because need space for both username and password
	loadUser(users);
	
	welcome();
	
	char choice;
	bool exitOuterLoop, exitMiddleLoop, exitInnerLoop;
	
	do
	{
		exitOuterLoop = false;
		
		if (!login(users))
		{
			break;	// to immediately exit the outer loop
		}
		
		do
		{
			exitMiddleLoop = false;
			
			mainMenu();
			choice = getChoice();
			
			if (choice == 'C' || choice == 'c')
			{
				exitInnerLoop = false;
				
				do
				{
					courseMenu();
					choice = getChoice();
					
					if (!processCourseChoice(choice, courses, teachers, numberOfCourses))
					{
						exitInnerLoop = true;
					}
					
				} while (!exitInnerLoop);
			}
			else if (choice == 'T' || choice == 't')
			{
				exitInnerLoop = false;
				
				do
				{
					teacherMenu();
					choice = getChoice();
					
					if (!processTeacherChoice(choice, teachers))
					{
						exitInnerLoop = true;
					}
					
				} while (!exitInnerLoop);
			}
			else if (choice == 'S' || choice == 's')
			{
				exitInnerLoop = false;
				
				do
				{
					studentMenu();
					choice = getChoice();
					
					if (!processStudentChoice(choice, courses, teachers, numberOfCourses))
					{
						exitInnerLoop = true;
					}
					
				} while (!exitInnerLoop);
			}
			else if (choice != 'L' && choice != 'l' && choice != 'Q' && choice != 'q')
			{
				displayMessage(INVALID_SELECTION);
			}
			
			if (choice == 'L' || choice == 'l' || choice == 'Q' || choice == 'q')
			{
				exitMiddleLoop = true;
			}
			
		} while (!exitMiddleLoop);
		
		if (choice == 'Q' || choice == 'q')
		{
			exitOuterLoop = true;
		}
		
	} while (!exitOuterLoop);
	
	storeUser(users);
	storeTeacher(teachers);
	storeCourse(courses, numberOfCourses);
	
	delete [] courses;
	
	return 0;
}
