#ifndef _NOMINACIONES_H_INCLUDED
#define _NOMINACIONES_H_INCLUDED

#include "juegos.h"
#include "categoria.h"


typedef struct stNominacion
{
	int idNominacion;
	int idJuego;
	int idCategoria;
	int puntaje;
	int esValido;
	Juego juego;
	Categoria categoria;

}Nominacion;

Nominacion crearNominacion(int id, int idJuego, int idCategoria, int puntaje, Juego juegoDeseado, Categoria categoriaDeseada);

int sonNominacionesDuplicadas(Nominacion n1, Nominacion n2);
#endif