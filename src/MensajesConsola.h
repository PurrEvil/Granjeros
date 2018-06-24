/*
 * MensajeError.h
 *
 *  Created on: 25 may. 2018
 *      Author: daniela
 */

#ifndef MENSAJESCONSOLA_H_
#define MENSAJESCONSOLA_H_

#include "Semilla.h"

class MensajesConsola {

	public:
		void almacenLleno(){
			std::cout << "No hay espacio disponible para guardar la cosecha" << std::endl;
		}

		void almacenVacio(){
			std::cout << "No tiene envios pendientes" << std::endl;
		}

		void saldoInsuficiente(){
			std::cout << "Saldo insuficiente" << std::endl;
		}

		void parcelaNoDisponible(){
			std::cout << "La parcela no esta disponible para realizar esta accion" << std::endl;
		}

		void aguaInsuficiente(){
			std::cout << "Cantidad de agua insuficiente" << std::endl;
		}

		void parcelaSeca(unsigned int fila, unsigned int columna){
			std::cout << "Ha perdido el cultivo (" << fila <<","<< columna <<") por falta de riego" << std::endl;
		}

		void parcelaPodrida (unsigned int fila, unsigned int columna){
			std::cout << "Ha perdido el cultivo (" << fila <<","<< columna <<") por no cosecharlo a tiempo" << std::endl;
		}

		void opcionInvalida (){
			std::cout << "La opcion ingresada es invalida. Vuelva a ingresar" << std::endl;
		}
		void ventaTerrenoCancelada(){
			std::cout << "No puede vender el unico terreno del que dispone"<<std::endl;
		}
		void salioDelJuego(){
			std::cout << "Ha salido del juego"<<std::endl;
		}
		void filaColumnaInvalida(){
			std::cout << "Fila o columna fuera de rango. Vuelva a ingresar."<<std::endl;
		}

		void datosComienzoDeTurno(unsigned int agua, unsigned int creditos) {
			std::cout << "Usted cuenta con: " << std::endl;
			std::cout << agua << " unidades de riego" << std::endl;
			std::cout << creditos << " creditos" << std::endl;
		}

		void parcelaSembrada (Semilla* semilla, unsigned int creditos){
			std::cout << "Se ha plantado " << semilla->obtenerNombre() << " exitosamente!" << std::endl;
			std::cout << "Creditos: " << creditos << std::endl;
			std::cout << "Tiempo de crecimiento: " << semilla->obtenerTiempoCrecimiento() << " turno/s\n" << std::endl;
		}

		void parcelaRegada (int tiempo, unsigned int agua){

			std::cout << "Se ha regado la parcela exitosamente!" << std::endl;
			std::cout << "Tiempo de crecimiento restante: " << tiempo << " turno/s\n" << std::endl;
			std::cout << "Unidades de riego: " << agua << "\n" << std::endl;
		}

		void parcelaCosechada(Semilla* semilla){
			std::cout << "Se ha cosechado una unidad de " << semilla->obtenerNombre() << std::endl;
			std::cout << "por un valor de "<<semilla->obtenerRentabilidad()<<" creditos."<< std::endl;
			std::cout << "Para acreditar el monto, recuerde efectuar el envio a destino." << std::endl;
			std::cout << "Tiempo de recuperacion de la tierra: " << semilla->obtenerTiempoRecuperacion() << " turno/s\n" << std::endl;
		}

		void actualizacionPropiedadesCreditos(unsigned int cantidadTerrenos, unsigned int creditos){
			std::cout <<"Tiene:" << cantidadTerrenos << " propiedad/es" << std::endl;
			std::cout << "Creditos: " << creditos << std::endl;

		}

		void cosechasEnviadas (int cantidadCosechas, std::string cosecha, unsigned int creditos){
			std::cout << "Se enviaron " << cantidadCosechas << " de " << cosecha << std::endl;
			std::cout << "Creditos: " << creditos << std::endl;
		}

		void capacidadAdquirida(unsigned int capacidad, unsigned int creditos){
			std::cout << "Ha adquirido capacidad para " << capacidad << " unidades" << std::endl;
			std::cout << "Creditos: " << creditos << std::endl;
		}

};



#endif /* MENSAJESCONSOLA_H_ */
