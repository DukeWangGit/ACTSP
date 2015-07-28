//#include "ant.h"
#include "stdlib.h"
#include "stdio.h"
#include "ant.h"
#include "math.h"
Ant::Ant(){
   
}
Ant::~Ant(){

}
void Ant::Init(){
    int i;
	
	for (i=0;i<NUM_CITY;i++){//设置所有城市为没去过的城市
        movedPath[i]=0;
		allowedCity[i]=1;
	}
	currentCityID=randIntNum(0,NUM_CITY);
	movedPath[0]=currentCityID;
	movedLength=0;
	passedCityNUM=1;
	allowedCity[currentCityID]=0;

	
}
void Ant::Move(){//需要完成的设置包括  选择出下一步要走的城市  增加去过的城市数目  在路径中加入这个城市  在禁忌表中这个城市禁止掉
    currentCityID=ChooseNextCity();
	movedPath[passedCityNUM]=currentCityID;
	passedCityNUM++;
	allowedCity[currentCityID]=0;
}
int Ant::ChooseNextCity(){
	int i,j;
    int chooseCity=-1;//将其定义为一个不是城市编号的数
    double totalInfo=0.0;//信息素和距离的双重影响
	double probablity[NUM_CITY];

	for(i=0;i<NUM_CITY;i++){
		if(1 == allowedCity[i]){
             probablity[i]=pow(DBQ_CITY[currentCityID][i],ALPHA)*pow(1.0/DISTANCE_CITY[currentCityID][i],BETA);//信息素的ALPHA 次方和距离倒数Beta次方的乘积 作为 该城市的概率
			 totalInfo+=probablity[i];
		}
		else{
			probablity[i]=0.0;
		}
	}


	//轮盘赌 选择下一个要去的城市
	double temp=0.0;

	if(totalInfo>0.0){
		temp=randDoubleNum(0.0,totalInfo);
		for(i=0;i<NUM_CITY;i++){
			if(1 == allowedCity[i]){
		 		temp-=probablity[i];
				if(temp<0.0){
					chooseCity=i;
					break;
				}
			}

		}

	}

	if(-1 == chooseCity){
		for (i=0;i<NUM_CITY;i++){
			if(allowedCity[i]==1){
				chooseCity= i;
				break;
			}
		}

	}

	return chooseCity;

}
void Ant::CalPassPathLength(){
	int i;
	movedLength=0.0; 
	for(i=0;i<NUM_CITY-1;i++){
       movedLength+=DISTANCE_CITY[movedPath[i]][movedPath[i+11]];
	}

	//这儿最容易忘记
	//还要加上从最后城市返回最开始城市的举例
	movedLength+=DISTANCE_CITY[movedPath[NUM_CITY-1]][movedPath[0]];

}

void Ant::Search(){
	Init();
	while(passedCityNUM<NUM_CITY){//考虑这个用< 还是≤
          //ChooseNextCity();
		  Move();
	}

	CalPassPathLength();
}