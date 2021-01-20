//
//  optimazation_solver.cpp
//  3611miniproject
//
//  Created by yufei xia on 2018/11/28.
//  Copyright © 2018年 yufei xia. All rights reserved.
//
#include <stdio.h>
#include <unordered_set>
#include "optimazation_solver.h"
#include "tree.cpp"
#include <ctime>
class BST;
struct node;

int optimazation_solver::heuristic(int** board){
    int collisions = 0;
    int square_size = block_size;
    
    for(int row = 0;row<m_size;row++){
        for(int col = 0; col<m_size;col++){
    int j;
    for(j = 0; j < m_size; ++j){
        if(board[row][j] == board[row][col] && j != col){
            collisions++;
        }
    }
    
    for(j = 0; j < m_size; ++j){
        if(board[j][col] == board[row][col] && j != row){
            collisions++;
        }
    }
    int tempRow = row / square_size * square_size;
    int tempCol = col / square_size * square_size;
    for(j = tempRow; j < tempRow + square_size;++j){
        for(int k = tempCol; k < tempCol + square_size; ++k){
            if(board[j][k] == board[row][col] && j != row && k != col){
               collisions++;
            }
        }
    }
        }
    }
    return collisions;
}


void optimazation_solver::solver(int n){
    bool solved = false;
    BST tree;
    for(int i =0;i<n;i++){
        int** board =generatesodu();
        int coll = heuristic(board);
        tree.insert(coll,board);
    }
    int** small_board = tree.smallestboard();
    int heris = tree.smallestherst();
    std::cout<<heris<<"\n";
    while(solved == false){
        if (heris == 0){
            sudo = small_board;
            solved = true;
        }
        else{
            tree.clean();
            BST tree;
            for(int i = 0 ;i<n;i++){
                 int** next = generatesuccessor(small_board);
                 int coll = heuristic(next);
                 tree.insert(coll, next);
            }
            small_board = tree.smallestboard();
            heris = tree.smallestherst();
       
        }
    }
    
}

int** optimazation_solver::generatesodu(){
    int** board =copyboard(sudo);
    int array[9];
    for(int j = 0 ;j<m_size;j++){
    for(int i = 1; i<m_size+1 ;i++){
        array[i-1] = i;
    }
    for(int k = 0; k<m_size;k++){
        for(int m = 0; m<m_size;m++){
            if (board[j][k] ==array[m]){
                array[m]=0;
            }
        }
        }
        
        for(int g =0; g<m_size;g++){
        if(board[j][g]==0){
        int num = rand()%m_size;
        while(array[num]==0){
            num = rand()%m_size;
        }
        board[j][g]=array[num];
        array[num]=0;
        }
        }
    
    }
    return board;
}
int** optimazation_solver::generatesuccessor(int** orig){
    
    int row = rand()%m_size;
   
    int index1 = rand()%m_size;
    
  
    while(hole[row][index1]==1){
        index1 = rand()%m_size;
    }
    
  
    int index2 = rand()%m_size;
    while(hole[row][index2]==1||index2==index1){
        srand(time(NULL));
        index2 = rand()&m_size;
    }
  
    
    int** board = copyboard(orig);
 
    int temp = board[row][index1];
    board[row][index1] =board[row][index2];
    board[row][index2] = temp;
    return board;
    
}

int** optimazation_solver::copyboard(int** orig){
    int** copy;
    copy = new int* [m_size] {};
    copy[0] = new int [m_size*m_size] {};
    
    for (int i=1; i<m_size; i++)
    {
        copy[i] = copy[i-1]+ m_size;
    }
    
    for (int i = 0; i < m_size; i++)
    {
        for (int j = 0; j<m_size; j++)
        {
            copy[i][j] = orig[i][j];
        }
    }
    
    return copy;
    
}

void optimazation_solver::sodu_printer(){
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


