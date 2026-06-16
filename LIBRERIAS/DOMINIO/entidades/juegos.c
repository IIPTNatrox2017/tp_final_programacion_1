#define _CRT_SECURE_NO_WARNINGS
#include "../cabeceraEntidades/juegos.h"
#include "../../Librerias Externas/scanner.h"
#include <stdio.h>
#include <string.h>

#define DIM_MAX_NOMBRES 50

Juego crearJuego(int id, char nombre[], char estudio[], char genero[])
{
	Juego nuevoJuego;

	nuevoJuego.idJuego = id;
	strcpy(nuevoJuego.nombre, nombre);
	strcpy(nuevoJuego.estudio, estudio);
	strcpy(nuevoJuego.genero, genero);

	return nuevoJuego;
}
void modificarNombreJuego(Juego* j, char nuevoNombre[])
{
	strcpy(j->nombre, nuevoNombre);
}
void modificarEstudioJuego(Juego* j, char nuevoEstudio[])
{
	strcpy(j->estudio, nuevoEstudio);
}
void modificarGeneroJuego(Juego* j, char nuevoGenero[])
{
	strcpy(j->genero, nuevoGenero);
}
int compararJuegosPorNombre(Juego j1, Juego j2)
{
	int resultado = 0;
	resultado = strcmpi(j1.nombre, j2.nombre);
	return resultado;
}
