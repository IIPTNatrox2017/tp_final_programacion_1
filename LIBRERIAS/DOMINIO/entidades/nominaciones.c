#define _CRT_SECURE_NO_WARNINGS

#include "../../multiusos/includesLibrerias.h"

Nominacion crearNominacion(int id, int idJuego, int idCategoria, int puntaje, Juego juegoDeseado, Categoria categoriaDeseada)
{
	Nominacion n;
	n.idNominacion = id;
	n.idJuego = idJuego;
	n.idCategoria = idCategoria;
	n.puntaje = puntaje;
	strcpy(n.juego.nombre, juegoDeseado.nombre);
	strcpy(n.categoria.nombre, categoriaDeseada.nombre);
	n.esValido = 1;
	return n;
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