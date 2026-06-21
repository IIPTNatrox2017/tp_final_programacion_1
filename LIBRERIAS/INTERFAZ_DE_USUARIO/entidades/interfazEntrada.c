#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "../cabeceraEntidades/interfazEntrada.h"
#include "../cabeceraEntidades/interfazSalida.h"
#include "../../SERVICIO/cabeceraEntidades/logicaCategoria.h"
#include "../../SERVICIO/cabeceraEntidades/logicaJuego.h"
#include "../../SERVICIO/cabeceraEntidades/logicaNominaciones.h"
#include "../../DOMINIO/cabeceraEntidades/categoria.h"
#include "../../Librerias Externas/scanner.h"
#include "../../DOMINIO/gestorEventos.h"
#include "../cabeceraEntidades/menus.h"
#include <ctype.h>
#include <time.h>

#define DIM_MAX_NOMBRES 50


void formularioAltaJuego()
{
	int cantCategorias = 0;
	Categoria* categorias = obtenerListadoCategoriasDinamico(&cantCategorias);

	if (cantCategorias == 0)
	{
		printf("Todavia no hay categorias cargadas. Por favor ingrese una.\n");
		system("pause");
		system("cls");
		formularioAltaCategoria();
		return;
	}


	char nombre[DIM_MAX_NOMBRES];
	char estudio[DIM_MAX_NOMBRES];

	int esValido = 0;

	do
	{ 
		printf("Ingrese Nombre Juego\n >>> ");
		scanString(nombre, DIM_MAX_NOMBRES);
	
		 esValido = validarNombres(nombre);

		if (!esValido)
		{
			printf("Nombre no valido.\n");
			system("pause");
			system("cls");
		}

	} while (!esValido);

	esValido = 0;
	system("cls");
	mostrarDatosJuegosCargados(nombre, estudio);

	do
	{
		printf("Ingrese Estudio\n >>> ");
		scanString(estudio, DIM_MAX_NOMBRES);

		esValido = validarNombres(estudio);

		if (!esValido)
		{
			printf("Estudio no valido.\n");
			system("pause");

		}

	} while (!esValido);

	system("cls");
	mostrarDatosJuegosCargados(nombre, estudio);

	// ACA VA LA MUESTRA DE CATEGORIAS.

	int opcion = 0;
	esValido = 0;

	do
	{
		
		menuCategoriasDisponibles(categorias, cantCategorias);
		printf("\n");
		opcion = pedirOpcion();

		if (opcion < 1 || opcion > cantCategorias)
		{
			printf("Opcion no valida. Por favor elija otra.\n");
			system("pause");
			system("cls");
			mostrarDatosJuegosTerminados(nombre, estudio);
		}
		else
		{
			esValido = 1;
		}

	} while (!esValido);

	int indice = opcion - 1;

	//
	int control = cargarNuevoJuego(nombre, estudio, categorias[indice].idCategoria); /*cambiar genero por idCategoria*///categorias[indice].idCategoria.

	if (control == 1)
	{
		printf("\nJuego guardado con exito!\n");
	}
	else
	{
		printf("\nError al intentar cargar el juego.\n");

	}
	free(categorias);

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
	int idJuego = 1;
	int idCategoria = 1;
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

	int control = registrarNominacion(idJuego, idCategoria, puntaje, dia, mes, anio);

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

void mostrarDatosJuegosCargados(char nombre[], char estudio[])
{
	static int indice = 0;

	if (indice == 2)
	{
		indice = 0;
	}

	if (indice == 0)
	{
		printf("Nombre Cargado: [%s]\n", nombre);
		indice++;
	}
	else if (indice == 1)
	{
		printf("Nombre Cargado: [%s]\n", nombre);
		printf("Estudio Cargado: [%s]\n", estudio);
		indice++;
	}

}

void mostrarDatosJuegosTerminados(char nombre[], char estudio[])
{
	printf("Nombre Cargado: [%s]\n", nombre);
	printf("Estudio Cargado: [%s]\n", estudio);
}

void modificarJuegoArchivo()
{

	int cantJuegos = 0;
	Juego* juegos = obtenerListadoJuegosDinamico(&cantJuegos);

	if (cantJuegos == 0)
	{
		printf("Aun no hay juego cargados. Por favor ingrese uno.\n");
		return;
	}

	int esValido = 0;
	int opcion = 0;

	do
	{
		system("cls");
		mostrarListadoJuegosPorId();
		opcion = pedirOpcionModificarJuego();

		if (opcion < 1 || opcion > cantJuegos)
		{
			printf("Opcion no valida. Intente de nuevo por favor.\n");
			system("pause");
			system("cls");
			mostrarListadoJuegosPorId();
		}
		else
		{
			esValido = 1;
		}

	} while (!esValido);
	
	int indice = opcion - 1;

	system("cls");
	mostrarJuego(juegos[indice]);
	subMenuModificarJuego();
	opcion = pedirOpcion();

	switch (opcion)
	{
		case 1:
		{
			char nombre[DIM_MAX_NOMBRES];
			printf("Ingrese Nuevo Nombre: ");
			scanString(nombre, DIM_MAX_NOMBRES);
			modificarJuegoPorNombre(juegos[indice].idJuego, nombre);

			break;
		}
	}
}
