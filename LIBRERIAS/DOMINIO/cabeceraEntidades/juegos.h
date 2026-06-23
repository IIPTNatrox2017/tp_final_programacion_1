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

/**
* @brief Compara juegos alfabeticamente por su nombre.
* 
* @param j1 Primer juego.
* @param j2 Segundo juego.
* @return int menor a 0 si j1 es menor.
* @return 0 Si son iguales.
* @return int Mayor si j1 es mayor
*/
int compararJuegosPorNombre(Juego j1, Juego j2);

/*
* @brief Compara juegos por su ID.
* 
* @param j1 Primer juego.
* @param j2 Segundo juego.
* @return int -1 si j1 tiene menor ID.
* @return 0 Si son iguales.
* @return int 1 si j1 tiene mayor ID.
*/
int compararJuegosPorId(Juego j1, Juego j2);

/**
* @brief Modifica el nombre de un juego.
* 
* @param j Puntero al juego a modificar.
* @param nuevoNombre Nuevo nombre del juego
*/
void modificarNombreJuego(Juego* j, char nuevoNombre[]);

/**
* @brief Modifica el estudio de un juego.
* 
* @param j Puntero al juego a modificar.
* @param nuevoEstudio Nuevo nombre del estudio.
*/
void modificarEstudioJuego(Juego* j, char nuevoEstudio[]);

#endif