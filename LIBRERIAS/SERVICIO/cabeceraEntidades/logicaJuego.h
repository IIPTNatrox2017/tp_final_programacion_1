#ifndef LOGICA_JUEGO_H_INCLUDED
#define LOGICA_JUEGO_H_INCLUDED

#include "../../DOMINIO/cabeceraEntidades/juegos.h"

/**
* @brief Carga un nuevo juego en el archivo de juegos.
* 
* @param nombre Nombre del juego a registrar.
* @param estudio Estudio desarrollador del juego.
* @param idCategoria ID de la categoria asociada al juego.
* @return int i si el juego se cargo correctamente, 0 si ocurrio un error.
*/
int cargarNuevoJuego(char nombre[], char estudio[], int idCategoria);

/**
* @brief Obtiene un arreglo dinamico de juegos almacenados en el archivo.
* 
* @param validos Puntero donde se almacena la cantidad de juegos obtenidos.
* @return Juego* Arreglo dinamico de juegos cargados.
* return NULL Si no se pudo abrir el archivo o reservar memoria.
*/
Juego* obtenerListadoJuegosDinamico(int* validos);

/**
* @brief Busca un juego por su ID en el archivo de juegos.
* 
* @param id ID del juego a buscar.
* @return Juego*Puntero al juego encontrado si esta activo.
* @return NULL Si el juego no existe o no esta activo.
*/
Juego* buscarJuegoPorId(int id);

/**
* @brief Da de baja un juego activo.
* 
* @param id ID del juego a dar de baja.
*/
void darDeBajaJuego(int id);

/**
* @brief Reactiva un juego previamente dado de baja.
* 
* @param idJuego ID del juego a reactivar.
*/
void reactivarUnJuego(int idJuego);

/**
* @brief Ordena un arreglo de juegos alfabeticamente por nombre.
* 
* @param arreglo Arreglo de juegos a ordenar.
* @param validos Cantidad de juegos validos en el arreglo.
*/
void ordenarJuegosAlfabeticamente(Juego arreglo[], int validos);

/**
* @brief Exporta los juegos almacenados a un archivo de texto.
* 
* @param rutaTexto Ruta del archivo de texto donde se exportaran los juegos.
*/
void exportarJuegosATexto(char rutaTexto[]);

/**
* @brief Ordena un arreglo de juegos por ID de forma ascendente.
* 
* @param arreglo Arreglo de juegos a ordenar.
* @param validos Cnatidad de juegos validos en el arreglo.
*/
void ordenarJuegosPorId(Juego arreglo[], int validos);

/**
* @brief Asigna la categoria correspondiente a un juego segun el ID de categoria.
* 
* @param idCategoria ID de la categoria a buscar.
* @param juego Puntero al juego que se le asignara el nombre de la categoria.
*/
void cargarCategoriaAjuego(int idCategoria, Juego* juego);

/**
* @brief Muestra un listado de juegos filtrado por categoria.
* 
* @param categoriaDeseada Nombre de la categoria a filtrar.
*/
void listadoJuegosSegunCategoria(char categoriaDeseada[]);

/**
* @brief Modifica el nombre de un juego segun su ID.
* 
* @param idJuego ID del juego a modificar.
* @param nombre Nuevo nombre del juego.
*/
void modificarJuegoPorNombre(int idJuego, char nombre[]);

/**
* @brief Modifica el estudio de un juego segun su ID.
* 
* @param idJuego ID del juego a modificar.
* @param estudio Nuevo nombre del estudio del juego.
*/
void modificarJuegoPorEstudio(int idJuego, char estudio[]);

/**
* @brief Modifica la categoria de un juego segun su ID.
* 
* @param idJuego ID del juego a modificar.
* @param nombreCategoria Nuevo nombre de la categoria.
*/
void modificarJuegoPorCategoria(int idJuego, char nombreCategoria[]);

/**
* @brief Verifica si el nombre del juego ya existe en el sistema.
* 
* @param nombreNuevo Nombre del juego a verificar.
* @return int 1 si el nombre ya existe.
* @return 0 si no existe o no se pudo abrir el archivo.
*/
int verificarNombreJuegoNuevo(char nombreNuevo[]);

/**
* @brief Exporta los juegos almacenados a un archivo CSV
* 
* @param rutaCSV Ruta del archivo CSV donde se exportaran los juegos.
*/
void exportarJuegosACsv(char rutaCSV[]);

#endif