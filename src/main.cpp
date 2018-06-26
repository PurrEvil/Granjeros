/*
 * main.cpp
 *
 *  Created on: 25 jun. 2018
 *      Author: purrevil
 */
#include "AdministradorDeCatalogoDeDestinos.h"
#include "Cola.h"
#include "Lista.h"
#include "Viaje.h"
#include "Arribo.h"
#include "Traductor.h"

#include <iostream>
using namespace std;

int main(){
	Cola<Arribo*> cola;

	AdministradorDeCatalogoDestinos catalogo;




	catalogo.leerArchivo("destinos.txt");
	Lista<Viaje*>* viajes = catalogo.obtenerListaDeDestinos();
	viajes->iniciarCursor();
	viajes->avanzarCursor();
	Viaje* viaje = viajes->obtenerCursor();
	Lista<Arribo*>* listaDestinos = viaje->obtenerArribos();
	listaDestinos->iniciarCursor();


	while(listaDestinos->avanzarCursor()){
		cola.acolar(listaDestinos->obtenerCursor()->obtenerCosto(), listaDestinos->obtenerCursor());
	}

	cola.quitarRaiz();

	unsigned int posicion = 1;
	while(posicion <= cola.obtenerTamanio()){
			cout << cola.obtenerDato(posicion)->obtenerArribo() << endl;
			posicion++;
		}

	return 0;
}

