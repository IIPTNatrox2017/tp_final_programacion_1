#define _CRT_SECURE_NO_WARNINGS

#include "../../multiusos/includesLibrerias.h"

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
		opcion = pedirOpcion("Seleccione una opcion:");
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
 
int pedirOpcion(char string[])
{
	int opcion;

	printf("%s ", string);

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
		mostrarSubMenuJuegos();
		opcion = pedirOpcion("Seleccione una opcion: ");
		ejecutarOpcionSubMenuJuegos(opcion);
	} while (opcion != 0);
}

void mostrarSubMenuJuegos()
{
	system("cls");
	printf("===========================\n");
	printf("      MENU JUEGOS\n");
	printf("===========================\n");

	printf("1. Cargar un juego al archivo.\n");
	printf("2. Listado de Juegos Alfabaticamente (A-Z)\n");
	printf("3. Ordenar juegos por ID.\n");
	printf("4. Vaciar Archivo juegos.\n");
	printf("5. Modificar Juego.\n");
	printf("6. Dar de Baja un Juego.\n");
	printf("7. Reactivar Un Juego.\n");
	printf("0. Volver al Menu Principal\n");
}

void ejecutarOpcionSubMenuJuegos(int opcion)
{
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
			system("cls");
			mostrarListadoJuegos();
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			int validos = 0;
			Juego* juegos = obtenerListadoJuegosDinamico(&validos);
			mostrarListadoJuegosPorId(juegos, validos);
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
		case 5:
		{
			system("cls");
			modificarJuegoArchivo();
			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			ejecutarDarDeBajaUnJuego();
			system("pause");
			break;
		}
		case 7:
		{
			system("cls");
			ejecutarReactivarUnJuego();
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

void subMenuModificarJuego()
{
	printf("===========================\n");
	printf("      OPCIONES JUEGO\n");
	printf("===========================\n");

	printf("1. Modificar Nombre.\n");
	printf("2. Modificar Estudio.\n");
	printf("3. Modificar Categoria.\n");
}


void subMenuCategorias()
{
	int opcion;
	do
	{
		mostrarSubMenuCategorias();
		opcion = pedirOpcion("Seleccione una opcion: ");
		ejecutarOpcionSubMenuCategorias(opcion);
	} while (opcion != 0);
}

void mostrarSubMenuCategorias()
{
	system("cls");
	printf("===========================\n");
	printf("      MENU CATEGORIAS\n");
	printf("===========================\n");

	printf("1. Cargar una Categoria al archivo.\n");
	printf("2. Listado Categorias.\n");
	printf("3. Abrir archivo limpio.\n");
	printf("4. Modificar Categoria.\n");
	printf("5. Dar de baja una Categoria.\n");
	printf("6. Reactivar una Categoria.\n");
	printf("0. Volver al Menu Principal\n");
}

void ejecutarOpcionSubMenuCategorias(int opcion)
{
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
			int validos = 0;
			Categoria* lista = obtenerListadoCategoriasDinamico(&validos);
			mostrarListadoCategorias(lista, validos);
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
		case 4:
		{
			system("cls");
			modificarCategoriaArchivo();
			break;
		}
		case 5:
		{
			system("cls");
			ejecutarDarDeBajaUnaCategoria();
			break;
		}
		case 6:
		{
			system("cls");
			ejecutarReactivarUnaCategoria();
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

void subMenuNominaciones()
{
	int opcion;
	do
	{
		mostrarSubMenuNominaciones();
		opcion = pedirOpcion("Seleccione una opcion: ");
		ejecutarOpcionSubMenuNominaciones(opcion);
	} while (opcion != 0);
}

void mostrarSubMenuNominaciones()
{
	system("cls");
	printf("===========================\n");
	printf("      MENU NOMINACIONES\n");
	printf("===========================\n");

	printf("1. Registrar Nominacion.\n");
	printf("2. Ranking Nominaciones.\n");
	printf("0. Volver al Menu Principal\n");
}

void ejecutarOpcionSubMenuNominaciones(int opcion)
{
	switch (opcion)
	{
		case 1:
		{
			system("cls");
			formularioRegistrarNominacion();
			system("pause");
			system("cls");
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
		case 3:
		{
			system("cls");
			abrirArchivoLimpio(ARCHIVO_NOMINACIONES);
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
}

void menuPuestosPila(int puesto, char nombreJuego[], char estudioJuego[])
{
	printf(" %d PUESTO: %s\n", puesto, nombreJuego);
	printf("    ESTUDIO: %s\n,", estudioJuego);
	printf("\n------------------------------------\n");
}

void menuCategoriasDisponibles(Categoria categorias[], int cantCategorias)
{
	printf("============================================\n");
	printf("\t--CATEGORIAS--\t\n");
	printf("============================================\n");
	for (int i = 0; i < cantCategorias; i++)
	{
		printf(" -[%d] [%s]", i + 1, categorias[i].nombre);
		if (i % 2 != 0)
		{
			printf("\n");
		}
	}
}
