/*
 * kernels.h
 * - Holds all the function prototypes for the kernels
 *
 */

 // Pre-defined libraries
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

 // Function prototypes
void displayTableHeader();
void displayTableBody(float* checkZ, float* z, float* asmZ);
void displayTableFooter();
float random_float_generator(float min, float max);
void saxpyC(int n, float a, float* x, float* y, float* z);
void computeAveTime(double* time, int iterations, double* totalTime, double* averageTime, char mode);
int checkCorrectness(int n, float* z, float* checkZ);