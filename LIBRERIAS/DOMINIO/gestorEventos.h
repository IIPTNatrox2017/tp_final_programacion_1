#ifndef _GESTOREVENTOS_H_INCLUDED
#define _GESTOREVENTOS_H_INCLUDED

/**
* @brief Crea o limpia un archivo binario.
* 
* @param nombreArchivo Nombre del archivo.
*/
void abrirArchivoLimpio(char nombreArchivo[]);

/**
* @brief Valida que un nombre no este vacio.
* 
* @param nombre Cdena a validar.
* r
* @return 1 Si el nombre es valido.
* @return 0 Si el nombre esta vacio.
*/
int validarNombres(char nombre[]);

/**
* @brief Genera un ID autoincremental para un archivo.
* 
* @param nombreArchivo Nombre del archivo.
* @param size Tamaño de cada registro en bytes.
* @return Proximo ID disponible.
* @return 0 si el archivo no se abre.
*/
int generadorDeIdAutoIncremental(char nombreArchivo[], size_t size);


#endif