//
//  pqPriority_Queue.cpp
//  pQueue
//
//  Created by Vince Mansel on 10/24/11.
//  Copyright (c) 2011 Wave Ocean Software. All rights reserved.
//

/*
 * This file implements the priority queue class based on the C++ STL Priority Queue. 
 *
 * Based on pqlist, Julie Zelenski, CS106
 */

#include "pqueue.h"
#include "genlib.h"
#include <iostream>


/* Implementation notes: PQueue class
 * ----------------------------------
 * The private section for the pqlist looks like this:
 struct Cell {
 int value;
 Cell *next;
 };
 Cell *head;
 */



/* Implementation notes: constructor
 * ---------------------------------
 * We do not have a dummy cell, since it really won't help us much.
 * When the head is NULL, the pqueue is empty.
 */
PQueue::PQueue()
{
    
}

PQueue::~PQueue()
{

}

bool PQueue::isEmpty()
{
    return prq.empty();  
}

/* Implementation notes: size
 * --------------------------
 * This version doesn't cache the number of entries, so we must traverse the list to count.
 */
int PQueue::size()
{
    return prq.size();
}


/* Implementation notes: enqueue
 * -----------------------------
 * We have to search to find the proper position, which can be a bit tricky with
 * a singly-linked list.  We walk two parallel pointers, one a step behind the other,
 * until we find the correct position to insert the new cell, which we then splice
 * into place. Note the special case of inserting at the head. Alternatively, this
 * operation could work recursively.
 */
void PQueue::enqueue(int newValue)
{
    prq.push(newValue);
}


/* Implementation notes: dequeueMax
 * --------------------------------
 * The maximum value is kept at the head of the list, so it's easy to find and
 * remove. Note we take care to free the memory for the deleted cell.
 */
int PQueue::dequeueMax()
{
    int value = prq.top();
    prq.pop();
	return value;
}


/* Implementation notes: bytesUsed
 * -------------------------------
 * The space needed is the sum of the object + the size of all the
 * allocated list cells.
 */
int PQueue::bytesUsed()
{
 	return prq.size();
}


string PQueue::implementationName()
{
	return "sorted linked list";
}

/*
 * Implementation notes: printDebuggingInfo
 * ----------------------------------------
 * The version for the singly-linked list prints the node structure
 * in order as a debugging aid to keeping track of the cell contents
 * and the pointers between them. It prints each cell in order
 */
void PQueue::printDebuggingInfo()
{
	cout << "------------------ START DEBUG INFO ------------------" << endl;
    cout << "TOP ELEMENT is " << prq.top() << endl;
	cout << "------------------ END DEBUG INFO ------------------" << endl;
}


