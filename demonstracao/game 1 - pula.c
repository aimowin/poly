#include "poly/poly.h"

int posicaoObstaculo1;
int posicaoObstaculo2;
int posicaoObstaculo3;
int alturaPulo = 0;
int gameover = 0;

void inicializaJogo() { //função que reseta as variavei para o jogo começar
	posicaoObstaculo1 =- 250;
	posicaoObstaculo2 =- 250;
	posicaoObstaculo3 =- 250;
	alturaPulo=0;
	gameover=0;
}

int main() {  //função principal
	setvideomode(); //modo gráfico

	inicializaJogo(); //chama a função que reseta as variavei para o jogo começar

	while(!keystate(KEY_ESCAPE)) { //loop que se repete ATÉ QUE O JOGADOR APERTE A TECLA ESC

		if(gameover != 0) { //se o jogo terminou
			if(keystate(KEY_UP)) //se o jogador apertou a tecla UP do teclado
				inicializaJogo(); //chama a função que reseta as variavei para o jogo começar

		} else { //se o jogo está rolando

			if(alturaPulo == 0 && keystate(KEY_UP)) //se o Joe está no solo e o jogador apertou a tecla UP do teclado
				alturaPulo = 5; //altura do pulo do Joe passa a ser 5 pixels

			if(alturaPulo % 4 == 1) //se a altura do pulo do joe é um (múltiplo de 4) mais um
				alturaPulo += 4; //joe sobe 4 pixels

			if(alturaPulo % 4 == 3) //se a altura do pulo do joe é um (múltiplo de 4) mais três
				alturaPulo -= 4; //joe desce 4 pixels

			if(alturaPulo > 28)
				alturaPulo = 31;

			if(alturaPulo < 2)
				alturaPulo = 0;

			//as três linhas abaixo desenham o retangulo onde o jogo rola
			setcolor(15);
			int background[8] = {20, 30, 300, 30, 300, 100, 20, 100};
			fillpoly(background, 4);

			setcolor(2); //verde

			int head[8] = {
				52, 80 - alturaPulo,
				56, 80 - alturaPulo,
				56, 83 - alturaPulo,
				52, 83 - alturaPulo};
			fillpoly(head, 4); //cabeça do Joe

			int arms[8] = {
				48, 84 - alturaPulo,
				60, 84 - alturaPulo,
				60, 86 - alturaPulo,
				48, 86 - alturaPulo};
			fillpoly(arms, 4); //braços do Joe

			int body[8] = {
				53, 86 - alturaPulo,
				56, 86 - alturaPulo,
				56, 91 - alturaPulo,
				53, 91 - alturaPulo};
			fillpoly(body, 4); //tronco

			//pernas
			int rightLeg[8] = {
				52, 91 - alturaPulo,
				54, 91 - alturaPulo,
				54, 98 - alturaPulo,
				52, 98 - alturaPulo};
			fillpoly(rightLeg, 4);
			int leftLeg[8] = {
				55, 91 - alturaPulo,
				57, 91 - alturaPulo,
				57, 98 - alturaPulo,
				55, 98 - alturaPulo};
			fillpoly(leftLeg, 4);

			setcolor(12); //vermelho
			posicaoObstaculo1 = (posicaoObstaculo1 + 3) % 274;
			posicaoObstaculo2 = (posicaoObstaculo2 + 4) % 274;
			posicaoObstaculo3 = (posicaoObstaculo3 + 5) % 274;

			int obs1[6] = {
				292 - posicaoObstaculo1, 98,
				296 - posicaoObstaculo1, 88,
				300 - posicaoObstaculo1, 98}; //coordenadas do obstáculo1 posicionado
			int obs2[6] = {
				292 - posicaoObstaculo2, 98,
				296 - posicaoObstaculo2, 88,
				300 - posicaoObstaculo2, 98}; //coordenadas do obstáculo2 posicionado
			int obs3[6] = {
				292 - posicaoObstaculo3, 98,
				296 - posicaoObstaculo3, 88,
				300 - posicaoObstaculo3, 98}; //coordenadas do obstáculo3 posicionado

			//desenha os obstáculos na tela
			if(posicaoObstaculo1 > 0) fillpoly(obs1, 3);
			if(posicaoObstaculo2 > 0) fillpoly(obs2, 3);
			if(posicaoObstaculo3 > 0) fillpoly(obs3, 3);

			//se o Joe está em colisão com algum dos obstáculos a variável gameover muda de valor
			if(posicaoObstaculo1 > 232 && posicaoObstaculo1 < 242 && alturaPulo < 9) gameover = 1;
			if(posicaoObstaculo2 > 232 && posicaoObstaculo2 < 242 && alturaPulo < 9) gameover = 1;
			if(posicaoObstaculo3 > 232 && posicaoObstaculo3 < 242 && alturaPulo < 9) gameover = 1;

			sleep(20); //pausa de 20 milissegundos
			waitvbl();
		}
	}
	return 0;
}
