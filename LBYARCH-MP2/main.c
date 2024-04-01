/*
* main.cpp
* - Main program that runs the kernel functions in both C and Assembly language
*
* Date: 29 March 2024
* Version: 1.0
*
* References:
* - Dynamic Array Allocation: https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/
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
extern float saxpyASM(float scalarA, float x, float y);

/***** Main Program *****/
int main(int argc, char* argv[]) {
	srand((unsigned int)time(NULL));
	
	/* Uncomment for choosing modes */
	//char mode = 'R';		// For Release Mode
	char mode = 'D';		// For Debug Mode

	// Time measurement for C
	clock_t startC, endC;
	double timeC[ITERATIONS];
	double currTimeC = 0.0;
	double totalTimeC = 0.0;
	double averageTimeC = 0.0;

	// Time measurement for assembly function
	clock_t startASM, endASM;
	double timeASM[ITERATIONS];
	double currTimeASM = 0.0;
	double totalTimeASM = 0.0;
	double averageTimeASM = 0.0;

	// Single precision floating point number
	//float min = (float)- 3.40282347E-38; 			// Smallest
	float min = 0.0f;
	//float max = (float)3.402823466e+38;			// Largest
	float max = 100.0f;

	// Vector sizes
	int vectorN = 1048576;					// 2^20 - Passed
	//int vectorN = 16777216;					// 2^24 - Passed
	//int vectorN = 134217728;					// 2^27 - Passed

	// Scalar value
	float scalarA = 0.0f;

	// Vector values
	float* x = (float*)malloc(vectorN * sizeof(float));
	float* y = (float*)malloc(vectorN * sizeof(float));
	float* z = (float*)malloc(vectorN * sizeof(float));			// C Z vector
	float* checkZ = (float*)malloc(vectorN * sizeof(float));	// Temporary Z vector for correctness check
	float* asmZ = (float*)malloc(vectorN * sizeof(float));		// Assembly Z vector

	// Temp variables
	float tempX = 0.0f;
	float tempY = 0.0f;
	float tempZ = 0.0f;

	// Check for correctness
	int isCorrectC = 1;
	int isCorrectASM = 1;


	if (x == NULL || y == NULL || z == NULL || asmZ == NULL) {
		printf("Memory allocation failed.\n");
		exit(0);
	} else {

		scalarA = random_float_generator(min, max);		// Set a random float number for the scalar value from min to max

		for (int i = 0; i < vectorN; i++) {				// Set a random float number for the X and Y vectors from min to max
			x[i] = random_float_generator(min, max);
			y[i] = random_float_generator(min, max);
		}
		
		// Main loop
		for (int i = 0; i < ITERATIONS; i++) {				// Loop for the number of iterations
			
			//printf("\nIteration: %d\n", i + 1);

			/**** Store the 1st Iteration Result for Correctness *****/
			if (i == 0) {
				saxpyC(vectorN, scalarA, x, y, checkZ);	// Call the C function for the 1st iteration
			}

			/***** For Assembly *****/
			startASM = clock();							// Start time measurement for Assembly function
			
			for (int i = 0; i < vectorN; i++) {
				asmZ[i] = saxpyASM(scalarA, x[i], y[i]);
			}
			endASM = clock();							// End time measurement for Assembly function

			// Calculate the time
			currTimeASM = ((double)(endASM - startASM)) / CLOCKS_PER_SEC;


			/***** For C *****/
			startC = clock();						// Start time measurement for C function
			saxpyC(vectorN, scalarA, x, y, z);		// Call the C function
			endC = clock();							// End time measurement for C function

			// Calculate the time
			currTimeC = ((double)(endC - startC)) / CLOCKS_PER_SEC;

			/***** Check the correctness of the C function on each iteration *****/
			isCorrectC = checkCorrectness(vectorN, z, checkZ);
			isCorrectASM = checkCorrectness(vectorN, asmZ, checkZ);

			// Check the correctness
			if (isCorrectC == 1) {
				break;
			}
			else {
				if (isCorrectASM == 1) {
					break;
				}
			}

			
			// Store the time measurement
			timeC[i] = currTimeC;
			timeASM[i] = currTimeASM;
		}

		// Display Vector Table
		printf("\n");
		printf("Vector Table Results\n");
		displayTableHeader();
		displayTableBody(checkZ, z, asmZ);
		displayTableFooter();

		printf("\n");

		// Display the mode
		printf("Set Up\n");
		if (mode == 'R') {
			printf("Mode\t\t\t: Release\n");
		} else if (mode == 'D') {
			printf("Mode\t\t\t: Debug\n");
		}

		// Display the n size
		printf("Vector Size\t\t: %d\n", vectorN);

		// Display the scalar value
		printf("Scalar Value\t\t: %f\n", scalarA);

		printf("\n");

		// Display Correctness
		printf("Correctness Result\n");
		// Diplay the correctness of the C function status
		if (isCorrectC == 0) {
			printf("Correctness Check in C\t\t: PASSED\n");
		}
		else {
			printf("Correctness Check in C\t\t: FAILED\n");
		}

		// Diplay the correctness of the Assembly function status
		if (isCorrectASM == 0) {
			printf("Correctness Check in Assembly\t: PASSED\n");
		}
		else {
			printf("Correctness Check in Assembly\t: FAILED\n");
		}

		printf("\n");

		// Display the time measurement
		printf("\nTime Measurement Results\n");

		// Calculate the average time for the C function
		computeAveTime(timeC, ITERATIONS, &totalTimeC, &averageTimeC, 'C');

		// Calculate the average time for the assembly function
		computeAveTime(timeASM, ITERATIONS, &totalTimeASM, &averageTimeASM, 'A');
		printf("\n");

		
		// Free the memory
		free(x);
		free(y);
		free(z);
		free(asmZ);
	}

	return 0;
}