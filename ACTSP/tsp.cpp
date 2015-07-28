#include "tsp.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
TSP::TSP(){

}
TSP::~TSP(){

}
void TSP::InitDate(){//��ʼ������֮��ľ������Ϣ��
	int i,j;

	best_ant.movedLength=DB_MAX;//����·�����ȳ�ʼ��Ϊ���ֵ

	memset(DISTANCE_CITY,0,sizeof(DISTANCE_CITY));
	for(i=0;i<NUM_CITY;i++){//��ʼ��������Ϣ
		for(j=i+1;j<NUM_CITY;j++){
            DISTANCE_CITY[i][j]=round(sqrt(pow(city_x[i]-city_x[j],2)+pow(city_y[i]-city_y[j],2)));
			DISTANCE_CITY[j][i]=DISTANCE_CITY[i][j];
		}
	}

	//��Ϣ������Ϊÿ��·������ȵ�ֵ
	//memset(DBQ_CITY,1.0,sizeof(DBQ_CITY));
	for (i=0;i<NUM_CITY;i++){
		for (j=0;j<NUM_CITY;j++){
		    DBQ_CITY[i][j]=1.0;
		}
	}
}
void TSP::search(){
    int i,j;
    InitDate();
	for (i=0;i<NUM_Iterator;i++){
		for(j=0;j<NUM_ANT;j++){
			ant[j].Search();
		}

		for(j=0;j<NUM_ANT;j++){
			if(ant[j].movedLength<best_ant.movedLength){
                   best_ant=ant[j];
			}
		}
	}
	updateInfo();
}
void TSP::updateInfo(){
	double temp[NUM_CITY][NUM_CITY];
	memset(temp,0,sizeof(temp));
    int i,j;
	int x=0,y=0;
	for(i=0;i<NUM_ANT;i++){
		for(j=0;j<NUM_CITY-1;j++){
			x=ant[i].movedPath[j];
			y=ant[i].movedPath[j+1];
            temp[x][y]+= DBQ/ant[i].movedLength;
			temp[y][x]=temp[x][y];
		}

		x=ant[i].movedPath[0];
		temp[x][y]+=DBQ/ant[i].movedLength;
		temp[y][x]=temp[x][y];
	}
    //������Ϣ��
	for(i=0;i<NUM_CITY;i++){
		for(j=0;j<NUM_CITY;j++){
            DBQ_CITY[i][j]=DBQ_CITY[i][j]*ROU+temp[i][j];
		}
	}
}