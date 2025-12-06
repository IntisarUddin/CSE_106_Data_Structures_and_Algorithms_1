#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }

    Node(int value, Node *nextNode)
    {
        data = value;
        next = nextNode;
    }
};

class Queue
{
private:
    Node *peekNode; // Points to the front of the queue
    int currentSize;

public:
    // Constructor
    Queue()
    {
        peekNode = nullptr;
        currentSize = 0;
    }

    // Enqueue an element onto the queue
    void enqueue(int x)
    {
       // write your code here. Create a new node with the value x and enqueue it onto the queue
       // update the peekNode and currentSize
        Node *new_node = new Node(x);
        if(peekNode == nullptr){
            peekNode = new_node;
            currentSize++;
            return;
        }
        Node *temp = peekNode;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = new_node;
        currentSize++;
    }

    // Remove and return the peek element
    int dequeue()
    {
        // write your code here. Check if the queueu is empty and return -1 if it is.
        if(currentSize == 0){
            cout<<"List is empty."<<endl;
            return -1;
        }
        // dequeue the peek element and return it
        // update the peekNode and currentSize
        
        Node *temp = peekNode;
        peekNode = peekNode->next;
        int value = temp->data;
        delete temp;
        currentSize--;
        return value;
        // delete the node that was dequeued
    }

    // Return the peek element without removing it
    int peek()
    {
        // write your code here. Check if the queueu is empty and return -1 if it is.
        if(currentSize == 0){
            cout<<"List is empty."<<endl;
            return -1;
        }
        return (peekNode->data);
        // return the peek element
    }

    // Return the number of elements in the queueu
    int length()
    {
        // write your code here. Return the number of elements in the queueu
        return currentSize;
    }

    // Check if the queueu is empty
    bool isEmpty()
    {
        // write your code here. Return true if the queueu is empty, false otherwise
        return (currentSize == 0);
    }

    // Clear the queueu
    void clear()
    {
        while (!isEmpty())
        {
            dequeue(); // Continuously dequeue elements until the queueu is empty
        }
    }

    // Destructor
    ~Queue()
    {
        clear();
    }
};
