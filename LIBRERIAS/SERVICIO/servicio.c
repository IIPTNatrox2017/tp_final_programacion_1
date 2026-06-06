#define _CRT_SECURE_NO_WARNINGS
#include "servicio.h"
#include <stdio.h>
#include <stdlib.h>
#include "../DOMINIO/cabeceraEntidades/nominaciones.h"
#include "../INTERFAZ_DE_USUARIO/menus.h"

void mostrarGOTYS(char nombreArchivo[])
{
	FILE* fp;
	fp = fopen(nombreArchivo, "rb");

	if (!fp)
	{
		printf("Error no se pudo abrir el archivo.\n");
		return;
	}

	Nominacion aux;

	while (fread(&aux, sizeof(Nominacion), 1, fp)>0)
	{
		mostrarunaNominacion(aux);
	}


	fclose(fp);
}

void darDeAltaUnaNominacion(char nombreArchivo[], Nominacion registroDeseado)
{
	FILE* fp = fopen(nombreArchivo, "rb+");

	if (!fp)
	{
		printf("Error al intentar abrir archivo.\n");
		return;
	}

	fseek(fp, 0, SEEK_SET);

	Nominacion aux;

	while (fread(&aux, sizeof(Nominacion), 1, fp) > 0)
	{
		if (aux.juego.idJuego == registroDeseado.juego.idJuego)
		{

		}
	}


	fclose(fp);
}

