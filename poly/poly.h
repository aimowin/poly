void setvideomode();
unsigned char* screenbuffer();
unsigned char* swapbuffers();
void waitvbl();
void setpal(int index,int r,int g,int b);
void getpal(int index,int* r,int* g,int* b);

int shuttingdown();

int getpixel(int x,int y);
void hline(int x,int y,int len,int color);
void putpixel(int x,int y,int color);

void setdrawtarget(unsigned char* pixels,int width,int height);

void setcolor(int color);
int getcolor();
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

enum keycode_t{
	KEY_INVALID,KEY_LBUTTON,KEY_RBUTTON,KEY_CANCEL,KEY_MBUTTON,KEY_XBUTTON1,KEY_XBUTTON2,KEY_BACK,KEY_TAB,
	KEY_CLEAR,KEY_RETURN,KEY_SHIFT,KEY_CONTROL,KEY_MENU,KEY_PAUSE,KEY_CAPITAL,KEY_KANA,KEY_HANGUL=KEY_KANA,
	KEY_JUNJA,KEY_FINAL,KEY_HANJA,KEY_KANJI=KEY_HANJA,KEY_ESCAPE,KEY_CONVERT,KEY_NONCONVERT,KEY_ACCEPT,
	KEY_MODECHANGE,KEY_SPACE,KEY_PRIOR,KEY_NEXT,KEY_END,KEY_HOME,KEY_LEFT,KEY_UP,KEY_RIGHT,KEY_DOWN,
	KEY_SELECT,KEY_PRINT,KEY_EXEC,KEY_SNAPSHOT,KEY_INSERT,KEY_DELETE,KEY_HELP,KEY_0,KEY_1,KEY_2,KEY_3,KEY_4,
	KEY_5,KEY_6,KEY_7,KEY_8,KEY_9,KEY_A,KEY_B,KEY_C,KEY_D,KEY_E,KEY_F,KEY_G,KEY_H,KEY_I,KEY_J,KEY_K,
	KEY_L,KEY_M,KEY_N,KEY_O,KEY_P,KEY_Q,KEY_R,KEY_S,KEY_T,KEY_U,KEY_V,KEY_W,KEY_X,KEY_Y,KEY_Z,KEY_LWIN,
	KEY_RWIN,KEY_APPS,KEY_SLEEP,KEY_NUMPAD0,KEY_NUMPAD1,KEY_NUMPAD2,KEY_NUMPAD3,KEY_NUMPAD4,KEY_NUMPAD5,
	KEY_NUMPAD6,KEY_NUMPAD7,KEY_NUMPAD8,KEY_NUMPAD9,KEY_MULTIPLY,KEY_ADD,KEY_SEPARATOR,KEY_SUBTRACT,KEY_DECIMAL,
	KEY_DIVIDE,KEY_F1,KEY_F2,KEY_F3,KEY_F4,KEY_F5,KEY_F6,KEY_F7,KEY_F8,KEY_F9,KEY_F10,KEY_F11,KEY_F12,
	KEY_F13,KEY_F14,KEY_F15,KEY_F16,KEY_F17,KEY_F18,KEY_F19,KEY_F20,KEY_F21,KEY_F22,KEY_F23,KEY_F24,
	KEY_NUMLOCK,KEY_SCROLL,KEY_LSHIFT,KEY_RSHIFT,KEY_LCONTROL,KEY_RCONTROL,KEY_LMENU,KEY_RMENU,KEY_BROWSER_BACK,
	KEY_BROWSER_FORWARD,KEY_BROWSER_REFRESH,KEY_BROWSER_STOP,KEY_BROWSER_SEARCH,KEY_BROWSER_FAVORITES,
	KEY_BROWSER_HOME,KEY_VOLUME_MUTE,KEY_VOLUME_DOWN,KEY_VOLUME_UP,KEY_MEDIA_NEXT_TRACK,KEY_MEDIA_PREV_TRACK,
	KEY_MEDIA_STOP,KEY_MEDIA_PLAY_PAUSE,KEY_LAUNCH_MAIL,KEY_LAUNCH_MEDIA_SELECT,KEY_LAUNCH_APP1,KEY_LAUNCH_APP2,
	KEY_OEM_1,KEY_OEM_PLUS,KEY_OEM_COMMA,KEY_OEM_MINUS,KEY_OEM_PERIOD,KEY_OEM_2,KEY_OEM_3,KEY_OEM_4,KEY_OEM_5,
	KEY_OEM_6,KEY_OEM_7,KEY_OEM_8,KEY_OEM_102,KEY_PROCESSKEY,KEY_ATTN,KEY_CRSEL,KEY_EXSEL,KEY_EREOF,KEY_PLAY,
	KEY_ZOOM,KEY_NONAME,KEY_PA1,KEY_OEM_CLEAR,
	KEYCOUNT,KEYPADDING=0xFFFFFFFF
};

int keystate(enum keycode_t key);

#define KEY_MODIFIER_RELEASED 0x80000000
enum keycode_t* readkeys();

#ifdef DOS_IMPLEMENTATION

#ifndef NO_MAIN_DEF
	#ifdef main
		#undef main
	#endif
#endif

#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "app.h"
#include "crtemu_pc.h"
#include "frametimer.h"

#ifdef _WIN32
#pragma warning(push)
#pragma warning(disable: 4201)
#endif
#ifdef _WIN32
#pragma warning(pop)
#endif

#ifdef _WIN32
#pragma warning(push)
#pragma warning(disable: 4024)
#pragma warning(disable: 4047)
#pragma warning(disable: 4242)
#pragma warning(disable: 4244)
#pragma warning(disable: 4701)
#endif
#ifdef _WIN32
#pragma warning(pop)
#endif

bool app_has_focus(app_t* app);

#include "thread.h"

static uint32_t default_palette[256] ={
	0x000000,0xaa0000,0x00aa00,0xaaaa00,0x0000aa,0xaa00aa,0x0055aa,0xaaaaaa,0x555555,0xff5555,0x55ff55,0xffff55,0x5555ff,0xff55ff,0x55ffff,0xffffff,0x000000,0x141414,0x202020,0x2c2c2c,0x383838,0x454545,0x515151,0x616161,0x717171,0x828282,0x929292,0xa2a2a2,0xb6b6b6,0xcbcbcb,0xe3e3e3,0xffffff,0xff0000,0xff0041,0xff007d,0xff00be,0xff00ff,0xbe00ff,0x7d00ff,0x4100ff,0x0000ff,0x0041ff,0x007dff,0x00beff,0x00ffff,0x00ffbe,0x00ff7d,0x00ff41,0x00ff00,0x41ff00,0x7dff00,0xbeff00,0xffff00,0xffbe00,0xff7d00,0xff4100,0xff7d7d,0xff7d9e,0xff7dbe,0xff7ddf,0xff7dff,0xdf7dff,0xbe7dff,0x9e7dff,
	0x7f7dff,0x7d9eff,0x7dbeff,0x7ddfff,0x7dffff,0x7dffdf,0x7dffbe,0x7dff9e,0x7dff7d,0x9eff7d,0xbeff7d,0xdfff7d,0xffff7d,0xffdf7d,0xffbe7d,0xff9e7d,0xffb6b6,0xffb6c7,0xffb6db,0xffb6eb,0xffb6ff,0xebb6ff,0xdbb6ff,0xc7b6ff,0xb6b6ff,0xb6c7ff,0xb6dbff,0xb6ebff,0xb6ffff,0xb6ffeb,0xb6ffdb,0xb6ffc7,0xb6ffb6,0xc7ffb6,0xdbffb6,0xebffb6,0xffffb6,0xffebb6,0xffdbb6,0xffc7b6,0x710000,0x71001c,0x710038,0x710055,0x710071,0x550071,0x380071,0x1c0071,0x000071,0x001c71,0x003871,0x005571,0x007171,0x007155,0x007138,0x00711c,0x007100,0x1c7100,0x387100,0x557100,0x717100,0x715500,0x713800,0x711c00,
	0x713838,0x713845,0x713855,0x713861,0x713871,0x613871,0x553871,0x453871,0x383871,0x384571,0x385571,0x386171,0x387171,0x387161,0x387155,0x387145,0x387138,0x457138,0x557138,0x617138,0x717138,0x716138,0x715538,0x714538,0x715151,0x715159,0x715161,0x715169,0x715171,0x695171,0x615171,0x595171,0x515171,0x515971,0x516171,0x516971,0x517171,0x517169,0x517161,0x517159,0x517151,0x597151,0x617151,0x697151,0x717151,0x716951,0x716151,0x715951,0x410000,0x410010,0x410020,0x410030,0x410041,0x300041,0x200041,0x100041,0x000041,0x001041,0x002041,0x003041,0x004141,0x004130,0x004120,0x004110,
	0x004100,0x104100,0x204100,0x304100,0x414100,0x413000,0x412000,0x411000,0x412020,0x412028,0x412030,0x412038,0x412041,0x382041,0x302041,0x282041,0x202041,0x202841,0x203041,0x203841,0x204141,0x204138,0x204130,0x204128,0x204120,0x284120,0x304120,0x384120,0x414120,0x413820,0x413020,0x412820,0x412c2c,0x412c30,0x412c34,0x412c3c,0x412c41,0x3c2c41,0x342c41,0x302c41,0x2c2c41,0x2c3041,0x2c3441,0x2c3c41,0x2c4141,0x2c413c,0x2c4134,0x2c4130,0x2c412c,0x30412c,0x34412c,0x3c412c,0x41412c,0x413c2c,0x41342c,0x41302c,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
};

struct internals_t{
	thread_atomic_int_t exit_flag;
	struct{
		thread_signal_t signal;
		thread_atomic_int_t count;
	} vbl;
	struct{
		int width;
		int height;
		int color;
		bool doublebuffer;
		uint8_t* buffer;
		uint8_t buffer0[1024*1024];
		uint8_t buffer1[1024*1024];
		uint32_t palette[256];
	} screen;
	struct{
		uint8_t* buffer;
		int width;
		int height;
	} draw;
	struct{
		bool keystate[KEYCOUNT];
		enum keycode_t* keybuffer;
		enum keycode_t keybuffer0[256];
		enum keycode_t keybuffer1[256];
		char* charbuffer;
		char charbuffer0[256];
		char charbuffer1[256];
	} input;
}* internals;

static void internals_create(int sound_buffer_size){
	(void)sound_buffer_size;
	internals=(struct internals_t*)malloc(sizeof(struct internals_t));
	memset(internals,0,sizeof(*internals));
	thread_signal_init(&internals->vbl.signal);
	thread_atomic_int_store(&internals->vbl.count,0);
	internals->screen.width=80;
	internals->screen.height=25;
	internals->screen.buffer=internals->screen.buffer0;
	memcpy(internals->screen.palette,default_palette,1024);
	internals->draw.buffer=internals->screen.buffer;
	internals->draw.width=internals->screen.width;
	internals->draw.height=internals->screen.height;
	internals->screen.color=15;
	internals->input.keybuffer=internals->input.keybuffer0;
	internals->input.charbuffer=internals->input.charbuffer0;
}

static void internals_destroy(){
	thread_signal_term(&internals->vbl.signal);
	free(internals);
	internals=NULL;
}

int shuttingdown(){
	return thread_atomic_int_load(&internals->exit_flag);
}

void setvideomode(){
	memcpy(internals->screen.palette,default_palette,1024);
	// videomode_320x200
	internals->screen.width=320;
	internals->screen.height=200;
	internals->draw.buffer=internals->screen.buffer;
	internals->draw.width=internals->screen.width;
	internals->draw.height=internals->screen.height;
};

unsigned char* screenbuffer(){
	return internals->screen.buffer;
}

unsigned char* swapbuffers(){
	if(internals->screen.doublebuffer){
		if(internals->screen.buffer==internals->screen.buffer0){
			if(internals->draw.buffer==internals->screen.buffer){
				internals->draw.buffer=internals->screen.buffer1;
			}
			internals->screen.buffer=internals->screen.buffer1;
		} else{
			if(internals->draw.buffer==internals->screen.buffer){
				internals->draw.buffer=internals->screen.buffer0;
			}
			internals->screen.buffer=internals->screen.buffer0;
		}
	}
	return internals->screen.buffer;
}

void setpal(int index,int r,int g,int b){
	if(index < 0||index >= 256){
		return;
	}
	r=(r & 63)<< 2;
	g=(g & 63)<< 2;
	b=(b & 63)<< 2;
	internals->screen.palette[index]=(b << 16)| (g << 8)| (r);
}

void getpal(int index,int* r,int* g,int* b){
	if(index < 0||index >= 256){
		return;
	}
	uint32_t c=internals->screen.palette[index];
	uint32_t cr=(c)& 0xff;
	uint32_t cg=(c >> 8)& 0xff;
	uint32_t cb=(c >> 16)& 0xff;
	if(r){
		*r=cr >> 2;
	}
	if(g){
		*g=cg >> 2;
	}
	if(b){
		*b=cb >> 2;
	}
}

int getpixel(int x,int y){
	if(x >= 0&&y >= 0&&x < internals->draw.width&&y < internals->draw.height){
		return internals->draw.buffer[x+internals->draw.width*y];
	} else{
		return 0;
	}
}

void putpixel(int x,int y,int color){
	if(x >= 0&&y >= 0&&x < internals->draw.width&&y < internals->draw.height){
		internals->draw.buffer[x+internals->draw.width*y]=(uint8_t)color;
	}
}

void setdrawtarget(unsigned char* pixels,int width,int height){
	internals->draw.buffer=pixels;
	internals->draw.width=width;
	internals->draw.height=height;
}

void setcolor(int color){
	if(color >= 0&&color <= 255){
		internals->screen.color=color;
	}
}

int getcolor(){
	return internals->screen.color;
}

void waitvbl(){
	if(thread_atomic_int_load(&internals->exit_flag)== 0){
		int current_vbl_count=thread_atomic_int_load(&internals->vbl.count);
		while(current_vbl_count==thread_atomic_int_load(&internals->vbl.count)){
			thread_signal_wait(&internals->vbl.signal,1000);
		}
	}
}

static void signalvbl(){
	thread_atomic_int_inc(&internals->vbl.count);
	thread_signal_raise(&internals->vbl.signal);
}

void hline(int x,int y,int len,int color){
	if(y < 0||y >= internals->draw.height){
		return;
	}
	if(x < 0){
		len += x; x=0;
	}
	if(x+len > internals->draw.width){
		len=internals->draw.width-x;
	}
	uint8_t* scr=internals->draw.buffer+y*internals->draw.width+x;
	uint8_t* end=scr+len;
	while(scr < end)*scr++=(uint8_t)color;
}

void line(int x1,int y1,int x2,int y2){
	int color=internals->screen.color;
	int dx=x2-x1;
	dx=dx < 0 ? -dx : dx;
	int sx=x1 < x2 ? 1 : -1;
	int dy=y2-y1;
	dy=dy < 0 ? -dy : dy;
	int sy=y1 < y2 ? 1 : -1;
	int err=(dx > dy ? dx : -dy)/ 2;
	int x=x1;
	int y=y1;
	while(x != x2||y != y2){
		putpixel(x,y,color);
		int e2=err;
		if(e2 > -dx){
			err -= dy;
			x += sx;
		}
		if(e2 < dy){
			err += dx;
			y += sy;
		}
	}
	putpixel(x,y,color);
}

void rectangle(int x,int y,int w,int h){
	int color=internals->screen.color;
	hline(x,y,w,color);
	hline(x,y+h,w,color);
	line(x,y,x,y+h);
	line(x+w-1,y,x+w-1,y+h);
}

void bar(int x,int y,int w,int h){
	int color=internals->screen.color;
	for(int i=y; i < y+h; ++i){
		hline(x,i,w,color);
	}
}

void circle(int x,int y,int r){
	int color=internals->screen.color;
	int f=1-r;
	int dx=0;
	int dy=-2*r;
	int ix=0;
	int iy=r;
	putpixel(x,y+r,color);
	putpixel(x,y-r,color);
	putpixel(x+r,y,color);
	putpixel(x-r,y,color);
	while(ix < iy){
		if(f >= 0){
			--iy;
			dy += 2;
			f += dy;
		}
		++ix;
		dx += 2;
		f += dx+1;
		putpixel(x+ix,y+iy,color);
		putpixel(x-ix,y+iy,color);
		putpixel(x+ix,y-iy,color);
		putpixel(x-ix,y-iy,color);
		putpixel(x+iy,y+ix,color);
		putpixel(x-iy,y+ix,color);
		putpixel(x+iy,y-ix,color);
		putpixel(x-iy,y-ix,color);
	}
}

void fillcircle(int x,int y,int r){
	int color=internals->screen.color;
	int f=1-r;
	int dx=0;
	int dy=-2*r;
	int ix=0;
	int iy=r;
	while(ix <= iy){
		hline(x-iy,y+ix,2*iy,color);
		hline(x-iy,y-ix,2*iy,color);
		if(f >= 0){
			hline(x-ix,y+iy,2*ix,color);
			hline(x-ix,y-iy,2*ix,color);
			--iy;
			dy += 2;
			f += dy;
		}
		++ix;
		dx += 2;
		f += dx+1;
	}
}


void ellipse(int x,int y,int rx,int ry){
	int color=internals->screen.color;
	int asq=rx*rx;
	int bsq=ry*ry;
	putpixel(x,y+ry,color);
	putpixel(x,y-ry,color);
	int wx=0;
	int wy=ry;
	int xa=0;
	int ya=asq*2*ry;
	int thresh=asq/4-asq*ry;
	for(; ;){
		thresh += xa+bsq;
		if(thresh >= 0){
			ya -= asq*2;
			thresh -= ya;
			--wy;
		}
		xa += bsq*2;
		++wx;
		if(xa >= ya){
			break;
		}
		putpixel(x+wx,y-wy,color);
		putpixel(x-wx,y-wy,color);
		putpixel(x+wx,y+wy,color);
		putpixel(x-wx,y+wy,color);
	}
	putpixel(x+rx,y,color);
	putpixel(x-rx,y,color);
	wx=rx;
	wy=0;
	xa=bsq*2*rx;
	ya=0;
	thresh=bsq/4-bsq*rx;
	for(; ;){
		thresh += ya+asq;
		if(thresh >= 0){
			xa -= bsq*2;
			thresh=thresh-xa;
			--wx;
		}
		ya += asq*2;
		++wy;
		if(ya > xa){
			break;
		}
		putpixel(x+wx,y-wy,color);
		putpixel(x-wx,y-wy,color);
		putpixel(x+wx,y+wy,color);
		putpixel(x-wx,y+wy,color);
	}
}


void fillellipse(int x,int y,int rx,int ry){
	int color=internals->screen.color;
	int asq=rx*rx;
	int bsq=ry*ry;
	int wx=0;
	int wy=ry;
	int xa=0;
	int ya=asq*2*ry;
	int thresh=asq/4-asq*ry;
	for(; ;){
		thresh += xa+bsq;
		if(thresh >= 0){
			ya -= asq*2;
			thresh -= ya;
			hline(x-wx,y-wy,wx*2,color);
			hline(x-wx,y+wy,wx*2,color);
			--wy;
		}
		xa += bsq*2;
		++wx;
		if(xa >= ya){
			break;
		}
	}
	hline(x-rx,y,rx*2,color);
	wx=rx;
	wy=0;
	xa=bsq*2*rx;
	ya=0;
	thresh=bsq/4-bsq*rx;
	for(; ;){
		thresh += ya+asq;
		if(thresh >= 0){
			xa -= bsq*2;
			thresh=thresh-xa;
			--wx;
		}
		ya += asq*2;
		++wy;
		if(ya > xa){
			break;
		}
		hline(x-wx,y-wy,wx*2,color);
		hline(x-wx,y+wy,wx*2,color);
	}
}

void drawpoly(int* points_xy,int count){
	for(int i=0; i < count-1; ++i){
		line(points_xy[i*2+0],points_xy[i*2+1],
			points_xy[(i+1)* 2+0],points_xy[(i+1)* 2+1]);
	}
}

void fillpoly(int* points_xy,int count){
	#define MAX_POLYGON_POINTS 256
	static int node_x[MAX_POLYGON_POINTS];

	if(count <= 0||count > MAX_POLYGON_POINTS){
		return;
	}
	int color=internals->screen.color;
	int min_y=points_xy[0+1];
	int max_y=min_y;
	// find extents
	for(int i=1; i < count; ++i){
		if(points_xy[i*2+1] < min_y)min_y=points_xy[i*2+1];
		if(points_xy[i*2+1] > max_y)max_y=points_xy[i*2+1];
	}
	for(int y=min_y; y < max_y; ++y){
		// find intersection points_xy
		int nodes=0;
		int j=count-1;
		for(int i=0; i < count; ++i){
			if((points_xy[i*2+1] <= y&&points_xy[j*2+1] > y)||
				(points_xy[j*2+1] <= y&&points_xy[i*2+1] > y)){

				int dx=points_xy[j*2+0]-points_xy[i*2+0];
				int dy=points_xy[j*2+1]-points_xy[i*2+1];
				node_x[nodes++]=points_xy[i*2+0]+((y-points_xy[i*2+1])* dx)/ dy ;
			}
			j=i;
		}
		// sort by x
		int xi=0;
		while(xi < nodes-1){
			if(node_x[xi] > node_x[xi+1]){
				int swap=node_x[xi];
				node_x[xi]=node_x[xi+1];
				node_x[xi+1]=swap;
				if(xi)--xi;
			} else{
				++xi;
			}
		}
		for(int i=0; i < nodes; i += 2){
			hline(node_x[i],y,node_x[i+1]-node_x[i],color);
		}
	}
}

void floodfill(int x,int y){
	#define FILLMAX 10000		/* FILLMAX depth of stack */
	#define FILLPUSH(Y,XL,XR,DY)	/* FILLPUSH new segment on stack */ \
		if(sp < stack+FILLMAX&&Y+(DY)>= 0&&Y+(DY)< internals->draw.height)\
			{ sp->y=Y; sp->xl=XL; sp->xr=XR; sp->dy=DY; ++sp; }
	#define FILLPOP(Y,XL,XR,DY)	/* FILLPOP segment off stack */ \
		{ --sp; Y=sp->y+(DY=sp->dy); XL=sp->xl; XR=sp->xr; }
	int color=internals->screen.color;
	/*
	* Filled horizontal segment of scanline y for xl<=x<=xr.
	* Parent segment was on line y-dy. dy=1 or -1
	*/
	struct segment_t{ int y,xl,xr,dy; };
	int l,x1,x2,dy;
	int ov;	/* old pixel value */
	struct segment_t stack[FILLMAX],*sp=stack;	/* stack of filled segments */
	ov=getpixel(x,y);		/* read pv at seed point */
	if(ov==color||x < 0||x >= internals->draw.width||y < 0||y >= internals->draw.height)return;
	FILLPUSH(y,x,x,1);			/* needed in some cases */
	FILLPUSH(y+1,x,x,-1);		/* seed segment (FILLPOPped 1st)*/
	while(sp > stack){
		/* FILLPOP segment off stack and fill a neighboring scan line */
		FILLPOP(y,x1,x2,dy);
		/*
		* segment of scan line y-dy for x1<=x<=x2 was previously filled,
		* now explore adjacent pixels in scan line y
		*/
		int xs;
		for(x=x1; x >= 0&&getpixel(x,y)== ov; --x)/* nothing */;
		hline(x+1,y,x1-x,color);
		if(x >= x1)goto skip;
		l=x+1;
		if(l < x1)FILLPUSH(y,l,x1-1,-dy);		/* leak on left? */
		x=x1+1;
		do{
			xs=x;
			for(; x < internals->draw.width&&getpixel(x,y)== ov; ++x)/* nothing */;
			hline(xs,y,x-xs,color);
			FILLPUSH(y,l,x-1,dy);
			if(x > x2+1)FILLPUSH(y,x2+1,x-1,-dy);	/* leak on right? */
		skip:
			for(x++; x <= x2&&getpixel(x,y)!= ov; ++x);
			l=x;
		} while(x <= x2);
	}
	#undef FILLMAX
}

void boundaryfill(int x,int y,int boundary){
	#define FILLMAX 10000		/* FILLMAX depth of stack */
	#define FILLPUSH(Y,XL,XR,DY)	/* FILLPUSH new segment on stack */ \
		if(sp < stack+FILLMAX&&Y+(DY)>= 0&&Y+(DY)< internals->draw.height)\
			{ sp->y=Y; sp->xl=XL; sp->xr=XR; sp->dy=DY; ++sp; }
	#define FILLPOP(Y,XL,XR,DY)	/* FILLPOP segment off stack */ \
		{ --sp; Y=sp->y+(DY=sp->dy); XL=sp->xl; XR=sp->xr; }
	int color=internals->screen.color;
	/*
	* Filled horizontal segment of scanline y for xl<=x<=xr.
	* Parent segment was on line y-dy. dy=1 or -1
	*/
	struct segment_t{ int y,xl,xr,dy; };
	int l,x1,x2,dy;
	int ov;	/* old pixel value */
	struct segment_t stack[FILLMAX],*sp=stack;	/* stack of filled segments */
	ov=boundary;
	if(x < 0||x >= internals->draw.width||y < 0||y >= internals->draw.height)return;
	FILLPUSH(y,x,x,1);			/* needed in some cases */
	FILLPUSH(y+1,x,x,-1);		/* seed segment (FILLPOPped 1st)*/
	while(sp > stack){
		/* FILLPOP segment off stack and fill a neighboring scan line */
		FILLPOP(y,x1,x2,dy);
		/*
		* segment of scan line y-dy for x1<=x<=x2 was previously filled,
		* now explore adjacent pixels in scan line y
		*/
		int xs;
		for(x=x1; x >= 0&&getpixel(x,y)!= ov; --x)/* nothing */;
		hline(x+1,y,x1-x,color);
		if(x >= x1)goto skip;
		l=x+1;
		if(l < x1)FILLPUSH(y,l,x1-1,-dy);		/* leak on left? */
		x=x1+1;
		do{
			xs=x;
			for(; x < internals->draw.width&&getpixel(x,y)!= ov; ++x)/* nothing */;
			hline(xs,y,x-xs,color);
			FILLPUSH(y,l,x-1,dy);
			if(x > x2+1)FILLPUSH(y,x2+1,x-1,-dy);	/* leak on right? */
		skip:
			for(x++; x <= x2&&getpixel(x,y)== ov; ++x);
			l=x;
		} while(x <= x2);
	}
	#undef FILLMAX
}

void traco1(int x,int y){line(x+1,y+0,x+3,y+0);}
void traco2(int x,int y){line(x+1,y+4,x+3,y+4);}
void traco3(int x,int y){line(x+1,y+8,x+3,y+8);}
void traco4(int x,int y){line(x+0,y+1,x+0,y+3);}
void traco5(int x,int y){line(x+4,y+1,x+4,y+3);}
void traco6(int x,int y){line(x+0,y+5,x+0,y+7);}
void traco7(int x,int y){line(x+4,y+5,x+4,y+7);}

void algarismo(int n,int x,int y){
	if(n==0){traco1(x,y);traco3(x,y);traco4(x,y);traco5(x,y);traco6(x,y);traco7(x,y);}
	if(n==1){traco5(x,y);traco7(x,y);}
	if(n==2){traco1(x,y);traco2(x,y);traco3(x,y);traco5(x,y);traco6(x,y);}
	if(n==3){traco1(x,y);traco2(x,y);traco3(x,y);traco5(x,y);traco7(x,y);}
	if(n==4){traco2(x,y);traco4(x,y);traco5(x,y);traco7(x,y);}
	if(n==5){traco1(x,y);traco2(x,y);traco3(x,y);traco4(x,y);traco7(x,y);}
	if(n==6){traco1(x,y);traco2(x,y);traco3(x,y);traco4(x,y);traco6(x,y);traco7(x,y);}
	if(n==7){traco1(x,y);traco5(x,y);traco7(x,y);}
	if(n==8){traco1(x,y);traco2(x,y);traco3(x,y);traco4(x,y);traco5(x,y);traco6(x,y);traco7(x,y);}
	if(n==9){traco1(x,y);traco2(x,y);traco3(x,y);traco4(x,y);traco5(x,y);traco7(x,y);}
}

void blitInt(int n,int x,int y){
	int base,padding=0;
	if(n<0){
		line(x+1,y+4,x+2,y+4);
		n=n*-1;
	}
	for(base=10;n>=base;base=base*10);
	while(base>9){
		algarismo((n%base)/(base/10),x+(padding++*7),y);
		base=base/10;
	}
}

int keystate(enum keycode_t key){
	int index=(int)key;
	if(index >= 0&&index < KEYCOUNT){
		return internals->input.keystate[index];
	}
	return false;
}

enum keycode_t* readkeys(){
	memset(internals->input.keybuffer,0,sizeof(internals->input.keybuffer0));
	if(internals->input.keybuffer==internals->input.keybuffer0){
		internals->input.keybuffer=internals->input.keybuffer1;
	} else{
		internals->input.keybuffer=internals->input.keybuffer0;
	}
	return internals->input.keybuffer;
};

struct app_context_t{
	int argc;
	char** argv;
};

struct user_thread_context_t{
	struct app_context_t* app_context;
	int sound_buffer_size;
	thread_signal_t user_thread_initialized;
	thread_atomic_int_t user_thread_finished;
	thread_signal_t app_loop_finished;
	thread_signal_t user_thread_terminated;
};

int dosmain(int argc,char* argv[]);

static int user_thread_proc(void* user_data){
	struct user_thread_context_t* context=(struct user_thread_context_t*)user_data;

	internals_create(context->sound_buffer_size);
	thread_signal_raise(&context->user_thread_initialized);
	waitvbl();
	int result=dosmain(context->app_context->argc,context->app_context->argv);
	thread_atomic_int_store(&context->user_thread_finished,1);
	thread_signal_wait(&context->app_loop_finished,5000);
	internals_destroy();
	thread_signal_raise(&context->user_thread_terminated);
	return result;
}

static int app_proc(app_t* app,void* user_data){
	struct app_context_t* app_context=(struct app_context_t*)user_data;

	app_title(app,app_filename(app));
	bool fullscreen=true;

	int modargc=0;
	char* modargv[256];
	for(int i=0; i < app_context->argc; ++i){
		if(strcmp(app_context->argv[i],"--window")== 0){
			fullscreen=false;
		}
		else if(strcmp(app_context->argv[i],"-w")== 0){
			fullscreen=false;
		} else{
			if(modargc >= sizeof(modargv)/ sizeof(*modargv)){
				break;
			}
			modargv[modargc++]=app_context->argv[i];
		}
	}
	app_context->argc=modargc;
	app_context->argv=modargv;
	int pointer_width=0;
	int pointer_height=0;
	int pointer_hotspot_x=0;
	int pointer_hotspot_y=0;
	static APP_U32 pointer_pixels[256*256];
	app_pointer_default(app,&pointer_width,&pointer_height,pointer_pixels,&pointer_hotspot_x,&pointer_hotspot_y);
	app_screenmode(app,fullscreen ? APP_SCREENMODE_FULLSCREEN : APP_SCREENMODE_WINDOW);
	#ifdef DISABLE_SYSTEM_CURSOR
		APP_U32 blank=0;
		app_pointer(app,1,1,&blank,0,0);
	#else
		if(fullscreen){
			APP_U32 blank=0;
			app_pointer(app,1,1,&blank,0,0);
		} else{
			app_pointer(app,pointer_width,pointer_height,pointer_pixels,pointer_hotspot_x,pointer_hotspot_y);
		}
	#endif
	app_displays_t displays=app_displays(app);
	if(displays.count > 0){
		int disp=0;
		for(int i=0; i < displays.count; ++i){
			if(displays.displays[i].x==0&&displays.displays[i].y==0){
				disp=i;
				break;
			}
		}
		int scrwidth=displays.displays[disp].width-80;
		int scrheight=displays.displays[disp].height-80;
		int aspect_width=(int)((scrheight*4.25f)/ 3);
		int aspect_height=(int)((scrwidth*3)/ 4.25f);
		int target_width,target_height;
		if(aspect_height <= scrheight){
			target_width=scrwidth;
			target_height=aspect_height;
		} else{
			target_width=aspect_width;
			target_height=scrheight;
		}

		int x=displays.displays[disp].x+(displays.displays[disp].width-target_width)/ 2;
		int y=displays.displays[disp].y+(displays.displays[disp].height-target_height)/ 2;
		int w=target_width;
		int h=target_height;
		app_window_pos(app,x,y);
		app_window_size(app,w,h);
	}
	struct user_thread_context_t user_thread_context;
	user_thread_context.app_context=app_context;
	thread_signal_init(&user_thread_context.user_thread_initialized);
	thread_atomic_int_store(&user_thread_context.user_thread_finished,0);
	thread_signal_init(&user_thread_context.app_loop_finished);
	thread_signal_init(&user_thread_context.user_thread_terminated);
	thread_ptr_t user_thread=thread_create(user_thread_proc,&user_thread_context,
		THREAD_STACK_SIZE_DEFAULT);
	if(!thread_signal_wait(&user_thread_context.user_thread_initialized,5000)){
		thread_signal_term(&user_thread_context.user_thread_initialized);
		thread_signal_term(&user_thread_context.app_loop_finished);
		thread_signal_term(&user_thread_context.user_thread_terminated);
		return EXIT_FAILURE;
	}
	#ifdef NULL_PLATFORM
		crtemu_pc_t* crt=NULL;
	#else
		crtemu_pc_t* crt=crtemu_pc_create(NULL);
	#endif
	// Create the frametimer instance,and set it to fixed 60hz update. This will ensure we never run faster than that,
	// even if the user have disabled vsync in their graphics card settings.
	frametimer_t* frametimer=frametimer_create(NULL);
	frametimer_lock_rate(frametimer,60);
	signalvbl();
	// Main loop
	static APP_U32 screen_xbgr[sizeof(internals->screen.buffer0)];
	int width=0;
	int height=0;
	int curs_vis=0;
	int curs_x=0;
	int curs_y=0;
	bool keystate[KEYCOUNT] ={ 0 };
	enum keycode_t keys[256] ={ (enum keycode_t)0 };
	char chars[256] ={ 0 };
	APP_U64 crt_time_us=0;
	APP_U64 prev_time=app_time_count(app);
	while(!thread_atomic_int_load(&user_thread_context.user_thread_finished)){
		app_state_t app_state=app_yield(app);
		frametimer_update(frametimer);
		int keys_index=0;
		memset(keys,0,sizeof(keys));
		int chars_index=0;
		memset(chars,0,sizeof(chars));
		float relx=0;
		float rely=0;
		app_input_t input=app_input(app);
		for(int i=0; i < input.count; ++i){
			app_input_event_t* event=&input.events[i];
			if(event->type==APP_INPUT_KEY_DOWN){
				int index=(int)event->data.key;
				if(index > 0&&index < KEYCOUNT){
					keystate[index]=true;
					if(keys_index < 255){
						keys[keys_index++]=(enum keycode_t)event->data.key;
					}
				}
				if(event->data.key==APP_KEY_F11){
					fullscreen=!fullscreen;
					app_screenmode(app,fullscreen ? APP_SCREENMODE_FULLSCREEN : APP_SCREENMODE_WINDOW);
					#ifdef DISABLE_SYSTEM_CURSOR
						APP_U32 blank=0;
						app_pointer(app,1,1,&blank,0,0);
					#else
						if(fullscreen){
							APP_U32 blank=0;
							app_pointer(app,1,1,&blank,0,0);
						} else{
							app_pointer(app,pointer_width,pointer_height,pointer_pixels,pointer_hotspot_x,pointer_hotspot_y);
						}
					#endif
				}
			} else if(event->type==APP_INPUT_KEY_UP){
				int index=(int)event->data.key;
				if(index >= 0&&index < KEYCOUNT){
					keystate[index]=false;
					if(keys_index < 255){
						keys[keys_index++]=(enum keycode_t)(((uint32_t)event->data.key)| KEY_MODIFIER_RELEASED);
					}
				}
			} else if(event->type==APP_INPUT_CHAR){
				if(event->data.char_code > 0){
					if(chars_index < 255){
						chars[chars_index++]=event->data.char_code;
					}
				}
			}
		}
		// Check if the close button on the window was clicked (or Alt+F4 was pressed)
		if(app_state==APP_STATE_EXIT_REQUESTED){
			// Signal that we need to force the user thread to exit
			thread_atomic_int_store(&internals->exit_flag,1);
			signalvbl();
			break;
		}
		// Copy data from user thread
		width=internals->screen.width;
		height=internals->screen.height;
		uint8_t* internals_screen=internals->screen.buffer;
		if(internals->screen.doublebuffer){
			if(internals->screen.buffer==internals->screen.buffer0){
				internals_screen=internals->screen.buffer1;
			} else{
				internals_screen=internals->screen.buffer0;
			}
		}
		static uint8_t screen[sizeof(internals->screen.buffer0)];
		memcpy(screen,internals_screen,width*height);
		static uint32_t palette[256];
		memcpy(palette,internals->screen.palette,1024);
		memcpy(internals->input.keystate,keystate,sizeof(internals->input.keystate));
		enum keycode_t* internals_keybuffer;
		if(internals->input.keybuffer==internals->input.keybuffer0){
			internals_keybuffer=internals->input.keybuffer1;
		} else{
			internals_keybuffer=internals->input.keybuffer0;
		}
		enum keycode_t* keyin=keys;
		enum keycode_t* keyout=internals_keybuffer;
		enum keycode_t* keyend=internals_keybuffer+sizeof(internals->input.keybuffer0)/ sizeof(*internals->input.keybuffer0)- 1;
		while(*keyout&&keyout < keyend){
			++keyout;
		}
		while(*keyin){
			if(keyout >= keyend){
				memmove(internals_keybuffer+1,internals_keybuffer,sizeof(internals->input.keybuffer0)/ sizeof(*internals->input.keybuffer0)- 1);
				--keyout;
			}
			*keyout++=*keyin++;
		}
		*keyout=KEY_INVALID;
		char* internals_charbuffer;
		if(internals->input.charbuffer==internals->input.charbuffer0){
			internals_charbuffer=internals->input.charbuffer1;
		} else{
			internals_charbuffer=internals->input.charbuffer0;
		}
		char* charin=chars;
		char* charout=internals_charbuffer;
		char* charend=internals_charbuffer+sizeof(internals->input.charbuffer0)/ sizeof(*internals->input.charbuffer0)- 1;
		while(*charout&&charout < charend){
			++charout;
		}
		while(*charin){
			if(charout >= charend){
				memmove(internals_charbuffer+1,internals_charbuffer,sizeof(internals->input.charbuffer0)/ sizeof(*internals->input.charbuffer0)- 1);
				--charout;
			}
			*charout++=*charin++;
		}
		*charout='\0';
		// Signal to the game that the frame is completed,and that we are just starting the next one
		signalvbl();

		for(int y=0; y < height; ++y){
			for(int x=0; x < width; ++x){
				screen_xbgr[x+y*width]=palette[screen[x+y*width]];
			}
		}
		if(!app_has_focus(app)){
			continue;
		}
		APP_U64 time=app_time_count(app);
		APP_U64 freq=app_time_freq(app);
		APP_U64 delta_time_us=(time-prev_time)/ ((freq > 1000000 ? freq/1000000 : 1));
		prev_time=time;
		crt_time_us += delta_time_us;
		if(crt){
			#ifndef DISABLE_SCREEN_FRAME
				crtemu_pc_present(crt,crt_time_us,screen_xbgr,width,height,0xffffff,0xff1a1a1a);
			#else
				crtemu_pc_present(crt,crt_time_us,screen_xbgr,width,height,0xffffff,0xff000000);
			#endif
		}
		app_present(app,NULL,1,1,0xffffff,0xff1a1a1a);
	}
	thread_signal_raise(&user_thread_context.app_loop_finished);
	int user_exit=thread_signal_wait(&user_thread_context.user_thread_terminated,170);
	if(!user_exit){
		for(int i=0; i < 60; ++i){
			APP_U64 time=app_time_count(app);
			APP_U64 delta_time_us=(time-prev_time)/ (app_time_freq(app)/ 1000000);
			prev_time=time;
			crt_time_us += delta_time_us;
			int v=((60-i)* 255)/ 60;
			uint32_t fade=(v << 16)| v << 8 | v;
			if(crt){
				crtemu_pc_present(crt,crt_time_us,screen_xbgr,width,height,fade,0xff1a1a1a);
			}
			app_present(app,NULL,1,1,0xffffff,0xff1a1a1a);
			frametimer_update(frametimer);
		}
		user_exit=thread_signal_wait(&user_thread_context.user_thread_terminated,30);
		if(!user_exit){
			exit(EXIT_FAILURE);
		}
	}
	thread_signal_term(&user_thread_context.user_thread_initialized);
	thread_signal_term(&user_thread_context.app_loop_finished);
	thread_signal_term(&user_thread_context.user_thread_terminated);
	frametimer_destroy(frametimer);
	if(crt){
		crtemu_pc_destroy(crt);
	}
	return thread_join(user_thread);
}

#define APP_IMPLEMENTATION
#ifdef NULL_PLATFORM
	#define APP_NULL
#elif defined(_WIN32)
	#define APP_WINDOWS
#else
	#define APP_SDL
#endif
#define APP_LOG(ctx,level,message)
#include "app.h"

#define CRTEMU_PC_IMPLEMENTATION
#include "crtemu_pc.h"

#define FRAMETIMER_IMPLEMENTATION
#include "frametimer.h"

#define THREAD_IMPLEMENTATION
#include "thread.h"

#define TSF_IMPLEMENTATION
#define TSF_POW	pow
#define TSF_POWF	(float)pow
#define TSF_EXPF	(float)exp
#define TSF_LOG	log
#define TSF_TAN	tan
#define TSF_LOG10 log10
#define TSF_SQRT (float)sqrt
#define TSF_SQRTF (float)sqrt
#include <math.h>

#define TML_IMPLEMENTATION
#ifdef _WIN32
#pragma warning(push)
#pragma warning(disable: 4201)
#endif
#ifdef _WIN32
#pragma warning(pop)
#endif

bool app_has_focus(app_t* app){
	#ifdef ALWAYS_UPDATE
		return true;
	#else
		#ifndef NULL_PLATFORM
			return app->has_focus;
		#else
			return true;
		#endif
	#endif
}

#include <inttypes.h>

int main(int argc,char** argv){
	(void)argc,(void)argv;
	struct app_context_t app_context;
	app_context.argc=argc;
	app_context.argv=argv;
	return app_run(app_proc,&app_context,NULL,NULL,NULL);
}

#ifdef _WIN32
	// pass-through so the program will build with either /SUBSYSTEM:WINDOWS or /SUBSYSTEM:CONSOLE
	int WINAPI __stdcall WinMain(HINSTANCE a,HINSTANCE b,char* c,int d){
		(void)a,b,c,d;
		return main(__argc,__argv);
	}
#endif

#endif /* DOS_IMPLEMENTATION */

#ifndef NO_MAIN_DEF
	#define main dosmain
#endif
