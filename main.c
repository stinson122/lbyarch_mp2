#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>
#include <time.h>

//asm function
extern void daxpy(int n, double A, double *X, double *Y, double *Z);

//C with SIMD instuctions
void daxpy_C(int n, double A, double* X, double* Y, double* Z) {
    
    //__m256d - double, 256-bit
    __m256d vectorA = _mm256_set1_pd(A); // set A to all vector elements
    int i;
    for (i = 0; i < n; i += 4) { //4 offset
        __m256d vectorX = _mm256_loadu_pd(&X[i]);
        __m256d vectorY = _mm256_loadu_pd(&Y[i]);
        // (A*X) + Y
        __m256d vectorZ = _mm256_add_pd(_mm256_mul_pd(vectorA, vectorX), vectorY);

        _mm256_storeu_pd(&Z[i], vectorZ);
    }
}

int main() {
    int n, i;
    int sizes[] = {1 << 20};
    double A, *X, *Y, *Z;
    clock_t start_time, end_time;
    double cpu_time_used;

    char choice;
    printf("Choose a vector size to test:\n");
    printf("A) 2^20\n");
    printf("B) 2^24\n");
    printf("C) 2^29\n");
    printf("Enter your choice (A/B/C): ");
    scanf(" %c", &choice);

    switch (choice) {
        case 'A': n = sizes[0]; break;
        case 'B': n = sizes[1]; break;
        case 'C': n = sizes[2]; break;
        default:
            printf("Invalid choice. Defaulting to 2^20.\n");
            n = sizes[0]; 
            break;
    }

    A = 2.0; //change later

	//initialize X,Y,Z
    X = (double *)malloc(n * sizeof(double));
    Y = (double *)malloc(n * sizeof(double));
    Z = (double *)malloc(n * sizeof(double));
    for (i = 0; i < n; i++) {
        X[i] = (double)(i+1);
        Y[i] = (double)(i + 11);
    }

    start_time = clock();
    daxpy(n, A, X, Y, Z);
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nExecution time for DAXPY (ASM): %.6lf seconds\n", cpu_time_used);

	//Print out 1st 10 elems of all vectors
	printf("\nA: %.1lf", A);
    printf("\nX: ");
    for (i = 0; i < 10; i++) {
        printf("%10.2lf ", X[i]);
    }
    printf("\n");
    
    printf("\nY: ");
    for (i = 0; i < 10; i++) {
        printf("%10.2lf ", Y[i]);
    }
    printf("\n");

    printf("\nCompute DAXPY (A*X+Y):");
    printf("\nZ:");
    for (i = 0; i < 10; i++) {
        printf("%10.2lf ", Z[i]);
    }
    printf("\n\n");
    
    start_time = clock();
    daxpy_C(n, A, X, Y, Z);
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Execution time for DAXPY using SIMD in C: %.6lf seconds\n", cpu_time_used);
    
    printf("\nDAXPY using SIMD instructions in C:");
    printf("\nZ:");
    for (i = 0; i < 10; i++) {
        printf("%10.1lf ", Z[i]);
    }
    printf("\n");

    //Free memory back to system
    free(X);
    free(Y);
    free(Z);
    
    return 0;
}

