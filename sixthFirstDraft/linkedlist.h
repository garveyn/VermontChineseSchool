#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>
#include "teacher.h"

using namespace std;

class LinkedList
{
   struct Node
   {
      Teacher mTeacher;
      Node *mNext;

      Node()
      {
         Teacher();
         mNext = NULL;
      }
   };

   Node *mHead, *mTail;
   int mCount;

public:
   LinkedList();
   ~LinkedList();

   int getCount();

   void addTeacher(Teacher teacher);
   void removeTeacher(Teacher teacher);
   void searchPrintTeacherName(string name);
   int searchGetListIndex(string ID);
   Teacher getTeacherFromIndex(int index);
   bool doesTeacherExist(string name);
   char getChoice();

   void updateTeacher(Teacher teacher);
   void updateTeacherName(Teacher teacher, string name);
   void updateTeacherPhone(Teacher teacher, string phoneNum);
   void updateTeacherEmail(Teacher teacher, string Email);
   void updateTeacherSubStatus(Teacher teacher, bool isSub);
   


  };

#endif