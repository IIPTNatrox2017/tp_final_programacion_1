#define _CRT_SECURE_NO_WARNINGS
#include "../cabeceraEntidades/logicaNominaciones.h"
#include <stdio.h>
#include <stdlib.h>

#define ARCHIVO_NOMINACIONES "nominaciones.bin"

int registrarNominacion(int puntajeValor, int d, int m, int a)
{
	FILE *fp = fopen(ARCHIVO_NOMINACIONES, "rb");

	if(existeNominacionDuplicada(idJuego, idCategoria))
    {
		return -2;
	}
	{
		fclose(fp);
		return 0;
	}
	printf("funcion no implementada\n");
	return 0;
}
int existeNominacionDuplicada(int idJuego, int idCategoria)
{
	FILE* fp = fopen(ARCHIVO_NOMINACIONES, "rb");

	Nominacion nominacion;

	if(fp != NULL)
	{
		while (fread());
	}


	printf("funcion no implementada\n");
	return 0;
}
Pila obtenerRankingNominaciones()
{
	printf("funcion no implementada\n");
	Pila p;
	inicpila(&p);
	return p;
}
void exportarNominacionesATexto(char rutaTexto[])
{
	printf("funcion no implementada\n");
}

