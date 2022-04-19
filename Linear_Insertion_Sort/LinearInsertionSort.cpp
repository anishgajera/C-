//preprocessor directives
#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>
#include <string>
using namespace std;

//function prototypes
void insertionSort(double[], int);
int fileName(double[], const int, int);
void outputArray(double[], int);

int main()
{
    const int SIZE = 100;
    double array[SIZE] = { };
    int input = 1;
    while (input > 0)
    {
        input = fileName(array, SIZE, input);
        outputArray(array, input);
    }
}//end funciton main()

//function fileName(double, const int, int) asks the user to input a file name and catches invalid files along with *s
int fileName(double array[], const int SIZE, int input)
{
   int i = 0;
   bool fileOpen = false;
   //variable which holds the name of the file inputted by the user
   string filesName;
   //user is promted to enter file name
   cout << "Enter input file name: ";
   //inputted name gets inputted into the filesName variable
   cin >> filesName;
   while (fileOpen == false)
   {
      //if the user enters a *
      if (filesName == "*")
      {
         exit(0);
      }
      ifstream inputFile;
      inputFile.open(filesName);
      if (inputFile)
      {
         fileOpen = true;
         while (!inputFile.eof())
         {
            double num;
            //whatever is in the inputFile gets inputted into num
            inputFile >> num;
            //array at index i is loaded with num
            array[i] = num;
            //insertion sort is called and i is incremented accordingly
            insertionSort(array, ++i);
         }
         inputFile.close();
      }
      else
      {
         //if the file is not found ("invald" user input)
         cout << "File not found. Try again: ";
         cin >> filesName;
      }
   }
    return (i);
}

//funciton insertionSort(double, int) performs the insertion sort algorithim on a set of values
void insertionSort(double array[], int input)
{
    int count, j;
    double key;

    for (count = 1; count < input; count++)
    {
        key = array[count];
        j = count - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
    return;
}

//function outputArray(double, int) outputs the array (diff. function for output per assignment instructions)
void outputArray(double array[], int input)
{
    int count;
    for (count = 0; count < input; count++)
    {
        if (array[count] == array[count - 1])
        {
            continue;
        }
        else
            cout << fixed << setprecision(2) << array[count] << endl;
    }
}
