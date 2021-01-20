//
//  sodukusolver.h
//  3611miniproject
//
//  Created by yufei xia on 2018/11/20.
//  Copyright © 2018年 yufei xia. All rights reserved.
//
//use backtracking to fill the soduku problem. and then use the time function to get the time of each method to s//the problem and compare them.
#include "sodukugenerator.h"
class sodukugenerator;
#ifndef sodukusolver_h
#define sodukusolver_h

class sodukusolver{
private:

//1 the whole soduku table
//2 the hole table, 1 mean hole, 0 mean number.
//3 the size number.
  int** sudo;
  int** hole;
  int m_size;

    //sodukusolver: constructor for class sodukusolver, we pass all the varible from the class sodukugenerator.
    //isplace: to check if it is ok to place an number into certain places. different from the genertor. the method h
    //ere check the position line by line. instead of generate randomly.
    //printdodu(): print the sudu table. same as generator.
    //checkuniquely(): to check if the sudo has only solution.
    //getsudo(): get the table of sudo.
    //gethole(): get the hole of sudo.
    //getsize(): get the size of sudo.
    

public:
    sodukusolver(sodukugenerator &generator){
        sudo = generator.getsudo();
        hole = generator.gethole();
        m_size = generator.getsize();
    }
    bool isPlace(int count);
    bool backtrace(int count);
    void printSudo();
    int checkuniquety(sodukugenerator generator,int count, int &times);
    int** getsudo(){return sudo;};
    int** gethole(){return hole;};
    int getsize(){return m_size;};
    
 

};

#endif /* sodukusolver_h */
