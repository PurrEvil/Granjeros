/*
 * Dificultad.cpp
 *
 *  Created on: 10 jun. 2018
 *      Author: daniela
 */
#include "SelectorDeDificultad.h"

float SelectorDeDificultad::obtenerDificultad(unsigned int dificultadElegida){
	float dificultad;
		switch (dificultadElegida){
			case 1: dificultad = 0.5;
					break;
			case 2: dificultad = 1.0;
					break;
			case 3: dificultad = 1.5;
					break;
		}
	return dificultad;
}



