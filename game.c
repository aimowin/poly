#include "poly/poly.h"
int main(){
	setvideomode();
	while(!keystate(KEY_ESCAPE)){

		waitvbl();
	}
	return 0;
}
