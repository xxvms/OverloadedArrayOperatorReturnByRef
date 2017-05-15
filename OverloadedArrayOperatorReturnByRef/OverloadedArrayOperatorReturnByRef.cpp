// OverloadedArrayOperatorReturnByRef.cpp : Defines the entry point for the console application.
//
/*
Create safe array index values are checked before access
uses overloded [] operator for both put and get!

*/
#include "stdafx.h"
#include <iostream>
#include <process.h> // for exit()

const int LIMIT = 100; // array size, letters in UPPER case are constatnt - they don't change from start to end of program

class SafeArray
{
	int arr[LIMIT];
public:
	int& operator [](int n) // note: return by reference!!! overloading []
	{
		if (n < 0 || n >= LIMIT) 
		{ 
			std::cout << "\nIndex out of bounds"; 
			exit(1);
		}
		return arr[n];
	}
};


int main()
{
	SafeArray sa1;

	for (int j = 0; j < LIMIT; j++) // insert elements
	{
		sa1[j] = j * 10;  //LEFT side of equal sign
	}
	for (int j = 0; j < LIMIT; j++) // display elements
	{
		int temp = sa1[j]; //RIGHT side of equal sign
		std::cout << "Element " << j << " is " << temp << std::endl;
	}

	system("pause");
    return 0;
}

