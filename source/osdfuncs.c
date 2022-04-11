#include "duke3d.h"
#include "build.h"
#include "names.h"

void GAME_drawosdchar(int x, int y, char ch, int shade, int pal)
{
	short ac;

	if (ch == 32) return;
	ac = ch-'!'+STARTALPHANUM;
	if (ac < STARTALPHANUM || ac > ENDALPHANUM) return;

	rotatesprite(((x<<3)+x)<<16, (y<<3)<<16, 65536l, 0, ac, shade, pal, 8|16, 0, 0, xdim-1, ydim-1);
}

void GAME_drawosdstr(int x, int y, char *ch, int len, int shade, int pal)
{
	short ac;

	for (x = (x<<3)+x; len>0; len--, ch++, x++) {
		if (*ch == 32) { x+=5; continue; }
		ac = *ch-'!'+STARTALPHANUM;
		if (ac < STARTALPHANUM || ac > ENDALPHANUM) return;

		rotatesprite(x<<16, (y<<3)<<16, 65536l, 0, ac, shade, pal, 8|16, 0, 0, xdim-1, ydim-1);
		if (*ch >= '0' && *ch <= '9') x+=8;
		else x += tilesizx[ac];
	}
}

void GAME_drawosdcursor(int x, int y, int type, int lastkeypress)
{
	short ac;

	if (type) ac = SMALLFNTCURSOR;
	else ac = '_'-'!'+STARTALPHANUM;

	if (!((GetTime()-lastkeypress) & 0x40l)) 
		rotatesprite(((x<<3)+x)<<16, ((y<<3)+(type?-1:2))<<16, 65536l, 0, ac, 0, 8, 8|16, 0, 0, xdim-1, ydim-1);
}

int GAME_getcolumnwidth(int w)
{
	return w/9;
}

int GAME_getrowheight(int w)
{
	return w>>3;
}

void GAME_onshowosd(int shown)
{
	if (numplayers == 1)
		if ((shown && !ud.pause_on) || (!shown && ud.pause_on))
			KB_KeyDown[sc_Pause] = 1;
}

//#define BGTILE 311
//#define BGTILE 1156
#define BGTILE 1141	// BIGHOLE
#define BORDTILE 3250	// VIEWBORDER
#define BITSTH 1+32+8+16	// high translucency
#define BITSTL 1+8+16	// low translucency
#define BITS 8+16+64		// solid
#define SHADE 16
#define PALETTE 0
void GAME_clearbackground(int c, int r)
{
	long x, y, xsiz, ysiz, tx2, ty2;
	long daydim, bits;

	if (getrendermode() < 3) bits = BITS; else bits = BITSTL;
	
	daydim = r<<3;

	xsiz = tilesizx[BGTILE]; tx2 = xdim/xsiz;
	ysiz = tilesizy[BGTILE]; ty2 = daydim/ysiz;

	for(x=0;x<=tx2;x++)
		for(y=0;y<=ty2;y++)
			rotatesprite(x*xsiz<<16,y*ysiz<<16,65536L,0,BGTILE,SHADE,PALETTE,bits,0,0,xdim,daydim);

	xsiz = tilesizy[BORDTILE]; tx2 = xdim/xsiz;
	ysiz = tilesizx[BORDTILE];
	
	for(x=0;x<=tx2;x++)
		rotatesprite(x*xsiz<<16,(daydim+ysiz+1)<<16,65536L,1536,BORDTILE,SHADE-12,PALETTE,BITS,0,0,xdim,daydim+ysiz+1);
}	

