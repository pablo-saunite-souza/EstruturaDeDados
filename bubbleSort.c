#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void trocarPosicao( int lista[], int pos ) {
    int aux;
    aux = lista[pos];
    lista[pos] = lista[pos+1];
    lista[pos+1] = aux;
}

void ordenar( int lista[], int tamanho ) {
    printf("\nOrdenando os números...\n");
    int vlrMaior, qtdTrocas, qtdIteracoes;
    int i, j;
    qtdTrocas = 0;
    for (i = 0; i < tamanho; i++ ){
        for (j = 0; j < tamanho-1; j++ ){
            qtdIteracoes++;
            if ( lista[j] < lista[j+1] ) {
                continue;
            }
            trocarPosicao(lista, j);
            qtdTrocas++;
        }
    }
    printf("\nCom BubbleSort foram %i trocas e %i iterações.\n", qtdTrocas, qtdIteracoes);
}

void imprimir( int lista[], int tamanho ) {
    int i;
    for ( i = 0; i < tamanho; i++ ) {
        printf("\tPos. %i número: %i \n", i+1, lista[i]);
    }
}

int main () {
    setlocale(LC_ALL, "Portuguese");
    int numeros [] = {25, 57, 48, 37, 12, 92, 86, 33};
    int tamanho = sizeof(numeros)/sizeof(int);
    printf("\nLista de números antes da ordenação:\n");
    imprimir(numeros, tamanho);
    ordenar(numeros, tamanho);
    printf("\nLista de números depois da ordenação:\n");
    imprimir(numeros, tamanho);
    return 1;
}
