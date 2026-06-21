#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "../cabeceraEntidades/logicaJuego.h"
#include "../../DOMINIO/cabeceraEntidades/categoria.h"
#include "../../DOMINIO/cabeceraEntidades/juegos.h"
#include "../../DOMINIO/cabeceraEntidades/nominaciones.h"
#include "../../DOMINIO/cabeceraEntidades/puntajes.h"
#include "../../INTERFAZ_DE_USUARIO/cabeceraEntidades/interfazSalida.h"
#include <string.h>

#include "../../ARCHIVOS/archivos.h"


int cargarNuevoJuego(char nombre[], char estudio[], int idCategoria) 
{
	FILE* fp;
	fp = fopen(ARCHIVO_JUEGOS, "ab+");

	if (!fp)
	{
		return 0;
	}

	fseek(fp, 0, SEEK_END);
	int cantidadRegistros = ftell(fp) / sizeof(Juego);

	Juego nuevoJuego;

	int idJuego = cantidadRegistros + 1;
	
	char categoria[50] = { 0 };

	nuevoJuego = crearJuego(idJuego, nombre, estudio, categoria);

	cargarCategoriaAjuego(idCategoria, &nuevoJuego);

	fwrite(&nuevoJuego, sizeof(Juego), 1, fp);

	fclose(fp);
	
	return 1;
}

void cargarCategoriaAjuego(int idCategoria, Juego* juego)
{
	FILE* fp = fopen(ARCHIVO_CATEGORIAS, "rb");

	if (!fp)
	{
		return;
	}

	Categoria auxCategoria;

	while (fread(&auxCategoria, sizeof(Categoria), 1, fp) > 0)
	{
		if (auxCategoria.idCategoria == idCategoria)
		{
			strcpy(juego->categoria, auxCategoria.nombre);
		}
	}
	fclose(fp);
}



Juego* obtenerListadoJuegosDinamico(int* validos)
{
	FILE* fp = fopen(ARCHIVO_JUEGOS, "rb");

	if (fp == NULL)
	{
		*validos = 0;
		return NULL;
	}

	fseek(fp, 0, SEEK_END);

	int totalRegistros = ftell(fp) / sizeof(Juego);

	rewind(fp);

	if (totalRegistros <= 0)
	{
		fclose(fp);
		*validos = 0;
		return NULL;
	}
	Juego* arregloJuegos = (Juego*) malloc(totalRegistros * sizeof(Juego));

	if (arregloJuegos == NULL)
	{
		fclose(fp);
		*validos = 0;
		return NULL;
	}

	fread(arregloJuegos, sizeof(Juego), totalRegistros, fp);

	fclose(fp);

	*validos = totalRegistros;

	return arregloJuegos;
}

int buscarJuegoPorId(int id)
{
	FILE* fp = fopen(ARCHIVO_JUEGOS, "rb");
	if (fp == NULL)
	{
		return -1;
	}
	
	int idDeseada = NULL;
	Juego juego;
	while(fread(&juego, sizeof(juego), 1, fp) > 0)
	{
		if (juego.idJuego == id)
		{
			fclose(fp);
			idDeseada = juego.idJuego;
			return idDeseada;
		}

	}
	fclose(fp);
	return idDeseada;

}

int darDeBajaJuego(int id)
{
	
	FILE* fp = fopen(ARCHIVO_JUEGOS, "rb+");

	if (fp == NULL)
	{
		return -1;
	}

	int	pos = buscarJuegoPorId(id);
	if (pos == -1)
	{
		fclose(fp);
		return -1;
	}
	
	Juego juego;
	
	if (fseek(fp, pos * sizeof(Juego), SEEK_SET) != 0)
	{
		fclose(fp);
		return -1;
	}

	if (fread(&juego, sizeof(Juego), 1, fp)  != 1)
	{
		fclose(fp);
		return -1;
	}
	juego.idJuego = -1;

	if (fseek(fp, pos * sizeof(Juego), SEEK_SET) != 0)
	{
		fclose(fp);
		return -1;
	}

	if(fwrite(&juego, sizeof(Juego), 1, fp) != 1)
	{
		fclose(fp);
		return -1;
	}
	
	fclose(fp);
	return 1;

}
void ordenarJuegosAlfabeticamente(Juego arreglo[], int validos)
{
	if (arreglo == NULL || validos <= 1)
	{
		return;
	}
	int i, j, indice;

	Juego temporal;

	for (i = 0; i < validos - 1; i++)
	{
		indice = i;
		for(j = i + 1; j < validos; j++)
		{
			if (compararJuegosPorNombre(arreglo[j], arreglo[indice]) < 0)
			{
				indice = j;
			}
		}
		if(indice != i)
		{
			temporal = arreglo[i];
			arreglo[i] = arreglo[indice];
			arreglo[indice] = temporal;
		}
	}
}

void ordenarJuegosPorId(Juego arreglo[], int validos)
{
	if (arreglo == NULL || validos <= 1)
	{
		return;
	}
	int i, j, indice;

	Juego temporal;

	for (i = 0; i < validos - 1; i++)
	{
		indice = i;
		for (j = i + 1; j < validos; j++)
		{
			if (compararJuegosPorId(arreglo[j], arreglo[indice]) < 0)
			{
				indice = j;
			}
		}
		if (indice != i)
		{
			temporal = arreglo[i];
			arreglo[i] = arreglo[indice];
			arreglo[indice] = temporal;
		}
	}
}
void exportarJuegosATexto(char rutaTexto[])
{
	FILE* fb = fopen(ARCHIVO_JUEGOS, "rb");
	if(fb == NULL)
	{
		
		return;
	}
	FILE* ft = fopen(rutaTexto, "w");
	if (ft == NULL)
	{
		fclose(fb);
		return;
	}
	Juego juego;
	while (fread(&juego, sizeof(Juego), 1, fb) == 1)
	{
		if (juego.idJuego == -1)
		{
			continue;
		}
		
		fprintf(ft, "ID: %d\nNombre: %s\nEstudio: %s\ncategoria: %s\n\n", juego.idJuego, juego.nombre, juego.estudio, juego.categoria);
		
	}
	fclose(fb);
	fclose(ft);
	
}

void modificarJuegoPorNombre(int idJuego, char nombre[])
{
	FILE* fp = fopen(ARCHIVO_JUEGOS, "rb+");

	if (!fp)
	{
		return;
	}
	Juego juegoAux;

	int encontrado = 0;

	while (fread(&juegoAux, sizeof(Juego), 1, fp) > 0 && encontrado == 0)
	{
		if (juegoAux.idJuego == idJuego)
		{
			modificarNombreJuego(&juegoAux, nombre);
			fseek(fp, (long)sizeof(Juego) * (-1), SEEK_CUR);
			fwrite(&juegoAux, sizeof(Juego), 1, fp);
			encontrado = 1;
		}
	}
	fclose(fp);
}

void modificarJuegoPorEstudio(int idJuego, char estudio[])
{
	FILE* fp = fopen(ARCHIVO_JUEGOS, "rb+");

	Juego juegoAux;
	int encontrado = 0;

	while (fread(&juegoAux, sizeof(Juego), 1, fp) > 0 && encontrado == 0)
	{
		if (juegoAux.idJuego == idJuego)
		{
			modificarEstudioJuego(&juegoAux, estudio);
			fseek(fp, (long)sizeof(Juego) * (-1), SEEK_CUR);
			fwrite(&juegoAux, sizeof(Juego), 1, fp);
			encontrado = 1;

		}
	}
	fclose(fp);
}

void modificarJuegoPorCategoria(int idJuego, int idCategoria)
{
	FILE* fp = fopen(ARCHIVO_CATEGORIAS, "rb");

	Categoria auxCategoria;

	int encontrado = 0;
	char categoriaBuscada[DIM_MAX_NOMRBES];


	while (fread(&auxCategoria, sizeof(Categoria), 1, fp) > 0 && encontrado == 0)
	{
		if (auxCategoria.idCategoria == idCategoria)
		{
			strcpy(categoriaBuscada, auxCategoria.nombre);
			encontrado = 1;
		}
	}

	fclose(fp);

	fp = fopen(ARCHIVO_JUEGOS, "rb+");

	Juego auxJuego;
	encontrado = 0;
	
	while (fread(&auxJuego, sizeof(Juego), 1, fp) > 0 && encontrado == 0)
	{
		if (auxJuego.idJuego == idJuego)
		{
			strcpy(auxJuego.categoria, categoriaBuscada);
			fseek(fp, (long)sizeof(Juego) * (-1), SEEK_CUR);
			fwrite(&auxJuego, sizeof(Juego), 1, fp);
			encontrado = 1;
		}
	}

	fclose(fp);
	
}
