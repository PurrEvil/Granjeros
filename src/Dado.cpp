/*
 * Dado.cpp
 *
 *  Created on: Jun 9, 2018
 *      Author: lubuntu
 */

#include "Dado.h"


Dado::Dado(){
	this->cantidadAgua = 0;
}

unsigned int Dado::obtenerCantidadAgua(){
	return this->cantidadAgua;
}

unsigned int Dado::asignarCantidadAgua(){
	unsigned int dado = (std::rand() % CARAS_DEL_DADO ) + VALOR_DE_AJUSTE;
	int aguaObtenidaEnTurno = (POTENCIADOR*dado);
	this->cantidadAgua += aguaObtenidaEnTurno;
	return dado;
}

void Dado::reiniciarValorDado(){
	this->cantidadAgua = 0;
}

