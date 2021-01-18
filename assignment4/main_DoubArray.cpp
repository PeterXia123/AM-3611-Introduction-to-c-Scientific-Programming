#include <cassert>
#include <iostream>
#include <cmath>
#include <fstream>

#include "DoubArray.h"

/* This program implements the implicit Euler method to solve dy/dx = -ysin(nh) where
 y(0) = 1 and x is in side [0,1]. h is defined as the constant step and N is
 the number of grid points and the length of the array. Once the user enters a value for N, the program
 will compute h and store the values of x and y coordinates in a file called
 xy.dat in two columns. The solution will be compared to y = e ^ (-1 + cos(x))*/

int getN();
void ImpEuler(int N,DoubArray& y, DoubArray& x);
void Exact(int N, DoubArray& y, DoubArray& x);

int main(int argc, char* argv[])
{
    DoubArray array1(10); // allocate 10 integer "array" via constructor
    for (int i=0; i < 10; ++i)
        array1.setValue(i, double (i+1));
    std::cout << "Array1 is: " << array1;
    
    DoubArray array2(array1); // Demonstrate the use of a copy constructor
    std::cout << "Array2 is a copy of Array1: " << array2;
    array2[2] = 12;
    std::cout << "Array2's element 2 is now: " << array2; // Demonstrate the overloaded operators []
    
    DoubArray array3(10);
    for (int i=0; i < 10; ++i)
        array3.setValue(i, double (i+2));
    std::cout << "Array3 is: " << array3;
    
    DoubArray array4(10); // Demonstrate the use of the = and - operators
    array4 = array3 - array1;
    std::cout << "Array4 is Array3 - Array1: " << array4;
    
    DoubArray array5(10); // Demonstrate the use of a construct with zeros
    std::cout << "Array5 is an array of zeros: " << array5;
    
    //Demonstrate that the P-Norm works
    std::cout << array1.PNorm(2) << "\n";
    
    // This is 3.3 using Class DoubArray (Part E)
    // Get N grid points from user
    int N;
    N = getN();
    
    DoubArray y(N);
    DoubArray x(N);
    ImpEuler(N, y, x);
    
    std::ofstream write_output("xy.dat");
    
    assert(write_output.is_open()); // Check the file is open
    
    write_output << "x pts | y pts\n";
    
    for (int i = 0; i < N; i++)
    {
        // Write out the first coordinates in the file
        write_output << x[i] << " | " << y[i] << "\n";
    }
    
    //This is part F
    
    std::ofstream new_output("PNorm_errors.dat");
    assert(new_output.is_open()); // Check the file is open
    
    for (int i=1; i<11; i++)
    {
        N = 10*i;
        
        DoubArray y_implicit(N);
        DoubArray x_implicit(N);
        ImpEuler(N, y_implicit, x_implicit);
        
        DoubArray y_exact(N);
        DoubArray x_exact(N);
        Exact(N, y_exact, x_exact);
        
        DoubArray errorP1(N);
        errorP1 = y_exact-y_implicit;
        
        double h;
        h = 1.0/(static_cast<double>(N)-1);
        
        new_output << "h:" << h << "  ";
        
        new_output << "P1 Norm:" << errorP1.PNorm(1.0)<< "  ";
        
        new_output << "P2 Norm:" << errorP1.PNorm(2.0)<<"\n";
    }
    
    return 0;
}     // All the DoubArray instances go out of scope and are destroyed here,
// so ~DoublArray() destructor function is called here
int getN()
{
    int N;
    std::cout<< "Enter the number of gridpoints:\n";
    std::cin>> N;
    
    assert(N > 1); // Check the grid points, N is more than 1
    return N;
}

void ImpEuler(int N, DoubArray &y, DoubArray &x)
{
    y.setValue(0,1.0);
    double h;
    h = 1.0/(static_cast<double>(N)-1);
    
    for(int i=1; i < N; i++)
    {
        x.setValue(i, double (i*h));
        y.setValue(i, y.getValue(i-1)/(1+h*sin(i*h)));
    }
}

void Exact(int N, DoubArray &y, DoubArray &x)
{
    double h;
    h = 1.0/(static_cast<double>(N)-1);
    
    for(int i=0; i < N; i++)
    {
        x.setValue(i, double (i*h));
        y.setValue(i, exp(-1+cos(x[i])));
    }
}
