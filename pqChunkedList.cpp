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

const int MaxElemsPerBlock = 16;
const int InsertionPoint = MaxElemsPerBlock;      // 2 => mid point, 4 => quarter, MaxElemsPerBlock => 1


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
    //cout << "PQueue::enqueue(" << newValue << "):";
 	BlockT *cur, *prev;
    //int *newOne = new int[MaxElemsPerBlock];
 	
    if (head == NULL) {
        //cout << "New Head:";
        head = new BlockT;
        head->block = new int[MaxElemsPerBlock];
        head->first = MaxElemsPerBlock/InsertionPoint;  // Mid-point insertion strategy
        head->last =  MaxElemsPerBlock/InsertionPoint;
        head->block[head->first] = newValue;
        head->next = NULL;
        return;
    }
    
 	for (prev = NULL, cur = head; cur != NULL; prev=cur, cur = cur->next) {
        if (newValue > cur->block[cur->first] && cur->first == 0) {
            //cout << " Scanned: Go to previous block and insert element there" << endl;
            //cout << "  ************ prev = " << prev << " (Address " << cur << ")" << " next = " << cur->next << endl;
            if (prev) 
                cur = prev;
            else {
                cur = head;
            }
            break;
        }
        else if (newValue > cur->block[cur->first] && cur->first != 0
                                                   && prev != NULL && newValue < prev->block[prev->last]) {
            //cout << " Scanned: Insert element at top of current block" << endl;
            //cout << "  ************ prev = " << prev << " (Address " << cur << ")" << " next = " << cur->next << endl;
            break;
        }
        
        else if (newValue > cur->block[cur->first] && cur->first != 0
                                                   && prev != NULL && newValue >= prev->block[prev->last]) {
            //cout << " Scanned: Insert element at bottom of previous block" << endl;
            //cout << "  ************ prev = " << prev << " (Address " << cur << ")" << " next = " << cur->next << endl;
            cur = prev;
            break;
        }
        else if (newValue > cur->block[cur->first] && cur->first != 0) {
            //cout << " Scanned: Insert element at top of current block, prev is NULL" << endl;
            //cout << "  ************ prev = " << prev << " (Address " << cur << ")" << " next = " << cur->next << endl;
            break;
        }
        else if (newValue == cur->block[cur->last] && cur->last == MaxElemsPerBlock-1 && cur->next != NULL && cur->next->first != 0) {
            //cout << " Scanned: Insert element at top of next block" << endl;
            //cout << "  ************ prev = " << prev << " (Address " << cur << ")" << " next = " << cur->next << endl;
            cur = cur->next;
            break;
        }
        else if (newValue == cur->block[cur->last] && cur->next == NULL) {
            //cout << " Scanned: TODO: Handle cur last tie >> need to create a new block" << endl;
            //cout << "  ************ prev = " << prev << " (Address " << cur << ")" << " next = " << cur->next << endl;
            //break;
        }

        else if (cur->next == NULL) {
            //cout << " Scanned: Normal Case Insert @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
            //cout << "  ************ prev = " << prev << " (Address " << cur << ")" << " next = " << cur->next << endl;
//            if (prev) 
//                cur = prev;
//            else {
//                cur = head;
//            }
            break;
 
        }
        else {
            //cout << " Scanned: Skipping to next Block" << endl;
            //cout << "  ************ prev = " << prev << " (Address " << cur << ")" << " next = " << cur->next << endl;
        }
 	}
    
    if (cur == NULL) {
        cur = prev;
        //cout << ": Hit back of linked-list: ";
    }
    
    //cout << "   **AFTER SCAN PROCESSING** prev = " << prev << " (Address " << cur << ")" << " next = " << cur->next << endl;
    
    if (newValue > cur->block[cur->first]) {
        if (cur->first > 0) { 
            //cout << " Handling Insert before first element in current block)" << endl;
            cur->first -= 1;
            cur->block[cur->first] = newValue;
            //cout << ":CurrentBlockSize=" << bSize(cur) << ":";
        }
        else {
            //cout << " Handling Block First Overflow: Create New Block Before)" << endl;
            BlockT * newBlock = new BlockT;
            BlockT * forwardBlock = cur;
            newBlock->block = new int[MaxElemsPerBlock];
            newBlock->next = cur->next;
            cur = newBlock;
            cur->first = MaxElemsPerBlock/InsertionPoint;  // point insertion strategy
            cur->last =  MaxElemsPerBlock/InsertionPoint;
            cur->block[cur->first] = newValue;
            //cout << ":CurrentBlockSize=" << bSize(cur) << ":";
            cur->next = forwardBlock;
            if (prev == NULL) {
                head = cur;
            }
            else {
                prev->next = cur;
            }
        }
    }
    else {
        for (int i = cur->last+1; i > cur->first ; i--) { // Find insertion point from bottom
            if (i < MaxElemsPerBlock) {
                //cout << "  $$$$ Attempting InsertFromBottom on Block at address = " << cur << endl;
                if (newValue > cur->block[i-1]) {
                    cur->block[i] = cur->block[i-1];
                    cur->block[i-1] = newValue;
                }
                else {
                    cur->block[i] = newValue;
                    cur->last += 1;
                    //cout << ":InsertFromBottom:CurrentBlockSize=" << bSize(cur) << ":";
                    break;
                }
            }
//            else if (newValue == cur->block[cur->last]) {
//                //cout << "  InsertFromBottom for newValue == cur->block[cur->last] on Block at address = " << cur << endl;
//                cur->block[cur->last+1] = newValue;
//                cur->last += 1;
//                //cout << ":::InsertFromBottom:CurrentBlockSize=" << bSize(cur) << ":";
//                break; 
//            }
            else {
                //cout << " Handling Block LAST Overflow: Create New Block After" << endl;
                // TODO: Create New Block After & Split Current, write new value in current
                BlockT * newBlock = new BlockT;
                newBlock->block = new int[MaxElemsPerBlock];
                
                //if (cur->next == NULL && newValue < cur->block[cur->last]) { // Hit the back of linked list
                if (newValue < cur->block[cur->last]) { // Hit the back of linked list
                    //cout << "Do not Split Current & write newValue in newBlock" << endl;
                    newBlock->first = MaxElemsPerBlock/InsertionPoint;  // Insertion-point insertion strategy
                    newBlock->last =  MaxElemsPerBlock/InsertionPoint;
                    newBlock->block[newBlock->first] = newValue;
                    //cout << ":NewBlockSize=" << bSize(newBlock) << ":";
                    newBlock->next = cur->next; // NULL
                    cur->next = newBlock;
                }
                else if (bSize(cur) > 1) {
                    //cout << "Split Current where newValue has priority & write newValue in current" << endl;
                    newBlock->first = MaxElemsPerBlock/InsertionPoint; // Quarter-Point Insertion
                    newBlock->last = newBlock->first;
                    if (newValue != cur->block[cur->last]) {
                        //cout << " >> Normal Split" << endl;
                        int i;
                        int transferCount = 0;
                        for (i = cur->last; ; i--) {
                            //cout << " Compare: newValue=" << newValue << " > " << "cur->block[" << i << "]=" << cur->block[i] << endl;
                            if (newValue > cur->block[i]) {
                                transferCount++;
                            }
                            else {
                                //cout << "   Finished Transfer List at i = " << i << endl;
                                break;
                            }
                        }
                        i++;
                        int curNewLast = i;
                        newBlock->first = MaxElemsPerBlock - transferCount;
                        if (MaxElemsPerBlock - transferCount > MaxElemsPerBlock/2)
                            newBlock->first = MaxElemsPerBlock/InsertionPoint;
                        
                        //cout << "TransferCount=" << transferCount << endl;
                        //cout << "Cur to New starting New @:" << newBlock->first << ":";
                        int j = 0;
                        for (; i <= cur->last; i++, j++) {
                            //cout << cur->block[i] << " ";
                            newBlock->block[newBlock->first + j] = cur->block[i];
                        }
                        newBlock->last = newBlock->first + j - 1;
                        newBlock->next = cur->next;
                        cur->next = newBlock;
                        cur->last = curNewLast;
                        cur->block[curNewLast] = newValue;
                        //cout << ":Writing newValue in cur[" << curNewLast << "]" << endl;
                        //cout << ":CurrentBlockSize=" << bSize(cur) << ":";
                        //cout << "NewBlockSize=" << bSize(newBlock) << ":";
                    }
                    else {
                        //cout << " >> Split Not Possible in current: NewValue is equal to element at cur->last" << endl;
                        //cout << " >> Check for cur->last growing beyond MaxElemPerBlock." << endl;
                        //cout << " >> If so then create new if next block is full (TODO)" << endl;
                        //cout << " TODO: Possible check for cur->last growing beyond MaxElemPerBlock, then create new" << endl;
                        if (cur->next != NULL && cur->next->last < MaxElemsPerBlock-1) {
                            //cout << "Do not Split Current & write newValue in next" << endl;
                            delete newBlock;
                            cur = cur->next;
                            cur->last += 1;
                            for (int i = cur->last; i > cur->first ; i--) { // Find insertion point from bottom
                                if (i < MaxElemsPerBlock) {
                                    //cout << "  (inner loop) Attempting InsertFromBottom on Block at address = " << cur << endl;
                                    if (newValue > cur->block[i-1]) {
                                        cur->block[i] = cur->block[i-1];
                                        cur->block[i-1] = newValue;
                                    }
                                    else {
                                        cur->block[i] = newValue;
                                        //cur->last += 1;
                                        //cout << " (inner loop):InsertFromBottom:CurrentBlockSize=" << bSize(cur) << ":";
                                        break;
                                    }
                                }
                            }
                        }
                        else {
                            //cout << "Current block full, create new Block & write newValue in newBlock" << endl;
                            //cout << " >>> TODO: This places the most recent of a long consecutive set of ints before last few..." << endl;
                            newBlock->first = MaxElemsPerBlock/InsertionPoint;  // Mid-point insertion strategy
                            newBlock->last =  MaxElemsPerBlock/InsertionPoint;
                            newBlock->block[newBlock->first] = newValue;
                            //cout << ":NewBlockSize=" << bSize(newBlock) << ":";
                            newBlock->next = cur->next;
                            cur->next = newBlock;
                        }
                    }
                }
                else {
                    //cout << "TODO: Readjust current since first=" << cur->first << "=last=" << cur->last << "=Max-1=" << MaxElemsPerBlock-1;
                }
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
 	
    //cout << "PQueue::dequeueMax():first=" << head->first << ":last=" << head->last << "= ";
    if (head->first > head->last) {
        //cout << endl << "PQueue::dequeueMax(): deleting head = ";
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
    int blockCount = 0;
    int elementCount = 0;
    
	cout << "------------------ START DEBUG INFO ------------------" << endl;
	for (BlockT *cur = head; cur != NULL; cur = cur->next) {
        cout << "Block#" << blockCount << " (at address " << cur << ")" << " next = " << cur->next << endl;
        if (cur != NULL) {
            cout << " QUEUE START: ";
            for (int i = cur->first; i <= cur->last; i++) {
                cout << "[" << i << "]=" << cur->block[i] << " ";
                elementCount++;
            }
            cout << ":QUEUE END" << endl;
        }        
        blockCount++; 
	}
    double occupancyRatio = (double) elementCount / (double) ((blockCount+1) * MaxElemsPerBlock);
    cout << "        **** occupancyRatio = " << occupancyRatio << " **** " << endl;
	cout << "------------------ END DEBUG INFO ------------------" << endl;
}

double occupancyRatio() {
    
    return 1.0;
}

int PQueue::bSize(BlockT *cur) {
    return cur->last - cur->first + 1;
}
