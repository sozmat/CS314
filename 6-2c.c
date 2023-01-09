#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inner(float *u, float *v, int length, float *dest) {
	int i;
	float sum = 0.0f;
	for (i = 0; i < length; i++) {
		sum += u[i] * v[i];
	}
	*dest = sum;
}

void inner2(float *u, float *v, int length, float *dest) {
	int i;
	float sum2 = 0.0f;
	for (i = 0; i < length; i+=4) {
		sum2 += u[i] * v[i];
		sum2 += u[i+1] * v[i+1];
		sum2 += u[i+2] * v[i+2];
		sum2 += u[i+3] * v[i+3];
	}
	*dest = sum2;
}

int main() {
    for (int i = 1; i < 22; i+=10){
    int array_size = 10 * i * i;
    float *u = (float *)malloc(array_size * sizeof(float));
    float *v = (float *)malloc(array_size * sizeof(float));

    // fill arrays of size 100
    for (int i = 0; i < array_size; i++){
		u[i] = i;
		v[i] = i;
    }

    float *final = (float *) malloc(sizeof(float));
    float *final2 = (float *) malloc(sizeof(float));
    
    // timing inner for array size 100
    clock_t start = clock();
    inner(u, v, array_size, final);
    clock_t end = clock();
    double totalTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    //timing inner2 for array size 100
    clock_t start2 = clock();
    inner2(u, v, array_size, final2);
    clock_t end2 = clock();
    double totalTime2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;


    printf("%f\n", *final);   // printing both these values to ensure
    printf("%f\n", *final2);  // these functions are functionally equivalent

    // time analysis
    printf("Time of inner function takes for %d size array is %f seconds.\n", array_size, totalTime);
    printf("Time of inner2 function takes for %d size array is %f seconds.\n", array_size, totalTime2);

    free(u);
    free(v);
    free(final);
    free(final2);
    }
    return 0;
}
