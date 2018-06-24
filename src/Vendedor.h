/*
 * Vendedor.h
 *
 *  Created on: 24 may. 2018
 *      Author: daniela
 */

#ifndef VENDEDOR_H_
#define VENDEDOR_H_

#include "Semilla.h"
#include "Lista.h"
#include "CatalogoSemillas.h"
#include "Creditos.h"

class Vendedor {

	public:
		/*
		 * post: creditos cobra la cantidad de cosechas vendidas multiplicado por su rentabilidad
		 */
		void vender(std::string cosecha, unsigned int cantidadVendida, Lista<Semilla*>* semillas, Creditos* credito);

};



#endif /* VENDEDOR_H_ */
