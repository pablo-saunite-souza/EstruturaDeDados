#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void trocarPosicao( int array[], int pos ) {
    int aux;
    aux = array[pos];
    array[pos] = array[pos+1];
    array[pos+1] = aux;
}

void ordenarNumeros( int array[], int index ) {
    printf("\nOrdenando os numeros...\n");
    int vlrMaior, i, j, trocas, ite;
    trocas = 0;
    for ( i = 0; i < index; i++ ){
        for ( j = 0; j < index-1; j++ ){
            if ( array[j] > array[j+1] ) {
                trocarPosicao(array, j);
                trocas++;
            }
            ite++;
        }
    }
    printf("\nCom BubbleSort foram %i trocas e %i iteracoes.\n", trocas, ite);
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
    ordenarNumeros(numeros, tam);
    printf("\nNumeros depois da ordenacao:\n");
    imprimirNumeros(numeros, tam);

}