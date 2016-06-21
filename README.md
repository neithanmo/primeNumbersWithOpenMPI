Este es un programa que implementa la busqueda de todos los numeros primos menores a N.
por defecto N = 5000, su valor puede modificarse, dentro de primo.cpp en el define.

##########################################################################################

					Dependencias

#########################################################################################

para la implementación en paralelo de la busqueda de numeros primos se utiliza la libreria openMPI
la cual se encuentra en los repositorios de ubuntu

##########################################################################################

                                        Compilación y ejecución
                                        
                                        
###########################################################################################

para compilar este programa, y su implementación secuencial ejecute el siguiente comando:

>g++ -o serial serial.cpp

para ejecutarlo bastará:

>./serial

para compilar la versión en paralelo, ejecute el siguiente comando

>mpic++ primos.cpp -o result

y la ejecución:

>time mpirun -np 8 result

para usar 8 procesos en paralelo ó

>time mpirun -np 10 result

a mayor cantidad de procesos, más rápido se calculan los numeros primos.

