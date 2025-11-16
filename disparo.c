/*
============================================================
  Fichero: disparo.c
  Creado: 14-11-2025
  Ultima Modificacion: dissabte, 15 de novembre de 2025, 19:44:35
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "starwars.h"

void dispara(int x,int y,int vy) {
	const int DISNAV=1;
	const int DISENE=2;
	Movil* m=movil_new(DISPARO);
	if(m) {
		m->delay_maxim=(vy==1)?DISENE:DISNAV;
		m->x=x;
		m->y=y;
		m->vx=0;
		m->vy=vy;
		m->sprite=sdisparo;
		m->w=1;
		m->h=5;
	}
}

