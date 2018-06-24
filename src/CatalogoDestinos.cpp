/*
 * CatalogoDestinos.cpp
 *
 *  Created on: 24 may. 2018
 *      Author: daniela
 */

#include "CatalogoDestinos.h"

Destino* CatalogoDestinos::obtenerDestino(Lista<Destino*>* destinos, std::string cultivo){

	Destino* ptrClaseDestino=NULL;
	bool encontro=false;

	destinos->iniciarCursor();

	while(destinos->avanzarCursor() && !encontro){
		if(destinos->obtenerCursor()->obtenerCultivo() == cultivo){
			ptrClaseDestino = destinos ->obtenerCursor();
			encontro = true;
		}
	}

	return ptrClaseDestino;

}


