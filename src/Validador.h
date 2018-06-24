/*
 * Validacion.h
 *
 *  Created on: 26 may. 2018
 *      Author: daniela
 */

#ifndef VALIDADOR_H_
#define VALIDADOR_H_

#include "MensajesConsola.h"

class Validador {

	public:

	unsigned int validarOpcion(unsigned int cotaInferior, unsigned int cotaSuperior, unsigned int opcion){
		MensajesConsola mensaje;
		while ((opcion < cotaInferior)||(opcion>cotaSuperior)){
			mensaje.opcionInvalida();
			std::cin>>opcion;
		}
		return opcion;
	}

	unsigned int validarOpcion(unsigned int cotaInferior, unsigned int opcion){
			MensajesConsola mensaje;
			while (opcion < cotaInferior){
				mensaje.opcionInvalida();
				std::cin>>opcion;
			}
			return opcion;
		}

	unsigned int validarFilaColumna (unsigned int cotaSuperior,unsigned int opcion){
		MensajesConsola mensaje;
		while ((opcion<1)|| (opcion>cotaSuperior)){
			mensaje.filaColumnaInvalida();
			std::cin>>opcion;
		}
		return opcion;
	}
};



#endif /* VALIDADOR_H_ */
