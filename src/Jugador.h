/*
 * Jugadores.h
 *
 *  Created on: 19 may. 2018
 *      Author: daniela
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "Propiedades.h"
#include "Creditos.h"
#include "Tanque.h"
#include "Almacen.h"

class Jugador {
	private:
		std::string nombre;
		unsigned int cantidadCreditos;
		Propiedades* listaTerrenos;
		Creditos* creditos;
		Tanque* tanqueDeAgua;
		Almacen* almacen;

	public:

		/*
		 *post: crea un jugador identificado por 'nombre', se le asigna una cantidad de creditos y una
		 * 		lista de propiedades que contiene un terreno inicial
		 */
		Jugador(float dificultad, std::string nombre, unsigned int filas, unsigned int columnas);

		/*
		 * post: devuelve el nombre del jugador
		 */
		std::string obtenerNombre();


		/*
		 * post: devuelve la cantidad de creditos que tiene el jugador
		 */
		unsigned int obtenerCantidadCreditos();

		/*
		 *post: devuelve un puntero a los terrenos que posee el jugador
		 */
		Propiedades* obtenerTerrenos();

		/*
		 * post: devuelve un puntero a los creditos que posee el jugador
		 */
		Creditos* obtenerCreditos();

		/*
		 * post: devuelve un puntero al tanque de agua que posee el jugador
		 */
		Tanque* obtenerTanqueDeAgua();

		/*
		 * post: devuelve un puntero al almacen que posee el jugador
		 */
		Almacen* obtenerAlmacen();

		/*
		 * post: devuelve si el jugador tiene mas creditos que otroJugador
		 */
		bool tieneMasCreditosQue (Jugador* otroJugador);

		~Jugador();
};



#endif /* JUGADOR_H_ */
