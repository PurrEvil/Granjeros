/*
 * Creditos.cpp
 *
 *  Created on: 16 may. 2018
 *      Author: purrevil
 */
#include "Creditos.h"
//#include <iostream>

Creditos::Creditos(float dificultad)
{
	creditos = (2*CREDITOS_BASE)/dificultad;
}

bool Creditos::hayCreditosSuficientes(unsigned int creditos)
{
	return (this->creditos >= creditos);
}

void Creditos::comprar(unsigned int creditosAPagar)
{
	this->creditos -= creditosAPagar;
}

void Creditos::vender(unsigned int creditosACobrar)
{
	this->creditos += creditosACobrar;
}

unsigned int Creditos::obtenerCreditos()
{
	return this->creditos;
}



