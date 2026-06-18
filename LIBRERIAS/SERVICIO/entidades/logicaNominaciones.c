#define _CRT_SECURE_NO_WARNINGS
#include "../cabeceraEntidades/logicaNominaciones.h"
#include "../../DOMINIO/cabeceraEntidades/nominaciones.h"
#include <stdio.h>
#include <stdlib.h>

#define ARCHIVO_NOMINACIONES "nominaciones.bin"

int registrarNominacion(int puntajeValor, int d, int m, int a)
{
	FILE *fp = fopen(ARCHIVO_NOMINACIONES, "rb");

	Nominacion nominacion;

	if(fp != NULL)
    {
		while(fread(&nominacion, sizeof(Nominacion), 1, fp) > 0)
		{
			if(existeNominacionDuplicada(idJuego))
			{
				return -2;
			}
		}
	}
	fclose(fp);
	return 0;
}
int existeNominacionDuplicada(int idJuego, int idCategoria)
{
	FILE* fp = fopen(ARCHIVO_NOMINACIONES, "rb");

	Nominacion nominacion;
	int nominacionEncontrada = 0;

	if(fp != NULL)
	{
		while (fread(&nominacion, sizeof(Nominacion), 1, fp) > 0)
		{
			if(idJuego == idJuego && nominacion.idCategoria == idCategoria)
			{
				nominacionEncontrada = 1;
			}
		}
	}
	fclose(fp);
	return nominacionEncontrada;
}
Pila obtenerRankingNominaciones()
{
	FILE* fp = fopen(ARCHIVO_NOMINACIONES, "rb");

	Nominacion nominacion;
	Pila p;
	inicpila(&p);
	int mayorPuntaje = 0;

	if (fp != NULL)
	{
		while (fread(&nominacion, sizeof(Nominacion), 1, fp) > 0)
		{
			if (nominacion.puntaje.valor > mayorPuntaje)
			{
				mayorPuntaje = nominacion.puntaje.valor;
				apilar(&p, mayorPuntaje);
			}
		}
	}
	fclose(fp);
	return p;
}
void exportarNominacionesATexto(char rutaTexto[])
{
	FILE *fp = fopen(ARCHIVO_NOMINACIONES, "rb");

	FILE* fTxt = fopen("nominaciones.txt", "w");

	Nominacion nominacion;

	if (fp != NULL && fTxt != NULL)
	{
		fprintf(fTxt, "ID Nominacion | Puntaje | Fecha Lanzamiento\n");
	}
	while(fread(&nominacion, sizeof(Nominacion), 1 , fp)> 0)
	{
		fprintf(fTxt, "%d | %d | %02d/%02d/%04d\n", nominacion.idNominacion, nominacion.puntaje.valor, nominacion.fecha.dia, nominacion.fecha.mes, nominacion.fecha.anio);
	}
	fclose(fp);
	fclose(fTxt);
}