#ifndef TEACHER_H
#define TEACHER_H

#include "person.h"


using namespace std;

class Teacher : public Person
{
private:
   bool mIsSub;

public:
   Teacher();
   ~Teacher();

   bool getIsSub();
   void setIsSub(bool isSub);

   ifstream friend &operator>>(ifstream &input, Teacher &teacher);
   ofstream friend &operator<<(ofstream &output, Teacher teacher);

   istream friend &operator>>(istream &input, Teacher &teacher);
   ostream friend &operator<<(ostream &output, Teacher teacher);

   bool operator==(Teacher teacher);
};

#endif