#ifndef LOGICA_JUEGO_H_INCLUDED
#define LOGICA_JUEGO_H_INCLUDED

#include "../../DOMINIO/cabeceraEntidades/juegos.h"

int cargarNuevoJuego(char nombre[], char estudio[], int idCategoria);
Juego* obtenerListadoJuegosDinamico(int* validos);
int buscarJuegoPorId(int id);
int darDeBajaJuego(int id);
void ordenarJuegosAlfabeticamente(Juego arreglo[], int validos);
void exportarJuegosATexto(char rutaTexto[]);
void ordenarJuegosPorId(Juego arreglo[], int validos);
void mostrarJuegosPorGenero(char genero[]);
void cargarCategoriaAjuego(int idCategoria, Juego* juego);

void modificarJuegoPorNombre(int idJuego, char nombre[]);
void modificarJuegoPorEstudio(int idJuego, char estudio[]);
void modificarJuegoPorCategoria(int idJuego, char nombreCategoria[]);

#endif
	















