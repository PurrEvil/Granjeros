/*
 * Terreno.cpp
 *
 *  Created on: 12 may. 2018
 *      Author: daniela
 */
#include "Terreno.h"

Terreno::Terreno(unsigned int cantidadFilas, unsigned int cantidadColumnas, unsigned int valor){
	this->posicionTerreno = 1;
	this->accesoAParcela = NULL;
	this->valor = valor;
	this->precioVenta = valor/IMPUESTO_A_LA_VENTA;
	this->cantidadFilas = cantidadFilas;
	this->cantidadColumnas = cantidadColumnas;
	this->terreno = new Lista<Lista<Parcela*>*>;
	for (unsigned int i = 1; i <= this->cantidadFilas; i++) {
		this->parcelas = new Lista<Parcela*>;
		for (unsigned int j = 1; j <= this->cantidadColumnas; j++){
			Parcela* parcelaNueva = new Parcela;
			this->parcelas->agregar(parcelaNueva);
		}
		this->terreno->agregar(this->parcelas);
	}
}

Parcela* Terreno::obtenerParcela(unsigned int posicionFila, unsigned int posicionColumna){
	this->accesoAParcela = this->terreno->obtener(posicionFila)->obtener(posicionColumna);
	return this->accesoAParcela;
}

unsigned int Terreno::obtenerFilas(){
	return this->cantidadFilas;
}

unsigned int Terreno::obtenerColumnas(){
	return this->cantidadColumnas;
}

unsigned int Terreno::obtenerCantidadParcelas(){
	return (this->obtenerFilas()*this->obtenerColumnas());
}

unsigned int Terreno::obtenerValor(){
	return this->valor;
}

unsigned int Terreno::obtenerPrecioVenta(){
	return this->precioVenta;
}

void Terreno::asignarValor(unsigned int cantidadParcelas, float dificultad){
	this->valor = (cantidadParcelas*dificultad*IMPUESTO_A_LA_COMPRA);
}

void Terreno::actualizacionPorTurno(){
	for (unsigned int i=1; i <= this->obtenerFilas(); i++) {
		for (unsigned int j=1; j <= this->obtenerColumnas(); j++){
			this->obtenerParcela(i,j)->verificarParcelaPodrida(i,j);
			this->obtenerParcela(i,j)->verificarParcelaPodrida(i,j);
			this->obtenerParcela(i,j)->verificarParcelaSeca(i,j);
			if (this->obtenerParcela(i,j)->estaCreciendo()){
				this->obtenerParcela(i,j)->actualizarTiempoCrecimiento();
			}
			else if (this->obtenerParcela(i,j)->estaRecuperandose() && !this->obtenerParcela(i,j)->estaPodrido()){
				this->obtenerParcela(i,j)->actualizarTiempoRecuperacion();
			}
			this->obtenerParcela(i,j)->actualizarEstados();
		}
	}
}

Terreno::~Terreno(){
	this->terreno->iniciarCursor();
	while (this->terreno->avanzarCursor()){
		Lista<Parcela*>* filaActual = this->terreno->obtenerCursor();
		filaActual->iniciarCursor();
		while (filaActual->avanzarCursor()){
			Parcela* parcelaActual = filaActual->obtenerCursor();
			delete parcelaActual;
		}
	}
	delete this->parcelas;
	delete this->terreno;
}
