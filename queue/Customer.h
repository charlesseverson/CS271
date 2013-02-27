//Customer.h
//This is the header file for customer.cpp. It enables the methods used to track customer data. 
//Charlie Severson

#ifndef _CUSTOMER_H
#define _CUSTOMER_H

//==============================================================================
// Customer header
// Customer tracks the data of each of the customers arrival times and service
// times. This allows for ease of implementation for testing their relative 
// wait times and aggregating data on every customer. 
//==============================================================================
class Customer 
	{
	public:
		Customer(int time = 0, int service = 0);			// time and service are initlized and set to a default integer of 0.
		int arrive;							// arrive is initialized
		int serve;							// serve is initialized
	};
#endif
