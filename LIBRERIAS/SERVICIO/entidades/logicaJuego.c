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
	printf("funcion no implementada\n");
	return 0;
}
int darDeBajaJuego(int id)
{
	printf("funcion no implementada\n");
	return 0;
}
void ordenarJuegosAlfabeticamente(Juego arreglo[], int validos)
{
	printf("funcion no implementada\n");
}
void exportarJuegosATexto(char rutaTexto[])
{
	printf("funcion no implementada\n");
}

