#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int ordenarNumeros( int array[], int index ) {
    int vlrMaior, i, j, count;
    count = 0;
    for ( i = 0; i < index; i++ ){
        for ( j = 0; j < index-1; j++ ){
            if ( array[j] > array[j+1] ) {
                vlrMaior = array[j];
                array[j] = array[j+1];
                array[j+1] = vlrMaior;
                count++;
            }
        }
    }
    printf("\nCom BubbleSort foram %i trocas.\n", count);
    return array;
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
    int tam = sizeof(numeros)/sizeof(int);
    printf("\nNumeros antes da ordenacao:\n");
    imprimirNumeros(numeros, tam);
    int numerosOrdenados = ordenarNumeros(numeros, tam);
    printf("\nNumeros depois da ordenacao:\n");
    imprimirNumeros(numerosOrdenados, tam);
}