#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "../cabeceraEntidades/interfazEntrada.h"
#include "../../SERVICIO/cabeceraEntidades/logicaCategoria.h"
#include "../../SERVICIO/cabeceraEntidades/logicaJuego.h"
#include "../../SERVICIO/cabeceraEntidades/logicaNominaciones.h"
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
	printf("Formulario de alta de categoria.\n");
}

void formularioRegistrarNominacion()
{
	printf("Formulario de registro de nominación.\n");
}