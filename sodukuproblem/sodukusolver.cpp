#include "sodukusolver.h"
#include <cmath>

bool sodukusolver::isPlace(int count){
    int square_size = sqrt(m_size);
    int row = count / m_size;
    int col = count % m_size;
    int j;
    //check each row conflict.
    for(j = 0; j < m_size; ++j){
        if(sudo[row][j] == sudo[row][col] && j != col){
            return false;
        }
    }
    //check each col conflict.
    for(j = 0; j < m_size; ++j){
        if(sudo[j][col] == sudo[row][col] && j != row){
            return false;
        }
    }
    //check each block conflict.
    int tempRow = row / square_size * square_size;
    int tempCol = col / square_size * square_size;
    for(j = tempRow; j < tempRow + square_size;++j){
        for(int k = tempCol; k < tempCol + square_size; ++k){
            if(sudo[j][k] == sudo[row][col] && j != row && k != col){
                return false;
            }
        }
    }
    return true;
}



// use the back tracking to fill the soduku table. it change the whole table when it finished.
bool sodukusolver::backtrace(int count){
    
    if(count == m_size*m_size){
        return true;
    }
    int row = count / m_size;
    int col = count % m_size;
    if(sudo[row][col] == 0){
        for(int i = 1; i <= m_size; ++i){
            sudo[row][col] = i;//place an value
            if(isPlace(count)){ //to test does it reach a conflict if we place here.
                bool finished = backtrace(count+1);//get into next level
                if(finished){
                    return true;
                }
            }
        }
        sudo[row][col] = 0;//backtracking
    }else{
        bool finished = backtrace(count+1);//get into next level.
        if(finished){
            return true;
        }
    }
    return false;
}
//same as backtrace. it use backtracking method. but it return the number of solution of certain soduku.
//to check the uniqueness or solution of soduku problem. if it has no solution return 0;
//if have one solution return 1. if it has more than one solution, return 2.
//it won't change the implict table.

int sodukusolver::checkuniquety(sodukugenerator generator,int count, int& times){
    if(count == generator.getsize()*generator.getsize()){
        return 1+times;
    }
    int row = count / generator.getsize();
    int col = count % generator.getsize();
    if(generator.getsudo()[row][col] == 0){
        for(int i = 1; i <= generator.getsize(); ++i){
            generator.getsudo()[row][col] = i;//given value
            if(isPlace(count)){//to test does it reach a conflict if we place here.
                times = checkuniquety(generator,count+1,times);//get into next level
                if(times==2){
                    return times;
                }
            }
        }
        generator.getsudo()[row][col] = 0;//backtracking
    }else{
        times = checkuniquety(generator,count+1,times);//get into next level.
        if(times==2){
            return times;
        }
    }
   
    return times;
    
}
// print the sudo. skip all the holes.
void sodukusolver::printSudo(){
    int square_size = sqrt(m_size);
    for (int y=0; y<m_size; y++)
    {
        (y % square_size == 0) ? (cout << "------------------------\n ") : (cout << " ");
        for (int x=0; x<m_size; x++)
        {
            cout << sudo[y][x] << " ";
            (x % square_size == square_size-1) ? (cout << "| ") : (cout << "");
        }
        cout << endl;
    }
    cout << "------------------------\n";
    
}
