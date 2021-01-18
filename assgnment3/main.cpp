//
//  main.cpp
//  3611asn3
//
//  Created by yufei xia on 2018/10/8.
//  Copyright © 2018年 yufei xia. All rights reserved.
//

#include <iostream>
#include <cmath>
double rand_gen();
double cal_mean(int *array, int size);
void cal_sd (int *array, double mean, int size, double& sd, double& skew);
int main(int argc, const char * argv[]) {
    int size;
    double mean;
    double skew;
    double sd;
    std::cout<<"please input the size of array N"<<std::endl;
    std::cin>>size;
    int *array = new int[size];
    for (int i=0; i<size-1 ;i++){
        array[i] = rand_gen();
    }
    mean = cal_mean(array,size);
    cal_sd(array,mean,size,sd,skew);
    std::cout<<"the sd of those random numbers are "<<sd<<std::endl;
    std::cout<<"the skew of those random numbers are "<<skew<<std::endl;
    delete[] array;
    
}


double rand_gen(){
    int randomint;
    randomint=std::rand();
    double randomdoub;
    randomdoub= static_cast<double>(randomint)/RAND_MAX;
    return randomdoub;
}


double cal_mean(int *array, int size){
    double sum = 0;
    for(int i = 0; i<size;i++){
        sum+=array[i];
    }
    return sum/size;
}


void cal_sd (int *array, double mean, int size, double& sd){
    double sum_2 = 0;
    for(int i =0;i<size;i++){
        sum_2 += pow(array[i]-mean,2);
    }
    sd = sqrt(sum_2/(size -1));
    
}

void cal_sd (int *array, double mean, int size, double& sd, double& skew){
    double sum_3 = 0;
    double sum_2 = 0;
    for(int i =0;i<size;i++){
        sum_2 += pow(array[i]-mean,2);
        sum_3 += pow(array[i]-mean,3);
    }
    sd = sqrt(sum_2/(size -1));
    skew =sum_3/(size*pow(sd,3));
}







