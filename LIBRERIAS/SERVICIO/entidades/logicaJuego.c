#define _CRT_SECURE_NO_WARNINGS

#include "../../multiusos/includesLibrerias.h"


int cargarNuevoJuego(char nombre[], char estudio[], int idCategoria) 
{
	int idJuego = generadorDeIdAutoIncremental(ARCHIVO_JUEGOS, sizeof(Juego));
	FILE* fp;
	fp = fopen(ARCHIVO_JUEGOS, "ab+");

	if (!fp)
	{
		return 0;
	}

	Juego nuevoJuego;

	char categoria[50] = { 0 };

	nuevoJuego = crearJuego(idJuego, nombre, estudio, categoria);

	cargarCategoriaAjuego(idCategoria, &nuevoJuego);

	fwrite(&nuevoJuego, sizeof(Juego), 1, fp);

	fclose(fp);
	
	return 1;
}

void cargarCategoriaAjuego(int idCategoria, Juego* juego)
{
	FILE* fp = fopen(ARCHIVO_CATEGORIAS, "rb");

	if (!fp)
	{
		return;
	}

	Categoria auxCategoria;

	while (fread(&auxCategoria, sizeof(Categoria), 1, fp) > 0)
	{
		if (auxCategoria.idCategoria == idCategoria)
		{
			strcpy(juego->categoria, auxCategoria.nombre);
		}
	}
	fclose(fp);
}



Juego* obtenerListadoJuegosDinamico(int* validos)
{
	FILE* fp = fopen(ARCHIVO_JUEGOS, "rb");

	if (fp == NULL)
	{
		*validos = 0;
		return NULL;
	}

	fseek(fp, 0, SEEK_END);

	int totalRegistros = ftell(fp) / sizeof(Juego);

	rewind(fp);

	if (totalRegistros <= 0)
	{
		fclose(fp);
		*validos = 0;
		return NULL;
	}
	Juego* arregloJuegos = (Juego*) malloc(totalRegistros * sizeof(Juego));

	if (arregloJuegos == NULL)
	{
		fclose(fp);
		*validos = 0;
		return NULL;
	}

	fread(arregloJuegos, sizeof(Juego), totalRegistros, fp);

	fclose(fp);

	*validos = totalRegistros;

	return arregloJuegos;
}

Juego* buscarJuegoPorId(int id)
{
	FILE* fp = fopen(ARCHIVO_JUEGOS, "rb");

	if (fp == NULL)
	{
		return NULL;
	}
	
	int idDeseada = 0;

	Juego juego;

	while(fread(&juego, sizeof(juego), 1, fp) > 0)
	{
		if (juego.idJuego == id && juego.estaActivo)
		{
			fclose(fp);
			return &juego;
		}
	}

	fclose(fp);
	return NULL;

}

void darDeBajaJuego(int id)
{
	FILE* fp = fopen(ARCHIVO_JUEGOS, "r+b");

	if (!fp)
	{
		return ;
	}

	Juego aux;
	int encontrado = 0;

	while (encontrado == 0 && fread(&aux, sizeof(Juego), 1, fp) > 0)
	{
		if (aux.idJuego == id && aux.estaActivo)
		{
			aux.estaActivo = 0;
			fseek(fp, sizeof(Juego) * (-1), SEEK_CUR);
			fwrite(&aux, sizeof(Juego), 1, fp);
			fseek(fp, 0, SEEK_CUR);
			encontrado = 1;
		}
	}

	fclose(fp);
}

void reactivarUnJuego(int idJuego)
{
	FILE* fp = fopen(ARCHIVO_JUEGOS, "r+b");

	if (!fp)
	{
		return;
	}

	Juego aux;
	int encontrado = 0;

	while (encontrado == 0 && fread(&aux, sizeof(Juego), 1, fp) > 0)
	{
		if (aux.idJuego == idJuego && aux.estaActivo == 0)
		{
			aux.estaActivo = 1;
			encontrado = 1;
			fseek(fp, sizeof(Juego) * (-1), SEEK_CUR);
			fwrite(&aux, sizeof(Juego), 1, fp);
			fseek(fp, 0, SEEK_CUR);
		}
	}

	fclose(fp);
}

void ordenarJuegosAlfabeticamente(Juego arreglo[], int validos)
{
	if (arreglo == NULL || validos <= 1)
	{
		return;
	}
	int i, j, indice;

	Juego temporal;

	for (i = 0; i < validos - 1; i++)
	{
		indice = i;
		for(j = i + 1; j < validos; j++)
		{
			if (compararJuegosPorNombre(arreglo[j], arreglo[indice]) < 0)
			{
				indice = j;
			}
		}
		if(indice != i)
		{
			temporal = arreglo[i];
			arreglo[i] = arreglo[indice];
			arreglo[indice] = temporal;
		}
	}
}

void ordenarJuegosPorId(Juego arreglo[], int validos)
{
	if (arreglo == NULL || validos <= 1)
	{
		return;
	}
	int i, j, indice;

	Juego temporal;

	for (i = 0; i < validos - 1; i++)
	{
		indice = i;
		for (j = i + 1; j < validos; j++)
		{
			if (compararJuegosPorId(arreglo[j], arreglo[indice]) < 0)
			{
				indice = j;
			}
		}
		if (indice != i)
		{
			temporal = arreglo[i];
			arreglo[i] = arreglo[indice];
			arreglo[indice] = temporal;
		}
	}
}
void exportarJuegosATexto(char rutaTexto[])
{
	FILE* fb = fopen(ARCHIVO_JUEGOS, "rb");
	if(fb == NULL)
	{
		
		return;
	}
	FILE* ft = fopen(rutaTexto, "w");
	if (ft == NULL)
	{
		fclose(fb);
		return;
	}
	Juego juego;
	while (fread(&juego, sizeof(Juego), 1, fb) == 1)
	{
		if (juego.idJuego == -1)
		{
			continue;
		}
		
		fprintf(ft, "ID: %d\nNombre: %s\nEstudio: %s\ncategoria: %s\n\n", juego.idJuego, juego.nombre, juego.estudio, juego.categoria);
		
	}
	fclose(fb);
	fclose(ft);
	
}

void modificarJuegoPorNombre(int idJuego, char nombre[])
{
	FILE* fp = fopen(ARCHIVO_JUEGOS, "r+b");

	if (!fp)
	{
		return;
	}
	Juego juegoAux;

	int encontrado = 0;
	

	while (encontrado == 0 && fread(&juegoAux, sizeof(Juego), 1, fp) > 0)
	{
		if (juegoAux.idJuego == idJuego)
		{
			modificarNombreJuego(&juegoAux, nombre);
			fseek(fp, -1 * sizeof(Juego), SEEK_CUR);
			fwrite(&juegoAux, sizeof(Juego), 1, fp);
			fseek(fp, 0, SEEK_CUR);
			encontrado = 1;
		}
	}
	fclose(fp);
}

void modificarJuegoPorEstudio(int idJuego, char estudio[])
{
	FILE* fp = fopen(ARCHIVO_JUEGOS, "rb+");

	if (!fp)
	{
		return;
	}

	Juego juegoAux;
	int encontrado = 0;

	while (encontrado == 0 && fread(&juegoAux, sizeof(Juego), 1, fp) > 0)
	{
		if (juegoAux.idJuego == idJuego)
		{
			modificarEstudioJuego(&juegoAux, estudio);
			fseek(fp, sizeof(Juego) * (-1), SEEK_CUR);
			fwrite(&juegoAux, sizeof(Juego), 1, fp);
			fseek(fp, 0, SEEK_CUR);
			encontrado = 1;

		}
	}
	fclose(fp);
}

void modificarJuegoPorCategoria(int idJuego, char nombreCategoria[])
{
	FILE* fp = fopen(ARCHIVO_JUEGOS, "rb+");

	if (!fp)
	{
		return;
	}

	Juego auxJuego;
	int encontrado = 0;
	
	while (encontrado == 0 && fread(&auxJuego, sizeof(Juego), 1, fp) > 0)
	{
		if (auxJuego.idJuego == idJuego)
		{
			strcpy(auxJuego.categoria, nombreCategoria);
			fseek(fp, (long)sizeof(Juego) * (-1), SEEK_CUR);
			fwrite(&auxJuego, sizeof(Juego), 1, fp);
			encontrado = 1;
		}
	}

	fclose(fp);
	
}

int verificarNombreJuegoNuevo(char nombreNuevo[])
{
	FILE* fp = fopen(ARCHIVO_JUEGOS, "rb");

	if (!fp)
	{
		return 0;
	}

	Juego aux;
	int encontrado = 0;
	int nombreRepetido = 0;

	while (encontrado == 0 && fread(&aux, sizeof(Juego), 1, fp) > 0)
	{
		if (_strcmpi(aux.nombre, nombreNuevo) == 0 && aux.estaActivo == 1)
		{
			nombreRepetido = 1;
			encontrado = 1;
		}
	}

	fclose(fp);
	return nombreRepetido;
}