#define _CRT_SECURE_NO_WARNINGS
#include "../cabeceraEntidades/logicaCategoria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../DOMINIO/cabeceraEntidades/categoria.h"

#define ARCHIVO_CATEGORIAS "categorias.bin"
#define ARCHIVO_JUEGOS "juegos.bin"

int cargarNuevaCategoria(char nombre[])
{
	FILE* fp = fopen(ARCHIVO_CATEGORIAS, "ab");

	if (!fp)
	{
		printf("ERROR! No se pudo abrir el archivo de categorías.\n");
		return 0;
	}
	
	fseek(fp, 0, SEEK_END);

	int cantCategorias = ftell(fp) / sizeof(Categoria);
	int nuevoId = cantCategorias + 1;

	Categoria nueva = crearCategoria(nuevoId, nombre);
	
	fwrite(&nueva, sizeof(Categoria), 1, fp);

	fclose(fp);

	return 1;
}
int buscarCategoriaPorId(int id)
{
	FILE* fp = fopen(ARCHIVO_CATEGORIAS, "rb");
	if (!fp)
	{
		printf("ERROR! No se pudo abrir el archivo de categorías.\n");
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
	Categoria aux;
	FILE* fp = fopen(ARCHIVO_CATEGORIAS, "rb");
	if(!fp)
	{ 
		printf("ERROR! No se pudo abrir el archivo de categorías.\n");
		return;
	}
	FILE* fpTexto = fopen(rutaTexto, "w");
	if(!fpTexto)
	{ 
		printf("ERROR! No se pudo abrir el archivo de texto.\n");
		fclose(fp);
		return;
	}
	while (fread(&aux, sizeof(Categoria), 1, fp) == 1)
	{
		fprintf(fpTexto, "=================================\n");
		fprintf(fpTexto, "ID: %d, Nombre: %s\n", aux.idCategoria, aux.nombre);
	}
	fclose(fp);
	fclose(fpTexto);
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

	Categoria* arregloCategorias;

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
		fread(&arregloCategorias[indice], sizeof(Categoria), 1, fp);
	}

	fclose(fp);

	return arregloCategorias;
}

int bajaCategoria(int idCategoria)
{
	FILE* fp = fopen(ARCHIVO_CATEGORIAS, "rb+");

	if (!fp)
	{
		return 0;
	}

	Categoria aux;
	int exito = -1;

	while (fread(&aux, sizeof(Categoria), 1, fp) > 0 && exito == -1)
	{
		if (aux.idCategoria == idCategoria)
		{
			aux.idCategoria = -1;

			fseek(fp, sizeof(Categoria), SEEK_CUR);

			fwrite(&aux, sizeof(Categoria), 1, fp);

			exito = 1;
		}
	}

	fclose(fp);

	return exito;
}

int modificarCategoria(int idCategoria, char nuevoNombre[])
{
	FILE* fp = fopen(ARCHIVO_CATEGORIAS, "rb+");

	if (!fp)
	{
		return 0;
	}

	Categoria aux;
	int exito = -1;

	while (fread(&aux, sizeof(Categoria), 1, fp) > 0 && exito == -1)
	{
		if (aux.idCategoria == idCategoria)
		{
			strcpy(aux.nombre, nuevoNombre);

			fseek(fp, sizeof(Categoria), SEEK_CUR);

			fwrite(&aux, sizeof(Categoria), 1, fp);

			exito = 1;
		}
	}

	fclose(fp);

	return exito;
}

int modificarJuego(
	int idJuego,
	char nuevoNombre[],
	char nuevoEstudio[],
	char nuevoGenero[]
)
{
	FILE* fp = fopen(ARCHIVO_JUEGOS, "rb+");

	if (!fp)
	{
		return 0;
	}

	Juego aux;
	int exito = -1;

	while (fread(&aux, sizeof(Juego), 1, fp) > 0 && exito == -1)
	{
		if (aux.idJuego == idJuego)
		{
			strcpy(aux.nombre, nuevoNombre);
			strcpy(aux.estudio, nuevoEstudio);
			strcpy(aux.genero, nuevoGenero);

			fseek(fp, sizeof(Juego), SEEK_CUR);

			fwrite(&aux, sizeof(Juego), 1, fp);

			exito = 1;
		}
	}

	fclose(fp);

	return exito;
}