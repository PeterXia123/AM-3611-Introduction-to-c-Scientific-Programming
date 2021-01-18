#include <iostream>
#include <cassert>
#include <cmath>

#include "DoubMatrix.h"
#include "DoubArray.h"

int main()
{
	int n = 3; // # of rows
	int m = 3; // # of columns
	
	DoubMatrix A(n,m); // include the array

	int element=1;
	for (int i=0; i < A.getRows(); i++)
	{
		for (int j=0; j < A.getColumns(); j++)
		{
			A.setValue(i, j, element); 
			element+=1;
		}
	}
	std::cout << A;
	std::cout << "This is matrix A.\n";
	std::cout << "\n";

	DoubMatrix B(A);
	std::cout << B;
	std::cout << "This is a copy of matrix A.\n";
	std::cout << "\n";
	
	DoubMatrix I(n,m); // include the identity matrix #Eunice2018

	int identity[] {1,0,0,0,1,0,0,0,1};
	int index = 0;
	
	for (int i=0; i < I.getRows(); i++)
	{
		for (int j=0; j < I.getColumns(); j++)
		{
			I.setValue(i, j, identity[index]); 
			index+=1;;
		}
	}
	std::cout << I;
	std::cout << "This is the identity matrix.\n";
	std::cout << "\n";
	
	std::cout << A*I;
	std::cout << "This is a demonstration of my matrix times matrix *overloader where the above is A*I.\n";
	std::cout << "\n";
	
	std::cout << A*2;
	std::cout << "This is a demonstration of my matrix times 2 *overloader where the above is A*2.\n";
	std::cout << "\n";
	
	DoubArray array1(3);
	for (int i=0; i < 3; ++i)
	{
		array1.setValue(i, 1.0);
	}
	std::cout << "\nArray1 is: " << array1<<"\n";
	
	std::cout << A*array1;
	std::cout << "This is a demonstration of my matrix times a vector *overloader where the above is A*[1,1,1].\n";
	std::cout << "\n";
	
	std::cout << array1*A;
	std::cout << "This is a demonstration of [1,1,1] times my matrix *overloader where the above is A*[1,1,1].\n";
	
	std::cout << A.Pow(2);
	
	std::cout << A*A;
	

	
	return 0;
} // instances of class DoubMatrix go out of scope and are destroyed here, 
// so ~DoubMatrix() destructor function is called here
