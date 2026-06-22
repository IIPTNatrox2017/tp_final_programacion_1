#ifndef SALIDA_H_INCLUDE
#define SALIDA_H_INCLUDE

#include "../../DOMINIO/cabeceraEntidades/juegos.h"

void mostrarListadoJuegos();
void mostrarListadoCategorias();
void mostrarRankingNominacionesUI();
void mostrarListadoJuegosPorId(Juego* lista, int validos);
void mostrarListadoJuegosDescativadosPorId(Juego* lista, int validos);
void mostrarJuego(Juego aux);

void formularioExportarArchivos();

#endif // !SALIDA_H_INCLUDE

