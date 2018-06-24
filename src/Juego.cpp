/*
 * Juego.cpp
 *
 *  Created on: 19 may. 2018
 *      Author: daniela
 */

#include "Juego.h"
#include <string>
using namespace std;


Juego::Juego(unsigned int cantidadJugadores){

	this->cantidadJugadores = cantidadJugadores;
	this->jugadores = new Lista<Jugador*>;
}

unsigned int Juego::obtenerCantidadJugadores(){

	return this->cantidadJugadores;
}

Jugador* Juego::accederAJugador(unsigned int posicion){

	unsigned int posicionLista = 1;
	Jugador* jugador = NULL;
	this->jugadores->iniciarCursor();
	while (this->jugadores->avanzarCursor()) {
		Jugador* jugadorActual = this->jugadores->obtenerCursor();
		if (posicion == posicionLista){
			jugador = jugadorActual;
		}
		posicionLista++;
	}
	return jugador;
}

void Juego::agregarJugador(float dificultad, std::string nombre, unsigned int filas, unsigned int columnas){

	Jugador* jugador = new Jugador(dificultad, nombre, filas, columnas);
	this->jugadores->agregar(jugador);
}

Lista<Jugador*>* Juego::obtenerJugadores(){

	return this->jugadores;
}


Juego::~Juego(){

	this->jugadores->iniciarCursor();

	while (this->jugadores->avanzarCursor()){
		Jugador* PtrABorrar = this->jugadores->obtenerCursor();

		delete PtrABorrar;
	}

	delete this->jugadores;
}


