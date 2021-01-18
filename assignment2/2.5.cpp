//
//  main.cpp
//  assignment2
//
//  Created by yufei xia on 2018/9/25.
//  Copyright © 2018年 yufei xia. All rights reserved.
//

#include <iostream>
#include <assert.h>
int main(int argc, const char * argv[]) {
    
    //quesiton 5
    double A[2][2] ={{4,10},{1,1}};
    int det = A[0][0]*A[1][1]-A[0][1]*A[1][0];
    assert(det!=0);
    A[0][1]=-A[0][1];
    A[1][0]=-A[1][0];
    int temp = A[0][0];
    A[0][0] = A[1][1];
    A[1][1] =temp;
    for(int i = 0;i<2;i++){
        for(int j = 0; j<2; j++){
            A[i][j] = A[i][j]/det;
        }
    }
    
    for(int i = 0; i<2 ; i++){
        for(int j=0 ; j<2;j++){
            std::cout<<"the "<<i+1<<" row and the "<<j+1  <<" column of the matrix is "<< A[i][j];
            std::cout<<std::endl;
        }
    }
    
    return 0;
    
    }
