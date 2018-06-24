/*
 * CatalogoSemillas.cpp
 *
 *  Created on: 17 may. 2018
 *      Author: daniela
 */

#include "CatalogoSemillas.h"

Semilla* CatalogoSemillas::obtenerInformacionSemilla(Lista<Semilla*>* semillas, std::string nombreSemillaSeleccionada){

	Semilla* semilla=NULL;
	bool semillaEncontrada = false;

	semillas->iniciarCursor();

	while(semillas->avanzarCursor() && !semillaEncontrada){
		semilla = semillas->obtenerCursor();

		if(semilla->obtenerNombre() == nombreSemillaSeleccionada){
					semillaEncontrada = true;
				}
	}
	return semilla;
}

Semilla* CatalogoSemillas::obtenerInformacionSemilla(Lista <Semilla*>* semillas, unsigned int posicion) {
	Semilla* semilla = NULL;
	unsigned int posicionLista = 1;

	semillas->iniciarCursor();

	while(semillas->avanzarCursor()){
		Semilla* semillaActual = semillas->obtenerCursor();

		if(posicionLista == posicion){
			semilla = semillaActual;
		}
		posicionLista++;
	}
	return semilla;
}


