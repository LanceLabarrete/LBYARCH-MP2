/*
 * References:
 * 
 * - Dynamic Array
 * https://www.geeksforgeeks.org/dynamic-array-in-c/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Function Prototype
// void saxpy(int n, float a, float x[], float y[]);


int main() {
    // Variables
    // For size of the array
    char size[100];             // For validating the size of the array
    int n;                      // Size of the array
    int validN = 0;             // Flag for valid input
    
    // For scalar value
    char scalar[100];           // For validating the scalar value
    float a;                    // Scalar value
    int validA = 0;             // Flag for valid input

    // For dynamic array
    float* ptrX;                  // Pointer to the array
    float* ptrY;                  // Pointer to the array
    float* ptrZ;                  // Pointer to the array

    // Temporary variables
    char tempX[100];            // Temporary variable for validating the input
    int validX = 0;             // Flag for valid input
    char tempY[100];            // Temporary variable for validating the input
    int validY = 0;             // Flag for valid input

    

    // Ask the user for the size of the array
    do {
        printf("Enter the size of the array: ");
        scanf("%s", &size);

        // Check if the input is a number
        for (int i = 0; size[i] != '\0'; i++) {
            if (size[i] < '0' || size[i] > '9') {
                validN = 0;
                printf("Invalid input. Please enter a valid integer.\n");
                printf("\n");
                break;
            } else {
                n = atoi(size);
                validN = 1;
            }
        }
    } while (validN != 1);

    printf("Size of the array: %d\n", n);
    printf("\n");

    // Check if scalar value is valid
    if (validN == 1) {
        do {
            printf("Enter the scalar value: ");
            scanf("%s", &scalar);

            // Check if the input is a number
            for (int j = 0; scalar[j] != '\0'; j++) {


                if (j == 0) {
                    if (scalar[j] != '-' && (scalar[j] <= '0' || scalar[j] >= '9')) {
                        break;
                    }
                } else {
                    if (scalar[j] == '.') {
                        validA += 1;
                    } else if (scalar[j] != '.' && (scalar[j] < '0' || scalar[j] > '9')) {
                        break;
                    }
                }
            }

            if (validA == 1) {
                a = atof(scalar);
                printf("Scalar value: %.2f\n", a);
                printf("\n");
            } else {
                validA = 0;
                printf("Invalid input. Please enter a valid float value.\n");
                printf("\n");
            }
        } while (validA != 1);

        // Allocate memory for the array X
        ptrX = (float*)malloc(n * sizeof(float));

        // Allocate memory for the array Y
        ptrY = (float*)malloc(n * sizeof(float));

        // Allocate memory for the array Z
        ptrZ = (float*)malloc(n * sizeof(float));

        // Check if memory allocation is successful
        if (ptrX == NULL || ptrY == NULL || ptrZ == NULL) {
            printf("Memory allocation failed.\n");
            exit(0);
        } else {
            printf("Memory allocation successful.\n");
            printf("\n");

            // Ask the user for the values of the array X
            printf("Enter the values of the array X:\n");
            for (int k = 0; k < n; k++) {

                do {
                    printf("X[%d]: ", k);
                    scanf("%s", &tempX);
                    // check if the input is a valid floating point number
                    // either positive or negative
                    for (int l = 0; tempX[l] != '\0'; l++) {
                        if (l == 0) {
                            if (tempX[l] != '-' && (tempX[l] < '0' || tempX[l] > '9')) {
                                validX = 0;
                                break;
                            }
                        } else {
                            if (tempX[l] == '.') {
                                validX += 1;
                            } else if (tempX[l] != '.' && (tempX[l] < '0' || tempX[l] > '9')) {
                                validX = 0;
                                break;
                            }
                        }
                    }

                    if (validX == 1) {
                        // Convert the string to float and store it in the array
                        ptrX[k] = atof(tempX);

                        // Display the value of the array
                        //printf("X[%d]: %.2f\n", k, ptrX[k]);
                    } else {
                        validX = 0;
                        printf("Invalid input. Please enter a valid float value.\n");
                        printf("\n");
                    }
                } while (validX != 1);

                // Reset the flag
                validX = 0;

                // Reset the temporary variable
                memset(tempX, 0, sizeof(tempX));
            }

            // Ask the user for the values of the array Y
            printf("Enter the values of the array Y:\n");
            for (int m = 0; m < n; m++) {
                do {
                    printf("Y[%d]: ", m);
                    scanf("%s", &tempY);
                    // check if the input is a valid floating point number
                    // either positive or negative
                    for (int n = 0; tempY[n] != '\0'; n++) {
                        if (n == 0) {
                            if (tempY[n] != '-' && (tempY[n] < '0' || tempY[n] > '9')) {
                                validY = 0;
                                break;
                            }
                        } else {
                            if (tempY[n] == '.') {
                                validY += 1;
                            } else if (tempY[n] != '.' && (tempY[n] < '0' || tempY[n] > '9')) {
                                validY = 0;
                                break;
                            }
                        }
                    }

                    if (validY == 1) {
                        // Convert the string to float and store it in the array
                        ptrY[m] = atof(tempY);

                        // Display the value of the array
                        //printf("Y[%d]: %.2f\n", m, ptrY[m]);
                    } else {
                        validY = 0;
                        printf("Invalid input. Please enter a valid float value.\n");
                        printf("\n");
                    }
                } while (validY != 1);

                // Reset the flag
                validY = 0;

                // Reset the temporary variable
                memset(tempY, 0, sizeof(tempY));
            }
        }

        // Perform the SAXPY operation
        for (int i = 0; i < n; i++) {
            ptrZ[i] = a * ptrX[i] + ptrY[i];
        }

        // Display the result
        printf("Result of the SAXPY operation:\n");
        for (int i = 0; i < n; i++) {
            printf("Z[%d]: %.2f\n", i, ptrZ[i]);
        }
    }
    
    return 0;
}


// Function to perform SAXPY operation
// void saxpy(int n, float a, float x[], float y[]) {
//     float z[n];
    
//     for (int i = 0; i < n; i++) {
//         z[i] = a * x[i] + y[i];
//     }
// }