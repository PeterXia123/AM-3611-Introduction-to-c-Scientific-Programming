//
//  DoubMatrix.cpp
//  DoubleArray
//
//  Created by yufei xia on 2018/10/31.
//  Copyright © 2018年 yufei xia. All rights reserved.
//
#include <iostream>
#include <cassert>
#include <cmath>
#include "DoubMatrix.h"
#include "DoubArray.h"
//class DoubArray;

DoubMatrix::DoubMatrix(int rows, int cols){
    m_col = cols;
    m_row = rows;
    M_matrix = new double* [rows];
    M_matrix[0] = new double [rows*cols];
    for (int i=1; i<rows; i++)
    {
        M_matrix[i] = M_matrix[i-1]+ cols;
        
    }
}

DoubMatrix::DoubMatrix(const DoubMatrix &org_matrix){
    m_col = org_matrix.m_col;
    m_row = org_matrix.m_row;
    M_matrix = new double* [m_row]{};
    M_matrix[0] = new double [m_row*m_col]{};
    for (int i=1; i<m_row; i++)
    {
        M_matrix[i] = M_matrix[i-1]+ m_col;
        
    }
    for(int i = 0;i<m_col;i++){
        for(int j = 0; j<m_row;j++){
            M_matrix[i][j]=org_matrix.M_matrix[i][j];
        }
    }
}

DoubMatrix::~DoubMatrix(){
    
    delete[] M_matrix[0];
    delete M_matrix;
}
void DoubMatrix::setValue(int i, int j, int value) { M_matrix[i][j] = value; }
double& DoubMatrix::getValue(int i, int j) const { return M_matrix[i][j]; }
int DoubMatrix::getRows() const { return m_row; }
int DoubMatrix::getColumns() const { return m_col; }




std::ostream& operator<<(std::ostream& output,const DoubMatrix &z1){
    for (int i = 0; i<z1.getRows();i++){
        for(int j = 0; j<z1.getColumns();j++)
        output << z1.getValue(i, j)<<" ";
    }
    return output;
}




DoubMatrix operator*(const DoubMatrix &z1, const DoubMatrix &z2){
    assert(z1.m_col== z2.m_row);
    DoubMatrix z3(z1.m_row, z2.m_col);
    for (int i = 0; i<z1.m_row;i++){
        for(int j = 0; j<z2.m_col;j++){
            for (int k = 0; k <z1.m_row;k++){
                z3.M_matrix[i][j] = z1.M_matrix[i][k]*z2.M_matrix[k][j];
            }
        }
    }
    return z3;
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





DoubMatrix operator*(const DoubMatrix &z1,double c){
    DoubMatrix z3(z1.m_row,z1.m_col);
    for(int i =0; i < z1.m_row;i++){
        for(int j = 0; j<z1.m_col;j++){
            double result = c*z1.getValue(i,j);
            z3.setValue(i,j,result);
        }
       
}
     return z3;
}




DoubMatrix operator*(double c,const DoubMatrix &z1){
        DoubMatrix z3(z1.m_row,z1.m_col);
        for(int i =0; i < z1.m_row;i++){
            for(int j = 0; j<z1.m_col;j++){
                double result = c*z1.getValue(i,j);
                z3.setValue(i,j,result);
            }
            
        }
return z3;
}

void DoubMatrix::operator=(const DoubMatrix &matrix)
{
    int row = matrix.getRows();
    int col = matrix.getColumns();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            M_matrix[i][j] = matrix.getValue(i,j);
        }
    }
}






DoubMatrix DoubMatrix::Pow(int p){
    DoubMatrix z3(*this);
    assert(z3.getRows() == z3.getColumns());
    for(int i = 0; i<p-1;i++){
        z3 = z3*z3;
    }
    return z3;
}

