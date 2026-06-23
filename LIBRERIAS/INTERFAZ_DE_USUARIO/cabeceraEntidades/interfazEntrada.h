#ifndef ENTRADA_H_INCLUDE
#define ENTRADA_H_INCLUDE

#include "../../DOMINIO/cabeceraEntidades/juegos.h"

/**
 * @brief Solicita los datos necesarios para dar de alta un juego.
 */
void formularioAltaJuego();

/**
 * @brief Da de alta una categoría.
 */
void formularioAltaCategoria();

/**
 * @brief Registra una nueva nominación seleccionando una categoría y un juego.
 */
void formularioRegistrarNominacion();

/**
 * @brief Muestra los datos de un juego cargado hasta el momento.
 */
void mostrarDatosJuegosCargados(char nombre[], char estudio[]);

/**
 * @brief Muestra los datos finales de un juego cargado.
 */
void mostrarDatosJuegosTerminados(char nombre[], char estudio[]);

/**
 * @brief Modifica los datos de un juego seleccionado.
 */
void modificarJuegoArchivo();

/**
 * @brief Modifica el estudio de un juego.
 *
 * @param idJuego ID del juego a modificar.
 * @param nuevoJuego Puntero al juego que será actualizado.
 */
void ejecutarModificacionEstudio(int idJuego, Juego* nuevoJuego);

/**
 * @brief Modifica el nombre de un juego.
 *
 * @param idJuego ID del juego a modificar.
 * @param juegoNuevo Puntero al juego que será actualizado.
 */
void ejecutarModificacionNombreJuego(int idJuego, Juego* juegoNuevo);

/**
 * @brief Modifica la categoría de un juego.
 *
 * @param idJuego ID del juego a modificar.
 * @param nombreCategoria Nombre de la nueva categoría.
 * @param juegoNuevo Puntero al juego que será actualizado.
 */
void ejecutarModificacionCategoria(int idJuego, char nombreCategoria[], Juego* juegoNuevo);

/**
 * @brief Da de baja una categoría seleccionada.
 */
void ejecutarDarDeBajaUnaCategoria();

/**
 * @brief Reactiva una categoría previamente dada de baja.
 */
void ejecutarReactivarUnaCategoria();

/**
 * @brief Da de baja un juego seleccionado.
 */
void ejecutarDarDeBajaUnJuego();

/**
 * @brief Reactiva un juego previamente dado de baja.
 */
void ejecutarReactivarUnJuego();

/**
 * @brief Modifica una categoría existente.
 */
void modificarCategoriaArchivo();

#endif // !1

