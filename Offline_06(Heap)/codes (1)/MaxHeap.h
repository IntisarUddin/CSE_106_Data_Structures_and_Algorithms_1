#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <fstream>
#include <stdexcept>

#define MAX_CAPACITY 100  //Defines the maximum capacity of the heap

class MaxHeap
{
private:
    int heap[MAX_CAPACITY];  //Array to store heap elements
    int size;                //Current number of elements in the heap

    //Sifts up the node at index i to maintain heap property
    void siftUp(int i)
    {
        /**Write your code here**/
    }

    //Sifts down the node at index i to maintain heap property
    void siftDown(int i)
    {
        /**Write your code here**/
    }

public:
    //Constructor initializes an empty heap
    MaxHeap() : size(0) {}

    //Inserts a new element x into the heap
    void insert(int x)
    {
        if (size == MAX_CAPACITY)
        {
            throw std::length_error("insert() called, but the heap is full.");
        }

        /**Write your code here**/

    }

    //Returns the maximum element without removing it
    int findMax()
    {
        if (size == 0)
        {
            throw std::runtime_error("findMax() called, but the heap is empty.");
        }

        /**Write your code here**/

    }

    //Removes and returns the maximum element from the heap
    int extractMax()
    {
        if (size == 0)
        {
            throw std::runtime_error("extractMax() called, but the heap is empty.");
        }

        /**Write your code here**/

    }


    //Returns the number of elements in the heap
    int getSize()
    {
        /**Write your code here**/
    }

    //Checks if the heap is empty. Returns true if the heap is empty, false otherwise.
    bool isEmpty()
    {
        /**Write your code here**/
    }

    //Increases the value of the element at index i to new_value
    void increaseKey(int i, int newValue)
    {
        if (i < 0 || i >= size || heap[i] >= newValue)
        {
            throw std::invalid_argument("increaseKey() called with invalid index or invalid new value.");
        }

        /**Write your code here**/

    }


    //Deletes the element at index i
    void deleteKey(int i)
    {
        /**Write your code here**/
    }

    //Prints the heap's content to the output file
    void printHeap(std::ofstream &outfile)
    {
        /**Write your code here**/
    }

    //Checkes whether the Max Heap property is preserved or not. Returns true if the Max Heap property is valid and returns false otherwise.
    bool isValidMaxHeap()
    {
        /**Write your code here**/
    }
};

#endif //MAXHEAP_H
