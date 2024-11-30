#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>

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
    A = 2.0; //change
    n = sizes[0];

	//initialize X,Y,Z
    X = (double *)malloc(n * sizeof(double));
    Y = (double *)malloc(n * sizeof(double));
    Z = (double *)malloc(n * sizeof(double));
    for (i = 0; i < n; i++) {
        X[i] = (double)(i+1);
        Y[i] = (double)(i + 11);
    }

    daxpy(n, A, X, Y, Z);

	//Print out 1st 10 elems of all vectors
	printf("\nA: %.1lf", A);
    printf("\nX: ");
    for (i = 0; i < 10; i++) {
        printf("%10.1lf ", X[i]);
    }
    printf("\nY: ");
    for (i = 0; i < 10; i++) {
        printf("%10.1lf ", Y[i]);
    }
    printf("\nCompute DAXPY (A*X+Y):");
    printf("\nZ:");
    for (i = 0; i < 10; i++) {
        printf("%10.1lf ", Z[i]);
    }
    
    daxpy_C(n, A, X, Y, Z);
    printf("\nDAXPY using SIMD instructions in C:");
    printf("\nZ:");
    for (i = 0; i < 10; i++) {
        printf("%10.1lf ", Z[i]);
    }
    
    return 0;
}

