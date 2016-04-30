#include "linkedlist.h"

LinkedList::LinkedList()
{
   mHead = NULL;
   mTail = NULL;
   mCount = 0;
}

LinkedList::~LinkedList()
{
   Node *currentNode, *nextNode;
   currentNode = mHead;

   if (mHead != NULL)
   {
      currentNode = mHead;
      while (currentNode->mNext != NULL)
      {
         nextNode = currentNode->mNext;
         delete currentNode;
         currentNode = nextNode;
      }
      delete currentNode;

      mHead = NULL;
      mTail = NULL;
      int mCount = 0;
   }
}

int LinkedList::getCount()
{
   return mCount;
}

void LinkedList::addTeacher(Teacher teacher)
{
   Node *newNode;
   newNode = new Node;
   newNode->mTeacher = teacher;
   newNode->mNext = NULL;

  if (mHead == NULL)
   {
      mHead = newNode;
      mTail = newNode;
   }
  

   mTail->mNext = newNode;
   mTail = newNode;
   mCount++;
}

void LinkedList::removeTeacher(Teacher teacher)
{
   Node *currentNode, *nodeBefore, *tmp = NULL;
   bool found = false;


   currentNode = mHead;
   nodeBefore = mHead;

   while (currentNode != NULL)
   {
      if (teacher == (*currentNode).mTeacher)
      {
         currentNode = NULL;
         found = true;
      }
      else
      {
         nodeBefore = currentNode;
         currentNode = currentNode->mNext;
      }
      if (found == false)
      {
         cout << "Teacher does not exist.";
      }
   }

   if (nodeBefore == mHead)
   {
      mHead = mHead->mNext;
   }
   else if (nodeBefore->mNext == mTail)
   {
      mTail = nodeBefore;
   }
   else
   {
      tmp = nodeBefore->mNext;
      nodeBefore = tmp;
   }
   delete nodeBefore;
   delete tmp;
   return;
}

void LinkedList::searchPrintTeacherName(string name)
{
   Node *currentNode;
   Teacher teacher;
   bool teacherFound = false;

   currentNode = mHead;
   while (currentNode != NULL)
   {
      if ((*currentNode).mTeacher.getName() == name)
      {
         teacher = currentNode->mTeacher;
         cout << teacher;
         if (teacherFound == false)
            teacherFound = true;
      }
      currentNode = currentNode->mNext;
   }

}

bool LinkedList::doesTeacherExist(string name)
{
   Node *currentNode = mHead;
   bool teacherFound = false;


   while (currentNode != NULL)
   {
      if ((*currentNode).mTeacher.getName() == name)
      {
            teacherFound = true;
      }
      if (teacherFound == true)
         currentNode = NULL;
      else
      currentNode = currentNode->mNext;
   }
   
   return teacherFound;
}



int LinkedList::searchGetListIndex(string ID) 
{
   Node *currentNode;
   Teacher teacherSelected;
   bool teacherFound = false;
   int listCount = 1;

   currentNode = mHead;

   if (currentNode != NULL)
   {
      if ((*currentNode).mTeacher.getID() == ID)
      {
         teacherSelected = currentNode->mTeacher;
         teacherFound = true;
      }
      currentNode = currentNode->mNext;
      listCount++;
   }
   if (teacherFound == false)
   {
      cout << "Teacher not found.\n";
      listCount = 0;
   }
   return listCount;
}

Teacher LinkedList::getTeacherFromIndex(int index)
{
   Node *currentNode;

   currentNode = mHead;

   for (int i = 0; i < index; i++)
   {
      currentNode = currentNode->mNext;
   }
   return currentNode->mTeacher;
}


void LinkedList::updateTeacher(Teacher teacher)
{
   char choice, choice2;
   string tempName, tempPhone, tempEmail;
   bool tempSub;
   bool valid = false;
   cout << "What would you like to update?\n"
      << "Name: N\n"
      << "Substitute Status: S\n"
      << "Phone Number: P\n"
      << "Email: E\n";
   choice = getChoice();

   switch (choice)
   {
   case 'N':
   case 'n':
      //name
      cout << "Please enter updated name: ";
      cin >> tempName;
      updateTeacherName(teacher, tempName);
      break;
   case 'S':
   case 's':
      //sub
      
      while (valid == false)
      {
         cout << "Is this person a substitute teacher? Y or N: ";
         cin >> choice2;
         if (toupper(choice2) == 'Y')
         {
            tempSub = true;
            valid = true;
         }
         else if (toupper(choice2) == 'N')
         {
            tempSub = false;
            valid = true;
         }
         else
            cout << "Input not valid.\n";
      }
      updateTeacherSubStatus(teacher, tempSub);
      break;
   case 'P':
   case 'p':
      //phone
      cout << "Please enter updated phone number: ";
      cin >> tempPhone;
      updateTeacherName(teacher, tempPhone);
      break;
   case 'E':
   case 'e':
      //email
      cout << "Please enter updated email: ";
      cin >> tempEmail;
      updateTeacherName(teacher, tempEmail);
      break;
   }
}

/*
Copy of getChoice() from functions.cpp.
Author: Michael English
*/
char LinkedList::getChoice()
{
   char choice;

      cout << "Enter your choice: ";
      cin >> choice;

   return choice;
}

void LinkedList::updateTeacherName(Teacher teacher, string name)
{
   Node *currentNode;
   
   currentNode = mHead;


   while (currentNode != NULL)
   {
      if (teacher == currentNode->mTeacher)
         (*currentNode).mTeacher.setName(name);

         currentNode = currentNode->mNext;     
   }

}

void LinkedList::updateTeacherPhone(Teacher teacher, string phoneNum)//name issub phone email
{
   Node *currentNode;

   currentNode = mHead;


   while (currentNode != NULL)
   {
      if (teacher == currentNode->mTeacher)
         (*currentNode).mTeacher.setPhoneNum(phoneNum);

         currentNode = currentNode->mNext;
   }

}

void LinkedList::updateTeacherEmail(Teacher teacher, string email)//name course issub phone email
{
   Node *currentNode;

   currentNode = mHead;


   while (currentNode != NULL)
   {
      if (teacher == currentNode->mTeacher)
         (*currentNode).mTeacher.setEmail(email);

      currentNode = currentNode->mNext;
   }

}

void LinkedList::updateTeacherSubStatus(Teacher teacher, bool isSub)//name course issub phone email
{
   Node *currentNode;

   currentNode = mHead;


   while (currentNode != NULL)
   {
      if (teacher == currentNode->mTeacher)
         (*currentNode).mTeacher.setIsSub(isSub);

      currentNode = currentNode->mNext;
   }


}

void LinkedList::printAllTeachers()
{
   Node *currentNode;

   currentNode = mHead;

   while (currentNode != NULL)
   {
      cout << currentNode->mTeacher;
      currentNode = currentNode->mNext;
   }
}