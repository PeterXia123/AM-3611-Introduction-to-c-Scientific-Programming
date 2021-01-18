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
    
    double x[4] = {0.0, 1.0, 1.0, 0.0};
    double y[4] = {0.0, 0.0, 1.0, 1.0};
    std::ofstream write_output("x_and_y.dat");
    assert(write_output.is_open());
    write_output.precision(10);
    for (int i=0; i<4; i++) {
        write_output << x[i] << " " ;
    }
    write_output <<"\n";
    write_output.flush();
    for (int j=0;j<4;j++){
        write_output << y[j]<<" ";
    }
    write_output <<"\n";
    write_output.close();
    return 0;
}


