#ifndef _GESTOREVENTOS_H_INCLUDED
#define _GESTOREVENTOS_H_INCLUDED


void abrirArchivoLimpio(char nombreArchivo[]);
int validarNombres(char nombre[]);
int generadorDeIdAutoIncremental(char nombreArchivo[], size_t size);


#endif