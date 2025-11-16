/*
============================================================
  Fichero: enemigo.c
  Creado: 15-11-2025
  Ultima Modificacion: diumenge, 16 de novembre de 2025, 09:23:12
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "starwars.h"

int enemigos=0;
int wave=0;

static void enemigo_pos(Movil* e) {
	int x=0;
	int vx=(rnd(0,1))?1:-1;
	if(vx==1) x=-rnd(1,5)*2*e->w;
	else x=SCRWP+rnd(1,5)*2*e->w;
	int y=rnd(0,SCRHP/2);
	e->x=x;
	e->y=y;
	e->vx=vx;
}

static int ovni_nuevo() {
	const int DEL=5;//delay
	const int SDEL=100;//delay shoot
	Movil* m=movil_new(ENEMIGO);
	if(m) {
		m->sprite=sovni;
		m->delay_maxim=DEL;
		m->w=15;
		m->h=16;
		m->vida=1;
		enemigo_pos(m);
		m->delay_shoot=m->shoot=SDEL;
		return 1;
	}
	return 0;
}

static int squid_nuevo() {
	const int DEL=4;//delay
	const int SDEL=75;//delay shoot
	Movil* m=movil_new(ENEMIGO);
	if(m) {
		m->sprite=ssquid;
		m->delay_maxim=DEL;
		m->w=9;
		m->h=11;
		m->vida=2;
		enemigo_pos(m);
		m->delay_shoot=m->shoot=SDEL;
		return 1;
	}
	return 0;
}

static int devil_nuevo() {
	const int DEL=3;//delay
	const int SDEL=50;//delay shoot
	Movil* m=movil_new(ENEMIGO);
	if(m) {
		m->sprite=sdevil;
		m->delay_maxim=DEL;
		m->w=12;
		m->h=13;
		m->vida=3;
		enemigo_pos(m);
		m->delay_shoot=m->shoot=SDEL;
		return 1;
	}
	return 0;
}

static int fly_nuevo() {
	const int DEL=2;//delay
	const int SDEL=25;//delay shoot
	Movil* m=movil_new(ENEMIGO);
	if(m) {
		m->sprite=sfly;
		m->delay_maxim=DEL;
		m->w=9;
		m->h=10;
		m->vida=3;
		enemigo_pos(m);
		m->delay_shoot=m->shoot=SDEL;
		return 1;
	}
	return 0;
}


static int enemigo_nuevo(int tipo) {
	switch(tipo) {
		case EOVNI:
			return ovni_nuevo();
		case ESQUID:
			return squid_nuevo();
		case EDEVIL:
			return devil_nuevo();
		case EFLY:
			return fly_nuevo();
		default:
			return 0;
	};
}

void wave_new() {
	if(enemigos==0) {
		wave++;
		for(int n=0;n<wave;n++) {
			enemigo_nuevo(rnd(EOVNI,TIPENE));
		}
	}
}

#define ien(M) ((M)->x>=nave->x && (M)->x<(nave->x+nave->w)) //en entorno nave
#define dado rnd(0,999)

void enemigo_action(Movil* m) {
	const int PCDX=5; //probabilidad de cambio de direccion de x
	const int PCDY=5; //probabilidad de cambio de direccion de y
	const int PDAL=1; //probabilidad de disparo aleatorio
	const int PDSJ=50; //probabilidad de disparo si esta encima de jugador
	if(m->y<=0) m->vy=1;
	else if(m->y>=230) m->vy=-1;
	else if(m->x<=0) m->vx=1;
	else if(m->x>=SCRWP-m->w) m->vx=-1;
	else if(ien(m) && dado<PDSJ) movil_dispara(m);
	else {
		int vd=dado;
		if(vd<PCDX) m->vx=rnd(-1,1);
		else if(vd>=PCDX && vd<PCDX+PCDY) m->vy=rnd(-1,1);
		else if(vd>=PCDX+PCDY && vd<PCDX+PCDY+PDAL) movil_dispara(m);
	}
	movil_shoot_delay(m);
}

#undef ien
#undef dado
