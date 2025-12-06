#include <iostream>
using namespace std;

class Queue
{
private:
    int *array;
    int currentSize;
    int capacity;
    int front;
    //write your code here. Add additional private variables if necessary

public:
    // Constructor
    Queue()
    {
        array = new int[1];
        capacity = 1;
        front = -1;
        currentSize = 0;
        //write your code here. Initialize additional private variables if necessary
    }
    Queue(int initialCapacity)
    {
        array = new int[initialCapacity]; // Allocate initial memory
        //write your code here. Initialize additional private variables if necessary
        capacity = initialCapacity;
        front = -1;
        currentSize = 0;
    }

    // Destructor
    ~Queue()
    {
        delete[] array; // Free dynamically allocated memory
    }

    // Helper function to resize the array when full
    void resize(int newCapacity)
    {
        int *newArray = new int[newCapacity]; // Allocate new array
        cout<<"Resized from "<<capacity<<" to "<<newCapacity<<endl;
        //write your code here. Copy the elements from the old array to the new array
        int f = front;
        for(int i = 0; i < currentSize; i++){
            *(newArray+i) = *(array+f);
            f++;
        }

        delete[] array; // Free old memory

        array = newArray;
        capacity = newCapacity;
        front = 0;
        //write your code here. Update the capacity and array pointers
    }

    // Enqueue an element onto the queue
    void enqueue(int x)
    {
        //write your code here. Check if the array is full and resize if necessary.
        if((front + currentSize) == capacity){
            //cout<<"Resized from "<<capacity<<" to "<<capacity*2<<endl;
            resize(capacity*2);
        }
        if(currentSize == 0){
            *(array + currentSize) = x;
            front = 0;
            currentSize++;
            return; 
        }
        *(array + currentSize) = x;
        currentSize++;
    }

    // Remove and return the peek element
    int dequeue()
    {
       //write your code here. Check if the stack is empty and return -1 if it is.
       if(currentSize == 0){
        cout<<"List is empty."<<endl;
        return -1;
       }
       int value = *(array + front);
       front++;
       currentSize--;
       if(currentSize == 0){
        capacity = 1;
        front = -1;
        return value; 
       }
       if(currentSize <= (capacity/4)){
            //cout<<"Resized from "<<capacity<<" to "<<capacity/2<<endl;
            resize(capacity/2);
        }
        return value;
       //remove the peek element and return it
       //resize the array if necessary
    }

    // Return the peek element without removing it
    int peek()
    {
        //write your code here. Check if the queue is empty and return -1 if it is.
        if(currentSize == 0){
            cout<<"List is Empty."<<endl;
            return -1;
        }
        return *(array + front);
        //return the peek element
    }

    // Return the number of elements in the queue
    int length()
    {
        //write your code here. Return the number of elements in the queue
        return currentSize;
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        //write your code here. Return true if the queue is empty, false otherwise
        return (currentSize == 0);
    }

    // Clear the queue
    void clear()
    {
        //write your code here. Clear the queue. resize the array to 1
        currentSize = 0;
        resize(1);
        front = -1;
        capacity = 1;
    }
};
