#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <fstream>
#include <string>
#include "person.h"
#include "student.h"

using namespace std;

const int STUDENTS_PER_COURSE = 30;

class Course
{
	string mCourseName, mTeacher;
	int mStudentCount;
	Student mStudents[STUDENTS_PER_COURSE];

	void updateStudentBackend(char choice, Student& studentToModify);

public:

	Course();
	Course(string courseName, string teacher, int studentCount);
	~Course();


	int getStudentCount();
	string getCourseName();
	string getTeacher();

	void setArrayOfStudents(Student newStudentArray[STUDENTS_PER_COURSE]);
	void setStudentCount(int newValue);
	void setCourseName(string newValue);
	void setTeacher(string newValue);

	//add search update remove student;
	Student addStudent();
	void deleteStudent();
	void searchStudentName(string name);
	Student searchStudentID(string ID);
	Student updateStudent();

	void displayAllStudents();

	bool operator==(Course rhs);
	bool operator==(string rhs);
	friend bool operator==(string lhs, Course rhs);

	void operator=(Course rhs);

	ifstream friend &operator>> (ifstream& input, Course& course);
	istream friend &operator>>(istream& input, Course& course);
	ostream friend &operator<<(ostream& output, Course course);
	ofstream friend &operator<<(ofstream& output, Course course);

};

#endif // !COURSE_H
