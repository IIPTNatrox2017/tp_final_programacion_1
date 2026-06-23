#define _CRT_SECURE_NO_WARNINGS

#include "../../multiusos/includesLibrerias.h"

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
		if (lista[i].estaActivo && lista[i].catActiva)
		{
			mostrarJuego(lista[i]);
		}
	}

}
void mostrarListadoJuegosPorId(Juego* lista, int validos)
{
	if (validos <= 0)
	{
		printf("\nNo hay Juegos cargados!.\n");
		return;
	}

	ordenarJuegosPorId(lista, validos);

	printf("========== LISTADO DE JUEGOS ==========\n");

	for (int i = 0; i < validos; i++)
	{
		if (lista[i].estaActivo && lista[i].catActiva)
		{
			mostrarJuego(lista[i]);
		}
	}

}
void mostrarListadoJuegosDescativadosPorId(Juego* lista, int validos)
{
	if (validos <= 0)
	{
		printf("\nNo hay Juegos cargados!.\n");
		return;
	}

	ordenarJuegosPorId(lista, validos);

	printf("========== LISTADO DE JUEGOS INACTIVOS ==========\n");

	for (int i = 0; i < validos; i++)
	{
		if (lista[i].estaActivo == 0 && lista[i].catActiva == 1)
		{
			mostrarJuego(lista[i]);
		}
	}

}

void mostrarListadoCategorias(Categoria lista[], int validos)
{

	if(lista == NULL)
	{
		printf("\nNo hay categorias para mostrar.\n");
		return;
	}

	ordenarCategoriasAlfabeticamente(lista, validos);

	printf("========== LISTADO DE CATEGORIAS ==========\n");
	for(int i = 0; i < validos; i++)
	{
		if (lista[i].estaActiva == 1)
		{
			printf("[%d] ", i+1);
			mostrarCategoria(lista[i]);
		}
	}

}

void mostrarListadoCategoriasInactivas(Categoria lista[], int validos)
{
	if (lista == NULL)
	{
		printf("\nNo hay categorias para mostrar.\n");
		return;
	}

	ordenarCategoriasAlfabeticamente(lista, validos);

	printf("========== LISTADO DE CATEGORIAS INACTIVAS ==========\n");
	for (int i = 0; i < validos; i++)
	{
		if (lista[i].estaActiva == 0)
		{
			printf("[%d] ", i + 1);
			mostrarCategoria(lista[i]);
		}
	}

}

void mostrarRankingNominacionesUI()
{
	Pila rankings;
	inicpila(&rankings);

	rankings = obtenerRankingNominaciones();

	if (pilavacia(&rankings))
	{
		printf("\nNo hay nominaciones registradas.\n");
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
		srand(time(NULL));
		int idJuegoBuscado = desapilar(&rankings);
		char nombreJuego[50] = "";
		char estudioJuego[50] = "";

		for (int i = 0; i < juegosTotales; i++)
		{
			if (listaJuegos[i].idJuego == idJuegoBuscado)
			{
				strcpy(nombreJuego,
					listaJuegos[i].nombre);

				strcpy(estudioJuego,
					listaJuegos[i].estudio);

				break;
			}
		}
		int cantidad = contarNominacionesJuego(idJuegoBuscado);


		printf("\nNro Nominacion: [%d]", puesto);
		printf("\nJuego %s", nombreJuego);
		printf("\nEstudio: %s", estudioJuego);
		printf("\nCantidad Nominaciones %d\n", cantidad);
		
		printf("\n-------------------------\n");


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
	printf("categoria: %s\n",aux.categoria);
	printf("----------------------------------\n");
}

void mostrarNominacion(Nominacion aux)
{
	printf("ID: %d\n", aux.idNominacion);
	printf("FECHA LANZAMIENTO: ");
	printf("%d", aux.fecha.dia);
	printf("%d", aux.fecha.mes);
	printf("%d\n", aux.fecha.anio);
	printf("----------------------------------\n");
}

void mostrarCategoria(Categoria aux)
{
	printf(" -Nombre: %s\n", aux.nombre);
	printf("----------------------------------\n");
}