/*
 * Dado.h
 *
 *  Created on: Jun 9, 2018
 *      Author: lubuntu
 */

#ifndef DADO_H_
#define DADO_H_

#include <cstdlib>
#include <ctime>

const unsigned int POTENCIADOR = 5;
const unsigned int CARAS_DEL_DADO = 6;
const unsigned int VALOR_DE_AJUSTE = 1;

class Dado {
	private:
			unsigned int cantidadAgua;
	public:
			/*
			 * post: pone el valor de dado en cero
			 */
			Dado();

			/*
			 * post: devuelve cantidadAgua
			 */
			unsigned int obtenerCantidadAgua();

			/*
			 * post: asigna un valor aleatorio a cantidadAgua
			 */
			unsigned int asignarCantidadAgua();

			/*
			 * post: reinicia el valor del dado en cero
			 */
			void reiniciarValorDado();
};




#endif /* DADO_H_ */
