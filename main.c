#include <stdio.h>
#include <immintrin.h>

void daxpy(int n, double A, double* X, double* Y, double* Z) {
    
    //__m256d - double, 256-bit
    __m256d vectorA = _mm256_set1_pd(A); // set A to all vector elements
    int i;
    for (i = 0; i < n; i += 4) { //4 elements
        __m256d vectorX = _mm256_loadu_pd(&X[i]);
        __m256d vectorY = _mm256_loadu_pd(&Y[i]);
        // (A*X) + Y
        __m256d vectorZ = _mm256_add_pd(_mm256_mul_pd(vectorA, vectorX), vectorY);

        _mm256_storeu_pd(&Z[i], vectorZ);
    }
}

int main() {
	//from example
    int n = 3, i;
    double A = 2.0;
    double X[3] = {1.0, 2.0, 3.0};
    double Y[3] = {11.0, 12.0, 13.0};
    double Z[3];

    daxpy(n, A, X, Y, Z);

    printf("Z: ");
    for (i = 0; i < n; i++) {
        printf("%.1f ", Z[i]);
    }

    return 0;
}

