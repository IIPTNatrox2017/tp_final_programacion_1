#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "../cabeceraEntidades/categoria.h"
#include <string.h>


Categoria crearCategoria(int id, char nombre[])
{
	Categoria nuevaCategoria;
	strcpy(nuevaCategoria.nombre, nombre);
	nuevaCategoria.idCategoria = id;

	return nuevaCategoria;
}
void modificarNombreCategoria(Categoria* c, char nuevoNombre[])
{
	strcpy(c->nombre, nuevoNombre);
}
int compararCategoriasPorNombre(Categoria c1, Categoria c2)
{
	int resultado;
	resultado = strcmpi(c1.nombre, c2.nombre);
	return resultado;
}