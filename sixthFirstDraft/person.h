#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

using namespace std;

const string DATA_FILE = "data.txt";

class Person
{
private:
	string mName, mID, mPhoneNum, mEmail, mCourseName;
	static int mCount;
public:
	Person();
	~Person();

	string getName();
	string getID();
	string getPhoneNum();
	string getEmail();
	string getCourseName();

	void setName(string newValue);
	void setID(string newValue);
	void setPhoneNum(string newValue);
	void setEmail(string newValue);
	void setCourseName(string newValue);

	bool operator==(string id);
	friend bool operator==(string id, Person person);

	friend istream &operator>>(istream &consoleInput, Person &person); //overload input for CONSOLE
	friend ifstream &operator>>(ifstream &fileInput, Person &person); //overload input for FILE
	friend ofstream &operator<<(ofstream &foutput, Person person); //overload output for FILE
	friend ostream &operator<<(ostream &coutput, Person person); //overload output for console

};

#endif // !PERSON_H
