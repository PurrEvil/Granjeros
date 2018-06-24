/*
 * Inmobiliaria.cpp
 *
 *  Created on: 25 may. 2018
 *      Author: daniela
 */

#include "Inmobiliaria.h"

unsigned int Inmobiliaria::comprarAlmacen(Almacen* almacen, Creditos* creditos)
{
	unsigned int creditosCobrados = 0;
	unsigned int costo = almacen->obtenerCapacidadDeUnAlmacen();
	if(creditos->hayCreditosSuficientes(costo))
	{
		creditos->comprar(costo);
		creditosCobrados = costo;
		almacen->agregarCapacidadTotal();
	}
	return creditosCobrados;
}

