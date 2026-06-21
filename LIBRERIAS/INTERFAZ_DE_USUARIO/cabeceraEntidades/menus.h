#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "../../DOMINIO/cabeceraEntidades/nominaciones.h"
#include "../../DOMINIO/cabeceraEntidades/categoria.h"
void menuPrincipal();
int pedirOpcion();
void ejecutarOpcion(int opcion);
int pedirOpcionModificarJuego();
void mostrarMenu();

void subMenuJuegos();
void subMenuModificarJuego();
void opcionModificarJuego();
void ejecutarMenuModificarJuego(int opcion);
void ejecutarOpcionSubMenuJuegos(int opcion);
void mostrarSubMenuJuegos();

void subMenuCategorias();
void ejecutarOpcionSubMenuCategorias(int opcion);
void mostrarSubMenuCategorias();

void subMenuNominaciones();
void ejecutarOpcionSubMenuNominaciones(int opcion);
void mostrarSubMenuNominaciones();
void menuPuestosPila(int puesto, char nombreJuego[], char estudioJuego[]);
void menuCategoriasDisponibles(Categoria categorias[], int cantCategorias);


#endif // !1