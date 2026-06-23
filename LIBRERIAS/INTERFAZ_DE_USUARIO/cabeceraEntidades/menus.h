#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "../../DOMINIO/cabeceraEntidades/nominaciones.h"
#include "../../DOMINIO/cabeceraEntidades/categoria.h"

/**
* @brief 
*/
void menuPrincipal();
int pedirOpcion(char string[]);
void ejecutarOpcion(int opcion);
void mostrarMenu();

void subMenuJuegos();
void subMenuModificarJuego();
void subMenuExportarDatosJuegos();

void ejecutarOpcionSubMenuJuegos(int opcion);
void mostrarSubMenuJuegos();
void mostrarSubMenuExportarDatosJuegos();
void ejecutarSubMenuExportarDatosJuegos(int opcion);

void subMenuCategorias();
void ejecutarOpcionSubMenuCategorias(int opcion);
void mostrarSubMenuCategorias();

void subMenuNominaciones();
void ejecutarOpcionSubMenuNominaciones(int opcion);
void mostrarSubMenuNominaciones();
void menuPuestosPila(int puesto, char nombreJuego[], char estudioJuego[]);
void menuCategoriasDisponibles(Categoria categorias[], int cantCategorias);

void pantallaBienvenida();
int anchoConsola();
int altoConsola();

#endif // !1