#include<stdio.h>

void printOut (int *array, int length){
    int i;
    printf("[ ");
    for (i = 0; i < length; i++){
        printf("%d ", array[i]);
    }
    printf("]\n");
}

void shellsort(int *array, int length, int *increment, int gapLength) {
    int i, j, k;
	int span, bigger;
    for (i = 0; i < gapLength; i++){
        span = increment[i];
        for (j = span; j < length; j++){
            bigger = array[j];
            for (k = j - span; k >= 0 && bigger < array[k]; k-=span){
            	array[k+span] = array[k];
			}
            array[k+span] = bigger;
        }
        printOut (array, length);
    }
}

int main(){
    int numArray[] = { 25, 57, 48, 37, 12, 92, 86, 33 };
    int gap[] = {5,3,1};
    int length = sizeof(numArray)/sizeof(int);
    int gapLength = sizeof(gap)/sizeof(int);
    printOut(numArray, length);
    shellsort(numArray, length, gap, gapLength);
}
