/*********************************************************************************
 * Autores: ZgzInfinity
 * Fecha: 10-2-2019
 * Resumen: Fichero de proyecto para trabajar con módulos de usuarios, usos y 
 *          estaciones del sistema Bizi Zaragoza.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
 ********************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include "../Uso/Bizi-uso.h"
#include "../Usuario/Bizi-usuario.h"
#include "../Estacion/Bizi-estacion.h"   

using namespace std;

const int MAX_LONG_NOMBRE_FICHERO = 50;
const int MAX_LONG_LINEA = 128;
const int MAX_USUARIOS = 30000;
const int ERROR_EN_BUSQUEDA = -1;

/*
 * Pre: Muestra por pantalla un menú informativo al usuario con el 
 *      siguiente formato:
 * 
 *      Eleccion de ficheros de usos y usuarios. Opciones disponibles: 
 *      16: octubre 2016 a marzo 2017 
 *      17: marzo 2017 a agosto 2017 
 *      Introduzca una opcion
 * 
 * Post: El usuario ha introducido por teclado una de las dos opciones disponibles,
 *       generandose los ficheros correspondientes a esa elección
 */ 
void pedirDatosUsuario(char orden[]){
	cout << endl;
	cout << " Eleccion de ficheros de usos y usuarios. Opciones disponibles: " << endl;
	cout << " 16: octubre 2016 a marzo 2017 " << endl;
	cout << " 17: marzo 2017 a agosto 2017 " << endl;
	
	// pide al usuario la opción con la que determinar con qué ficheros trabajar
	cout << " Introduzca una opcion " << flush;
	cin.getline(orden, MAX_LONG_LINEA, '\n');
}

/*
 * Pre : ---
 * Post: Muestra por pantalla un menú informativo con las
 *       posibles opciones con las que puede trabajar el usuario.
 *       El menú tiene la siguiente apariencia:
 * 
 *       ORDENES DISPONIBLES 
 *       ===================
 *       AYUDA:  muestra esta pantalla de ayuda
 *       FICHERO: permite elegir los ficheros de usos y usuarios. 
 *       INFORME <nombre-fichero>: escribe en el fichero especificado un informe con el numero 
 *       de usos de las estaciones segun los ficheros selecionados actualmente. 
 *       USUARIO <id-usuario>: informa acerca del numero de usos realizados por el usuario 
 *       especificado.
 *       ESTADISTICAS: informa sobre el numero de usos de hombres y mujeres segun el contenido 
 *       de los ficheros seleccionados actualmente.
 *       FIN: termina la ejecucion del programa. 
 */
void mostrarOpciones(){
	cout << endl;
	cout << " ORDENES DISPONIBLES " << endl;
	cout << " =================== " << endl;
	cout << " AYUDA:  muestra esta pantalla de ayuda " << endl;
	cout << " FICHERO: permite elegir los ficheros de usos y usuarios. " << endl;
	cout << " INFORME <nombre-fichero>: escribe en el fichero especificado un informe con el numero " << endl;
	cout << " de usos de las estaciones segun los ficheros selecionados actualmente. " << endl;
	cout << " USUARIO <id-usuario>: informa acerca del numero de usos realizados por el usuario " << endl;
	cout << " especificado. " << endl;
	cout << " ESTADISTICAS: informa sobre el numero de usos de hombres y mujeres segun el contenido " << endl;
	cout << " de los ficheros seleccionados actualmente. " << endl;
	cout << " FIN: termina la ejecucion del programa. " << endl << endl;
}


/*
 * Pre: ---
 * Post: Ha almacenado en <<orden>> la orden introducida por el usuario
 *       y en <<valor>> el parámetro necesario para llevarla a cabo
 */
void pedirOrden(char orden[]){
	cout << " Orden: " << flush;
	cin.getline(orden, MAX_LONG_LINEA, '\n');
}


/*
 * Pre: <<orden>> es una secuencia de caracteres que constituye una orden valida del programa
 * Post: Ha insertado en cada componente de la cadena <<orden>> el caracter '\0' para vaciarla
 */
void limpiarOrden(char orden[]){
	int tamanyo = strlen(orden);
	for (int i = 0; i < tamanyo; i++){
		orden[i] = '\0';
	}
}


/*
 * Pre: La cadena de caracteres <<orden>> guarda la petición
 *      introducida por el usuario a través de teclado. La cadena <<orden>>
 *      puede contener como máximo un único espacio en blanco
 * Post: Devuelve el índice si y solo si en la cadena <<orden>> se encuentra
 *       el caracter espacio en blanco, en caso contario devuelve valor negativo
 */
int existeEspacio(char orden[]){
	int i = 0;
	bool hallado = false;
	while(!hallado && i < int(strlen(orden)) - 1){
		// quedan componentes por recorrer o no se ha encontrado
		if (orden[i] == ' '){
			// es el espacio
			// parada de la búsqeda
			hallado = true;
		}
		else {
			// no es el espacio en blanco
			i++;
		}
	}
	if (hallado){
		return i;
	}
	else {
		return ERROR_EN_BUSQUEDA;
	}
}


/*
 * Pre: La cadena de caracteres <<origen>> almacena la orden introducida por el usuario
 *      a través de teclado y <<referencia>> es el índice donde se encuentra el caracter 
 *      espacio en blanco
 * Post: Ha copaido en <<destino>> todos los caracteres de la cadena <<origen>> posteriores
 *       al espacio en blanco
 */
void copiarFragmentoCadena(char origen[], char destino[], int referencia){
	int i;
	int j = 0;
	// copia de caracteres
	for (i = referencia; i < int(strlen(origen)); i++){
		destino[j] = origen[i];
		j++;
	}
	//inserción del final de la cadena
	destino[j] = '\0';
}




/*
 * Pre: La cadena de caracteres <<cadena>> almacena la orden introducida 
 *      por el usuario a través del teclado formado por caracteres alfabéticos 
 *      escritos en mayúsculas, en minúsculas o en ambos.
 * Post: Ha convertido aquellos caracteres de la cadena <<cadena>> escritos en minúsculas a mayúsculas
 *       Los caracteres ya escritos en mayúculas no se han modificado
 */
void aMayusculas(char cadena[]){
	// Recorrido de la cadena 
	for (int i = 0; i < int(strlen(cadena)); i++){
		if (!isupper(cadena[i])){
			// es minúscula 
			// pasar a mayúscula
			cadena[i] = toupper(cadena[i]);
		}
	}
}




/*
 * Pre: <<ficheroUsosBizi>> es un fichero de usos de bizi Zaragoza, 
 *      <<ficheroEstacionesBizi>> es un fichero de estaciones de bizis de Zaragoza y 
 * Post: Ha creado a partir del fichero de usos de bizi y del fichero de estaciones de
 *       Zaragoza un fichero denominado <<ficheroInforme>> donde se ha escrito la
 *       siguiente información sobre cada estación almacenada en el fichero
 *       <<ficheroEstacionesBizi>>: puesto, número de usos, identificador de la estación y
 *       nombre, con un formato similar al siguiente:
 *
 *           Puesto    Usos  Id Nombre
 *           ------ ------- --- ---------------------------------------
 *                1   47064  16 Plaza España
 *                2   42306  67 Avda. G. Gómez de Avellaneda - C/ Clara Campoamor
 *                3   40251  47 Plaza San Francisco - Universidad
 *           ...
 */
void procesarUnInforme(const char ficheroUsosBizi[], const char ficheroEstacionesBizi[], char ficheroInforme[]){
	// vector de estaciones
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
}


/*
 * Pre: <<ficheroUsos>> es un fichero de texto que guarda información sobre diferentes
 *      usos de Bizis en Zaragoza. <<hombres>> es un vector de usuarios donde se hallan
 *      guardados todos los hombres que han usado el sistema de bizis de Zaragoza, y 
 *      <<mujeres>> es un vector donde se almacenan todas las mujeres que han empleado el 
 *      sistema de bizis de Zaragoza, ambos vectores tienen capacidad de <<numHombres>> y
 *      <<numMujeres>> respectivamente;
 * Post: Si no ha habido problemas en la lectura ha almacenado en <<usosHombres>>  cuantos 
 *       usos del sistema de bizis de Zaragoza han hecho los hombres, en <<usosMujeres>> 
 *       cuantos usos del sistema de bizi Zaragoza han hecho las mujeres, y ha devuelto <<true>>
 *       En caso contrario, se ha limitado a devolver <<false>>
 */  
bool contarUsosPorSexo(const char ficheroUsos[], Usuario hombres[], Usuario mujeres[], 
							int numHombres, int numMujeres, int& usosHombres, int& usosMujeres){
	ifstream f;
	f.open(ficheroUsos);
	// apertura del fichero de usos
	if (f.is_open()){
		UsoBizi uso;
		f.ignore(MAX_LONG_LINEA, '\n');
		// Lectura de un uso de bizi
		leerUso(f, uso);
		while (!f.eof()){
			// quedan usos pendientes de leer en el fichero de usos
			int codigo = codigoDelUsuario(uso);
			if (encontrarUsuario(hombres, codigo, numHombres) != -1){
				// el usuario que ha realizado el uso del sistema es hombre
				// incremento de los usos de los hombres
				usosHombres++;
			}
			else if (encontrarUsuario(mujeres, codigo, numMujeres) != -1){
				// el usuario que ha realizado el uso del sistema es mujer
				// incremento de los usos de las mujeres
				usosMujeres++;
			}
			// lectura de un nuevo uso 
			leerUso(f, uso);
		}
		// cierre del flujo de lectura asociado al fichero de usos
		f.close();
		return true;
	}
	else {
		// error en la lectura del fichero de usos
		cerr << " No se ha podido leer el fichero " << ficheroUsos << endl;
		return false;
	}
}



/*
 * Pre: <<rutaFichero>> es una cadena de caracteres representa el nombre y la
 *      ruta de acceso a un fichero de usos del sistema de bizis de Zaragoza y 
 *      <<codigoUsuario>> representa el codigo de identificación de un usuario
 * Post: Si el fichero <<rutaFichero>> se ha podido leerse sin problemas ha devuelto 
 *       el total de usos realizados por el usuario con identificador <<codigoUsuario>>
 */
int contarUsosUsuario(const char rutaFichero[], int codigoUsuario){
	int resultado = 0;
	ifstream f;
	// apertura del fichero de lectura de usos
	f.open(rutaFichero);
	if (f.is_open()){
		UsoBizi uso;
		f.ignore(MAX_LONG_LINEA, '\n');
		// Lectura de un uso de bizi
		leerUso(f, uso);
		while (!f.eof()){
			// quedan usos pendientes de leer en el fichero
			if (codigoDelUsuario(uso) == codigoUsuario){
				// el uso es realizado por el usuario buscado
				resultado++;
			}
			// lectura del siguiente uso del fichero
			leerUso(f, uso);
		}
		// cierre del flujo de lectura asociado al fichero de usos
		f.close();
	}
	else {
		// fallo de lectura del fichero de usos 
		cerr << " No se ha podido leer el fichero " << rutaFichero << endl;
		resultado = -1;
	}
	// Devuelve el resultado obtenido
	return resultado;
}


/*
 * El programa pide al usuario wue introduzca por teclado una de las posibles 
 * opciones válidas para poder trabajar con ficheros pertenecientes al sistema de bizis 
 * de Zaragoza. Una vez introducida la opción muestra por pantalla un listado de cuales son las
 * posibles tareas que se pueden realizar en función de la opción establecida. 
 * El programa solicita tareas de forma reiterada hasta que el usuario teclee la orden "FIN" para
 * terminar la ejecución del programa
 */
int main(){
	// orden a introducir por el usuario
	char orden[MAX_LONG_LINEA];
	// orden a introducir por el usuario modificada
	char ordenMod[MAX_LONG_LINEA];
	// parametro para poder ejecutar la orden pedida
	char valor[MAX_LONG_LINEA];
	// fichero de usos del sistema bizi de Zaragoza
	char ficheroUsos[MAX_LONG_NOMBRE_FICHERO] = "../Datos/usos-";
	// fichero de usuarios del sistema bizi de Zaragoza 
	char ficheroUsuarios[MAX_LONG_NOMBRE_FICHERO] = "../Datos/usuarios-";
	// fichero de estaciones del sistema bizi de Zaragoza
	char ficheroEstaciones[MAX_LONG_NOMBRE_FICHERO] = "../Datos/estaciones-";
	
	// solicitud al usuario de la opción para trabajar con los ficheros
	// del sistema de bizis de Zaragoza
	pedirDatosUsuario(orden);
	
	// Obtención completa de la ruta del fichero de usos 
	strcat(ficheroUsos, orden);
	strcat(ficheroUsos, ".csv");
	
	// Obtención completa de la ruta del fichero de usuarios
	strcat(ficheroUsuarios, orden);
	strcat(ficheroUsuarios, ".csv");
	
	// Obtención completa de la ruta del fichero de estaciones
	strcat(ficheroEstaciones, orden);
	strcat(ficheroEstaciones, ".csv");
	
	// contadores de usos normales, circulares y totaeles del sistema 
	// de Bizis de Zaragoza
	int usosNormales = 0, usosCirculares = 0, numUsuarios;
	
	// conteo del número de usos normales y circulares
	contarUsos(ficheroUsos, usosNormales, usosCirculares);
	
	// vector de usuarios
	Usuario usuarios[MAX_USUARIOS];
	
	// lectura de usuarios del sistema bizi de Zaragoza
	leerUsuarios(ficheroUsuarios, usuarios, numUsuarios);
	
	// Muestra por pantalla el número total del usos del sistema bizi de Zaragoza y
	// cuántos usuarios lo han empleado
	cout << " El fichero " << ficheroUsos << " existe y tiene " << usosNormales + usosCirculares << " utilizaciones " << endl;
	cout << " El fichero " << ficheroUsuarios << " existe y tiene " << numUsuarios << " usuarios " << endl;
	
	// muestra menú con las posibles acciones ha realizar en base a los ficheros
	// introducidos por el usuario
	mostrarOpciones();
	
	// petición de orden al usuario
	pedirOrden(orden);
	
	// comprobación de la existencia de espacio
	int indiceEspacio = existeEspacio(orden);

	if (indiceEspacio != ERROR_EN_BUSQUEDA){
		// tratamiento de la orden para obtener el parámetro
		// copia hasta el espacio
		strcpy(valor,"\0");
		strncpy(ordenMod, orden, indiceEspacio);
		// copia del fragmento de cadena restante
		copiarFragmentoCadena(orden, valor, indiceEspacio + 1);
	}
	else {
		// tratar orden sin espacios en blanco
		strncpy(ordenMod, orden, strlen(orden));
	}
	
	// transformar a mayusculas
	aMayusculas(ordenMod);
	
	while (strcmp(ordenMod, "FIN") != 0){
		// mientras que la orden sea distinta de "fin"
		if (strcmp(ordenMod, "AYUDA") == 0){
			// la orden es "AYUDA"
			// se muestra de nuevo el menú de opciones
			mostrarOpciones();
		}
		else if (strcmp(ordenMod, "FICHERO") == 0 ) {
			// la orden es "FICHERO"
			// solicita de nuevo los ficheros con los que trabajar
			pedirDatosUsuario(ordenMod);
		}
		else if (strcmp(ordenMod, "INFORME") == 0){
			// la orden es "INFORME"
			// genera un fichero informe de las estaciones y usos del sistema bizi de Zaragoza
			procesarUnInforme(ficheroUsos, ficheroEstaciones, valor);
		}
		else if (strcmp(ordenMod, "USUARIO") == 0){
			// la orden es "USUARIO"
			// informa de cuántas veces el usuario introducido como parámetro ha sido el sistema bizi
			// de Zaragoza
			int codigoUsuario = atoi(valor);
			int numVeces = contarUsosUsuario(ficheroUsos, codigoUsuario);
			
			cout << " El/la usuario " << codigoUsuario << " ha realizado " << numVeces << " viajes " << endl;
		}
		else if (strcmp(ordenMod, "ESTADISTICAS") == 0){
			// la orden es "ESTADISTICAS"
			int numUsuarios = 0, numMujeres = 0, numHombres = 0;
			int usosHombres = 0, usosMujeres = 0;
			
			// lectura de usuarios del sistema bizi de Zaragoza
			leerUsuarios(ficheroUsuarios, usuarios, numUsuarios);
			
			// vector de usuarios hombres
			Usuario hombres [numUsuarios];
			// vector de usuarios mujeres
			Usuario mujeres [numUsuarios];
			
			// clasifica los usuarios que han usado el sistema bizi de Zaragoza por sexo
			clasificarUsuariosPorSexo(usuarios, hombres, mujeres, numUsuarios, numHombres, numMujeres);
			
			// cuenta cuántos usos han realizado los hombres y las mujeres del sistema bizi de Zaragoza
			contarUsosPorSexo(ficheroUsos, hombres, mujeres, numHombres, numMujeres, usosHombres, usosMujeres);
			
			cout << " Usos de bizi por hombres: " << usosHombres << endl;
			cout << " Usos de bizi por mujeres: " << usosMujeres << endl;
		}
		else {
			// la orden es desconocida 
			// informa del error
			cerr << " La orden " << ordenMod << " no esta contempleada " << endl;
			cerr << " Vuelva a intentarlo " << endl;
		}
		// la orden es distinta de "FIN"
		// muestra de nuevo el menú de opciones
		mostrarOpciones();
		
		// Limpiar la orden anterior
		limpiarOrden(orden);
		limpiarOrden(ordenMod);
		
		// pide al usuario de nuevo tarea
		pedirOrden(orden);
		
		// comprobación de si esxiste espacio en blanco en la nueva orden
		indiceEspacio = existeEspacio(orden);
		
		if (indiceEspacio != ERROR_EN_BUSQUEDA){
			// tratamiento de la orden para obtener el parámetro
			// copia hasta el espacio
			strcpy(valor,"\0");
			strncpy(ordenMod, orden, indiceEspacio);
			copiarFragmentoCadena(orden, valor, indiceEspacio + 1);
		}
		else {
			// tratar orden sin espacios en blanco
			strcpy(ordenMod, orden);
		}
		
		// procesamiento de la nueva tarea
		aMayusculas(ordenMod);
	}
	// la orden introducida es "FIN"
	// Fin de ejecución del programa
	cout << endl;
	cout << " Fin de ejecucion del programa " << endl;
	return 0;
}
