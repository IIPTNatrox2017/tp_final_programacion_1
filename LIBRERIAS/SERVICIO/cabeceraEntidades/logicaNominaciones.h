#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
#include "../../Librerias Externas/pila .h"

int registrarNominacion(int idJuego, int idCategoria, int puntajeValor, int d, int m, int a);
int existeNominacionDuplicada(int idJuego, int idCategoria);
Pila obtenerRankingNominaciones();
void exportarNominacionesATexto(char rutaTexto[]);
int modificarNominacion(int idNominacion, int nuevoPuntaje, int d, int m, int a);
int bajaNominacion(int idNominacion);

#endif

