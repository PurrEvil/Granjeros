/*
 * Transporte.cpp
 *
 *  Created on: 24 may. 2018
 *      Author: daniela
 */
/*
#include "Transporte.h"

unsigned int Transporte::enviar(Lista<Destino*>* destinos, Almacen* almacen, unsigned int posicion, Creditos* creditos)
{
	MensajesConsola mensaje;
	unsigned int cantidadEnviada = 0;
	if(almacen->obtenerCosecha(posicion) != NULL)
	{
		unsigned int costoEnvio = obtenerCostoEnvio(destinos, almacen, posicion);
		if(creditos->hayCreditosSuficientes(costoEnvio))
		{
			cantidadEnviada = almacen->eliminarUnaCosecha(posicion);
			creditos->comprar(costoEnvio);
		}else {
			mensaje.saldoInsuficiente();
		}

	}

	return cantidadEnviada;

}

unsigned int Transporte::obtenerCostoEnvio(Lista<Destino*>* destinos, Almacen* almacen, unsigned int posicion){
	CatalogoDestinos catalogo;
	Cosecha* cosecha = almacen->obtenerCosecha(posicion);
	unsigned int cantidad = almacen->obtenerCantidadDeUnaCosecha(cosecha);
	unsigned int costo = cantidad*((catalogo.obtenerDestino(destinos, cosecha->obtenerTipoCosecha())->obtenerDistancia()) / 100);
	return costo;
}
*/
