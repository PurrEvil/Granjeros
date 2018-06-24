/*
 * Propiedades.h
 *
 *  Created on: 12 may. 2018
 *      Author: daniela
 */

#ifndef PROPIEDADES_H_
#define PROPIEDADES_H_

#include "Lista.h"
#include "Terreno.h"
#include "Creditos.h"
#include "MensajesConsola.h"

const int CANTIDAD_BASE_PARCELAS = 9;
const unsigned int TERRENO_INICIAL = 1;

class Propiedades {

	private:
		Lista<Terreno*>* terrenos;

	public:

		/*
		 * post: crea una lista con puntero a Terreno y agrega un terreno inicial
		 */
		Propiedades(float dificultad, unsigned int filas, unsigned int columnas);

		/*
		 * post: agrega un terreno de 'dimension' filas y 'dimension' columnas a la lista de terrenos
		 */
		Terreno* comprarTerreno (Creditos* creditosDisponibles, unsigned int filas, unsigned int columnas, float dificultad, unsigned int parcelasAComprar);

		/*
		 * pre: debe haber por lo menos un terreno en la lista de terrenos
		 * post: elimina de la lista de terrenos 'terrenoEnVenta'
		 */
		void venderTerreno(Terreno* terrenoEnVenta, Creditos* creditosDisponibles);

		/*
		 * post: devuelve el puntero a la lista de terrenos
		 */
		Lista<Terreno*>* obtenerTerrenos();

		/*
		 * pre: 'posicion' debe estar entre [1... obtenerCantidadTerrenos()]
		 * post: devuelve el puntero al terreno en la posicion indicada de la lista
		 */
		Terreno* accederATerreno(unsigned int posicion);

		/*
		 * post: devuelve la cantidad de terrenos que hay en la lista de terrenos
		 */
		unsigned int obtenerCantidadTerrenos ();

		/*
		 * post: devuelve la cantidad total de parcelas de cada terreno que componen Propiedades
		 */

		unsigned int obtenerCantidadParcelasTotales();

		/*
		 * pre: se pasa por parametro la sumatoria de parcelas de todos los terrenos que componen Propiedades
		 * y la dificultad del juego
		 * post: informa el valor del terreno a aniadir a Propiedades
		 */

		unsigned int obtenerValorTerrenoParaCompra(unsigned int cantidadParcelasTotales, float dificultad, unsigned int parcelasAComprar);

		/*
		 * post: libera los recursos utilizados
		 */
		~Propiedades();

};



#endif /* PROPIEDADES_H_ */
