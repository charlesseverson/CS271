//mainArray.cpp
//This file contains the functions by which I will test my implementations of an array Queue. 
//Charlie Severson

#include <iostream>
#include <string>
#include "queueA.h"
#include "assert.h"

using namespace std;

void testQuantityInt() 
	{
	
    	queue<int> q;
    	q.enqueue(0);
    	q.enqueue(1);
    	q.enqueue(2);
    	q.enqueue(3);
    	
    	cout << "\n" << endl;
    	cout << "Test of integer size in queue." << endl;
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
	
    	queue<char> q;
    	q.enqueue('q');
    	q.enqueue('b');
    	q.enqueue('c');
    	q.enqueue('d');
    	
    	cout << "\n" << endl;
    	cout << "Test of string size in queue." << endl;
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

void testEnqueueInt() 
	{
    	queue<int> q;

    	for (int i = 0; i < 100; i++)
    		{
        	q.enqueue(i);
    		}
    		
    	cout << "\n" << endl;
    	cout << "Test of enqueue integers in queue." << endl;
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
void testEnqueueChar() 
	{
    	queue<char> q;
    	for (int i = 0 ; i < 100; i++) 
    		{
        	q.enqueue('k');
    		}
    		
    	cout << "\n" << endl;
    	cout << "Test of enqueue string in queue." << endl;
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

void testDequeueInt() 
	{
    	queue<int> q;

    	for (int i = 0; i < 100; i++)
    		{
        	q.enqueue(i);
      		}
    	for (int i = 0; i < 100; i++)
    		{
        	q.dequeue();
    		}
    		
    	cout << "\n" << endl;
    	cout << "Test of dequeue integer in queue." << endl;
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


void testDequeueChar() 
	{
    	queue<char> q;

    	for (int i = 0; i < 100;i++)
    		{
        	q.enqueue('k');
    		}
    	for (int i = 0; i < 100;i++)
    		{
        	q.dequeue();
    		}   
    		 
	cout << "\n" << endl;
    	cout << "Test of dequeue string in queue." << endl;
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

void testExpand() 
	{
	queue<int>q;
	
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.dequeue();
	q.dequeue();
	q.dequeue();
	
	cout << "\n" << endl;
    	cout << "Test of expand in queue." << endl;
    	cout << "\n" << endl;
    	cout << "#1 should be True." << endl;
    	if (q.dequeue() == 4)
    		{
    		cout << "True." << endl;
    		}
    	else
    		{
    		cout << "False." << endl;
    		}
	cout << "#2 should be True." << endl;
    	if (q.dequeue() == 5)
    		{
    		cout << "True." << endl;
    		}
    	else
    		{
    		cout << "False." << endl;
    		}	   
	
	for (int k = 0; k < 150; k++) 
		{
		q.enqueue(k);
	    	}
	for (int j = 0; j < 147; j++) 
		{
		q.dequeue();
	    	}
    	cout << "#3 should be True." << endl;
    	if (q.size() == 3)
    		{
    		cout << "True." << endl;
    		}
    	else
    		{
    		cout << "False." << endl;
    		}
	cout << "#4 should be False." << endl;
    	if (q.size() == 0)
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
	testEnqueueInt(); 
	testEnqueueChar();
	testDequeueInt(); 
	testDequeueChar();
	testExpand();
	cout << "\n" << endl;
  	cout << "All tests completed successfully." << endl;
  	cout << "\n" << endl;
	return 0;
	}

