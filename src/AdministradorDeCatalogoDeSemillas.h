/*
 * cargarCatalogoSemillas.h
 *
 *  Created on: 17 may. 2018
 *      Author: daniela
 */

#ifndef ADMINISTRADORDECATALOGODESEMILLAS_H_
#define ADMINISTRADORDECATALOGODESEMILLAS_H_

#include "Semilla.h"
#include "Lista.h"
#include "Traductor.h"

const int CANTIDAD_DATOS_SEMILLAS = 6;
const int CANTIDAD_MINIMA_SEMILLAS = 1;

class AdministradorDeCatalogoDeSemillas{

	private:

		Lista<Semilla*>* semillas;

	public:

		/*
		 * post: crea una lista de punteros a clase Cultivo y
		 * la asigna a 'cultivos'
		 */
		AdministradorDeCatalogoDeSemillas();


		/*
		 * post: lee el archivo .txt a recibido por 'rutaEntrada'
		 */
		void leerArchivo(std::string rutaEntrada);


		/*
		 * post: recibe un string tipo getline del metodo leerArchivo
		 * cargar los datos en un vector, los convierte a enteros y se los pasa
		 * al constructor Cultivo y los agrega a la lista 'cultivos'
		 */
		void cargarStringASemilla (std::string stringLinea);

		/*
		 * post: devuelve el atributo 'cultivos'
		 */
		Lista<Semilla*>* obtenerListaDeSemillas();

		/*
		 * post: devuelve la cantidad de semillas que hay en el catalogo
		 */
		unsigned int obtenerCantidadSemillas();

		/*
		 * post: libera cada puntero a semilla que se fueron agregando
		 * como datos a la lista
		 */
		~AdministradorDeCatalogoDeSemillas();

};


#endif /* ADMINISTRADORDECATALOGODESEMILLAS_H_ */
