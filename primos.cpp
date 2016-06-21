#include <mpi.h>
#include <math.h>
#include <iostream>
#include <vector>
#define num_rows 5000

void esPrimo(int limite, std::vector<int> *array1);

void esPrimo(int limite, std::vector<int> *array1){
    int number;
    for(int i = 0; i< array1->size(); i++){ //cálculo de los numeros primos
        number = array1->at(i);  //eliminando del array todos aquellos que no lo sean
        if(number < limite){
            for(int contador = 0; contador < array1->size(); contador++){
                    int valor = array1->at(contador);
                    if((valor != number) && (valor % number == 0)){
                          array1->erase(array1->begin() + contador);
                    }

            }
        }
    }
}

int main(int argc, char *argv[]){

    int my_id, root_process, ierr, i, num_procs,
            an_id, avg_rows_per_process,
            limite, number;

    ierr = MPI_Init(&argc, &argv);//a partir de aqui todo el código se ejecutara en paralelo

    std::vector <int > *array = new std::vector<int>(num_rows);//vector original con los enteros hasta 5000
        limite = (int)sqrt(num_rows);

	/* la idea es partir el vector de 5000 elementos es arreglos mas pequeños de 1250 cada uno, y
	que cada proceso, cuatro en total, operen sobre uno de ellos y realize el cálculo de los numeros
	primos, eliminando del arreglo aquellos que no lo son. de modo que proceso 0, inicializa el arreglo y reparte 
	los elementos entre los demas procesos, enviandole el arreglo y el punto de inicio y final sobre el arreglo para operar,
	los procesos envian al proceso 0 los nuevos arreglos conteniendo los primos encontrados */


	root_process = 0;
	
	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
    ierr = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);//numero de procesos, deben ser 4 en total
    avg_rows_per_process = num_rows/num_procs;

    std::vector <int > *array1 = new std::vector<int>(avg_rows_per_process); //array de datos que recive cada proceso

	if(my_id == root_process){
            printf("proceso 0 inicializando arreglo \n");
            for(i = 0; i < num_rows; i++){
                    array->at(i) = i+2;
            }
    }

    MPI_Scatter(&array->front(), avg_rows_per_process, MPI_INT, &array1->front(),
                    avg_rows_per_process, MPI_INT, 0, MPI_COMM_WORLD);


    if(my_id == 0)
        esPrimo(limite, array1);
    else
       esPrimo(limite, array1);

    //int num_primos = array1->size();

    switch (my_id) {
    case 1:{
        printf("\n el proceso %u inicia con %u: \n", my_id, (int)array1->at(0));
            printf("\n el proceso %u encontro los siguientes numeros primos: \n", my_id);
            printf("\n %u TAMAÑO DEL VECTOR PRIMOS ES DE %u \n", my_id,(int)array1->size());
            for(int i = 0; i<array1->size();i++){
                printf(" %u", array1->at(i));
            }
            printf("\n ===========================================================================> \n");
        }

            break;
     case 0:{
        printf("\n el proceso %u inicia con %u: \n", my_id, (int)array1->at(0));
            printf("\n el proceso %u encontro los siguientes numeros primos: \n", my_id);
            printf("\n %u TAMAÑO DEL VECTOR PRIMOS ES DE %u \n", my_id,(int)array1->size());
            for(int i = 0; i<array1->size();i++){
                printf(" %u", array1->at(i));
            }
            printf("\n ===========================================================================> \n");
        }
            break;
     case 2:{
        printf("\n el proceso %u inicia con %u: \n", my_id, (int)array1->at(0));
            printf("\n el proceso %u encontro los siguientes numeros primos: \n", my_id);
            printf("\n %u TAMAÑO DEL VECTOR PRIMOS ES DE %u \n", my_id,(int)array1->size());
            for(int i = 0; i<array1->size();i++){
                printf(" %u", array1->at(i));
            }
            printf("\n ===========================================================================> \n");
        }
            break;
     case 3:{
        printf("\n el proceso %u inicia con %u: \n", my_id, (int)array1->at(0));
           printf("\n el proceso %u encontro los siguientes numeros primos: \n", my_id);
           printf("\n %u TAMAÑO DEL VECTOR PRIMOS ES DE %u \n", my_id,(int)array1->size());
           for(int i = 0; i<array1->size();i++){
               printf(" %u", array1->at(i));
           }
           printf("\n ===========================================================================> \n");
       }
           break;
        default:
            break;
        }

    delete array;
    delete array1;

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();

}


