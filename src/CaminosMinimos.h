/*
 * CaminosMinimos.h
 *
 *  Created on: 27 jun. 2018
 *      Author: purrevil
 */

#ifndef CAMINOSMINIMOS_H_
#define CAMINOSMINIMOS_H_

#include "Viaje.h"
#include "Lista.h"
#include "Cola.h"



class CaminosMinimos{

	public:

	/*
	 * pre:
	 * post: recibe por parametro el heap con los costes de envio, remueve
	 * la raiz y actualiza la prioridad de heap.
	 */

	void caminosMinimos(Cola<Arribo*>* heap, Lista<Viaje*>* listaDeAdyacencia);


	bool elCosteDeLaSumaEsMenorAlCosteDirecto(Arribo* almacenAProvincia,
		Arribo*provinciaAProvincia, Arribo* candidatoAlmacenAProvincia);


	Lista<Arribo*>* buscarEnListaDeAdyacencia(Lista<Viaje*>* listaDeAdyacencia, Arribo* unArribo);

	Lista<Arribo*>* buscarEnListaDeAdyacenciaPorNombre(Lista<Viaje*>* listaDeAdyacencia, std::string nombreProvincia);

	Arribo* buscarEnListaDeArribos(Lista<Arribo*>* listaDeArribos, Arribo* unArribo);


};




#endif /* CAMINOSMINIMOS_H_ */
