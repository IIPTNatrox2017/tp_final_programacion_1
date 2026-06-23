#ifndef SALIDA_H_INCLUDE
#define SALIDA_H_INCLUDE

#include "../../DOMINIO/cabeceraEntidades/juegos.h"

/**
* @brief Muestra un listado de juegos activos ordenados alfabeticamente.
*/
void mostrarListadoJuegos();

/**
* @brief Muestra un listado de categorias activas ordenadas alfabeticamente.
* 
* @param lista Arreglo de categorias a mostrar.
* @param validos Cantidad de categorias validas en el arreglo.
*/
void mostrarListadoCategorias(Categoria lista[], int validos);

/**
* @brief Muestra un listado de categorias inactivas ordenadas alfabeticamente.
* 
* @param lista Arreglo de categorias a mostrar.
* @param validos Cantidad de categorias validas en el arreglo.
*/
void mostrarListadoCategoriasInactivas(Categoria lista[], int validos);

/**
* @brief Muestra el ranking de nominaciones de los juegos.
*/
void mostrarRankingNominacionesUI();

/**
* @brief Muestra el listado de juegos ordenados por ID.
* 
* @param lista Arreglo de juegos a mostrar.
* @param validos Cantidad de juegos validos en el arreglo.
*/
void mostrarListadoJuegosPorId(Juego* lista, int validos);

/**
* @brief Muestra el listado de juegos inactivos ordenados por ID.
* 
* @param lista Arreglo de juegos a mostrar.
* @param validos Cantidad de juegos validos en el arreglo.
*/
void mostrarListadoJuegosDescativadosPorId(Juego* lista, int validos);

/**
* @brief Muestra los datos de un juego.
* 
* @param aux Juego a mostrar.
*/
void mostrarJuego(Juego aux);

/**
* @brief Muestra los datos de una categoria.
* 
* @param aux Categoria a mostrar.
*/
void mostrarCategoria(Categoria aux);

/**
* @brief Exporta los archivos de juegos, categorias y nominaciones a archivos de texto.
*/
void formularioExportarArchivos();

#endif // !SALIDA_H_INCLUDE

void mostrarUnaNominacion(int puesto, char nombreJuego[], char estudioJuego[], int puntaje);
void mostrarNominacion(Nominacion aux);
Nominacion* obtenerListadoNominacionesDinamico(int* validos);