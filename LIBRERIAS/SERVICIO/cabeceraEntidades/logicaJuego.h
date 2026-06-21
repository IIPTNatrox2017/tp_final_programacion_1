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
int modificarJuego(int idJuego, char nuevoNombre[], char nuevoEstudio[], char nuevoGenero[]);
void mostrarJuegosPorGenero(char genero[]);
void cargarCategoriaAjuego(int idCategoria, Juego* juego);

#endif
	















