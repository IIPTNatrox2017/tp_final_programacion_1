#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "../cabeceraEntidades/interfazEntrada.h"
#include "../../SERVICIO/cabeceraEntidades/logicaCategoria.h"
#include "../../SERVICIO/cabeceraEntidades/logicaJuego.h"
#include "../../SERVICIO/cabeceraEntidades/logicaNominaciones.h"
#include "../../DOMINIO/cabeceraEntidades/categoria.h"
#include "../../Librerias Externas/scanner.h"
#define DIM_MAX_NOMBRES 50


void formularioAltaJuego()
{
	char nombre[DIM_MAX_NOMBRES];
	char genero[DIM_MAX_NOMBRES];
	char estudio[DIM_MAX_NOMBRES];

	printf("Ingrese nombre\n >>> ");
	scanString(nombre, DIM_MAX_NOMBRES);

	printf("Ingrese genero\n >>> ");
	scanString(genero, DIM_MAX_NOMBRES);

	printf("Ingrese estudio\n >>> ");
	scanString(estudio, DIM_MAX_NOMBRES);

	int control = cargarNuevoJuego(nombre, estudio, genero);

	if (control == 1)
	{
		printf("\nJuego guardado con exito!\n");
	}
	else
	{
		printf("\nError al intentar cargar el juego.\n");
	}

}

void formularioAltaCategoria()
{
	char categoria[DIM_MAX_NOMBRES];
	int id;

	do
	{
		printf("Ingrese nombre de la categoria\n >>> ");
		scanString(categoria, DIM_MAX_NOMBRES);

	} while (strlen(categoria) == 0);

	printf("Ingrese ID de la categoria\n >>> ");
	id = scanInt();


	int control = cargarNuevaCategoria(id, categoria);
		
	if (control == 1)
	{
		printf("\nCategoria guardada con exito!\n");
	}
	else
	{
		printf("\nError al intentar cargar la categoria.\n");
	}

}

void formularioRegistrarNominacion()
{
	int idJuego;
	int idCategoria;
	float puntaje;
	int d, m, a;

	printf("Ingrese ID del Juego\n >>> ");
	idJuego = scanInt();

	printf("Ingrese ID de la Categoria\n >>> ");
	idCategoria = scanInt();

	printf("Ingrese puntaje\n>>> ");
	puntaje = scanFloat();

	printf("Ingrese fecha de nominacion (dd/mm/aaaa)\n>>> ");
	scanf("%d/%d/%d", &d, &m, &a);

	int control = registrarNominacion(idJuego, idCategoria, puntaje, d, m, a);

	if (control == -2)
	{
		printf("\nAlerta: La nominacion ya existe.\n");
	}
	else if(control == 1)
	{
		printf("\nNominacion registrada con exito!\n");
	}
	else
	{
		printf("\nError al intentar registrar la nominacion.\n");
	}
}