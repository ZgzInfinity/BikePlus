/*********************************************************************************
 * Autores: ZgzInfinity
 * Fecha: 8-2-2019
 * Resumen: Fichero de prueba del módulo «bizi-estacion» para trabajar con
 *          registros que representan estaciones del sistema Bizi Zaragoza.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
 ********************************************************************************/

#include <iostream>
#include <iomanip>
#include "bizi-estacion.h"


const int MAX_LONG_NOMBRE_FICHERO = 20;
const int MAX_LONG_LINEA = 128;

using namespace std;

/*
 * El programa pide al usuario tres ficheros:
 * - un fichero de Usos de Bizi
 * - un fihcero de estaciones de Bizi
 * - un fichero para generar un informe de resultados
 * 
 * Una vez que el usuario proporciona los tres ficheros anteriores
 * por teclado, el programa genera un informe de resultados con el formato
 * especificado a continuación:
 * 
 *           Puesto    Usos  Id Nombre
 *           ------ ------- --- ---------------------------------------
 *                1   47064  16 Plaza España
 *                2   42306  67 Avda. G. Gómez de Avellaneda - C/ Clara Campoamor
 *                3   40251  47 Plaza San Francisco - Universidad
 *          ...
 *
 * En caso de producirse errores al trabajar con los ficheros,
 * el programa informa al usuario con que fichero de los proporcionados 
 * hay problemas.
 */
int main(){
	
	// fichero de usos de bizi Zaragoza
	char ficheroUsosBizi[MAX_LONG_NOMBRE_FICHERO];
	// fichero de estaciones de bizi Zaragoza
	char ficheroEstacionesBizi[MAX_LONG_NOMBRE_FICHERO];
	// fichero que guarda el informe de resultados a generar
	char ficheroInforme[MAX_LONG_NOMBRE_FICHERO];
	
	// El programa pide al usuario la ruta del fichero de usos bizi
	cout << "Escriba el nombre de un fichero de usos del sistema Bizi: " << flush;
	cin.getline(ficheroUsosBizi, MAX_LONG_LINEA, '\n');
	
	// El programa solicita al usuario la ruta del fichero de estaciones de bizi
	cout << "Escriba el nombre de un fichero de estaciones del sistema Bizi: " << flush;
	cin.getline(ficheroEstacionesBizi, MAX_LONG_LINEA, '\n');
	
	//  El programa pide al usuario la ruta del fichero del informe a generar
	cout << "Escriba el nombre de fichero de informe: " << flush;
	cin.getline(ficheroInforme, MAX_LONG_LINEA, '\n');
	
	// vector de estaciones a gestionar
	Estacion estaciones[NUM_ESTACIONES];
	
	// lectura de las estaciones almacenadas en el fichero de estaciones
	leerEstaciones(ficheroEstacionesBizi, estaciones);
	
	// contabilización de usos de las estaciones
	contarUsosEstaciones(ficheroUsosBizi, estaciones);
	
	// ordenación de las estaciones por orden decreciente
	// de usos de bizi
	ordenarPorUso(estaciones);
	
	// Escritura del informe de resultados
	escribirInforme(ficheroInforme, estaciones);
	
	// Muestra por pantalla mensaje de acabado al usuario
	// Fin de ejecución
	cout << "Fichero " << ficheroInforme << " creado correctamente. " << endl;
	return 0;
}