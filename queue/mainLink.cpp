//mainLink.cpp
//This file includes several methods which will test my implementation of a linked list queueL. 
//Charlie Severson

#include <iostream>
#include <string>
#include "queueL.h"
#include "assert.h"

using namespace std;

void testQuantityInt() 
	{
	
    	queueL<int> q;
    	q.enqueueL(0);
    	q.enqueueL(1);
    	q.enqueueL(2);
    	q.enqueueL(3);
    	
    	cout << "\n" << endl;
    	cout << "Test of integer size in queueL." << endl;
    	cout << "\n" << endl;
    	cout << "#1 should be True." << endl;
    	if (q.size() == 4)
    		{
    		cout << "True." << endl;
    		}
    	else
    		{
    		cout << "False." << endl;
    		}
	cout << "#2 should be False." << endl;
    	if (q.size() == 5)
    		{
    		cout << "True." << endl;
    		}
    	else
    		{
    		cout << "False." << endl;
    		}
	}

void testQuantityChar()
	{
	
    	queueL<char> q;
    	q.enqueueL('q');
    	q.enqueueL('b');
    	q.enqueueL('c');
    	q.enqueueL('d');
    	
    	cout << "\n" << endl;
    	cout << "Test of string size in queueL." << endl;
    	cout << "\n" << endl;
    	cout << "#1 should be True." << endl;
    	if (q.size() == 4)
    		{
    		cout << "True." << endl;
    		}
    	else
    		{
    		cout << "False." << endl;
    		}
	cout << "#2 should be False." << endl;
    	if (q.size() == 5)
    		{
    		cout << "True." << endl;
    		}
    	else
    		{
    		cout << "False." << endl;
    		}
	}

void testEnqueueLInt() 
	{
    	queueL<int> q;

    	for (int i = 0; i < 100; i++)
    		{
        	q.enqueueL(i);
    		}
    		
    	cout << "\n" << endl;
    	cout << "Test of enqueueL integers in queueL." << endl;
    	cout << "\n" << endl;
    	cout << "#1 should be True." << endl;
    	if (q.size() == 100)
    		{
    		cout << "True." << endl;
    		}
    	else
    		{
    		cout << "False." << endl;
    		}
	cout << "#2 should be False." << endl;
    	if (q.size() == 101)
    		{
    		cout << "True." << endl;
    		}
    	else
    		{
    		cout << "False." << endl;
    		}
	}
void testEnqueueLChar() 
	{
    	queueL<char> q;
    	for (int i = 0 ; i < 100; i++) 
    		{
        	q.enqueueL('k');
    		}
    		
    	cout << "\n" << endl;
    	cout << "Test of enqueueL string in queueL." << endl;
    	cout << "\n" << endl;
    	cout << "#1 should be True." << endl;
    	if (q.size() == 100)
    		{
    		cout << "True." << endl;
    		}
    	else
    		{
    		cout << "False." << endl;
    		}
	cout << "#2 should be False." << endl;
    	if (q.size() == 101)
    		{
    		cout << "True." << endl;
    		}
    	else
    		{
    		cout << "False." << endl;
    		}
	}

void testDequeueLInt() 
	{
    	queueL<int> q;

    	for (int i = 0; i < 100; i++)
    		{
        	q.enqueueL(i);
      		}
    	for (int i = 0; i < 100; i++)
    		{
        	q.dequeueL();
    		}
    		
    	cout << "\n" << endl;
    	cout << "Test of dequeueL integer in queueL." << endl;
    	cout << "\n" << endl;
    	cout << "#1 should be True." << endl;
    	if (q.size() == 0)
    		{
    		cout << "True." << endl;
    		}
    	else
    		{
    		cout << "False." << endl;
    		}
	cout << "#2 should be False." << endl;
    	if (q.size() == 1)
    		{
    		cout << "True." << endl;
    		}
    	else
    		{
    		cout << "False." << endl;
    		}	   
	}


void testDequeueLChar() 
	{
    	queueL<char> q;

    	for (int i = 0; i < 100;i++)
    		{
        	q.enqueueL('k');
    		}
    	for (int i = 0; i < 100;i++)
    		{
        	q.dequeueL();
    		}   
    		 
	cout << "\n" << endl;
    	cout << "Test of dequeueL string in queueL." << endl;
    	cout << "\n" << endl;
    	cout << "#1 should be True." << endl;
    	if (q.size() == 0)
    		{
    		cout << "True." << endl;
    		}
    	else
    		{
    		cout << "False." << endl;
    		}
	cout << "#2 should be False." << endl;
    	if (q.size() == 1)
    		{
    		cout << "True." << endl;
    		}
    	else
    		{
    		cout << "False." << endl;
    		}
	}

int main() 
	{
    	testQuantityInt(); 
	testQuantityChar();
	testEnqueueLInt(); 
	testEnqueueLChar();
	testDequeueLInt(); 
	testDequeueLChar();

	cout << "\n" << endl;
  	cout << "All tests completed successfully." << endl;
  	cout << "\n" << endl;
    	return 0;
	}

