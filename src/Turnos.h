/*
 * Turnos.h
 *
 *  Created on: 17 may. 2018
 *      Author: daniela
 */

#ifndef TURNOS_H_
#define TURNOS_H_

class Turnos {
	private:
			unsigned int cantidadTurnosTotales;
			unsigned int turnoActual;

	public:
			/*
			 * post: define la cantidad de turnos disponibles e inicializa los turnos jugados
			 */
			Turnos(unsigned int cantidadTotalDeTurnos);

			/*
			 *post: devuelve la cantidad de turnos disponibles para jugar
			 */
			unsigned int obtenerCantidadTurnosTotales();

			/*
			 *post: devuelve el turno actual
			 */
			unsigned int obtenerTurnoActual();

			/*
			 *post: termina el turno sumando un valor a 'turnoActual'
			 */
			void terminarTurno();
};



#endif /* TURNOS_H_ */
