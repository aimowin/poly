#include "poly/poly.h"
int exibicao=0;
int fila[100];
int tamanho=0;
void quadrado(int sel){
	int x=sel%15,y=sel/15;
	int background[8]={
	(10+(x*20))+2,(y*20)+12,
	(10+(x*20))+19,(y*20)+12,
	(10+(x*20))+19,(y*20)+28,
	(10+(x*20))+2,(y*20)+28};
	fillpoly(background,4);
}
void addMoves(){
	int movimentos=rand()%3;
	for(int x=0;x<movimentos+1;x++){
		int meio;
		do{
			int move=rand()%4;
			meio=-1;
			if(move==0&&fila[tamanho-1]%15!=0)meio=fila[tamanho-1]-1;
			if(move==1&&fila[tamanho-1]>14)meio=fila[tamanho-1]-15;
			if(move==2&&fila[tamanho-1]%15!=14)meio=fila[tamanho-1]+1;
			if(move==3&&fila[tamanho-1]<120)meio=fila[tamanho-1]+15;
		}while(meio==-1);
		fila[tamanho]=meio;
		tamanho++;
	}
}
int main(){
	int sel=0;
	int last=0;
	int tic=0;
	int moves[100];
	int mexidas=0;
	srand(time(0));
	fila[0]=rand()%135;
	moves[0]=fila[0];
	tamanho=1;
	mexidas=1;
	sel=fila[0];
	setvideomode();
	while(!keystate(KEY_ESCAPE)){
		if(tamanho==mexidas&&exibicao==-1){
			int iguais=1;
			for(int x=0;x<tamanho;x++)if(moves[x]!=fila[x])iguais=0;
			if(iguais==0){
				fila[0]=rand()%135;
				moves[0]=fila[0];
				tamanho=1;
				mexidas=1;
			}
			addMoves();
			exibicao=0;
			mexidas=1;
			sel=fila[0];
		}
		if(exibicao>-1){
			setcolor(0);
			rectangle(5,6,310,188);
			setcolor(15);
			for(int x=0;x<135;x++)quadrado(x);
			setcolor(55);
			quadrado(fila[exibicao]);
			tic++;
			if(tic>20){
				tic=0;
				exibicao++;
				if(exibicao==tamanho)exibicao=-1;
			}
		}
		else{
			setcolor(15);
			rectangle(5,6,310,188);
			setcolor(0);
			for(int x=0;x<135;x++)quadrado(x);
			setcolor(42);
			if(last==0&&sel%15!=0&&keystate(KEY_LEFT))sel-=1;
			if(last==0&&sel>14&&keystate(KEY_UP))sel-=15;
			if(last==0&&sel%15!=14&&keystate(KEY_RIGHT))sel+=1;
			if(last==0&&sel<120&&keystate(KEY_DOWN))sel+=15;
			if(last==0&&(keystate(KEY_LEFT)||keystate(KEY_UP)||keystate(KEY_RIGHT)||keystate(KEY_DOWN))){
				moves[mexidas]=sel;
				mexidas++;
				last=10;
			}
			else if(last>0)last--;
			quadrado(sel);
		}
		sleep(20);
		waitvbl();
	}
	return 0;
}
