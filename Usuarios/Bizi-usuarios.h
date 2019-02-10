/*********************************************************************************
 * Autores: ZgzInfinity
 * Fecha: 8-2-2019
 * Resumen: Fichero de interfaz «bizi-usuarios.h» de un módulo para trabajar con
 *          registros que representan utilizaciones del sistema Bizi Zaragoza.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
 ********************************************************************************/


/*********************************************************************************
 * Autores: Rubén Rodriguez Esteban --> ZgzInfinity
 * Fecha: 9-2-2019
 * Resumen: Fichero de interfaz «bizi-usuarios.h» de un módulo para trabajar con
 *          registros que representan utilizaciones del sistema Bizi Zaragoza.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
 ********************************************************************************/

#ifndef BIZI_USUARIOS_H_INCLUDED
#define BIZI_USUARIOS_H_INCLUDED

#include <fstream>

using namespace std;

const int MAX_LONG_EDAD = 10;

struct Usuario {
    // Define los campos necesarios para representar los siguientes datos de un
    // usuario del sistema Bizi: el identificador del usuario que utiliza la
    // bicicleta, el sexo del usuario y el rango de edad 
	int codigoUsuario;
	char sexo;
	char rango_edad[MAX_LONG_EDAD];
};



/*
 * Pre: <<codigo>> es el código de un usuario que ha usado el sistema bizi de Zaragoza,
 *      <<sexo>> es el sexo del usuario y <<rango_edad>> es su rango de edad
 * Post: Ha creado un usuario de modo que su identificador es <<codigo>>, su sexo es <<sexo>>
 *       y su rango de edad es <<rango_edad>>
 */
Usuario crearUsuario(int codigo, char sexo, char rango_edad[]);




/*
 * Pre: ---
 * Post: Devuelve el identificador del usuarioha
 *       efectuado el uso de la bizi
 */
int codigoUsuario(Usuario u);




/*
 * Pre: ---
 * Post: Devuelve el sexo del usuario que ha
 *       efectuado el uso de la bizi
 */
char sexo(Usuario u);




/*
 * Pre: ---
 * Post: Ha copiado en <<edad>> el rango de edad del 
 *       usuario que ha usado el sistema bizi
 */
void rangoDeEdad(Usuario u, char edad[]);



/*
 * Pre: La cadena de caracteres <<ficheroUsuarios>> contiene el nombre y la ruta
 *      de acceso de un fichero de usuarios del sistema bizi de Zaragoza y <<Usuarios>>
 *      es un vector con capacidad para MAX_USUARIOS usuarios
 * Post: Si el fichero se ha podido leer sin problemas ha copiado en el vector <<Usuarios>>
 *       los usuarios almacenados en el fichero <<ficheroUsuarios>>, ha guarddado en 
 *       <<numUsuarios>> el total de usuarios del fichero y ha devuelto <<true>>
 *       En caso contrario, ha devuelto <<false>>
 */
bool leerUsuarios (const char ficheroUsuarios[], Usuario Usuarios[], int& numUsuarios);



/*
 * Pre: El vector <<usuarios>> almacena <<n>> usuarios ordendos por orden
 *       creciente de identificador, <<n>> es positivo, y
 *      <<codigo>> es el identificador de un usuario que ha usado el sistema bizi
 * Post: Si entre los usuarios almacenados en el vector <<usuarios>> ha uno con un código
 *       de identificación igual a <<codigo>> devuelve el índice del vector en el que dicho 
 *       usuario se encuentra. En caso contario devuelve un valor negativo.
 */
int encontrarUsuario(Usuario usuarios[], const int codigo, const int n);



/*
 * Pre: El vector <<usuarios>> es un vector que almacena <<nUsuarios>> usuarios y 
 *      <<nUsuarios>> es positivo
 * Post: Ha almacenado en las primeras <<numHombres>> componentes del vector <<hombres>>
 *       los usuarios que son hombres y en las primeras <<numMujeres>> componentes del vector
 *       <<mujeres>> las mujeres
 */
void clasificarUsuariosPorSexo(Usuario usuarios[], Usuario hombres[], Usuario mujeres[], int& nUsuarios, int& numHombres, int& numMujeres);

#endif // BIZI_USUARIOS_H_INCLUDED
