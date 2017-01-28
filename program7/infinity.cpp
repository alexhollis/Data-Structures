/********************************************
Name:   		Isaias Delgado, Alex Hollis
Course: 		CSCE 3110.002
Assignment:     Program 7, Dynamic Programming
Due Date:       May 08, 2015 at 11:59PM
********************************************/

#include<iostream>
using namespace std;

long long table[46];	// Array table to hold the values

long long f1(int x)     // Function 1
{
	if(x <= 1) 
		return 1;    // F(1) = 1
	else
		return (((2* f1(x-1)) + f1(x-2)) + ((x*x)-1));  // recursively call backwards to obtain result from bottom up
}

long long f2(int x)     // Function 2
{
	if(x <= 1) 
		return 1;    // F(1) = 1
	else
		return (f2(x - 2) + (2*(f2(x-1))) + ((x*x)-1)); // recursively call backwards to obtain result from bottom up
}

long long f3(int x)     // Function 3 - Dyanamic Programming - Lookup Table
{
	if(table[x] == -1)      // if value not in table
	{
		if(x <= 1)      // check if it is less than or equal to one first
			table[x] = 1;   // if it is, set that value in the table to 1, as F(1) = 1
		else 
			table[x] = ((f3(x-2)) + (2*f3(x-1)) + ((x*x)-1));   // if it is not <= 1, we'll need to use the previous recursive call function to find the value (We used F2 format for this part)
	}
	return table[x];        // return the value in the table as position x
}

int main()
{
	clock_t t;          // System clock
	table[0] = table[1] = 1;	// Lookup table that holds the value
	
	for(int i = 2; i < 46; i++)
		table[i] = -1;		// Creates an empty table full of value -1
	
	t = clock();		// Starts the clock for function 1
	f1(45);
	t = clock()-t;		// Captures the time stamp for the first function
	cout << "f1(45) in " << t << " clicks" << endl;
	
	t = clock();		// Starts the clock for function 2
	f2(45);
	t = clock() - t;	// Captures the time stamp for the second function
	cout << "f2(45) in " << t << " clicks" << endl;
	
	t = clock();		// Starts the clock for function 3
	f3(45);
	t = clock() - t;	// Captures the time stamp for the third function
	cout << "f3(45) in " << t << " clicks" << endl;
	
	return 0;
}