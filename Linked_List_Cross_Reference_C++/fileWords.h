//
//  fileWords.h
//  AAG190007Asg8
//
//  Created by Anish Gajera on 5/8/21.
//

#ifndef fileWords_h
#define fileWords_h
#ifndef LINKEDWORDLIST_H
#define LINKEDWORDLIST_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;

class fileWords
{
private:
   string str1, str2, strFinal;
   bool repetition;
   bool repeatedLine;
   int diffWords;
   
   //linked list for line numbers in file (nodes)
   struct LineNode
   {
      int line;
      LineNode* next;
   };
   
   struct Node
   {
      string value;
      Node* next;
      LineNode* nodeHead;
   };
   Node* head;
public:
   fileWords()
   {
      head = nullptr;
   }

   void appendNode(Node*, int);
   void nodeInsertion(string, int);
   void outputList();
   void deleteList();

};

#endif

#endif /* fileWords_h */
