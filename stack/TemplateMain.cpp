//TemplateMain.cpp
//Test program for templated stack class
//Charlie Severson

#include <iostream>
#include <stdlib.h>
#include "TemplateClass.h"

using namespace std;

//==============================================================================
// main
//==============================================================================

int main(void)
	{
	Stack<int> a;
	Stack<int> b;

	
	char x;
	char Yes;
	char No;
	
	cout << "\n" << endl;
	cout << "This is templated stack a." << endl;
	
	a.push(0);
	a.push(1);
	a.push(2);
	
	cout << "Now there are 3 items on stack a:" << "\n" << a << endl;
	
     	a.pop();
     	
    	cout << "The pop function is called once, so one value is popped off stack a:" << "\n" << a << endl;
    	
    	for(int i = 0; i < 105; i++)
    		{
        	b.push(1);
   		}
    	
    	cout << "Stack b has 105 values added to it, but the default is 100. Stack b is expanded to: " << b.size_<< "\n" << endl;
    	
    	b.push(0);
	b.push(1);
	b.push(2);
	b.push(0);
	b.push(1);
	b.push(2);
	b.push(2);
	
    	cout << "What if 7 more values are added? Now stack b is expanded to: " << b.size_ << "\n" << endl;	
    	   		
    	cout << "Is stack a empty? " << endl;
    	if (a.isEmpty() == 1)
    		{
    		cout << "Yes \n" << endl;
    		}
    	else if (a.isEmpty() == 0)
    		{
    		cout << "No \n" << endl;
    		cout << a << endl;
    		}
    		
    	a.pop();
    	a.pop();
    	
    	cout << "Two values are popped from stack a. Now is it empty?" << endl;
    	if (a.isEmpty() == 1)
    		{
    		cout << "Yes \n" << endl;
    		}
    	else if (a.isEmpty() == 0)
    		{
    		cout << "No \n" << endl;
    		cout << a << endl;
    		}
    		
    	a.pop();
    	a.pop();
    	
    	cout << "Two more values are popped from stack a. Is it still empty?" << endl;
    	if (a.isEmpty() == 1)
    		{
    		cout << "Yes \n" << endl;
    		}
    	else if (a.isEmpty() == 0)
    		{
    		cout << "No \n" << endl;
    		cout << a << endl;
    		}
    	
   	
    	cout << "The stack c is now initialized " << "\n" << endl;
    	Stack <string> c;
    	
    	for(int i = 0; i < 20; i++)
    		{
    		c.push("A");
    		c.push("B");
    		c.push("C");
    		}
    		
    	cout << "The contents of c are: "<< "\n" << c << endl;
	
	return 0;
 
	}
