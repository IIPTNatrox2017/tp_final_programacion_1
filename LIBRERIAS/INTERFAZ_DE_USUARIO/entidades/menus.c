#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include "../../DOMINIO/cabeceraEntidades/nominaciones.h"
#include "../cabeceraEntidades/menus.h"
#include <stdio.h>
#include "../../Librerias Externas/scanner.h"
#include "../cabeceraEntidades/interfazEntrada.h"
#include "../cabeceraEntidades/interfazSalida.h"

#define DIM_MAX_NOMBRES 50

//ESTA CAPA SERA LA UNICA ENCARGADA DE SOLICITAR DATOS AL USUARIO.
// SE RECOMIENDA EL USO RESPONSABLE DE IA.
// TODO EL CODIGO ENTREGADO DEBE PODER SER DEFENDIDO POR CUALQUIER INTEGRANTE DEL GRUPO.



void menuPrincipal()
{
	int opcion;
	do
	{
		mostrarMenu();
		opcion = pedirOpcion();
		ejecutarOpcion(opcion);
	} while (opcion != 0);
}

void mostrarMenu()
{
	system("cls");
	printf("===========================\n");
	printf("      MENU PRINCIPAL\n");
	printf("===========================\n");

	printf("1. Juegos.\n");
	printf("2. Categorias.\n");
	printf("3. Nominaciones.\n");
	printf("0. Salir.\n");
}
 
int pedirOpcion()
{
	int opcion;

	printf("Ingrese una opcion>> ");
	opcion = scanInt();

	return opcion;
}

void ejecutarOpcion(int opcion)
{
	switch (opcion)
	{
		case 1:
		{
			system("cls");
			subMenuJuegos();
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			subMenuCategorias();
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			subMenuNominaciones();
			system("pause");
			break;
		}
		case 0:
		{
			system("cls");
			printf("Saliendo del programa...\n");
			break;
		}
		default:
		{
			system("cls");
			printf("Opcion invalida. Por favor, intente de nuevo.\n");
			system("pause");
			break;
		}
	}
}

void subMenuJuegos()
{
	int opcion;

	do
	{
		system("cls");
		printf("===========================\n");
		printf("      MENU JUEGOS\n");
		printf("===========================\n");

		printf("1. Alta Juego\n");
		printf("2. Listado de Juegos\n");
		printf("0. Volver al Menu Principal\n");
		printf("Ingrese una opcion>> ");
		opcion = scanInt();

		switch (opcion)
		{
		case 1:
		{
			system("cls");
			formularioAltaJuego();
			break;
		}
		case 2:
		{
			system("cls");
			mostrarListadoJuegos();
			break;
		}
		case 0:
		{
			system("cls");
			printf("Volviendo al menu principal...\n");
			break;
		}
		default:
		{
			system("cls");
			printf("Opcion invalida. Por favor, intente de nuevo.\n");
			break;
		}

		} 
	}
	while (opcion != 0);
}


void subMenuCategorias()
{
	int opcion;

	do
	{
		printf("===========================\n");
		printf("      MENU CATEGORIAS\n");
		printf("===========================\n");

		printf("1. Alta Categoria.\n");
		printf("2. Listado Categorias.\n");
		printf("0. Volver al Menu Principal\n");
		printf("Ingrese una opcion>> ");
		opcion = scanInt();

		switch (opcion)
		{
		case 1:
		{
			system("cls");
			formularioAltaCategoria();
			break;
		}
		case 2:
		{
			system("cls");
			mostrarListadoCategorias();
			break;
		}
		case 0:
		{
			system("cls");
			printf("Volviendo al menu principal...\n");
			break;
		}
		default:
		{
			system("cls");
			printf("Opcion invalidad. Por favor, intente de nuevo.\n");
			break;
		}

		}

	} while (opcion != 0);
}

void subMenuNominaciones()
{
	int opcion;

	do
	{
		printf("===========================\n");
		printf("      MENU NOMINACIONES\n");
		printf("===========================\n");

		printf("1. Registrar Nominacion.\n");
		printf("2. Ranking Nominaciones.\n");
		printf("0. Volver al Menu Principal\n");
		printf("Ingrese una opcion>> ");
		opcion = scanInt();

		switch (opcion)
		{
		case 1:
		{
			system("cls");
			formularioRegistrarNominacion();
			break;
		}
		case 2:
		{
			system("cls");
			mostrarRankingNominacionesUI();
			break;
		}
		case 0:
		{
			system("cls");
			printf("Volviendo al menu principal...\n");
			break;
		}
		default:
		{
			system("cls");
			printf("Opcion invalida. Por favor, intente de nuevo.\n");
			break;
		}
		}
	} while (opcion != 0);
}
