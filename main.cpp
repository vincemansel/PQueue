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
int main()
{
    PQueue basic;
    
    cout << "Before Enqueue: IsEmpty = " << basic.isEmpty() << endl;
    cout << "Before Enqueue: Size = " << basic.size() << endl;

    basic.enqueue(66);
    cout << "Size = " << basic.size() << endl;
    basic.enqueue(55);
    cout << "Size = " << basic.size() << endl;
    basic.enqueue(44);
    cout << "Size = " << basic.size() << endl;
    basic.enqueue(33);
    cout << "Size = " << basic.size() << endl;
    basic.enqueue(22);
    cout << "Size = " << basic.size() << endl;
    basic.enqueue(11);
    cout << "Size = " << basic.size() << endl;

//    basic.enqueue(77);
//    cout << "Size = " << basic.size() << endl;
//    basic.enqueue(88);
//    cout << "Size = " << basic.size() << endl;
//    basic.enqueue(99);
//    cout << "Size = " << basic.size() << endl;
//    basic.enqueue(1010);
//    cout << "Size = " << basic.size() << endl;
//    basic.enqueue(1313);
//    cout << "Size = " << basic.size() << endl;
//    basic.enqueue(1414);
//    cout << "Size = " << basic.size() << endl;
    
    cout << "IsEmpty = " << basic.isEmpty() << endl;
    cout << "Size = " << basic.size() << endl;

    cout << "DeQ = " << basic.dequeueMax() << endl;
    cout << "Size = " << basic.size() << endl;    
    cout << "DeQ = " << basic.dequeueMax() << endl;
    cout << "Size = " << basic.size() << endl;
    cout << "DeQ = " << basic.dequeueMax() << endl;
    cout << "Size = " << basic.size() << endl;
    cout << "DeQ = " << basic.dequeueMax() << endl;
    cout << "Size = " << basic.size() << endl;
    cout << "DeQ = " << basic.dequeueMax() << endl;
    cout << "Size = " << basic.size() << endl;
    cout << "DeQ = " << basic.dequeueMax() << endl;
    cout << "Size = " << basic.size() << endl;




    
//    basic.enqueue(33);
//    cout << "Size = " << basic.size() << endl;
//    basic.enqueue(22);
//    cout << "Size = " << basic.size() << endl;
//    basic.enqueue(11);
//    cout << "Size = " << basic.size() << endl;
//    
//    basic.enqueue(-11);
//    cout << "Size = " << basic.size() << endl;
//    cout << endl;
//    
//    cout << "DeQ = " << basic.dequeueMax() << endl;
//    cout << "Size = " << basic.size() << endl;
//    basic.enqueue(33);
//    cout << "Size = " << basic.size() << endl;
//    basic.enqueue(32);
//    cout << "Size = " << basic.size() << endl;
//    cout << "DeQ = " << basic.dequeueMax() << endl;
//    cout << "Size = " << basic.size() << endl;
//    basic.enqueue(1212);
//    cout << "Size = " << basic.size() << endl;
//    basic.enqueue(1313);
//    cout << "Size = " << basic.size() << endl;
//    basic.enqueue(1414);
//    cout << "Size = " << basic.size() << endl;
//    cout << "DeQ = " << basic.dequeueMax() << endl;
//    cout << "Size = " << basic.size() << endl;    
//    cout << "DeQ = " << basic.dequeueMax() << endl;
//    cout << "Size = " << basic.size() << endl;
//    cout << "DeQ = " << basic.dequeueMax() << endl;
//    cout << "Size = " << basic.size() << endl;
//    cout << "DeQ = " << basic.dequeueMax() << endl;
//    cout << "Size = " << basic.size() << endl;
//    cout << "DeQ = " << basic.dequeueMax() << endl;
//    cout << "Size = " << basic.size() << endl;
//    cout << "DeQ = " << basic.dequeueMax() << endl;
//    cout << "Size = " << basic.size() << endl;
//    cout << "DeQ = " << basic.dequeueMax() << endl;
//    cout << "Size = " << basic.size() << endl;
//    cout << "DeQ = " << basic.dequeueMax() << endl;
//    cout << "Size = " << basic.size() << endl;
//    cout << "DeQ = " << basic.dequeueMax() << endl;
//    cout << "Size = " << basic.size() << endl;
//    cout << "DeQ = " << basic.dequeueMax() << endl;
//    cout << "Size = " << basic.size() << endl;
//    basic.enqueue(1212);
//    cout << "Size = " << basic.size() << endl;
//    basic.enqueue(1414);
//    cout << "Size = " << basic.size() << endl;
//    basic.enqueue(33);
//    cout << "Size = " << basic.size() << endl;
//    basic.enqueue(1313);
//    cout << "Size = " << basic.size() << endl;
//    cout << "DeQ = " << basic.dequeueMax() << endl;
//    cout << "Size = " << basic.size() << endl;
//    basic.enqueue(44);
//    cout << "Size = " << basic.size() << endl;
//    basic.enqueue(66);
//    cout << "Size = " << basic.size() << endl;
//    basic.enqueue(55);
//    cout << "Size = " << basic.size() << endl;
//    basic.enqueue(1717);
//    cout << "Size = " << basic.size() << endl;
//    cout << "Size = " << basic.size() << endl;
//    cout << "DeQ = " << basic.dequeueMax() << endl;
//    cout << "Size = " << basic.size() << endl;
//    cout << "DeQ = " << basic.dequeueMax() << endl;
//    cout << "Size = " << basic.size() << endl;
//    cout << "DeQ = " << basic.dequeueMax() << endl;
//    cout << "Size = " << basic.size() << endl;
//    cout << "DeQ = " << basic.dequeueMax() << endl;
//    cout << "Size = " << basic.size() << endl;
//    cout << "DeQ = " << basic.dequeueMax() << endl;
//    cout << "Size = " << basic.size() << endl;
//    cout << "DeQ = " << basic.dequeueMax() << endl;
//    cout << "Size = " << basic.size() << endl;
//



    //cout << "DeQ = " << basic.dequeueMax() << endl; // Should Error out
    
    
    
//	BasicPQueueTest();
//	MorePQueueTest();
//	PQueueSortTest();
//   	PQueuePerformance();
//    cout << endl << "Goodbye and have a nice day!" << endl;
    return (0);
}

