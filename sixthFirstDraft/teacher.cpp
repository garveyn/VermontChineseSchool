#include "teacher.h"
using namespace std;

Teacher::Teacher() : Person()
{
   mIsSub = false;
}

Teacher::~Teacher()
{

}

bool Teacher::getIsSub()
{
   return mIsSub;
}

void Teacher::setIsSub(bool isSub)
{
   mIsSub = isSub;
}

ifstream &operator>>(ifstream &input, Teacher &teacher)
{
   string garbo;
   char isSub;

   input >> static_cast<Person &>(teacher);

   input >> isSub;
   if (isSub == 't' || isSub == 'T')
   {
	   teacher.mIsSub = true;
   }
   else
   {
	   teacher.mIsSub = false;
   }
   getline(input, garbo);

   return input;
}

ofstream &operator<<(ofstream& output, Teacher teacher)
{
	output << static_cast <Person &>(teacher);
	if (teacher.mIsSub)
		output << "T" << endl;
	else
		output << "F" << endl;

   return output;
}

istream &operator>>(istream &input, Teacher &teacher)
{
   string garbo, userInput;
   bool isSub;

   input >> static_cast<Person &>(teacher);

   do
   {
      cout << endl << "Please specify if this teacher is a sub (true or false): ";
      getline(cin, userInput);

      if (userInput == "true")
      {
         isSub = true;
      }

      if (userInput == "false")
      {
         isSub = false;
      }

      if (userInput != "true" && userInput != "false")
      {
         cout << endl << "Input must be true or false.";
      }
   } while ((userInput != "true" && userInput != "false"));

   teacher.setIsSub(isSub);

   return input;
}

ostream &operator<<(ostream& output, Teacher teacher)
{
   output << static_cast <Person &>(teacher)
      << "Is this Teacher a sub: " << teacher.mIsSub << endl;

   return output;
}


bool Teacher::operator==(Teacher teacher)
{
   bool isSame;
   if (getName() == teacher.getName())
   {
      if (getID() == teacher.getID())
         isSame = true;
   }
   else
      isSame = false;

   return isSame;
}