/* File: main.cpp
 * --------------
 * Simple main module for PQueueT testing.
 */
 
#include <iostream>
#include "genlib.h"
#include "pqueueT.h"
#include "random.h"

/*
 * Use these functions to test your PQueue implementation.
 * Comment out those tests you aren't interested in running
 * while you are mid-development.
 */

void StructTest();
void VectorTest();

int main()
{
    Randomize();
        
    //StructTest();
    VectorTest();
   
    return (0);
}

// Test routines for Vector of structs test as pqueueT template type

struct testT1 {
    int priority;
    string name;
};

void EnQ1(PQueueT<Vector<testT1> > &pq, Vector<testT1> value, int & count) {
    pq.enqueue(value);
    //cout << "Size = " << pq.size() << ":" << ++count << endl;
    //pq.printDebuggingInfo();
}
void DeQ1(PQueueT<Vector<testT1> > &pq, int & count) {
    cout << "DeQ = " << pq.dequeueMax().size() << endl;
    //cout << "Size = " << pq.size() << ":" << --count << endl;
    //pq.printDebuggingInfo();
}

int MoreElementsFirst(Vector<testT1> one, Vector<testT1> two) {
	if (one.size() == two.size()) return 0;
	if (one.size() < two.size()) return -1;
	return 1;
}

int FewerElementsFirst(Vector<testT1> one, Vector<testT1> two) {
    if (one.size() == two.size()) return 0;
    if (one.size() > two.size()) return -1;
    return 1;
}

void VectorTest() {
    
    Vector<testT1> vt1;
    Vector<testT1> vt2;
    
    PQueueT<Vector<testT1> > basic(FewerElementsFirst);
    
    cout << "Before Enqueue: IsEmpty = " << basic.isEmpty() << endl;
    cout << "Before Enqueue: Size = " << basic.size() << endl;
    
    basic.printDebuggingInfo();
    
    int qSize = 0;
    
    for (int i = 0; i < 10; i++) {
        testT1 t;
        int item = RandomInteger(1001, 2001);
        t.name = "name" + IntegerToString(item);
        t.priority = item;
        vt1.add(t);
    }
    
    EnQ1(basic,vt1,qSize);
    basic.printDebuggingInfo();
    
    for (int i = 0; i < 20; i++) {
        testT1 t;
        int item = RandomInteger(5001, 7001);
        t.name = "name" + IntegerToString(item);
        t.priority = item;
        vt2.add(t);
    }
    
    EnQ1(basic,vt2,qSize);
    basic.printDebuggingInfo();
    
    for (int i = 0; i < 2; i++)
        DeQ1(basic, qSize);
}

//****************************************************//

// Test routines for struct test as pqueueT template type

struct testT {
    int priority;
    string name;
};

void EnQ(PQueueT<testT> &pq, testT value, int & count) {
    pq.enqueue(value);
    //cout << "Size = " << pq.size() << ":" << ++count << endl;
    //pq.printDebuggingInfo();
}
void DeQ(PQueueT<testT> &pq, int & count) {
    cout << "DeQ = " << pq.dequeueMax().name << endl;
    //cout << "Size = " << pq.size() << ":" << --count << endl;
    //pq.printDebuggingInfo();
}

int HigherPriorityFirst(testT one, testT two) {
	if (one.priority == two.priority) return 0;
	if (one.priority < two.priority) return -1;
	return 1;
}

int LowerPriorityFirst(testT one, testT two) {
	if (one.priority == two.priority) return 0;
	if (one.priority > two.priority) return -1;
	return 1;
}

int LowerNameFirst(testT one, testT two) {
	if (one.name == two.name) return 0;
	if (one.name > two.name) return -1;
	return 1;
}

void StructTest() {
    PQueueT<testT> basic(LowerNameFirst);
    
    cout << "Before Enqueue: IsEmpty = " << basic.isEmpty() << endl;
    cout << "Before Enqueue: Size = " << basic.size() << endl;
    
    basic.printDebuggingInfo();
    
    int qSize = 0;
    
    for (int i = 0; i < 10; i++) {
        testT t;
        int item = RandomInteger(1001, 2001);
        t.name = "name" + IntegerToString(item);
        t.priority = item;
        EnQ(basic,t,qSize);
    }
    
    basic.printDebuggingInfo();
    
    for (int i = 0; i < 10
         ; i++)
        DeQ(basic, qSize);
}
