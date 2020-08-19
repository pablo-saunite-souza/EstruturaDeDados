#include <stdio.h>

void printOut ( int *array, int length ) {
    int i;
    printf("[ ");
    for ( i = 0; i < length; i++ ) {
        printf("%i ", array[i]);
    }
    printf("]\n");
}

void changePosition ( int *array, int index, int length ) {
    int bigger;
    bigger = array[index];
    array[index] = array[index+1];
    array[index+1] = bigger;
    printOut (array, length);
}

void bubblesort ( int *array, int length ) {
    int changeCount, iCount;
    changeCount = 0;
    iCount = 0;
    int i, j;
    for (i = 0; i < length; i++ ){
        for (j = 0; j < length-1; j++ ){
            if ( array[j] > array[j+1] ) {
                changePosition(array, j, length);
            	changeCount++;
            }
            iCount++;
        }
    }
    printf("\nBubblesort %i changes and %i iterations.\n", changeCount, iCount);
}

int main () {
    int numbersArray [] = { 25, 57, 48, 37, 12, 92, 86, 33 };
    int length = sizeof(numbersArray)/sizeof(int);
    printOut(numbersArray, length);
    bubblesort(numbersArray, length);
    return 1;
}
