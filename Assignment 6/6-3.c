#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float f(float *a, int n) {
	float prod = 1.0f;
	for (int i = 0; i < n; ++i) {
		if (a[i] != 0.0f) {
			prod *= a[i];
		}
	}
	return prod;
}

float g(float *b, int n) {
	//same as f() but without zero check
	float prod = 1.0f;
	for (int i = 0; i < n; ++i) {
		prod *= b[i];
	}
	return prod;
}

float* createArray(int size) {
	float *a = (float *)malloc(size * sizeof(float));
	for (int i = 0; i < size; ++i) {
		// 50% chance that a[i] is 0.0f, random value on the range
		//  [0.76, 1.26] otherwise.
		float r = rand() / (float)RAND_MAX;
		a[i] = r < 0.5f ? 0.0f : r + 0.26f;
	}
	return a;
}

int main(){

    // create array a
    float *a = createArray(10000);
    
    // time array a
    clock_t start = clock();
    for (int i = 0; i < 10000; i++){ // to exaggerate the time taken
    	f(a, 10000);
    }
    clock_t end = clock();
    double totalTime = ((double) (end - start)) / CLOCKS_PER_SEC;

    // create array b
    float *b = malloc(10000 * sizeof(float));

    // replace 0.0f with 1.0f
    int counter = 0;
    for (int i = 0; i < 10000; i++){
	    if (a[i] == 0.0f){
		    b[i] = 1.0f;
		    counter++;
	    }
	    else{
		    b[i] = a[i];
    	}
    }
    
    // time array b
    clock_t start2 = clock();
    for (size_t i = 0; i < 10000; i++) { // extra loop to exaggerate the time taken
	    g(b, 10000);
    }
    clock_t end2 = clock();
    double totalTime2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;


    // create array c, c contains only nonzero elements of a
    int new_size = 10000 - counter;  //counter is computed in code above, finds out
    				     // how many zero elements there are in array a
    float *c = malloc(new_size * sizeof(float));
    int tracker = 0; // array c needs its own indexer
    for (int i = 0; i < new_size; i++){
	    if (a[i] != 0.0f) {
		    c[tracker] = a[i];
		    tracker++;
	    }
    } 
    

    // time array c
    clock_t start3 = clock();
    for (size_t i = 0; i < 10000; i++) { // extra loop to exaggerate time taken
	    g(c, 10000);
    }
    clock_t end3 = clock();
    double totalTime3 = ((double) (end3 - start3)) / CLOCKS_PER_SEC;

    // print results
    printf("Array a time is %f\n", totalTime);
    printf("Array b time is %f\n", totalTime2);
    printf("Array c time is %f\n", totalTime3);

    /*
    b)
    g(b) compared to f(a) runs slower. I believe this is because in f(a), the if statement checks for any nonzeros
    and then performs the operation. If there is a zero in the array, it will be skipped over which means we won't 
    have to do the mul operation, saving us CPE. Although we no longer have the if statement, for g(b) we have to 
    run through every element and compute the multiplication no matter the value which ends up being more costly.

    c)
    On average g(c) runs faster than both f(a) and g(b). This makes sense since the array size is smaller, so 
    we have less iterations to run through. By only have the nonzero elements of a, we run through fewer iterations
    and save CPE by not having to do as many multiplication operations. 
     */

    // free memory
    free(a);
    free(b);
    free(c);
   
}
