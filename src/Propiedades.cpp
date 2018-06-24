/*
 * Inmobiliaria.cpp
 *
 *  Created on: 12 may. 2018
 *      Author: daniela
 */
#include "Propiedades.h"
#include <string>

using namespace std;

Propiedades::Propiedades(float dificultad, unsigned int filas, unsigned int columnas){

	this->terrenos = new Lista<Terreno*>;
	unsigned int valorTerrenoInicial = CANTIDAD_BASE_PARCELAS*dificultad*IMPUESTO_A_LA_COMPRA;
	Terreno* terrenoInicial = new Terreno(filas, columnas, valorTerrenoInicial);
	this->terrenos->agregar(terrenoInicial);
}

Terreno* Propiedades::comprarTerreno(Creditos* creditosDisponibles, unsigned int filas, unsigned int columnas, float dificultad,  unsigned int parcelasAComprar) {
		MensajesConsola mensaje;
		Terreno* terrenoNuevo = NULL;
		unsigned int valorTerreno = this->obtenerValorTerrenoParaCompra(this->obtenerCantidadParcelasTotales(),dificultad,parcelasAComprar);
		if (creditosDisponibles->hayCreditosSuficientes(valorTerreno)){
			creditosDisponibles->comprar(valorTerreno);
			terrenoNuevo = new Terreno(filas, columnas, valorTerreno);
			this->terrenos->agregar(terrenoNuevo);
		} else {
			mensaje.saldoInsuficiente();
		}
		return terrenoNuevo;
	}

void Propiedades::venderTerreno(Terreno* terrenoEnVenta, Creditos* creditosDisponibles) {

	bool vendido = false;
	unsigned int posicion = 0;
	unsigned int valorTerrenoActual;
	this->terrenos->iniciarCursor();
	while (this->terrenos->avanzarCursor() && !vendido) {
		Terreno* terrenoActual = this->terrenos->obtenerCursor();
		vendido = (terrenoActual == terrenoEnVenta);
		valorTerrenoActual = terrenoActual->obtenerValor();
		posicion++;
	}
	if (vendido) {
		this->terrenos->remover(posicion);
		creditosDisponibles->vender(valorTerrenoActual/IMPUESTO_A_LA_VENTA);
	}
}

Lista<Terreno*>* Propiedades::obtenerTerrenos() {

	return this->terrenos;

}

Terreno* Propiedades::accederATerreno(unsigned int posicion){

	unsigned int posicionLista = 1;
	Terreno* terreno = NULL;
	this->terrenos->iniciarCursor();
	while (this->terrenos->avanzarCursor()) {
		Terreno* terrenoActual = this->terrenos->obtenerCursor();
		if ((posicion) == posicionLista){
			terreno = terrenoActual;
		}
		posicionLista++;
	}
	return terreno;
}

unsigned int Propiedades::obtenerCantidadTerrenos() {
	return this->obtenerTerrenos()->contarElementos();
}

unsigned int Propiedades::obtenerCantidadParcelasTotales(){
	unsigned int cantidadParcelasTotales = 0;
	this->terrenos->iniciarCursor();
	while (this->terrenos->avanzarCursor()){
		Terreno* terrenoActual= this->terrenos->obtenerCursor();
		cantidadParcelasTotales += terrenoActual->obtenerCantidadParcelas();
	}
	return cantidadParcelasTotales;
}

unsigned int Propiedades::obtenerValorTerrenoParaCompra(unsigned int cantidadParcelasTotales, float dificultad, unsigned int parcelasAComprar){

	return (cantidadParcelasTotales*dificultad*parcelasAComprar*IMPUESTO_A_LA_COMPRA);
}

Propiedades::~Propiedades() {

	terrenos->iniciarCursor();

	while (terrenos->avanzarCursor()){
		Terreno* PtrABorrar = terrenos->obtenerCursor();
		delete PtrABorrar;
	}

	delete this->terrenos;

}
