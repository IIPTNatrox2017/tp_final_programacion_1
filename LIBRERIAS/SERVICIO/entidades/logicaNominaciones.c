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
	Pila p;
	inicpila(&p);

	int juegosTotales = 0;

	Juego* listaJuegos =
		obtenerListadoJuegosDinamico(&juegosTotales);

	if (listaJuegos == NULL)
	{
		return p;
	}

	RankingJuego* ranking =
		(RankingJuego*)malloc(sizeof(RankingJuego) * juegosTotales);

	if (ranking == NULL)
	{
		free(listaJuegos);
		return p;
	}

	int i;
	int j;

	for (i = 0; i < juegosTotales; i++)
	{
		ranking[i].idJuego = listaJuegos[i].idJuego;

		ranking[i].cantidad =
			contarNominacionesJuego(listaJuegos[i].idJuego);
	}

	RankingJuego aux;

	for (i = 0; i < juegosTotales - 1; i++)
	{
		for (j = i + 1; j < juegosTotales; j++)
		{
			if (ranking[j].cantidad >
				ranking[i].cantidad)
			{
				aux = ranking[i];
				ranking[i] = ranking[j];
				ranking[j] = aux;
			}
		}
	}

	for (i = juegosTotales - 1; i >= 0; i--)
	{
		apilar(&p, ranking[i].idJuego);
	}

	free(ranking);
	free(listaJuegos);

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

int bajaNominacion(int idNominacion)
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
			aux.idNominacion = -1;

			fseek(fp, sizeof(Nominacion), SEEK_CUR);

			fwrite(&aux, sizeof(Nominacion), 1, fp);

			exito = 1;
		}
	}

	fclose(fp);

	return exito;
}

void mostrarNominacionesPorCategoria(int idCategoria)
{
	FILE* fp = fopen(ARCHIVO_NOMINACIONES, "rb");

	if (!fp)
	{
		return;
	}

	Nominacion aux;

	while (fread(&aux, sizeof(Nominacion), 1, fp) > 0)
	{
		if (aux.idCategoria == idCategoria)
		{
			mostrarNominacion(aux);
		}
	}

	fclose(fp);
}

int contarNominacionesJuego(int idJuego)
{
	FILE* fp = fopen(ARCHIVO_NOMINACIONES, "rb");

	if (fp == NULL)
	{
		return 0;
	}

	Nominacion aux;
	int contador = 0;

	while (fread(&aux, sizeof(Nominacion), 1, fp) > 0)
	{
		if (aux.idNominacion != -1 &&
			aux.idJuego == idJuego)
		{
			contador++;
		}
	}

	fclose(fp);

	return contador;
}