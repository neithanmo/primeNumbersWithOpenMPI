#include <math.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#define num_rows 5000

void esPrimo(int &limite, std::vector<int> *array1);

void esPrimo(int &limite, std::vector<int> *array1){
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
    std::vector <int > *array = new std::vector<int>(num_rows);//vector original con los enteros hasta 5000
    int limite = (int)sqrt(num_rows);
	
    for(int i = 0; i < num_rows; i++){
            array->at(i) = i+2;
     }

    esPrimo(limite, array);

    printf("\n ===========================================================================> \n");
    printf("\n SE ENCONTRARON %u NUMEROS PRIMOS Y SON LOS SIGUIENTES \n", (int)array->size());
    for(int i = 0; i<array->size();i++){
            std::cout<<"  "<<array->at(i);
    }
    printf("\n ===========================================================================> \n");
    delete array;

}


