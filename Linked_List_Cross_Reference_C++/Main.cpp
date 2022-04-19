#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include "fileWords.h"
using namespace std;

//preprocessor directives
bool peekFile(ifstream&, string&);
void readInfo(ifstream&, string, string, int);

int main()
{

   ifstream file;
   string fileName;
   string lineOfText = "";
   string word = "";
   int line = 0;

   while (peekFile(file, fileName))
   {
      readInfo(file, lineOfText, word, line);
      file.close();
   }
   file.close();
}
void readInfo(ifstream& file, string lineOfText, string word, int line)
{
   fileWords ListNode;
   //reads in a line from a specifc file
   while (getline(file, lineOfText))
   {
      //tabs what line it is
      line++;
      //for loop for seperating words (from 0 till the size of the line of text)
      for (int i = 0; i < lineOfText.length(); i++)
      {
         if (!isalnum(lineOfText.at(i)))
         {
            if (word == "" || word == "," || word == ".")
            {
               word = "";
               continue;
            }
            //nodeInsertion;
            ListNode.nodeInsertion(word, line);
            word = "";
         }
         else
         {
            word += lineOfText.at(i);
            if (i == lineOfText.length() - 1)
            {
               // Insert our node
               ListNode.nodeInsertion(word, line);
               word = "";
            }
         }
      }
   }
   ListNode.outputList();
   //delete nodes (i.e. the list)
   ListNode.deleteList();
}//end function main()

bool peekFile(ifstream& file, string& fileName)
{
   bool check = false;

   //user prompted to enter name of file
   cout << "Enter file name: " << endl;
   cin >> fileName;
   file.open(fileName);
   //if cin input == an asterisk
   if (fileName == "*")
   {
      exit(0);//exit
   }
   //if file does not exist
   if (!file)
   {
      while (!check)
      {
         cout << "File not found. Try again: " << endl;
         cin >> fileName;
         file.open(fileName);
         //same loop from above (if input is an asterisk)
         if (fileName == "*")
         {
            exit(0);
         }
         if (file)
         {
            check = true;
            return check;
         }
      }
   }
   else
   {
      check = true;
      return check;
   }
   return check;
}

