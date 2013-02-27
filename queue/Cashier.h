//Cashier.h
//The header file for Cashier.cpp. This creates all the methods to be used during the Cashier simulation. 
//Charlie Severson

#include "queueA.h"
#include "Customer.h"
#include <algorithm>  

#ifndef _SimulateCashier_H
#define _SimulateCashier_H

//==============================================================================
// Cashier header
// Cashier is the catalyst for which the Cashier simulation is run through. 
// It takes in information regarding the customers from Customer.h,
// and it uses that data to analyze the arrive times and serivce times of
// each customer, generating data on the wait times for customers.
//==============================================================================
class Cashier
	{
	public:
		void SimulateCashier(queue< Customer > QArrival);		// This method defines the variables which will be used to keep track of various aspects of our Qline.
		void execute(); 						// execute sets the parameters for QIterateTime, making sure that it is only called when the conditions are appropriate.
		float QWaitAverage();						// Quite simply, this is the average time it takes, per customer, to be served.
		int QWaitMaximum();						// This is the maximum time a customer would have to wait if they were in the line at Wendys.
		int QQuantityMaximum();						// This is the maximum quantity of customers in the line at any one time.
		float QWaitPercent();						// This is the percentage of customers that are required to wait in the line at Wendys.
		void QTimeIterate();						// One of the parameters of the inputFile is Time arrived (represented as time). This method uses that parameter and updates it as customers are served.
	    	
	private:
		int time_;							// Time represents the time that has elapsed (time arrived).
		int serve_;							// Serve represents the time of service (serive time).
		int maxWait_;							// MaxWait represents the maximum waiting time, relative to time.
		int maxQuantity_;						// MaxQuantity represents the maximum quantity of the line of Customers
		int customers_;							// Customers represents the number customers who have been served.
		float waitTotal_;						// Total wait is the total time that customers waited in line.
		float sumCustomersWaited_;					// If a customer has to wait, this variable is iterated by one.
		queue< Customer > CustomerArrival;				// A shallow copy of the data in QArrival, which contains the data of arrival time and serivce time
		queue< Customer > QLine;					// A shallow copy of the Customer queue, which will be used to track the size of the queue
	};
#endif
