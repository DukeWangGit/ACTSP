// ACTSP.cpp : 定义控制台应用程序的入口点。
//
#include "ACTSP.h"
#include "stdio.h"
#include "stdlib.h"
#include "tsp.h"

#include "time.h"



//double ALPHA=0.5;
//double BETA=0.5;
//double ROU=0.5;
//
//const int NUM_CITY=51;
//const int NUM_ANT=34;
//const int NUM_Iterator=100;
//
//double DBQ = 100;


double DBQ_CITY[NUM_CITY][NUM_CITY];
double DISTANCE_CITY[NUM_CITY][NUM_CITY];

double city_x[NUM_CITY]={
	37,49,52,20,40,21,17,31,52,51,  
	42,31,5,12,36,52,27,17,13,57,  
	62,42,16,8,7,27,30,43,58,58,  
	37,38,46,61,62,63,32,45,59,5,  
	10,21,5,30,39,32,25,25,48,56,  
	30 
};
double city_y[NUM_CITY]={
	52,49,64,26,30,47,63,62,33,21,  
	41,32,25,42,16,41,23,33,13,58,  
	42,57,57,52,38,68,48,67,48,27,  
	69,46,10,33,63,69,22,35,15,6,  
	17,10,64,15,10,39,32,55,28,37,  
	40 
};
int randIntNum(int a,int b){
    return (int)((double)rand()/((RAND_MAX + 1.0) / (b-a+1.0))+ a);  
}
double randDoubleNum(double a,double b){
    return (double)rand()/((double)RAND_MAX /(b-a))+a;  
}

double round(double x){//四舍五入函数
	return (double)((int)(x+0.5));
}


int main(){
	time_t tm;
	time(&tm);
	unsigned int nseed=(unsigned int)tm;
	srand(nseed);
    //printf("the best path is \n");
    TSP tsp;
	tsp.InitDate();
	tsp.search();
	printf("the best routh:\n");

	char buffer[150];
    int i=0;
	for(i=0;i<NUM_CITY;i++){
       sprintf(buffer,"%d ",tsp.best_ant.movedPath[i]+1);

	   if(i%20==0){
		   printf("\n");
	   }
	   printf(buffer);
	}
	system("PAUSE");
	return 0;
}
