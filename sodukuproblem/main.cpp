//
//
//  main.cpp
//  3611miniproject
//
//  Created by yufei xia on 2018/11/19.
//  Copyright © 2018年 yufei xia. All rights reserved.
//
#include "sodukusolver.h"
#include "sodukugenerator.h"
#include "optimazation_solver.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>

int main(){
    srand(time(0));
    std::cout<<"we generate 5 different level of 9*9 soduku problem."<<std::endl;
    for(int i = 0; i<5;i++){
        std::cout<<"the "<<i+1<<" level of difficulties of generated matrix is as followed.\n"<<std::endl;
        sodukugenerator A(9);
        A.num_generator(i+1);
        A.printSudo();
        std::cout<<"now let's calculate the time to solve "<<i+1<<" level of difficulties soduku problem.\n";
        sodukusolver solver_A(A);
        int intvalue = 0;
        std::cout<<"the number of solution of this soduku is "<<solver_A.checkuniquety(A,0, intvalue)<<std::endl;
        const clock_t begin_time = clock();
        solver_A.backtrace(0);
        std::cout <<"the time for solving level "<<i+1<<" difficulties is "<< float( clock () - begin_time )<<std::endl<<"\n"<<"\n";
        solver_A.printSudo();
    }
    
    
    sodukugenerator B(9);
    B.num_generator(5);
    B.printSudo();
    
    optimazation_solver solve_B(B);
    
    std::cout<<solve_B.heuristic(B.getsudo())<<"\n";
    int** ab =  solve_B.generatesodu();
    std::cout<<solve_B.heuristic(ab)<<"\n";
    for(int i = 0;i<9;i++){
        for(int j = 0; j<9;j++){
            std::cout<<ab[i][j]<<" ";
        }
    }
   
    std::cout<<std::endl;
    int ** cd = solve_B.generatesuccessor(ab);
    for(int i = 0;i<9;i++){
        for(int j = 0; j<9;j++){
            std::cout<<cd[i][j]<<" ";
        }
    }
    
    const clock_t begin_time = clock();
    solve_B.solver(100);
    std::cout <<"the time for solving level 5 difficulties using stochastic search is "<< float(clock()-begin_time)<<std::endl<<"\n"<<"\n";
    solve_B.sodu_printer();
    
    
    
    
    

}
