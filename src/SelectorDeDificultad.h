/*
 * Dificultad.h
 *
 *  Created on: 10 jun. 2018
 *      Author: daniela
 */

#ifndef SELECTORDEDIFICULTAD_H_
#define SELECTORDEDIFICULTAD_H_

const int DIFICULTAD_MINIMA = 1, DIFICULTAD_MAXIMA = 3;

class SelectorDeDificultad {
	public:

	/*
	 * post: devuelve el valor de la dificultad segun el nivel elegido por el jugador, el cual regulara el proceso del juego
	 */
	float obtenerDificultad (unsigned int dificultadElegida);
};




#endif /* SELECTORDEDIFICULTAD_H_ */
