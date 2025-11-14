/*
============================================================
  Fichero: sprite.h
  Creado: 07-11-2025
  Ultima Modificacion: dissabte, 8 de novembre de 2025, 18:48:57
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

// SPRITE: Seccion de zx81 que tiene:
// 	1. Funcion que crea un sprite a partir de cadenas de caracteres con 0 y 1. Este sprite se puede poner en cualquiier zona de la memoria
// 	2. Funcion que traslada el sprite desde su residencia a la pantalla para ser representado.

#include "zxou.h"

//direccion de memoria ASCII para representar caracteres o gdu's
#define ASC(A) (OASC+ (8*(A)))

//metodos
#define sprnew(D,H,C) z_sprite_new((D),(H),(C))
#define sprins(D,W,H,X,Y) z_sprite_screen((D),(W),(H),(X),(Y))

address z_sprite_new(address dir,byte h,char* data[]);
//se crea un sprite en la memoria, en la direccion dir, la altura del sprite es h, data, si es '0' no se dibuja. Se exige que cada componente de data tenga la misma longitud
//se retorna 0 si no se ha podido construir el sprite o la siguiente direccion si se ha podido

void z_sprite_screen(address dir,byte w,byte h,int x,int y);
//se traslada un sprite que empieza en la direccion de memoria dir a la posicion de pantalla x,y

