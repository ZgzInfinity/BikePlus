/*********************************************************************************
 * Autores: ZgzInfinity
 * Fecha: 8-2-2019
 * Resumen: Fichero de interfaz «bizi-estacion.h» de un módulo para trabajar con
 *          registros que representan estaciones del sistema Bizi Zaragoza.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
 ********************************************************************************/

#ifndef BIZI_ESTACION_H_INCLUDED
#define BIZI_ESTACION_H_INCLUDED

#include <fstream>
using namespace std;

const int NUM_ESTACIONES = 130;
const int MAX_NOMBRE_ESTACION = 50;


struct Estacion {
	 // Define los campos para representar los siguientes datos de una estación
    // Bizi: el identificador de la estación, su nombre y el número de usos de la
    // misma
    int idEstacion;
	char nombreEstacion[MAX_NOMBRE_ESTACION];
	int numUsos;
};



/*
 * Pre: <<codigoEstacion>> es el identificador de ua estación 
 *      de bizis en Zaragoza y <<nombre>> es el nombre de dicha
 *      estación
 *
 * Post: Se ha creado un dato de tipo <<Estacion>> donde el 
 *       codigo de identificación de la estación es <<codigoEstacion,
 *       el su nombre es <<nombre>> y el total de Usos es nulo
 */
Estacion crearEstacion(int codigoEstacion, char nombre[]);



/*
 * Pre: ---
 * Post: Devuelve el código de la estación de bizis
 */
int obtenerCodigoEstacion(Estacion e);



/*
 * Pre: ---
 * Post: Devuelve el número de usos de la estación
 */
int obtenerUsosEstacion(Estacion e);



/*
 * Pre: ---
 * Post: Copia el nombre de la estación de bizis 
 *       en la cadena <<nombre>>
 */
void obtenerNombreEstacion(Estacion e, char nombre[]);



/*
 * Pre: ---
 * Post: Se incrementa el número de usos de bizi
 *       de la estación <<e>>
 */
void incrementarUsoEstacion(Estacion& e);



/*
 * Pre: a1 = X, a2 = Y
 * Post: a1 = Y, a2 = X
 */ 
void permutar(Estacion& a1, Estacion& a2);



/*
 * Pre: <<estaciones>> es un vector de estaciones de bizi de Zaragoza
 * Post: Ha permutado las estaciones de manera que ahora se hayan ordenadas
 *       por orden creciente de número de usos
 */
void ordenarPorId(Estacion estaciones[]);



/*
 * Pre: <<estaciones>> es un vector de NUM_ESTACIONES componentes que 
 *      guarda estaciones NUM_ESTACIONES y <<codigo>> es el código de identficación
 *      de una estación
 * Post: Devuelve el índice la componente del vector donde se encuentra la estación
 *       con identificador <<codigo>> en caso de que exista. En caso contario retorna
 *       un número negativo
 */
int consultarEstacion(Estacion estaciones[], const int codigo);


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
bool leerEstaciones(const char rutaFicheroEstaciones[], Estacion estaciones[]);


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
bool contarUsosEstaciones(const char rutaFichero[], Estacion estaciones[]);


/*
 * Pre:  El vector «estaciones» tiene «NUM_ESTACIONES» componentes.
 * Post: El contenido del vector «estaciones» es una permutación del contenido
 *       inicial del mismo que está ahora ordenado de mayor a menor número de usos
 *       de las estaciones.
 */
void ordenarPorUso(Estacion estaciones[]);



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
void mostrarMenuInforme (ofstream& f);



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
bool escribirInforme(const char nombreFichero[], const Estacion estaciones[]);

#endif // BIZI_ESTACION_H_INCLUDED