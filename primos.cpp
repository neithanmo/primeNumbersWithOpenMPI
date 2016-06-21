#include <mpi.h>
#include <math.h>
#include <iostream>
#include <vector>
#define num_rows 5000

void esPrimo(int limite, std::vector<int> *array1);

void esPrimo(int limite, std::vector<int> *array1){
    int number;
    for(int i = 1; i<=limite; i++){ //cálculo de los numeros primos
        number = i;  //eliminando del array todos aquellos que no lo sean
        for(int contador = 0; contador < array1->size(); contador++){
              int valor = array1->at(contador);
              if((valor != number) && (valor % number == 0)){
                       array1->erase(array1->begin() + contador);
                 }

         }
    }
}


int main(int argc, char *argv[]){

    int my_id, root_process, ierr, i, num_procs,
            avg_rows_per_process, limite;

    ierr = MPI_Init(NULL, NULL);

    std::vector <int > *array = new std::vector<int>(num_rows);//vector original con los enteros hasta 5000
        limite = (int)sqrt(num_rows);

    /* la idea es partir el vector de 5000 elementos en arreglos mas pequeños de 5000/(numero de procesos) cada uno, y
    que cada proceso, opere sobre uno de ellos y realize el cálculo de los numeros
	primos, eliminando del arreglo aquellos que no lo son. de modo que proceso 0, inicializa el arreglo y reparte 
    los elementos entre los demas procesos, enviandole la sección del arreglo que inicializa a cada proceso
     luego cada proceso muestra en pantalla la cantidad de primos que encontro y los muestra, esta es la forma
    mas lógica de paralelizar este programa*/


	root_process = 0;
	
	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
    ierr = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);//numero de procesos, deben ser 4 en total
    avg_rows_per_process = num_rows/num_procs;

    std::vector <int > *array1 = new std::vector<int>(avg_rows_per_process); //array de datos que recive cada proceso

    double t1 = MPI_Wtime();

	if(my_id == root_process){
            for(i = 0; i < num_rows; i++){
                    array->at(i) = i+2;
            }
    }

    MPI_Scatter(&array->front(), avg_rows_per_process, MPI_INT, &array1->front(),
                    avg_rows_per_process, MPI_INT, root_process, MPI_COMM_WORLD);

    esPrimo(limite, array1);

   switch (my_id) {

    case 1:{
            printf("\n ===========================================================================> \n");
            printf("\n EL PROCESO %u ENCONTRO %u NUMEROS PRIMOS Y SON LOS SIGUIENTES \n", my_id, (int)array1->size());
            for(int i = 0; i<array1->size();i++){
                std::cout<<" "<< array1->at(i);
                //printf(" %u", array1->at(i));
            }
            printf("\n ===========================================================================> \n");
        }

            break;
     case 0:{
            printf("\n ===========================================================================> \n");
            printf("\n EL PROCESO %u ENCONTRO %u NUMEROS PRIMOS Y SON LOS SIGUIENTES \n", my_id, (int)array1->size());
            for(int i = 0; i<array1->size();i++){
                std::cout<<" "<< array1->at(i);
            }
            printf("\n ===========================================================================> \n");
        }
            break;
     case 2:{
            printf("\n ===========================================================================> \n");
            printf("\n EL PROCESO %u ENCONTRO %u NUMEROS PRIMOS Y SON LOS SIGUIENTES \n", my_id, (int)array1->size());
            for(int i = 0; i<array1->size();i++){
                std::cout<<" "<< array1->at(i);
            }
            printf("\n ===========================================================================> \n");
        }
            break;
     case 3:{
            printf("\n ===========================================================================> \n");
            printf("\n EL PROCESO %u ENCONTRO %u NUMEROS PRIMOS Y SON LOS SIGUIENTES \n", my_id, (int)array1->size());
           for(int i = 0; i<array1->size();i++){
               std::cout<<" "<< array1->at(i);
           }
           printf("\n ===========================================================================> \n");
       }
           break;
        default:{
                printf("\n ===========================================================================> \n");
                printf("\n EL PROCESO %u ENCONTRO %u NUMEROS PRIMOS Y SON LOS SIGUIENTES \n", my_id, (int)array1->size());
                for(int i = 0; i<array1->size();i++){
                        std::cout<<" "<< array1->at(i);
                        }
                printf("\n ===========================================================================> \n");
            }
            break;
        }


    MPI_Barrier(MPI_COMM_WORLD);
    double t2 = MPI_Wtime();
    printf( "\n process %u haved Elapsed time of %f\n", my_id, t2 - t1 );
    delete array;
    delete array1;
    MPI_Finalize();

}


