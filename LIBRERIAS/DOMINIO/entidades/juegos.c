#define _CRT_SECURE_NO_WARNINGS
#include "../cabeceraEntidades/juegos.h"
#include "../../Librerias Externas/scanner.h"
#include <stdio.h>
#include <string.h>

#define DIM_MAX_NOMBRES 50

Juego crearJuego(int id, char nombre[], char estudio[], char categoria[])
{
	Juego nuevoJuego;

	nuevoJuego.idJuego = id;
	strcpy(nuevoJuego.nombre, nombre);
	strcpy(nuevoJuego.estudio, estudio);
	strcpy(nuevoJuego.categoria, categoria);
	nuevoJuego.estaActivo = 1;

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
void modificarcategoriaJuego(Juego* j, char nuevocategoria[])
{
	strcpy(j->categoria, nuevocategoria);
}
int compararJuegosPorNombre(Juego j1, Juego j2)
{
	int resultado = 0;
	resultado = _strcmpi(j1.nombre, j2.nombre);
	return resultado;
}

int compararJuegosPorId(Juego j1, Juego j2)
{
	if (j1.idJuego < j2.idJuego)
	{
		return -1;
	}
	if (j1.idJuego > j2.idJuego)
	{
		return 1;
	}

	return 0;
}