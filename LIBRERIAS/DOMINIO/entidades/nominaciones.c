#define _CRT_SECURE_NO_WARNINGS

#include "../cabeceraEntidades/nominaciones.h"
#include "../cabeceraEntidades/juegos.h"
#include "../../Librerias Externas/scanner.h"
#include <stdio.h>

Nominacion crearNominacion(int id, int idJuego, int idCategoria, Puntaje p, FechaLanzamiento f)
{
	Nominacion n = { 0 };

	n.idNominacion = id;
	n.idJuego = idJuego;
	n.idCategoria = idCategoria;
	n.puntaje = p;
	n.fecha = f;

	return n;
}
void modificarPuntajeNominacion(Nominacion* n, Puntaje nuevoPuntaje)
{
	n->puntaje = nuevoPuntaje;
}
void modificarFechaNominacion(Nominacion* n, FechaLanzamiento nuevaFecha)
{
	n->fecha = nuevaFecha;
}
int sonNominacionesDuplicadas(Nominacion n1, Nominacion n2)
{
	int encontrado = 0;

	if(n1.idJuego == n2.idJuego && n1.idCategoria == n2.idCategoria)
	{
		encontrado = 1;
	}
	return encontrado;
}