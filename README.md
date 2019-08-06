# BikePlus

LOGO 

Proyecto que gestiona datos relativos a estaciones, usos y usuarios del sistema Bizi obtenidos del portal de datos abiertos
del Ayuntamiento de Zaragoza.

## 1 - Descripción 

BikePlus es un proyecto que tiene como objetivo la gestión de datos relativos al sistema de Bizi del ayuntamiento de Zaragoza.
El programa objeto de este proyecto es un intérprete de órdenes o comandos que, reiteradamente,solicitará una orden al usuario y 
la ejecutará, hasta que el usuario decida dar por concluida la ejecucióndel programa.


## 2 - Diseño 

### 2.1 - Inicio del programa

Cuando el programa comienza su ejecución, solicita al usuario que indique por tclado el conjunto de datos con el que va a trabajar
inicialmente. Dichos ficheros de texto con los datos han sido obtenidos del portal de datos abiertos del ayuntamiento de Zaragoza.
El programa mostrará cuales son las opciones de ficheros disponibles y el usuario deberá seleccionar la que él quiera. 
A continuación, se muestra una captura de dicha interacción.

IMAGEN

El programa ofrecerá las opciones disponibles y solicitará una. Cuando el usuario introduzca su respuesta, el programa comprueba 
si existe el fichero correspondiente de usos e informa del número de usos que contiene. Seguidamente, comprueba que existe el 
de usuarios e informa de cuántos usuarios contiene. Si el usuario introduce una opción para la que no hay ficheros, notifica
de que el fichero correspondiente no existe, y vuelve a informar sobre las opciones disponibles y a solicitar una nueva hasta que
el usuario elija una opción que esté disponible. Es importante tener en cuenta que los ficheros con los que trabaja el programa
para poder ser utilizados deben alojarse en el directorio "Datos". Seguidamente se muestra una captura de la retroalimentación 
del sistema.

IMAGEN

### 2.2 - Menú de opciones disponibles

A continuación, el programa informará de cuáles son las órdenes que acepta, mostrando la información reflejada en la siguiente 
imagen.

IMAGEN

### 2.3 - Órdenes de ejecución disponibles

Después de presentar el menú anterior, el programa solicita interactivamente una de las órdenes disponibles. El usuario debe
escribir una de ellas por teclado junto con los posibles parámetros adecuados en el caso de que se requieran para la correcta
ejecución de la tarea como es el caso de las órdenes «INFORME» y «USUARIO», la ejecutará y volverá a pedir una nueva orden 
hasta que el usuario escriba la orden «FIN», en cuyo caso el programa termina. Es completamente indiferente que el usuario 
escriba la orden en mayúsculas, minúsculas o cualquier combinaciónde ambas. Se describen a continuación con más detalles 
en qué consisten las distintas órdenes.

### 2.4 - Orden <<AYUDA>>

Cuando el usuario introduce por teclado esta orden el programa muestra el menú con las opciones posibles que se pueden realizar
tal y como se ha explicado en el apartado 2.2

IMAGEN

### 2.5 - Orden <<FICHERO>>

La orden «FICHERO» permite modificar la selección de ficheros con los que se está trabajando, y que fueron introducidos al 
comienzo de la ejecución del programa. El programa se comportará como se especificó en la sección 2.1. La orden no se completa 
hasta que el usuario selecciona una opción correcta.

IMAGEN

### 2.6 - Orden <<INFORME>>

Cuando el usuario escribe esta opción, debe proporcionar como argumento el nombre del fichero en el que se va a escribir la 
información acerca de las estaciones Bizi más usadas de acuerdo con el fichero de usos que se encuentre seleccionado en ese 
momento, ordenadas de mayor a menor número de usos. Adicionalmente, el programa mostrará las primeras diez líneas del fichero 
correspondiente al informe, de forma que muestre las ocho estaciones más utilizadas de toda Zaragoza. El programa no solo 
muestra por la pantalla las estaciones más usadas sino que crea un fichero en la carpeta "Datos" con dicho contenido. La 
imagen inferior muestra todo lo explicado anteriormente.

IMAGEN 

### 2.7 - Orden <<USUARIO>>

Cuando el usuario escribe esta opción, debe proporcionar como argumento el identificador de un usuario del sistema Bizi. 
El programa informará acerca del número de utilizaciones del sistema que dicho usuario haya realizado de acuerdo con el 
fichero de usos seleccionado actualmente. Seguidamente se plasma una captura para reseñar el comportamiento del programa.

IMAGEN 

### 2.8 - Orden <<ESTADISTICAS>>

En caso de que el usuario escribe esta opción, el programa informa del número de utilizaciones del sistemaque han realizado 
hombres y mujeres de acuerdo con el fichero de usos seleccionado actualmente. La captura siguiente refleja como retorna el
sistema los resultados al usuario.

IMAGEN

### 2.9. - Orden <<FIN>>

Si el usuario selecciona esta opción, el programa termina (y, por lo tanto, no vuelve a solicitarmás órdenes).


## 3. - Control de órdenes no válidas

Cuando el usuario seleccione una órden no disponible, deberá informar sobre el error y solicitar unanueva orden. La imagen 
siguiente muestra la retralimentación del programa.

IMAGEN


## 4 - Ficheros del proyecto

Como se ha mencionado en apartados anteriores, los ficheros de texto con los que trabaja BikePlus han sido extraídos del portal
de datos abiertos del ayuntamiento de Zaragoza. En los subapartados siguientes se describen con detallesestos ficheros y su 
contenido.

### 4.1 - Fichero de usuarios

Cada fichero comienza con una línea de cabecera a la que le sigue la información sobre los usuario sdel sistema Bizi en un 
determinado periodo de tiempo. Estos usuarios figuran cada uno en una línea distinta y contienen información sobre su 
identificador, su sexo (masculino —‘M’— o femenino —‘F’—) y sobre su rango de edad. En este proyecto no se ha a empleado la 
información relativa al rango de edad al que pertenece cada usuario. La siguiente captura muestra un ejemplo de la apariencia
del fichero.

IMAGEN

### 4.2 - Fichero de usos

Cada fichero comienza con una línea de cabecera a la que le sigue la información sobre los usos del sistema Bizi en un 
determinado periodo de tiempo. Estos usos figuran cada uno en una línea distinta y contienen información sobre el usuario al 
que corresponde el uso (identificado a través de un entero), el día y la hora en la que se retiró una bicicleta por parte del 
usuario, el código de la estación de laque se retiró, el día y la hora en la que se devolvió la bicicleta y el código de la 
estación en la que sedevolvió. En este proyecto no se han empleado los datos relativos a los días y horas de retirada y 
devolución de las bicicletas. La siguiente captura evidencia la estructura sintáctica del fichero.

IMAGEN

### 4.3 - Fichero de estaciones

Cada fichero comienza con una línea de cabecera a la que le sigue la información sobre las estacionesdel sistema Bizi, 
a razón de una estación por línea. De toda la información que sobre cada estación figura en el fichero, solo se ha usado 
su identificador numérico (que figura al final de la primera URL decada línea) y el nombre de la estación (el tercer dato de 
cada línea del fichero). Nótese como tanto la URL donde figura el identificador numérico como el nombre de la estación están 
rodeados por comillas. Seguidamente se muestra una imagen para reflejar la sintaxis del fichero.


IMAGEN


### 5 - Entornos de programación y desarrollo

BikePlus es un programa que ha sido desarrollado y preparado para poder ser ejecutado en sistemas operativos Linux y en sistemas
operativos de la familia de Windows. Para la programación de la versión de BikePlus para Windows se ha empleado el entorno de 
programación Codelite cuya versión es la 12.0 y el compilador MINGW para Windows de 64 bits. Para llevar a cabo la programación
de BikePlus en Linux se ha usado el editor de textos Atom.


### 6 - Compilación  y ejecución del proyecto

## 6.1 - Windows 

Para llevar a cabo la compilación y ejecución en Windows se ha proporcionado una carpeta denominada "Windows" en cuyo interior
se encuentra una carpeta llamada "BikePlus" correspondiente al proyecto desarrollado en Codelite. Para poder ejecutarlo basta 
crear un workspace, importar el proyecto y darle a la opción "Build and run project" tal y como muestra la siguiente imagen.

IMAGEN

## 6.2 - Linux

Para efectiar la compilación y ejecución del proyecto BikePlus se ha proporcioando una carpeta llamada "Linux" que contiene
una carpeta denominada "BikePlus" donde se encuentran los fichers del programa. Para poder compilar se debe hacer uso de un 
fichero Makefile. En el intérprete de comandos se deben introducir las órdenes make clean y make, generando un ejecutable en
el directorio "BikePlus". Para poder ejecutar el programa basta con teclear "./BikePlus.


### 7 - Pruebas

BikePLus ha sido probado en computadores con los sistemas operativos Windows 7, Windows 10, Ubuntu 17.10, Ubuntu 18.4 y 
Debian 9.4, aunque éste último es una máquina virtual corrida con Virtualbox, versión 5.2.14 r123301 (Qt5.6.2).


### 8 - Release 

Se ha proporcionado un archio .exe para poder ejecutar el programa BikePlus en Windows junto con otro archivo ejecutable para 
poder ejecutar en Linux. Adicionalmente se facilita la capeta "Datos" con unos cuántos ficheros de prueba para poder porbar su
funcionamiento.


### 9 - Documentación

Los ficheros del portal de datos abiertos del ayuntamiento de Zaragoza han sido extraídos de la URL mostrada a continuación.









