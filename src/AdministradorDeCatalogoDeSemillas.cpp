/*
 * cargarCatalogoSemillas.cpp
 *
 *  Created on: 17 may. 2018
 *      Author: daniela
 */

#include <fstream>
#include <sstream>
#include "AdministradorDeCatalogoDeSemillas.h"

using namespace std;


AdministradorDeCatalogoDeSemillas::AdministradorDeCatalogoDeSemillas(){

	this->semillas = new Lista<Semilla*>;
}

void AdministradorDeCatalogoDeSemillas::leerArchivo(std::string rutaEntrada) {
	std::ifstream archivo;
	archivo.open(rutaEntrada.c_str());
	std::string linea;
	while (getline(archivo,linea)){
		this->cargarStringASemilla(linea);
	};
	archivo.close();
}

void AdministradorDeCatalogoDeSemillas::cargarStringASemilla(std::string getLinea){

	int i=0;

	Traductor traductor;

	//crea un vector para almacenar cada dato del txt.
	std::string vectorDeStrings[CANTIDAD_DATOS_SEMILLAS];

	//carga el vector con los datos de la linea
	for (int j=0; j<= (CANTIDAD_DATOS_SEMILLAS-1); j++){ //
		while(getLinea[i] != ',' && getLinea[i]!= '\0'){
			vectorDeStrings[j] =  vectorDeStrings[j] + getLinea[i];
			i++;
		}
		i++;
	}

	Semilla* punteroSemilla;

	std::string nombre = vectorDeStrings[0];

	int costo = traductor.convertirAEntero(vectorDeStrings[1]);

	int rentabilidad = traductor.convertirAEntero(vectorDeStrings[2]);

	int tiempoCrecimiento = traductor.convertirAEntero(vectorDeStrings[3]);

	int tiempoRecuperacion = traductor.convertirAEntero(vectorDeStrings[4]);

	int consumoAgua = traductor.convertirAEntero(vectorDeStrings[5]);

	/*asigno un espacio en el heap para un puntero a una Semilla*/
	punteroSemilla = new Semilla(nombre, costo, rentabilidad,
			tiempoCrecimiento, tiempoRecuperacion, consumoAgua);

	this->semillas->agregar(punteroSemilla);

}

Lista<Semilla*>* AdministradorDeCatalogoDeSemillas::obtenerListaDeSemillas(){

	return this->semillas;
}

unsigned int AdministradorDeCatalogoDeSemillas::obtenerCantidadSemillas(){
	return this->semillas->contarElementos();
}

AdministradorDeCatalogoDeSemillas::~AdministradorDeCatalogoDeSemillas(){

	semillas->iniciarCursor();

	while (semillas->avanzarCursor()){
		Semilla* PtrABorrar = semillas->obtenerCursor();

		delete PtrABorrar;
	}

	delete this->semillas;

}
