//Wendys.cpp
//This file includes all the methods to create a queue using either the array queue or the linked list queue. It then displays the results of the simulation. 
//Charlie Severson
#include "queueA.h"
#include "queueL.h"								//Both header files are included so that either the array queue or the linked list queue may be tested
#include "Customer.h"
#include "Cashier.h"
#include <fstream>
#include <iostream>

using namespace std;
		
//==============================================================================
// QArrivalQueue
// Create an ArrivalQueue.
// The first line of the inputFile is the number of Customers.
// The rest of inputFile contains arrival time (time) and service time (service)
// QArrivalQueue will create a queue consisting of these two parameters
//==============================================================================
queue<Customer> QArrivalQueue(const char filename[]) 				//The const keyword is a compiler-assist in keeping your promise that you won't modify data, in this case a file. 
	{
	ifstream inputFile;							//ifstream provides an interface to read data from files as input streams, in this case, inputFile.
	int quantity, time, service;						//The size of the queue, the time overall, and the time of service
	int sum = 0;								//sum tracks how many times we enqueue to Arrival queue in the while loop, and is set as one of the paramters. 
	queue< Customer > ArrivalQueue;						//Use the customer class to create a queue, ArrivalQuene
	inputFile.open(filename);						//Open the inputFile in order to be addressed.
	inputFile >> quantity;							//This writes the contents of the inputFile to quantity, essentially declaring that "there exists this number of people to be served"
	while (!inputFile.eof() && (sum < quantity))
		{
		inputFile >> time >> service;					//This operator (>>) applied to an input stream is known as extraction operator, and in this case, where inputFile is the identifier of a istream object and time / service are objects of any type.
		ArrivalQueue.enqueue(Customer(time, service));			//We enqueue the time and service time to the Arrival queue, because these are the two parameters given to us in this inputFile.
		sum++;								//We iterate sum, which tracks how many times we enqueue to the ArrivalQueue. Once there is nothing left to enqueue, sum is no longer satisfied, and the while loop terminates. 
		}
	inputFile.close();							//This is required by c++, essentially due to the same reasons we delete memory in order to prvent memory leaks. 
	return ArrivalQueue;							//Return the ArrivalQueue, consisting of a local copy of the data from the inputFile.
	}

//==============================================================================
// main
// The main output method for the simulation. 
// All results from the event simulator are outputted from this.
//==============================================================================
int main()
	{
	
	queue<Customer> arrivals = QArrivalQueue("DataSetSingle.txt");		//Use Customer class to create arrvivals, the queue equivalent to an ArrivalQueue of the inputFile
   	Cashier Wendys;							//Wendys is a temp queue using the methods of Cashier class, which interpretes the data of the inputFile
	Wendys.SimulateCashier(arrivals);					//Our temp queue runs the method SimulateCashier on arrivals, which initalizes the values which will track our data. 	
	Wendys.execute();							//execute runs through the rests of the methods of Wendys (or vicariously Cashier.cpp)
	float minutes;								//Initalize minutes, since our output is defaulted to seconds
	float minutes2;								//Ibid.
	minutes = Wendys.QWaitAverage() / 60;					//Represent in minutes
	minutes2 = Wendys.QWaitMaximum() / 60;					//Ibid.
	
	cout << "\n" << endl;
	cout << "The line at Wendys has an average wait time per customer of " << Wendys.QWaitAverage() << " seconds, or " << minutes << " minutes." << endl;	//Output our average wait time
	cout << "\n" << endl;
	cout << "The line at Wendys has a maximum wait time of " << Wendys.QWaitMaximum() << " seconds, or " << minutes2 << " minutes." << endl;		//Output our maximum wait time
	cout << "\n" << endl;
	cout << "The line at Wendys has a maximum number of " << Wendys.QQuantityMaximum() << " customers in line." << endl;					//Output our maximum quanitity (of customers in Wendys queue)
    	cout << "\n" << endl;
    	cout << "In the line at Wendys " << Wendys.QWaitPercent() << "% " << "of the customers in line had to wait." << endl;					//Output the percetnage of customers who had to wait in a queue (less is better, more effcient) 
    	cout << "\n" << endl;
    	cout << "All tests completed successfully." << endl;
  	cout << "\n" << endl;
	return 0;
	}

