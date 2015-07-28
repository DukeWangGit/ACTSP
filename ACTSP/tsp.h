#pragma once
#include "ant.h"
#include "ACTSP.h"
class TSP{
public:
	TSP();
	~TSP();
public:
	Ant ant[NUM_ANT];
	Ant best_ant;

public:
	void InitDate();
	void search();
	void updateInfo();
};