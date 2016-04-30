#include "student.h"

Student::Student() : Person()
{
	mIsAdult = false;
}

Student::~Student()
{

}

bool Student::getIsAdult()
{
	return mIsAdult;
}
emergencyContact Student::getEMC()
{
	return mEMC;
}

void Student::setIsAdult(bool isAdult)
{
	mIsAdult = isAdult;
}

void Student::setEMC(string eMCName, string eMCPhone, string eMCRelations)
{
	mEMC.mEMCName = eMCName;
	mEMC.mEMCPhone = eMCPhone;
	mEMC.mEMCRelations = eMCRelations;
}

void Student::setEMC(emergencyContact input)
{
	mEMC = input;
}

ifstream &operator >> (ifstream& input, Student &student)
{
	string garbage, eMCName, eMCPhone, eMCRelations;
	char isAdult;
	input >> static_cast<Person &>(student);

	getline(input, eMCName);
	getline(input, eMCPhone);
	getline(input, eMCRelations);
	input >> isAdult;
	if (isAdult == 't' || isAdult == 'T')
	{
		student.mIsAdult = true;
	}
	else
	{
		student.mIsAdult = false;
	}
	getline(input, garbage);

	student.mEMC.mEMCName = eMCName;
	student.mEMC.mEMCPhone = eMCPhone;
	student.mEMC.mEMCRelations = eMCRelations;


	return input;
}


istream &operator>>(istream& input, Student &student)
{
	string garbage, eMCName, eMCPhone, eMCRelations;
	bool isAdult;

	input >> static_cast<Person &>(student);

	cout << endl << "Please enter the name for the Emergency Contact: ";
	getline(input, eMCName);

	cout << endl << "Please enter the phone number for the Emergency Contact: ";
	getline(input, eMCPhone);

	cout << endl << "Please enter the relation for the Emergency Contact: ";
	getline(input, eMCRelations);

	cout << endl << "Please enter if the student is an adult: ";
	char answer;
	bool checker = true;
	do
	{
		cout << "Please input a t if the student is an adlut or an f if they are not " << endl;
		input >> answer;
		if (answer == 't' || answer == 'T')
		{
			isAdult = true;
			checker = false;
		}
		else if (answer == 'f' || answer == 'F')
		{
			isAdult = false;
			checker = false;
		}
		else
		{
			cout << "Not a valid input please try again " << endl;
		}
	} while (checker);
	getline(input, garbage);

	student.mEMC.mEMCName = eMCName;
	student.mEMC.mEMCPhone = eMCPhone;
	student.mEMC.mEMCRelations = eMCRelations;
	student.mIsAdult = isAdult;

	return input;

}

ostream &operator<<(ostream& output, Student& student)
{
	output << static_cast <Person &>(student)
		<< endl << "Emergency contact name: " << student.mEMC.mEMCName
		<< endl << "Emergency contact number: " << student.mEMC.mEMCPhone
		<< endl << "Emergency contact relation: " << student.mEMC.mEMCRelations
		<< endl << "Is emergency contact adult: " << student.mIsAdult << endl;
	return output;
}

ofstream &operator << (ofstream& output, Student& student)
{
	output << static_cast <Person &>(student)
		<< student.mEMC.mEMCName
		<< endl << student.mEMC.mEMCPhone
		<< endl << student.mEMC.mEMCRelations;
	if (student.mIsAdult)
	{
		output << endl << 't' << endl;
	}
	else
	{
		output << endl << 'f' << endl;
	}
	return output;
}
