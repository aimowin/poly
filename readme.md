## Compilar
Para gerar o arquivo executável *(o jogo)* basta executar o arquivo 'compila'

Esse arquivo envia o código-fonte do arquivo *game.c* para o compilador tcc\
(Tiny C Compiler).

No desenvolvimento de software é comum errar e tentar de novo.\
Caso haja algum erro no código o 'compila' irá falhar.\
As regras da linguagem C são muitas e são rígidas.

O **compila.bat** exibe uma descrição do erro (em inglês) caso o executável não possa ser gerado.\
Procurar na internet pela descrição do erro exibida é uma boa iniciativa. 

## Código Mínimo (entrando no modo gráfico)
```c
#include "poly/poly.h"
main(){
	setvideomode();
	while(!keystate(KEY_ESCAPE)){

		waitvbl();
	}
}
```

## Poly
Esse é um software resignadamente educacional e os jogos resultantes tem limitações.\
Bons softwares geralmente exploram alguns limites e esse é complacente.

O objetivo desse software é incentivar a comunidade brasileira de jogos.\
Esse software atua na divulgação do fato que escrever código é legal.

## Funções Poly
```c
void setcolor(int color);
int getcolor();
void putpixel(int x,int y,int color);
void line(int x1,int y1,int x2,int y2);
void rectangle(int x,int y,int w,int h);
void bar(int x,int y,int w,int h);
void circle(int x,int y,int r);
void fillcircle(int x,int y,int r);
void ellipse(int x,int y,int rx,int ry);
void fillellipse(int x,int y,int rx,int ry);
void drawpoly(int* points_xy,int count);
void fillpoly(int* points_xy,int count);
void floodfill(int x,int y);
void boundaryfill(int x,int y,int boundary);
void blitInt(int n,int x,int y);
```
