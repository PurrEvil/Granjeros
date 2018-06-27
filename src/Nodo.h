/*
 * Nodo.h
 *
 *  Created on: 25 jun. 2018
 *      Author: purrevil
 */

#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif

#ifndef INF
#define INF 100
#endif

template<class T> class Nodo{
private:
	Nodo<T>* siguiente;
	T dato;
	unsigned int* prioridad;


public:
    /*
     * post: el Nodo resulta inicializado con el dato dado
     *       sin un Nodo siguiente y con la mayor prioridad.
     */

	Nodo(T dato){

		this->siguiente = NULL;
		this->dato = dato;
		this->prioridad = NULL;
	}

    /*
     * post: el Nodo resulta inicializado con el dato dado
     *       sin un Nodo siguiente y con la prioridad dada.
     */
	Nodo (unsigned int* prioridad, T dato){

		this->siguiente = NULL;
		this->dato = dato;
		this->prioridad = prioridad;
	}


    /*
     * post: devuelve el siguiente Nodo.
     */

	Nodo<T>* obtenerSiguiente(){
		return this->siguiente;
	}

    /*
     * post: devuelve el valor del dato.
     */

	T obtenerDato(){
		return this->dato;
	}

    /*
     * post: cambia el valor del dato.
     */
	void cambiarDato(T nuevoDato){
		this->dato = nuevoDato;
	}

    /*
     * post: cambia el siguiente Nodo por nuevoSiguiente.
     */
	void cambiarSiguiente(Nodo<T>* nuevoSiguiente){
		this->siguiente = nuevoSiguiente;
	};
	/*
	 * post: devuelve la prioridad
	 */
	unsigned int* obtenerPrioridad(){
		return this->prioridad;
	}

	/*
	 * post: cambia la prioridad por la nuevaPrioridad.
	 */
	void cambiarPrioridad(unsigned int* nuevaPrioridad){
		this->prioridad = nuevaPrioridad;
	}
};
#endif /* NODO_H_ */
