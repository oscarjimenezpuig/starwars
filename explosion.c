/*
============================================================
  Fichero: explosion.c
  Creado: 13-11-2025
  Ultima Modificacion: divendres, 14 de novembre de 2025, 19:49:57
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "starwars.h"

void explosion(int x,int y) {
	const int PARTICULAS=10; //numero de particulas de la explosion
	const int MAXDEL=5; //maximo delay
	const int MINDEL=1; //minimo delay
	const double ANGULO=2*PI/(double)PARTICULAS; //angulo entre cada particula
	double angini=2*PI/(double)rnd(1,360);
	double angulo=0;
	for(int k=0;k<PARTICULAS;k++) {
		Movil* m=movil_new(PARTICULA);
		if(m) {
			angulo=angini+k*ANGULO;
			m->x=x;
			m->y=y;
			m->vx=cos(angulo);
			m->vy=sin(angulo);
			m->delay_maxim=rnd(MINDEL,MAXDEL);
		}
	}
}
