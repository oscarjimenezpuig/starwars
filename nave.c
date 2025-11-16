/*
============================================================
  Fichero: nave.c
  Creado: 14-11-2025
  Ultima Modificacion: diumenge, 16 de novembre de 2025, 08:10:10
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "starwars.h"

Movil* nave=NULL;

void nave_define() {
	nave=movil_new(NAVE);
	if(nave) {
		nave->x=125;
		nave->y=240;
		nave->vx=nave->vy=0;
		nave->sprite=snave;
		nave->w=9;
		nave->h=11;
		nave->delay_maxim=NAVDL;
		nave->shoot=nave->delay_shoot=NAVSD;
	}
}

void nave_action() {
	if(inkey('j')) nave->vx=-1;
	else if(inkey('l')) nave->vx=1;
	else nave->vx=0;
	if(inkey('i')) movil_dispara(nave);
	movil_shoot_delay(nave);
}


