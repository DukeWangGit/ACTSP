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
	
	for (i=0;i<NUM_CITY;i++){//�������г���Ϊûȥ���ĳ���
        movedPath[i]=0;
		allowedCity[i]=1;
	}
	currentCityID=randIntNum(0,NUM_CITY);
	movedPath[0]=currentCityID;
	movedLength=0;
	passedCityNUM=1;
	allowedCity[currentCityID]=0;

	
}
void Ant::Move(){//��Ҫ��ɵ����ð���  ѡ�����һ��Ҫ�ߵĳ���  ����ȥ���ĳ�����Ŀ  ��·���м����������  �ڽ��ɱ���������н�ֹ��
    currentCityID=ChooseNextCity();
	movedPath[passedCityNUM]=currentCityID;
	passedCityNUM++;
	allowedCity[currentCityID]=0;
}
int Ant::ChooseNextCity(){
	int i,j;
    int chooseCity=-1;//���䶨��Ϊһ�����ǳ��б�ŵ���
    double totalInfo=0.0;//��Ϣ�غ;����˫��Ӱ��
	double probablity[NUM_CITY];

	for(i=0;i<NUM_CITY;i++){
		if(1 == allowedCity[i]){
             probablity[i]=pow(DBQ_CITY[currentCityID][i],ALPHA)*pow(1.0/DISTANCE_CITY[currentCityID][i],BETA);//��Ϣ�ص�ALPHA �η��;��뵹��Beta�η��ĳ˻� ��Ϊ �ó��еĸ���
			 totalInfo+=probablity[i];
		}
		else{
			probablity[i]=0.0;
		}
	}


	//���̶� ѡ����һ��Ҫȥ�ĳ���
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

	//�������������
	//��Ҫ���ϴ������з����ʼ���еľ���
	movedLength+=DISTANCE_CITY[movedPath[NUM_CITY-1]][movedPath[0]];

}

void Ant::Search(){
	Init();
	while(passedCityNUM<NUM_CITY){//���������< ���ǡ�
          //ChooseNextCity();
		  Move();
	}

	CalPassPathLength();
}