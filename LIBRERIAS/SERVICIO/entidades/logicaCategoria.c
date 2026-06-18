#define _CRT_SECURE_NO_WARNINGS
#include "../cabeceraEntidades/logicaCategoria.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../DOMINIO/cabeceraEntidades/categoria.h"

#define ARCHIVO_CATEGORIAS "categorias.bin"


int cargarNuevaCategoria(int id, char nombre[])
{
	FILE* fp = fopen(ARCHIVO_CATEGORIAS, "ab");

	if (!fp)
	{
		return 0;
	}
	
	Categoria nueva = crearCategoria(id, nombre);
	
	fwrite(&nueva, sizeof(Categoria), 1, fp);

	fclose(fp);

	return 1;
}
int buscarCategoriaPorId(int id)
{
	printf("funcion no implementada\n");
	return 0;
}
void ordenarCategoriasAlfabeticamente(Categoria arreglo[], int validos)
{
	printf("funcion no implementada\n");
}
void exportarCategoriasATexto(char rutaTexto[])
{
	printf("funcion no implementada\n");
}

