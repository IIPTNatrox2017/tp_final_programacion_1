#define _CRT_SECURE_NO_WARNINGS

#include "menus.h"
#include "../DOMINIO/cabeceraEntidades/nominaciones.h"
#include <stdio.h>
#include "../Librerias Externas/scanner.h"


//ESTA CAPA SERA LA UNICA ENCARGADA DE SOLICITAR DATOS AL USUARIO.
// SE RECOMIENDA EL USO RESPONSABLE DE IA.
// TODO EL CODIGO ENTREGADO DEBE PODER SER DEFENDIDO POR CUALQUIER INTEGRANTE DEL GRUPO.



void menuPrincipal()
{
	printf("MENU PRINCIPAL.\n");
}

void mostrarGOTYS(char nombreArchivo[])
{
	FILE* fp;
	fp = fopen(nombreArchivo, "rb");

	if (!fp)
	{
		printf("Error no se pudo abrir el archivo.\n");
		return;
	}

	Nominacion aux;

	while (fread(&aux, sizeof(Nominacion), 1, fp) > 0)
	{
		mostrarunaNominacion(aux);
	}


	fclose(fp);
}


void mostrarunaNominacion(Nominacion aux)
{
	int ancho=75;
	char renglonId[100];
	char renglonJuego[150];
	char renglonPuntaje[100];
	char renglonFechaLanzamiento[100];
	char renglonCategoriaGenero[150];

	sprintf(renglonId, "ID NOMINACION: %d | ID JUEGO %d", aux.idNominacion, aux.juego.idJuego);
	sprintf(renglonJuego, "NOMBRE DE JUEGO: %s | NOMBRE DEL ESTUDIO: %s", aux.juego.nombre, aux.juego.estudio);
	sprintf(renglonCategoriaGenero, "GENERO: %s | CATEGORIA: %s", aux.juego.genero, aux.categoria.nombre);
	sprintf(renglonFechaLanzamiento, "FECHA DE LANZAMIENTO: %d/%d/%d", aux.fecha.dia, aux.fecha.mes, aux.fecha.anio);
	sprintf(renglonPuntaje, "PUNTAJE: %.1f", aux.puntaje.valorPuntaje);


	printf("+"); for (int i = 0; i < ancho; i++) printf("="); printf("+\n");
	printf("| %-*s |\n", ancho - 2, renglonId);
	printf("| %-*s |\n", ancho - 2, renglonJuego);
	printf("| %-*s |\n", ancho - 2, renglonCategoriaGenero);
	printf("| %-*s |\n", ancho - 2, renglonFechaLanzamiento);
	printf("| %-*s |\n", ancho - 2, renglonPuntaje);
	printf("+"); for (int i = 0; i < ancho; i++) printf("="); printf("+\n");

}

void cargarUnJuego()
{
	int idJuego;
	char nombre[50];
	char estudio[50];
	char genero[50];
	int cargado = 0;

	printf("Ingrese el ID del juego: ");
	idJuego = scanInt();

	printf("Ingrese el nombre del juego: ");
	scanString(nombre, 50);

	printf("Ingrese el estudio del juego: ");
	scanString(estudio, 50);

	printf("Ingrese el genero del juego: ");
	scanString(genero, 50);

}