// ADS102 Assignment 3
// Marcus Boreham
// ADS103A3Q2.cpp 


//-------------------------- LIBRARIES ----------------------------------------

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//---------------------------- CLASSES -----------------------------------------

// Class to build a heap data structure
class Heap
{
public:

    // Class attributes
    vector<int> theHeap;
    int count = 0;

    // Constructor
    Heap()
    {
        theHeap;
        count;
    }

    // Swaps index elements with parent if parent has a lower value
    void heapifyUp()
    {
        int index = count - 1;
        while (index != 0 && theHeap[(index - 1) / 2] < theHeap[index])
        {
            swap((index - 1) / 2, index);
            index = (index - 1) / 2;
        }
    }

    // Swaps two elements in a vector
    void swap(int index1, int index2)
    {
        int temp = theHeap[index1];
        theHeap[index1] = theHeap[index2];
        theHeap[index2] = temp;
    }

    // Takes a value and adds it to the heap vector
    // Calls the heapify function to update the heap
    void insert(int data)
    {
        theHeap.push_back(data);
        count++;
        heapifyUp();
    }

    // Returns the current state of the heap
    string returnHeap()
    {
        string result;
        for (int i = 0; i < count; i++)
        {
            result += to_string(theHeap[i]) + " ";
        }
        return result;
    }

};

//---------------------------------------- MAIN --------------------------------------

int main()
{
    //-------- Variables & Containers----------
    int size = 0;
    string line;
    string numbers;
    string fileOutput;

    vector<string> fileContents;
    vector<int> fileElements;
    //-----------------------------------------

    Heap myHeap; // Object of the Heap class

    // Opens a flie and pushes the contents into a vector
    fstream aFile;
    aFile.open("input-q2a2.txt", fstream::in);

    if (aFile.is_open())
    {
        while (getline(aFile, line))
            fileContents.push_back(line);

        aFile.close();
    }
    else
        cout << " Unable to open file";

     // Assign file contents into variables
     size = stoi(fileContents[0]);
     numbers = fileContents[1];

     // Takes the string containing the numbers and streams them
     // by word split by spaces (default)
     // Populates the integer vector with the individual numbers
     stringstream ss(numbers);
     string word;
     while (ss >> word)
         fileElements.push_back(stoi(word));
        
     // Loop through the integers in the input vector
     // Assign to a string variable the heap vector before and after 'heapifying'
     for (int i = 0; i < size; i++)
     {         
         fileOutput += myHeap.returnHeap() + to_string(fileElements[i]) + "\n";        
         myHeap.insert(fileElements[i]);
         fileOutput += myHeap.returnHeap() + "\n";     
     }

     // Output to file the final heap 
     ofstream outFile;
     outFile.open("output-q2-a2.txt", ios::out);

     if (outFile.is_open())
     {
         outFile << fileOutput;

         outFile.close();
     }
     else cout << " Unable to open file";
}

