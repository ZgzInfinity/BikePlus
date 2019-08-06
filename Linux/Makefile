#*****************************************************************
# Archivo: Makefile Proyecto BikePlus
# Author:  Ruben Rodriguez Esteban ZgzInfinity
# Fecha:   6 de agosto de 2019
# Coms:    Fichero MakeFile para compilar el proyecto BikePlus   
#          Para compilar y ejecutar seguir estos pasos en terminal
#          1 - Make clean
#          2 - Make
#          3 - ./BikePlus      
#*****************************************************************

# Seleccion del compilador
CC=g++

# Expansion de variables
USUARIO_BIZI_DIR=Usuario
USO_BIZI_DIR=Uso
ESTACION_BIZI_DIR=Estacion
BIKEPLUS_DIR=BikePlus

USUARIO=${USUARIO_BIZI_DIR}/Bizi-usuario
USO=${USO_BIZI_DIR}/Bizi-uso
ESTACION=${ESTACION_BIZI_DIR}/Bizi-estacion
BIKEPLUS=${BIKEPLUS_DIR}/BikePlus


# Regla para compilar el programa principal
all: ${BIKEPLUS} 


# USUARIO
# Compilacion
${USUARIO}.o: ${USUARIO}.h  ${USUARIO}.cc
	${CC} -c  ${USUARIO}.cc -o ${USUARIO}.o
#----------------------------------------------------------------


# ESTACION
# Compilacion
${ESTACION}.o: ${ESTACION}.h ${ESTACION}.cc
	${CC} -c ${ESTACION}.cc -o ${ESTACION}.o
#--------------------------------------------------------------


# USO
# Compilacion
${USO}.o: ${USO}.h  ${USO}.cc
	${CC} -c ${USO}.cc -o ${USO}.o
#---------------------------------------------------------------


# BIKEPLUS
# Compilacion
${BIKEPLUS/BIKEPLUS}.o: ${BIKEPLUS}.cpp
	${CC} -c ${BIKEPLUS}.cpp

# Linkado
${BIKEPLUS}: ${USUARIO}.o ${USO}.o ${ESTACION}.o ${BIKEPLUS}.o  
	${CC} ${USUARIO}.o ${USO}.o ${ESTACION}.o ${BIKEPLUS}.o -o ${BIKEPLUS}
#---------------------------------------------------------------

# LIMPIEZA
clean:
	$(RM) ${USUARIO}.o
	$(RM) ${USO}.o
	$(RM) ${ESTACION}.o
	$(RM) ${BIKEPLUS}.o
