/*
 * Vendedor.cpp
 *
 *  Created on: 25 may. 2018
 *      Author: daniela
 */

#include "Vendedor.h"

void Vendedor::vender(std::string tipoCosecha, unsigned int cantidad, Lista<Semilla*>* semillas , Creditos* credito){

	CatalogoSemillas catalogoSemillas;
	unsigned int rentabilidad = catalogoSemillas.obtenerInformacionSemilla(semillas, tipoCosecha)->obtenerRentabilidad();
	unsigned int creditosACobrar = rentabilidad*cantidad;
	credito->vender(creditosACobrar);
}


