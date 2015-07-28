#pragma once
#include "ACTSP.h"

class Ant{
public:
	Ant();
	~Ant();
public:
   int movedPath[NUM_CITY];//�����߹���·��
   int allowedCity[NUM_CITY];//taku ���ɱ�

   int passedCityNUM;//�Ѿ�ȥ�����е�����
   double movedLength;//�Ѿ�ȥ�����е�·������
   int currentCityID;//�������ڳ��еı��

   void Init();
   void Move();
   void Search();
   int ChooseNextCity();
   void CalPassPathLength();
};