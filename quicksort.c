#include <stdio.h>

void printOut (int *array, int length){
    int i;
    printf("[ ");
    for (i = 0; i < length; i++){
        printf("%d ", array[i]);
    }
    printf("]\n");
}

void changePosition (int *array, int i, int j){
    int bigger;
    bigger = array[i];
    array[i] = array[j];
    array[j] = bigger;
    printOut (array, 8);
}

int particao (int *array, int initialPosition, int finalPosition){
    int center, i, j;
    center = array[(initialPosition+finalPosition)/2];
    i = initialPosition-1;
    j = finalPosition+1;
    while (i < j){
        do{
            j--;
        }while (array[j] > center);
        do{
            i++;
        }while (array[i] < center);
        if (i < j){
        	changePosition (array, i, j);
		}
    }
    return j;
}

void quicksort (int *array, int initialPosition, int finalPosition){
    int middle;
    if (initialPosition < finalPosition){
        middle = particao (array, initialPosition, finalPosition);
        quicksort (array, initialPosition, middle);
        quicksort (array, middle+1, finalPosition);
    }
}

int main(){
    int numbers[] = { 25, 37, 48, 57, 12, 92, 86, 33 };
    int length = sizeof(numbers)/sizeof(int);
    printOut (numbers, length);
    quicksort (numbers, 0, length-1);
}
