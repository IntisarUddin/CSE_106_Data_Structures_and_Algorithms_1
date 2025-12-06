#include <iostream>
using namespace std;

class Stack
{
private:
    int *array;
    //write your code here. Add additional private variables if necessary

public:
    // Constructor
    Stack()
    {
        array = new int[1]; 
        //write your code here. Initialize additional private variables if necessary
    }
    Stack(int initialCapacity)
    {
        array = new int[initialCapacity]; // Allocate initial memory
        //write your code here. Initialize additional private variables if necessary
    }

    // Destructor
    ~Stack()
    {
        delete[] array; // Free dynamically allocated memory
    }

    // Helper function to resize the array when full
    void resize(int newCapacity)
    {
        int *newArray = new int[newCapacity]; // Allocate new array
        
        //write your code here. Copy the elements from the old array to the new array

        delete[] array; // Free old memory
        
        //write your code here. Update the capacity and array pointers
    }

    // Push an element onto the stack
    void push(int x)
    {
        //write your code here. Check if the array is full and resize if necessary.
        //push the element onto the stack
    }

    // Remove and return the top element
    int pop()
    {
       //write your code here. Check if the stack is empty and return -1 if it is.
       //pop the top element and return it
       //resize the array if necessary
    }

    // Return the top element without removing it
    int top()
    {
        //write your code here. Check if the stack is empty and return -1 if it is.
        //return the top element
    }

    // Return the number of elements in the stack
    int length()
    {
        //write your code here. Return the number of elements in the stack
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        //write your code here. Return true if the stack is empty, false otherwise
    }

    // Clear the stack
    void clear()
    {
        //write your code here. Clear the stack. resize the array to 1
        
    }
};
