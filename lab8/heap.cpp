/* Comp 15 Lab 8: Heaps 
 * Implementation of Heap class with string keys
 * Updated 11/2/202 by Ellis Brown
 * Edited by: Sam Lacet-Brown
 */

#include <iostream>

#include "heap.h"

using namespace std;

/*
 * Default constructor
 */
Heap::Heap()
{
        heap        = new string[INIT_SIZE];
        heapSize    = 0;
        maxCapacity = INIT_SIZE;
}

/*
 * Destructor
 */
Heap::~Heap()
{
        heapSize = 0;
        delete [] heap;
}

/*
 * intialize a heap from an array
 */
Heap::Heap(string list[], int listSize)
{
        heap        = new string[listSize + 1];
        maxCapacity = listSize + 1;

        // Remember our implementation of a heap
        // starts at 1 not zero, so we store a
        // nonce value at index 0.
        // Don't use the fact that this value is there:
        // Clients could store this string in their heap!
        // Just remember index 0 is not used
        heap[0] = "I'M NOT PART OF THE HEAP";

        // copy the unsorted list over
        for (int i = 0; i < listSize; i++) {
                heap[i + 1] = list[i]; //notice indexing
        }
        heapSize = listSize;

        // use the build heap function
        // to make unsorted array into a heap
        buildHeap();
}

/*
 * insert a string into the heap. 
 * requires the function upHeap to be implemented
 */
void Heap::insert(string s)
{
        // NB:  We do not use slot zero in the array
        // The array is thus already of size (heapSize + 1)
        // But we want to add one more element, so we
        // need an array of size (heapSize + 2)
        ensureCapacity(heapSize + 2);

        // first, satisfy the shape invariant:
        // location to insert is heapSize + 1
        // (Recall, 0th location not used)
        heap[heapSize + 1] = s;
        heapSize++;

        // re-establish the heap invariant
        //heapSize is the index with our inserted element
        upHeap(heapSize); 
}

/*
 * return smallest element in heap
 */
string Heap::min()
{       
        return heap[1];
}

/*
 * remove and return smallest element in heap
 */
string Heap::removeMin()
{
        if(heapSize > 0) {
                string minItem = min();
                heap[1] = heap[heapSize];
                heapSize--;
                for(int i = heapSize/2; i > 0; i--) {
                        downHeap(i);
                }
                return minItem;
        }
        throw runtime_error("no minimum in empty heap");
}

/*
 * return size of heap
 */
int Heap::size()
{
        return heapSize;
}

/*
 * downHeap establishes/verifies heap invariant from given 
 * location down to leaves
 * if parent is out of order with respect to children,
 * swap with smaller child and downHeap from updated child
 */
void Heap::downHeap(int location)
{
        bool done = false;
        int smallest;
        while(done != true) {
                smallest = location;
                if(heap[leftChild(location)] <= heap[smallest]) {
                        smallest = leftChild(location);
                }
                if (heap[rightChild(location)] <= heap[smallest]) {
                        smallest = rightChild(location);
                }
                if(heap[smallest] == heap[location]) {
                        done = true;
                } else {
                        string temp = heap[smallest];
                        heap[smallest] = heap[location];
                        heap[location] = temp;
                }
        }
}

/* NOT required for this lab, but you can write it if you have time
 * upHeap reestablishes heap invariant from given node to root
 * If child is out of order with respect to parent, swap and
 * continue to upHeap from parent to root
 */
void Heap::upHeap(int location)
{
        (void) location; // Removes compiler warning about unused variable.
}

/*
 * creates a heap out of the unsorted array.
 * Naive algorithm is O(n log n)
 * Algorithm from class/prelab is O(n) (proof in 160)
 */
void Heap::buildHeap()
{
        for(int i = heapSize/2; i > 0; i--) {
                downHeap(i);
        }
}

/*
 * Return left child for element at given index
 */
int Heap::leftChild(int index)
{
        return index * 2;
}

/*
 * Return right child for element at given index
 */
int Heap::rightChild(int index)
{
        return (index * 2) + 1;

}

/*
 * Return the parent for element at given index
 */
int Heap::parent(int index)
{
        return index / 2; // note integer division
}

/* 
 * Purpose: Ensure heap array has at least the desired capacity.
 */
void Heap::ensureCapacity(int desiredCapacity)
{
        if (maxCapacity >= desiredCapacity)
                        return;  // Nothing to do:  array is big enough

        // otherwise, expand
        int     newCapacity = max(desiredCapacity, 2 * maxCapacity + 2);
        string *newArray    = new string[newCapacity];

        // dutifully copying unused slot 0
        // Note elements occupy slots 1 .. heapSize, inclusive
        for (int i = 0; i < heapSize + 1; ++i) {
                newArray[i] = heap[i];
        }
        
        maxCapacity = newCapacity;
        delete [] heap;
        heap = newArray;
}


// Comp cat
// =^.^=
