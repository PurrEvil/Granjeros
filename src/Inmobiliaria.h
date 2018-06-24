/*
 * Inmobiliaria.h
 *
 *  Created on: 25 may. 2018
 *      Author: daniela
 */

#ifndef INMOBILIARIA_H_
#define INMOBILIARIA_H_

#include "Almacen.h"
#include "Creditos.h"

class Inmobiliaria {

	public:

		/*
		 * post: si tiene los creditos suficientes agrega capacidad a almacen y creditos lo paga.
		 */
		unsigned int comprarAlmacen(Almacen* almacen, Creditos* creditos);
};


#endif /* INMOBILIARIA_H_ */
