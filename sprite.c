/*
============================================================
  Fichero: sprite.c
  Creado: 06-11-2025
  Ultima Modificacion: dissabte, 8 de novembre de 2025, 18:48:37
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "sprite.h"

address z_sprite_new(address dir,byte h,char* data[]) {
	byte w=0;
	byte* ptr=memory+dir;
	for(int j=0;j<h;j++) {
		char* ptd=data[j];
		byte flag=128;
		*ptr=0;
		byte nw=0;
		while(*ptd!='\0' && ptr!=memory+DMEM) {
			nw++;
			if(*ptd!='0') *ptr|=flag;
			flag=flag>>1;
			if(flag==0) {
				flag=128;
				ptr++;
				*ptr=0;
			}
			ptd++;
		}
		ptr++;
		if(w!=0 && w!=nw) return 0;
		else if(w==0) w=nw;
	}
	address newdir=dir+((w/8 +((w%8)?1:0))*h);
	return newdir;
}

#define inscrx (px>=0 && px<SCRWP)
#define inscry (py>=0 && py<SCRHP)

void z_sprite_screen(address dir,byte w,byte h,int x,int y) {
	int q=w/8;
	int r=w%8;
	w=(r>0)?8*(q+1):8*q;
	byte* ptr=memory+dir;
	for(int j=0;j<h;j++) {
		byte flag=128;
		for(int i=0;i<w;i++) {
			int px=x+i;
			int py=y+j;
			if(inscrx && inscry) {
				byte apl=(*ptr & flag)?1:0;
				byte lpl=plotted(px,py);
				byte isplot=apl | lpl;
				if(isplot) plot(px,py);
				else unplot(px,py);
			}
			flag=flag>>1;
			if(flag==0) {
				flag=128;
				ptr++;
			}
		}
	}
}
