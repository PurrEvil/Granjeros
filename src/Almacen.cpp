/*
 * Almacen.cpp
 *
 *  Created on: 16 may. 2018
 *      Author: purrevil
 */


#include "Almacen.h"

Almacen::Almacen(float dificultad)
{
	this->cosechas = new Lista<Cosecha*>;
	this->capacidadDeUnAlmacen = (2*CAPACIDAD_BASE_ALMACEN)/dificultad;
	this->capacidadTotal = this->capacidadDeUnAlmacen;
	this->capacidadOcupada = 0;
}

unsigned int Almacen::obtenerCapacidadDeUnAlmacen(){
	return this->capacidadDeUnAlmacen;
}

Lista<Cosecha*>* Almacen::obtenerCosechas()
{
	return this->cosechas;
}


unsigned int Almacen::obtenerCapacidadDisponible()
{
	return this->capacidadTotal - this->capacidadOcupada;
}


unsigned int Almacen::obtenerCapacidadOcupada()
{
	return this->capacidadOcupada;
}

unsigned int Almacen::obtenerCapacidadTotal()
{
	return this->capacidadTotal;
}

void Almacen::agregarCapacidadTotal()
{
	this->capacidadTotal+=this->capacidadDeUnAlmacen;
}

void Almacen::ocuparUnLugar()
{
	if (hayLugar()){
		this->capacidadOcupada++;
	}
}

void Almacen::liberarUnLugar()
{
	if(this->capacidadOcupada > 0)
			this->capacidadOcupada--;
}

bool Almacen::hayLugar()
{
	return ((this->capacidadTotal - this->capacidadOcupada)>0);
}

Cosecha* Almacen::obtenerCosecha(std::string tipoCosecha)
{
	bool encontroCosecha = false;
	Cosecha* punteroACosecha = NULL;
	this->cosechas->iniciarCursor();
	while(this->cosechas->avanzarCursor() && !encontroCosecha){
		if(this->cosechas->obtenerCursor()->obtenerTipoCosecha() == tipoCosecha)
		{
			encontroCosecha = true;
			punteroACosecha = this->cosechas->obtenerCursor();
		}
	}
		return punteroACosecha;
}

Cosecha* Almacen::obtenerCosecha(unsigned int posicion){
	Cosecha* cosecha = NULL;
	unsigned int posicionLista = 1;

	this->cosechas->iniciarCursor();

	while(this->cosechas->avanzarCursor()){
		Cosecha* cosechaActual = this->cosechas->obtenerCursor();

		if(posicionLista == posicion){
			cosecha = cosechaActual;
		}
		posicionLista++;
	}
	return cosecha;
}


int Almacen::agregarUnaCosecha(std::string tipoCosecha)
{
	MensajesConsola mensaje;
	int cosechaAgregada = 0;
	if(hayLugar()){
		if(obtenerCosecha(tipoCosecha) != NULL)
		{
			obtenerCosecha(tipoCosecha)->agregarUnaUnidadDeCosecha();
		}
		else
		{
			this->cosechas->agregar(new Cosecha(tipoCosecha, 1));
			}
		cosechaAgregada = 1;
		ocuparUnLugar();
	}
	else {
		mensaje.almacenLleno();
	}
	return cosechaAgregada;
}

int Almacen::obtenerCantidadDeUnaCosecha(Cosecha* cosecha)
{
	int cantidad = 0;
	if(cosecha != NULL){
		cantidad = cosecha->obtenerCantidad();
	}
	return cantidad;
}

int Almacen::obtenerCantidadDeUnaCosecha(std::string tipoCosecha)
{
	int cantidad = 0;
	if(obtenerCosecha(tipoCosecha) != NULL){
		cantidad = obtenerCosecha(tipoCosecha)->obtenerCantidad();
	}
	return cantidad;
}

unsigned int Almacen::eliminarUnaCosecha(unsigned int posicion)
{
	Cosecha* cosechaEnviada = obtenerCosecha(posicion);
	unsigned int cantidadEnviada = this->obtenerCantidadDeUnaCosecha(cosechaEnviada);
	cosechaEnviada->eliminarCantidadCosecha();
	delete cosechaEnviada;
	this->cosechas->remover(posicion);
	this->capacidadOcupada -= cantidadEnviada;
	return cantidadEnviada;
}

unsigned int Almacen::obtenerCantidadCosechasDistintas(){
	return this->cosechas->contarElementos();
}

bool Almacen::almacenVacio(){
	return (this->obtenerCantidadCosechasDistintas() == 0);
}

Almacen::~Almacen()
{
	this->cosechas->iniciarCursor();
	while(this->cosechas->avanzarCursor()){
		Cosecha* cosechaABorrar = cosechas->obtenerCursor();
		delete cosechaABorrar;
	}

	delete this->cosechas;

}
