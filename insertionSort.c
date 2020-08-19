#include <stdio.h>

void printOut ( int *array, int length ) {
    int i;
    printf("[");
    for ( i = 0; i < length; i++ ) {
        printf("%i ", array[i]);
    }
    printf("]\n");
}

void insertionsort ( int *array, int length ) {
    int i, j, bigger, changeCount, iCount;
    changeCount = 0;
    iCount = 0;
    for( i = 1; i < length; i++ ) {
        bigger = array[i];
        for( j = i-1; j >=0 && bigger < array[j]; j-- ) {
            array[j+1] = array[j];
            iCount++;
        }
        array[j+1] = bigger;
        changeCount++;
        printOut (array, length);
    }
    printf("\nInsertionsort %i changes and %i iterations.\n", changeCount, iCount);
}

int main() {
    int numbersArray [] = { 25, 57, 48, 37, 12, 92, 86, 33 };
    int length = sizeof( numbersArray )/sizeof( int );
    printOut (numbersArray, length);
    insertionsort (numbersArray, length);
    return 1;
}
