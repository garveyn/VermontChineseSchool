#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

#include "course.h"
#include "person.h"
#include "student.h"
#include "teacher.h"
#include "linkedlist.h"

using namespace std;

enum ERR_CODE { INVALID_SELECTION = 1, INVALID_LOGIN };

const string MSG[] = { "", "Invalid Selection", "Invalid Login" };

const string USER_FILE = "./data/users.txt";	// username and password on one line separated by a space and followed by new line
const string TEACHER_FILE = "./data/teachers.txt";
const string COURSE_NAMES_FILE = "./data/courseNames.txt";

const string COURSE_TO_DELETE = "DELETE_COURSE";

const int NUMBER_OF_USERS = 2;	// the first user is the principle and the second user is the administrator


void displayMessage(int code);
void welcome();
void mainMenu();
char getChoice();
void courseMenu();
bool processCourseChoice(char choice, Course* courses, LinkedList teachers, int numberOfCourses);
void teacherMenu();
bool processTeacherChoice(char choice, LinkedList& teachers);
void studentMenu();
bool processStudentChoice(char choice, Course* courses, LinkedList teachers, int numberOfCourses);

void loadTeacher(LinkedList& teachers);
int getNumberOfCourses();
void loadCourse(Course* courses, int numberOfCourses);
void storeTeacher(LinkedList& teachers);
void storeCourse(Course* courses, int numberOfCourses);

void loadUser(string users[]);
bool login(string users[]);
void changePrinciple(string users[]);
void changeAdministrator(string users[]);
void storeUser(string users[]);

//courses functions

void addCourse(Course* courses, LinkedList teachers, int &courseInArray);
Course searchCourse(Course* courses, int coursesInArray);
void removeCourse(Course courseToRemove, Course* courses, int &coursesInArray);
void updateCourse(Course courseToUpdate, Course* courses, LinkedList teachers, int coursesInArray);
Course* shrinkCourseArray(Course* courses, int numberOfCourses);
Course* expandCourseArray(Course* courses, int numberOfCourses);

void snowDay(Course* courses, int coursesInArray, LinkedList teachers);

void pause();
void clearScreen();

#endif
