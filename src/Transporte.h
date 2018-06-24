/*
 * Transporte.h
 *
 *  Created on: 24 may. 2018
 *      Author: daniela
 */

#ifndef TRANSPORTE_H_
#define TRANSPORTE_H_

#include "Almacen.h"
#include "CatalogoDestinos.h"
#include "Creditos.h"
#include "MensajesConsola.h"

class Transporte{

	public:

		/*
		 * pre: la cosecha debe pertenecer a Almacen
		 * post: cobra el costo de envio y envia una cantidad de cosechas a destino
		 */
		unsigned int enviar(Lista<Destino*>* destinos, Almacen* almacen, unsigned int posicion, Creditos* creditos);

		/*
		 * post: devuelve el costo del envio según la cosecha que se quiere enviar
		 */
		unsigned int obtenerCostoEnvio(Lista<Destino*>* destinos, Almacen* almacen, unsigned int posicion);
};






#endif /* TRANSPORTE_H_ */
