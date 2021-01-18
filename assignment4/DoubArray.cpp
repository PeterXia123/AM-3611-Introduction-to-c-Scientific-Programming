//
//  DoubleArray.cpp
//  DoubleArray
//
//  Created by yufei xia on 2018/10/31.
//  Copyright © 2018年 yufei xia. All rights reserved.
//
#include <iostream>
#include <cassert>
#include <cmath>
#include "DoubArray.h"
#include "DoubMatrix.h"
//class DoubMatrix;

DoubArray::DoubArray(int length) // constructor
{
    assert(length > 0);
    m_array = new double[length]{};
    m_length = length;
    m_normflag =false;
    
}

DoubArray::DoubArray(const DoubArray &org_array) // copy constructor
{
    m_length = org_array.m_length;
    m_array = new double[m_length];
    for (int i=0; i<m_length; i++)
        m_array[i]=org_array.m_array[i];
    
    
    //std::cout << "...finishing copy constructor\n";
}


DoubArray::~DoubArray() // destructor
{
    // Dynamically delete the array we allocated earlier
    delete[] m_array ;
    //std::cout << "...finishing destructor\n";
}


void DoubArray::setValue(int index, int value) {
    m_array[index] = value;
    m_normflag = false;
}


DoubArray operator-(const DoubArray &z1, const DoubArray &z2){
    assert(z1.getLength()==z2.getLength());
    DoubArray w(z1.getLength());
    for(int i = 0;i<z1.getLength();i++){
        w.m_array[i] = z1.getValue(i)-z2.getValue(i);
    }
    return w;
    
}
double& DoubArray::operator[](const int index){
    assert(index<m_length);
    return m_array[index];
}

const double& DoubArray::operator[] (const int index) const 
{
    assert (index <= m_length);
    return m_array[index];
}

DoubArray operator*(const DoubMatrix &z1,const DoubArray &z2){
    double sum;
    assert(z1.m_col == z2.m_length);
    DoubArray z3(z1.m_row);
    for(int i =0; i < z1.m_row;i++){
        sum = 0;
        for(int j = 0; j<z2.m_length;j++){
            sum += z1.M_matrix[i][j]*z2.m_array[j];
        }
        z3.setValue(i, sum);
    }
    return z3;
}

DoubArray operator*(const DoubArray &z1,const DoubMatrix &z2){
    double sum;
    assert(z1.m_length== z2.m_row);
    DoubArray z3(z2.m_col);
    for(int i =0; i < z2.m_col;i++){
        sum = 0;
        for(int j = 0; j<z1.m_length;j++){
            sum += z2.M_matrix[j][i]*z1.m_array[j];
        }
        z3.setValue(i, sum);
    }
    return z3;
}



double DoubArray::PNorm(double p){
   
    if ((m_normflag == false)||(m_p!=p) )
    {
        m_p = p;
        double sum = 0.0;
        for (int i=0; i<m_length; i++)
        {
            sum += pow(fabs(m_array[i]), p);
        }
        m_norm = pow(sum, 1.0/p);
        m_normflag = true;
    }
    return m_norm;
}


std::ostream& operator<<(std::ostream& output, const DoubArray &array)
{
    for (int i=0; i < array.m_length; i++)
    {
        output << array[i] << "  ";
    }
    output << "\n";
    return output;
}





