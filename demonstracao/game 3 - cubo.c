#include "poly/poly.h"

int cubo[54];
int troca[39][4]={
	{0,9,18,27},
	{1,10,19,28},
	{2,11,20,29},
	{42,44,38,36},
	{43,41,37,39},

	{3,12,21,30},
	{4,13,22,31},
	{5,14,23,32},

	{6,15,24,33},
	{7,16,25,34},
	{8,17,26,35},
	{45,47,53,51},
	{46,50,52,48},

	{45,15,44,29},
	{46,12,43,32},
	{47,9,42,35},
	{6,8,2,0},
	{7,5,1,3},

	{48,16,41,28},
	{49,13,40,31},
	{50,10,39,34},

	{51,17,38,27},
	{52,14,37,30},
	{53,11,36,33},
	{26,24,18,20},
	{25,21,19,23},

	{36,0,45,26},
	{39,3,48,23},
	{42,6,51,20},
	{29,35,33,27},
	{32,34,30,28},

	{37,1,46,25},
	{40,4,49,22},
	{43,7,52,19},

	{38,2,47,24},
	{41,5,50,21},
	{44,8,53,18},
	{9,15,17,11},
	{12,16,14,10}
};

void ladrilho(int cor,int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
	setcolor(cor);
	int background[8]={x1,y1,x2,y2,x3,y3,x4,y4};
	fillpoly(background,4);
}

void seleciona(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
	int background[8]={x1,y1,x2,y2,x3,y3,x4,y4};
	drawpoly(background,4);
}

void prala(int indice){
	int extra=cubo[troca[indice][0]];
	cubo[troca[indice][0]]=cubo[troca[indice][1]];
	cubo[troca[indice][1]]=cubo[troca[indice][2]];
	cubo[troca[indice][2]]=cubo[troca[indice][3]];
	cubo[troca[indice][3]]=extra;
}
void praca(int indice){
	int extra=cubo[troca[indice][3]];
	cubo[troca[indice][3]]=cubo[troca[indice][2]];
	cubo[troca[indice][2]]=cubo[troca[indice][1]];
	cubo[troca[indice][1]]=cubo[troca[indice][0]];
	cubo[troca[indice][0]]=extra;
}

void main(){
	int sel=4,pressed=0;

	for(int x=0;x<9;x++)cubo[x]=41;
	for(int x=9;x<18;x++)cubo[x]=54;
	for(int x=18;x<27;x++)cubo[x]=22;
	for(int x=27;x<36;x++)cubo[x]=43;
	for(int x=36;x<45;x++)cubo[x]=73;
	for(int x=45;x<54;x++)cubo[x]=49;
	
	setvideomode();

	while(!keystate(KEY_ESCAPE)){
			//if(keystate(KEY_UP)&&keystate(KEY_SHIFT)&&keystate(KEY_CONTROL))howHigh=5;
			
			if(pressed==0&&keystate(KEY_LEFT)&&keystate(KEY_SHIFT)){
				switch(sel){
					case 0: case 1: case 2:
						prala(0); prala(1); prala(2); prala(3); prala(4);
					break;
					case 3: case 4: case 5:
						prala(5); prala(6); prala(7);
					break;
					case 6: case 7: case 8:
						prala(8); prala(9); prala(10); prala(11); prala(12);
					break;
					case 9: case 10: case 11:
						prala(13); prala(14); prala(15); prala(16); prala(17);
					break;
					case 12: case 13: case 14:
						prala(18); prala(19); prala(20);
					break;
					case 15: case 16: case 17:
						prala(21); prala(22); prala(23); prala(24); prala(25);
					break;
				}
				pressed=8;
			}
			else if(pressed==0&&keystate(KEY_RIGHT)&&keystate(KEY_SHIFT)){
				switch(sel){
					case 0: case 1: case 2:
						praca(0); praca(1); praca(2); praca(3); praca(4);
					break;
					case 3: case 4: case 5:
						praca(5); praca(6); praca(7);
					break;
					case 6: case 7: case 8:
						praca(8); praca(9); praca(10); praca(11); praca(12);
					break;
					case 9: case 10: case 11:
						praca(13); praca(14); praca(15); praca(16); praca(17);
					break;
					case 12: case 13: case 14:
						praca(18); praca(19); praca(20);
					break;
					case 15: case 16: case 17:
						praca(21); praca(22); praca(23); praca(24); praca(25);
					break;
				}
				pressed=8;
			}
			else if(pressed==0&&keystate(KEY_UP)&&keystate(KEY_SHIFT)){
				switch(sel){
					case 0: case 3: case 6: case 9: case 12: case 15:
						prala(26); prala(27); prala(28); prala(29); prala(30);
					break;
					case 1: case 4: case 7: case 10: case 13: case 16:
						prala(31); prala(32); prala(33);
					break;
					case 2: case 5: case 8: case 11: case 14: case 17:
						prala(34); prala(35); prala(36); prala(37); prala(38);
					break;
				}
				pressed=8;
			}
			else if(pressed==0&&keystate(KEY_DOWN)&&keystate(KEY_SHIFT)){
				switch(sel){
					case 0: case 3: case 6: case 9: case 12: case 15:
						praca(26); praca(27); praca(28); praca(29); praca(30);
					break;
					case 1: case 4: case 7: case 10: case 13: case 16:
						praca(31); praca(32); praca(33);
					break;
					case 2: case 5: case 8: case 11: case 14: case 17:
						praca(34); praca(35); praca(36); praca(37); praca(38);
					break;
				}
				pressed=8;
			}
			else if(pressed==0&&keystate(KEY_UP)&&sel>2){
				sel-=3;
				pressed=8;
			}
			else if(pressed==0&&keystate(KEY_DOWN)&&sel<15){
				sel+=3;
				pressed=8;
			}
			else if(pressed==0&&keystate(KEY_LEFT)&&sel%3!=0){
				sel-=1;
				pressed=8;
			}
			else if(pressed==0&&keystate(KEY_RIGHT)&&sel%3!=2){
				sel+=1;
				pressed=8;
			}
			else if(pressed>0)pressed--;

			ladrilho(cubo[27],55,100,70,70,85,100,70,130);
			ladrilho(cubo[28],70,70,85,40,100,70,85,100);
			ladrilho(cubo[29],85,40,100,10,115,40,100,70);
			
			ladrilho(cubo[30],70,130,85,100,100,130,85,160);
			ladrilho(cubo[31],85,100,100,70,115,100,100,130);
			ladrilho(cubo[32],100,70,115,40,130,70,115,100);
			
			ladrilho(cubo[33],85,160,100,130,115,160,100,190);
			ladrilho(cubo[34],100,130,115,100,130,130,115,160);
			ladrilho(cubo[35],115,100,130,70,145,100,130,130);

			ladrilho(cubo[0],100,10,140,10,155,40,115,40);
			ladrilho(cubo[1],140,10,180,10,195,40,155,40);
			ladrilho(cubo[2],180,10,220,10,235,40,195,40);

			ladrilho(cubo[3],115,40,155,40,170,70,130,70);
			ladrilho(cubo[4],155,40,195,40,210,70,170,70);
			ladrilho(cubo[5],195,40,235,40,250,70,210,70);
			
			ladrilho(cubo[6],130,70,170,70,185,100,145,100);
			ladrilho(cubo[7],170,70,210,70,225,100,185,100);
			ladrilho(cubo[8],210,70,250,70,265,100,225,100);

			ladrilho(cubo[51],100,190,140,190,155,160,115,160);
			ladrilho(cubo[52],140,190,180,190,195,160,155,160);
			ladrilho(cubo[53],180,190,220,190,235,160,195,160);

			ladrilho(cubo[48],115,160,155,160,170,130,130,130);
			ladrilho(cubo[49],155,160,195,160,210,130,170,130);
			ladrilho(cubo[50],195,160,235,160,250,130,210,130);
			
			ladrilho(cubo[45],130,130,170,130,185,100,145,100);
			ladrilho(cubo[46],170,130,210,130,225,100,185,100);
			ladrilho(cubo[47],210,130,250,130,265,100,225,100);

			setcolor(0);
			line(55,100,100,10);
			line(55,100,100,190);
			line(145,100,100,10);
			line(145,100,100,190);

			line(100,10,220,10);
			line(145,100,265,100);
			line(100,190,220,190);

			line(220,10,265,100);
			line(220,190,265,100);

			line(70,70,115,160);
			line(85,40,130,130);
			line(70,130,115,40);
			line(85,160,130,70);

			line(115,40,235,40);
			line(130,70,250,70);
			line(140,10,185,100);
			line(180,10,225,100);

			line(115,160,235,160);
			line(130,130,250,130);
			line(140,190,185,100);
			line(180,190,225,100);

			setcolor(7);
			if(sel==0)seleciona(100,10,140,10,155,40,115,40);
			if(sel==1)seleciona(140,10,180,10,195,40,155,40);
			if(sel==2)seleciona(180,10,220,10,235,40,195,40);
			if(sel==3)seleciona(115,40,155,40,170,70,130,70);
			if(sel==4)seleciona(155,40,195,40,210,70,170,70);
			if(sel==5)seleciona(195,40,235,40,250,70,210,70);
			if(sel==6)seleciona(130,70,170,70,185,100,145,100);
			if(sel==7)seleciona(170,70,210,70,225,100,185,100);
			if(sel==8)seleciona(210,70,250,70,265,100,225,100);
			if(sel==15)seleciona(100,190,140,190,155,160,115,160);
			if(sel==16)seleciona(140,190,180,190,195,160,155,160);
			if(sel==17)seleciona(180,190,220,190,235,160,195,160);
			if(sel==12)seleciona(115,160,155,160,170,130,130,130);
			if(sel==13)seleciona(155,160,195,160,210,130,170,130);
			if(sel==14)seleciona(195,160,235,160,250,130,210,130);
			if(sel==9)seleciona(130,130,170,130,185,100,145,100);
			if(sel==10)seleciona(170,130,210,130,225,100,185,100);
			if(sel==11)seleciona(210,130,250,130,265,100,225,100);

			sleep(20);
			waitvbl();
	}
}
