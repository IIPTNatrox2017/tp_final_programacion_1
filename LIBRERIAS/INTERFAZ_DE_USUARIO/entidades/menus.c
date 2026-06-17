#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include "../../DOMINIO/cabeceraEntidades/nominaciones.h"
#include "../cabeceraEntidades/menus.h"
#include <stdio.h>
#include "../../Librerias Externas/scanner.h"
#include "../cabeceraEntidades/interfazEntrada.h"

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
	printf("=====MENU PRINCIPAL=====\n");
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
			printf("\n=====MENU JUEGOS=====\n");
			subMenuJuegos();
			formularioAltaJuego();
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			printf("\n=====MENU CATEGORIAS=====\n");
			subMenuCategorias();
			
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			printf("\n=====MENU NOMINACIONES=====\n");
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
	printf("Todavia no se implemento esta funcion.\n");

}

void subMenuCategorias()
{
	printf("Todavia no se implemento esta funcion.\n");
}

void subMenuNominaciones()
{
	printf("Todavia no se implemento esta funcion.\n");
}
