//queneA.cpp
//A queue class that uses an list to hold data. Includes several methods used to address and use said data. 
//Charlie Severson

#include "queueA.h"

using namespace std;

//==============================================================================
// Template queue default constructor
// We intilize, or construct, the global variables to be used throughout the
// queue program. 
//==============================================================================
template <class Q>
	queue<Q>::queue(int i) 								
		{ 								
	    	space = i;							// space is set to i, which is in turn set to 100. Space is the size of the list in use. 
		list = new Q[space];						// list is set to space
	    	quantity = 0;							// quantity is set to 0, having being initialized in header as int.
	    	head = 0;							// head is set to 0, having being initialized in header as int. This will serve as the "top" of our queue.
	    	tail = 0;							// tail is set to 0, having being initialized in header as int. This will serve as the "bottom" of our queue.
		}

//==============================================================================
// List copy constructor
// Performs a deep copy of the input object "S".
//==============================================================================
template <class Q>
	queue<Q>::queue(const queue& S) 					//A copy constructor is a special constructor for a class/struct that is used to make a copy of an existing instance.
		{
	    	space = S.space;						// copy constructor is used to initialize in declaration of S.Space.
	    	quantity = S.quantity;						// copy constructor is used to initialize in declaration of S.quantity
	    	list = new Q[S.space];						// list is set to S.space
	    	for (int j = 0; j < S.quantity; j++) 				// for the length of the queue (quantity)
	    		{
			list[j] = S.list[j];					// copy constructor is used to initialize in declaration of S.list (and all of its componants)
	    		}
	    	head = S.head;							// copy constructor is used to initialize in declaration of S.head
	    	tail = S.tail;							// copy constructor is used to initialize in declaration of S.tail
		}

//==============================================================================
// List destructor
// Does a deep removal of the queue values.
//==============================================================================
template<class Q>
	queue<Q>::~queue() 
		{
    		delete [] list;							// This prevents a memory leak (destructor)
		}
		
//==============================================================================
// Assignment operator
// Does first a deep removal of memory for the calling
// object, queue, and then a deep copy of the input object S
// The assignment operator does member-wise assignment of
// each data member from the source object.
//==============================================================================
template<class Q>
	void queue<Q>::operator = (const queue& S) 
		{
   		if (&S != this)							// if the pointer to S does not equal S . . .
   		 	{
        		delete [] list;						// Deep removal of the memory for the calling object						
        		space = S.space;					// copy constructor is used to initialize in declaration of S.Space.
        		quantity = S.quantity;					// copy constructor is used to initialize in declaration of S.quantity
       			list = new Q[S.space];					// list is set to S.space
        		for (int j = 0; j < S.quantity; j++) 			// for the length of the queue (quantity)
        			{
            			list[j] = S.list[j];				// copy constructor is used to initialize in declaration of S.list (and all of its componants)
            			}
    			}
		head = S.head;							// copy constructor is used to initialize in declaration of S.head
		space = S.space;						// copy constructor is used to initialize in declaration of S.space		
		tail = S.tail;							// copy constructor is used to initialize in declaration of S.tail
		}

//==============================================================================
// isEmpty
// Returns true if the list is empty, false otherwise.
//==============================================================================
template<class Q>
	bool queue<Q>::isEmpty() 						
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
	bool queue<Q>::isFull() 
		{
    		if (quantity >= space) 						// If queue is full or greater than full
    			{
        		return true;						// Then isFull is True
    			}
    		else 								// Else if queue is not Full...		
    			{
        		return false;						// Then isFull is False
    			}
		}
		
//==============================================================================
// enqueue
// How values are added to the queue.
// Checks if queue is full, calls expand as needed.
// Value is addd to queue
//==============================================================================
template<class Q>
	void queue<Q>::enqueue(Q Value) 					
		{
    		if (quantity < space) 						// if the quantity of customers is less than the space available . . . 
    			{
    			list[tail] = Value;					// the tail value of the list  is set to the input Value.
    			tail = (tail + 1) % space;				// tail is set to tail + 1 mod space, or the remainder of tail + 1 / space
    			quantity++;						// quantity is iterated to reflect this change to the queue. 
    			}    
    		else 
    			{
        		expand();						// call the expand method, which will increase the size of the available space by 10, preventing overflow.
        		list[tail] = Value;					// the tail value of the list  is set to the input Value.
        		tail = (tail + 1) % space;				// tail is set to tail + 1 mod space, or the remainder of tail + 1 / space	
        		quantity++;						// quantity is postively iterated to reflect this change to the queue. 
   			}
		}
		
//==============================================================================
// dequeue
// How values are removed from the queue.
// Checks if queue is empty, if not it removes the topmost value of the queue
// list / list. The head is changed appropriotly. 
//==============================================================================
template<class Q>
	Q queue<Q>::dequeue()
		{
    		if (quantity > 0) 						// if the length of the values in the queue is greater than one (i.e., it contains values) . . .
    			{
    			Q push;							// initialize push, which is synonymous with the stack method
    			push = list[head];					// set push to the first value of the queue
    			head = (head + 1) % space;				// head is set to head + 1 mod space, or the remainder of head + 1 / space
    			quantity--;						// quantity is negatively iterated to reflect this change to the queue. 	
    			return push;						// return the value which has been removed from the first postion of the queue.
    			}
    		else 						// else if the length of the values in the queue is less than one (i.e., it does not contains values) . . .
    			{
        		cout << "The Queue is Empty. Please check the inputFile." <<endl; // print a statement displaying the queue is empty, so there is nothing to remove. 
    			}
		}
		
//==============================================================================
// Size
// Returns size of Queue list
//==============================================================================
template<class Q>
	int queue<Q>::size() 
		{
    		return quantity;						// size is the method of the len of queue, but I return "quantity" because it helps clarify. 
		}

//==============================================================================
// expand
// The method of preventing an overflow.
// If the queue is "full", this function will be called and
// then the stack size will be increased by 10.
//==============================================================================
template<class Q>
	void queue<Q>::expand() 
		{
    		Q *val;								// Declare pointer to 'val', our temporary value
    		val = new Q[space + 10];					// We have to create memory to be added
    		for (int i = 0; i < quantity; i++) 				// quantity is updated to reflect value changes
    			{
        		val[i] = list[head];					// This is how we address new memory space usage
        		head = (head + 1) % space;				// Aggragating the memory changes
    			}
    		delete [] list;							// This prevents a memory leak
    		list = val;
    		head = 0;							// Reset head to value 0
    		tail = quantity;						// Reset tail to end value
    		space = space + 10;						// Increase size by 10
		}
		


//==============================================================================
// first
// first returns the first value in the list, which is useful for retaining a
// value of head, such as in the checkout program. 
//==============================================================================
template<class Q>
	Q queue<Q>::first() 
		{ 								
    		Q first;							// first is initialized as a method of Q
    		if (! isEmpty()) 						// If the queue is not Full . . .
    			{
        		first = list[head];					// the first value in the queue is the head, and this becomes the value of first.
        		return first;						// return the first value of Q
    			}
		}

