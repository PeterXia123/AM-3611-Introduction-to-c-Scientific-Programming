//
//  DoubArray.h
//  DoubleArray
//
//  Created by yufei xia on 2018/10/31.
//  Copyright © 2018年 yufei xia. All rights reserved.
//

#ifndef DoubArray_h
#define DoubArray_h
#include <stdio.h>
//#include "DoubMatrix.h"
class DoubArray;
class DoubMatrix;
class DoubArray
{
private:
    double *m_array;
    int m_length;
    double m_norm;
    bool m_normflag=false;
    int m_p;
    
public:
    DoubArray(int length); // constructor
    DoubArray(const DoubArray &org_array);// copy constructor
    ~DoubArray(); // destructor
    void setValue(int index, int value);
    double& getValue(int index)const {return m_array[index];}
    bool getnormflag(){return m_normflag;}
    int getLength() const {return m_length; }
    friend DoubArray operator-(const DoubArray &array1, const DoubArray &array2);
    double& operator[] (const int index); // consider non-const objects (Part D)
    const double& operator[] (const int index) const; // consider const objects (Part D)
    friend DoubArray operator*(const DoubMatrix &z1,const DoubArray &z2);
    friend DoubArray operator*(const DoubArray &z1,const DoubMatrix &z2);
    double PNorm(double p);
    friend std::ostream& operator<<(std::ostream& output, const DoubArray &array);
    
};
#endif /* DoubleArray_h */

