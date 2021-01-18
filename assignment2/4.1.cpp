//
//  main.cpp
//  assignment2
//
//  Created by yufei xia on 2018/9/25.
//  Copyright © 2018年 yufei xia. All rights reserved.
//

#include <iostream>
#include <fstream>


int main(int argc, char * argv[]) {
    int i = 5;
    int* p_j = &i;
    *p_j = *p_j * 5;
    std::cout<<"the number of i become "<<i<<"\n";
    double* p_k;
    p_k = new double;
    *p_k = i;
    std::cout<<"the contents of varible i stored is "<<*p_k<<"\n";
    

    return 0;
    
    
    
    
}




