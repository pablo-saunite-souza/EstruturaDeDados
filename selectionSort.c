#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void trocarNumeros( int lista[], int pos, int indice ) {
	int aux;
	aux = lista[indice];
	lista[indice] = lista[pos];
	lista[pos] = aux;
}

void ordenarNumeros( int lista[], int tamanho ) {
    printf("\nOrdenando os números...\n");
    int vlrMaior, indice, qtdTrocas, qtdIteracoes;
    int pos1, pos2;
    for ( pos1 = tamanho-1; pos1 > 0; pos1-- ) {
        vlrMaior = lista[0];
        indice = 0;
        for ( pos2 = 1; pos2 <= pos1; pos2++ ) {
            qtdIteracoes++;
            if ( lista[pos2] < vlrMaior ) {
                continue;
            }
            vlrMaior = lista[pos2];
            indice = pos2;
        }
        qtdTrocas++;
        trocarNumeros(lista, pos1, indice);
    }
    printf("\nCom Selectionsort foram %i trocas e %i iterações.\n", qtdTrocas, qtdIteracoes);
}

void imprimirNumeros( int lista[], int tamanho ) {
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
    imprimirNumeros(numeros, tamanho);
    ordenarNumeros(numeros, tamanho);
    printf("\nLista de números depois da ordenação:\n");
    imprimirNumeros(numeros, tamanho);
    return 1;
}
