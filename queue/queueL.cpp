//queueL.cpp
//A queue class implemented using a linked list implementation. Includes several methods used to address and use imported data.
//Charlie Severson

#include "queueL.h"
#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <string>

using namespace std;

//==============================================================================
// Template queue default constructor
// We intilize, or construct, the global variables to be used throughout the
// queue program. 
//==============================================================================
template <class Q>
	queueL<Q>::queueL() 
		{ 								
    		quantity = 0;							// quantity is set to 0, having being initialized in header as int.
		head = NULL;							// The head of a list is its first node, set to Null.
		tail = NULL;							// The tail of a list refers to the last node in the list, set to Null.
		}
	
//==============================================================================
// List copy constructor
// Performs a deep copy of the input object "S".
//==============================================================================
template <class Q>
	queueL<Q>::queueL(const queueL& S) 
		{
		copy(S);							// Deep copy of S
		}
		
//==============================================================================
// List destructor
// Does a deep removal of the queue values.
//==============================================================================
template<class Q>
	queueL<Q>::~queueL() 
		{
    		LinkedList<Q> *NodeAlpha;					// NodeAlpha pointer is initialized as a method of LinkedList.
    		LinkedList<Q> *NodeGamma;					// NodeGamma pointer is initialized as a method of LinkedList.
    		NodeAlpha = head;						// NodeAlpha is set to head.
    		while (NodeAlpha) 						// While NodeAlpha is true.
    			{
        		NodeGamma = NodeAlpha;					// NodeGamma is set to NodeAlpha.
        		NodeAlpha = NodeAlpha -> next;				// NodeAplha is set to pointer NodeAlpha to next.
        		delete NodeGamma;					// delete NodeGamma to prevent a memory leak. 
    			}
		}

//==============================================================================
// Assignment operator
// Does first a deep removal of memory for the calling
// object, queue, and then a deep copy of the input object S
// The assignment operator does member-wise assignment of
// each data member from the source object.
//==============================================================================
template<class Q>
	void queueL<Q>::operator = (const queueL& S) 
		{
    		LinkedList<Q> *NodeAlpha;					// NodeAlpha pointer is initialized as a method of LinkedList.
    		LinkedList<Q> *NodeBeta;					// NodeBeta pointer is initialized as a method of LinkedList.
    		LinkedList<Q> *NodeGamma;					// NodeGamma pointer is initialized as a method of LinkedList.
    		NodeAlpha = head;						// NodeAlpha set to head. 
    		while (NodeAlpha) 						// While NodeAlpha is true . . .
    			{
        		NodeGamma = NodeAlpha;					// NodeGamma is set to NodeAlpha.
        		NodeAlpha = NodeAlpha -> next;				// NodeAplha is set to pointer NodeAlpha to next.
        		delete NodeGamma;					// This prevetns a memory leak
    			}    

    		NodeBeta = S.head;						// copy constructor is used to initialize in declaration of S.head to NodeBeta.
    		if (NodeBeta) 							// if NodeBeta is true . . .
    			{			
        		head = NodeAlpha = new LinkedList<Q>(NodeBeta -> Value);// head equals NodeAlpha which equals pointer NodeBeta to Value	
        		NodeBeta = NodeAlpha -> next;				// NodeBeta is set to pointer NodeAlpha to next.
    			}
    		while (NodeBeta) 						// while Nodebeta is true . . .
    			{		
        		NodeAlpha -> next = new LinkedList<Q>(NodeBeta -> Value);	// pointer NodeAlpha to next, which equals pointer NodeBeta to Value.
        		NodeAlpha = NodeAlpha -> next;				// NodeAlpha is set to pointer NodeAlpha to next.
        		NodeBeta = NodeBeta -> next;				// NodeBeta is set to pointer NodeBeta to next
    			}
    		quantity = S.quantity;						// copy constructor is used to initialize in declaration of S.quantity.
		}

//==============================================================================
// isEmpty
// Returns true if the list is empty, false otherwise.
//==============================================================================
template<class Q>
	bool queueL<Q>::isEmpty() 
		{
    		if (quantity == 0) 						// If queue is empty
    			{
        		return true;						// Then isEmpty is True
    			}
    		else 								// Else if queue is not empty...
    			{
        		return false;						// Then isEmpty is False
    			}
		}

//==============================================================================
// isFull
// Returns false if the list is empty, true otherwise.
//==============================================================================
template<class Q>
	bool queueL<Q>::isFull() 						
		{
    		return false;							// As we are using a linked list implementation, the queue will never be full, thus isFull is always false.
		}

//==============================================================================
// enqueue
// How values are added to the queue.
// Checks if queue is full, calls expand as needed.
// Value is addd to queue
//==============================================================================
template<class Q>
	void queueL<Q>::enqueueL(Q Value) 
		{
  		LinkedList<Q> *NodeNew = new LinkedList<Q>;			// pointer NodeNew is initialized as a method of LinkedList and set to new LinkedList.
    		NodeNew -> Value = Value;					// pointer NodeNew to Value which is set to Value.
		NodeNew -> next = NULL;						// pointer NodeNew to Next which is set to Null.
    		if (head != NULL) 						// If head does not equal Null . . .
    			{
			tail -> next = NodeNew;					// pointer tail to next which is set to NodeNew.
			NodeNew -> next = NULL;					// pointer Nodenew to next which is set to Null.
			tail = tail -> next;        				// tail is set to pointer tail to next.
    			}
    		else 								// else if head does equal Null . . .
    			{
        		head = NodeNew;						// head is set to NodeNew.
        		tail = head;						// tail is set to head.
       			}			
    		quantity++;							// quantity is postively iterated to reflect quantity change. 
		}

//==============================================================================
// dequeue
// How values are remvoed from the queue.
// Checks if queue is empty, if not it removes the topmost value of the queue
// array / list. The head is changed appropriotly. 
//==============================================================================
template<class Q>
	Q queueL<Q>::dequeueL()
		{
		LinkedList<Q> *NodeGamma;					// NodeGamma pointer is initialized as a method of LinkedList.
		assert (head != NULL);						// check that head does not equal Null.
		NodeGamma = head;						// NodeGamma is set to head.
		head = NodeGamma -> next;					// head is set to pointer NodeGamma to next.
		delete NodeGamma;						// This prevents a memory leak
		quantity--;							// quantity is negatively iterated to reflect quantity change. 
		}
		
//==============================================================================
// size
// Returns the current size of the queue
//==============================================================================
template<class Q>
	int queueL<Q>::size() 							
		{
    		return quantity;						// size is the method of the len of queue, but I return "quantity" because it helps clarify. 
		}







