/*
 * Tanque.h
 *
 *  Created on: 16 may. 2018
 *      Author: purrevil
 */

#ifndef TANQUE_H_
#define TANQUE_H_


#include "CatalogoSemillas.h"
#include "MensajesConsola.h"

const int COSTO_CAPACIDAD_TANQUE_DE_AGUA = 20;
const float CAPACIDAD_BASE_TANQUE_DE_AGUA = 20.0;

class Tanque {

	private:
			unsigned int capacidadTotal;
			unsigned int cantidadAguaDisponible;
			unsigned int capacidadLibre;
			unsigned int costoAumentoDeCapacidad;

	public:
			/*
			 * post: crea tanque de agua con su capacidad definida por el nivel de dificultad
			 */
			Tanque(float dificultad);

			/*
			 * post: devuelve capacidadTotal
			 */
			unsigned int obtenerCapacidadTotal();

			/*
			 * post: devuelve cantidadOcupada, la cantidad de unidades de agua que tiene el tanque
			 */
			unsigned int obtenerCantidadAguaDisponible();

			/*
			 * post: devuelve cantidadDisponible, la cantidad de unidades libres que tiene el tanque
			 */
			unsigned int obtenerCapacidadLibre();

			/*
			 * informa el costo de aumentar la capacidad del tanque en capacidadTotal unidades
			 */
			unsigned int obtenerCostoAumentoDeCapacidad();

			/*
			 * pre: cantidadDisponbles es mayor o igual a cantidadAguaParaRiego
	     	 * post: resta cantidadAguaParaRiego a cantidadOcupada, es decir, utiliza las unidades de agua
	     	 * 		 dadas por cantidadAguaParaRiego
			 */
			void utilizarAgua(unsigned int cantidadAguaParaRiego);

			/*
			 * post: establece la cantidad de agua disponible por este turno, se calcula mediante la suma del
			 * agua por turno (que es aleatoria) mas la capacidad Ocupada del tanque.
			 */

			void cargarTanque(unsigned int cantidadDeAguaPorCargar);

			/*
			 * post: a la capacidad total del tanque se le suma 'capacidadTotal'
			 */
			void comprarCapacidad(float dificultad);
};


#endif /* TANQUE_H_ */
