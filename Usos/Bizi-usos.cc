/*********************************************************************************
 * Autores: ZgzInfinity
 * Fecha: 8-2-2019
 * Resumen: Fichero de implementación del módulo «bizi-usos» para trabajar con
 *          registros que representan utilizaciones del sistema Bizi Zaragoza.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
 ********************************************************************************/

#include <iostream>
#include <fstream>
#include "Bizi-usos.h"

using namespace std;

const int MAX_LONG_TIEMPO = 30;
const int MAX_LONG_LINEA = 128;

/*
 * Pre: <<idUsuario>> es el código identificador de un usuario, 
 *      <<codigoEstacionRetiro>> es el identificador de la estación de la que un
 *      usuario ha retirado una bicicleta, y <<codigoEstacionDevolucion >> es el 
 *      coódigo de identificación de la estación en la que el usuario ha dejado la 
 *      bicicleta después de usarla
 *
 * Post: Se ha creado un dato de tipo <<UsoBizi>> de tal forma que el identificador del
 *       usuario es <<idUsuario, el identificador de la estación de retiro de la bicicleta 
 *       es <<codigoEstacionRetiro>> y el código de la estación donde la bicicleta se ha dejado 
 *       es <<codigoEstacionDevolucion>>
 */
void crearUsoBizi(int idUsuario, int codigoEstacionRetiro, int codigoEstacionDevolucion, UsoBizi& uso){
	uso.codigoUsuario = idUsuario;
	uso.codigoEstacionRetiro = codigoEstacionRetiro;
	uso.codigoEstacionDevolucion = codigoEstacionDevolucion;
}

/*
 * Pre: ---
 * Post: Devuelve el identifcador del usuario que ha
 *       efectuado el uso de la bizi
 */
int codigoDelUsuario(UsoBizi uso){
	return uso.codigoUsuario;
}

/*
 * Pre: ---
 * Post: Devuelve el código de identificación de la 
 *       estación de la que se ha retirado una bicicleta
 */
int codigoDeEstacionRetiro(UsoBizi uso){
	return uso.codigoEstacionRetiro;
}


/*
 * Pre: ---
 * Post: Devuelve el código de identificación de la 
 *       estación en la que se ha depositado la bicicleta
 */
int codigoDeEstacionDevolucion(UsoBizi uso){
	return uso.codigoEstacionDevolucion;
}

/*
 * Pre:  El flujo «f» está asociado con un fichero de texto con el formato de usos
 *       del sistema Bizi establecido en el enunciado y en disposición de
 *       leer desde el principio de una línea distinta a la de la cabecera.
 * Post: Ha intentado leer la línea mencionada en la precondición y, si no se han
 *       terminado los datos del fichero en dicho intento, ha almacenado en los
 *       campos del parámetro «uso» el identificador del usuario al que
 *       corresponde la utilización de la línea leída y los códigos de las
 *       estaciones de retira y devolución de la bicicleta.
 */
void leerUso(ifstream& f, UsoBizi& uso){
	int idUsuario, codigoEstacionRetiro, codigoEstacionDevolucion;
	char tiempo_retirada[MAX_LONG_TIEMPO], tiempo_devolucion[MAX_LONG_TIEMPO];
	// Lectura del identificador del usuario
	f >> idUsuario;
	f.ignore(1, ';');
	// Lectura del instante de retirada de la bicicleta
	f.getline(tiempo_retirada, 50, ';'); 
	// Lectura del código de la estación de retiro
	f >> codigoEstacionRetiro;
	f.ignore(1, ';');
	// Lectura del instante de devoluxión de la bicicleta
	f.getline(tiempo_devolucion, 50, ';');
	// Lectura del código de la estación de devolución
	f >> codigoEstacionDevolucion;
	crearUsoBizi(idUsuario, codigoEstacionRetiro, codigoEstacionDevolucion, uso);
}


/*
 * Pre:  La cadena de caracteres «rutaFichero» respresenta la ruta de acceso y el
 *       nombre de un fichero de texto con el formato de usos del sistema Bizi
 *       establecido en el enunciado.
 * Post: Si el fichero de nombre «rutaFichero» se ha podido abrir y leer
 *       correctamente, la función ha devuelto «true», «traslados» es el número de
 *       usos entre estaciones distintas del sistema Bizi Zaragoza contenidos en
 *       el fichero de nombre «rutaFichero» y «usosCirculares» es el número de
 *       usos contenidos en dicho fichero que tienen como origen y destino la
 *       misma estación. En caso contrario, la función ha devuelto «false».
 */
bool contarUsos(const char rutaFichero[], int& traslados, int& usosCirculares){
	ifstream f;
	// Apertura del flujo de entrada del fichero de usos bizi
	f.open(rutaFichero);
	if (f.is_open()){
		// El fichero se abre correctamente
		UsoBizi uso;
		f.ignore(MAX_LONG_LINEA, '\n');
		// Lectura de un uso de bizi
		leerUso(f, uso);
		while (!f.eof()){
			// queda datos en el fichero pendientes de leer
			// Los codigos de identificacion de las estaciones son iguales
			if (uso.codigoEstacionRetiro == uso.codigoEstacionDevolucion){
				// uso circular
				usosCirculares++;
			}
			else {
				// uso normal
				traslados++;
			}
			// lectura de un nuevo uso
			leerUso(f, uso);
		}
		// cierre del flujo de lectura asociado al fichero
		f.close();
		return true;
	}
	else {
		// Error en la apertura del fichero
		cerr << " No se ha podido leer del fichero " << rutaFichero << endl;
		return false;
	}
}