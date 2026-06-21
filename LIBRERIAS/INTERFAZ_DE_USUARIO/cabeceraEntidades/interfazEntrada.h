#ifndef ENTRADA_H_INCLUDE
#define ENTRADA_H_INCLUDE

void formularioAltaJuego();
void formularioAltaCategoria();
void formularioRegistrarNominacion();
void mostrarDatosJuegosCargados(char nombre[], char estudio[]);
void mostrarDatosJuegosTerminados(char nombre[], char estudio[]);
void modificarJuegoArchivo();

void ejecutarModificacionEstudio(int idJuego);
void ejecutarModificacionNombreJuego(int idJuego);
void ejecutarModificacionCategoria(int idJuego, int idCategoria);

#endif // !1

