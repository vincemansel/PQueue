/* File: main.cpp
 * --------------
 * Simple main module for PQueue assignment.
 */
 
#include "pqueuetest.h"
#include "performance.h"
#include <iostream>
#include "genlib.h"
#include "pqueue.h"
#include "random.h"


/*
 * Use these functions to test your PQueue implementation.
 * Comment out those tests you aren't interested in running
 * while you are mid-development.
 */

void EnQ(PQueue &pq, int value, int & count) {
    pq.enqueue(value);
//    cout << "Size = " << pq.size() << ":" << ++count << endl;
    //pq.printDebuggingInfo();
}
void DeQ(PQueue &pq, int & count) {
    //cout << "DeQ = " << pq.dequeueMax() << endl;
    //cout << "Size = " << pq.size() << ":" << --count << endl;
    //pq.printDebuggingInfo();
}

int main()
{
//    Randomize();
//    PQueue basic;
//    
//    //cout << "Before Enqueue: IsEmpty = " << basic.isEmpty() << endl;
//    //cout << "Before Enqueue: Size = " << basic.size() << endl;
//
//    int qSize = 0;
//
//    for (int i = 0; i < 1000; i++) {
//        EnQ(basic,RandomInteger(1, 500),qSize);
//    }
    
	BasicPQueueTest();
	MorePQueueTest();
	PQueueSortTest();
   	PQueuePerformance();
    cout << endl << "Goodbye and have a nice day!" << endl;
    return (0);
}

void testCode(PQueue &basic, int qSize) {
    EnQ(basic,66,qSize);
    EnQ(basic,67,qSize);
    EnQ(basic,55,qSize);
    EnQ(basic,33,qSize);
    EnQ(basic,44,qSize);
    EnQ(basic,22,qSize);
    EnQ(basic,11,qSize);
    EnQ(basic,77,qSize);
    EnQ(basic,88,qSize);
    EnQ(basic,99,qSize);
    EnQ(basic,1010,qSize);
    EnQ(basic,1313,qSize);
    EnQ(basic,1000,qSize);
    EnQ(basic,1414,qSize);
    EnQ(basic,1212,qSize);
    EnQ(basic,1211,qSize);
    EnQ(basic,1210,qSize);
    EnQ(basic,1209,qSize);
    EnQ(basic,1208,qSize);
    EnQ(basic,1207,qSize);
    EnQ(basic,1005,qSize);
    
    
    cout << endl;
    cout << "IsEmpty = " << basic.isEmpty() << endl;
    cout << "Size = " << basic.size() << endl;
    cout << endl;
    
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    
    cout << endl;
    
    EnQ(basic,34,qSize);
    EnQ(basic,34,qSize);
    EnQ(basic,34,qSize);
    EnQ(basic,34,qSize);
    EnQ(basic,34,qSize);
    EnQ(basic,34,qSize);
    EnQ(basic,34,qSize);
    EnQ(basic,34,qSize);
    EnQ(basic,34,qSize);
    EnQ(basic,34,qSize);
    EnQ(basic,34,qSize);
    EnQ(basic,34,qSize);
    EnQ(basic,34,qSize);
    EnQ(basic,34,qSize);
    EnQ(basic,34,qSize);
    EnQ(basic,34,qSize);
    EnQ(basic,34,qSize);
    
    
    
    EnQ(basic,2221,qSize);
    EnQ(basic,10,qSize);
    EnQ(basic,-11,qSize);
    
    cout << endl;    DeQ(basic, qSize);    
    DeQ(basic, qSize);
    EnQ(basic,32,qSize);
    EnQ(basic,23,qSize);
    EnQ(basic,31,qSize);
    EnQ(basic,30,qSize);
    EnQ(basic,29,qSize);
    EnQ(basic,28,qSize);
    EnQ(basic,25,qSize);
    EnQ(basic,26,qSize);
    DeQ(basic, qSize);
    EnQ(basic,1212,qSize);
    EnQ(basic,1313,qSize);
    EnQ(basic,70,qSize);
    EnQ(basic,68,qSize);
    EnQ(basic,71,qSize);
    EnQ(basic,1414,qSize);
    EnQ(basic,7,qSize);
    
    cout << endl;
    
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
    DeQ(basic, qSize);
}
