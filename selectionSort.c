#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int ordenarNumeros ( int array[], int n ) {
    int i, j, vlrMaior, index, count;
    for ( i = n-1; i > 0; i-- ) {
        vlrMaior = array[0];
        index = 0;
        for ( j = 1; j <= i; j++ ) {
            if ( array[j] > vlrMaior ) {
                vlrMaior = array[j];
                index = j;
            }
        }
        array[index] = array[i];
        array[i] = vlrMaior;
        count++;
    }
    printf("\nCom SelectionSort foram %i trocas.\n", count);
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