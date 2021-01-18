#include <iostream>
#include <cassert>
#include <cmath>

#include "DoubMatrix.h"
#include "DoubArray.h"

int main()
{
    int rows = 4; // # of rows
    int cols = 4; // # of columns
    
    DoubMatrix A(rows,cols); // include the array
    
    
    for (int i=0; i < A.getRows(); i++)
    {
        for (int j=0; j < A.getColumns(); j++)
        {
            A.setValue(i, j, i+j);
        }
    }
    std::cout << "the matrix A is as followed.\n";
    std::cout << "\n";
    std::cout << A;
    
    std::cout << "use the copy constructor to copy A to B\n";
    std::cout << "\n";
    DoubMatrix B(A);
    std::cout << B;
    
    DoubMatrix C(cols,rows); // include the array
    
    
    for (int i=0; i < C.getRows(); i++)
    {
        for (int j=0; j < C.getColumns(); j++)
        {
            C.setValue(i, j, i-j);
        }
    }
    
    DoubMatrix D(rows,rows);
    D = A*C;
    std::cout << "D = " << D << std::endl;
    std::cout << "A*C =" << A*C << std::endl;
    DoubArray v(4);
    DoubArray u(4);
    for (int i=0; i < 4; ++i)
    {
        v.setValue(i, i);
    }
    std::cout << "\nArray1 is: " << v <<"\n";
    
    v = A.Pow(4)*v;
    u = A*A*A*A*v;
    std::cout << "u = " << u << "v = " << v << std::endl;
    
    std::cout << "test scalar multiply an matrix"<< std::endl;
    DoubMatrix E(rows,rows);
    DoubMatrix F(rows,rows);
    E = A*3;
    F = 3*A;
    std::cout << "E = " << E << " = " << F << std::endl;
    
    
    
    return 0;
} // instances of class DoubMatrix go out of scope and are destroyed here,
// so ~DoubMatrix() destructor function is called here
