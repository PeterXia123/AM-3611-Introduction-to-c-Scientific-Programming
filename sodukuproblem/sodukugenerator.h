
#ifndef sodukugenerator_h
#define sodukugenerator_h
//
//  sodukugenerator.hpp
//  3611miniproject
//
//  Created by yufei xia on 2018/11/19.
//  Copyright © 2018年 yufei xia. All rights reserved.
//

#include <iostream>
#include <ctime>
using namespace std;
#include <stdio.h>
class sodukugenerator
{
// set up the variable.
//1. the number of rows.
//2 the number of collumns
//3 the whole soduku table
//4 the hole table, 1 mean hole, 0 mean number.

private:
    int m_rows;
    int m_columns;
    int** sudo;
    int** hole;
//the function introduction
//set: to put an number into certain position. before put, check if the position is occupied.
//reset: to unchoose a point.
//inixord: to generate a random number row.
//fillfrom: to fill the whole table using backtracking.
//dighole: to dig holes from the exsiting table. followed by different diffculties. 1,2,3,4,5.
//num_generator:the combination of fillform and dighole to generate a complete soduku problem.
//printsudo: to print out the sudu in a nice format.
//getsudo:to return the table of soduku problem
//gethole:to return the hole table of suduku problem.
//getsize:to return the size of sudoku.
//checkuniquety: to check the uniqueness or solution of soduku problem. if it has no solution return 0;
//if have one solution return 1. if has more than one solution return2.

    

public:
    sodukugenerator(int size);
    sodukugenerator(sodukugenerator &generator){
        sudo = generator.getsudo();
        hole = generator.gethole();
        m_rows = generator.getsize();
        m_columns = generator.getsize();
    }
    bool set(int x, int y, int val);
    void reset(int x, int y);
    void initXOrd(int* xOrd);
    bool fillFrom(int y, int val);
    void digHole(int level);
    void num_generator(int level);
    void printSudo();
    int** getsudo(){return sudo;};
    int** gethole(){return hole;};
    int getsize(){return m_rows;};
    int checkuniquety(sodukugenerator generator,int count, int &times);
    bool isPlace(int count);
};




#endif /* sodukugenerator_h */
