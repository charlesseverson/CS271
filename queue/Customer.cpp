//Customer.cpp
//Customer.cpp is created in order to accuratley track the data inputed from the sourcefile regarding customer arrivaltime and time served. 
//Charlie Severson

#include "Customer.h"

using namespace std;

//==============================================================================
// Customer
// Customer tracks the data of each of the customers arrival times and service
// times. This allows for ease of implementation for testing their relative 
// wait times and aggregating data on every customer. 
//==============================================================================
Customer::Customer(int time, int service)
	{
	arrive = time;								// time is defined as the time in which a customer arrives at Wendys.
    	serve = service;							// service is defined as the time in which a customer is serviced at Wendys, obviously following their arrival time. 
	}
