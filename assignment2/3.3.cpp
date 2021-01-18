//
//  main.cpp
//  assignment2
//
//  Created by yufei xia on 2018/9/25.
//  Copyright © 2018年 yufei xia. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <assert.h>


int main(int argc, char * argv[]) {
    int n;
    double y=1.0;
    std::cout<<"please input the N";
    std::cin >> n;
    assert(n>1);
    double h = (double)1/n;
    
    std::ofstream write_output("xy.dat");
    assert(write_output.is_open());
    write_output.precision(10);
    write_output<< 0 <<" "<< y << "\n";
    for (int i=1; i<n; i++) {
        y=y/(1+h);
        write_output << h*i << " "<< y<<"\n";
    }
    
    write_output << "\n";
    write_output.close();
    return 0;
}





