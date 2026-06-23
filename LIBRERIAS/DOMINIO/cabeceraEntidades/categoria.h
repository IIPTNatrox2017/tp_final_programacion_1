#ifndef _CATEGORIA_H_INCLUDED
#define _CATEGORIA_H_INCLUDED

typedef struct stCategoria
{
	int idCategoria;
	char nombre[50];
	int estaActiva;
} Categoria;

/**
* @brief Crea una nueva categoria con valores iniciales.
* 
* @param id ID de la categoria.
* @param nombre Nombre de la categoria. 
* @return Categoria Categoria creada e inicializada.
*/
Categoria crearCategoria(int id, char nombre[]);

/**
* @brief Compara dos categorias alfabeticamente por su nombre.
* 
* @param c1	Primera categoria.
* @param c2 Segunda categoria.
* @return int menor a 0 si c1 es menor.
* @return 0 Si son iguales.
* @return int Mayor si c1 es mayor
*/
int compararCategoriasPorNombre(Categoria c1, Categoria c2);

/**
* @brief Modifica el nombre de una categoria.
* 
* @param c Puntero a la categoria a modificar.
* @param nuevoNombre Nuevo nombre de la categoria.
*/
void modificarNombreCategoria(Categoria* c, char nuevoNombre[]);

/**
* @brief Modifica el ID de una categoria.
* 
* @param c Puntero a la categoria a modificar.
* @param idNuevo Nuevo ID de la categoria.
*/
void modificarIDcategoria(Categoria* c, int idNuevo);
#endif