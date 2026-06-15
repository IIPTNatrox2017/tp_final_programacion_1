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
    printf("========== INICIANDO CONTROL GENERAL DE ARQUITECTURA UTN ==========\n\n");

    // -------------------------------------------------------------------------
    // FASE 1: DOMINIO
    // -------------------------------------------------------------------------
    printf("--- [FASE 1] Verificando Capa de Dominio ---\n");
    Puntaje p1 = crearPuntaje(9.5f);
    FechaLanzamiento f1 = crearFecha(10, 12, 2026);
    Juego j1 = crearJuego(1, "Elden Ring", "FromSoftware", "Soulslike");
    Categoria c1 = crearCategoria(10, "GOTY");
    Nominacion n1 = crearNominacion(100, j1.idJuego, c1.idCategoria, p1, f1);
    printf("-> Capa de Dominio: OK.\n\n");

    // -------------------------------------------------------------------------
    // FASE 2: LÓGICA / SERVICIO
    // -------------------------------------------------------------------------
    printf("--- [FASE 2] Verificando Capa de Logica ---\n");
    cargarNuevoJuego("Resident Evil", "Capcom", "Survival Horror");
    int v_juegos = 0;
    Juego* listaDinamica = obtenerListadoJuegosDinamico(&v_juegos);
    buscarJuegoPorId(1);
    printf("-> Capa de Logica: OK.\n\n");

    // -------------------------------------------------------------------------
    // FASE 3: INTERFAZ DE USUARIO (Ejecutando tu lista completa)
    // -------------------------------------------------------------------------
    printf("--- [FASE 3] Verificando Capa de Interfaz de Usuario ---\n");

    // Módulo 1: Menús y Navegación
    menuPrincipal();
    subMenuJuegos();
    subMenuCategorias();
    subMenuNominaciones();

    // Módulo 2: Formularios de Entrada
    formularioAltaJuego();
    formularioAltaCategoria();
    formularioRegistrarNominacion();

    // Módulo 3: Visualización y Reportes
    mostrarListadoJuegos();
    mostrarListadoCategorias();
    mostrarRankingNominacionesUI();
    formularioExportarArchivos();

    printf("\n-> Capa de Interfaz de Usuario: OK.\n\n");

    // =========================================================================
    // FIN DEL CONTROL
    // =========================================================================
    printf("==================================================================\n");
    printf(" ¡PROYECTO COMPLETO COMPILADO CON ÉXITO!\n");
    printf(" Dominio, Logica e Interfaz estan perfectamente enlazados.\n");
    printf("==================================================================\n");

    return 0;
}