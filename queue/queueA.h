//queueA.h
//Header file for queueA. Implements all the methods used to implement the queue. 
//Charlie Severson

#ifndef _QUEUEA_H
#define _QUEUEA_H


#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Customer.h"
using namespace std;

template <class Q>
class queue;									// The templated class of queue is initialized.

//==============================================================================
// queueA header
// queueA is a queue class for integers which uses a list to hold the data.
// It contains several methods which are used to check whether the list is
// full or not, add or remove values, and a method to prevent memory overflow 
// by resizing the array.
//==============================================================================
template <class Q>
class queue 
	{
    
	public:
		Q *list;
	    
		queue(int i = 100);						// Default constructor, which will intilize, or construct, the global variables to be used throughout the queue program. 
	    	queue(const queue& S);						// Copy constructor, which performs a deep copy of the input object "S".
	    	~queue(); 							// Destructor, which does a deep removal of the queue values.
		                               
	    	void operator = (const queue& S);				// The assignment operator does member-wise assignment of each data member from the source object, S. 
	   	int space;							// Space is the size of the list in use. 
	   	bool isEmpty();							// Checks if the queue is empty.	
	   	bool isFull();							// Checks if the queue is full.
	   	void enqueue(Q Value);						// How values are added to the queue.
	    	Q dequeue();							// How values are removed from the queue.	
	    	int size();							// size is the current quantity of the values inside the queue.
	    	void expand();							// this method expands the queue to prevent overflow.
	    	Q first();							// first returns the first value in the list.	
	    	
    
	private:
	    int quantity;							// quantity represents the number of values in the queue.	
	    int head;								// head represents the topmost value of the queue.
	    int tail;								// tail represents the bottommost value of the queue. As a queue is LILO, whenever a value is appended to the queue, this is what is updated. 
	};

#include "queueA.cpp"
#endif

