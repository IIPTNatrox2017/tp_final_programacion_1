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

	int cantNominaciones = 0;
	Nominacion* listaNominaciones = obtenerListadoNominacionesDinamico(&cantNominaciones);
	rankings = obtenerRankingNominaciones(rankings, listaNominaciones, cantNominaciones);

	if (pilavacia(&rankings))
	{
		printf("\nNo hay nominaciones registradas.\n");
		return;
	}

	while (!pilavacia(&rankings))
	{
		
		int idNominacion = desapilar(&rankings);

		for (int i = 0; i < cantNominaciones; i++)
		{
			if (listaNominaciones[i].idNominacion == idNominacion)
			{
				mostrarUnaNominacion(listaNominaciones[i].idNominacion, listaNominaciones[i].juego.nombre, listaNominaciones[i].juego.estudio, listaNominaciones[i].puntaje);
			}
		}
		
	}

	free(listaNominaciones);
}

void mostrarUnaNominacion(int puesto, char nombreJuego[], char estudioJuego[], int puntaje)
{
	printf("NOMINACION\n");
	printf("\nNro Nominacion: [%d]\n", puesto);
	printf("\nJuego %s", nombreJuego);
	printf("\nEstudio: %s", estudioJuego);
	printf("\nCantidad Nominaciones %d\n", puntaje);
	printf("\n-------------------------\n");
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
	int ancho = 75;
	char renglonId[100];
	char renglonNombre[150];
	char renglonEstudio[150];
	char renglonCategoria[150];

	sprintf(renglonId, "ID: %d", aux.idJuego);
	sprintf(renglonNombre, "Nombre: %s", aux.nombre);
	sprintf(renglonEstudio, "Estudio: %s", aux.estudio);
	sprintf(renglonCategoria, "Categoria: %s", aux.categoria);

	printf("+");
	for (int i = 0; i < ancho; i++)
	{
		printf("=");
	}
	printf("+\n");

	printf("| %-*s |\n", ancho - 2, renglonId);
	printf("| %-*s |\n", ancho - 2, renglonNombre);
	printf("| %-*s |\n", ancho - 2, renglonEstudio);
	printf("| %-*s |\n", ancho - 2, renglonCategoria);

	printf("+");
	for (int i = 0; i < ancho; i++)
	{
		printf("=");
	}
	printf("+\n");
}


void mostrarNominacion(Nominacion aux)
{
	printf("ID: %d\n", aux.idNominacion);
	printf("Nombre Juego: %s\n", aux.juego.nombre);
	printf("Estudio: %s\n", aux.categoria.nombre);
	printf("Cantidad de Votos: %d\n", aux.puntaje);
	printf("----------------------------------\n");
}

void mostrarCategoria(Categoria aux)
{
	printf(" -Nombre: %s\n", aux.nombre);
	printf("----------------------------------\n");
}

Nominacion* obtenerListadoNominacionesDinamico(int* validos)
{

	FILE* fp = fopen(ARCHIVO_NOMINACIONES, "rb");

	if (fp == NULL)
	{
		*validos = 0;
		return NULL;
	}
	
	fseek(fp, 0, SEEK_END);
	int totalRegistros = ftell(fp) / sizeof(Nominacion);
	rewind(fp);

	if (totalRegistros <= 0)
	{
		fclose(fp);
		*validos = 0;
		return NULL;
	}
	Nominacion* arregloNominaciones = (Nominacion*)malloc(totalRegistros * sizeof(Nominacion));

	if (arregloNominaciones == NULL)
	{
		fclose(fp);
		*validos = 0;
		return NULL;
	}

	fread(arregloNominaciones, sizeof(Juego), totalRegistros, fp);

	fclose(fp);

	*validos = totalRegistros;

	return arregloNominaciones;
}
