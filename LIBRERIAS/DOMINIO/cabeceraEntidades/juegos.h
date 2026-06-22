#ifndef _JUEGOS_H_INCLUDED
#define _JUEGOS_H_INCLUDED

typedef struct stJuego
{
	int idJuego;
	char nombre[50];
	char estudio[50];
	char categoria[50];
	int estaActivo;
	int catActiva;

} Juego;


Juego crearJuego(int id, char nombre[], char estudio[], char categoria[]);

int compararJuegosPorNombre(Juego j1, Juego j2);
int compararJuegosPorId(Juego j1, Juego j2);

void modificarNombreJuego(Juego* j, char nuevoNombre[]);
void modificarEstudioJuego(Juego* j, char nuevoEstudio[]);

#endif