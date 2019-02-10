/*********************************************************************************
 * Autores: ZgzInfinity
 * Fecha: 8-2-2019
 * Resumen: Fichero de prueba del un módulo usuarios para trabajar con
 *          registros que representan utilizaciones del sistema Bizi Zaragoza.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
 ********************************************************************************/

#include <iostream>
#include <iomanip>
#include "Bizi-usuarios.h"


using namespace std;

const int MAX_LONG_NOMBRE_FICHERO = 50;
const int MAX_USUARIOS = 30000;

int main(){
	char ficheroUsuarios[MAX_LONG_NOMBRE_FICHERO];
	
	cout << "Introduzca un fichero de usuarios: " << flush;
	cin >> ficheroUsuarios;
	
	int nUsuarios = 0;
	Usuario usuarios[MAX_USUARIOS];
	
	
	leerUsuarios(ficheroUsuarios, usuarios, nUsuarios);
	
	int i1 = encontrarUsuario(usuarios, 23, nUsuarios);
	int i2 = encontrarUsuario(usuarios, 91606, nUsuarios);
	int i3 = encontrarUsuario(usuarios, 42176 , nUsuarios);
	int i4 = encontrarUsuario(usuarios, 11111111, nUsuarios);
	
	cout << "El usuario con codigo 23 se halla en la posicion " << i1 << endl;
	cout << "El usuario con codigo 91606 se halla en la posicion " << i2 << endl;
	cout << "El usuario con codigo 42176 se halla en la posicion " << i3 << endl;
	cout << "El usuario con codigo 11111111 se halla en la posicion " << i4 << endl;
	
	return 0;
}