#ifndef LOGICA_CATEGORIA_H_INCLUDED
#define LOGICA_CATEGORIA_H_INCLUDED

#include "../../DOMINIO/cabeceraEntidades/juegos.h"
#include "../../DOMINIO/cabeceraEntidades/categoria.h"


int cargarNuevaCategoria(char nombre[]);
Categoria* obtenerListadoCategoriasDinamico(int* validos);
int buscarCategoriaPorId(int id);
void modificarCategoria(int idCategoria, char nuevoNombre[]);
char* conseguirCategoriaPorId(int idCategoria);
void reactivarCategoria(int idCategoria);
void darDeBajaCategoria(int idCategoria);
void ordenarCategoriasAlfabeticamente(Categoria arreglo[], int validos);
void exportarCategoriasATexto(char rutaTexto[]);
int obtenerMayorIdNominacion(void);
void exportarCategoriaACsv(char rutaCSV[]);


#endif
