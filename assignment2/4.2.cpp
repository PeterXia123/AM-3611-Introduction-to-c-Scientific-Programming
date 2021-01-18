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

    
    int x, y, *a, *b, temp;
    
    printf("Enter the value of x and y\n");
    scanf("%d%d", &x, &y);
    
    printf("Before Swapping\nx = %d\ny = %d\n", x, y);
    
    a = &x;
    b = &y;
    
    temp = *b;
    *b = *a;
    *a = temp;
    
    printf("After Swapping\nx = %d\ny = %d\n", x, y);
    
    return 0;
    
    
    
    
}




