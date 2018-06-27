/*
 * CargarCatalogoDestinos.cpp
 *
 *  Created on: 24 may. 2018
 *      Author: daniela
 */

#include <fstream>
#include <sstream>

#include "AdministradorDeCatalogoDeDestinos.h"


AdministradorDeCatalogoDestinos::AdministradorDeCatalogoDestinos(){

	this -> destinos = new Lista<Viaje*>;

}

void AdministradorDeCatalogoDestinos::leerArchivo(std::string rutaEntrada) {

	std::ifstream archivo;
	archivo.open(rutaEntrada.c_str());

	std::string linea;

	while (getline(archivo,linea)) {

		this->cargarStringADestino(linea);
		}



	archivo.close();
}

void AdministradorDeCatalogoDestinos::completarCatalogo(Lista<Viaje*>* destinos){
	// HIPOTESIS el origen se encuentra en la primera linea del TXT, es decir ALMACEN.

	Lista<Arribo*>* arribosOrigen = destinos->obtener(1)->obtenerArribos();
	for(unsigned int posicion = 2; posicion <= destinos->contarElementos(); posicion++){
		bool encontro = false;
		arribosOrigen->iniciarCursor();
		while(arribosOrigen->avanzarCursor() && !encontro){
			if(destinos->obtener(posicion)->obtenerSalidaDelViaje() == arribosOrigen->obtenerCursor()->obtenerArribo()){
				encontro = true;
			}
		}
		if(!encontro){
			Lista<Arribo*>* arribos = destinos->obtener(posicion)->obtenerArribos();
			arribos->iniciarCursor();
			while(arribos->avanzarCursor()){
				arribosOrigen->agregar(new Arribo(destinos->obtener(posicion)->obtenerSalidaDelViaje(),
						INF, arribos->obtenerCursor()->obtenerCultivo() ));
			}
		}
	}
}
void AdministradorDeCatalogoDestinos::cargarStringADestino(std::string getLinea){

	int i=0;
	bool encontro = false;

	Traductor Traductor;

	//crea un vector para almacenar cada dato del txt.
	std::string vectorDeStrings[4];

	//carga el vector con los datos de la linea
	for (int j=0; j<= 3; j++){
		while(getLinea[i] != ',' && getLinea[i]!= '\0'){
			vectorDeStrings[j] =  vectorDeStrings[j] + getLinea[i];
			i++;
		}
		i++;
	}




	std::string puntoSalida = vectorDeStrings[0];

	std::string puntoLlegada = vectorDeStrings[1];

	int costo = Traductor.convertirAEntero(vectorDeStrings[2]);

	std::string cultivo=vectorDeStrings[3];

	Arribo* arribo  = new Arribo(puntoLlegada, costo, cultivo);
	// HIPOTESIS = en el TXT las salidas se encuentran de manera consecutiva (una debajo de la otra).
	if(!destinos->estaVacia()){
		destinos->iniciarCursor();
		while(destinos->avanzarCursor() && !encontro){
			Viaje* viaje = destinos->obtenerCursor();
			if(viaje->obtenerSalidaDelViaje() == puntoSalida){
				viaje->agregarArribo(arribo);
				encontro = true;
			}
		}
		if(!encontro){
			this->destinos->agregar(new Viaje(puntoSalida, arribo));
		}
	}
	else{
		this->destinos->agregar(new Viaje(puntoSalida, arribo));
	}

	this->completarCatalogo(this->destinos);



}




Lista<Viaje*>* AdministradorDeCatalogoDestinos::obtenerListaDeDestinos(){

	return this ->destinos;
}




AdministradorDeCatalogoDestinos::~AdministradorDeCatalogoDestinos(){

	destinos->iniciarCursor();

	while (destinos->avanzarCursor()){
		Viaje* viaje = destinos->obtenerCursor();

		Lista<Arribo*>* arribos = viaje->obtenerArribos();
		arribos->iniciarCursor();
		while(arribos->avanzarCursor()){
			Arribo* arribo = arribos->obtenerCursor();

			delete arribo;
		}

		delete viaje;
	}

	delete this ->destinos;

}



