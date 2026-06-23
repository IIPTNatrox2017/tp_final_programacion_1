#ifndef _NOMINACIONES_H_INCLUDED
#define _NOMINACIONES_H_INCLUDED

#include "juegos.h"
#include "categoria.h"
#include "puntajes.h"

typedef struct stNominacion
{
	int idNominacion;
	int idJuego;
	int idCategoria;
	Puntaje puntaje;
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
Nominacion crearNominacion(int id, int idJuego, int idCategoria, Puntaje p);

/**
* @brief Verifica si dos nominaciones son duplicadas.
* 
* @param n1	Primera nominacion.
* @param n2 Segunda nominacion.
* @return int 1 si son duplicadas.
* @return 0 si no estan duplicadas.
*/
int sonNominacionesDuplicadas(Nominacion n1, Nominacion n2);

/**
* @brief Modifica el puntaje de una dominacion.
* 
* @param n Puntero a la nominacion a modificar
* @param nuevoPuntaje Nuevo puntaje a asignar.
*/
void modificarPuntajeNominacion(Nominacion* n, Puntaje nuevoPuntaje);	
#endif