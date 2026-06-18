#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "../cabeceraEntidades/interfazSalida.h"
#include "../../DOMINIO/cabeceraEntidades/juegos.h"
#include "../../SERVICIO/cabeceraEntidades/logicaJuego.h"
#include "../../DOMINIO/cabeceraEntidades/categoria.h"
#include "../../SERVICIO/cabeceraEntidades/logicaCategoria.h"

void mostrarListadoJuegos()
{
	int validos = 0;

	Juego* lista = obtenerListadoJuegosDinamico(&validos);

	ordenarJuegosAlfabeticamente(lista, validos);

	printf("========== LISTADO DE JUEGOS ==========\n");

	for(int i=0; i < validos; i++)
	{ 
		printf("ID: %d\n", lista[i].idJuego);
		printf("Nombre: %s\n", lista[i].nombre);
		printf("Estudio: %s\n", lista[i].estudio);
		printf("Genero: %s\n", lista[i].genero);
		printf("----------------------------------\n");
	}

	free(lista);
}
void mostrarListadoCategorias()
{
	int validos = 0;

	Categoria* lista = obtenerListadoCategoriasDinamico(&validos);

	if(lista == NULL)
	{
		printf("\nNo hay categorias para mostrar.\n");
		return;
	}

	ordenarCategoriasAlfabeticamente(lista, validos);

	printf("========== LISTADO DE CATEGORIAS ==========\n");
	for(int i = 0; i < validos; i++)
	{ 
		printf("ID: %d\n", lista[i].idCategoria);
		printf("Nombre: %s\n", lista[i].nombre);
		printf("----------------------------------\n");
	}

	free(lista);
}

void mostrarRankingNominacionesUI()
{
	printf("Todavia no se implemento esta funcion.\n");
}
void formularioExportarArchivos()
{
	printf("Todavia no se implemento esta funcion.\n");
}