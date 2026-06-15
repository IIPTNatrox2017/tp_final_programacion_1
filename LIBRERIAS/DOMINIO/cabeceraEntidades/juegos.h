#ifndef _JUEGOS_H_INCLUDED
#define _JUEGOS_H_INCLUDED

typedef struct stJuego
{
	int idJuego;
	char nombre[50];
	char estudio[50];
	char genero[50];

} Juego;

typedef struct	stPuntaje
{
	float valorPuntaje;

} Puntaje;

typedef struct stFechaLanzamiento
{
	int dia;
	int mes;
	int anio;
} FechaLanzamiento;

typedef struct stCategoria
{
	int idCategoria;
	char nombre[50];
} Categoria;

#endif