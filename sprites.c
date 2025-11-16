/*
============================================================
  Fichero: sprites.c
  Creado: 13-11-2025
  Ultima Modificacion: diumenge, 16 de novembre de 2025, 09:20:59
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "starwars.h"

address snave,sproteccion,sdisparo,sovni,ssquid,sdevil,sfly;

static address actdir=ORAM;

static void snave_define() {
	char* datan[]={	"000010000",
					"000111000",
					"000111000",
					"000111000",
					"000101000",
					"000101000",
					"000101000",
					"000111000",
					"001111100",
					"011111110",
					"111000111"
	};
	snave=actdir;
	actdir=sprnew(snave,11,datan);
}

static void sproteccion_define() {
	char* datap[]={	"000000000111000000000",
					"000000011111110000000",
					"000000011111110000000",
					"000001111111111100000",
					"000111111111111111000",
					"011111111111111111110",
					"111111111111111111111",
					"111111111111111111111",
					"111111111000111111111",
					"111111100000001111111",
					"111110000000000011111",
					"111000000000000000111",
					"100000000000000000001",
					"100000000000000000001"
	};
	sproteccion=actdir;
	actdir=sprnew(sproteccion,14,datap);
}

static void sdisparo_define() {
	char* datad[] = {
		"1","1","1","1","1"
	};
	sdisparo=actdir;
	actdir=sprnew(sdisparo,5,datad);
}

static void senemigo_define() {
	char* datao[] = {	"000000111000000",
						"000001000100000",
						"000001000100000",
						"000001000100000",
						"001111111111100",
						"011111111111110",
						"011111111111110",
						"111111111111111",
						"011111111111110",
						"011111111111110",
						"001111111111100",
						"000011111110000",
						"000001000100000",
						"000010000010000",
						"000010000010000",
						"000111000111000"
	};
	sovni=actdir;
	ssquid=sprnew(sovni,16,datao);
	char* datas[] = {	"001111100",
						"011111110",
						"110010011",
						"110010011",
						"111111111",
						"011111110",
						"101111101",
						"100010001",
						"100010001",
						"100010001",
						"010010010"
	};
	sdevil=sprnew(ssquid,11,datas);
	char* datad[] = {	"100000000001",
						"100000000001",
						"101111111101",
						"011111111110",
						"011011110110",
						"011011110110",
						"011111111110",
						"001111111100",
						"000111111000",
						"000110011000",
						"000110011000",
						"000110011000",
						"000011110000"
	};
	sfly=sprnew(sdevil,13,datad);
	char* dataf[]={	"000010000",
					"000010000",
					"011111110",
					"100111001",
					"100010001",
					"011111110",
					"000111000",
					"001010100",
					"010000010",
					"010000010"
	};
	actdir=sprnew(sfly,10,dataf);
}

void sprites_define() {
	snave_define();
	sproteccion_define();
	sdisparo_define();
	senemigo_define();
}

void sprite_unshow(int w,int h,int x,int y) {
	for(int i=x;i<x+w;i++) {
		for(int j=y;j<y+h;j++) {
			unplot(i,j);
		}
	}
}


