#define _CRT_SECURE_NO_WARNINGS

#include "../../multiusos/includesLibrerias.h"

int registrarNominacion(int idJuego, int idCategoria, Juego juegoDeseado, Categoria categoriaDeseada)
{
	FILE* fp = fopen(ARCHIVO_NOMINACIONES, "ab+");

	if (!fp)
	{
		return 0;
	}

	Nominacion nuevaNominacion;
	int idNominacion = generadorDeIdAutoIncremental(ARCHIVO_NOMINACIONES, sizeof(Nominacion));
	int puntaje = generarNumeroVotosNominacion();
	nuevaNominacion = crearNominacion(idNominacion, idJuego, idCategoria, puntaje, juegoDeseado, categoriaDeseada);

	fwrite(&nuevaNominacion, sizeof(Nominacion), 1, fp);

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
	/*
	Pila p;
	inicpila(&p);

	int juegosTotales = 0;

	Juego* listaJuegos = obtenerListadoJuegosDinamico(&juegosTotales);

	if (listaJuegos == NULL)
	{
		return p;
	}

	RankingJuego* ranking = (RankingJuego*)malloc(sizeof(RankingJuego) * juegosTotales);

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

		ranking[i].cantidad = contarNominacionesJuego(listaJuegos[i].idJuego);
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
	*/
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

int generarNumeroVotosNominacion()
{
	srand(time(NULL));
	int puntaje = (rand() % 10000) + 1;

	return puntaje;
}

void exportarNominacionesATexto(char rutaTexto[])
{
	FILE* fp = fopen(ARCHIVO_NOMINACIONES, "rb");
	if (fp == NULL)
	{
		return;
	}
	FILE* ft = fopen(rutaTexto, "w");
	if (ft == NULL)
	{
		fclose(fp);
		return;
	}
	Nominacion nominacion;

	while(fread(&nominacion, sizeof(Nominacion), 1 , fp) == 1)
	{
		if (nominacion.idNominacion == -1)
		{
			continue;
		}
		fprintf(ft, "%d, %d, %d, %d \n", nominacion.idNominacion, nominacion.idJuego, nominacion.idCategoria, nominacion.puntaje);
	}

	fclose(fp);
	fclose(ft);
}
void exportarNominacionesACsv(char rutaCSV[])
{
	FILE* fp = fopen(ARCHIVO_NOMINACIONES, "rb");
	if (fp == NULL)
	{
		return;
	}
	FILE* fc = fopen(rutaCSV, "w");
	if (fc == NULL)
	{
		fclose(fp);
		return;
	}
	Nominacion nominacion;
	while (fread(&nominacion, sizeof(Nominacion), 1, fp) == 1)
	{
		if (nominacion.idNominacion == -1)
		{
			continue;
		}
		fprintf(fc, "%d, %d, %d, %d \n", nominacion.idNominacion, nominacion.idJuego, nominacion.idCategoria, nominacion.puntaje);
		fclose(fp);
		fclose(fc);
	}
}