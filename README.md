# BikePlus

Proyecto que gestiona datos relativos a estaciones, usos y usuarios del sistema Bizi obtenidos del portal de datos abiertos
del Ayuntamiento de Zaragoza.

![alt text](https://i.ibb.co/bzbBPsX/chulo.jpg) 

## 1 - Descripción 

BikePlus es un proyecto que tiene como objetivo la gestión de datos relativos al sistema de Bizi del ayuntamiento de Zaragoza.
El programa objeto de este proyecto es un intérprete de órdenes o comandos que, reiteradamente,solicita una orden al usuario y 
la ejecuta, hasta que el usuario decide dar por concluida la ejecución del programa.


## 2 - Diseño 

### 2.1 - Inicio del programa

Cuando el programa comienza su ejecución, solicita al usuario que indique por teclado el conjunto de datos con el que va a 
trabajar. Dichos ficheros de texto con los datos han sido obtenidos del portal de datos abiertos del ayuntamiento 
de Zaragoza. El programa muestra cuáles son las opciones de ficheros disponibles y el usuario debe seleccionar la que quiera. 

El programa ofrece las opciones disponibles y solicita una. Cuando el usuario introduce su respuesta, el programa comprueba 
si existe el fichero correspondiente de usos. Seguidamente, comprueba que existe el de usuarios, y si los dos ficheros existen
devuelve cuántos usos y cuántos usuarios contienen. Si el usuario introduce una opción para la que no hay ficheros, notifica 
que los ficheros correspondientes no existen, y vuelve a informar sobre las opciones disponibles y a solicitar una nueva
hasta que el usuario elija una opción que esté disponible. Es importante tener en cuenta que los ficheros con los que trabaja el 
programa para poder ser utilizados deben alojarse en el directorio "Datos". Seguidamente se muestra una captura de la 
retroalimentación del sistema cuando el usuario introduce una opción de ficheros disponible y otra cuando no, respectivamente.

![alt text](https://i.ibb.co/DGMCcBr/0.png) 


![alt text](https://i.ibb.co/DGMCcBr/0.png)


### 2.2 - Menú de opciones disponibles

A continuación, el programa informa de cuáles son las órdenes que acepta, mostrando la información reflejada en la siguiente 
imagen.

![alt text](https://i.ibb.co/QXWDhJf/0.png)


### 2.3 - Órdenes de ejecución disponibles

Después de presentar el menú anterior, el programa solicita interactivamente una de las órdenes disponibles. El usuario debe
escribir una de ellas por teclado junto con los posibles parámetros adecuados en el caso de que se requieran para la correcta
ejecución de la tarea como es el caso de las órdenes «INFORME» y «USUARIO», la ejecutará y volverá a pedir una nueva orden 
hasta que el usuario escriba la orden «FIN», en cuyo caso el programa termina. Es completamente indiferente que el usuario 
escriba la orden en mayúsculas, minúsculas o cualquier combinación de ambas. Se describen a continuación con más detalles 
en qué consisten las distintas órdenes.

### 2.4 - Orden AYUDA

Cuando el usuario introduce por teclado esta orden el programa muestra el menú con las opciones posibles que se pueden realizar
tal y como se ha explicado en el apartado 2.2

![alt text](https://i.ibb.co/wSTYRck/1.png)

### 2.5 - Orden FICHERO

La orden «FICHERO» permite modificar la selección de ficheros con los que se está trabajando, y que fueron introducidos al 
comienzo de la ejecución del programa. El programa se comportará como se especificó en la sección 2.1. La orden no se completa 
hasta que el usuario selecciona una opción correcta.

![alt text](https://i.ibb.co/nRy7t5L/0.png)

### 2.6 - Orden INFORME

Cuando el usuario escribe esta opción, debe proporcionar como argumento el nombre del fichero en el que se va a escribir la 
información acerca de las estaciones Bizi más usadas de acuerdo con el fichero de usos que se encuentre seleccionado en ese 
momento, ordenadas de mayor a menor número de usos. Adicionalmente, el programa mostrará un listado con todas las estaciones
guardadas en el fichero de estaciones por orden decreciente de usos, de forma que muestre las estaciones desde la más utilizada
de Zaragoza a la de menos. El programa no solo muestra por la pantalla las estaciones sino que crea un fichero en la
carpeta "Datos" con dicho contenido. La imagen inferior muestra todo lo explicado anteriormente.

![alt text](https://i.ibb.co/Ht4CKPn/3.png)

![alt text](https://i.ibb.co/WnN7PG0/1.png)

### 2.7 - Orden USUARIO

Cuando el usuario escribe esta opción, debe proporcionar como argumento el identificador de un usuario del sistema Bizi. 
El programa informa acerca del número de utilizaciones del sistema que dicho usuario haya realizado de acuerdo con el 
fichero de usos seleccionado actualmente. Seguidamente se plasma una captura para reseñar el comportamiento del programa.

![alt text](https://i.ibb.co/Ht4CKPn/3.png) 

### 2.8 - Orden ESTADISTICAS

En caso de que el usuario escriba esta opción, el programa informa del número de utilizaciones del sistema que han realizado 
hombres y mujeres de acuerdo con el fichero de usos seleccionado actualmente. La captura siguiente refleja como retorna el
sistema los resultados al usuario.

![alt text](https://i.ibb.co/mNyJw4W/2.png)

### 2.9. - Orden FIN

Si el usuario selecciona esta opción, el programa termina (y, por lo tanto, no vuelve a solicitarmás órdenes). A continuación,
se muestra una imagen de la salida del sistema cuando el usaurio teclea una orden incorrecta.

![alt text](https://i.ibb.co/N9YgyPM/0.png)


## 3 - Control de órdenes no válidas

Cuando el usuario seleccione una órden no disponible, informa sobre el error y solicitar una nueva orden. La imagen 
siguiente muestra la retralimentación del programa.

![alt text](https://i.ibb.co/zFQZ59q/0.png)


## 4 - Ficheros del proyecto

Como se ha mencionado en apartados anteriores, los ficheros de texto con los que trabaja BikePlus han sido extraídos del portal
de datos abiertos del ayuntamiento de Zaragoza. En los subapartados siguientes se describen con detalle estos ficheros y su 
contenido.

### 4.1 - Fichero de usuarios

Cada fichero comienza con una línea de cabecera a la que le sigue la información sobre los usuarios del sistema Bizi en un 
determinado periodo de tiempo. Estos usuarios figuran cada uno en una línea distinta y contienen información sobre su 
identificador, su sexo (masculino —‘M’— o femenino —‘F’—) y sobre su rango de edad. En este proyecto no se ha empleado la 
información relativa al rango de edad al que pertenece cada usuario. La siguiente captura muestra un ejemplo de la apariencia
del fichero.

![alt text](https://i.ibb.co/QPsBg6K/7.png)

### 4.2 - Fichero de usos

Cada fichero comienza con una línea de cabecera a la que le sigue la información sobre los usos del sistema Bizi en un 
determinado periodo de tiempo. Estos usos figuran cada uno en una línea distinta y contienen información sobre el usuario al 
que corresponde el uso (identificado a través de un entero), el día y la hora en la que se retiró una bicicleta por parte del 
usuario, el código de la estación de la que se retiró, el día y la hora en la que se devolvió la bicicleta y el código de la 
estación en la que se devolvió. En este proyecto no se han empleado los datos relativos a los días y horas de retirada y 
devolución de las bicicletas. La siguiente captura evidencia la estructura sintáctica del fichero.

![alt text](https://i.ibb.co/x7mCfKR/5.png)

### 4.3 - Fichero de estaciones

Cada fichero comienza con una línea de cabecera a la que le sigue la información sobre las estaciones del sistema Bizi, 
a razón de una estación por línea. De toda la información que sobre cada estación figura en el fichero, solo se ha usado 
su identificador numérico (que figura al final de la primera URL de cada línea) y el nombre de la estación (el tercer dato de 
cada línea del fichero). Nótese como tanto la URL donde figura el identificador numérico como el nombre de la estación están 
rodeados por comillas. Seguidamente se muestra una imagen para reflejar la sintaxis del fichero.

![alt text](https://i.ibb.co/6bMqNJP/6.png) 


## 5 - Entornos de programación y desarrollo

BikePlus es un programa que ha sido desarrollado y preparado para poder ser ejecutado en sistemas operativos Linux y en sistemas
operativos de la familia de Windows. Para la programación de la versión de BikePlus para Windows se ha empleado el entorno de 
programación Codelite cuya versión es la 12.0 y el compilador MINGW para Windows de 64 bits. Para llevar a cabo la programación
de BikePlus en Linux se ha usado el editor de textos Atom.


## 6 - Compilación  y ejecución del proyecto

### 6.1 - Windows 

Para llevar a cabo la compilación y ejecución en Windows se ha proporcionado una carpeta denominada "Windows" en cuyo interior
se encuentra una carpeta llamada "BikePlus" correspondiente al proyecto desarrollado en Codelite. Para poder ejecutarlo basta 
crear un workspace, importar el proyecto y darle a la opción "Build and Run Project" tal y como muestra la siguiente imagen.

![alt text](https://i.ibb.co/K0FYJK8/8.png) 

### 6.2 - Linux

Para efectiar la compilación y ejecución del proyecto BikePlus se ha proporcioando una carpeta llamada "Linux" que contiene
una carpeta denominada "BikePlus" donde se encuentran los fichers del programa. Para poder compilar se debe hacer uso de un 
fichero Makefile. En el intérprete de comandos se deben introducir las órdenes make clean y make, generando un ejecutable en
el directorio "BikePlus". Para poder ejecutar el programa basta con teclear "./BikePlus en el directorio "BikePlus". Las 
siguientes imagenes muestran como compilar y ejecutar en Linux.

![alt text](https://i.ibb.co/0KRq9fv/10.jpg) 

![alt text](https://i.ibb.co/SrMBkp6/11.jpg)


## 7 - Pruebas

BikePLus ha sido probado en computadores con los sistemas operativos Windows 7, Windows 10, Ubuntu 17.10, Ubuntu 18.4 y 
Debian 9.4, aunque éste último es una máquina virtual corrida con Virtualbox, versión 5.2.14 r123301 (Qt5.6.2).


## 8 - Release 

El release es un zip comprimido que contiene dos capertas donde se guardan los archivos ejecutables de las versiones de BikePlus
para Linux y Windows, "BikePlusLinux" y "BikePlusWindows" respectivamente. Adicionalmente hay una carpeta llamada "Datos" donde
se almacenan los ficheros con los que trabaja el programa.


## 9 - Documentación

Los ficheros del portal de datos abiertos del ayuntamiento de Zaragoza han sido extraídos de la URL mostrada a continuación.

URL del portal: https://www.zaragoza.es/sede/portal/datos-abiertos/servicio/catalogo/70#CSV









