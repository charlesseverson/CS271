//queueL.h
//Header file for queueL. Implements all the methods used to implement the linked list queue. 
//Charlie Severson

#ifndef _QUEUEL_H
#define _QUEUEL_H
#include <cstdlib>
#include <string>
using namespace std;

//==============================================================================
// LinkedList header
// LinkedList establishes the nessasary componants for a linked list structure 
// queue.
//==============================================================================
template <class Q>
	class LinkedList							// LinkedList establishes the nessasary componants for a linked list structure queue.
		{
	    	public:
	    		LinkedList<Q> *next;					// pointer next refers to the next list
	    		Q Value;						// Value is a mothod of Q which will be used to retain a value. 
		};

//==============================================================================
// queueL header
// queueL contains a LinkedList which is used to hold the data.
// It contains several methods which are used to check whether the list is
// full or not, add or remove values, and return the size of the queue.
//==============================================================================		
template <class Q>
	class queueL 
		{
		public:
			queueL();						// Default constructor, which will intilize, or construct, the global variables to be used throughout the queue program. 
		    	queueL(const queueL& S);				// Copy constructor, which performs a deep copy of the input object "S".
		    	~queueL();						// Destructor, which does a deep removal of the queue values.
		    
		    	void operator = (const queueL& S);			// The assignment operator does member-wise assignment of each data member from the source object, S. 
		    	bool isEmpty();						// Checks if the queue is empty.
		    	bool isFull();						// Checks if the queue is full.
		    	void enqueueL(Q Value);					// How values are added to the queue.
		    	Q dequeueL();						// How values are removed from the queue.
		    	int size();						// size is the current quantity of the values inside the queue.
		    
	    	private:
	    		int quantity;						// quantity represents the number of values in the queue.
	    		LinkedList<Q> *head;					// head represents the topmost value of the queue.
	    		LinkedList<Q> *tail;					// tail represents the bottommost value of the queue. As a queue is LILO, whenever a value is appended to the queue, this is what is updated. 
	    		

		};

#include "queueL.cpp"
#endif 

