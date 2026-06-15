#include <stdint.h>
#include <stdio.h>
#include "LIBRERIAS/INTERFAZ_DE_USUARIO/menus.h"
#include "LIBRERIAS/DOMINIO/gestorEventos.h"
#include "LIBRERIAS/SERVICIO/cabeceraEntidades/logicaJuego.h"
#include "LIBRERIAS/SERVICIO/cabeceraEntidades/logicaCategoria.h"
#include "LIBRERIAS/SERVICIO/cabeceraEntidades/logicaNominaciones.h"

#define PRESENTACIONESGOTY "goty.bin"


int main()
{
	/*abrirArchivoLimpio(PRESENTACIONESGOTY);*/
	/*cargarArchivoConNominaciones(PRESENTACIONESGOTY);*/
	mostrarGOTYS(PRESENTACIONESGOTY);
	
	// Las funciones están declaradas en los headers incluidos; no es necesario volver a declararlas aquí.

	return 0;
}
