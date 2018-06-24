/*
 * Creditos.h
 *
 *  Created on: 16 may. 2018
 *      Author: purrevil
 */

#ifndef CREDITOS_H_
#define CREDITOS_H_

const float CREDITOS_BASE = 15.0;

class Creditos
{
private:
	unsigned int creditos;

public:

	/*
	 * post: inicializa la cantidad de creditos
	 */
	Creditos(float dificultad);

	/*
	 *pre: hay suficientes creditos
	 *post: resta los creditos a pagar
	 */
	void comprar(unsigned int creditosAPagar);

	/*
	 *post: agrega los creditos a cobrar
	 */
	void vender(unsigned int creditosACobrar);

	/*
	 *post: devuelve si hay igual o mas creditos que los ingresados
	 */
	bool hayCreditosSuficientes(unsigned int creditos);

	/*
	 *post: devuelve la cantidad de creditos que hay disponibles
	 */
	unsigned int obtenerCreditos();

};



#endif /* CREDITOS_H_ */
