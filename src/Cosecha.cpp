/*
 * BolsaSemilla.cpp
 *
 *  Created on: 16 may. 2018
 *      Author: purrevil
 */

#include "Cosecha.h"

Cosecha::Cosecha(std::string tipoCosecha, unsigned int cantidad)
{
	this->tipoCosecha = tipoCosecha;
	this->cantidadDeLaCosecha = cantidad;
}

unsigned int Cosecha::obtenerCantidad()
{
	return this->cantidadDeLaCosecha;
}

std::string Cosecha::obtenerTipoCosecha()
{
	return this->tipoCosecha;

}

void Cosecha::agregarUnaUnidadDeCosecha()
{
	this->cantidadDeLaCosecha++;
}

void Cosecha::eliminarCantidadCosecha()
{
	this->cantidadDeLaCosecha = 0;
}

