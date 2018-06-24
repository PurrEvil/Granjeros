/*
 * CatalogoSemillas.h
 *
 *  Created on: 17 may. 2018
 *      Author: daniela
 */

#ifndef CATALOGOSEMILLAS_H_
#define CATALOGOSEMILLAS_H_

#include "Semilla.h"
#include "Lista.h"

class CatalogoSemillas{
	public:

	/*
	 * post: devuelve el puntero a la clase Semilla que tenga
	 * como atributo 'nombreSemillaSeleccionada'
	 */
		Semilla* obtenerInformacionSemilla(Lista <Semilla*>* semillas, std::string nombreSemillaSeleccionada);

	/*
	 * post: devuelve el puntero a la clase Semilla que se encuentre en la posicion 'posicion' de la lista de semillas
	 *
	 */
		Semilla* obtenerInformacionSemilla(Lista <Semilla*>* semillas, unsigned int posicion);


};


#endif /* CATALOGOSEMILLAS_H_ */
