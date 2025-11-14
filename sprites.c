/*
============================================================
  Fichero: sprites.c
  Creado: 13-11-2025
  Ultima Modificacion: dijous, 13 de novembre de 2025, 20:18:36
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "starwars.h"

address snave,sproteccion;

static address actdir=ORAM;

static void snave_define() {
	char* datan[]={	"000010000",
					"000111000",
					"000111000",
					"000111000",
					"000101000",
					"000101000",
					"999101000",
					"000111000",
					"001111100",
					"011111110",
					"111000111"
	};
	snave=actdir;
	actdir=sprnew(snave,11,datan);
}

static void sproteccion_define() {
	char* datap[]={	"00001110000",
					"00111111100",
					"01111111110",
					"11111111111",
					"11000000011",
					"10000000001"
	};
	sproteccion=actdir;
	actdir=sprnew(sproteccion,6,datap);
}

void sprites_define() {
	snave_define();
	sproteccion_define();
}


