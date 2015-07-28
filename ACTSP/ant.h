#pragma once
#include "ACTSP.h"

class Ant{
public:
	Ant();
	~Ant();
public:
   int movedPath[NUM_CITY];//蚂蚁走过的路径
   int allowedCity[NUM_CITY];//taku 禁忌表

   int passedCityNUM;//已经去过城市的数量
   double movedLength;//已经去过城市的路径长度
   int currentCityID;//现在所在城市的编号

   void Init();
   void Move();
   void Search();
   int ChooseNextCity();
   void CalPassPathLength();
};