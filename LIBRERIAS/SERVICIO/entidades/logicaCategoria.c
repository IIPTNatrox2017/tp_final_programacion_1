#define _CRT_SECURE_NO_WARNINGS
#include "../cabeceraEntidades/logicaCategoria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	FILE* fp = fopen(ARCHIVO_CATEGORIAS, "rb");
	if (!fp);
	{
		return -1;
	}

	int pos = 0;
	Categoria aux;
	while(fread(&aux, sizeof(Categoria), 1, fp))
	{ 
		if (aux.idCategoria == id)
		{
			fclose(fp);
			return pos;
		}
		pos++;
	}
	fclose(fp);
	return -1;
}

void ordenarCategoriasAlfabeticamente(Categoria arreglo[], int validos)
{
	int posMenor;
	Categoria aux;

	for(int i = 0; i < validos - 1; i++)
	{ 
		posMenor = i;
		
		for(int j = i + 1; j < validos; j++)
		{
			if (strcmp(arreglo[j].nombre, arreglo[posMenor].nombre) < 0)
			{
				posMenor = j;
			}
		}
		if (posMenor != i)
		{
			aux = arreglo[i];
			arreglo[i] = arreglo[posMenor];
			arreglo[posMenor] = aux;
		}
	}
}

void exportarCategoriasATexto(char rutaTexto[])
{
	printf("funcion no implementada\n");
}

Categoria* obtenerListadoCategoriasDinamico(int* validos)
{
	FILE* fp = fopen (ARCHIVO_CATEGORIAS, "rb");

	if (!fp)
	{
		*validos = 0;
		return 0;
	}
	int indice; 

	Juego* arregloCategorias;

	fseek(fp, 0, SEEK_END);

	*validos = ftell(fp) / sizeof(Categoria);

	arregloCategorias = (Categoria*)malloc((*validos) * sizeof(Categoria));
	if(arregloCategorias == NULL)
	{
		fclose(fp);
		*validos = 0;
		return NULL;
	}

	fseek(fp, 0, SEEK_SET);

	for (indice = 0; indice < *validos; indice++)
	{
		fread(&arregloCategorias, sizeof(Categoria), 1, fp);
	}

	fclose(fp);

	return arregloCategorias;
}

