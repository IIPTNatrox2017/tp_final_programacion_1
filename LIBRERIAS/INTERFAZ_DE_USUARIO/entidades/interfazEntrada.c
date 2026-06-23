#define _CRT_SECURE_NO_WARNINGS

#include "../../multiusos/includesLibrerias.h"

#define DIM_MAX_NOMBRES 50


void formularioAltaJuego()
{
	int cantCategorias = 0;
	Categoria* categorias = obtenerListadoCategoriasDinamico(&cantCategorias);

	if (cantCategorias == 0)
	{
		printf("Todavia no hay categorias cargadas. Por favor ingrese una.\n");
		system("pause");
		system("cls");
		formularioAltaCategoria();
		return;
	}


	char nombre[DIM_MAX_NOMBRES];
	char estudio[DIM_MAX_NOMBRES];

	int esValido = 0;
	int stringRepetido = 0;

	do
	{ 
		printf("Ingrese Nombre Juego\n >>> ");
		scanString(nombre, DIM_MAX_NOMBRES);
	
		esValido = validarNombres(nombre);
		stringRepetido = verificarNombreJuegoNuevo(nombre);

		if (!esValido)
		{
			printf("Nombre no valido.\n");
			system("pause");
			system("cls");
		}
		if (stringRepetido == 1)
		{
			printf("Nombre ya existe.\n");
			system("pause");
			system("cls");
		}

	} while (!esValido || stringRepetido == 1);

	esValido = 0;
	stringRepetido = 0;

	system("cls");
	mostrarDatosJuegosCargados(nombre, estudio);

	do
	{
		printf("Ingrese Estudio\n >>> ");
		scanString(estudio, DIM_MAX_NOMBRES);

		esValido = validarNombres(estudio);
		if (!esValido)
		{
			printf("Estudio no valido.\n");
			system("pause");
			system("cls");
			mostrarDatosJuegosCargados(nombre, estudio);
		}

	} while (!esValido);

	system("cls");
	mostrarDatosJuegosCargados(nombre, estudio);

	int opcion = 0;
	esValido = 0;

	do
	{
		menuCategoriasDisponibles(categorias, cantCategorias);
		printf("\n");
		opcion = pedirOpcion("Seleccione una Categoria: ");

		if (opcion < 1 || opcion > cantCategorias)
		{
			printf("Opcion no valida. Por favor elija otra.\n");
			system("pause");
			system("cls");
			mostrarDatosJuegosTerminados(nombre, estudio);
		}
		else
		{
			esValido = 1;
		}

	} while (!esValido);

	int indice = opcion - 1;

	
	int control = cargarNuevoJuego(nombre, estudio, categorias[indice].idCategoria);
	if (control == 1)
	{
		printf("\nJuego guardado con exito!\n");
	}
	else
	{
		printf("\nError al intentar cargar el juego.\n");

	}
	free(categorias);

}

void formularioAltaCategoria()
{
	char categoria[DIM_MAX_NOMBRES];
	int esValido = 0;

	do
	{
		printf("Ingrese nombre de la categoria\n >>> ");
		scanString(categoria, DIM_MAX_NOMBRES);

		esValido = validarNombres(categoria);
		if (!esValido)
		{
			printf("Ingrese un nombre valido.\n");
			system("pause");
			system("cls");
		}

	} while (!esValido);


	int control = cargarNuevaCategoria(categoria);
		
	if (control == 1)
	{
		printf("\nCategoria guardada con exito!\n");
	}
	else
	{
		printf("\nError al intentar cargar la categoria.\n");
	}

}

void formularioRegistrarNominacion()
{
	int cantJuegos = 0;
	int cantCategorias = 0;

	Juego* listaJuegos = obtenerListadoJuegosDinamico(&cantJuegos);
	Categoria* listaCategorias = obtenerListadoCategoriasDinamico(&cantCategorias);

	if (cantJuegos == 0)
	{
		printf("Todavia no hay juegos cargados. Por favor ingrese uno.\n");
		system("pause");
		system("cls");
		return;
	}
	if (cantCategorias == 0)
	{
		printf("Todavia no hay categorias cargadas. Por favor Ingrese una.\n");
		system("pause");
		system("cls");
		return;
	}

	int esValido = 0;
	int opcion = 0;

	do
	{
		system("cls");
		mostrarListadoCategorias(listaCategorias, cantCategorias);
		opcion = pedirOpcion("Seleccione un ID de Categoria para la Nominacion:");

		if (opcion < 1 || opcion > cantCategorias || listaCategorias[opcion - 1].estaActiva == 0)
		{
			printf("Seleccione un juego Valido.\n");
			system("pause");
			system("cls");
			mostrarListadoCategorias(listaCategorias, cantCategorias);
		}
		else
		{
			esValido = 1;
		}

	} while (!esValido);

	int idCategoria = listaCategorias[opcion - 1].idCategoria;

	esValido = 0;
	opcion = 0;

	do
	{
		system("cls");
		mostrarListadoJuegosPorId(listaJuegos, cantJuegos);
		//MOSTRAR JUEGOS DE LA CATEGORIA SELECCIONADA.
		opcion = pedirOpcion("Seleccione una ID de Juego para la Nominacion:");

		if (opcion < 1 || opcion > cantJuegos || listaJuegos[opcion - 1].estaActivo == 0)
		{
			printf("Seleccione un juego Valido.\n");
			system("pause");
			system("cls");
			//MOSTRAR JUEGOS DE LA CATEGORIA SELECCIONADA.
			mostrarListadoJuegosPorId(listaJuegos, cantJuegos);
			
		}
		else
		{
			esValido = 1;
		}

	} while (!esValido);

	int idJuego = listaJuegos[opcion - 1].idJuego;

	int indice = opcion - 1;

	mostrarCategoria(listaCategorias[idCategoria]);
	mostrarJuego(listaJuegos[idJuego]);
}

void mostrarDatosJuegosCargados(char nombre[], char estudio[])
{
	static int indice = 0;

	if (indice == 2)
	{
		indice = 0;
	}

	if (indice == 0)
	{
		printf("Nombre Cargado: [%s]\n", nombre);
		indice++;
	}
	else if (indice == 1)
	{
		printf("Nombre Cargado: [%s]\n", nombre);
		printf("Estudio Cargado: [%s]\n", estudio);
		indice++;
	}

}

void mostrarDatosJuegosTerminados(char nombre[], char estudio[])
{
	printf("Nombre Cargado: [%s]\n", nombre);
	printf("Estudio Cargado: [%s]\n", estudio);
}

void modificarJuegoArchivo()
{

	int cantJuegos = 0;
	Juego* juegos = obtenerListadoJuegosDinamico(&cantJuegos);

	int cantCategorias = 0;
	Categoria* categorias = obtenerListadoCategoriasDinamico(&cantCategorias);

	if (cantJuegos == 0)
	{
		printf("Aun no hay juego cargados. Por favor ingrese uno.\n");
		return;
	}

	int esValido = 0;
	int opcion = 0;

	do
	{
		system("cls");
		mostrarListadoJuegosPorId(juegos, cantJuegos);
		opcion = pedirOpcion("Seleccione un ID a modificar");

		if (opcion < 1 || opcion > cantJuegos || juegos[opcion - 1].estaActivo == 0)
		{
			printf("Opcion no valida. Intente de nuevo por favor.\n");
			system("pause");
			system("cls");
			mostrarListadoJuegosPorId(juegos, cantJuegos);
		}
		else
		{
			esValido = 1;
		}

	} while (!esValido);


	int indice = opcion - 1;
	

	system("cls");

	int terminar = 1;

	do
	{
		mostrarJuego(juegos[indice]);
		subMenuModificarJuego();
		opcion = pedirOpcion("Seleccione un campo a modificar: ");

		switch (opcion)
		{
			case 1:
			{

				ejecutarModificacionNombreJuego(juegos[indice].idJuego, &juegos[indice]);
				printf("Datos Modificados con Exito!\n");
				break;
			}
			case 2:
			{
				ejecutarModificacionEstudio(juegos[indice].idJuego, &juegos[indice]);
				printf("Datos Modificados con Exito!\n");
				break;
			}
			case 3:
			{
				int opcion1 = 0;
				do
				{
					system("cls");
					menuCategoriasDisponibles(categorias, cantCategorias);
					opcion1 = pedirOpcion("Seleccione una categoria: ");

					if (opcion1 < 1 || opcion1 > cantCategorias)
					{
						printf("Opcion no valida. Intente de nuevo por favor.\n");
						system("pause");
						system("cls");
						menuCategoriasDisponibles(categorias, cantCategorias);
					}
					else
					{
						esValido = 1;
					}

				} while (!esValido);

				int indiceCat = opcion1 - 1;
				ejecutarModificacionCategoria(juegos[indice].idJuego, categorias[indiceCat].nombre, &juegos[indice]);
				printf("\nDatos Modificados con Exito!\n");
				break;
			}
			default:
			{
				printf("Opcion no valida. Seleccione otra\n");
				break;
			}
		}

		printf("\nDesea seguir Modificando Datos?\n >>> ");
		terminar = confirmar('s');

		system("cls");

	} while (terminar != 0);

	free(juegos);
	free(categorias);
}

void ejecutarModificacionEstudio(int idJuego, Juego* nuevoJuego)
{
	int esValido = 0;
	char estudio[DIM_MAX_NOMBRES];
	do
	{
		printf("Ingrese Nuevo Estudio: ");
		scanString(estudio, DIM_MAX_NOMBRES);
		esValido = validarNombres(estudio);
		if (!esValido)
		{
			printf("Nombre no valido. Ingrese otro.\n");
			system("pause");
			system("cls");
			mostrarJuego(*nuevoJuego);
		}

	} while (!esValido);

	modificarJuegoPorEstudio(idJuego, estudio);
	strcpy(nuevoJuego->estudio, estudio);
}

void ejecutarModificacionCategoria(int idJuego, char nombreCategoria[], Juego* juegoNuevo)
{
	modificarJuegoPorCategoria(idJuego, nombreCategoria);
	strcpy(juegoNuevo->categoria, nombreCategoria);
}

void ejecutarDarDeBajaUnJuego()
{
	int validos = 0;
	Juego* lista = obtenerListadoJuegosDinamico(&validos);

	int opcion = 0;
	int esValido = 0;

	do
	{
		system("cls");
		mostrarListadoJuegosPorId(lista, validos);
		opcion = pedirOpcion("Seleccione una ID para dar de baja: ");

		if (opcion < 1 || opcion > validos || lista[opcion - 1].estaActivo == 0)
		{
			printf("Opcion No valida. Elija otra.\n");
			system("pause");
			system("cls");
			mostrarListadoJuegosPorId(lista, validos);
		}
		else
		{
			esValido = 1;
		}

	} while (!esValido);

	int indice = opcion - 1;

	system("cls");
	mostrarJuego(lista[indice]);

	int continuar = 1;

	printf("Esta seguro que quiere eliminar este juego?[s/n]\n >>> ");
	continuar = confirmar('s');
	if (continuar)
	{
		darDeBajaJuego(lista[indice].idJuego);
	}

	free(lista);

}

void ejecutarReactivarUnJuego()
{
	int validos = 0;
	Juego* lista = obtenerListadoJuegosDinamico(&validos);

	if (lista == NULL)
	{
		printf("No hay Juegos eliminados.");
		system("pause");
		system("cls");
		return;
	}

	int opcion = 0;
	int esValido = 0;

	do
	{
		system("cls");
		mostrarListadoJuegosDescativadosPorId(lista, validos);
		opcion = pedirOpcion("Seleccione una ID: ");

		if (opcion < 1 || opcion > validos || lista[opcion - 1].estaActivo == 1)
		{
			printf("Opcion no valida. Por favor elija otra.\n");
			system("pause");
			system("cls");
			mostrarListadoJuegosDescativadosPorId(lista, validos);
		}
		else
		{
			esValido = 1;
		}

	}while(!esValido);

	int indice = opcion - 1;

	system("cls");
	mostrarJuego(lista[indice]);

	int continuar = 1;

	printf("Esta seguro que quiere Reactivar este juego?[s/n]\n >>> ");
	continuar = confirmar('s');

	if (continuar)
	{
		reactivarUnJuego(lista[indice].idJuego);
	}

	free(lista);
	return;
}

	void modificarCategoriaArchivo()
	{
		int cantCategorias = 0;
		Categoria* lista = obtenerListadoCategoriasDinamico(&cantCategorias);

		if (cantCategorias == 0)
		{
			printf("Aun no hay Categorias Cargadas.\n");
			system("pause");
			system("cls");
			return;
		}

		int opcion = 0;
		int esValido = 0;

		do
		{
			system("cls");
			mostrarListadoCategorias(lista, cantCategorias);
			opcion = pedirOpcion("Seleccione una Categoria:");

			if (opcion < 1 || opcion > cantCategorias || lista[opcion - 1].estaActiva == 0)
			{
				printf("Opcion no valida. Por favor Ingrese otra.\n");
				system("pause");
				system("cls");
				mostrarListadoCategorias(lista, cantCategorias);
			}
			else
			{
				esValido = 1;
			}

		} while (!esValido);

		int indice = opcion - 1;

		system("cls");
		mostrarCategoria(lista[indice]);

		char nombreNuevo[DIM_MAX_NOMBRES];

		printf("Ingrese nuevo Nombre de Categoria: ");
		scanString(nombreNuevo, DIM_MAX_NOMBRES);

		int continuar = 1;
		printf("Esta seguro que desea modificar esta Categoria?[s/n]\n >>> ");
		continuar = confirmar('s');

		if (continuar)
		{
			modificarCategoria(lista[indice].idCategoria, nombreNuevo);
		}

		free(lista);
	}

void ejecutarModificacionNombreJuego(int idJuego, Juego* juegoNuevo)
{
	int esValido = 0;
	char nombre[DIM_MAX_NOMBRES];
	do
	{
		printf("Ingrese Nuevo Nombre: ");
		scanString(nombre, DIM_MAX_NOMBRES);
		esValido = validarNombres(nombre);
		if (!esValido)
		{
			printf("Nombre no valido. Ingrese otro.\n");
			system("pause");
			system("cls");
			mostrarJuego(*juegoNuevo);
		}

	} while (!esValido);
	modificarJuegoPorNombre(idJuego, nombre);
	strcpy(juegoNuevo->nombre, nombre);
}

void ejecutarDarDeBajaUnaCategoria()
{
	int cantCategorias = 0;
	Categoria* lista = obtenerListadoCategoriasDinamico(&cantCategorias);

	if (cantCategorias == 0)
	{
		printf("No hay categorias cargadas.\n");
		return;
	}

	int opcion = 0;
	int esValido = 0;

	do
	{
		system("cls");
		mostrarListadoCategorias(lista, cantCategorias);
		opcion = pedirOpcion("Seleccione una ID para dar de baja: ");

		if (opcion < 1 || opcion > cantCategorias || lista[opcion - 1].estaActiva == 0)
		{
			printf("Opcion No valida. Elija otra.\n");
			system("pause");
			system("cls");
			mostrarListadoJuegosPorId(lista, cantCategorias);
		}
		else
		{
			esValido = 1;
		}

	} while (!esValido);

	int indice = opcion - 1;

	system("cls");
	mostrarCategoria(lista[indice]);
	int continuar = 1;

	printf("Esta seguro que quiere eliminar esta Categoria?[s/n]\n >>> ");
	continuar = confirmar('s');
	if (continuar)
	{
		darDeBajaCategoria(lista[indice].idCategoria);
	}

	free(lista);
}

void ejecutarReactivarUnaCategoria()
{
	int cantCategorias = 0;
	Categoria* lista = obtenerListadoCategoriasDinamico(&cantCategorias);

	if (cantCategorias == 0)
	{
		printf("No hay categorias cargadas.\n");
		return;
	}

	int opcion = 0;
	int esValido = 0;

	do
	{
		system("cls");
		mostrarListadoCategoriasInactivas(lista, cantCategorias);
		opcion = pedirOpcion("Seleccione una ID para dar de baja: ");

		if (opcion < 1 || opcion > cantCategorias || lista[opcion - 1].estaActiva == 1)
		{
			printf("Opcion No valida. Elija otra.\n");
			system("pause");
			system("cls");
			mostrarListadoJuegosPorId(lista, cantCategorias);
		}
		else
		{
			esValido = 1;
		}

	} while (!esValido);

	int indice = opcion - 1;

	system("cls");
	mostrarCategoria(lista[indice]);
	int continuar = 1;

	printf("Esta seguro que quiere eliminar esta Categoria?[s/n]\n >>> ");
	continuar = confirmar('s');
	if (continuar)
	{
		reactivarCategoria(lista[indice].idCategoria);
	}

	free(lista);
}

void exportarNominacionJuego()
{
	int cantJuegos = 0;
	Juego* juegos = obtenerListadoJuegosDinamico(&cantJuegos);

	if (cantJuegos == 0)
	{
		printf("Aun no hay juego cargados. Por favor ingrese uno.\n");
		return;
	}

	int opcion = 0;
	int valido = 0;

	do
	{
		system("cls");
		mostrarListadoJuegosPorId(juegos, cantJuegos);
		opcion = pedirOpcion("Seleccione un juego a exportar: ");

		if (opcion < 1 || opcion > cantJuegos || juegos[opcion - 1].estaActivo == 0)
		{
			printf("Opcion no valida. Intente de nuevo por favor.\n");
			system("pause");
			system("cls");
			mostrarListadoJuegosPorId(juegos, cantJuegos);
		}
		else
		{
			valido = 1;
		}

	} while (!valido);





}