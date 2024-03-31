/*
* main.cpp
* - Main program that runs the kernel functions in both C and Assembly language
*
* Date: 29 March 2024
* Version: 1.0
*
* References:
* - Dynamic Array Allocation: https://www.geeksforgeeks.org/dynamic-array-in-c/
* - Random Number Generation: https://stackoverflow.com/questions/13408990/how-to-generate-random-float-number-in-c
* - Time Measurement: https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
*/

// Pre-defined libraries
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// for random number generation
#include <time.h>

// User-defined libraries
#include "kernels.h"

// Define variables
#define ITERATIONS 30


// TO DO: Call the assembly function


/***** Main Program *****/
int main(int argc, char* argv[]) {
	// Time measurement
	clock_t startC, endC;

	// Array to store the time measurements
	double* timeC = (double*)malloc(ITERATIONS * sizeof(double));
	double currTimeC = 0.0;
	double totalTimeC = 0.0;
	double averageTimeC = 0.0;


	// Time measurement for assembly function
	clock_t startASM, endASM;

	// Array to store the time measurements
	double* timeASM = (double*)malloc(ITERATIONS * sizeof(double));
	double totalTimeASM = 0.0;
	double averageTimeASM = 0.0;


	// Smallest single precision floating point number
	//float min = (float)- 3.40282347E-38;
	float min = (float)0.0;

	// Largest single precision floating point number
	//float max = (float)3.402823466e+38;
	float max = (float)100.0;

	// Vector sizes = 2^20, 2^24, 2^30
	//int n[] = {1048576, 16777216, 1073741824};
	int vectorN = 1048576;

	// Scalar value
	float scalarA = 0.0;

	// Vector values
	float* x = (float*)malloc(vectorN * sizeof(float));
	float* y = (float*)malloc(vectorN * sizeof(float));
	float* z = (float*)malloc(vectorN * sizeof(float));			// C Z vector	
	float* asmZ = (float*)malloc(vectorN * sizeof(float));		// Assembly Z vector


	// Main process
	if (timeC != NULL && timeASM != NULL) {
		for (int i = 0; i < ITERATIONS; i++) {	// Loop for the number of iterations
			
			scalarA = random_generator(min, max);	// Set a random float number for the scalar value from min to max
			printf("Scalar Value: %f\n", scalarA);

			// Allocate memory for the vectors
			if (x != NULL && y != NULL && z != NULL && asmZ != NULL) {
				
				for (int i = 0; i < vectorN; i++) {	// Set a random float number for the X and Y vectors from min to max
					x[i] = (float)random_generator(min, max);
					y[i] = (float)random_generator(min, max);
				}

				/***** For C *****/
				startC = clock();					// Start time measurement for C function
				saxpyC(vectorN, scalarA, x, y, z);	// Call the C function
				endC = clock();						// End time measurement for C function

				// Calculate the time
				currTimeC = (double)(endC - startC) / CLOCKS_PER_SEC;

				// Print the first 10 values of the Z vectors
				printf("Z Vector: ");
				for (int i = 0; i < 10; i++) {
					printf("%f ", z[i]);
				}

				printf("\n");

				/***** For Assembly *****/
				// TO DO: Implement the Assembly function and measure the time



				// Print the first 10 values of the asmZ vectors
				// TO DO: Uncomment the code below
				//printf("ASM Z Vector: ");
				//for (int i = 0; i < 10; i++) {
				//	printf("%f ", asmZ[i]);
				//}
			}
			else {
				printf("Memory allocation failed.\n");
			}

			
			// Store the time measurement
			timeC[i] = currTimeC;

			// Reset the times
			startC = 0.0;
			endC = 0.0;
			currTimeC = 0.0;
		}
	} else {
		printf("Memory allocation failed.\n");
	}

	// Calculate the average time for the C function
	computeAveTime(timeC, ITERATIONS, &totalTimeC, &averageTimeC);

	print("\n");

	// Calculate the average time for the assembly function
	// TO DO: Call the computeAveTime function for the assembly function

	return 0;
}