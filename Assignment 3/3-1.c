#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 10

struct IntArray {
	int length;
	int *dataPtr;
};

struct IntArray* mallocIntArray(int len){
	//allocates, initializes and returns a pointer to a new struct IntArray	
	struct IntArray* array = malloc(len * sizeof(struct IntArray));
	array->length = len; 
	array->dataPtr = (int*)malloc(sizeof(int) * len);
	return array;
	}	

void freeIntArray(struct IntArray *arrayPtr){
	//frees the instance's dataPtr and frees the instance
	free(arrayPtr->dataPtr); 
	free(arrayPtr);
	}

void readIntArray(struct IntArray *array){
	//prompts and reads positive (>0) ints from the user to fill the array
	// should print error message and prompt again if user enters value
	// that cannot be parsed as positive int
	int i = 0;
	while (i < array->length) {
	char linebuf[BUFSIZE];
	char *p;

	long size = 0L;
	while (size <= 0L) {
		printf("Enter an integer: ");
		fgets(linebuf, BUFSIZE, stdin);
		size = strtol(linebuf, &p, 10);
			if (p == linebuf) {
				printf("Invalid input.\n");
			} else if (size < 0) {
				printf("Invalid input. Negative values not allowed.\n");
			}
		} array->dataPtr[i] = size; //stores our values into our array
		i++;		
	}
}

void swap(int *xp, int *yp){
	//swaps the int values stored at the xp and yp pointers
	int t0 = *xp;
	int t1 = *yp;
	*xp = t1;
	*yp = t0;
	}

void sortIntArray(struct IntArray *array){
	//sorts the input array in ascending order using Bubble Sort
	// https://www.geeksforgeeks.org/bubble-sort/
	int i, j;
	for (i = 0; i < array->length -1; i++){
		for (j = 0; j < array->length -i-1; j++){
			if (array->dataPtr[j] > array->dataPtr[j+1]){
				swap(&array->dataPtr[j], &array->dataPtr[j+1]);
			}
		}
	}
}

void printIntArray(struct IntArray *array){
	printf("[");
	for (int i = 0; i < array->length; i++){
		if (i < array->length -1) {
			printf("%d, ", array->dataPtr[i]);
			continue;}
		printf("%d", array->dataPtr[i]);
	}
	printf("]\n");
}

int main() {
    char linebuf[BUFSIZE];
    char *p;

    long size = 0L;
    while (size <= 0L) {
	printf("Enter a length size: ");
 	fgets(linebuf, BUFSIZE, stdin);
	size = strtol(linebuf, &p, 10);
		if(p == linebuf) {
			printf("Invalid input.\n");
		} else if (size < 0) {
			printf("Invalid input. Negative values not allowed.\n");
	}
    }
    
    int length = (int)size;
    struct IntArray *array = mallocIntArray(length);
    readIntArray(array);
    sortIntArray(array);
    printIntArray(array);
    freeIntArray(array);	//ran with valgrind, no memory errors detected :)
    return 0;
    

}
