#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
#include "../../Librerias Externas/pila .h"

typedef struct stRankingJuego
{
	int idJuego;
	int cantidad;
}RankingJuego;

int registrarNominacion(int idJuego, int idCategoria, Juego juegoDeseado, Categoria categoriaDeseada);
int existeNominacionDuplicada(int idJuego, int idCategoria);
int modificarNominacion(int idNominacion, int nuevoPuntaje, int d, int m, int a);
int bajaNominacion(int idNominacion);
void mostrarNominacionesPorCategoria(int idCategoria);
Pila obtenerRankingNominaciones();
int generarNumeroVotosNominacion();
void exportarNominacionesATexto(char rutaTexto[]);
void exportarNominacionesACsv(char rutaCSV[]);

#endif

