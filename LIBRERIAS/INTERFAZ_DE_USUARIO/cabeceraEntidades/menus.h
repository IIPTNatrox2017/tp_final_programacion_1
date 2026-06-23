#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "../../DOMINIO/cabeceraEntidades/nominaciones.h"
#include "../../DOMINIO/cabeceraEntidades/categoria.h"

/**
* @brief Ejecuta el menu principal del sistema.
*/
void menuPrincipal();

/**
* @brief Solicita una opcion al usuario y la devuelve.
* 
* @param string Mensaje a mostrar en pantalla.
* @return Opcion ingresada por el usuario.
*/
int pedirOpcion(char string[]);

/**
* @brief Ejecuta la opcion seleccionada del menu principal.
* 
* @param opcion Opcion ingresada por el usuario.
*/
void ejecutarOpcion(int opcion);

/**
* @brief Muestra el menu principal del sistema.
*/
void mostrarMenu();

/**
* @brief Ejecuta el submenu de juegos.
*/
void subMenuJuegos();

/**
* @brief Muestra el submenu de opciones para modificar un juego.
*/
void subMenuModificarJuego();

/**
* @brief Ejecuta el submenu de exportacion de datos de juegos.
*/
void subMenuExportarDatosJuegos();

/**
* @brief Ejecuta la opcion seleccionada del submenu de juegos.
* 
* @param opcion opcion ingresada por el usuario.
*/
void ejecutarOpcionSubMenuJuegos(int opcion);

/**
* @brief Muestra el submenu de juegos. 
*/
void mostrarSubMenuJuegos();

/**
* @brief Muestra el submenu de exportacion de datos del juego.
*/
void mostrarSubMenuExportarDatosJuegos();

/**
* @brief Ejecuta la opcion seleccionada del submenu de exportacion de juegos.
* 
* @param opcion Opcion ingresada por el usuario.
*/
void ejecutarSubMenuExportarDatosJuegos(int opcion);

/**
* @brief Ejecuta el submenu de categorias. 
*/
void subMenuCategorias();

/**
* @brief Ejecuta la opcion seleccionada del submenu de categorias
* 
* @param opcion Opcion ingresada por el usuario.
*/
void ejecutarOpcionSubMenuCategorias(int opcion);

/**
* @brief Ejecuta el submenu de categorias del sistema.
*/
void mostrarSubMenuCategorias();

/**
* @brief Ejecuta el sub menu de nominaciones del sistema.
*/
void subMenuNominaciones();

/**
* @brief Ejecuta la opcion seleccionada del submenu de nominaciones.
* 
* @param opcion Opcion ingresada por el usuario.
*/
void ejecutarOpcionSubMenuNominaciones(int opcion);

/**
* @brief Muestra el submenu de nominaciones.
*/
void mostrarSubMenuNominaciones();

/**
* @brief Muestra un puesto del ranking de nominaciones.
* 
* @param puesto apaosicion en el ranking.
* @param nombreJuego Nombre del juego.
* @param estudioJuego Nombre del estudio del juego.
*/
void menuPuestosPila(int puesto, char nombreJuego[], char estudioJuego[]);

/**
* @brief Muestra las categorias disponibles para que el usuario seleccione una.
* 
* @param categorias Arreglo de categorias a mostrar.
* @param cantCategorias Cantidad de categorias en el arreglo.
*/
void menuCategoriasDisponibles(Categoria categorias[], int cantCategorias);

/**
* @brief Muestra una pantalla de bienvenida con animacion de carga.
*/
void pantallaBienvenida();

/**
* @brief Obtiene el ancho de la consola.
* 
* @return Ancho de la ventana de consola en caracteres.
*/
int anchoConsola();

/**
* @@brief Obtiene el alto de la consola.
* 
* @return alto de la ventana de la consola en filas.
*/
int altoConsola();

#endif // !1