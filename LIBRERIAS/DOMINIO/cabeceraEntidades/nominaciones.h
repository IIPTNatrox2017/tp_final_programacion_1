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

/**
* @brief Crea una nueva nominacion con valores iniciales.
* 
* @param id ID de la nominacion.
* @param idJuego ID del juego relacionado.
* @param idCategoria ID de la categoria relacionada.
* @param p puntaje de la nominacion.
* @return Nominacion Nominacion creada e inicializada
*/
Nominacion crearNominacion(int id, int idJuego, int idCategoria, int puntaje, Juego juegoDeseado, Categoria categoriaDeseada);

/**
* @brief Verifica si dos nominaciones son duplicadas.
* 
* @param n1	Primera nominacion.
* @param n2 Segunda nominacion.
* @return int 1 si son duplicadas.
* @return 0 si no estan duplicadas.
*/
int sonNominacionesDuplicadas(Nominacion n1, Nominacion n2);

#endif