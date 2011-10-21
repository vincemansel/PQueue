/* File: main.cpp
 * --------------
 * Simple main module for PQueue assignment.
 */
 
#include "pqueuetest.h"
#include "performance.h"
#include <iostream>
#include "genlib.h"
#include "pqueue.h"


/*
 * Use these functions to test your PQueue implementation.
 * Comment out those tests you aren't interested in running
 * while you are mid-development.
 */

void EnQ(PQueue &pq, int value, int & count) {
    pq.enqueue(value
               
               
               
               \
               );
    cout << "Size = " << pq.size() << ":" << ++count << endl;
}
void DeQ(PQueue &pq, int & count) {
    cout << "DeQ = " << pq.dequeueMax() << endl;
    cout << "Size = " << pq.size() << ":" << --count << endl;   
}

int main()
{
    PQueue basic;
    
    cout << "Before Enqueue: IsEmpty = " << basic.isEmpty() << endl;
    cout << "Before Enqueue: Size = " << basic.size() << endl;

    int qSize = 0;
    
    EnQ(basic,66,qSize);
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
    EnQ(basic,1414,qSize);

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
    EnQ(basic,21,qSize);
    EnQ(basic,10,qSize);
    EnQ(basic,-11,qSize);
    
    cout << endl;    DeQ(basic, qSize);    
    DeQ(basic, qSize);
    EnQ(basic,32,qSize);
    EnQ(basic,23,qSize);
    DeQ(basic, qSize);
    EnQ(basic,1212,qSize);
    EnQ(basic,1313,qSize);
    EnQ(basic,1414,qSize);
    
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
    
    
    
//	BasicPQueueTest();
//	MorePQueueTest();
//	PQueueSortTest();
//   	PQueuePerformance();
//    cout << endl << "Goodbye and have a nice day!" << endl;
    return (0);
}

