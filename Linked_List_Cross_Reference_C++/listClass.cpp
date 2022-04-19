//
//  List.cpp
//  AAG190007Asg8
//
//  Created by Anish Gajera on 5/8/21.
//

#include <stdio.h>
#include "fileWords.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

//function takes line number and performs insertion of word in line into the linked list (where it belongs)
//if a word is repeated, it is also disregarded as we only need to print the word once, but its line numbers as
//many times as necessary
void fileWords::nodeInsertion(string word, int line)
{

   Node* firstNode;
   Node* secondNode = nullptr;
   Node* nodePtr;
   str1 = str2 = strFinal = "";

   firstNode = new Node;
   repetition = false;
   firstNode->value = word;
   firstNode->nodeHead = nullptr;

   if (!head)
   {
      firstNode->next = nullptr;
      head = firstNode;
      appendNode(firstNode, line);

   }
   else
   {
      nodePtr = head;
      secondNode = nullptr;
      while (nodePtr != nullptr)
      {
         //cases are ignored in this assignment, so disregard them using toLower func
         str1 = firstNode->value;
         strFinal = nodePtr->value;
         for (int i = 0; i < str1.length(); i++)
         {
            str1.at(i) = tolower(str1.at(i));
         }
         for (int i = 0; i < strFinal.length(); i++)
         {
            strFinal.at(i) = tolower(strFinal.at(i));
         }
         if (str1 == strFinal)
         {
            repetition = true;
            appendNode(nodePtr, line);
         }
         if (strFinal < str1)
         {
            secondNode = nodePtr;
            nodePtr = nodePtr->next;
         }
         else
         {
            break;
         }
      }
      //if word is not repeated, the insert it into the linked list
      if (!repetition)
      {
         if (secondNode == nullptr)
         {
            //assign the head node
            head = firstNode;
            firstNode->next = nodePtr;
         }
         else
         {
            secondNode->next = firstNode;
            firstNode->next = nodePtr;
         }
         appendNode(firstNode, line);
      }
   }
}



void fileWords::appendNode(Node* nodePtr, int lineNum)
{
   LineNode* lineNodes = new LineNode;
   LineNode* linePtr;
   
   lineNodes->line = lineNum;
   lineNodes->next = nullptr;
   repeatedLine = false;
   
   if (!(nodePtr->nodeHead))
   {
      nodePtr->nodeHead = lineNodes;
   }
   else
   {
      linePtr = nodePtr->nodeHead;
      if (linePtr->line == lineNum)
      {
         return;
      }
      else
      {
         //nodes to append
         while (linePtr->next)
         {
            //if any repeating fileWords
            if (linePtr->line == lineNum)
            {
               repeatedLine = true;
            }
            linePtr = linePtr->next;
         }
         //else, just append to the list
         if (!repeatedLine)
         {
            linePtr->next = lineNodes;
         }
         if (linePtr->line == lineNodes->line)
         {
            delete lineNodes;
            linePtr->next = nullptr;
         }
      }

   }
}

//funciton displays the linked list when done sorting (in correct order)
void fileWords::outputList()
{
   Node* nodePtr;
   nodePtr = head;
   diffWords = 0;
   while (nodePtr)
   {
      LineNode* linePtr = nodePtr->nodeHead;
      cout << nodePtr->value << " ";
      while (linePtr)
      {
         cout << linePtr->line << " ";
         linePtr = linePtr->next;
      }
      nodePtr = nodePtr->next;
      cout << endl;
      diffWords++;
   }
}

//funciton that deletes the list (i.e. the nodes of the list)
void fileWords::deleteList()
{
   Node* nodePtr;
   Node* nextPtr;
   LineNode* linePtr;
   LineNode* nextNode;
   nodePtr = head;
   
   if (!nodePtr)
      return;
   else
   {
      while (nodePtr != nullptr)
      {
         linePtr = nodePtr->nodeHead;
         while (linePtr)
         {
            nextNode = linePtr->next;
            delete linePtr;
            linePtr = nextNode;
         }
         nextPtr = nodePtr->next;
         delete nodePtr;
         nodePtr = nextPtr;
      }
   }
}
