#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
#include "../../Librerias Externas/pila .h"

int registrarNominacion(int puntajeValor, int d, int m, int a);
int existeNominacionDuplicada(int idJuego, int idCategoria);
Pila obtenerRankingNominaciones();
void exportarNominacionesATexto(char rutaTexto[]);

#endif

