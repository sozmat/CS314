#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct ColorPoint {
	long a;
	long r;
	long g;
	long b;
};

long f(struct ColorPoint **points, int n) {
	long sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += points[j][i].a;
			sum += points[j][i].r;
			sum += points[j][i].g;
			sum += points[j][i].b;
		}
	}
	return sum;
}

long g(struct ColorPoint **points, int n) {
	long sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += points[i][j].a;
			sum += points[i][j].r;
			sum += points[i][j].g;
			sum += points[i][j].b;
		}
	}
	return sum;
}


struct ColorPoint** create2DArray(int n) {
	//Array to hold a pointer to the beginning of each row
	struct ColorPoint **points = 
		(struct ColorPoint **) malloc(n * sizeof(struct ColorPoint *));
	for (int i = 0; i < n; ++i) {
		//Array to hold each row
		points[i] = (struct ColorPoint *)malloc(n * sizeof(struct ColorPoint));
		for (int j = 0; j < n; ++j) {
			//Init the ColorPoint
			points[i][j].a = rand();
			points[i][j].r = rand();
			points[i][j].g = rand();
			points[i][j].b = rand();
		}
	}
	return points;
}

void free2DArray(struct ColorPoint** points, int n) {
	for (int i = 0; i < n; ++i) {
		free(points[i]);
	}
	free(points);
}

int main() {
    	
	// allocates a 2048 x 2048 array of ColorPoint structs 
	
	struct ColorPoint** array = create2DArray(2048);
	
	//measure the time taken to call the g and f functions for array above
	clock_t start = clock();
	for (size_t i = 0; i < 100000; i++) {
		f(array, 2048);
	}
	clock_t end = clock();
	double totalTime = ((double) (end - start)) / CLOCKS_PER_SEC;

	clock_t start2 = clock();
	for (size_t i = 0; i < 100000; i++) {
		g(array, 2048);
	}
	clock_t end2 = clock();
	double totalTime2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;

	printf("Time for f function to run is %f seconds\n", totalTime);
	printf("Time for g function to run is %f seconds\n", totalTime2);

	free(array);

	//on average, function f is taking longer than function g. I think this is because memory is row major
	//meaning that it is faster to access memory sequentially throughout rows than it is to go column by columnn 
	//which is what function f is doing when we access the array like array[j][i] rather than array[i][j].

	return 0;

}
