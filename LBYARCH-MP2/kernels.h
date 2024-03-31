/*
 * kernels.h
 * - Holds all the function prototypes for the kernels
 *
 */

 // Function prototypes
float random_generator(float min, float max);
float saxpyC(int n, float a, float* x, float* y, float* z);
void computeAveTime(double* time, int iterations, double* totalTime, double* averageTime);