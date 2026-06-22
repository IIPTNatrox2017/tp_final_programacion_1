#ifndef ENTRADA_H_INCLUDE
#define ENTRADA_H_INCLUDE

#include "../../DOMINIO/cabeceraEntidades/juegos.h"

void formularioAltaJuego();
void formularioAltaCategoria();
void formularioRegistrarNominacion();

void mostrarDatosJuegosCargados(char nombre[], char estudio[]);
void mostrarDatosJuegosTerminados(char nombre[], char estudio[]);

void modificarJuegoArchivo();

void ejecutarModificacionEstudio(int idJuego, Juego* nuevoJuego);
void ejecutarModificacionNombreJuego(int idJuego, Juego* juegoNuevo);
void ejecutarModificacionCategoria(int idJuego, char nombreCategoria[], Juego* juegoNuevo);
void ejecutarDarDeBajaUnJuego();
void ejecutarReactivarUnJuego();
void ejecutarModificacionCategoriaArchivo();

#endif // !1

