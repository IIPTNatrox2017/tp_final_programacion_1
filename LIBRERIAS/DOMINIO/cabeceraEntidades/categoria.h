#ifndef _CATEGORIA_H_INCLUDED
#define _CATEGORIA_H_INCLUDED

typedef struct stCategoria
{
	int idCategoria;
	char nombre[50];
} Categoria;


Categoria crearCategoria(int id, char nombre[]);
void modificarNombreCategoria(Categoria* c, char nuevoNombre[]);
int compararCategoriasPorNombre(Categoria c1, Categoria c2);
void modificarIDcategoria(Categoria* c, int idNuevo);
#endif