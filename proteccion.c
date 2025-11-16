/*
============================================================
  Fichero: proteccion.c
  Creado: 15-11-2025
  Ultima Modificacion: diumenge, 16 de novembre de 2025, 08:19:52
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "starwars.h"

static Movil* mproteccion[PROTECCIONES];

void proteccion_define() {
	for(int k=0;k<PROTECCIONES;k++) {
		Movil* m;
		m=mproteccion[k]=movil_new(PROTECCION);
		m->w=PROTSW;
		m->h=PROTSH;
		m->sprite=sproteccion;
		m->x=(PROTE*(k+1)+PROTSW*k);
		m->y=PROTY;
		m->vx=1;
		m->vida=PROTV;
		m->delay_maxim=PROTD;
	}
}

void proteccion_action(Movil* m) {
	if(m->x==0) m->vx=1;
	else if(m->x+m->w>=SCRWP) m->vx=-1;
}

