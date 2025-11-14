/*
============================================================
  Fichero: movil.c
  Creado: 13-11-2025
  Ultima Modificacion: dijous, 13 de novembre de 2025, 20:43:25
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "starwars.h"

Movil movil[MOVILES];
int moviles=0;

Movil* movil_new() {
	if(moviles<MOVILES) {
		return movil+moviles++;
	}
	return NULL;
}

void movil_set_velocidad(Movil* m,double vx,double vy) {
	if(vx!=0.0 || vy!=0.0) {
		double mv=sqrt(pow(vx,2)+pow(vy,2));
		vx=vx/mv;
		vy=vy/mv;
	}
	m->vx=vx;
	m->vy=vy;
}	

void movil_mueve(Movil* m) {
	if(m->delay>=m->delay_maxim) {
		m->x+=vx;
		m->y+=vy;
		m->delay=0;
	} else m->delay++;
}
