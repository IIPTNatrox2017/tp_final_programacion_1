#ifndef LOGICA_CATEGORIA_H_INCLUDED
#define LOGICA_CATEGORIA_H_INCLUDED

#include "../../DOMINIO/cabeceraEntidades/juegos.h"

int cargarNuevaCategoria(char nombre[]);
int buscarCategoriaPorId(int id);
void ordenarCategoriasAlfabeticamente(Categoria arreglo[], int validos);
void exportarCategoriasATexto(char rutaTexto[]);

#endif
