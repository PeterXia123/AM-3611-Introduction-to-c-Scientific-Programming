//
//  optimazation_solver.h
//  3611miniproject
//
//  Created by yufei xia on 2018/11/28.
//  Copyright © 2018年 yufei xia. All rights reserved.
//


#include<cmath>

#include "sodukugenerator.h"
#ifndef optimazation_solver_h
#define optimazation_solver_h
class optimazation_solver{
private:
    
    int** sudo;
    int** hole;
    int m_size;
    int block_size;
public:
    optimazation_solver(sodukugenerator &generator){
        sudo = generator.getsudo();
        hole = generator.gethole();
        m_size = generator.getsize();
        block_size = sqrt(m_size);
    }
    

    int heuristic(int** board);
    int** generatesodu();
    int** copyboard(int** orig);
    int** generatesuccessor(int** orig);
    void solver(int n );
    void sodu_printer();
    
};


      
#endif /* optimazation_solver_h */
