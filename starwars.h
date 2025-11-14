/*
============================================================
  Fichero: starwars.h
  Creado: 13-11-2025
  Ultima Modificacion: dijous, 13 de novembre de 2025, 20:44:06
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#ifndef STARWARS_H
#define STARWARS_H

#include <stdio.h>
#include <maths.h>

#include "sprite.h"

//CONSTANTES
#define MOVILES 200

//MACROS

//TIPOS
typedef unsigned char u1;
typedef signed char s1;

typedef struct {
	double x,y;
	double vx,vy;
	int delay;
	int delay_maxim;
} Movil; 

//VARIABLES
extern address snave,sproteccion;

extern Movil movil[MOVILES];
extern int moviles;

//FUNCIONES
void sprites_define();
//defineiciion de los sprites

void escenario_define();
//dibujo del escenario

Movil* movil_new();
//nuevo movil definido
void movil_set_velocidad(Movil* m,double vx,double vy);
//definimos la velocidad del movil
void movil_mueve(Movil* m);
//mueve un movil

void explosion(int x,int y);
//crea una explosion en el lugar dicho

#endif //STARWARS_H


