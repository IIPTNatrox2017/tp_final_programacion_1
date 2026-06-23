#define _CRT_SECURE_NO_WARNINGS

#include "../../multiusos/includesLibrerias.h"


int cargarNuevaCategoria(char nombre[])
{
	FILE* fp = fopen(ARCHIVO_CATEGORIAS, "ab");

	if (!fp)
	{
		printf("ERROR! No se pudo abrir el archivo de categorías.\n");
		return 0;
	}
	
	int nuevoId = generadorDeIdAutoIncremental(ARCHIVO_CATEGORIAS, sizeof(Categoria));

	Categoria nueva = crearCategoria(nuevoId, nombre);
	
	fwrite(&nueva, sizeof(Categoria), 1, fp);

	fclose(fp);

	return 1;
}
int buscarCategoriaPorId(int id)
{
	FILE* fp = fopen(ARCHIVO_CATEGORIAS, "rb");
	if (!fp)
	{
		printf("ERROR! No se pudo abrir el archivo de categorías.\n");
		return -1;
	}

	int pos = 0;
	Categoria aux;
	while(fread(&aux, sizeof(Categoria), 1, fp))
	{ 
		if (aux.idCategoria == id)
		{
			fclose(fp);
			return pos;
		}
		pos++;
	}
	fclose(fp);
	return -1;
}

void ordenarCategoriasAlfabeticamente(Categoria arreglo[], int validos)
{
	int posMenor;
	Categoria aux;

	for(int i = 0; i < validos - 1; i++)
	{ 
		posMenor = i;
		
		for(int j = i + 1; j < validos; j++)
		{
			if (strcmp(arreglo[j].nombre, arreglo[posMenor].nombre) < 0)
			{
				posMenor = j;
			}
		}
		if (posMenor != i)
		{
			aux = arreglo[i];
			arreglo[i] = arreglo[posMenor];
			arreglo[posMenor] = aux;
		}
	}
}

void exportarCategoriasATexto(char rutaTexto[])
{
	Categoria aux;
	FILE* fp = fopen(ARCHIVO_CATEGORIAS, "rb");
	if(!fp)
	{ 
		return;
	}
	FILE* ft = fopen(rutaTexto, "w");
	if(ft == NULL)
	{ 
		fclose(fp);
		return;
	}
	while (fread(&aux, sizeof(Categoria), 1, fp) == 1)
	{
		fprintf(ft, "ID: %d, Nombre: %s\n", aux.idCategoria, aux.nombre);
	}
	fclose(fp);
	fclose(ft);
}

Categoria* obtenerListadoCategoriasDinamico(int* validos)
{
	FILE* fp = fopen (ARCHIVO_CATEGORIAS, "rb");

	if (!fp)
	{
		*validos = 0;
		return 0;
	}
	int indice;

	Categoria* arregloCategorias;

	fseek(fp, 0, SEEK_END);

	*validos = ftell(fp) / sizeof(Categoria);

	arregloCategorias = (Categoria*)malloc((*validos) * sizeof(Categoria));
	if (arregloCategorias == NULL)
	{
		fclose(fp);
		*validos = 0;
		return NULL;
	}

	fseek(fp, 0, SEEK_SET);

	for (indice = 0; indice < *validos; indice++)
	{
		fread(&arregloCategorias[indice], sizeof(Categoria), 1, fp);
	}

	fclose(fp);

	return arregloCategorias;
}

void darDeBajaCategoria(int idCategoria)
{
	FILE* fp = fopen(ARCHIVO_CATEGORIAS, "r+b");

	if (!fp)
	{
		return 0;
	}

	Categoria aux;
	int encontrado = 0;

	while (encontrado == 0 && fread(&aux, sizeof(Categoria), 1, fp) > 0)
	{
		if (aux.idCategoria == idCategoria && aux.estaActiva)
		{
			aux.estaActiva = 0;

			fseek(fp, sizeof(Categoria) * -1, SEEK_CUR);
			fwrite(&aux, sizeof(Categoria), 1, fp);
			fseek(fp,0 , SEEK_CUR);
			encontrado = 1;
		}
	}

	fclose(fp);
}

void reactivarCategoria(int idCategoria)
{
	FILE* fp = fopen(ARCHIVO_CATEGORIAS, "r+b");

	if (!fp)
	{
		return 0;
	}

	Categoria aux;
	int encontrado = 0;

	while (encontrado == 0 && fread(&aux, sizeof(Categoria), 1, fp) > 0)
	{
		if (aux.idCategoria == idCategoria && aux.estaActiva == 0)
		{
			aux.estaActiva = 1;

			fseek(fp, sizeof(Categoria) * -1, SEEK_CUR);
			fwrite(&aux, sizeof(Categoria), 1, fp);
			fseek(fp, 0, SEEK_CUR);
			encontrado = 1;
		}
	}

	fclose(fp);
}


void modificarCategoria(int idCategoria, char nuevoNombre[])
{
	FILE* fp = fopen(ARCHIVO_CATEGORIAS, "r+b");

	if (!fp)
	{
		return ;
	}

	Categoria aux;
	char nombreViejo[DIM_MAX_NOMRBES];

	while (fread(&aux, sizeof(Categoria), 1, fp) > 0)
	{
		if (aux.idCategoria == idCategoria)
		{
			strcpy(nombreViejo, aux.nombre);

			strcpy(aux.nombre, nuevoNombre);
			fseek(fp, sizeof(Categoria) * -1, SEEK_CUR);
			fwrite(&aux, sizeof(Categoria), 1, fp);
			fseek(fp, 0, SEEK_CUR);
		}
	}

	fclose(fp);

	fp = fopen(ARCHIVO_JUEGOS, "r+b");

	if (!fp)
	{
		return;
	}

	Juego auxJuego;

	while (fread((&auxJuego), sizeof(Juego), 1, fp) > 0)
	{
		if (_strcmpi(auxJuego.categoria, nombreViejo) == 0)
		{
			strcpy(auxJuego.categoria, nuevoNombre);
			fseek(fp, sizeof(Juego) * -1, SEEK_CUR);
			fwrite(&auxJuego, sizeof(Juego), 1, fp);
			fseek(fp, 0, SEEK_CUR);
		}
	}

	fclose(fp);
}
void exportarCategoriaACsv(char rutaCSV[])
{
	FILE* fp = fopen(ARCHIVO_CATEGORIAS, "rb");
	if (fp == NULL)
	{
		return;

	}
	FILE* csv = fopen(rutaCSV, "w");
	if (csv == NULL)
	{
		return;
	}

	Categoria categoria;
	
	while (fread(&categoria, sizeof(Categoria), 1, fp) == 1)
	{
		if (categoria.idCategoria == -1)
		{
			continue;
		}

		fprintf(csv, "%s,%d\n", categoria.nombre, categoria.idCategoria);
	}


	fclose(fp);
	fclose(csv);

}