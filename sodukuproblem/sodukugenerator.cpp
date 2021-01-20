#include "sodukugenerator.h"
using namespace std;
#include <cmath>

//construct the whole table using dynamic allocation.
sodukugenerator::sodukugenerator(int size){
    m_rows = size;
    m_columns = size;
    
    sudo = new int* [m_rows] {};
    sudo[0] = new int [m_rows*m_columns] {};
    
    for (int i=1; i<m_rows; i++)
    {
        sudo[i] = sudo[i-1]+ m_columns;
    }
    hole = new int* [m_rows] {};
    hole[0] = new int [m_rows*m_columns] {};
    
    for (int i=1; i<m_rows; i++)
    {
        hole[i] = hole[i-1]+ m_columns;
    }
    
    for (int i=1; i<m_rows; i++){
        for(int j=1; j<m_columns;j++){
            hole[i][j]=0;
        }
    }
    
  
}

//set: to put an number into certain position. before put, check if the position is occupied.
bool sodukugenerator::set(int x, int y, int val)
{
    //if it is not empty
    int square_size = sqrt(m_rows);
    if (sudo[y][x] != 0)
        return false;
    int x0, y0;
    for (x0=0; x0<m_rows; x0++)
    {
        if (sudo[y][x0] == val)  // row conflict
            return false;
    }
    for (y0=0; y0<m_rows; y0++)
    {
        if (sudo[y0][x] == val)    //column conflict
            return false;
    }
    for (y0=y/square_size*square_size; y0<y/square_size*square_size+square_size; y0++)
    {
        for (x0=x/square_size*square_size; x0<x/square_size*square_size+square_size; x0++)
        {
            if (sudo[y0][x0] == val) //small square conflict
                return false;
        }
    }
    sudo[y][x] = val;
    return true;
}

void sodukugenerator::reset(int x, int y)
{
    sudo[y][x] = 0;
}

void sodukugenerator::initXOrd(int* xOrd)    //to generate number from 1 to 9.
{
    int i, k, tmp;
    for (i=0; i<m_rows; i++)
    {
        xOrd[i] = i;
    }
    for (i=0; i<m_rows; i++)
    {
        k = rand() % m_rows;
        tmp = xOrd[k];
        xOrd[k] = xOrd[i];
        xOrd[i] = tmp;
    }
}

bool sodukugenerator::fillFrom(int y, int val)
{
    int xOrd[m_rows];
    initXOrd(xOrd);        //finish  scan to the current row.
    for (int i=0; i<m_rows; i++)
    {
        int x = xOrd[i];
        if (set(x, y, val))
        {
            if (y == m_rows-1)                    //it comes to the last colu.
            {
                if (val == m_rows || fillFrom(0, val+1))    //when it comes to 9, the function finish. otherwise it comes to the first number of next line.
                    return true;
            }
            else
            {
                if (fillFrom(y+1, val))    //it fill the next line
                    return true;
            }
            reset(x, y);    // using backtracking
        }
    }
    return false;
}

void sodukugenerator::digHole(int level){
    if(m_rows == 4){
        int idx[m_rows*m_columns];
        int i, k;
        for (i=0; i<m_rows*m_columns; i++)
        {
            hole[i / m_rows][i % m_rows] = 0;
            idx[i] = i;
        }
        for (i=0; i<level*2; i++)    //randomly position you dig a hole.
        {
            k = rand() % (m_rows*m_columns);
            int tmp = idx[k];
            idx[k] = idx[i];
            idx[i] = tmp;
        }
        for (i=0; i<level*2; i++)
        {
            hole[idx[i] / m_rows][idx[i] % m_rows] = 1;
        }
        
        
    }
    else{
        //randomly assign 47 positions to delete.
        if (level == 1) {
            sodukugenerator B(*this);
            int xy;
            for (int i = 0; i < 47; i++) {
                int times = 0;
                int x = rand() % m_rows;
                int y = rand() % m_rows;
                if(hole[x][y]==1){
                    i--;
                    continue;
                }
                
                hole[x][y]=1;
                xy = sudo[x][y];
                sudo[x][y]=0;
                B.getsudo()[x][y]=0;
                B.gethole()[x][y]=1;
                if(checkuniquety(B, 0, times)==2){//uniqueness check..
                    i--;
                    hole[x][y]=0;
                    sudo[x][y]=xy;
                }
                
            }
        //randomly assign 51 positions to delete.
        } else if (level == 2) {
            sodukugenerator B(*this);
            int xy;
            for (int i = 0; i < 51; i++) {
                int times = 0;
                int x = rand() % m_rows;
                int y = rand() % m_rows;
                if(hole[x][y]==1){
                    i--;
                    continue;
                }
                
                hole[x][y]=1;
                xy = sudo[x][y];
                sudo[x][y]=0;
                B.getsudo()[x][y]=0;
                B.gethole()[x][y]=1;
                if(checkuniquety(B, 0, times)==2){//uniqueness check..
                    i--;
                    hole[x][y]=0;
                    sudo[x][y]=xy;
                }
                
            }
        }
        /* use the seperation */
        else if (level == 3) {
            for(int i = 0 ;i < m_rows ; i ++){
                sodukugenerator B(*this);
                int xy;
                int times = 0;
                if( i % 2 == 0){
                    /*if it is even row the 8 hole is not allowed to be digged.*/
                    for(int j = 0 ;j < 6 ; j ++){
                        int tempY = rand() % m_rows;
                        if(tempY == 8 || hole[i][tempY]==1){j--;continue;}
                        hole[i][tempY]=1;
                        xy = sudo[i][tempY];
                        sudo[i][tempY]=0;
                        B.getsudo()[i][tempY]=0;
                        B.gethole()[i][tempY]=1;
                        if(checkuniquety(B, 0, times)==2){//uniqueness check..
                            j--;
                            hole[i][tempY]=0;
                            sudo[i][tempY]=xy;
                        }
                        
                    }
                }
                else{
                    for(int j = 0 ;j < 6 ; j ++){
                        sodukugenerator B(*this);
                        int xy;
                        int times = 0;
                        int tempY = rand() % m_rows;
                        if(tempY == 0|| hole[i][tempY]==1){j--;continue;}
                        hole[i][tempY]=1;
                        xy = sudo[i][tempY];
                        sudo[i][tempY]=0;
                        B.getsudo()[i][tempY]=0;
                        B.gethole()[i][tempY]=1;
                        if(checkuniquety(B, 0, times)==2){//uniqueness check..
                            j--;
                            hole[i][tempY]=0;
                            sudo[i][tempY]=xy;
                        }
                    }
                }
            }
            /*the rest of 4 is assigned randomly.*/
            for(int i = 0 ;i < 4 ; i ++){
                sodukugenerator B(*this);
                int xy;
                int times = 0;
                int tempX = rand() % m_rows;
                int tempY = rand() % m_rows;
                if(hole[tempX][tempY]==1){i--;continue;}
                else{
        
                    hole[tempX][tempY]=1;
                    xy = sudo[tempX][tempY];
                    sudo[tempX][tempY]=0;
                    B.getsudo()[tempX][tempY]=0;
                    B.gethole()[tempX][tempY]=1;
                    if(checkuniquety(B, 0, times)==2){//uniqueness check..
                        i--;
                        hole[tempX][tempY]=0;
                        sudo[tempX][tempY]=xy;
                    }
                }
            }
        }
        /* use the snake shape. dig at least 6 hole for each row. the rest of 6 is assigned randomly*/
        else if (level == 4) {
            for(int i = 0 ;i < m_rows ; i++){
                for(int j = 0 ; j < 6 ;j ++){
                    sodukugenerator B(*this);
                    int xy;
                    int times = 0;
                    int tempY = rand() % m_rows;
                    if(hole[i][tempY]==1){j--;continue;}
                    hole[i][tempY]=1;
                    xy = sudo[i][tempY];
                    sudo[i][tempY]=0;
                    B.getsudo()[i][tempY]=0;
                    B.gethole()[i][tempY]=1;
                    if(checkuniquety(B, 0, times)==2){//uniqueness check..
                        j--;
                        hole[i][tempY]=0;
                        sudo[i][tempY]=xy;
                    }
                }
                
            }
            for(int j  = 0 ;j < 6 ; j++){
                sodukugenerator B(*this);
                int xy;
                int times = 0;
                int tempY = rand() % m_rows;
                int tempX = rand() % m_rows;
                if(hole[tempX][tempY]==1){j--;continue;}
                hole[tempX][tempY]=1;
                xy = sudo[tempX][tempY];
                sudo[tempX][tempY]=0;
                B.getsudo()[tempX][tempY]=0;
                B.gethole()[tempX][tempY]=1;
                if(checkuniquety(B, 0, times)==2){//uniqueness check..
                    j--;
                    hole[tempX][tempY]=0;
                    sudo[tempX][tempY]=xy;
                }
                
                
            }
        }
        /* from left to right , from up to bottom */
        else if (level == 5) {
            
            for(int i = 0 ;i < m_rows ; i++){
                for(int j = 0 ; j < 6 ;j ++){
                    sodukugenerator B(*this);
                    int xy;
                    int times = 0;
                    int tempY = rand() % m_rows;
                    if(hole[i][tempY]==1){j--;continue;}
                    hole[i][tempY]=1;
                    xy = sudo[i][tempY];
                    sudo[i][tempY]=0;
                    B.getsudo()[i][tempY]=0;
                    B.gethole()[i][tempY]=1;
                    if(checkuniquety(B, 0, times)==2){//uniqueness check..
                        j--;
                        hole[i][tempY]=0;
                        sudo[i][tempY]=xy;
                    }
                    
                }
                
            }
            for(int i = 0 ;i < 8 ; i++){
                sodukugenerator B(*this);
                int xy;
                int times = 0;
                int tempY = rand() % m_rows;
                int tempX = rand() % m_rows;
                if(hole[tempX][tempY]==1){i--;continue;}
                hole[tempX][tempY]=1;
                xy = sudo[tempX][tempY];
                sudo[tempX][tempY]=0;
                B.getsudo()[tempX][tempY]=0;
                B.gethole()[tempX][tempY]=1;
                if(checkuniquety(B, 0, times)==2){//uniqueness check..
                    i--;
                    hole[tempX][tempY]=0;
                    sudo[tempX][tempY]=xy;
                }
                
            }
            
            
        }
    }
}
// to generate a full table and dighole from that
void sodukugenerator::num_generator(int level){
    while(!fillFrom(0, 1));
    digHole(level);
}
// print to the sodu and skip the holes to print.
void sodukugenerator::printSudo()
{
    int square_size = sqrt(m_rows);
    for (int y=0; y<m_rows; y++)
    {
        (y % square_size == 0) ? (cout << "------------------------\n ") : (cout << " ");
        for (int x=0; x<m_rows; x++)
        {
            (hole[y][x] == 0) ? (cout << sudo[y][x] << " ") : (cout << "  ");
            (x % square_size == square_size-1) ? (cout << "| ") : (cout << "");
        }
        cout << endl;
    }
    cout << "------------------------\n";
}

bool sodukugenerator::isPlace(int count){
    int square_size = sqrt(m_rows);
    int row = count / m_rows;
    int col = count % m_rows;
    int j;
    for(j = 0; j < m_rows; ++j){
        if(sudo[row][j] == sudo[row][col] && j != col){
            return false;
        }
    }
    
    for(j = 0; j < m_rows; ++j){
        if(sudo[j][col] == sudo[row][col] && j != row){
            return false;
        }
    }
    
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

//checkuniquety: to check the uniqueness or lack of soduku problem. if it has no solution return 0;
//if have one solution return 1. if has more than one solution return 2.
int sodukugenerator::checkuniquety(sodukugenerator generator,int count, int &times){
    if(count == generator.getsize()*generator.getsize()){
        return 1+times;
    }
    int row = count / generator.getsize();
    int col = count % generator.getsize();
    if(generator.getsudo()[row][col] == 0){
        for(int i = 1; i <= generator.getsize(); ++i){
            generator.getsudo()[row][col] = i;//place an number to certain place.
            if(isPlace(count)){//test if is ok to place in such positions
                times = checkuniquety(generator,count+1,times);//get into next level.
                if(times==2){
                    return times;
                }
            }
        }
        generator.getsudo()[row][col] = 0;//backtracking
    }else{
        times = checkuniquety(generator,count+1,times);//get into next level
        if(times==2){
            return times;
        }
    }
    
    return times;
}
