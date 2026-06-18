#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "../../DOMINIO/cabeceraEntidades/nominaciones.h"
void menuPrincipal();
int pedirOpcion();
void ejecutarOpcion(int opcion);
void mostrarMenu();

void subMenuJuegos();
int pedirOpcionSubMenuJuegos();
void ejecutarOpcionSubMenuJuegos(int opcion);
void mostrarSubMenuJuegos();

void subMenuCategorias();
int pedirOpcionSubMenuCategorias();
void ejecutarOpcionSubMenuCategorias(int opcion);
void mostrarSubMenuCategorias();

void subMenuNominaciones();
int pedirOpcionSubMenuNominaciones();
void ejecutarOpcionSubMenuNominaciones(int opcion);
void mostrarSubMenuNominaciones();
void menuPuestosPila(int puesto, char nombreJuego[], char estudioJuego[]);
#endif // !1