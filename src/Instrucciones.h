/*
 * Instrucciones.h
 *
 *  Created on: 25 may. 2018
 *      Author: daniela
 */

#ifndef INSTRUCCIONES_H_
#define INSTRUCCIONES_H_

class Instrucciones {

	public:
		void mostrarInstrucciones() {
			std::cout << "Granjeros® es un juego de estrategia cuyo objetivo es acumular la mayor cantidad de créditos a través "
					"de la compra y venta de cosechas en un determinado número de turnos." << std::endl;
			std::cout<< "Numero minimo de jugadores : 1"<<std::endl;
			std::cout << "Cada jugador dispondrá, inicialmente, de un terreno, un tanque de agua, un granero para almacenar "
					"las cosechas y una cantidad de créditos, según la dificultad. En cada turno, el jugador cuenta con las "
					"siguientes opciones:" << std::endl;
			std::cout << "1. Operar con parcelas" << std::endl;
			std::cout << "En esta opción el jugador puede optar por las siguientes sub-opciones:" << std::endl;
			std::cout << "Sembrar: Una parcela solo podrá ser sembrada si está disponible para siembra. Una parcela está "
					"disponible para siembra si la parcela indicada no cuenta con ningún otro sembrado o el tiempo de "
					"recuperación correspondiente se ha agotado. Sembrar un determinado tipo de semilla tiene un coste y "
					"rendimiento definidos." << std::endl;
			std::cout << "Regar: Una parcela podrá regarse si y solo si la misma cuenta con alguna siembra. Todos los "
					"sembrados deben regarse en cada turno, de lo contrario, la misma se perderá y la parcela volverá a "
					"estar disponible para siembra en el siguiente turno." << std::endl;
			std::cout << "Cosechar: Una parcela podrá ser cosechada si el tiempo de sembrado se ha agotado. Si transcurrido"
					" este periodo, la parcela no se cosecha, la misma se perderá y se deberá aguardar a que se cumpla el "
					"plazo de recuperación para que la parcela vuelva a estar disponible para sembrar. Cuando una parcela "
					"se cosecha, la misma se almacena automaticamente en el granero para envíos." << std::endl;
			std::cout << "2. Comprar/Vender terrenos" << std::endl;
			std::cout << "Comprar: El jugador podrá adquirir terrenos adicionales (de dimension a eleccion) para continuar "
					"sembrando. Podrá acceder a los mismos desde la opción “Operar con parcelas”." << std::endl;
			std::cout << "Vender: El jugador podrá vender los terrenos adicionales que haya adquirido. El terreno para la "
					"venta puede o no tener parcelas sembradas. Esto no cambiara el valor de venta de la propiedad. "
					"El jugador no podrá, sin embargo, vender todos sus terrenos. Quedará siempre con al menos un terreno "
					"para continuar jugando." << std::endl;
			std::cout << "3.       Enviar cosechas/Comprar graneros" << std::endl;
			std::cout << "Enviar Cosechas: Las cosechas almacenadas podrán ser enviadas a distintos puntos geográficos, "
					"con un costo/redito proporcional a la distancia del lugar respecto a la ubicación del granero." << std::endl;
			std::cout << "Comprar graneros: Cada granero almacena un UNICO tipo de cosecha, con capacidad limitada."
					" El jugador puede aumentar la capacidad de cada granero a través de esta opción." << std::endl;
			std::cout << "4.       Comprar capacidad tanque de agua" << std::endl;
			std::cout << "Cada jugador dispone de una capacidad de agua según el nivel de dificultad. La cantidad de agua "
					"disponible vendrá dada por el valor obtenido del dado que arroje el jugador por un multiplicador, "
					"siendo el resultado la cantidad de agua disponible para riego. Se operara del mismo modo en cada turno "
					"que se ejecute. Si la cantidad de agua superase a la capacidad, el excedente se perderá."
					" Por tal motivo, el jugador podrá incrementar la capacidad de su tanque para minimizar las pérdidas"
					" de agua." << std::endl;
			std::cout << "5.       Terminar turno" << std::endl;
			std::cout << "Se finaliza el turno y se pasa al siguiente jugador." << std::endl;
			std::cout <<  std::endl;
			std::cout << "Se consagra ganador de la partida aquel jugador que logre una mayor cantidad de créditos en el "
					"número de turnos asigna" << std::endl;

	}
};



#endif /* INSTRUCCIONES_H_ */
