/*
 * Author:     Anish Gajera
 * Course:     CS 1336.010
 * Date:       11/16/2020
 * Assignment: Lecture Homework 9, Excercise 1
 * Compiler:   Xcode
 */

/*
 * Description: This program calculates and displays on the screen
 * a Goldbach partition for all even integers between 4 and 100. (includes bonus as all partitons are printed out)
 */

#include <iostream>
#include <ostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

//function prototype(s)
bool isPrime (int num);


int main()
{
   //num to start with
   int testingNum = 4;
   
   //goes until num is 100
   while (testingNum <= 100)
   {
      //cout prompts
      cout << "Even integer " << testingNum;
      //testing for the Goldbach partitions
      for (int val1 = 2; val1 <= testingNum / 2; val1++)
      {
         if (isPrime(val1))
         {
            for (int val2 = testingNum - val1; val2 <= testingNum; val2++)
            {
               if (isPrime(val2) && (val1 + val2 == testingNum))
               {
                  cout << " = " << val1 << " + " << val2;
                  break;
               }
            }
         }
      }
      cout << endl;
      testingNum+=2;
   }
}//end function main()

// function takes in a number returns true if the number is a prime false if otherwise
/*
  * This function isPrime() is used to find prime numbers.
  * The function checks a series of conditions with variable "num" and based on it,
  * determines whether or not the number is prime or not to return the goldbach partitions
 */
bool isPrime (int num)
{
   if (num <= 1)
   {
      return false;
   }
      
   for (int i = 2; i < num; i++)
   {
      if (num % i == 0)
   {
      return false;
   }
      
   }
   return true;
}//end function isPrime()



//NOTES
/*
   Calculate and display on the screen a Goldbach partition for all even integers
   between 4 and 100. Here is a sample output for the val1 few numbers:
   A sample Goldbach Partition for all even integers between 4 and 100:
      Even integer 4 = 2 + 2
      Even integer 6 = 3 + 3
      Even integer 8 = 3 + 5
      Even integer 10 = 3 + 7
 
 
 
 bool isPrime (int num)
 {
    for (int i = 2; i <= num / 2; i++)
    {
       if (num % i == 0)
          return false;
    }
    return true;
 }
 */
