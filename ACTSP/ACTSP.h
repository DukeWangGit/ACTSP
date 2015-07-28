
#pragma once

//extern double ALPHA;
//extern double BETA;
//extern double ROU;
//
//extern int NUM_CITY;
//extern int NUM_ANT;
//extern int NUM_Iterator;
//
//extern double DBQ;


#define ALPHA 1.0

#define BETA 2.0
#define ROU 0.5
#define NUM_CITY 51
#define NUM_ANT 34 
#define NUM_Iterator 1000

#define DBQ 100.0
#define DB_MAX 10e9

extern double DBQ_CITY[NUM_CITY][NUM_CITY];
extern double DISTANCE_CITY[NUM_CITY][NUM_CITY];

extern double city_x[NUM_CITY];
extern double city_y[NUM_CITY];

int randIntNum(int x,int y);
double randDoubleNum(double x,double y);
double round(double x);