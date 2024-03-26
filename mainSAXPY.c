/*
 * References:
 * 
 * - Dynamic Array
 * https://www.geeksforgeeks.org/dynamic-array-in-c/
*/

#include <stdio.h>
#include <stdlib.h>


// Function Prototype
// void saxpy(int n, float a, float x[], float y[]);


int main() {
    // Variables
    // For size of the array
    char size[100];             // For validating the size of the array
    int n;                      // Size of the array
    int validN = 0;             // Flag for valid input

    // For dynamic array
    int* ptr;                   // Pointer to the array
    
    // For scalar value
    char scalar[100];           // For validating the scalar value
    float a;                    // Scalar value
    int validA = 0;             // Flag for valid input

    

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

            printf("Scalar: %s\n", scalar);

            // Check if the input is a number
            for (int j = 0; scalar[j] != '\0'; j++) {
                printf("Scalar: %c\n", scalar[j]);


                if (j == 0) {
                    if (scalar[j] == '-') {
                        printf("Val (with negative): %d\n", validA);
                    } else if (scalar[j] <= '0' || scalar[j] >= '9') {
                        printf("Val (not with negative): %d\n", validA);
                        break;
                    }
                } else {
                    if (scalar[j] == '.') {
                        validA += 1;
                        printf("Val (with dot): %d\n", validA);
                    } else if (scalar[j] != '.' && (scalar[j] < '0' || scalar[j] > '9')) {
                        printf("Val (not with negative): %d\n", validA);
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