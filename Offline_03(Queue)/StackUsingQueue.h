#include <iostream>
using namespace std;
//#include "QueueArray.h"
#include "QueueLinkedList.h"

class Stack
{
private:
    
    //write your code here. Add additional private variables if necessary
    Queue q1,q2;
    int  size;
    int Capacity;

public:
    // Constructor
    Stack()
    {
        //write your code here. Initialize additional private variables if necessary
        size = 0;
        Capacity = 1;
    }
    Stack(int initialCapacity)
    {
        //write your code here. Initialize additional private variables if necessary
        //q1.resize(initialCapacity);
        //q2.resize(initialCapacity);
        Capacity = initialCapacity;
        size = 0;
    }

    // Destructor
    ~Stack()
    {
    }

    
    // Push an element onto the stack
    void push(int x)
    {
        //write your code here.
        //push the element onto the stack
        q2.enqueue(x);
        while(!q1.isEmpty()){
            q2.enqueue(q1.dequeue());
        }
        while(!q2.isEmpty()){
            q1.enqueue(q2.dequeue());
        }
        size++;
    }

    // Remove and return the top element
    int pop()
    {
       //write your code here. Check if the stack is empty and return -1 if it is.
       if  (size == 0){
        cout<<"Stack is Empty."<<endl;
        return -1;
       }
       int value = q1.dequeue();
        size--;
       if  (size == 0){
        Capacity = 1;
       }
       return value;
       //pop the top element and return it
    }

    // Return the top element without removing it
    int top()
    {
        //write your code here. Check if the stack is empty and return -1 if it is.
        if  (size == 0){
            cout<<"Stack is Empty."<<endl;
            return -1;
        }
        return (q1.peek());
        //return the top element
    }

    // Return the number of elements in the stack
    int  length()
    {
        //write your code here. Return the number of elements in the stack
        return  size;
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        //write your code here. Return true if the stack is empty, false otherwise
        return   (size == 0);
    }

    // Clear the stack
    void clear()
    {
        //write your code here. Clear the stack.
        q1.clear();
        q2.clear();
        size = 0;
        Capacity = 1;
    }
};
