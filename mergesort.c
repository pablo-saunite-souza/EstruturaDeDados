#include <stdio.h>

void printOut (int *array, int length){
    int i;
    printf("[ ");
    for (i = 0; i < length; i++){
        printf("%d ", array[i]);
    }
    printf("]\n");
}

void mount (int *array, int start, int end, int middle){
	int freePosition, leftArray, rightArray, i;
	int aux[end];
	leftArray = start;
	rightArray = middle+1;
	freePosition = start;
	while (leftArray <= middle && rightArray <= end){
	    if (array[leftArray] <= array[rightArray]){
	        aux[freePosition] = array[leftArray];
	        leftArray += 1;
	    }else{
	        aux[freePosition] = array[rightArray];
	        rightArray += 1;
	    }
	    freePosition++;
	}
	for (i = leftArray; i <= middle; i++){
	    aux[freePosition] = array[i];
	    freePosition++;
	}
	for (i = rightArray; i <= end; i++){
	    aux[freePosition] = array[i];
	    freePosition++;
	}
	for (i = start; i <= end; i++){
		array[i] = aux[i];
	}   
    printOut (array, 8);
}

void mergesort (int *array, int initialPosition, int finalPosition){
    int middle;
    
    if (initialPosition < finalPosition){
    	
        middle = (initialPosition+finalPosition)/2;
        mergesort (array, initialPosition, middle);
        mergesort (array, middle+1, finalPosition);
        mount (array, initialPosition, finalPosition, middle);
    }
}

int main(){
    int numbers[] = { 25, 57, 48, 37, 12, 92, 86, 33 };
    int length = sizeof(numbers)/sizeof(int);
    printOut (numbers, length);
    mergesort (numbers, 0, length-1);
}

