#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void ordenarNumeros( int *ponteiro, int tamanho ) {
    int i, j, valor, qtdTrocas, qtdIteracoes;
    for( i = 1; i < tamanho; i++ ) {
    	qtdIteracoes++;
        valor = ponteiro[i];
        for( j = i-1; j >=0 && valor < ponteiro[j]; j-- ) {
        	qtdIteracoes++;
            ponteiro[j+1] = ponteiro[j];  
        }
        ponteiro[j+1] = valor;
        qtdTrocas++;
    }
    printf("\nCom InsertionSort foram %i trocas e %i iterações.\n", qtdTrocas, qtdIteracoes);
}

void imprimirNumeros( int array[], int tamanho ) {
    int i;
    for ( i = 0; i < tamanho; i++ ) {
        printf("\tPos. %i número: %i \n", i+1, array[i]);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int numeros [] = {25, 57, 48, 37, 12, 92, 86, 33};
    int tamanho = sizeof( numeros )/sizeof( int );
    printf("\nNúmeros originais:\n");
    imprimirNumeros(numeros, tamanho);
    ordenarNumeros(numeros, tamanho);
    printf("\nNúmeros ordenados:\n");
    imprimirNumeros(numeros, tamanho);
    return 1;
}
