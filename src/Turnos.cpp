/*
 * Turnos.cpp
 *
 *  Created on: 17 may. 2018
 *      Author: daniela
 */

#include "Turnos.h"

Turnos::Turnos(unsigned int cantidadTotalDeTurnos){

	this->cantidadTurnosTotales = cantidadTotalDeTurnos;
	this->turnoActual = 1;
}

unsigned int Turnos::obtenerCantidadTurnosTotales() {

	return this->cantidadTurnosTotales;
}

unsigned int Turnos::obtenerTurnoActual(){

	return this->turnoActual;
}

void Turnos::terminarTurno() {

	this->turnoActual++;
}

