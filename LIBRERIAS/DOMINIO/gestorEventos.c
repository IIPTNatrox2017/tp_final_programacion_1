#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "gestorEventos.h"

#define DIM_MAX_NOMBRES 50


void abrirArchivoLimpio(char nombreArchivo[])
{
	FILE* fp;
	fp = fopen(nombreArchivo, "wb");

	if (!fp)
	{
		printf("Error, no se logro abrir el archivo.\n");
		return;
	}

	printf("El archivo se creo y/o abrio vacio.\n");

	fclose(fp);
}

