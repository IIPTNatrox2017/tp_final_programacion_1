#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "../cabeceraEntidades/categoria.h"
#include <string.h>


Categoria crearCategoria(char nombre[])
{
	Categoria nuevaCategoria;
	
	strcpy(nuevaCategoria.nombre, nombre);

	return nuevaCategoria;
}
void modificarNombreCategoria(Categoria* c, char nuevoNombre[])
{
	strcpy(c->nombre, nuevoNombre);
}
int compararCategoriasPorNombre(Categoria c1, Categoria c2)
{
	int resultado;
	resultado = _strcmpi(c1.nombre, c2.nombre);
	return resultado;
}

void modificarIDcategoria(Categoria* c, int idNuevo)
{
	c->idCategoria = idNuevo;
}