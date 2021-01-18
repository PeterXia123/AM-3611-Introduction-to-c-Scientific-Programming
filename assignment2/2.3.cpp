//
//  main.cpp
//  assignment2
//
//  Created by yufei xia on 2018/9/25.
//  Copyright © 2018年 yufei xia. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    //quesiton 2.3
    int n;
    int num;
    int result;
    std::cout<<"please input the number.";
    std::cin>>num;
    result = num;
    while(num!=-1&&result<=100 ){
        std::cout<<"please input the number.";
        std::cin>>num;
        result += num;
        if(num<=0&&num!=-1){
            std::cout<<"do you want to reset the sum(input the -2)";
            std::cin>> n;
            if(n == -2){
                std::cout<<"the sum has been reset to 0\n";
                result =0;
            }
        }
        
    }
    
    std::cout<<"the sum is "<< result<<"\n";
    return result;
    
    
    
}
