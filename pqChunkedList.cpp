//
//  pqChunkedList.cpp
//  pQueue
//
//  Created by Vince Mansel on 10/20/11.
//  Copyright (c) 2011 Wave Ocean Software. All rights reserved.
//

/*
 * This file implements the priority queue class as a singly-linked
 * list of integer arrays stored in descreasing order, a chunked list.
 * This makes it easy dequeue the max (it's right in front),
 * but slightly harder to enqueue since we
 * have to search for the proper block position to insert the new cell in the array.
 *
 * Based on pqlist.cpp from Julie Zelenski, CS106
 */

#include "pqueue.h"
#include "genlib.h"
#include <iostream>

const int MaxElemsPerBlock = 10;


/* Implementation notes: PQueue class
 * ----------------------------------
 * The private section for the pqlist looks like this:

    struct BlockT {
        int *block;
        int first;
        int last;
        BlockT *next;
    };
    BlockT *head;
 */



/* Implementation notes: constructor
 * ---------------------------------
 * We do not have a dummy cell, since it really won't help us much.
 * When the head is NULL, the pqueue is empty.
 */
PQueue::PQueue()
{
    head = NULL;
}

PQueue::~PQueue()
{
    
    while (head != NULL) {
    	BlockT *next = head->next;
        delete head->block;
        delete head;
        head = next;
    }
}

bool PQueue::isEmpty()
{
    return (head == NULL);  
}

/* Implementation notes: size
 * --------------------------
 * This version doesn't cache the number of entries, so we must traverse the list to count.
 */
int PQueue::size()
{
    int count = 0;
    for (BlockT *cur = head; cur != NULL; cur = cur->next)
    	count += (cur->last - cur->first) + 1;
    return count;
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
 	BlockT *cur, *prev;
    //int *newOne = new int[MaxElemsPerBlock];
 	
    if (head == NULL) {
        cout << "PQueue::enqueue IN" << endl;
        head = new BlockT;
        head->block = new int[MaxElemsPerBlock];
        head->first = MaxElemsPerBlock/2;  // Mid-point insertion strategy
        head->last =  MaxElemsPerBlock/2;
        head->block[head->first] = newValue;
        head->next = NULL;
        return;
    }
    
    //Find block: iterate over blocks until newValue > block[firstElem]
    //  if firstElem > 0,
    //    if block full
    //          create new block
    //          split current block
    //    insert before firstElem in current block
    //  
    //  if firstElem == 0
    //  Insert into previous block:
    //    if block full
    //          create new block
    //          split current block
    //    insert before firstElem in current block
    //    
    //Inserting:
    //   Find insertion point
    //      element = firstElem
    //      for all elements (from bottom); check next elem
    //        if newValue > block[element] 
    //          if firstElem > 0
    //            shift elements up
    //          else 
    //            shift elements down
    //          insert newValue in current cell
    
    
 	
// 	for (prev = NULL, cur = head; cur != NULL; prev=cur, cur = cur->next) {
// 		if (newValue > cur->block[cur->first]) {
//            // Go to previous block and insert element there
//            break;
//        }
//        else {
//            break;
//        }
// 	}
//    
//    if (prev) 
//        prev->next = newBlock;
//    else {
//        head = newBlock;
//    }
    
    cur = head;
    prev = head;
    
    if (bSize(cur) == MaxElemsPerBlock) {
        cout << "PQueue::enqueue(): Handling case size()==Max (Create New Block Only)" << endl;
        BlockT * newBlock = new BlockT;
        BlockT * forwardBlock = cur;
        newBlock->block = new int[MaxElemsPerBlock];
        newBlock->next = cur->next;
        cur = newBlock;
        cur->first = MaxElemsPerBlock/2;  // Mid-point insertion strategy
        cur->last =  MaxElemsPerBlock/2;
        cur->block[cur->first] = newValue;
        cur->next = forwardBlock;
        head = cur; // Special case only
    }
    else if (newValue > cur->block[cur->first]) {
        if (cur->first > 0) { 
            cur->first -= 1;
            cur->block[cur->first] = newValue;
        }
        else {
            cout << "PQueue::enqueue(): Handling Block First Overflow: Create New Block Only)" << endl;
            BlockT * newBlock = new BlockT;
            BlockT * forwardBlock = cur;
            newBlock->block = new int[MaxElemsPerBlock];
            newBlock->next = cur->next;
            cur = newBlock;
            cur->first = MaxElemsPerBlock/2;  // Mid-point insertion strategy
            cur->last =  MaxElemsPerBlock/2;
            cur->block[cur->first] = newValue;
            cur->next = forwardBlock;
            head = cur; // special case only
        }
    }
    else {
        for (int i = cur->last+1; i > cur->first ; i--) { // Find insertion point from bottom
            if (i < MaxElemsPerBlock) {
                if (newValue > cur->block[i-1]) {
                    cur->block[i] = cur->block[i-1];
                    cur->block[i-1] = newValue;
                }
                else {
                    cur->block[i] = newValue;
                    cur->last += 1;
                    break;
                }
            }
            else {
                cout << "PQueue::enqueue(): Handling Block LAST Overflow: Create New Block and Split)" << endl;
                
                BlockT * newBlock = new BlockT;
                BlockT * prevBlock = cur;

                newBlock->block = new int[MaxElemsPerBlock];
                newBlock->next = cur->next;
                
                cur = newBlock;
                
                // This is a brute force strategy that does not work for half-filled initial current (prevBlock) Blocks;
                cur->first = 0;  // Top-point insertion strategy for splits - easy
                cur->last =  MaxElemsPerBlock/2 - 1;
                
                // Copy previous bottom to current top
                
                for (int i = 0; i < MaxElemsPerBlock/2; i++) {
                    cur->block[i] = prev->block[i+MaxElemsPerBlock/2];
                }
                
                // For testing
                for (int i = MaxElemsPerBlock/2; i < MaxElemsPerBlock; i++) {
                    prev->block[i] = -107809;
                }
                
                prevBlock->first = 0;  // Top-point insertion strategy for splits - easy
                prevBlock->last =  MaxElemsPerBlock/2 ;

                prevBlock->block[prev->last] = newValue;
                head = prevBlock; // special case only

                break;
            }
        }
    }
}


/* Implementation notes: dequeueMax
 * --------------------------------
 * The maximum value is kept at the head of the list, so it's easy to find and
 * remove. Note we take care to free the memory for the deleted cell.
 */
int PQueue::dequeueMax()
{
	if (isEmpty())
		Error("Tried to dequeue max from an empty pqueue!");
	
 	BlockT *toBeDeleted = head;
    int *blockToBeDeleted = head->block;
 	int value = head->block[head->first];
    head->first += 1;
 	
    cout << "PQueue::dequeueMax():first=" << head->first << ":last=" << head->last << "= ";
    if (head->first > head->last) {
        cout << endl << "PQueue::dequeueMax(): deleting head = ";
        head = head->next; 	// splice head cell out
        delete blockToBeDeleted;
        delete toBeDeleted;
    }
	return value;

}


/* Implementation notes: bytesUsed
 * -------------------------------
 * The space needed is the sum of the object + the size of all the
 * allocated list cells.
 */
int PQueue::bytesUsed()
{
	int total = sizeof(*this);
 	for (BlockT *cur = head; cur != NULL; cur = cur->next)
 		total += sizeof(*cur);
 	return total;
}


string PQueue::implementationName()
{
	return "singly-linked chunklist";
}

/*
 * Implementation notes: printDebuggingInfo
 * ----------------------------------------
 * The version for the singly-linked chunk list prints the node structure
 * in order as a debugging aid to keeping track of the cell contents
 * and the pointers between them. It prints each cell in order
 */
void PQueue::printDebuggingInfo()
{
    int count = 0;
    
	cout << "------------------ START DEBUG INFO ------------------" << endl;
	for (BlockT *cur = head; cur != NULL; cur = cur->next) {
        cout << "Block#" << count << " (at address " << cur << ") val = " << "TODO: insert value" // cur->value
        << " next = " << cur->next << endl;
        count++;
	}
	cout << "------------------ END DEBUG INFO ------------------" << endl;
}

int PQueue::bSize(BlockT *cur) {
    return cur->last - cur->first + 1;
}
