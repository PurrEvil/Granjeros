/*
 * Parcela.h
 *
 *  Created on: 12 may. 2018
 *      Author: daniela
 */

#ifndef PARCELA_H_
#define PARCELA_H_

#include "CatalogoSemillas.h"
#include "Lista.h"
#include "Creditos.h"
#include "MensajesConsola.h"
#include "Tanque.h"

class Parcela {
	private:
		std::string cultivo;
		bool estadoSiembra;
		bool estadoRiego;
		bool estadoCosecha;
		bool podrido;
		bool seco;
		bool creciendo;
		bool recuperandose;
		int tiempoRecuperacion;
		int tiempoCrecimiento;

	public:
		/*
		 * post: crea una parcela con los valores inicializados
		 */
		Parcela();

		/*
		 * pre: la parcela debe estar sin sembrar
		 * post: siembra la parcela actualizando los valores de 'cultivo', 'tiempoCrecimiento',
		 * 		'estadoSiembra' y 'estaRecuperandose'
		 */
		void sembrarParcela(Semilla* semillaSeleccionada, Creditos* creditosDisponibles);

		/*
		 * pre: estadoSiembra tiene que ser true (hay un cultivo sembrado) y el tiempo de recuperacion debe estar en 0
		 * post: cosecha la parcela actualizando los valores de 'cultivo', 'estadoCosecha' y 'tiempoRecuperacion'
		 */
		void cosecharParcela(Semilla* semillaSeleccionada);

		/*
		 * pre: estadoRiego debe ser false y estadoSiembra true
		 * post: riega la parcela actualizando 'estadoRiego' a true
		 */
		void regarParcela(Semilla* semillaSeleccionada, Tanque* tanqueDeAgua);

		/*
		 * post: informa si la parcela esta sembrada
		 */
		bool sembrado();

		/*
		 * post: informa si la parcela esta regada
		 */
		bool regado();

		/*
		 * post: informa si la parcela fue cosechada
		 */
		bool cosechado();

		/*
		 * post: devuelve el nombre del cultivo
		 */
		std::string obtenerCultivo();

		/*
		 * post: devuelve el tiempo de recuperacion de la parcela para poder ser sembrada
		 */
		int obtenerTiempoRecuperacion();

		/*
		 * post: devuele el tiempo de crecimiento de la semilla para poder ser cosechada
		 */
		int obtenerTiempoCrecimiento();

		/*
		 * post: informa si el cultivo se echo a perder por falta de cosecha
		 */
		bool estaPodrido();

		/*
		 * post: informa si el cultivo se seco por falta de riego
		 */
		bool estaSeco();

		/*
		 * post: actualiza los estados necesarios para reiniciar una parcela al avanzar un turno
		 */
		void actualizarEstados();

		/*
		 * post: disminuye en una unidad el tiempo de crecimiento
		 */
		void actualizarTiempoCrecimiento();

		/*
		 * post: disminuye en una unidad el tiempo de recuperacion
		 */
		void actualizarTiempoRecuperacion();

		/*
		 * post: echa a perder la parcela por no cosechar a tiempo
		 */
		void verificarParcelaPodrida(unsigned int fila, unsigned int columna);

		/*
		 * post: seca la parcela por falta de riego
		 */
		void verificarParcelaSeca(unsigned int fila, unsigned int columna);

		/*
		 * post: informa si el cultivo esta en proceso de crecimiento
		 */
		bool estaCreciendo();

		/*
		 * post: informa si la tierra esta recuperandose
		 */
		bool estaRecuperandose();

		/*
		 * post: informa si la parcela esta lista para cosechar o no
		 */
		bool listoParaCosechar();

		/*
		 * post: informa si la parcela esta lista para sembrar o no
		 */
		bool listoParaSembrar();
};



#endif /* PARCELA_H_ */
