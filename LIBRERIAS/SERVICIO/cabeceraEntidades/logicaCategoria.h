#ifndef LOGICA_CATEGORIA_H_INCLUDED
#define LOGICA_CATEGORIA_H_INCLUDED

#include "../../DOMINIO/cabeceraEntidades/juegos.h"
#include "../../DOMINIO/cabeceraEntidades/categoria.h"


int cargarNuevaCategoria(char nombre[]);
Categoria* obtenerListadoCategoriasDinamico(int* validos);
int buscarCategoriaPorId(int id);
void ordenarCategoriasAlfabeticamente(Categoria arreglo[], int validos);
void exportarCategoriasATexto(char rutaTexto[]);
int obtenerMayorIdNominacion(void);
int bajaCategoria(int idCategoria);
int modificarCategoria(int idCategoria, char nuevoNombre[]);
int modificarJuego(int idJuego, char nuevoNombre[], char nuevoEstudio[], char nuevoGenero[]);
#endif
