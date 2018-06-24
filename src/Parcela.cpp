/*
 * Parcela.cpp
 *
 *  Created on: 12 may. 2018
 *      Author: daniela
 */

#include "Parcela.h"
#include "Tanque.h"
#include <string>
using namespace std;

Parcela::Parcela(){
	this->cultivo = "X";
	this->estadoCosecha = false;
	this->estadoRiego = false;
	this->estadoSiembra = false;
	this->tiempoCrecimiento = 0;
	this->tiempoRecuperacion = 0;
	this->podrido = false;
	this->seco = false;
	this->creciendo = false;
	this->recuperandose = false;
}

void Parcela::sembrarParcela(Semilla* semillaSeleccionada, Creditos* creditosDisponibles){
	MensajesConsola mensaje;
	if (creditosDisponibles->hayCreditosSuficientes(semillaSeleccionada->obtenerCostoSemilla())){
		if (this->listoParaSembrar()){
			creditosDisponibles->comprar(semillaSeleccionada->obtenerCostoSemilla());
			this->cultivo = semillaSeleccionada->obtenerNombre();
			this->tiempoCrecimiento = semillaSeleccionada->obtenerTiempoCrecimiento();
			this->tiempoRecuperacion = semillaSeleccionada->obtenerTiempoRecuperacion();
			this->estadoSiembra = true;
			this->recuperandose = false;
		} else {
			mensaje.parcelaNoDisponible();
		}

	} else {
		mensaje.saldoInsuficiente();
	}
}

void Parcela::cosecharParcela(Semilla* semillaSeleccionada){
	MensajesConsola mensaje;
	if (listoParaCosechar()){
		this->cultivo = "X";
		this->estadoCosecha = true;
		this->estadoSiembra = false;
		this->creciendo = false;
	}
	else {
		mensaje.parcelaNoDisponible();
	}
}

void Parcela::regarParcela(Semilla* semillaSeleccionada, Tanque* tanqueDeAgua){
	MensajesConsola mensaje;
	unsigned int aguaNecesaria = semillaSeleccionada->obtenerConsumoAgua();
	if (aguaNecesaria <= (tanqueDeAgua->obtenerCantidadAguaDisponible())){
		tanqueDeAgua->utilizarAgua(aguaNecesaria);
		this->estadoRiego = true;
	}else {
		mensaje.aguaInsuficiente();
	}
}

bool Parcela::sembrado(){
	return this->estadoSiembra;
}

bool Parcela::regado(){
	return this->estadoRiego;
}

bool Parcela::cosechado(){
	return this->estadoCosecha;
}

std::string Parcela::obtenerCultivo(){
	return this->cultivo;
}

bool Parcela::estaPodrido(){
	return this->podrido;
}

bool Parcela::estaSeco(){
	return this->seco;
}

int Parcela::obtenerTiempoRecuperacion(){
	return this->tiempoRecuperacion;
}

int Parcela::obtenerTiempoCrecimiento(){
	return this->tiempoCrecimiento;
}

void Parcela::verificarParcelaPodrida(unsigned int fila, unsigned int columna) {
	MensajesConsola mensaje;
	if (this->listoParaCosechar()) {
		this->podrido = true;
		this->cultivo = "X";
		this->tiempoRecuperacion = this->tiempoRecuperacion / 2;
		mensaje.parcelaPodrida(fila, columna);
	}
	else {
		this->podrido = false;
	}
}

void Parcela::verificarParcelaSeca(unsigned int fila, unsigned int columna) {
	MensajesConsola mensaje;
	if ((!this->regado()) && (this->cultivo != "X")){
		this->seco = true;
		this->cultivo = "X";
		this->creciendo = false;
		mensaje.parcelaSeca(fila, columna);
	}
	else {
		this->seco = false;
	}
}

void Parcela::actualizarEstados(){
	this->estadoRiego = false;
	this->estadoSiembra = false;
	this->estadoCosecha = false;
}


void Parcela::actualizarTiempoCrecimiento(){
	this->tiempoCrecimiento--;
}

void Parcela::actualizarTiempoRecuperacion() {
	this->tiempoRecuperacion--;
}

bool Parcela::estaCreciendo(){
	this->creciendo = ((this->tiempoCrecimiento > 0) && (this->cultivo != "X"));
	return this->creciendo;
}

bool Parcela::estaRecuperandose(){
	this->recuperandose = ((this->tiempoRecuperacion > 0) && (this->cultivo == "X"));
	return this->recuperandose;
}

bool Parcela::listoParaCosechar(){
	return (!this->cosechado() && this->obtenerTiempoCrecimiento() == 0 && this->cultivo != "X");
}

bool Parcela::listoParaSembrar() {
	return (!this->sembrado() && this->obtenerTiempoRecuperacion() == 0 && this->cultivo == "X");
}

