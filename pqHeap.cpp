//
//  pqHeap.cpp
//  pQueue
//
//  Created by Vince Mansel on 10/24/11.
//  Copyright (c) 2011 Wave Ocean Software. All rights reserved.
//

/*
 * ------------------
 * This file implements the priority queue class as a balanced sorted heap
 * of integers stored in decreasing order according to heap rules.  This makes it easy
 * enqueue new elements, and as easy to dequeue the max right off the top.
 *
 * Based on pqvector.cpp, Julie Zelenski, CS106
 */

#include "pqueue.h"
#include "genlib.h"
#include <iostream>

/* Implementation notes: PQueue class
 * ----------------------------------
 * The private section for the pqvector looks like this:
 *
 *	Vector<int> heap;
 */

void swap(int &one, int &two);

int getHigherChildIndex(Vector<int> &heap, int index);

/*
 * There is a dummy cell at the beginning of the vector
 */

PQueue::PQueue()
{
    heap.add(NULL);
}


PQueue::~PQueue()
{
    heap.clear();
}


bool PQueue::isEmpty()
{
    return (heap.size() == 1);  
}

int PQueue::size()
{
	return (heap.size() - 1);
}


/* Implementation notes: enqueue
 * -----------------------------
 */
void PQueue::enqueue(int newValue)
{
    //cout << "PQueue::enqueue(" << newValue << "):";
    // Heap insert
	heap.add(newValue);
    
    // Bubble up the newValue;
    
    int index = heap.size() - 1;
    while (index != 1) {
        if (newValue > heap[index/2]) {
            swap(heap[index], heap[index/2]);
            index /= 2;
        }
        else break;
    }
}


/* Implementation notes: dequeueMax
 * --------------------------------
 */
int PQueue::dequeueMax()
{
	//cout << "PQueue::dequeueMax():";
    if (isEmpty()) {
        cout << endl;
        Error("pQueue is empty");
    }
    
	int value = heap[1];
    heap[1] = heap[heap.size()-1];
    heap.removeAt(heap.size()-1);
    int heapSize1 = heap.size()-1;
    
    // Trickle down the new root
    
    int index = 1;
    
    while (2*index < heapSize1) {
        //cout << endl << "index:*2:*2-1:heap.size()-1 >> " << index << ":" << 2*index << ":" << 2*index+1 << ":" << heap.size()-1 << "=" << endl;
        int higherChildIndex = getHigherChildIndex(heap,index);
        //cout << "heap[higherChildIndex] = heap[" << higherChildIndex << "] = " << heap[higherChildIndex] << endl;
        if (heap[higherChildIndex] > heap[index]) {
            //cout << "Swap " << heap[higherChildIndex] << "," << heap[index] << endl;
            swap(heap[higherChildIndex],heap[index]);
            index = higherChildIndex;
        }
        else break;
    }
    // Quick Fix
    if (size() == 2) {
        if (heap[1] < heap[2]) {
            swap(heap[1], heap[2]);
        }
    }
    
    return value;
}

int PQueue::bytesUsed() 
{
	return sizeof(*this) + heap.bytesUsed();
}


string PQueue::implementationName()
{
	return "binary heap";
}

void PQueue::printDebuggingInfo()
{
	cout << "------------------ START DEBUG INFO ------------------" << endl;
	cout << "Pqueue contains " << size() << " entries" << endl;
	for (int i = 1; i < heap.size(); i++) 
		cout << heap[i] << " ";
	cout << endl;
	cout << "------------------ END DEBUG INFO ------------------" << endl;
}

void swap(int &one, int &two) {
    int temp = one;
    one = two;
    two = temp;
}

// Assumes (2*index < heap.size() + 1) has been checked by calling function
int getHigherChildIndex(Vector<int> &heap, int index) {
    int result = 2*index;
    if (2*index + 1 <= heap.size() - 1) {
        if (heap[2*index] < heap[2*index + 1])
            result += 1;
    }
    return result;
}
