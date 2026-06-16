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
	printf("todavia no se implemento la funcion\n");
}
void modificarEstudioJuego(Juego* j, char nuevoEstudio[])
{
	printf("todavia no se implemento la funcion\n");
}
void modificarGeneroJuego(Juego* j, char nuevoGenero[])
{
	printf("todavia no se implemento la funcion\n");
}
int compararJuegosPorNombre(Juego j1, Juego j2)
{
	printf("todavia no se implemento la funcion\n");
	return 0;
}
