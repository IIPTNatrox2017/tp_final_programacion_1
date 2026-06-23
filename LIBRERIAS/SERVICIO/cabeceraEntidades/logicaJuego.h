#ifndef LOGICA_JUEGO_H_INCLUDED
#define LOGICA_JUEGO_H_INCLUDED

#include "../../DOMINIO/cabeceraEntidades/juegos.h"

int cargarNuevoJuego(char nombre[], char estudio[], int idCategoria);
Juego* obtenerListadoJuegosDinamico(int* validos);
Juego* buscarJuegoPorId(int id);
void darDeBajaJuego(int id);
void reactivarUnJuego(int idJuego);
void ordenarJuegosAlfabeticamente(Juego arreglo[], int validos);
void exportarJuegosATexto(char rutaTexto[]);
void ordenarJuegosPorId(Juego arreglo[], int validos);
void cargarCategoriaAjuego(int idCategoria, Juego* juego);

void listadoJuegosSegunCategoria(char categoriaDeseada[]);

void modificarJuegoPorNombre(int idJuego, char nombre[]);
void modificarJuegoPorEstudio(int idJuego, char estudio[]);
void modificarJuegoPorCategoria(int idJuego, char nombreCategoria[]);
int verificarNombreJuegoNuevo(char nombreNuevo[]);
void exportarJuegosACsv(char rutaCSV[]);

#endif
	















