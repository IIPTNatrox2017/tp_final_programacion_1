#ifndef _JUEGOS_H_INCLUDED
#define _JUEGOS_H_INCLUDED

typedef struct stJuego
{
	int idJuego;
	char nombre[50];
	char estudio[50];
	char genero[50];

} Juego;


Juego crearJuego(int id, char nombre[], char estudio[], char genero[]);
void modificarNombreJuego(Juego* j, char nuevoNombre[]);
void modificarEstudioJuego(Juego* j, char nuevoEstudio[]);
void modificarGeneroJuego(Juego* j, char nuevoGenero[]);
int compararJuegosPorNombre(Juego j1, Juego j2);
int compararJuegosPorId(Juego j1, Juego j2);

#endif