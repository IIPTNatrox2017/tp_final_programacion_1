#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
#include "../../Librerias Externas/pila .h"

typedef struct stRankingJuego
{
	int idJuego;
	int cantVotos;
}RankingJuego;

/**
* @brief Registra una nueva dominacion de un juego en una categoria con su puntaje.
* 
* @param idJuego ID del juego a nominar.
* @param idCategoria ID de la categoria.
* @param puntajeValor Valor del puntaje asignado.
* @return 1 Si la nominacion se registro completamente.
*/
int registrarNominacion(int idJuego, int idCategoria, Juego juegoDeseado, Categoria categoriaDeseada);

/**
* @brief Verifica si ya existe una dominacion para un juego y categoria.
* 
* @param idJuego ID del jugador a nominar.
* @param idCategoria ID de la categoria.
* @return 1 Si la nominacion fue encontrada.
* @return 0 Si ocurrio un error al abrir el archivo.
*/
int existeNominacionDuplicada(int idJuego, int idCategoria);

/**
* @brief Modifica el puntaje de una nominacion existente.
* 
* @param idNominacion ID de la nominacion a modificar.
* @param nuevoPuntaje Nuevo valor del puntaje.
*/
int modificarNominacion(int idNominacion, int nuevoPuntaje, int d, int m, int a);

/**
* @brief Da de baja una nominacion.
* 
* @param idNominacion ID de la nominacion a dar de baja.
* @return 1 Si la baja fue exitosa.
* @return 0 Si no se pudo abrir el archivo.
* @return -1 Si no se encontro la nominacion.
*/
int bajaNominacion(int idNominacion);

/**
* @brief Muestra todas las nominaciones que pertenecen a una categoria.
*
* @param idCategoria ID de la categoria a flitrar.
*/
void mostrarNominacionesPorCategoria(int idCategoria);

/**
* @brief Genera un ranking de juegos segun la cantidad de nominaciones.
* 
* @return Pila Pila con los IDs de los juegos ordenados por ranking.
*/
Pila obtenerRankingNominaciones(Pila p, Nominacion listaNominaciones[], int nominacionesTotales);
/**
* @brief Cuenta la cantidad de nominaciones de un juego.
* 
* @param idJuego ID del juego.
* @return int Cantidad de nominaciones del juego.
*/
int contarNominacionesJuego(int idJuego);

/**
* @brief Exporta las nominaciones almacenadas a un archivo de texto.
* 
* @param rutaTexto Ruta del archivo donde se exportaran las nominaciones.
*/
void exportarNominacionesATexto(char rutaTexto[]);

/**
* @brief Exporta las nominaciones almacenadas en un archivo CSV.
* 
* @param rutaCSV Ruta del archivo CSV donde se exportaran las nominaciones.
*/
void exportarNominacionesACsv(char rutaCSV[]);
int generarNumeroVotosNominacion();
int conseguirPuntajeDeNominacion(int idNominacion);
void mostrarNominacioneArchivo();
int contarRegistrosArchivo(char nombreArchivo[], size_t size);

#endif

