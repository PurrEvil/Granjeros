/*
 * Almacen.h
 *
 *  Created on: 16 may. 2018
 *      Author: purrevil
 */

#ifndef ALMACEN_H_
#define ALMACEN_H_

#include "Lista.h"
#include "Cosecha.h"
#include <string>
#include "MensajesConsola.h"

const float CAPACIDAD_BASE_ALMACEN = 6.0;

class Almacen
{
	private:

		Lista<Cosecha*>* cosechas;
		unsigned int capacidadTotal;
		unsigned int capacidadOcupada;
		unsigned int capacidadDeUnAlmacen;

	public:

		Almacen(float dificultad);

		/*
		 * post: devuelve la capacidad de un unico almacen, es decir, la capacidad total del almacen al crearlo y sin haber agregado capacidad.
		 */
		unsigned int obtenerCapacidadDeUnAlmacen();

		/*
		 * post: devuelve un puntero a la lista de cosechas
		 */
		Lista<Cosecha*>* obtenerCosechas();

		/*
		 * post: devuelve la capacidad total del almacen.
		 */

		unsigned int obtenerCapacidadTotal();

		/*
		 * post: devuelve la capacidad disponible en el almacen
		 */
		unsigned int obtenerCapacidadDisponible();

		/*
		 * post: devuelve la capacidad ocupada en el almacen
		 */
		unsigned int obtenerCapacidadOcupada();

		/*
		 * post: añade capacidad equivalente a un almacen a la capacidad total
		 */
		void agregarCapacidadTotal();

		/*
		 * pre : hay lugar disponible
		 * post: ocupa un lugar en el almacen
		 */
		void ocuparUnLugar();

		/*
		 * pre : no esta vacio
		 * post: libera un lugar en el almacen
		 */
		void liberarUnLugar();

		/*
		 * post: si el tipo de cosecha ya se encuentra en el almacen se le suma uno a su cantidad, si no, se agrega el tipo
		 *       de cosecha a la lista y su cantidad inicia en 1
		 */
		int agregarUnaCosecha(std::string tipoCosecha);

		/*
		 * post: devuelve la cantidad que hay almacenada de un tipo de cosecha
		 */
		int obtenerCantidadDeUnaCosecha(Cosecha* cosecha);

		/*
		 * post: devuelve la cantidad que hay  del tipo de cosecha ingresado en el almacen
		 */
		int obtenerCantidadDeUnaCosecha(std::string tipoCosecha);

		/*
		 * pre	: la cosecha ingresada se encuentra en la lista
		 * post : devuelve la cantidad de cosecha eliminada
		 */
		unsigned int eliminarUnaCosecha(unsigned int posicion);

		/*
		 * post: devuelve el puntero a la cosecha a partir del nombre de la cosecha
		 */
		Cosecha* obtenerCosecha(std::string tipoCosecha);

		/*
		 * post: devuelve el puntero a la cosecha a partir de la posicion en la lista
		 */
		Cosecha* obtenerCosecha(unsigned int posicion);

		/*
		 * post: devuelve la cantidad de tipos de cosechas distintos que hay en la lista de cosechas
		 */

		unsigned int obtenerCantidadCosechasDistintas();

		/*
		 * post: devuelve si el almacen esta vacio o no
		 */

		bool almacenVacio();

		~Almacen();

	private:
		/*
		 * post: devuelve si hay lugar disponible en el almacen
		 */
		bool hayLugar();
};


#endif /* ALMACEN_H_ */
