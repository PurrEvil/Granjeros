/*
 * Menues.h
 *
 *  Created on: 23 may. 2018
 *      Author: daniela
 */

#ifndef MENUES_H_
#define MENUES_H_

class Menu {
public:
	Menu(){
	}

	void principal (){

		std::cout << "\n1. Jugar" << std::endl;
		std::cout << "2. Instrucciones" << std::endl;
		std::cout << "3. Salir" << std::endl;
	}

	void dificultad () {

		std::cout << "\nIngrese el nivel de dificultad:" << std::endl;
		std::cout << "1. Facil" << std::endl;
		std::cout << "2. Intermedio" << std::endl;
		std::cout << "3. Dificil" << std::endl;
	}

	void acciones(){

		std::cout << "\n.:MENU DE JUEGO:." << std::endl;
		std::cout << "1. Operar con parcelas" << std::endl;
		std::cout << "2. Comprar/Vender terrenos" << std::endl;
		std::cout << "3. Enviar cosechas/Comprar graneros" << std::endl;
		std::cout << "4. Comprar capacidad tanque de agua" << std::endl;
		std::cout << "5. Terminar turno" << std::endl;
	}

	void parcelas(){

		std::cout << "\n.:PARCELAS:." << std::endl;
		std::cout << "Ingrese la accion que desea realizar:" << std::endl;
		std::cout << "1. Sembrar Parcela" << std::endl;
		std::cout << "2. Regar Parcela" << std::endl;
		std::cout << "3. Cosechar Parcela" << std::endl;
		std::cout << "4. Volver" << std::endl;
	}

	void terrenos(){

		std::cout << "\n.:TERRENOS.:" << std::endl;
		std::cout << "Ingrese la accion que desea realizar:" << std::endl;
		std::cout << "1. Comprar Terreno" << std::endl;
		std::cout << "2. Vender Terreno" << std::endl;
		std::cout << "3. Volver" << std::endl;
	}

	void almacen(){

		std::cout << "\n.:ALMACEN DE COSECHAS:." << std::endl;
		std::cout << "1. Enviar cosecha" << std::endl;
		std::cout << "2. Comprar capacidad de almacen" << std::endl;
		std::cout << "3. Volver" << std::endl;
	}


};



#endif /* MENUES_H_ */
