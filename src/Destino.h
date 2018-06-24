/*
 * Destino.h
 *
 *  Created on: 24 may. 2018
 *      Author: daniela
 */

#ifndef DESTINO_H_
#define DESTINO_H_

#include <string>

class Destino{

private:

	std::string salida;

	std::string llegada;

	int costo;

	std::string cultivo;


public:

	/*
	 * post: instancia de 'Viaje' inicializada
	 */

	Destino(std::string salida, std::string llegada, int costo, std::string cultivo){

		this -> salida = salida;

		this -> llegada = llegada;

		this-> costo = costo;

		this -> cultivo = cultivo;



	}


	/*
	 * post: devuelve el dato 'nombreDelDestino'
	 */

	std::string obtenerSalidaDelViaje(){

		return this ->salida;

	}


	/*
	* post: devuelve el dato 'distancia'
	*/

	std::string obtenerLlegadaDelViaje(){

		return this -> llegada;
	}



	/*
	 * post: devuelve el dato 'cultivo'
	 */

	std::string obtenerCultivo(){

		return this -> cultivo;

	}

	int obtenerCosto(){
		return this->costo;
	}

};


#endif /* DESTINO_H_ */
