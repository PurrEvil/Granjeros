/*
 * Conjunto.h
 *
 *  Created on: 22 jun. 2018
 *      Author: purrevil
 */

#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include "Viaje.h"
#include "Lista.h"

class Conjunto{
private:
	Lista<Lista<Viaje*>*>* viajes;
public:
	Conjunto(){
		this->viajes = new Lista<Lista<Viaje*>*>;
	}

	bool estaElViaje(Viaje* viaje){
		this->viajes->iniciarCursor();
		bool encontro = false;
		while(viajes->avanzarCursor() && !encontro){
			if((viaje->obtenerSalidaDelViaje) == (this->viajes->obtenerCursor())){
				encontro = true;
			}
		}
		return encontro;
	}


	void agregarViaje(Viaje* viaje){

	}

};


#endif /* CONJUNTO_H_ */
