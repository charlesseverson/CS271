//Cashier.cpp
//Cashier forms the skeleton of the total function of a customer event simulator. 
//It does this by use of several methods designed to structure the simulation.
//Charlie Severson

#include "Cashier.h"
#include "Customer.h"

using namespace std;

//==============================================================================
// SimulateCashier
// This method defines the variables which will be used to keep track of 
// various aspects of our line.
//==============================================================================
void Cashier::SimulateCashier(queue<Customer> QArrival) 			// SimulateCashier is initialized, using input from Customer class to create QArrival
	{
	time_ = 0;								// Time represents the time that has elapsed (time arrived).
    	serve_ = 0;								// Serve represents the time of service (serive time).
    	customers_ = 0;								// Customers represents the number customers who have been served.
    	maxWait_ = 0;								// MaxWait represents the maximum waiting time, relative to time.
    	maxQuantity_ = 0;							// MaxQuantity represents the maximum quantity of the line of Customers
    	sumCustomersWaited_ = 0;						// If a customer has to wait, this variable is iterated by one.
    	waitTotal_ = 0;								// Total wait is the total time that customers waited in line.
    										
	CustomerArrival = QArrival;						// A shallow copy of the data in QArrival, which contains the data of arrival time and serivce time	
	QLine = queue<Customer>();						// A shallow copy of the Customer queue, which will be used to track the size of the queue
	}
	
//==============================================================================
// QTimeIterate
// One of the parameters of the inputFile is Time arrived (represented as time)
// This method uses that parameter and updates it as customers are served.
//==============================================================================
void Cashier::QTimeIterate() 
	{
	int Wait; 								// Initialize Wait, which will help us track wait times 
	Customer servedCustomer; 						// Initialize the temp variable servedCustomer, which will help us track when a customer needs to be removed form the queue.								
	time_++; 								// This implies that a customer has arrived, so time is now set to 1.
	while(CustomerArrival.size() > 0 && CustomerArrival.first().arrive == time_) // while the Arrivalqueue is not empty and the first (a method from QueueA) customer's time of arrival equals the local time (they start getting served). . .
		{ 								
        	QLine.enqueue(CustomerArrival.dequeue());  			// The first customer in the Qline is no longer part of the Qline (as they are being serviced)
        	customers_++; 							// The line of serviced customers increases by one.
		}
	maxQuantity_ = max(maxQuantity_, QLine.size()); 			// maxQuantity is set to the maximum value of either maxQuantity, or Qline. 
	if (serve_ > 0) 
		{ 								// If someone is still being serviced . . .
		serve_--; 							// Service time decreases by one (as each customer has a set amount of time it takes to be serviced)
		}
	else if (QLine.size() > 0) 						// Else if there is a customer waiting in line to be serviced  . . .
		{
        	servedCustomer = QLine.dequeue(); 				// The customer being serviced finishes being serviced, and now the first customer in the Qline is no longer part of the Qline (as they are being serviced)
		serve_ = servedCustomer.serve; 					// The new customer to be serviced is now serviced (their time to be serviced is now the subject time of serve_)
		Wait = time_ - servedCustomer.arrive; 				// Wait is set to how long the customer was standing in line (which is implied that they were since they were quened in Qline)
       		if (Wait != 0) 							// If there are other customers having to wait in Qline . . .
       			{   							
            		sumCustomersWaited_++; 					// Then there are customers who had to wait, so sumCustomersWaited is iterated.
            		Wait--; 						// Once someone is done being serviced, the next person in line no longer has to wait.
            		time_--; 						// Once a customer leaves the Qline to be serviced after waiting, they are serviced immediately 
        		}
        	else								// There is no other possibility.
        		{
        		}
		waitTotal_ += Wait; 						// waitTotal is the sum of wait times for customers (if there are any)
		maxWait_ = max(maxWait_, Wait); 				// maxWait is to the maximum value of either maxWait, or Wait. 
    		}
    	else									// There is no other possibility.			
    		{
    		}
	}

//==============================================================================
// execute
// execute sets the parameters for QIterateTime, making sure that it is only
// called when the conditions are appropriate.
//==============================================================================
void Cashier::execute() 
	{  									
	while(serve_ > 0 || CustomerArrival.size() > 0 || QLine.size() > 0) 	// While there are are customers being serviced, the Arrivalqueue is not empty, or there customers in Qline (i.e., there are customers in the store)
		{ 								
		QTimeIterate(); 						// Execute the QTimeIterate function.
		}
	}

//==============================================================================
// QWaitAverage
// Quite simply, this is the average time it takes, per customer, to be served.
//==============================================================================
float Cashier::QWaitAverage() 
	{
	float average = waitTotal_ / customers_; 				// average is defined as the total amount of time waited by customers divided by the number of customers who were served 
	return average;  							// return the average amount of time waited by customers 
	}

//==============================================================================
// QWaitMaximum
// This is the maximum time a customer would have to wait if they were in the
// line at Wendys. This variable / method is highly dependant on the quantity 
// of customers, their arrival times, their service times, and how many cashiers
// are serving the line.
//==============================================================================
int Cashier::QWaitMaximum() 
	{
	return maxWait_;  							// simply return the variable maxWait, which has been set to the maximum time waited by customers after the QTimeIterate function has fully run.
	}

//==============================================================================
// QQuantityMaximum
// This is the maximum quantity of customers in the line at any one time.
// Obviously, this variable / method is similar to QWaitMaximum, but instead
// has to do with quantity of customers, rather than the time they are waiting.
//==============================================================================
int Cashier::QQuantityMaximum() 
	{
	return maxQuantity_;  							// simply return the variable maxQuantity, which has been set to the maximum number of customers in the Qline the QTimeIterate function has fully run.
	}

//==============================================================================
// QWaitPercent
// This is the percentage of customers that are required to wait in the line at 
// Wendys. Generally, this is the case so long as customers > 1, so long as
// cashiers = 1. This percetnage has nothing to do with how long customers had
// to wait, but the fact that they had to wait. It is highly dependant on the
// arrival time of customers and the serivce time, but only loosely dependant
// on the amount of customers.
//==============================================================================
float Cashier::QWaitPercent() 
	{
    	float percentage_ = (sumCustomersWaited_ / customers_) * 100; 		// percentage is defined as the number of customers who had to wait divided by the number of customers who were served, multiplied by 100 to give a better representation.
    	return percentage_;							// return the percentage of the total number of customers who had to wait in the Qline. 
	}



