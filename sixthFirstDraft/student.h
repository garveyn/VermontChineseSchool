#ifndef STUDENTHEADER_H
#define STUDENTHEADER_H

#include "person.h"
#include "fstream"

struct emergencyContact
{
	string mEMCName, mEMCPhone, mEMCRelations;
};

class Student : public Person
{
private:
	bool mIsAdult;
	emergencyContact mEMC;
public:
	Student();
	~Student();

	bool getIsAdult();
	emergencyContact getEMC();

	void setIsAdult(bool isAdult);
	void setEMC(string eMCName, string eMCPhone, string eMCRelations);
	void setEMC(emergencyContact input);

	ifstream friend &operator >> (ifstream& input, Student &student);
	istream friend &operator>>(istream& input, Student &student);
	ostream friend &operator<<(ostream& output, Student &student);
	ofstream friend &operator << (ofstream& output, Student &student);
};

#endif
