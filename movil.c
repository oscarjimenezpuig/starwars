/*
============================================================
  Fichero: movil.c
  Creado: 13-11-2025
  Ultima Modificacion: diumenge, 16 de novembre de 2025, 08:48:01
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "starwars.h"

Movil movil[MOVILES];

static void movil_ci(Movil* m) {
	m->active=0;
	m->x=m->y=m->w=m->h=m->delay=m->delay_maxim=0;
	m->vx=m->vy=0.0;
	m->sprite=0;
	m->type=0;
	m->vida=0;
	m->shoot=0;
}

static void moviles_init() {
	static byte done=0;
	if(!done) {
		Movil* m=movil;
		while(m!=movil+MOVILES) movil_ci(m++);
		done=1;
	}
}

Movil* movil_new(byte t) {
	moviles_init();
	Movil* m=movil;
	while(m!=movil+MOVILES) {
		if(m->active==0) {
			m->active=1;
			m->type=t;
			if(t==ENEMIGO) enemigos++;
			return m;
		}
		m++;
	}
	return NULL;
}

void movil_delete(Movil* m) {
	if(m->type==ENEMIGO) enemigos--;
	movil_unshow(m);
	movil_ci(m);
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

static Movil* movil_find(Movil* c,int fx,int fy) {
	Movil copy;
	copy.x=fx;
	copy.y=fy;
	copy.w=c->w;
	copy.h=c->h;
	Movil* p=movil;
	while(p!=movil+MOVILES) {
		if(c!=p && movil_colision(&copy,p)) return p;
		p++;
	}
	return NULL;
}

void movil_mueve(Movil* m) {
	if(m->delay>=m->delay_maxim) {
		int fx=round(m->x+m->vx);
		int fy=round(m->y+m->vy);
		if(m->type==PARTICULA) {
			byte ip=plotted(fx,fy);
			if(!ip && fx>=0 && fx<SCRWP && fy>=0 && fy<SCRHP) {
				m->x=fx;
				m->y=fy;
			} else {
				movil_delete(m);
			}
		} else if(m->type==DISPARO) {
			Movil* c=movil_find(m,fx,fy);
			if(c && (c->type==PROTECCION || (c->type==ENEMIGO && m->vy==-1) || (c->type==NAVE && m->vy==1))) {
				movil_touched(c);
				movil_delete(m);
			} else if(fy>SCRHP+m->h || fy<-m->h) {
				movil_delete(m);
			}
			if(m->active) {
				m->x=fx;
				m->y=fy;
			}
		} else if(m->type==NAVE) {
			if(fx>=0 && fx<SCRWP-m->w) {
				m->x=fx;
				m->y=fy;
			}
		} else if(m->type==PROTECCION) {
			Movil* c=movil_find(m,fx,fy);
			if(c && c->type!=PROTECCION) {
				movil_touched(c);
			} else {
				m->x=fx;
				m->y=fy;
			}
		} else if(m->type==ENEMIGO) {
			m->x=fx;
			m->y=fy;
		}
		m->delay=0;
	} else if(m->active) m->delay++;
}

void movil_dispara(Movil* m) {
	if(m->shoot>=m->delay_shoot) {
		int x=m->x+(m->w/2);
		int y=m->y+m->h+10;
		int vy=1;
		if(m==nave) {
			vy=-1;
			y=m->y-10;
		}
		m->shoot=0;
		dispara(x,y,vy);
	}
}

void movil_shoot_delay(Movil* m) {
	if(m->shoot<m->delay_shoot) m->shoot++;
}

u1 movil_colision(Movil* a,Movil* b) {
	if(a!=b) {
		int w=(a->x>=b->x)?b->w:a->w;
		int h=(a->y>=b->y)?b->h:a->h;
		int dx=fabs(a->x-b->x);
		int dy=fabs(a->y-b->y);
		if(dx<w && dy<h) return 1;
	}
	return 0;
}

void movil_touched(Movil* m) {
	if(m->vida==1) {
		movil_destroy(m);
	} else {
		m->vida--;
	}
}

void movil_destroy(Movil* m) {
	int x=m->x;
	int y=m->y;
	int w=m->w;
	int h=m->h;
	movil_delete(m);
	explosion(x+w/2,y+h/2);
}

void movil_unshow(Movil* m) {
	if(m->type==PARTICULA) unplot(m->x,m->y);
	else sprite_unshow(m->w,m->h,m->x,m->y); 
}

void movil_show(Movil* m) {
	if(m->active) {
		if(m->type==PARTICULA) {
			plot(m->x,m->y);
		} else {
			sprins(m->sprite,m->w,m->h,m->x,m->y);
		}
	}
}

void movil_master() {
	Movil* p=movil;
	while(p!=movil+MOVILES) {
		if(p->active) {
			if(p->type==NAVE) nave_action();
			else if(p->type==ENEMIGO) enemigo_action(p);
			else if(p->type==PROTECCION) proteccion_action(p);
			//movil_unshow(p);
			movil_mueve(p);
			movil_show(p);
		}
		p++;
	}
}
		
