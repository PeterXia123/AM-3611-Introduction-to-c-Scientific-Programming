//
//  DoubMatrix.h
//  DoubleArray
//
//  Created by yufei xia on 2018/10/31.
//  Copyright © 2018年 yufei xia. All rights reserved.
//

#ifndef DoubMatrix_h
#define DoubMatrix_h
#include <stdio.h>
//#include "DoubArray.h"
#include <iostream>
class DoubArray;
class DoubMatrix;
class DoubMatrix
{
private:
    double **M_matrix;
    int m_col;
    int m_row;
    
public:
    DoubMatrix(int rows, int cols);
    DoubMatrix(const DoubMatrix &org_matrix);
    ~DoubMatrix();
    void setValue(int i, int j, int value);
    double& getValue(int i, int j) const;
    int getRows() const;
    int getColumns() const;
    friend std::ostream& operator<<(std::ostream& output,const DoubMatrix &z2);
    friend DoubMatrix operator*(const DoubMatrix &z1,const DoubMatrix &z2);
    friend DoubArray operator*(const DoubMatrix &z1,const DoubArray &z2);
    friend DoubArray operator*(const DoubArray &z1,const DoubMatrix &z2);
    friend DoubMatrix operator*(const DoubMatrix &z1,double c);
    friend DoubMatrix operator*(double c,const DoubMatrix &z1);
    void operator=(const DoubMatrix &matrix1);
    DoubMatrix Pow(int p);
    
};
#endif /* DoubMatrix_hpp */

