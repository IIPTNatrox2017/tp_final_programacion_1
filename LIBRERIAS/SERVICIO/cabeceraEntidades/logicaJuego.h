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

int modificarJuegoPorNombre(int idJuego, char nombre[]);
int modificarJuegoPorEstudio(int idJuego, char estudio[]);

#endif
	















