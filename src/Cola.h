/*
 * Cola.h
 *
 *  Created on: 25 jun. 2018
 *      Author: purrevil
 */

#ifndef COLA_H_
#define COLA_H_
#include "Nodo.h"

template<class T>

class Cola{

private:
	Nodo<T>* primero;
	Nodo<T>* ultimo;
	unsigned int tamanio;
	Nodo<T>* obtenerNodo(unsigned int posicion);
	void asignar(T elemento, unsigned int posicion, unsigned int prioridad);
	void intercambiar(unsigned int posicionPadre, unsigned int posicionHijo);

public:
	Cola();
	void acolar(unsigned int prioridad, T dato);
	T desacolar();
	bool estaVacia();
	T obtenerFrente();
	unsigned int obtenerPosicion(T dato);
	void bajar(unsigned int posicionPadre);
	T obtenerDato(unsigned int posicion);
	T quitarRaiz();
	unsigned int obtenerTamanio();


	~Cola();
};

template <class T> unsigned int Cola<T>::obtenerTamanio(){
	return this->tamanio;
}

template <class T> void Cola<T>::intercambiar(unsigned int posicionPadre, unsigned int posicionHijo){

	T datoPadre = this->obtenerNodo(posicionPadre)->obtenerDato();
	unsigned int prioridadPadre = this->obtenerNodo(posicionPadre)->obtenerPrioridad();
	// cambia el dato del padre por el dato del hijo
	this->obtenerNodo(posicionPadre)->cambiarDato(this->obtenerNodo(posicionHijo)->obtenerDato());
	//cambia la prioridad del padre por la prioridad del hijo
	this->obtenerNodo(posicionPadre)->cambiarPrioridad(this->obtenerNodo(posicionHijo)->obtenerPrioridad());

	this->obtenerNodo(posicionHijo)->cambiarDato(datoPadre);
	this->obtenerNodo(posicionHijo)->cambiarPrioridad(prioridadPadre);


}

template <class T> T Cola<T>::obtenerDato(unsigned int posicion){
	T dato;
	if(0<posicion && posicion<=this->tamanio){
		dato = this->obtenerNodo(posicion)->obtenerDato();
	}
	return dato;
}

template <class T> unsigned int Cola<T>::obtenerPosicion(T dato){
	unsigned int posicion = 1;
	unsigned int posicionADevolver;
	bool encontro = false;
	while(posicion <=this->tamanio && !encontro){
		if(this->obtenerDato(posicion)==dato){
			posicionADevolver = posicion;
			encontro = true;
		}
	}
	return posicionADevolver;
}
template <class T> T Cola<T>::obtenerFrente(){
	return this->primero;
}
template <class T> Cola<T>::Cola(){
	this->primero = NULL;
	this->ultimo = NULL;
	this->tamanio = 0;
}
template<class T> void Cola<T>::acolar(unsigned int prioridad, T dato){
	Nodo<T>* nuevoNodo = new Nodo<T>(prioridad, dato);
	bool intercambio = false;
	if(estaVacia()){
		this->primero = nuevoNodo;
		this->ultimo = nuevoNodo;
	}
	else if(this->primero->obtenerPrioridad()>prioridad){
		nuevoNodo->cambiarSiguiente(this->primero);
		this->primero = nuevoNodo;
	}
	else if(this->ultimo->obtenerPrioridad() <= prioridad){
		this->ultimo->cambiarSiguiente(nuevoNodo);
		this->ultimo = nuevoNodo;
	}
	else{
		Nodo<T> * nodoActual = this->primero;
		while(nodoActual->obtenerSiguiente() != NULL && !intercambio){
			if((nodoActual->obtenerPrioridad() < prioridad) && (nodoActual->obtenerSiguiente()->obtenerPrioridad()> prioridad)){
				nuevoNodo->cambiarSiguiente(nodoActual->obtenerSiguiente());
				nodoActual->cambiarSiguiente(nuevoNodo);
				intercambio = true;
			}
			nodoActual = nodoActual->obtenerSiguiente();
		}
	}
	this->tamanio++;
}

template<class T> bool Cola<T>::estaVacia(){
	return this->tamanio == 0;
}
template<class T> T Cola<T>::desacolar(){
	if (this->estaVacia()) {
	        throw std::string("No se puede desacolar, la cola está vacía.");
	    }

	    Nodo<T>* frenteAnterior = this->primero;
	    this->primero = frenteAnterior->obtenerSiguiente();

	    if (this->primero == NULL) {
	        this->ultimo = NULL;
	    }

	    /* devuelve el elemento y libera los recursos asociados */
	    T elemento = frenteAnterior->obtenerDato();
	    delete frenteAnterior;
	    this->tamanio--;

	    return elemento;
	}


template<class T> Nodo<T>* Cola<T>::obtenerNodo(unsigned int posicion){
    Nodo<T>* actual = this->primero;
    for (unsigned int i = 1; i < posicion; i++) {

        actual = actual->obtenerSiguiente();
    }

    return actual;
}

template<class T> void Cola<T>::bajar(unsigned int posicionPadre){
	bool termino = false;
	unsigned int posicionHijoMenor = posicionPadre*2;
	while(posicionHijoMenor<= this->tamanio && !termino){
		if(posicionHijoMenor < this->tamanio && obtenerNodo(posicionHijoMenor)->obtenerPrioridad() > obtenerNodo(posicionHijoMenor+1)->obtenerPrioridad()){
			posicionHijoMenor++;
		}
		if(obtenerNodo(posicionPadre)->obtenerPrioridad() > obtenerNodo(posicionHijoMenor)->obtenerPrioridad()){
			this->intercambiar(posicionPadre, posicionHijoMenor);
			posicionPadre = posicionHijoMenor;
			posicionHijoMenor = posicionPadre*2;
		}
		else{
			termino = true;
		}

	}
}

template<class T> T Cola<T>::quitarRaiz(){
	T dato = this->obtenerDato(1);
	this->intercambiar(1,this->tamanio);
	this->tamanio--;
	this->bajar(1);
	return dato;
}

template<class T> Cola<T>::~Cola(){
	while(!estaVacia()){
		this->desacolar();
	}

}


#endif /* COLA_H_ */
