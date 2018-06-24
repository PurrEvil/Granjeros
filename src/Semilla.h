/*
 * Cultivo.h
 *
 *  Created on: 12 may. 2018
 *      Author: daniela
 */


#ifndef SEMILLA_H_
#define SEMILLA_H_

#include <string>

class Semilla{

	private:

		std::string nombre;

		int costo;

		int rentabilidad;

		int tiempoCrecimiento;

		int tiempoRecuperacion;

		int consumoAgua;

	public:

		/*
		 * post: instancia de 'Semilla' inicializada
		 */

		Semilla (std::string nombre, int costo,
				int renta, int tiempoCrecimiento, int tiempoRecuperacion, int agua){

			this -> nombre = nombre;

			this ->costo = costo;

			this ->rentabilidad = renta;

			this->tiempoCrecimiento = tiempoCrecimiento;

			this ->tiempoRecuperacion = tiempoRecuperacion;

			this -> consumoAgua = agua;

		}

		/*
		 * post: devuelve el nombre de la semilla
		 */

		std::string obtenerNombre(){

			return this -> nombre;
		}

		/*
		 * post: devuelve el costo de la semilla
		 */

		int obtenerCostoSemilla(){

			return this ->costo;

		}

		/*
		 * post: devuelve la rentabilidad de la semilla
		 */

		int obtenerRentabilidad(){

			return this ->rentabilidad;
		}

		/*
		 * post: devuelve la cantidad de turnos necesarios para poder cosechar el cultivo
		 */

		int obtenerTiempoCrecimiento(){
			return this->tiempoCrecimiento;
		}

		/*
		 * post: devuelve la cantidad de turnos necesarios para poder plantar una nueva semilla
		 */
		int obtenerTiempoRecuperacion(){

			return this ->tiempoRecuperacion;
		}

		/*
		 * post: devuelve la cantidad de agua necesaria para regar un cultivo
		 */
		int obtenerConsumoAgua(){

			return this -> consumoAgua;
		}
};


#endif /* SEMILLA_H_ */
