#include "poly/poly.h"
int obstacle1,obstacle2,obstacle3,howHigh,gameover;
void init(){
	obstacle1=-250;
	obstacle2=-250;
	obstacle3=-250;
	howHigh=0;
	gameover=0;
}
int main(){
	setvideomode();
	init();
	while(!keystate(KEY_ESCAPE)){
		if(gameover!=0){
			if(keystate(KEY_UP))init();
		}else{
			if(howHigh==0&&keystate(KEY_UP))howHigh=5;
			if(howHigh%4==1)howHigh+=4;
			if(howHigh%4==3)howHigh-=4;
			if(howHigh>28)howHigh=31;
			if(howHigh<2)howHigh=0;
			setcolor(15);
			int background[8]={20,30,300,30,300,100,20,100};
			fillpoly(background,4);
			setcolor(2);
			int head[8]={
				52,80-howHigh,
				56,80-howHigh,
				56,83-howHigh,
				52,83-howHigh};
			fillpoly(head,4);
			int arms[8]={
				48,84-howHigh,
				60,84-howHigh,
				60,86-howHigh,
				48,86-howHigh};
			fillpoly(arms,4);
			int body[8]={
				53,86-howHigh,
				56,86-howHigh,
				56,91-howHigh,
				53,91-howHigh};
			fillpoly(body,4);
			int rightLeg[8]={
				52,91-howHigh,
				54,91-howHigh,
				54,98-howHigh,
				52,98-howHigh};
			fillpoly(rightLeg,4);
			int leftLeg[8]={
				55,91-howHigh,
				57,91-howHigh,
				57,98-howHigh,
				55,98-howHigh};
			fillpoly(leftLeg,4);
			setcolor(12);
			obstacle1=(obstacle1+3)%274;
			obstacle2=(obstacle2+4)%274;
			obstacle3=(obstacle3+5)%274;
			int obs1[6]={
				292-obstacle1,98,
				296-obstacle1,88,
				300-obstacle1,98};
			int obs2[6]={
				292-obstacle2,98,
				296-obstacle2,88,
				300-obstacle2,98};
			int obs3[6]={
				292-obstacle3,98,
				296-obstacle3,88,
				300-obstacle3,98};
			if(obstacle1>0)fillpoly(obs1,3);
			if(obstacle2>0)fillpoly(obs2,3);
			if(obstacle3>0)fillpoly(obs3,3);
			if(obstacle1>232&&obstacle1<242&&howHigh<9)gameover=1;
			if(obstacle2>232&&obstacle2<242&&howHigh<9)gameover=1;
			if(obstacle3>232&&obstacle3<242&&howHigh<9)gameover=1;
			sleep(20);
			waitvbl();
		}
	}
	return 0;
}
