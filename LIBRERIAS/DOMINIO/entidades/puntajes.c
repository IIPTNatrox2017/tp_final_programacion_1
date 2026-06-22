#define _CRT_SECURE_NO_WARNINGS

#include "../../multiusos/includesLibrerias.h"

#define VAL_MIN 0
#define VAL_MAX 100

Puntaje crearPuntaje(int valor)
{
	Puntaje nuevoPuntaje;
	if (valor < VAL_MIN || valor > VAL_MAX)
	{
		nuevoPuntaje.valor = 0;
		nuevoPuntaje.esValido = 0;
	}
	else
	{
		nuevoPuntaje.valor = valor;
		nuevoPuntaje.esValido = 1;
	}
	return nuevoPuntaje;
}
FechaLanzamiento crearFecha(int dia, int mes, int anio)
{
	FechaLanzamiento nuevaFecha;

	nuevaFecha.esValido = 1;

	if (dia < 1 || dia > 31)
	{
		nuevaFecha.esValido = 0;

	}
	else
	{
		nuevaFecha.dia = dia;
	}

	if (mes < 1 || mes > 12)
	{
		nuevaFecha.esValido = 0;
	}
	else
	{
		nuevaFecha.mes = mes;
	}

	if(anio <= 1950 || anio >= 2030)
	{
		nuevaFecha.esValido = 0;
	}
	else
	{
		nuevaFecha.anio = anio;
	}

	return nuevaFecha;
}