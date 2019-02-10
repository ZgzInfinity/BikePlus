/*********************************************************************************
 * Autores: ZgzInfinity
 * Fecha: 8-2-2019
 * Resumen: Fichero de interfaz «bizi-usos.h» de un módulo para trabajar con
 *          registros que representan utilizaciones del sistema Bizi Zaragoza.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
 ********************************************************************************/

#ifndef BIZI_USOS_H_INCLUDED
#define BIZI_USOS_H_INCLUDED

#include <fstream>
using namespace std;

struct UsoBizi {
    // Define los campos necesarios para representar los siguientes datos de un
    // uso del sistema Bizi: el identificador del usuario que utiliza la
    // bicicleta, el código de la estación de la que se retira la bicicleta y el
    // código de la estación en la que se devuelve.
	int codigoUsuario;
	int codigoEstacionRetiro;
	int codigoEstacionDevolucion;
};



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
void crearUsoBizi(int idUsuario, int codigoEstacionRetiro, int codigoEstacionDevolucion, UsoBizi& uso);



/*
 * Pre: ---
 * Post: Devuelve el identifcador del usuario que ha
 *       efectuado el uso de la bizi
 */
int codigoDelUsuario(UsoBizi uso);



/*
 * Pre: ---
 * Post: Devuelve el código de identificación de la 
 *       estación de la que se ha retirado una bicicleta
 */
int codigoDeEstacionRetiro(UsoBizi uso);



/*
 * Pre: ---
 * Post: Devuelve el código de identificación de la 
 *       estación en la que se ha depositado la bicicleta
 */
int codigoDeEstacionDevolucion(UsoBizi uso);



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
void leerUso(ifstream& f, UsoBizi& uso);


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
bool contarUsos(const char rutaFichero[], int& traslados, int& usosCirculares);


#endif // BIZI_USOS_H_INCLUDED
