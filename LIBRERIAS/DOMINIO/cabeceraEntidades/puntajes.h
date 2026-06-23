#ifndef _PUNTAJES_H_INCLUDED
#define _PUNTAJES_H_INCLUDED

typedef struct stPuntaje
{
    int valor;
    int esValido;
} Puntaje;

typedef struct stFechaLanzamiento
{
    int dia;
    int mes;
    int anio;
    int esValido;
} FechaLanzamiento;

/**
* @brief Crea un puntaje validando su rango
* 
* @param valor Valor nuemerico del puntaje.
* @return Puntaje Puntaje creado, indicando si es valido o no.
*/
Puntaje crearPuntaje(int valor);

/**
* @brief Crea una fecha de lanzamiento validando sus valores.
* 
* @param dia Dia de la fecha de lanzamiento.
* @param mes Mes de la fecha de lanzamiento.
* @param anio Año de la fecha de lanzamiento.
*/
FechaLanzamiento crearFecha(int dia, int mes, int anio);

#endif
