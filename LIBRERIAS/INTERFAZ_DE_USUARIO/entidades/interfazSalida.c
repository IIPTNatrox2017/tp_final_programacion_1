#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "../cabeceraEntidades/interfazSalida.h"
#include "../../DOMINIO/cabeceraEntidades/juegos.h"
#include "../../SERVICIO/cabeceraEntidades/logicaJuego.h"
#include "../../DOMINIO/cabeceraEntidades/categoria.h"
#include "../../SERVICIO/cabeceraEntidades/logicaCategoria.h"
#include "../../SERVICIO/cabeceraEntidades/logicaNominaciones.h"
#include "../../Librerias Externas/scanner.h"
#include <string.h>
#include "../../INTERFAZ_DE_USUARIO/cabeceraEntidades/menus.h"

void mostrarListadoJuegos()
{
	int validos = 0;

	Juego* lista = obtenerListadoJuegosDinamico(&validos);

	ordenarJuegosAlfabeticamente(lista, validos);

	if (validos <= 0)
	{
		printf("\nNo hay Juegos cargados!.\n");
		return;
	}
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
void mostrarListadoJuegosPorId()
{
	int validos = 0;

	Juego* lista = obtenerListadoJuegosDinamico(&validos);
	
	ordenarJuegosPorId(lista, validos);

	printf("========== LISTADO DE JUEGOS ==========\n");

	for (int i = 0; i < validos; i++)
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

	int numCat = 0;
	printf("========== LISTADO DE CATEGORIAS ==========\n");
	for(int i = 0; i < validos; i++)
	{ 
		numCat = i+1;
		printf("[%d] Nombre: %s\n", numCat, lista[i].nombre);
		printf("----------------------------------\n");
	}

	free(lista);
}

void mostrarRankingNominacionesUI()
{
	Pila rankings;
	inicpila(&rankings);

	rankings = obtenerRankingNominaciones();


	if (pilavacia(&rankings))
	{
		printf("\n No hay nominaciones registradas para armar el ranking.\n");
		return;
	}
	
	int juegosTotales = 0;

	Juego* listaJuegos = obtenerListadoJuegosDinamico(&juegosTotales);


	if (listaJuegos == NULL)
	{
		return;
	}

	int puesto = 1;

	while (!pilavacia(&rankings))
	{
		int idJuegoBuscado = desapilar(&rankings);

		char nombreJuego[50] = { };
		char estudioJuego[50] = { };



		for (int i = 0; i < juegosTotales; i++)
		{
			if (listaJuegos[i].idJuego == idJuegoBuscado)
			{
				strcpy(nombreJuego, listaJuegos[i].nombre);
				strcpy(estudioJuego, listaJuegos[i].estudio);
			}
		}
		
		menuPuestosPila(puesto, nombreJuego, estudioJuego);
		puesto++;
	}

	free(listaJuegos);
}

void formularioExportarArchivos()
{
	char opcion;

	printf("Desea exportar los archivos? (s/n)\n>>> ");
	scanf(" %c", &opcion);

	if(opcion == 's' || opcion == 'S')
	{
		exportarJuegosATexto("Juegos.txt");
		exportarCategoriasATexto("Categorias.txt");
		exportarNominacionesATexto("Nominaciones.txt");

		printf("\nArchivos guardados en la carpeta del proyecto.\n");
	}
	else
	{
		printf("\nOperacion Cancelada.\n");
	}
}

void mostrarJuego(Juego aux)
{
	printf("ID: %d\n", aux.idJuego);
	printf("Nombre: %s\n", aux.nombre);
	printf("Estudio: %s\n",aux.estudio);
	printf("Genero: %s\n",aux.genero);
	printf("----------------------------------\n");
}