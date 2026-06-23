#ifndef LOGICA_CATEGORIA_H_INCLUDED
#define LOGICA_CATEGORIA_H_INCLUDED

#include "../../DOMINIO/cabeceraEntidades/juegos.h"
#include "../../DOMINIO/cabeceraEntidades/categoria.h"

/**
* @brief Registra una nueva categoria en el archivo de categorias.
* 
* @param nombre Nombre de la categoria a registrar.
* @return 1 si la categoria se cargo correctamente, 0 en caso de error.
*/
int cargarNuevaCategoria(char nombre[]);

/**
* @brief Obtiene un listado dinamico de las categorias almacenadas en el archivo de categorias.
* 
* @param validos Puntero en donde se almacena la cantidad de categorias obtenidas.
* @return Categoria* Puntero al arreglo dinamico de categorias si la operacion fue exitosa.
* @return NULL si no se pudo abrir el archivo o reservar memoria.
*/
Categoria* obtenerListadoCategoriasDinamico(int* validos);

/**
* @brief Busca una categoria por su ID.
* 
* @param id ID de la categoria a buscar.
* @return int La posicion de la categoria en el archivo si fue encontrada.
* @return -1 si la categoria no existe o si no se pudo abrir el archivo.
*/
int buscarCategoriaPorId(int id);

/**
* @brief Modifica el nombre de una categoria y la actualiza en los juegos relacionados.
* 
* @param idCategoria ID de la categoria a modificar.
* @param nuevoNombre Nuevo nombre de la categoria.
*/
void modificarCategoria(int idCategoria, char nuevoNombre[]);

/**
*@brief Obtiene el nombre de la categoria apartir de su ID.
* 
* @param idCategoria ID de la categoria.
* return char* Puntero al nombre de la categoria si fue encontrada.
* @return NULL si la categoria no existe o si no se pudo abrir el archivo.
*/
char* conseguirCategoriaPorId(int idCategoria);

/**
* @brief Reactiva una categoria previamente dada de baja.
* 
* @param idCategoria ID de la categoria a reactivar.
*/
void reactivarCategoria(int idCategoria);

/**
* @brief Dar de baja una categoria activa.
* 
* @param idCategoria ID de la categoria a dar de baja.
*/
void darDeBajaCategoria(int idCategoria);

/**
* @brief Ordena un arreglo de categorias alfabeticamente por nombre.
* 
* @param arreglo Arreglo de categorias a ordenar.
* @return validos Cantidad de categorias validas en el arreglo.
*/
void ordenarCategoriasAlfabeticamente(Categoria arreglo[], int validos);

/**
* @brief Exporta las categorias almacenadas a un archivo de texto.
* 
* @param rutaTexto Ruta del archivo de texto donde se exportaran las categorias.
*/
void exportarCategoriasATexto(char rutaTexto[]);

/**
* @brief Obtiene el mayor ID registrado entre las nominaciones.
* 
* @return int Mayor ID de las nominaciones almacenadas.
* @return 0 si no se pudo abrir el archivo o si no hay nominaciones registradas.
*/
int obtenerMayorIdNominacion(void);

/**
* @brief Exporta las categorias almacenadas a un archivo CSV.
* 
* @param rutaCSV Ruta del archivo CSV donde se exportaran las categorias.
*/
void exportarCategoriaACsv(char rutaCSV[]);


#endif
