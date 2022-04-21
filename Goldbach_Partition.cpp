/*
 * Author:     Anish Gajera
 * Course:     CS 1336.010
 * Date:       11/11/2020
 * Assignment: Lecture Homework 8, Excercise 1
 * Compiler:   Xcode
 */

/*
 * Description: This program asks the user to enter in a number which ranges from 1 to 100,
 * and after the user inputs the number, prime numbers are printed out based on the value entered.
 * Ex) if the user enters 37, the first 37 prime numbers are outputted
 */

#include <iostream>
#include <ostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

//output file declaration
ofstream fileOut;

void file();
int num = 100;
//function prototype
bool isPrime(int num);

bool value;
//user entered value
int userVal;
//counter - # of prime numbers that will be printed
int counter1 = 0;

//function prototype
void number();

//counter - 10 numbers per line
int counter2 = 0;

int main()
{
   file();
   //call to function "number"
   number();
   
   //call to function "isPrime"
   isPrime(num);
   
   return 0;
}//end function main()

void number()
{
   //user prompted to enter value
   cout << "Enter a number between 1 and 100" << endl;
   cin >> userVal;
   //if value is not valid, this input validation loop runs to get a valid value from the user
   while (userVal < 1 || userVal > 100)
   {
      cout << "Number out of range, please re-enter" << endl;
      cin >> userVal;
   }
}//end function number()

/*
  * This function isPrime() uses the number entered by the user (call it #) to find and output # number of prime numbers
  * the number entered by the user is between 1 and 100, therefore, for example, if the user enters 37, the first
  * 37 prime numbers are outputted. Spacing and number primes is accomodated within the function through the use of loops
  * and "counter" variables within the function.
 */
bool isPrime(int num)
{
   fileOut.open("PrimeOut.txt");
   for (int i = 2; i <= num; i++)
   {
      bool value = true;
      for (int j = 2; j <= (i - 1); j++)
      {
         if (i % j == 0)
         {
            value = false;
            break;
         }
      }
      if (value == true)
      {
         fileOut << i << setw(5);
         cout << i << "  ";
         counter1++;
         counter2++;
         if (counter2 == 10)
         {
            cout << endl;
            counter2 = 0;
         }
      }
      num++;
      
      if (counter1 == userVal)
      {
         break;
      }
   }
   cout << endl;
   
   return value;
}//end function isPrime(int num)

/*
 * This function can be used to open the output file after the prime numbers have been outputted;
 * this function determines whether or not the file was opened successfully and then the user is able to enter in
 * information required which would then be outputted to the corresponding output file.
 */
void file()
{
   fileOut.open("PrimeOut.txt");
   
   if(!fileOut)
   {
      cout << "The file could not be opened. Try again" << endl;
   }
   else
   {
      cout << "File opened successfully" << endl;
   }
   
   fileOut.close();
}//end function file()








//NOTES
/*
 int main()
 {
    int num;
    cout << "Enter a number between 1 and 100" << endl;
    cin >> num;
    while (num < 1 || num > 100)
    {
       cout << "Number out of range, please re-enter" << endl;
       cin >> num;
    }
    int currentNum = 2;
    isPrime(num);
    
    return 0;
 }
 */

/*
 bool isPrime(int num)
 {
    bool isPrime = false;
    int counter = 0;
    int currentNum = 2;
    num = enterNum();
    if (num == 1)
    {
       isPrime = true;
       cout << currentNum << endl;
    }
    while (num > 1)
    {
       for (int i = 0; i < num; i++)
       {
          if (currentNum % 2 == 0)
          {
             cout << setw(5) << currentNum;
             currentNum++;
             counter++;
             while (counter == 10)
             {
                cout << endl;
                counter = 0;
             }
          }
       }
    }
    
    return isPrime;
 }
 */

/*
 bool isPrime(int num)
 {
    bool isPrime;
    int currentNum = 2;
    int count = 0;
    
    if (num == 1)
    {
       cout << currentNum;
       isPrime = true;
       return isPrime;
    }
    else if (num > 1)
    {
       for(int i = 0; i < num; i++)
       {
          while (currentNum % 2 != 0)
          {
             cout << currentNum;
             currentNum++;
             isPrime = false;
             return isPrime;
          }
          count++;
          while (count == 10)
          {
             cout << endl;
             count = 0;
          }
       }
    }
    
    
    return isPrime;
 }
 */
