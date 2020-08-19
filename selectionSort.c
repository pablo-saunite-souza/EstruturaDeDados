#include <stdio.h>

void printOut ( int *array, int length ) {
	int i;
	printf("[");
    for ( i = 0; i < length; i++ ) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

void changePosition( int *array, int pos, int index, int length ) {
	int bigger;
	bigger = array[index];
	array[index] = array[pos];
	array[pos] = bigger;
	printOut (array, length);
}

void selectionsort ( int *array, int length ) {
    int bigger, index, changeCount, iCount;
    int pos1, pos2;
    changeCount = 0;
    iCount = 0;
    for ( pos1 = length-1; pos1 > 0; pos1-- ) {
        bigger = array[0];
        index = 0;
        for ( pos2 = 1; pos2 <= pos1; pos2++ ) {
            if ( array[pos2] > bigger ) {
            	bigger = array[pos2];
            	index = pos2;
            }
            iCount++;
        }
        changePosition(array, pos1, index, length);
        changeCount++;
    }
    printf("\nSelectionsort %i changes and %i iterations.\n", changeCount, iCount);
}

int main () {
    int numArray [] = { 25, 57, 48, 37, 12, 92, 86, 33 };
    int length = sizeof(numArray)/sizeof(int);
    printOut (numArray, length);
    selectionsort(numArray, length);
    return 1;
}
