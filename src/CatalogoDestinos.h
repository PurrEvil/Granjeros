/*
 * CatalogoDestinos.h
 *
 *  Created on: 24 may. 2018
 *      Author: daniela
 */

#ifndef CATALOGODESTINOS_H_
#define CATALOGODESTINOS_H_

#include "Destino.h"
#include "Lista.h"

class CatalogoDestinos{

	public:

		/*
		 * post: devuelve el puntero a la clase Destino que tenga
		 * como atributo this->cultivo al 'cultivo'
		 */
		Destino* obtenerDestino(Lista <Destino*>* destinos, std::string cultivo);



};



#endif /* CATALOGODESTINOS_H_ */
