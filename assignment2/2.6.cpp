//
//  main.cpp
//  assignment2
//
//  Created by yufei xia on 2018/9/25.
//  Copyright © 2018年 yufei xia. All rights reserved.
//

#include <iostream>
#include <cmath>
double func(double x)
{
    return exp(x) + x*x*x-5;
}
double derifunc(double x){
    return exp(x) + 3*x*x;
}

int main(int argc, const char * argv[]) {
    
    
    //question 6
    double x[101];
    x[0]=0;
    
    
    for (int i = 1; i<101;i++){
        x[i] =x[i-1] - func(x[i-1])/derifunc(x[i-1]);
        std::cout<<"the x of interation "<<i<<" is "<<x[i]<<"\n";
    }
    
    double x_prev = 0;
    double x_next;
    for(int i = 1; i<101;i++){
        x_next = x_prev - func(x_prev)/derifunc(x_prev);
        x_prev = x_next;
        std::cout<<"the x of interation "<<i<<" is "<<x_next<<"\n";
        std::cout<<"here comes the check, plug the x back to the function"<<"\n";
        std::cout<<"the value for the function is " << func(x_prev)<<"\n";
        
    }
    
    double eps = 0.1;
    x_prev = 0;
    x_next = x_prev - func(x_prev)/derifunc(x_prev);
    while(abs(x_prev - x_next)>eps){
        std::cout<<"the x is "<<x_next<<"\n";
        x_prev = x_next;
        x_next = x_prev - func(x_prev)/derifunc(x_prev);
        if(abs(x_prev - x_next)<=eps){
            std::cout<<"oops! out of epslion\n";
        }
    }
    return 0;
}








