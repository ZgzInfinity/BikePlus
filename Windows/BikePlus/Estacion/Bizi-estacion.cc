/*********************************************************************************
 * Autores: ZgzInfinity
 * Fecha: 8-2-2019
 * Resumen: Fichero de implementación «bizi-estacion.cc» de un módulo para trabajar con
 *          registros que representan estaciones del sistema Bizi Zaragoza.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
 ********************************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Bizi-estacion.h"


using namespace std;


const int MAX_LONG_LINEA = 128;
const int MAX_LONG_RESTO = 500;
const int LONG_URL_ID = 85;
const int MAX_LONG_TIEMPO = 30;
const int ERROR_EN_BUSQUEDA = -1;

/*
 * Pre: <<codigoEstacion>> es el identificador de ua estación 
 *      de bizis en Zaragoza y <<nombre>> es el nombre de dicha
 *      estación
 *
 * Post: Se ha creado un dato de tipo <<Estacion>> donde el 
 *       codigo de identificación de la estación es <<codigoEstacion,
 *       el su nombre es <<nombre>> y el total de Usos es nulo
 */
Estacion crearEstacion(int codigoEstacion, char nombre[]){
	// Asignación de los campos
	Estacion e;
	e.idEstacion = codigoEstacion;
	strcpy(e.nombreEstacion, nombre);
	e.numUsos = 0;
	
	// Retorno del resultado
	return e;
}



/*
 * Pre: ---
 * Post: Devuelve el código de la estación de bizis
 */
int obtenerCodigoEstacion(Estacion e){
	return e.idEstacion;
}



/*
 * Pre: ---
 * Post: Devuelve el número de usos de la estación
 */
int obtenerUsosEstacion(Estacion e){
	return e.numUsos;
}



/*
 * Pre: ---
 * Post: Copia el nombre de la estación de bizis 
 *       en la cadena <<nombre>>
 */
void obtenerNombreEstacion(Estacion e, char nombre[]){
	strcpy(nombre, e.nombreEstacion);
}



/*
 * Pre: ---
 * Post: Se incrementa el número de usos de bizi
 *       de la estación <<e>>
 */
void incrementarUsoEstacion(Estacion& e){
	e.numUsos++;
}



/*
 * Pre: a1 = X, a2 = Y
 * Post: a1 = Y, a2 = X
 */ 
void permutar(Estacion& a1, Estacion& a2){
	Estacion aux = a1;
	a1 = a2;
	a2 = aux;
}



/*
 * Pre: <<estaciones>> es un vector de estaciones de bizi de Zaragoza
 * Post: Ha permutado las estaciones de manera que ahora se hayan ordenadas
 *       por orden creciente de número de usos
 */
void ordenarPorId(Estacion estaciones[]){
	int codigoMenor, codigoActual, iMenor;
	for (int i = 0; i < NUM_ESTACIONES - 1; i++){
		// código de la estación con menor número de usos
		iMenor = i;
		// obtención del código
		codigoMenor = obtenerCodigoEstacion(estaciones[i]);
		for (int j = i + 1; j < NUM_ESTACIONES; j++){
			// búsqueda de una estación con menor número de usos en las restantes 
			codigoActual = obtenerCodigoEstacion(estaciones[j]);
			if (codigoActual < codigoMenor){
				// actualización de la nueva encontrada
				codigoMenor = codigoActual;
				iMenor = j;
			}
		}
		// Intercambio de las estaciones
		permutar(estaciones[i], estaciones[iMenor]);
	}
}



/*
 * Pre: <<estaciones>> es un vector de NUM_ESTACIONES componentes que 
 *      guarda estaciones NUM_ESTACIONES y <<codigo>> es el código de identficación
 *      de una estación
 * Post: Devuelve el índice la componente del vector donde se encuentra la estación
 *       con identificador <<codigo>> en caso de que exista. En caso contario retorna
 *       un número negativo
 */
int consultarEstacion(Estacion estaciones[], const int codigo){
	bool encontrado = false;
	int indice = 0;
	// no se ha encontrado todavía
	while (!encontrado && indice < NUM_ESTACIONES){
		// comprobación del identificador de la estación
		if (obtenerCodigoEstacion(estaciones[indice]) == codigo){
			// parar búsqueda
			// coincide
			encontrado = true;
		}
		else {
			// no coincide
			// seguir búsqueda
			indice++;
		}
	}
	
	if (encontrado){
		// Retorno del índice donde se encuentra
		return indice;
	}
	else {
		// Retorno de error de búsqueda
		return ERROR_EN_BUSQUEDA;
	}
}

/*
 * Pre:  La cadena de caracteres «rutaFicheroEstaciones» contiene la ruta de
 *       acceso y nombre de un fichero de estaciones Bizi que sigue la sintaxis
 *       establecida en el enunciado y que contiene información de
 *       «NUM_ESTACIONES» estaciones. El vector «estaciones» tiene
 *       «NUM_ESTACIONES» componentes.
 * Post: Si no ha habido problemas de lectura del fichero «rutaFicheroEstaciones»,
 *       la función ha devuelto «true» y se han leído los datos de las estaciones
 *       Bizi contenidos en el fichero
 *       indicado por «rutaFicheroEstaciones» y se han almacenado en el vector
 *       «estaciones» de forma tal que en cada componente «i» se almacena el
 *       identificador y el nombre de la estación de identificador «i» + 1 (es
 *       decir, en estaciones[0] se encuentra almacenada la información de la
 *       estación con identificador 1, en estaciones[1] se encuentra almacenada la
 *       estación con identificador 2 y así sucesivamente). La información sobre
 *       el número de usos de cada estación es 0 en todas ellas.
 *       Si no se ha podido leer el fichero «rutaFicheroEstaciones», se ha
 *       limitado a devolver «false».
 */
bool leerEstaciones(const char rutaFicheroEstaciones[], Estacion estaciones[]){
	ifstream f;
	// Aperura del fichero de estaciones
	f.open(rutaFicheroEstaciones);
	if (f.is_open()){
		Estacion nuevaEstacion;
		int i = 0;
		int codigoEstacion;
		char nombreEstacion [MAX_NOMBRE_ESTACION];
		f.ignore (MAX_LONG_LINEA,'\n');
		f.ignore(LONG_URL_ID);
		// lectura del código de estación
		f >> codigoEstacion;
		while (!f.eof()){
			// queda contenido de fichero pendiente de leer
			f.ignore(MAX_LONG_LINEA, ';');
			f.ignore(MAX_LONG_LINEA, ';');
			f.ignore(1, '"');
			// lecutra del nonbre de estación
			f.getline(nombreEstacion, MAX_LONG_LINEA, '"');
			f.ignore(MAX_LONG_RESTO, '\n');
			// inserción de la nueva estación leida
			nuevaEstacion = crearEstacion(codigoEstacion, nombreEstacion);
			estaciones[i] = nuevaEstacion;
			i++;
			f.ignore(LONG_URL_ID);
			
			// lectura de la sigueinte
			f >> codigoEstacion;
		}
		// cierre del flujo de lectura asociado al fichero
		f.close();
		// ordenaciób de estaciones por orden de identificador
		ordenarPorId(estaciones);
		return true;
	}
	else {
		// error de apertura del fcihero de estaciones
		cerr << " No se ha podido leer del fichero " << rutaFicheroEstaciones << endl;
		return false;
	}
}


/*
 * Pre:  La cadena de caracteres «rutaFichero» representa la ruta de acceso y el
 *       nombre de un fichero de texto con el formato de usos del sistema Bizi
 *       establecido en el enunciado. El vector «estaciones» tiene
 *       «NUM_ESTACIONES» componentes donde se ha almacenado información sobre
 *       estaciones Bizi de forma tal que en cada componente «i» se almacena la
 *       información de la estación de identificador «i» + 1 (es decir, en
 *       estaciones[0] se encuentra almacenada la información de la estación con
 *       identificador 1, en estaciones[1] se encuentra almacenada la estación con
 *       identificador 2 y así sucesivamente). La información sobre
 *       el número de usos de cada estación es 0 en todas ellas.
 * Post: Si no ha habido problemas de lectura del fichero «rutaFichero», la
 *       función ha devuelto «true» y ha actualizado el número de usos de cada
 *       estación del vector «estaciones» de acuerdo con el contenido del fichero
 *       «rutaFichero», contabilizando como un uso tanto la retirada como la
 *       devolución de bicicletas. En caso contrario, se ha limitado a devolver
 *       «false».
 */
 
bool contarUsosEstaciones(const char rutaFichero[], Estacion estaciones[]){
	ifstream f;
	// apertura del fichero de estaciones
	f.open(rutaFichero);
	if (f.is_open()){
		// el fichero se abre correctamente
		UsoBizi uso;
		int codigoEstacionRetiro, codigoEstacionDevolucion, posicion;
		int i = 1;
		f.ignore(MAX_LONG_LINEA, '\n');
		//lectura de un uso de bizi
		leerUso(f, uso);
		while (!f.eof()){
			
			// obtención del código de estación de retiro de la bicicleta
			codigoEstacionRetiro = codigoDeEstacionRetiro(uso);
			// obtención del código de estación de devolución de la bicicleta
			codigoEstacionDevolucion = codigoDeEstacionDevolucion(uso);
		
			// comparación de códigos
			if (codigoEstacionRetiro == codigoEstacionDevolucion){
				// uso de bizi circular
				// obtención del índice de la estación
				posicion = consultarEstacion(estaciones, codigoEstacionRetiro);
				
				if (posicion != ERROR_EN_BUSQUEDA){
					// no hay error de búsqueda
					// actualización del uso de la estación (retiro y devolución)
					incrementarUsoEstacion(estaciones[posicion]);
					incrementarUsoEstacion(estaciones[posicion]);
				}
			}
			else {
				// el uso es normal
				// obtención de la posición de la estación de retiro
				posicion = consultarEstacion(estaciones, codigoEstacionRetiro);
				
				if (posicion != ERROR_EN_BUSQUEDA){
					// no hay error en búsqueda
					// incremento de los usos de la estación de retiro
					incrementarUsoEstacion(estaciones[posicion]);
				}
				
				// obtención de la posición de la estación de devolución
				posicion = consultarEstacion(estaciones, codigoEstacionDevolucion);
				
				if (posicion != ERROR_EN_BUSQUEDA){
					// no hay error en búsqueda
					// incremento de los usos de la estación de devolución
					incrementarUsoEstacion(estaciones[posicion]);
				}
			}
			// lectura de nuevo uso de bizi
			i++;
			leerUso(f, uso);
		}
		// cierre del flujo de lectura asociado al fichero de usos
		f.close();
		return true;
	}
	else {
		// error en la apertura del fichero de usos
		cerr << " No se ha podido leer del fichero " << rutaFichero << endl;
		return false;
	}
}


/*
 * Pre:  El vector «estaciones» tiene «NUM_ESTACIONES» componentes.
 * Post: El contenido del vector «estaciones» es una permutación del contenido
 *       inicial del mismo que está ahora ordenado de mayor a menor número de usos
 *       de las estaciones.
 */
void ordenarPorUso(Estacion estaciones[]){
	int usosMayor, usosActual, iMayor;
	for (int i = 0; i < NUM_ESTACIONES - 1; i++){
		// índice de la estación con mayor número de usos
		iMayor = i;
		usosMayor = obtenerUsosEstacion(estaciones[i]);
		// búsqueda de una estación con mayor número de usos que la atual
		for (int j = i + 1; j < NUM_ESTACIONES; j++){
			usosActual = obtenerUsosEstacion(estaciones[j]);
			if (usosActual > usosMayor){
				// nueva estación encontradada
				usosMayor = usosActual;
				iMayor = j;
			}
		}
		// intercambio de estaciones
		permutar(estaciones[i], estaciones[iMayor]);
	}
}

/*
 * Pre: <<f>> es un flujo de lectura asociado a un fichero
 *      para generar informes
 * Post: Ha escrito en el informe una cabecera con el siguiente formato
 * 
 *           Puesto    Usos  Id Nombre
 *           ------ ------- --- ---------------------------------------
 *                1   47064  16 Plaza España
 *                2   42306  67 Avda. G. Gómez de Avellaneda - C/ Clara Campoamor
 *                3   40251  47 Plaza San Francisco - Universidad
 *           ...
 *
 */
void mostrarMenuInforme (ofstream& f){
	// Mostrar cabecera del informe en el fichero
	cout << endl << endl;
	f << setw(17) << "Puesto"  
		  << setw(8) <<  "Usos" 
		  << setw(4) << "id" 
		  << setw(7) << "Nombre" 
		  << endl;
		f << setw(11) << ' ' 
		  << setw(6) << setfill('-') << "" << " "  
		  << setw(7) << setfill('-') << "" << " "
		  << setw(3) << setfill('-') << "" << " "
		  << setw(40) << setfill('-') << " " << endl;

	// Mostrar cabecera del informe en la pantalla
	cout << setw(17) << "Puesto"  
		  << setw(8) <<  "Usos" 
		  << setw(4) << "id" 
		  << setw(7) << "Nombre" 
		  << endl;
		cout << setw(11) << ' ' 
		  << setw(6) << setfill('-') << "" << " "  
		  << setw(7) << setfill('-') << "" << " "
		  << setw(3) << setfill('-') << "" << " "
		  << setw(40) << setfill('-') << " " << endl;
}




/*
 * Pre:  ---
 * Post: Si la función ha podido crear un fichero de texto cuyo nombre es el
 *       contenido de la cadena de caracteres «nombreFichero», la función ha
 *       devuelto «true» y  ha escrito en el fichero creado la
 *       siguiente información sobre cada estación almacenada en el vector
 *       «estaciones»: puesto, número de usos, identificador de la estación y
 *       nombre, con un formato similar al siguiente:
 *
 *           Puesto    Usos  Id Nombre
 *           ------ ------- --- ---------------------------------------
 *                1   47064  16 Plaza España
 *                2   42306  67 Avda. G. Gómez de Avellaneda - C/ Clara Campoamor
 *                3   40251  47 Plaza San Francisco - Universidad
 *           ...
 */
bool escribirInforme(const char nombreFichero[], const Estacion estaciones[]){
	ofstream f;
	// creación del fichero de informe a generar
	f.open(nombreFichero);
	
	if(f.is_open()){
		// el fichero se abre correctamente
		// escritura de la cabecera del informs
		mostrarMenuInforme(f);

		int codigoEstacion, numUsos;
		char nombreEstacion[MAX_NOMBRE_ESTACION];
		// recorrido de las estaciones 
		for (int i = 0; i < NUM_ESTACIONES; i++){
			// obtención de los datos de la i-ésima estación
			codigoEstacion = obtenerCodigoEstacion(estaciones[i]);
			numUsos = obtenerUsosEstacion(estaciones[i]);
			obtenerNombreEstacion(estaciones[i], nombreEstacion);
			// escritura de los datos obtenidos de cada estación en el informe
			f << setw(17) << setfill(' ') << i + 1 
			  << setw(8) << setfill(' ') << numUsos 
			  << setw(4) << setfill(' ') << codigoEstacion 
			  << " " << nombreEstacion << endl; 
			// muestreo de los datos por pantalla de cada estacion en el informe
			cout << setw(17) << setfill(' ') << i + 1 
			  << setw(8) << setfill(' ') << numUsos 
			  << setw(4) << setfill(' ') << codigoEstacion 
			  << " " << nombreEstacion << endl; 
		}
		// cierre del flujo de escritura asociado al fichero de informe
		f.close();
		return true;
	}
	else {
		// error en la apertura del fichero de informe
		cerr << " No se ha podido leer del fichero " << nombreFichero << endl;
		return false;
	}
}



