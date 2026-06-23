#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "../../DOMINIO/cabeceraEntidades/nominaciones.h"
#include "../../DOMINIO/cabeceraEntidades/categoria.h"

/**
 * @brief Ejecuta el menú principal del sistema.
 */
void menuPrincipal();

/**
 * @brief Solicita una opción al usuario y la devuelve.
 *
 * @param string Mensaje a mostrar en pantalla.
 * @return Opción ingresada por el usuario.
 */
int pedirOpcion(char string[]);

/**
 * @brief Ejecuta la opción seleccionada del menú principal.
 *
 * @param opcion Opción ingresada por el usuario.
 */
void ejecutarOpcion(int opcion);

/**
 * @brief Muestra el menú principal del sistema.
 */
void mostrarMenu();

/**
 * @brief Ejecuta el submenú de juegos.
 */
void subMenuJuegos();

/**
 * @brief Muestra el submenú de opciones para modificar un juego.
 */
void subMenuModificarJuego();

/**
 * @brief Ejecuta el submenú de exportación de datos de juegos.
 */
void subMenuExportarDatosJuegos();

/**
 * @brief Ejecuta la opción seleccionada del submenú de juegos.
 *
 * @param opcion Opción ingresada por el usuario.
 */
void ejecutarOpcionSubMenuJuegos(int opcion);

/**
 * @brief Muestra el submenú de juegos.
 */
void mostrarSubMenuJuegos();

/**
 * @brief Muestra el submenú de exportación de datos de juegos.
 */
void mostrarSubMenuExportarDatosJuegos();

/**
 * @brief Ejecuta la opción seleccionada del submenú de exportación de juegos.
 *
 * @param opcion Opción ingresada por el usuario.
 */
void ejecutarSubMenuExportarDatosJuegos(int opcion);

/**
 * @brief Ejecuta el submenú de categorías.
 */
void subMenuCategorias();

/**
 * @brief Ejecuta la opción seleccionada del submenú de categorías.
 *
 * @param opcion Opción ingresada por el usuario.
 */
void ejecutarOpcionSubMenuCategorias(int opcion);

/**
 * @brief Muestra el submenú de categorías.
 */
void mostrarSubMenuCategorias();
void mostrarSubMenuExportarDatosCategoria();
void ejecutarSubMenuExportarDatosCategoria(int opcion);
void subMenuExportarDatosCategorias();

/**
 * @brief Ejecuta el submenú de nominaciones.
 */
void subMenuNominaciones();

/**
 * @brief Ejecuta la opción seleccionada del submenú de nominaciones.
 *
 * @param opcion Opción ingresada por el usuario.
 */
void ejecutarOpcionSubMenuNominaciones(int opcion);

/**
 * @brief Muestra el submenú de nominaciones.
 */
void mostrarSubMenuNominaciones();

/**
 * @brief Muestra un puesto del ranking de nominaciones.
 *
 * @param puesto Posición en el ranking.
 * @param nombreJuego Nombre del juego.
 * @param estudioJuego Nombre del estudio del juego.
 */
void menuPuestosPila(int puesto, char nombreJuego[], char estudioJuego[]);

/**
 * @brief Muestra las categorías disponibles para que el usuario seleccione una.
 *
 * @param categorias Arreglo de categorías a mostrar.
 * @param cantCategorias Cantidad de categorías en el arreglo.
 */
void menuCategoriasDisponibles(Categoria categorias[], int cantCategorias);

/**
 * @brief Muestra una pantalla de bienvenida con animación de carga.
 */
void pantallaBienvenida();

/**
 * @brief Obtiene el ancho de la consola.
 *
 * @return Ancho de la ventana de consola en caracteres.
 */
int anchoConsola();

/**
 * @brief Obtiene el alto de la consola.
 *
 * @return Alto de la ventana de consola en filas.
 */
int altoConsola();

void ejecutarSubMenuExportarDatosNominacion(int opcion);
void subMenuExportarDatosNominacion();
void mostrarSubMenuExportarDatosNominacion();

#endif // !1