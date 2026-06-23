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

Pila obtenerRankingNominaciones(Pila p, Nominacion listaNominaciones[], int nominacionesTotales)
{

	if (nominacionesTotales == 0)
	{
		return p;
	}

	for (int i = 0; i < nominacionesTotales; i++)
	{
		apilar(&p, listaNominaciones[i].idNominacion);
	}

	Pila aux;
	inicpila(&aux);

	while (!pilavacia(&p))
	{
		apilar(&aux, desapilar(&p));
	}



	return aux;
	
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

	int puntaje = (rand() % 10000 + 1);

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
		if (aux.idJuego == idJuego)
		{
			contador++;
		}
	}

	fclose(fp); 
	return contador;
}

int conseguirPuntajeDeNominacion(int idNominacion)
{
	FILE* fp = fopen(ARCHIVO_NOMINACIONES, "rb");

	if (!fp)
	{
		return;
	}

	Nominacion aux;
	int puntaje = 0;
	while (fread(&aux, sizeof(Categoria), 1, fp) > 0)
	{
		if (aux.idNominacion == idNominacion && aux.esValido == 0)
		{
			puntaje = aux.puntaje;
		}
	}

	fclose(fp);
	return puntaje;
}

void mostrarNominacioneArchivo()
{
	FILE* fp = fopen(ARCHIVO_NOMINACIONES, "rb");

	if (!fp)
	{
		return;
	}

	Nominacion aux;

	while (fread(&aux, sizeof(Nominacion), 1, fp) > 0)
	{
		mostrarNominacion(aux);
	}

	fclose(fp);
}

int contarRegistrosArchivo(char nombreArchivo[], size_t size)
{
	FILE* fp = fopen(nombreArchivo, "rb");

	if (!fp)
	{
		return 0;
	}
	int cantRegistros = ftell(fp) / size;

	fclose(fp);
	return cantRegistros;
}

