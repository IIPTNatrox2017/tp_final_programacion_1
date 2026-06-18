#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include "../../DOMINIO/cabeceraEntidades/nominaciones.h"
#include "../cabeceraEntidades/menus.h"
#include <stdio.h>
#include "../../Librerias Externas/scanner.h"
#include "../../SERVICIO/cabeceraEntidades/logicaJuego.h"
#include "../../INTERFAZ_DE_USUARIO/cabeceraEntidades/interfazSalida.h"
#include "../../DOMINIO/gestorEventos.h"
#include "../../SERVICIO/cabeceraEntidades/logicaCategoria.h"

#define DIM_MAX_NOMBRES 50
#define ARCHIVO_JUEGOS "juegos.bin"
#define ARCHIVO_CATEGORIAS "categorias.bin"

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

	printf("Ingrese una opcion\n >>> ");
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
			system("cls");
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

		printf("1. Cargar un juego al archivo.\n");
		printf("2. Listado de Juegos Alfabaticamente (A-Z)\n");
		printf("3. Ordenar juegos por ID.\n");
		printf("4. Vaciar Archivo juegos.\n");
		printf("0. Volver al Menu Principal\n");
		printf("Ingrese una opcion\n>>> ");
		opcion = scanInt();

		switch (opcion)
		{
		case 1:
		{
			system("cls");
			formularioAltaJuego();
			system("pause");
			break;
		}
		case 2:
		{
			mostrarListadoJuegos();
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			mostrarListadoJuegosPorId();
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			abrirArchivoLimpio(ARCHIVO_JUEGOS);
			system("pause");
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
			system("pause");
			system("cls");
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

		printf("1. Cargar una Categoria al archivo.\n");
		printf("2. Listado Categorias.\n");
		printf("3. Abrir archivo limpio.\n");
		printf("0. Volver al Menu Principal\n");
		printf("Ingrese una opcion\n>>> ");
		opcion = scanInt();

		switch (opcion)
		{
		case 1:
		{
			system("cls");
			formularioAltaCategoria();
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			mostrarListadoCategorias();
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			abrirArchivoLimpio(ARCHIVO_CATEGORIAS);
			system("pause");
			system("cls");
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
			system("pause");
			system("cls");
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
		printf("Ingrese una opcion\n >>> ");
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
			system("pause");
			system("cls");
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
			system("pause");
			system("cls");
			break;
		}
		}
	} while (opcion != 0);
}
