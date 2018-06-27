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
#include "CaminosMinimos.h"
#include <iostream>
using namespace std;

int main(){
	Cola<Arribo*>* cola = new Cola<Arribo*>;

	AdministradorDeCatalogoDestinos catalogo;




	catalogo.leerArchivo("destinos.txt");
	Lista<Viaje*>* viajes = catalogo.obtenerListaDeDestinos();
	viajes->iniciarCursor();
	viajes->avanzarCursor();
	Viaje* viaje = viajes->obtenerCursor();
	Lista<Arribo*>* listaDestinos = viaje->obtenerArribos();
	listaDestinos->iniciarCursor();


	while(listaDestinos->avanzarCursor()){
		cola->acolar(listaDestinos->obtenerCursor()->obtenerCosto(), listaDestinos->obtenerCursor());
	}


	unsigned int posicion =1;

	while(posicion <= cola->obtenerTamanio()){
			cout << cola->obtenerDato(posicion)->obtenerArribo() << " " << (*cola->obtenerDato(posicion)->obtenerCosto()) << endl;
			posicion++;
		}
	cout << "termino" << endl;

	CaminosMinimos camino;
	camino.caminosMinimos(cola,viajes);

	listaDestinos->iniciarCursor();
	posicion = 1;
	while(listaDestinos->avanzarCursor()){
		cout << listaDestinos->obtenerCursor()->obtenerArribo() << " " << listaDestinos->obtenerCursor()->obtenerCosto() << endl;
	}


	/*
	posicion = 1;


	cola.quitarRaiz();

	while(posicion <= cola.obtenerTamanio()){
			cout << cola.obtenerDato(posicion)->obtenerArribo() << " " << (*cola.obtenerDato(posicion)->obtenerCosto()) << endl;
			posicion++;
		}
	cout << "termino" << endl;


	posicion = 1;
	listaDestinos->iniciarCursor();
	while(posicion < (listaDestinos->contarElementos()-1)){
		listaDestinos->avanzarCursor();
		posicion++;
	}


	Arribo* lugar = listaDestinos->obtenerCursor();


	lugar->cambiarCosto(1);
	cola.promover(lugar);

	posicion = 1;
	while(posicion <= cola.obtenerTamanio()){
		cout << cola.obtenerDato(posicion)->obtenerArribo() << " " << (*cola.obtenerDato(posicion)->obtenerCosto()) << endl;
		posicion++;
	}
*/
	return 0;
}

