#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "gestorEventos.h"
#include <string.h>


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

int validarNombres(char nombre[])
{

	int valido;

	if(strlen(nombre) >= 1)
	{
		valido = 1;
	}
	else
	{
		valido = 0;
	}

	return valido;
}

int generadorDeIdAutoIncremental(char nombreArchivo[], size_t size)
{
	FILE* fp = fopen(nombreArchivo, "ab+");

	if (!fp)
	{
		return 0;
	}
	fseek(fp, 0, SEEK_END);

	int cantRegistros = ftell(fp) / size;

	fclose(fp);
	return cantRegistros + 1;
}