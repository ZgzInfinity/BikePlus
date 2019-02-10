/*********************************************************************************
 * Autores: ZgzInfinity
 * Fecha: 8-2-2019
 * Resumen: Fichero de prueba del módulo «bizi-uso» para trabajar con
 *          registros que representan estaciones del sistema Bizi Zaragoza.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
 ********************************************************************************/
 
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Bizi-usos.h"

using namespace std;

const int MAX_LONG_NOMBRE_FICHERO = 20;

/*
 * El programa pide al usuario que introduzca por teclado un 
 * fichero de usos de bizi Zaragoza. Una vez que es introducido
 * muestra por pantalla cuántos usos se han realizado en total,
 * y cuántos usos han sido normales y circulares, respectivamente.
 * 
 * Si ocurre algún error de lectura de fichero el programa le informa
 * al usuario del ello
 */
int main(){
	
	// fichero de usos de bizi Zaragoza
	char nombreFichero[MAX_LONG_NOMBRE_FICHERO];
	// Solicitud al usuario del fichero de usos de bizi
	cout << "Escriba el nombre de un fichero de usos del sistema Bizi: " << flush;
	cin >> nombreFichero;
	
	// incialización de los contadores de tipos de uso 
	int numTraslados = 0, numCirculares = 0;
	
	// conteo de los usos
	contarUsos(nombreFichero, numTraslados, numCirculares);
	
	// muestreo por pantalla de los resultados obtenidos y fin de ejecuón
	cout << endl;
	cout << "Numero de usos como traslado: " << numTraslados << endl;
	cout << "Numero de usos circulares: " << numCirculares << endl;
	cout << "Numero de usos totales: " << numTraslados + numCirculares << endl;
	
	return 0;
}