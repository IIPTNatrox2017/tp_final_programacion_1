#define _CRT_SECURE_NO_WARNINGS
#include "../cabeceraEntidades/logicaNominaciones.h"
#include "../../DOMINIO/cabeceraEntidades/nominaciones.h"
#include "../../SERVICIO/cabeceraEntidades/logicaJuego.h"
#include "../cabeceraEntidades/logicaCategoria.h"
#include <stdio.h>
#include <stdlib.h>

#define ARCHIVO_NOMINACIONES "nominaciones.bin"

int registrarNominacion(int idJuego, int idCategoria, int puntajeValor, int d, int m, int a)
{
	if (buscarJuegoPorId(idJuego) == -1)
	{
		return -3;
	}

	if (buscarCategoriaPorId(idCategoria) == -1)
	{
		return -4;
	}

	if (existeNominacionDuplicada(idJuego, idCategoria))
	{
		return -2;
	}
	Puntaje nuevoPuntaje = crearPuntaje(puntajeValor);

	if (!nuevoPuntaje.esValido)
	{
		return -5;
	}

	FechaLanzamiento nuevaFecha = crearFecha(d, m, a);

	if (!nuevaFecha.esValido)
	{
		return -6;
	}

	FILE* fp = fopen(ARCHIVO_NOMINACIONES, "ab");

	if (!fp)
	{
		return 0;
	}

	fseek(fp, 0, SEEK_END);

	int idNominacion = obtenerMayorIdNominacion() + 1;

	Nominacion nuevaNominacion = crearNominacion(idNominacion, idJuego, idCategoria, nuevoPuntaje, nuevaFecha);

	if (fwrite(&nuevaNominacion, sizeof(Nominacion), 1, fp) != 1)
	{
		fclose(fp);
		return 0;
	}

	fclose(fp);
	return 1;
}
int existeNominacionDuplicada(int idJuego, int idCategoria)
{
	FILE* fp = fopen(ARCHIVO_NOMINACIONES, "rb");

	Nominacion nominacion;
	int nominacionEncontrada = 0;

	if(!fp)
	{
		return 0;
	}

	while (fread(&nominacion, sizeof(Nominacion), 1, fp) > 0)
	{
		if(nominacion.idJuego == idJuego && nominacion.idCategoria == idCategoria)
		{
			nominacionEncontrada = 1;
		}
	}
	fclose(fp);
	return nominacionEncontrada;
}

Pila obtenerRankingNominaciones()
{
	FILE* fp = fopen(ARCHIVO_NOMINACIONES, "rb");

	Pila p;
	inicpila(&p);

	if (fp == NULL)
	{
		return p;
	}

	fseek(fp, 0, SEEK_END);
	int total = ftell(fp) / sizeof(Nominacion);

	if (total == 0)
	{
		fclose(fp);
		return p;
	}

	
	Nominacion* arreglo = (Nominacion*)malloc(total * sizeof(Nominacion));
	fseek(fp, 0, SEEK_SET);
	fread(arreglo, sizeof(Nominacion), total, fp);
	fclose(fp); 

	int i, j, posMin;
	for (i = 0; i < total - 1; i++)
	{
		posMin = i;
		for (j = i + 1; j < total; j++)
		{
			
			if (arreglo[j].puntaje.valor < arreglo[posMin].puntaje.valor)
			{
				posMin = j;
			}
		}
		if (posMin != i)
		{
			Nominacion aux = arreglo[i];
			arreglo[i] = arreglo[posMin];
			arreglo[posMin] = aux;
		}
	}

	for (i = 0; i < total; i++)
	{
		apilar(&p, arreglo[i].idJuego);
	}

	
	free(arreglo);

	return p; 
}

void exportarNominacionesATexto(char rutaTexto[])
{
	FILE *fp = fopen(ARCHIVO_NOMINACIONES, "rb");

	FILE* fTxt = fopen(rutaTexto, "w");

	Nominacion nominacion;

	if (fp != NULL && fTxt != NULL)
	{
		fprintf(fTxt, "========================================================\n");
		fprintf(fTxt, "ID Nominacion | ID Juego | ID Categoria | Puntaje | Fecha \n");
		fprintf(fTxt, "========================================================\n");
	}
	while(fread(&nominacion, sizeof(Nominacion), 1 , fp)> 0)
	{
		fprintf(fTxt, "%d | %d | %02d/%02d/%04d\n", nominacion.idNominacion, nominacion.idJuego, nominacion.idCategoria, nominacion.puntaje.valor, nominacion.fecha.dia, nominacion.fecha.mes, nominacion.fecha.anio);
	}

	fclose(fp);
	fclose(fTxt);
}

int obtenerMayorIdNominacion(void)
{
	FILE* fp = fopen(ARCHIVO_NOMINACIONES, "rb");

	if (!fp)
	{
		return 0;
	}

	Nominacion aux;

	int mayor = 0;

	while (fread(&aux, sizeof(Nominacion), 1, fp) > 0)
	{
		if (aux.idNominacion > mayor)
		{
			mayor = aux.idNominacion;
		}
	}

	fclose(fp);

	return mayor;
}

int modificarNominacion(int idNominacion, int nuevoPuntaje, int d, int m, int a)

{
	FILE* fp = fopen(ARCHIVO_NOMINACIONES, "rb+");

	if (!fp)
	{
		return 0;
	}

	Nominacion aux;
	int exito = -1;

	while (fread(&aux, sizeof(Nominacion), 1, fp) > 0 && exito == -1)
	{
		if (aux.idNominacion == idNominacion)
		{
			aux.puntaje = crearPuntaje(nuevoPuntaje);
			aux.fecha = crearFecha(d, m, a);

			fseek(fp, sizeof(Nominacion), SEEK_CUR);

			fwrite(&aux, sizeof(Nominacion), 1, fp);

			exito = 1;
		}
	}

	fclose(fp);

	return exito;
}
