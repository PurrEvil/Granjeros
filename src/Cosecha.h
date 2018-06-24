/*
 * BolsaSemilla.h
 *
 *  Created on: 16 may. 2018
 *      Author: purrevil
 */

#ifndef COSECHA_H_
#define COSECHA_H_

#include <string>

class Cosecha{
private:

	std::string tipoCosecha;
	unsigned int cantidadDeLaCosecha;

public:

	/*
	 * post:asigna qué cultivo ha sido cosechado y qué cantidad del mismo
	 */
	Cosecha(std::string tipoCosecha, unsigned int cantidadDeLaCosecha);

	/*
	 *post: devuelve la cantidad de cosecha
	 */
	unsigned int obtenerCantidad();

	/*
	 *post: devuelve el nombre del cultivo que ha sido cosechado
	 */
	std::string obtenerTipoCosecha();

	/*
	 *post: agrega una unidad de cosecha a 'cantidadDeLaCosecha'
	 */
	void agregarUnaUnidadDeCosecha();

	/*
	 * post: elimina 'cantidad' de cosechas
	 */
	void eliminarCantidadCosecha();
};



#endif /* COSECHA_H_ */
