#ifndef _PUNTAJES_H_INCLUDED
#define _PUNTAJES_H_INCLUDED

typedef struct stPuntaje
{
    float valor;
    int esValido;
} Puntaje;

typedef struct stFechaLanzamiento
{
    int dia;
    int mes;
    int anio;
    int esValido;
} FechaLanzamiento;


Puntaje crearPuntaje(float valor);
FechaLanzamiento crearFecha(int dia, int mes, int anio);

#endif
