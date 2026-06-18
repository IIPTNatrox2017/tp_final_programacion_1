#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "../cabeceraEntidades/interfazEntrada.h"
#include "../../SERVICIO/cabeceraEntidades/logicaCategoria.h"
#include "../../SERVICIO/cabeceraEntidades/logicaJuego.h"
#include "../../SERVICIO/cabeceraEntidades/logicaNominaciones.h"
#include "../../DOMINIO/cabeceraEntidades/categoria.h"
#include "../../Librerias Externas/scanner.h"
#include <time.h>

#define DIM_MAX_NOMBRES 50


void formularioAltaJuego()
{
	char nombre[DIM_MAX_NOMBRES];
	char genero[DIM_MAX_NOMBRES];
	char estudio[DIM_MAX_NOMBRES];

	printf("Ingrese nombre\n >>> ");
	scanString(nombre, DIM_MAX_NOMBRES);
	int cantLetras = strlen(nombre);

	if (cantLetras < 1)
	{
		printf("\nNombre no valido\n");
		return;
	}

	printf("Ingrese genero\n >>> ");
	scanString(genero, DIM_MAX_NOMBRES);
	cantLetras = strlen(genero);

	if (cantLetras <= 1)
	{
		printf("\nGenero no valido\n");
		return;
	}

	printf("Ingrese estudio\n >>> ");
	scanString(estudio, DIM_MAX_NOMBRES);
	cantLetras = strlen(estudio);

	if (cantLetras < 1)
	{
		printf("\nEstudio no valido\n");
		return;
	}
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
	do
	{
		printf("Ingrese nombre de la categoria\n >>> ");
		scanString(categoria, DIM_MAX_NOMBRES);

		if (strlen(categoria) == 0)
		{
			printf("Ingrese un nombre valido.\n");
			system("pause");
			system("cls");
		}

	} while (strlen(categoria) == 0);


	int control = cargarNuevaCategoria(categoria);
		
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
	srand(time(NULL));

	int puntaje = (rand() % 10000) + 1;
	int dia = 0;
	int	mes = 0;
	int	anio = 0;


	while (dia <= 0 || dia >= 32)
	{
		printf("Ingrese fecha de nominacion (dd/mm/aaaa)\n");
		printf("DIA: >>> ");
		scanf("%d", &dia);
		if (dia <= 0 || dia >= 32)
		{
			printf("--Dia no valido.\n");
			system("pause");
			system("cls");
		}

	}

	printf("Dia cargado con exito!\n");
	system("pause");
	system("cls");

	while (mes <= 0 || mes >= 13)
	{
		printf("Ingrese fecha de nominacion (dd/mm/aaaa)\n");
		printf("MES: >>> ");
		scanf("%d", &mes);
		if (mes <= 0 || mes >= 13)
		{
			printf("--Mes no valido.\n");
			system("pause");
			system("cls");
		}
	}

	printf("Mes cargado con exito!\n");
	system("pause");
	system("cls");

	while (anio <= 1950 || anio >= 2051)
	{
		printf("Ingrese fecha de nominacion (dd/mm/aaaa)\n");
		printf("ANIO: >>> ");
		scanf("%d", &anio);
		if (anio <= 1950 || anio >= 2051)
		{
			printf("--Anio no valido.\n");
			system("pause");
			system("cls");
		}
	}

	printf("Anio cargado con exito!\n");
	system("pause");
	system("cls");


	int control = registrarNominacion(puntaje, dia, mes, anio);

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