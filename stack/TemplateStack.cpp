//TemplateStack.cpp
//Templated Stack class methods
//Charlie Severson

#include "TemplateClass.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//==============================================================================
// Template stack default constructor
//==============================================================================
template<class T> Stack<T>::Stack(void)
	{
	Stack_ = 0;								//Stack intialized as empty
	size_ = 100;								//Default size set to 100
	values_ = new T [size_];						//Allocate storage space for array of size representation 
	}

//==============================================================================
// List copy constructor
// Performs a deep copy of the input object "S".
//==============================================================================
template<class T> Stack<T>::Stack(const Stack &S)
	{
	copy(S);								//Deep copy of S
	}
	
//==============================================================================
// List destructor
// Does a deep removal of the stack values.
//==============================================================================
template<class T> Stack<T>::~Stack()
	{
	delete []values_;							//This prevents a memory leak
	}

//==============================================================================
// Assignment operator
// Does first a deep removal of memory for the calling
// object, Stack and then a deep copy of the input object S
// The assignment operator does member-wise assignment of
// each data member from the source object.
//==============================================================================
template<class T> Stack<T> Stack<T>::operator = (const Stack &S)
	{
	delete []values_;							//Deep removal of the memory for the calling object
	copy(S);			
	return *this;								//Literally returns the source object, S. 
	}

//==============================================================================
// isEmpty
// The isEmpty method is a boolean method indicating if the stack
// is currently empty or not. An empty stack contains 0 items. This
// method is useful to precede a pop method to avoid an error by
// popping from an empty stack.
//==============================================================================
template<class T> bool Stack<T>::isEmpty()
	{
	if (Stack_ == 0)							//if stack is empty
		{
		return 1;							//true
		}
	return 0;								//Stack is not empty if false
	}


//==============================================================================
// push
// The push method adds element x to the top of the stack. The stack
// is an ordered structure meaning the items in the stack retain the
// order in which they are added. The top of the stack is the location
// of the most recently added item; the bottom of the stack contains
// the oldest item in the stack.
//==============================================================================
template<class T> void Stack<T>::push(T input)
	{
	if (Stack_ == size_)							//if the size of stack is equal to the array size_
		{
		expand();							//call expand method
		values_[Stack_] = input;					//input is added to the stack
		Stack_++;
		return;							//Stack inrements by 1
		}
	else
		{
		values_[Stack_] = input;					//input is added to the stack
		Stack_++;							//Stack inrements by 1
		return;								//return reflected changes
		}
	}

//==============================================================================
// pop
// The pop method removes and returns the top item on the stack;
// this is the most recently added item in the stack. Each other item
// in the stack moves up one location so that the second most recently
// added item is now on the top of the stack and ready to be accessed
// next via another pop method. It is generally an error to attempt to
// pop from an empty stack.
//==============================================================================
template<class T> T Stack<T>::pop()
	{
	if (isEmpty() == 1)
		{
		return values_[0];						//stack is empty. This is recoverable as we just assert that when trying to pop an empty stack, nothing is returned. 
		}
	else
		{
		T reserve = values_[Stack_ - 1];				//temp reserve holds value to be removed
		Stack_--;							//stack deincrements by 1
		return reserve;							//temp reserve returned
		}
	}


//==============================================================================
// expand
// The method of preventing a stack overflow.
// If the stack is "full", this function will be called and
// then the stack size will be increased by 10.
//==============================================================================
template<class T> void Stack<T>::expand()
	{
	T *val;									//Declare pointer to 'val', our temporary value
	size_ = size_ + 10;							//The expand function adds 10 to the stack size
	val = new T [size_];							//temp val records the new value of size_
	for (int i = 0; i < Stack_ ; i++)					//Stack_ is updated to reflect value changes
		{
		val[i] = values_[i];						//values is loaded with new space
		}
	delete[] values_;							//Incur delete to prevent memory leak
	values_ = val;								//values_ adopts temp val
	
	}

	

