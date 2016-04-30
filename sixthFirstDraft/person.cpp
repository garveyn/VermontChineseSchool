#include "person.h"

int Person::mCount = 0;

Person::Person()
{
	mName = "";
	mID = "";
	mPhoneNum = "";
	mEmail = "";
	mCourseName = "";
}

Person::~Person()
{
}

string Person::getName()
{
	return mName;
}

string Person::getID()
{
	return mID;
}

string Person::getPhoneNum()
{
	return mPhoneNum;
}

string Person::getEmail()
{
	return mEmail;
}

string Person::getCourseName()
{
	return mCourseName;
}

void Person::setName(string newValue)
{
	mName = newValue;
}

void Person::setID(string newValue)
{
	mID = newValue;
}

void Person::setPhoneNum(string newValue)
{
	mPhoneNum = newValue;
}

void Person::setEmail(string newValue)
{
	mEmail = newValue;
}

void Person::setCourseName(string newValue)
{
	mCourseName = newValue;
}

ifstream &operator>>(ifstream &finput, Person &person)
{
	person.mCount++;

	string garbage, name, email, phoneNum, ID, courseName;

	getline(finput, name);
	getline(finput, email);
	getline(finput, phoneNum);
	getline(finput, courseName);

	person.setName(name);
	person.setEmail(email);
	person.setPhoneNum(phoneNum);
	person.setCourseName(courseName);

	stringstream ss;
	ss << setw(7)
		<< setfill('0')
		<< person.mCount;
	ID = ss.str();
	person.setID(ID);

	return finput;

}

istream &operator>>(istream &cinput, Person &person)
{
	string garbage, name, email, phoneNum, ID, courseName;

	person.mCount++;

	cout << endl << "Please enter the name: ";
	getline(cinput, name);

	cout << endl << "Please enter the email: ";
	getline(cinput, email);

	cout << endl << "Please enter the phone number: ";
	getline(cinput, phoneNum);

	cout << endl << "Please enter the course name: ";
	getline(cinput, courseName);


	person.setName(name);
	person.setEmail(email);
	person.setPhoneNum(phoneNum);
	person.setCourseName(courseName);

	stringstream ss;
	ss << setw(7)
		<< setfill('0')
		<< person.mCount;
	ID = ss.str();
	person.setID(ID);

	return cinput;
}


ofstream &operator<<(ofstream &foutput, Person person)
{
	foutput << person.getName() << endl
		<< person.getPhoneNum() << endl
		<< person.getEmail() << endl
		<< person.getCourseName() << endl;

	return foutput;
}

ostream &operator<<(ostream &coutput, Person person)
{
	coutput << "Name: " << person.getName() << endl
		<< "ID: " << person.getID() << endl
		<< "Phone Number: " << person.getPhoneNum() << endl
		<< "Email: " << person.getEmail() << endl
		<< "Course Name: " << person.getCourseName() << endl;

	return coutput;
}

bool Person::operator==(string id)
{
	bool isEqual = false;

	if (id == mID)
		isEqual = true;

	return isEqual;
}

bool operator==(string id, Person person)
{
	bool isEqual = false;

	if (id == person.getID())
		isEqual = true;

	return isEqual;
}
