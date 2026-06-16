#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>




// =========================================================================
// 1. INCLUSIÓN DE LAS CABECERAS (Las 3 capas completas)
// =========================================================================
#include "LIBRERIAS/DOMINIO/cabeceraEntidades/puntajes.h"
#include "LIBRERIAS/DOMINIO/cabeceraEntidades/juegoS.h"
#include "LIBRERIAS/DOMINIO/cabeceraEntidades/categoria.h"
#include "LIBRERIAS/DOMINIO/cabeceraEntidades/nominaciones.h"

#include "LIBRERIAS/SERVICIO/cabeceraEntidades/logicaCategoria.h"
#include "LIBRERIAS/SERVICIO/cabeceraEntidades/logicaJuego.h"
#include "LIBRERIAS/SERVICIO/cabeceraEntidades/logicaNominaciones.h"

// Tus nuevos módulos de Interfaz de Usuario
#include "LIBRERIAS/INTERFAZ_DE_USUARIO/cabeceraEntidades/menus.h"
#include  "LIBRERIAS/INTERFAZ_DE_USUARIO/cabeceraEntidades/interfazEntrada.h"
#include "LIBRERIAS/INTERFAZ_DE_USUARIO/cabeceraEntidades/interfazSalida.h"

int main()
{
    menuPrincipal();
    return 0;
}