/*
 * main.cpp
 *
 *  Created on: 12 may. 2018
 *      Author: daniela
 */
#include <iostream>
#include <string>

#include "Cola.h"
#include "AdministradorDeCatalogoDeDestinos.h"
#include "AdministradorDeCatalogoDeSemillas.h"
#include "Propiedades.h"
#include "Juego.h"
#include "Turnos.h"
#include "Dado.h"
#include "Menues.h"
#include "BMPTerreno.h"
#include "Transporte.h"
#include "Vendedor.h"
#include "Inmobiliaria.h"
#include "Instrucciones.h"
#include "MensajesConsola.h"
#include "SelectorDeDificultad.h"
#include "Validador.h"


using namespace std;

int main (int argc, char* argv[]){

	Cola<Arribo*> cola;

	AdministradorDeCatalogoDestinos catalogo;

	catalogo.leerArchivo("destinos.txt");

	Lista<Viaje*>* viajes = catalogo.obtenerListaDeDestinos();
	viajes->iniciarCursor();
	viajes->avanzarCursor();

	Viaje* viaje = viajes->obtenerCursor();

	Lista<Arribo*>* listaDestinos = viaje->obtenerArribos();

	listaDestinos->iniciarCursor();
	while(listaDestinos->avanzarCursor()){
		cola.acolar(listaDestinos->obtenerCursor()->obtenerCosto(), listaDestinos->obtenerCursor());
	}

	while(!cola.estaVacia()){
		Arribo* eliminado;
		eliminado = cola.desacolar();
		cout << eliminado->obtenerCosto() << endl;
	}








/*
	Menu menu;
	Instrucciones instrucciones;
	MensajesConsola mensaje;
	Validador validacion;
	SelectorDeDificultad nivelDificultad;
	unsigned int opcionPrincipal, opcionJuego, opcionParcelas, opcionTerreno, opcionAlmacen, opcionSemilla,
				opcionCosecha, opcionContinuarOperacion;
	bool salir=false, jugar=true;
	unsigned int cantidadJugadores, cantidadTotalDeTurnos, cantidadFilas, cantidadColumnas, parcelasAComprar,
				cantidadFilasInicial, cantidadColumnasInicial;
	unsigned int dificultadElegida;
	float dificultad;
	unsigned int terrenoPosicion;
	unsigned int terrenoSeleccionado;
	unsigned int fila, columna;
	string nombre, semilla, cosecha;

	AdministradorDeCatalogoDeSemillas catalogoSemillas;
	AdministradorDeCatalogoDestinos catalogoDestinos;

	catalogoSemillas.leerArchivo("semillas.txt");
	catalogoDestinos.leerArchivo("destinos.txt");
	BMPTerreno bmp;
	Transporte transporte;
	Vendedor vendedor;
	Inmobiliaria bienesRaices;

	cout << ".:Granjeros:." << endl;

while (!salir) {
	menu.principal();

	cin >> opcionPrincipal;

	switch (opcionPrincipal) {
		case 1:	{
				menu.dificultad();
				cin >> dificultadElegida;

				dificultadElegida = validacion.validarOpcion(DIFICULTAD_MINIMA, DIFICULTAD_MAXIMA, dificultadElegida);

				dificultad = nivelDificultad.obtenerDificultad(dificultadElegida);

				cout << "Ingrese la cantidad de jugadores" << endl;

				cin >> cantidadJugadores;
				cantidadJugadores = validacion.validarOpcion(CANTIDAD_MINIMA, cantidadJugadores);

				//crea lista de jugadores y se definen los turnos
				Juego partidaActual(cantidadJugadores);


				cout << "Ingrese la cantidad de turnos que desea que dure la partida" << endl;
				cin >> cantidadTotalDeTurnos;
				cantidadTotalDeTurnos = validacion.validarOpcion(CANTIDAD_MINIMA, cantidadTotalDeTurnos);
				Turnos turnos(cantidadTotalDeTurnos);

				/*
				* crea cada jugador identificado por nombre y los va agregando a la lista de jugadores, a cada jugador
				* se le asigna una lista con propiedades con un terreno inicial
				*/

/*
				for (unsigned int i = 1; i <= partidaActual.obtenerCantidadJugadores(); i++) {
					cout<<"Ingresar nombre jugador n:"<< i << endl;
					cin>>nombre;

					cout << "Indique el tamaño del terreno inicial" << endl;
					cout << "Ingrese la cantidad de filas" << endl;
					cin >> cantidadFilasInicial;
					cantidadFilasInicial = validacion.validarOpcion(CANTIDAD_MINIMA, cantidadFilasInicial);

					cout << "Ingrese la cantidad de columnas" << endl;
					cin >> cantidadColumnasInicial;
					cantidadColumnasInicial = validacion.validarOpcion(CANTIDAD_MINIMA, cantidadColumnasInicial);

					partidaActual.agregarJugador(dificultad, nombre, cantidadFilasInicial, cantidadColumnasInicial);
					Terreno* terrenoInicial = partidaActual.accederAJugador(i)->obtenerTerrenos()->accederATerreno(TERRENO_INICIAL);
					bmp.guardarTerrenoEnBMP(argc, argv,terrenoInicial, nombre, TERRENO_INICIAL);
				}

				Dado dadoDeJuego;
				while (turnos.obtenerTurnoActual() <= turnos.obtenerCantidadTurnosTotales() ){

					for (unsigned int jugadorActual = 1; jugadorActual <= partidaActual.obtenerCantidadJugadores(); jugadorActual++) {
						jugar = true;

						cout << "Turno N: " << turnos.obtenerTurnoActual() << endl;
						string nombreJugador = partidaActual.accederAJugador(jugadorActual)->obtenerNombre();
						cout << "Jugador: " << nombreJugador << endl;

						dadoDeJuego.reiniciarValorDado();
						unsigned int resultadoDado = dadoDeJuego.asignarCantidadAgua();
						cout << "El resultado del dado es: " << resultadoDado <<endl;

						Propiedades* terrenosDisponibles = partidaActual.accederAJugador(jugadorActual)->obtenerTerrenos();
						Creditos* creditosDisponibles = partidaActual.accederAJugador(jugadorActual)->obtenerCreditos();
						Tanque* tanqueDeAgua = partidaActual.accederAJugador(jugadorActual)->obtenerTanqueDeAgua();
						Almacen* almacen = partidaActual.accederAJugador(jugadorActual)->obtenerAlmacen();

						tanqueDeAgua->cargarTanque(dadoDeJuego.obtenerCantidadAgua());

						unsigned int aguaDisponibleTurnoActual = tanqueDeAgua->obtenerCantidadAguaDisponible();

						mensaje.datosComienzoDeTurno(aguaDisponibleTurnoActual, creditosDisponibles->obtenerCreditos());

						while (jugar) {
						menu.acciones();
						cin >> opcionJuego;

						switch (opcionJuego){
							case 1: {
									cout << "Seleccione un terreno:" << endl;
									for (unsigned int j=1; j <= terrenosDisponibles->obtenerCantidadTerrenos() ; j++){
										cout << j << ". Terreno de " << terrenosDisponibles->accederATerreno(j)->obtenerFilas() <<
												"x"<< terrenosDisponibles->accederATerreno(j)->obtenerColumnas() << endl;
									}

									cin >> terrenoSeleccionado;
									terrenoSeleccionado = validacion.validarOpcion(CANTIDAD_MINIMA,
											terrenosDisponibles->obtenerCantidadTerrenos(),terrenoSeleccionado);

									Terreno* terreno = terrenosDisponibles->accederATerreno(terrenoSeleccionado);

									cout << "Seleccione la posicion de la parcela." << endl;
									cout<< "Ingrese la fila"<<endl;
									cin >> fila;
									fila = validacion.validarFilaColumna(terrenosDisponibles->accederATerreno(terrenoSeleccionado)->obtenerFilas(), fila);
									cout<< "Ingrese la columna"<<endl;
									cin >> columna;
									columna = validacion.validarFilaColumna(terrenosDisponibles->accederATerreno(terrenoSeleccionado)->obtenerColumnas(), columna);

									menu.parcelas();
									cin >> opcionParcelas;

									CatalogoSemillas informacionCultivo;

									switch (opcionParcelas){
										case 1:	{
												cout << "SEMILLAS DISPONIBLES" << endl;
												for (unsigned int posicionSemilla=1; posicionSemilla <= catalogoSemillas.obtenerCantidadSemillas(); posicionSemilla++) {
													Semilla* semillaActual = informacionCultivo.obtenerInformacionSemilla(catalogoSemillas.obtenerListaDeSemillas(),
															posicionSemilla);
													cout << posicionSemilla <<". " << semillaActual->obtenerNombre() << endl;
												}

												cout << "Ingrese la semilla que desea sembrar" << endl;

												cin >> opcionSemilla;

												opcionSemilla = validacion.validarOpcion(CANTIDAD_MINIMA,
														catalogoSemillas.obtenerCantidadSemillas(),opcionSemilla);

												Semilla* semillaSeleccionada = informacionCultivo.obtenerInformacionSemilla(catalogoSemillas.obtenerListaDeSemillas(),
														opcionSemilla);


												if (!(terreno->obtenerParcela(fila, columna)->sembrado())){

													terreno->obtenerParcela(fila, columna)->sembrarParcela(semillaSeleccionada, creditosDisponibles);

													bmp.guardarTerrenoEnBMP(argc, argv,terreno, nombreJugador, terrenoSeleccionado);

													if (terreno->obtenerParcela(fila, columna)->sembrado()){

														mensaje.parcelaSembrada(semillaSeleccionada, creditosDisponibles->obtenerCreditos());
													}

												} else {
													mensaje.parcelaNoDisponible();
												}
												}break;

										case 2:{
												semilla = terreno->obtenerParcela(fila, columna)->obtenerCultivo();
												Semilla* semillaARegar = informacionCultivo.obtenerInformacionSemilla(catalogoSemillas.obtenerListaDeSemillas(), semilla);

												if ((!terreno->obtenerParcela(fila, columna)->regado()) && (terreno->obtenerParcela(fila,columna)->estaCreciendo())){
													terreno->obtenerParcela(fila, columna)->regarParcela(semillaARegar, tanqueDeAgua);
													bmp.guardarTerrenoEnBMP(argc, argv,terreno, nombreJugador, terrenoSeleccionado);

													if (terreno->obtenerParcela(fila, columna)->regado()){

														mensaje.parcelaRegada(terreno->obtenerParcela(fila, columna)->obtenerTiempoCrecimiento(),
																tanqueDeAgua->obtenerCantidadAguaDisponible());
													}

												} else {
													mensaje.parcelaNoDisponible();
												}

												}break;


										case 3:{
												semilla = terreno->obtenerParcela(fila, columna)->obtenerCultivo();
												Semilla* semillaACosechar = informacionCultivo.obtenerInformacionSemilla(catalogoSemillas.obtenerListaDeSemillas(),
														semilla);
												if (terreno->obtenerParcela(fila, columna)->listoParaCosechar()){
													terreno->obtenerParcela(fila, columna)->cosecharParcela(semillaACosechar);
													almacen->agregarUnaCosecha(semillaACosechar->obtenerNombre());

													bmp.guardarTerrenoEnBMP(argc, argv,terreno, nombreJugador, terrenoSeleccionado);

													if (terreno->obtenerParcela(fila, columna)->cosechado()){

														mensaje.parcelaCosechada(semillaACosechar);
														cout << "Capacidad de almacen disponible: " << almacen->obtenerCapacidadDisponible() << endl;

													}
												}else {
													mensaje.parcelaNoDisponible();
												}
												}break;

										case 4: break;

										default: mensaje.opcionInvalida();
									}

									}break;

							case 2:{
									menu.terrenos();
									cin >> opcionTerreno;

									switch (opcionTerreno){
										case 1: {

											cout << "Indique el tamaño del terreno que desea comprar" << endl;

											cout << "Ingrese la cantidad de filas" << endl;
											cin >> cantidadFilas;
											cantidadFilas = validacion.validarOpcion(CANTIDAD_MINIMA, cantidadFilas);

											cout << "Ingrese la cantidad de columnas" << endl;
											cin >> cantidadColumnas;
											cantidadColumnas = validacion.validarOpcion(CANTIDAD_MINIMA, cantidadColumnas);
											parcelasAComprar = cantidadFilas*cantidadColumnas;

											cout << "El terreno de "<< cantidadFilas << "x" << cantidadColumnas << " tiene un costo de: " <<
													terrenosDisponibles->obtenerValorTerrenoParaCompra(terrenosDisponibles->obtenerCantidadParcelasTotales(), dificultad, parcelasAComprar) << " creditos" << endl;
											cout << "Desea continuar con la operacion?" << endl;
											cout << "1. Si" << endl;
											cout << "2. No" << endl;

											cin >> opcionContinuarOperacion;

											switch (opcionContinuarOperacion){
												case 1: {
														Terreno* terrenoNuevo = terrenosDisponibles->comprarTerreno(creditosDisponibles, cantidadFilas,
																cantidadColumnas, dificultad, parcelasAComprar);
														mensaje.actualizacionPropiedadesCreditos(terrenosDisponibles->obtenerCantidadTerrenos(),
																creditosDisponibles->obtenerCreditos());
														if (terrenoNuevo != NULL){
															bmp.guardarTerrenoEnBMP(argc, argv, terrenoNuevo, nombreJugador, terrenosDisponibles->obtenerCantidadTerrenos());
														}
														}break;

												case 2: break;

												default: mensaje.opcionInvalida();
											}

											}break;

										case 2: {
												if (terrenosDisponibles->obtenerCantidadTerrenos()>1){
													cout << "Que terreno desea vender?:" << endl;

													for (unsigned int a=1; a <= terrenosDisponibles->obtenerCantidadTerrenos(); a++) {
														Terreno* terrenoDisponible = terrenosDisponibles->accederATerreno(a);
														cout << a << ". Terreno de " << terrenoDisponible->obtenerFilas() <<
																"x"<< terrenoDisponible->obtenerColumnas() <<
																" - Precio de venta: " << terrenosDisponibles->accederATerreno(a)->obtenerPrecioVenta() <<endl;
													}
													cin>>terrenoPosicion;
													terrenoPosicion = validacion.validarOpcion(CANTIDAD_MINIMA, terrenosDisponibles->obtenerCantidadTerrenos(),
															terrenoPosicion);

													Terreno* terrenoEnVenta = terrenosDisponibles->accederATerreno(terrenoPosicion);
													terrenosDisponibles->venderTerreno(terrenoEnVenta, creditosDisponibles);
													mensaje.actualizacionPropiedadesCreditos(terrenosDisponibles->obtenerCantidadTerrenos(),
															creditosDisponibles->obtenerCreditos());

												} else {
													mensaje.ventaTerrenoCancelada();
												}

												}break;

										case 3: break;

										default: mensaje.opcionInvalida();
										}
									}break;

							case 3:{
									menu.almacen();
									cin >> opcionAlmacen;

									switch (opcionAlmacen){
										case 1:{

											if (!almacen->almacenVacio()){
												cout << "COSECHAS DISPONIBLES PARA ENVIO" << endl;
												for (unsigned int posicionCosecha = 1; posicionCosecha <= almacen->obtenerCantidadCosechasDistintas(); posicionCosecha++){
													cout << posicionCosecha << ". " << almacen->obtenerCosecha(posicionCosecha)->obtenerTipoCosecha()
															<<": " << almacen->obtenerCosecha(posicionCosecha)->obtenerCantidad()<< " unidad/es." <<endl;
												}

												cout << "Seleccione la cosecha que desea enviar" << endl;
												cin >> opcionCosecha;
												opcionCosecha = validacion.validarOpcion(CANTIDAD_MINIMA, almacen->obtenerCantidadCosechasDistintas(), opcionCosecha);

												cosecha = almacen->obtenerCosecha(opcionCosecha)->obtenerTipoCosecha();

												cout << "El costo del envio es de: " << transporte.obtenerCostoEnvio(catalogoDestinos.obtenerListaDeDestinos(), almacen, opcionCosecha) << " creditos" << endl;

												unsigned int cantidadCosechasEnviadas = transporte.enviar(catalogoDestinos.obtenerListaDeDestinos(), almacen, opcionCosecha, creditosDisponibles);

												vendedor.vender(cosecha, cantidadCosechasEnviadas, catalogoSemillas.obtenerListaDeSemillas(), creditosDisponibles);

												mensaje.cosechasEnviadas(cantidadCosechasEnviadas, cosecha, creditosDisponibles->obtenerCreditos());
											} else {
												mensaje.almacenVacio();
											}

											}break;

										case 2: {
												bienesRaices.comprarAlmacen(almacen, creditosDisponibles);
												mensaje.capacidadAdquirida(partidaActual.accederAJugador(jugadorActual)->obtenerAlmacen()->obtenerCapacidadTotal(), creditosDisponibles->obtenerCreditos());

												}break;

										case 3: break;

										default: mensaje.opcionInvalida();
									}
									}break;

							case 4:{
									unsigned int costoAumentoDeCapacidad = tanqueDeAgua->obtenerCostoAumentoDeCapacidad();
									if ((creditosDisponibles->obtenerCreditos())>=(costoAumentoDeCapacidad)){
										creditosDisponibles->comprar(costoAumentoDeCapacidad);
										tanqueDeAgua->comprarCapacidad(dificultad);
										mensaje.capacidadAdquirida(tanqueDeAgua->obtenerCapacidadTotal(), creditosDisponibles->obtenerCreditos());
									} else {
										mensaje.saldoInsuficiente();
									}
									}break;

							case 5: jugar = false;
									break;

							default:
									mensaje.opcionInvalida();
							}
						}
						for (unsigned int j=1; j <= terrenosDisponibles->obtenerCantidadTerrenos() ; j++){
							terrenosDisponibles->accederATerreno(j)->actualizacionPorTurno();
							bmp.guardarTerrenoEnBMP(argc, argv, terrenosDisponibles->accederATerreno(j), nombreJugador, j);
						}

					}
					turnos.terminarTurno();

				}
				cout <<"		*********************"<<endl;
				cout <<"		****TABLERO FINAL****" << endl;
				cout <<"		*********************"<<endl;
				Jugador* ganador = partidaActual.accederAJugador(1);
				for (unsigned int numeroJugador = 1; numeroJugador <= partidaActual.obtenerCantidadJugadores(); numeroJugador++){
					cout << partidaActual.accederAJugador(numeroJugador)->obtenerNombre() << ": " << partidaActual.accederAJugador(numeroJugador)->obtenerCantidadCreditos() << " creditos" << endl;
					if (partidaActual.accederAJugador(numeroJugador)->tieneMasCreditosQue(ganador)){
						ganador = partidaActual.accederAJugador(numeroJugador);
					}
				}
				cout << "EL GANADOR ES " << ganador->obtenerNombre() << "!!!" << endl;

				}break;

		case 2:	cout << ".:Instrucciones:." << endl;
				instrucciones.mostrarInstrucciones();
				break;

		case 3: {
				salir = true;
				mensaje.salioDelJuego();
		}
				break;

		default: mensaje.opcionInvalida();
	}
}*/
	return 0;
}



