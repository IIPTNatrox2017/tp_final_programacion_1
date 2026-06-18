#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "../cabeceraEntidades/logicaJuego.h"
#include "../../DOMINIO/cabeceraEntidades/categoria.h"
#include "../../DOMINIO/cabeceraEntidades/juegos.h"
#include "../../DOMINIO/cabeceraEntidades/nominaciones.h"
#include "../../DOMINIO/cabeceraEntidades/puntajes.h"

#define ARCHIVO_JUEGOS "juegos.bin"


int cargarNuevoJuego(char nombre[], char estudio[], char genero[]) 
{
	FILE* fp;
	fp = fopen(ARCHIVO_JUEGOS, "ab");

	if (!fp)
	{
		return 0;
	}

	fseek(fp, 0, SEEK_END);
	int cantidadRegistros = ftell(fp) / sizeof(Juego);

	Juego nuevoJuego;

	int idJuego = cantidadRegistros + 1;
	
	nuevoJuego = crearJuego(idJuego, nombre, estudio, genero);

	fwrite(&nuevoJuego, sizeof(Juego), 1, fp);

	fclose(fp);
	
	return 1;
}
Juego* obtenerListadoJuegosDinamico(int* validos)
{
	FILE* fp = fopen(ARCHIVO_JUEGOS, "rb");
	if (fp == NULL)
	{
		*validos = 0;
		return NULL;
	}
	int indice;

	Juego* arregloJuegos;

	fseek(fp, 0, SEEK_END);
	 
	*validos = ftell(fp) / sizeof(Juego);

	arregloJuegos = (Juego*)malloc(*validos * sizeof(Juego));
	if (arregloJuegos == NULL)
	{
		fclose(fp);
		*validos = 0;
		return NULL;
	}
	
	fseek(fp, 0, SEEK_SET);

	for (indice = 0; indice < *validos; indice++)
	{
		fread(&arregloJuegos[indice], sizeof(Juego), 1, fp);
	}
	
	fclose(fp);

	return arregloJuegos;


}
int buscarJuegoPorId(int id)
{
	FILE* fp = fopen(ARCHIVO_JUEGOS, "rb");
	if (fp == NULL)
	{
		return -1;
	}
	
	int pos = 0;
	Juego juego;
	while(fread(&juego, sizeof(juego), 1, fp) == 1)
	{
		if (juego.idJuego == id)
		{
			fclose(fp);
			return pos;
		}
		pos++;
	}
		fclose(fp);
		return -1;
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
		
		fprintf(ft, "ID: %d\nNombre: %s\nEstudio: %s\nGenero: %s\n\n", juego.idJuego, juego.nombre, juego.estudio, juego.genero);
		
	}
	fclose(fb);
	fclose(ft);
	
}

