/*
============================================================
  Fichero: escenario.c
  Creado: 13-11-2025
  Ultima Modificacion: dijous, 13 de novembre de 2025, 20:16:32
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "starwars.h"

void escenario_define() {
	const int ESP=56;
	const int DEW=11;
	const int DEH=6;
	const int DEY=230;
	for(int n=0;n<3;n++) {
		sprins(sproteccion,DEW,DEH,ESP*(n+1)+DEW*n,DEY);
	}
}

