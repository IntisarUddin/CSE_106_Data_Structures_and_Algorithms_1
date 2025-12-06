#include <iostream>
using namespace std;

class Stack
{
private:
    int *array;
    int size;
    int capacity;
    //write your code here. Add additional private variables if necessary

public:
    // Constructor
    Stack()
    {
        array = new int[1]; 
        //write your code here. Initialize additional private variables if necessary
        capacity = 1;
        size = 0;
    }
    Stack(int initialCapacity)
    {
        array = new int[initialCapacity]; // Allocate initial memory
        //write your code here. Initialize additional private variables if necessary
        capacity = initialCapacity;
        size = 0;
    }

    // Destructor
    ~Stack()
    {
        delete[] array;
         // Free dynamically allocated memory
    }

    // Helper function to resize the array when full
    void resize(int newCapacity)
    {
        int *newArray = new int[newCapacity]; // Allocate new array
        
        //write your code here. Copy the elements from the old array to the new array
        for(int i = 0; i < size; i++){
            *(newArray + i) = *(array + i);
        }
        delete[] array; // Free old memory
        //write your code here. Update the capacity and array pointers
        array = newArray;
        capacity = newCapacity;
    }

    // Push an element onto the stack
    void push(int x)
    {
        //write your code here. Check if the array is full and resize if necessary.
        //push the element onto the stack
        if(size == capacity){
            resize(2*capacity);
        }
        *(array + size) = x;
        size++;
    }

    // Remove and return the top element
    int pop()
    {
       //write your code here. Check if the stack is empty and return -1 if it is.
        if(size == 0){
            // Stack is Empty
            return -1;
        }
       //pop the top element and return it
        int value = *(array + size - 1);
        size--;
       //resize the array if necessary
        if(size == (capacity/4)){
            resize(capacity/2);
        }
        if(size == 0){
            resize(1);
        }
        return value;
    }

    // Return the top element without removing it
    int top()
    {
        //write your code here. Check if the stack is empty and return -1 if it is.
        if(size == 0){
            //Stack is empty
            return -1;
        }
        //return the top element
        int value = *(array + size - 1);
        return value;
    }

    // Return the number of elements in the stack
    int length()
    {
        //write your code here. Return the number of elements in the stack
        return size;
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        //write your code here. Return true if the stack is empty, false otherwise
        return (size == 0);
    }

    // Clear the stack
    void clear()
    {
        //write your code here. Clear the stack. resize the array to 1
        size = 0;
        resize(1);
    }
};
