//TemplateClass.h
//Stack class header 
//Charlie Severson

#ifndef _TEMPLATESTACK_H
#define _TEMPLATESTACK_H
#include <iostream>
#include <stdlib.h>

using namespace std;

//==============================================================================
// Stack ADT
//The stack is an ordered data structure storing multiple items, typically of the same
//data type. The stack is ordered because the order of the items added to the stack
//dictates the order in which items may be removed. It is a LIFO structure, meaning
//last-in, first-out. Items in the stack are removed in reverse order they are added; the
//last item to be added to the stack is the next item to be removed.
//The stack supports two basic access methods, a push operation for adding an item
//to the stack and a pop operation to remove items. The stack may support auxiliary
//methods to access the number of items in the stack or to peek at an item on the top.
//==============================================================================


//==============================================================================
// Stack class header
// Stack creates the methods nessasary to replicate the functions of a stack.
// such as push and pop, as well as other nessasary operations, such as expand
//==============================================================================
template< class T > class Stack
	{
	public:
								
		Stack(void);							// Default constructor, which will intilize, or construct, the global variables to be used throughout the queue program. 
		Stack(const Stack &s);						// Copy constructor, which performs a deep copy of the input object "S".
		~Stack(void);							// Destructor, which does a deep removal of the queue values.
	
		Stack operator = (const Stack &S);				// The assignment operator does member-wise assignment of each data member from the source object, S. 
		friend  ostream& operator << (ostream &os, Stack<T> &S) 	// In principle, private and protected members of a class cannot be accessed from outside the same class in which they are declared. However, this rule does not affect friends.
			{
			for(int i = 0; i < S.Stack_; i++)			// For the length of S.Stack (the size of the stack)
				{
				os << S.values_[i] << endl;			// This operator (<<) applied to an output stream is known as insertion operator, which performs an output operation on a stream generally involving some sort of formatting of the data,
										// where os is the identifier of a ostream object and S.values_[i] is an object of any type.
				}
			return os;					
			}
		bool isEmpty();							//Checks if stack is empty
		
		void push(T input);						// Much like a Pez dispenser, a stack "pushes" new items in, and 
										// "pops" old items out. This is the push, or add, to the stack 
										// the value of input
		T pop();							// Because a stack is LIFO, this will pop of the "Last In"
		
		T *values_;							// The pointer Values references the values in the stack
		int size_;							// size_ is the current length of the values inside the stack
		int Stack_;							// Stack acts as the representation of the size of the stack. 
	
	private:
		void expand(); 							// Expanding the stack to prevent overflow

	};
	
#include "TemplateStack.cpp"
#endif
