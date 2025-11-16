/*
============================================================
  Fichero: starwars.h
  Creado: 13-11-2025
  Ultima Modificacion: diumenge, 16 de novembre de 2025, 09:20:59
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#ifndef STARWARS_H
#define STARWARS_H

#include <stdio.h>
#include <math.h>

#include "sprite.h"

//CONSTANTES
#define PI 3.141592653589 //numero pi

#define MOVILES 500 //numero de moviles maximo
					
//nave
#define NAVDL 2 //delay de la nave
#define NAVSD 50 //shoot delay de la nave


#define PROTECCIONES 3 //numero de protecciones totales
#define PROTY 210 //coordenada y de las protecciones
#define PROTV 15 //numero de vidas de cada proteccion
#define PROTSW 21 //anchura del sprite de proteccion
#define PROTSH 14 //altura del sprite de proteccion
#define PROTE ((SCRWP-(PROTECCIONES*PROTSW))/(PROTECCIONES+1)) //espacio entre protecciones
#define PROTD 10 //maximo delay de la proteccion

#define ENEMIGOS 20 //enemigos maximos que puede haber en una pantalla
//tipos de enemigos
#define EOVNI 1
#define ESQUID 2
#define EDEVIL 3
#define EFLY 4
#define TIPENE 4

//tipos
#define NAVE 1
#define PARTICULA 2
#define DISPARO 3
#define PROTECCION 4
#define ENEMIGO 5

//MACROS

//TIPOS
typedef unsigned char u1;
typedef signed char s1;

typedef struct {
	struct {
		u1 type : 7;
		u1 active : 1;
	};
	address sprite;
	int w,h;
	int x,y;
	double vx,vy;
	int delay;
	int delay_maxim;
	int shoot;
	int delay_shoot;
	u1 vida;
} Movil; 

//VARIABLES
extern address snave,sproteccion,sdisparo,sovni,ssquid,sdevil,sfly;

extern Movil* nave;

extern Movil movil[MOVILES];

extern int enemigos; //numero de enemigos en pantalla

extern int wave; //ola actual (determina el numero de enemigos en pantalla iniciales)

//FUNCIONES
void sprites_define();
//defineiciion de los sprites
void sprite_unshow(int w,int h,int x,int y);
//borrado de un sprite

void escenario_define();
//dibujo del escenario

Movil* movil_new(byte type);
//nuevo movil definido
void movil_delete(Movil* m);
//deja libre la posicion del movil
void movil_set_velocidad(Movil* m,double vx,double vy);
//definimos la velocidad del movil
void movil_mueve(Movil* m);
//mueve un movil
void movil_dispara(Movil* m);
//disparo del movil
void movil_shoot_delay(Movil* m);
//incrementa el shoot delay llegando al maximo
u1 movil_colision(Movil* a,Movil* b);
//dice si los dos moviles colisionan
void movil_touched(Movil* m);
//un movil es tocado (se destruye si las vidas son 0)
void movil_destroy(Movil* m);
//se destruye un movil
void movil_unshow(Movil* m);
//quita de la pantalla el movil
void movil_show(Movil* m);
//muestra el movil
void movil_master();
//actua con todos los moviles

void proteccion_define();
//definimos la proteccion
void proteccion_action();
//rige el movimiento de las protecciones

void nave_define();
//iniciamos la nave del jugador
void nave_action();
//accion de la nave jugador

void enemigo_action();
//actuacion de los enemigos
void wave_new();
//crea una nueva ola de ataque

void dispara(int x,int y,int vy);
//disparo en la posicion x,y y direccion vy

void explosion(int x,int y);
//crea una explosion en el lugar dicho

#endif //STARWARS_H


