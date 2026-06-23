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

/**
* @brief Crea un nuevo juego con valores iniciales.
* 
* @param id ID del juego.
* @param nombre Nombre del juego.
* @param estudio Estudio desarrollador del juego.
* @param categoria Nombre de la categoria del juego.
* @return Juego Juego creado e inicializado.
*/
Juego crearJuego(int id, char nombre[], char estudio[], char categoria[]);


int compararJuegosPorNombre(Juego j1, Juego j2);
int compararJuegosPorId(Juego j1, Juego j2);

void modificarNombreJuego(Juego* j, char nuevoNombre[]);
void modificarEstudioJuego(Juego* j, char nuevoEstudio[]);

#endif