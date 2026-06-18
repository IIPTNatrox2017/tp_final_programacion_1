#ifndef _NOMINACIONES_H_INCLUDED
#define _NOMINACIONES_H_INCLUDED

#include "juegos.h"
#include "categoria.h"
#include "puntajes.h"

typedef struct stNominacion
{
	int idNominacion;
	Puntaje puntaje;
	FechaLanzamiento fecha;
	Juego juego;
	Categoria categoria;
}Nominacion;

Nominacion crearNominacion(int id, int idJuego, int idCategoria, Puntaje p, FechaLanzamiento f);
void modificarPuntajeNominacion(Nominacion* n, Puntaje nuevoPuntaje);
void modificarFechaNominacion(Nominacion* n, FechaLanzamiento nuevaFecha);
int sonNominacionesDuplicadas(Nominacion n1, Nominacion n2);
	
#endif