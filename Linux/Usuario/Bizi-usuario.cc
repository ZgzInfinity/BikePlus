/*********************************************************************************
 * Autores: ZgzInfinity
 * Fecha: 9-2-2019
 * Resumen: Fichero de interfaz «bizi-usuarios.h» de un módulo para trabajar con
 *          registros que representan utilizaciones del sistema Bizi Zaragoza.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
 ********************************************************************************/

const int MAX_LONG_LINEA = 128;
const int ERROR_EN_BUSQUEDA = -1;

#include <fstream>
#include <iostream>
#include <cstring>
#include "Bizi-usuario.h"

using namespace std;



/*
 * Pre: <<codigo>> es el código de un usuario que ha usado el sistema bizi de Zaragoza,
 *      <<sexo>> es el sexo del usuario y <<rango_edad>> es su rango de edad
 * Post: Ha creado un usuario de modo que su identificador es <<codigo>>, su sexo es <<sexo>>
 *       y su rango de edad es <<rango_edad>>
 */
Usuario crearUsuario(int codigo, char sexo, char rango_edad[]){
	//Asignación de los campos
	Usuario u;
	u.codigoUsuario = codigo;
	u.sexo = sexo;
	strcpy(u.rango_edad, rango_edad);
	// Retorno de resultado
	return u;
}



/*
 * Pre: ---
 * Post: Devuelve el identificador del usuarioha
 *       efectuado el uso de la bizi
 */
int codigoUsuario(Usuario u){
	return u.codigoUsuario;
}




/*
 * Pre: ---
 * Post: Devuelve el sexo del usuario que ha
 *       efectuado el uso de la bizi
 */
char sexo(Usuario u){
	return u.sexo;
}




/*
 * Pre: ---
 * Post: Ha copiado en <<edad>> el rango de edad del 
 *       usuario que ha usado el sistema bizi
 */
void rangoDeEdad(Usuario u, char edad[]){
	strcpy(edad, u.rango_edad);
}




/*
 * Pre: La cadena de caracteres <<ficheroUsuarios>> contiene el nombre y la ruta
 *      de acceso de un fichero de usuarios del sistema bizi de Zaragoza y <<Usuarios>>
 *      es un vector con capacidad para MAX_USUARIOS usuarios
 * Post: Si el fichero se ha podido leer sin problemas ha copiado en el vector <<Usuarios>>
 *       los usuarios almacenados en el fichero <<ficheroUsuarios>>, ha guarddado en 
 *       <<numUsuarios>> el total de usuarios del fichero y ha devuelto <<true>>
 *       En caso contrario, ha devuelto <<false>>
 */
bool leerUsuarios (const char ficheroUsuarios[], Usuario Usuarios[], int& numUsuarios){
	ifstream f;
	f.open(ficheroUsuarios);
	// apertura del flujo de lectura del fichero de usuarios
	if (f.is_open()){
		numUsuarios = 0;
		Usuario usuarioNuevo;
		int codigo; 
		char sexo;
		char edad[MAX_LONG_EDAD];
		f.ignore(MAX_LONG_LINEA, '\n');
		// lectura del identificador del usuario
		f >> codigo;
		while (!f.eof()){
			// quedan usuarios pendientes de leer en el fichero
			f.ignore(1, ';');
			f >> sexo;
			f.ignore(1, ';');
			f.getline(edad, MAX_LONG_LINEA, '\n');
			
			// almacena en el vector el usuario leido
			usuarioNuevo = crearUsuario(codigo, sexo, edad);
			Usuarios[numUsuarios] = usuarioNuevo;
			numUsuarios++;
			
			// lectura de un nuevo usuario del fichero
			f >> codigo;
		}
		// cierre del flujo de lectura asociado al fichero de usuarios
		f.close();
		return true;
	}
	else{
		// notifica del error al intentar abrir el fichero de usuarios
		cerr << " No se ha podido leer el fichero " << ficheroUsuarios << endl;
		return false;
	}
}



/*
 * Pre: El vector <<usuarios>> almacena <<n>> usuarios ordendos por orden
 *       creciente de identificador, <<n>> es positivo, y
 *      <<codigo>> es el identificador de un usuario que ha usado el sistema bizi
 * Post: Si entre los usuarios almacenados en el vector <<usuarios>> ha uno con un código
 *       de identificación igual a <<codigo>> devuelve el índice del vector en el que dicho 
 *       usuario se encuentra. En caso contario devuelve un valor negativo.
 */
int encontrarUsuario(Usuario usuarios[], const int codigo, const int n){
	// incialización de límites de búsqueda
	int inf = 0;
	int sup = n - 1;
	int med;
	while (inf < sup){
		// mientras queden usuarios por comprobar
		// obtención del usuario central
		med = (inf + sup) / 2;
		if (codigoUsuario(usuarios[med]) < codigo){
			// El usuario tiene un códgio menor que <<codigo>>
			// despreciar todos los usuarios del margen izquierdo
			inf = med + 1;
		}
		else {
			// El usuario tiene un códgio igual o superior que <<codigo>>
			// despreciar todos los usuarios del margen derecho
			sup = med;
		}
	}
	// búsqueda concluída
	// comprobación de códigos de usuario
	if (codigoUsuario(usuarios[inf]) == codigo){
		// es el usuario buscado
		return inf;
	}
	else {
		// no existe el usuario en el vector
		return ERROR_EN_BUSQUEDA;
	}
}



/*
 * Pre: El vector <<usuarios>> es un vector que almacena <<nUsuarios>> usuarios y 
 *      <<nUsuarios>> es positivo
 * Post: Ha almacenado en las primeras <<numHombres>> componentes del vector <<hombres>>
 *       los usuarios que son hombres y en las primeras <<numMujeres>> componentes del vector
 *       <<mujeres>> las mujeres
 */
void clasificarUsuariosPorSexo(Usuario usuarios[], Usuario hombres[], Usuario mujeres[], 
									int& nUsuarios, int& numHombres, int& numMujeres){
	//Recorrido del vector de usuarios
	for (int i = 0; i < nUsuarios; i++){
		if (sexo(usuarios[i]) == 'M'){
			// el usuario i-ésimo es hombre
			hombres[numHombres] = usuarios[i];
			numHombres++;
		}
		else {
			// el usuario i-ésimo es mujer
			mujeres[numMujeres] = usuarios[i];
			numMujeres++;
		}
	}
}


