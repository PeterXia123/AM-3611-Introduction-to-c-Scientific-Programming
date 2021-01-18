//
//  main.cpp
//  assignment2
//
//  Created by yufei xia on 2018/9/25.
//  Copyright © 2018年 yufei xia. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    
    //question 2.4
    double u[3] = {1.0,2.0,3.0};
    double v[3] = {6.0,5.0,4.0};
    double A[3][3] = {{1.0,5.0,0.0},{7.0,1.0,2.0},{0.0,0.0,1.0}};
    double B[3][3] = {{-2.0,0.0,1.0},{1.0,0.0,0.0},{4.0,1.0,0.0}};
    double x[3];
    double y[3];
    double z[3];
    double D[3][3];
    double C[3][3];
    
    for(int i = 0; i<3;i++){
        x[i] = u[i]-v[i];
        for(int j = 0; j<3; j++){
            y[i] += A[i][j]*u[j];
            z[i] = y[i] - v[i];
            C[i][j] = 4*A[i][j]-3*B[i][j];
            for(int k = 0; k<3; k++){
                D[i][j]+= A[i][k]*B[k][j];
            }
        }
    }
    std::cout<<"the vector of x is as followed.";
    std::cout<<std::endl;
    for(int i = 0;i<3;i++){
        std::cout<<x[i]<<" ";
    }
    
    std::cout<<std::endl;
    std::cout<<"the vector of y is as followed.";
    std::cout<<std::endl;
    for(int i = 0;i<3;i++){
        std::cout<<y[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"the vector of z is as followed.";
    std::cout<<std::endl;
    for(int i = 0;i<3;i++){
        std::cout<<z[i]<<" ";
    }
    
    
    std::cout<<std::endl;
    std::cout<<"the matrix of C is as followed.";
    std::cout<<std::endl;
    for(int i = 0;i<3;i++){
        for(int j = 0; j<3;j++){
            std::cout<<C[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"the matrix of D is as followed.";
    std::cout<<std::endl;
    for(int i = 0;i<3;i++){
        for(int j = 0; j<3;j++){
            std::cout<<D[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    
    return 0;
    
}






