/*
* kernels.c
* - Holds all the function implementations for the kernels
*/
// Pre-defined libraries
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// for random number generation
#include <time.h>


float random_generator(float min, float max) {
	return ((float)rand() / (float)RAND_MAX) * (max - min) + min;
}


/***** SAXPY Operation *****/
float saxpyC(int n, float a, float* x, float* y, float* z) {
	for (int i = 0; i < n; i++) {
		z[i] = a * x[i] + y[i];
	}
}


void computeAveTime(double* time, int iterations, double* totalTime, double* averageTime) {
	// Compute the total time
	for (int i = 0; i < iterations; i++) {
		*totalTime += time[i];
	}

	// Compute the average time
	*averageTime = *totalTime / iterations;

	// Display the average time
	printf("Average time: %f\n", *averageTime);
}