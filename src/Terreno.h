/*
 * Terreno.h
 *
 *  Created on: 12 may. 2018
 *      Author: daniela
 */

#ifndef TERRENO_H_
#define TERRENO_H_

#include "Parcela.h"
#include "Lista.h"

const float IMPUESTO_A_LA_COMPRA = 1.5;
const unsigned int IMPUESTO_A_LA_VENTA = 2;

class Terreno {

	private:
		unsigned int cantidadFilas;
		unsigned int cantidadColumnas;
		Lista<Parcela*>* parcelas;
		Lista<Lista<Parcela*>*>* terreno;
		Parcela* accesoAParcela;
		unsigned int posicionTerreno;
		unsigned int valor;
		unsigned int precioVenta;

	public:

		/*
		 * post: crea la matriz 'terreno' de 'filas' filas y 'columnas' columnas
		 */
		Terreno(unsigned int cantidadFilas, unsigned int cantidadColumnas, unsigned int valor);

		/*
		 * post: devuelve la parcela que se encuentra en la posicionFila y posicionColumna del terreno
		 */
		Parcela* obtenerParcela(unsigned int posicionFila, unsigned int posicionColumna);

		/*
		 * post: devuelve la cantidad de filas de la matriz 'terreno'
		 */
		unsigned int obtenerFilas();

		/*
		 * post: devuelve la cantidad de columnas de la matriz 'terreno'
		 */
		unsigned int obtenerColumnas();

		/*
		 * post: actualiza el estado de cada parcela al cambiar de turno
		 */
		void actualizacionPorTurno();

		/*
		 * post: devuelve la cantidad de parcelas del terreno
		 */
		unsigned int obtenerCantidadParcelas();

		/*
		 * post: devuelve "valor", el valor del terreno
		 */
		unsigned int obtenerValor();

		/*
		* post: devuelve "precioVenta", el precio al que se cotiza el terreno en el mercado
		 */
		unsigned int obtenerPrecioVenta ();

		/*
		 * post: asigna "valor" al terreno segun la cantidad de parcelas previas y la dificultad
		 */
		void asignarValor(unsigned int cantidadParcelasPrevias, float dificultad);

		~Terreno();
};



#endif /* TERRENO_H_ */
