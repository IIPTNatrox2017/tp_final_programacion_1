#ifndef _CATEGORIA_H_INCLUDED
#define _CATEGORIA_H_INCLUDED

typedef struct stCategoria
{
	int idCategoria;
	char nombre[50];
} Categoria;


Categoria crearCategoria(int id, char nombre[]);

int compararCategoriasPorNombre(Categoria c1, Categoria c2);

void modificarNombreCategoria(Categoria* c, char nuevoNombre[]);
void modificarIDcategoria(Categoria* c, int idNuevo);
#endif