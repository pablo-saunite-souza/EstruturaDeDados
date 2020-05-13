#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int ordenarNumeros( int *pont, int index ) {
    int i, j, valor, count;
    for ( i = 1; i < index; i++ ) {
        valor = pont[i];
        for ( j = i-1; j >=0 && valor < pont[j]; j-- ) {
            pont[j+1] = pont[j];
            count++;
        }
        pont[j+1] = valor;
    }
    printf("\nCom InsertionSort foram %i trocas.\n", count);
    return pont;
}

void imprimirNumeros( int array[], int index ) {
    int i;
    for ( i = 0; i < index; i++ ) {
        printf("\tPos. %i numero: %i \n", i+1, array[i]);
    }
}

int main () {
    setlocale(LC_ALL, "Portuguese");
    int numeros [] = {25, 57, 48, 37, 12, 92, 86, 33};
    int tam = sizeof( numeros )/sizeof( int );
    printf("\nNúmeros originais:\n");
    imprimirNumeros ( numeros, tam );
    int numerosOrdenados = ordenarNumeros( numeros, tam );
    printf("\nNúmeros ordenados:\n");
    imprimirNumeros ( numerosOrdenados, tam );
}