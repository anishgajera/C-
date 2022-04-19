#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

void alterString(string s);
bool isPalindrome(string str);

int main()
{
   string userString;
   bool repeat = true;
   //while loop acts to make program a driver program (i.e. the program keeps going until a specific condition is met)
   while (repeat)
   {
      //user prompted to enter a string of their choice
      cout << "Enter a string: ";
      getline(cin, userString);
      //if the user enters an asterisk character '*'
      if (userString == "*")
      {
         //the program exits
         exit(0);
      }
      alterString(userString);
   }
   return 0;
}//end function main()

/*
   This function alterString() takes the string the user enters and makes it to where all cases
   are the same and to where there are no more spaces in the string; this will make reading the
   string into the isPalindrome function agile.
 */
void alterString(string s)
{
   int length = s.length();
   //any spaces within the string are removed
   s.erase(remove(s.begin(), s.end(), ' '), s.end());
//   s.erase(remove(s.begin(), s.end(), ','), s.end());
   //for loop which iterates to remove any punctuation within the string as it can result in false results
   for (int i = 0; i < length; i++)
   {
      if (ispunct(s[i]))
      {
         s.erase(i--, 1);
         length = s.size();
      }
   }
   //for loop which iterates making all characters of the string entered lowercase for easier comparison
   for (int i = 0; i < s.length(); i++)
   {
      s[i] = tolower(s[i]);
   }
   isPalindrome(s);
}

/*
   This function isPalindrome() takes the altered string from the previous function and uses it to
   determine whether the string entered by the user was a palindrome. Since the string was altered
   to account for spaces and punctuation, this function can then take the string and determine whether
   or not it is a palindrome.
 */
bool isPalindrome(string str)
{
   //initially false
   bool is_Palindrome = false;
   int length = str.length();
   
   //if the string consists of only 1 character
   if(length <= 1)
   {
      //it is automatically a palindrome
      is_Palindrome = true;
      cout << "String is a Palindrome" << endl;
   }
   //else if the string contains more than 1 character, it is tested with the next characters in a recursive manner
   else
      //if the first character is same as the last
      if(str.at(0) == str.at(length - 1))
      {
         //string is modified using substr funciton
         str = str.substr(1, (length - 2));
         //isPalindrome is called again (Recursion occurs here)
         isPalindrome(str);
      }
      //else if the first character is not the same as the last
      else
      {
         //the string is not a palindrome
         is_Palindrome = false;
         cout << "String is not a palindrome." << endl;
      }
   
   return is_Palindrome;
}
