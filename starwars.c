/*
============================================================
  Fichero: starwars.c
  Creado: 13-11-2025
  Ultima Modificacion: dijous, 13 de novembre de 2025, 20:17:46
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "starwars.h"

begin
	sprites_define();
	escenario_define();
	show;
	while(inkey('q')==0) listen;
end


