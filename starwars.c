/*
============================================================
  Fichero: starwars.c
  Creado: 13-11-2025
  Ultima Modificacion: diumenge, 16 de novembre de 2025, 08:44:46
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "starwars.h"

begin
	randomize(-1);
	sprites_define();
	proteccion_define();
	nave_define();
	if(nave) {
		do {
			listen;
			movil_master();		
			show;
			pause(0.005);
			cls;
			wave_new();
		} while(inkey('q')==0);
	}
end


