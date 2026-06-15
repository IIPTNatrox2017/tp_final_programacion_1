#ifndef _NOMINACIONES_H_INCLUDED
#define _NOMINACIONES_H_INCLUDED

#include "juegos.h"

typedef struct stNominacion
{
	int idNominacion;
	Categoria categoria;
	Juego juego;
	Puntaje puntaje;
	FechaLanzamiento fecha;
	int estaNominado;

}Nominacion;


#endif