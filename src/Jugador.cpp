/*
 * Jugadores.cpp
 *
 *  Created on: 19 may. 2018
 *      Author: daniela
 */
#include <string>
#include "Jugador.h"
using namespace std;

Jugador::Jugador(float dificultad, string nombre, unsigned int filas, unsigned int columnas){

	this->nombre = nombre;
	this->creditos = new Creditos(dificultad);
	this->cantidadCreditos = creditos->obtenerCreditos();
	this->listaTerrenos = new Propiedades(dificultad, filas, columnas);
	this->tanqueDeAgua = new Tanque(dificultad);
	this->almacen = new Almacen (dificultad);
}

string Jugador::obtenerNombre() {

	return this->nombre;
}

unsigned int Jugador::obtenerCantidadCreditos(){

	this->cantidadCreditos = this->creditos->obtenerCreditos();
	return this->cantidadCreditos;
}

Propiedades* Jugador::obtenerTerrenos(){

	return this->listaTerrenos;
}

Creditos* Jugador::obtenerCreditos(){

	return this->creditos;
}

Tanque* Jugador::obtenerTanqueDeAgua(){

	return this->tanqueDeAgua;
}

Almacen* Jugador::obtenerAlmacen(){

	return this->almacen;
}

bool Jugador::tieneMasCreditosQue(Jugador* otroJugador){
	return (this->obtenerCantidadCreditos() > otroJugador->obtenerCantidadCreditos());
}

Jugador::~Jugador(){
	delete this->almacen;
	delete this->creditos;
	delete this->listaTerrenos;
	delete this->tanqueDeAgua;
}
