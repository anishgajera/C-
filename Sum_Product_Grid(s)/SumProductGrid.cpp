//preprocessor directives
#include <iostream>
#include <ostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

//function prototypes
int values(int[], const int);
void matricies(int*, int*, int[], int, int);
void spMatrix(int*, int[], int, int);
bool checkNumber(string);

//function main()
int main()
{
   const int SIZE = 100;
   int userVals[SIZE];
   int inputs;


   while ((inputs = !0))
   {
      inputs = values(userVals, SIZE);
      int* matrix = new int[(inputs + 1) * (inputs + 1)]; // creates the Table based on n+1^2 of user inputted numbers
      spMatrix(matrix, userVals, inputs + 1, inputs + 1);
      matricies(matrix, matrix, userVals, inputs + 1, inputs + 1);
      delete[] matrix;
   }
   return 0;
}//end function main()


//bool input validation function which checks whether data entered is valid or not (i.e. for bad data)
bool checkNumber(const string inputString)
{
   for (int i = 0; i < inputString.length(); i++)
   {
      //if the value is not within the bounds or is not whitespace
      if (inputString[i] == ' ' || !(inputString[i] >= '0' && inputString[i] <= '9'))
      {
         return false;
      }
   }
   return true;
}

//function values() reads in array and its size to take in the input from it, validate it, and then returns number of inputs used to create 2d array
int values(int userVals[], const int SIZE)
{
   int ctInput = 0;
   string userValue;

   //input validation
   cout << "Enter positive integers with spaces. Enter a 0 to stop input." << endl;
   for (; ctInput < SIZE; ctInput++)
   {
      cin >> userValue;
      //checks if values entered by user are positive
      if (checkNumber(userValue))
      {
         //if true, then input >> integer and is stored
         userVals[ctInput] = stoi(userValue);
      }
      else
      {
         cout << "Invalid input. Try again: " << endl;
         --ctInput;
         continue;
      }
      if (ctInput == 0 && userVals[ctInput] == 0)
      {
         exit(0);
      }
      else if (userVals[ctInput] == 0)
      {
         return ctInput;
      }
   }
   return ctInput;
}

//function matricies() creates and displays the individual matricies that will be displayed
void matricies(int* pMatrix, int* sMatrix, int userVals[], int row, int col)
{
   //variables/pointers for the creation and display of the product matrix
   int* valuesArray2 = new int[(row - 1) * (row - 1)];
   bool* frequency2 = new bool[(row - 1) * (row - 1)];
   //variables/pointers for the creation and display of the product matrix
   int* valuesArray = new int[(row - 1) * (row - 1)];
   bool* frequency = new bool[(row - 1) * (row - 1)];
   //for loop calculates values that will go into the product matrix in each index (i.e. multiplies and returns the values into the output window)
   for (int iRow = 1; iRow < (row); iRow++)
   {
      for (int iCol = 1; iCol < (col); iCol++)
      {
         pMatrix[iRow * row + iCol] = pMatrix[iRow] * pMatrix[iCol];
         frequency2[(iRow - 1) * (row - 1) + (iCol - 1)] = false;
         valuesArray2[(iRow - 1) * (row - 1) + (iCol - 1)] = pMatrix[iRow] * pMatrix[iCol];
      }
   }
   
   //block of code below prints out the product matrix in the correct form (numbers across top and down the side)
   cout << "Product Matrix" << endl << endl;
   for (int iRow = 0; iRow < (row); iRow++)
   {
      for (int iCol = 0; iCol < (col); iCol++)
      {
         if (iRow == 0 && iCol == 0)
            cout << " " << right << setw(7) << " ";
         else
            cout << right << setw(7) << pMatrix[iRow * row + iCol] << " ";
      }
      cout << endl;
   }
   cout << endl;
   cout << right << setw(7) << " Value";
   cout << right << setw(7) << "  Frequency" << endl;
   for (int i = 0; i < ((row - 1) * (col - 1)); i++)
   {
      if (frequency2[i] == true)
      {
         continue;
      }
      int count = 1;
      //loop checks for values after the first index and is incremented each time the value is found
      for (int j = i + 1; j < (row - 1) * (col - 1); j++)
      {
         if (valuesArray2[i] == valuesArray2[j])
         {
            frequency2[j] = true;
            count++;
         }
      }
      cout << right << setw(7) << valuesArray2[i] << right << setw(7) << count << endl;
   }
   cout << endl;
   cout << endl;
   delete[] valuesArray2;
   delete[] frequency2;
   
   for (int iRow = 1; iRow < (row); iRow++)
   {
      for (int iCol = 1; iCol < (col); iCol++)
      {
         sMatrix[iRow * (row)+iCol] = sMatrix[iRow] + sMatrix[iCol];
         frequency[(iRow - 1) * (row - 1) + (iCol - 1)] = false;
         valuesArray[(iRow - 1) * (row - 1) + (iCol - 1)] = sMatrix[iRow] + sMatrix[iCol];
      }
   }
   
   //block of code below prints out the sum matrix in the correct form (numbers across top and down the side)
   cout << "Sum Matrix" << endl << endl;
   for (int iRow = 0; iRow < (row); iRow++)
   {
      for (int iCol = 0; iCol < (col); iCol++)
      {
         if (iRow == 0 && iCol == 0)
         {
            cout << right << setw(7) << "";
         }
         else
            cout << right << setw(7) << sMatrix[iRow * (row)+iCol];
      }
      cout << endl;
   }

   cout << endl;
   cout << right << setw(7) << " Value";
   cout << right << setw(7) << "   Frequency" << endl;
   for (int i = 0; i < ((row - 1) * (col - 1)); i++)
   {
      if (frequency[i] == true)
      {
         continue;
      }
      int count = 1;
      for (int j = i + 1; j < (row - 1) * (col - 1); j++)
      {
         if (valuesArray[i] == valuesArray[j])
         {
            frequency[j] = true;
            count++;
         }
      }
      cout << right << setw(7) << valuesArray[i] << right << setw(7) << count << endl;
   }
   cout << endl;
   cout << endl;
   delete[] valuesArray;
   delete[] frequency;
   
}

//function spMatrix() "creates" the final matrix to be displayed
void spMatrix(int* dynamicArray, int userVals[], int row, int col)
{
   //nested for loops allow "easy" traversal through the 2d array/matrix
   for (int iRow = 0; iRow < 1; iRow++)
   {
      for (int iCol = 1; iCol < (col); iCol++)
      {
         dynamicArray[iRow * (row)+iCol] = userVals[iCol - 1];
      }
   }
   for (int iRow = 1; iRow < (row); iRow++)
   {
      dynamicArray[iRow * (row)] = userVals[iRow - 1];
   }
}
