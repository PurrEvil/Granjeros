/*
 * Tanque.cpp
 *
 *  Created on: 16 may. 2018
 *      Author: purrevil
 */

#include "Tanque.h"

Tanque::Tanque(float dificultad)
{
	this->capacidadTotal = CAPACIDAD_BASE_TANQUE_DE_AGUA/dificultad;
	this->cantidadAguaDisponible = 0;
	this->capacidadLibre = this->capacidadTotal;
	this->costoAumentoDeCapacidad = (COSTO_CAPACIDAD_TANQUE_DE_AGUA)*dificultad;
}

unsigned int Tanque::obtenerCapacidadTotal()
{
	return capacidadTotal;
}

unsigned int Tanque::obtenerCantidadAguaDisponible()
{
	return this->cantidadAguaDisponible;
}

unsigned int Tanque::obtenerCapacidadLibre()
{
	return this->capacidadLibre;
}

unsigned int Tanque::obtenerCostoAumentoDeCapacidad(){
	return this->costoAumentoDeCapacidad;
}


void Tanque::cargarTanque(unsigned int cantidadDeAguaPorCargar){

	while ((this->capacidadLibre <= this->capacidadTotal) && (cantidadDeAguaPorCargar > 0)){
		this->cantidadAguaDisponible ++;
		this->capacidadLibre --;
		cantidadDeAguaPorCargar--;
	}
}


void Tanque::utilizarAgua(unsigned int cantidadAguaParaRiego){

		this->cantidadAguaDisponible -= cantidadAguaParaRiego;
		this->capacidadLibre += cantidadAguaParaRiego;
}



void Tanque::comprarCapacidad(float dificultad){
	this->capacidadTotal+=(CAPACIDAD_BASE_TANQUE_DE_AGUA/dificultad);
}
