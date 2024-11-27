#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void daxpy_c(double *X, double *Y, double *Z, int n, double A);
extern void daxpy_sasm(double *X, double *Y, double *Z, int n, double A); // ASM function

void print_summary(double *times_c, double *times_sasm, int *sizes, int num_tests);

int main() {
    int n, i, j;
    double *X, *Y, *Z, *Z_c, A;
    clock_t start, end;
    double total_time_c = 0.0, total_time_sasm = 0.0, avg_time_c, avg_time_sasm;

    // Predefined vector sizes for testing
    int sizes[] = {1 << 20, 1 << 24, 1 << 28};
    int num_tests = sizeof(sizes) / sizeof(sizes[0]);

    // Array to store average times for each kernel
    double times_c[num_tests], times_sasm[num_tests];

    // Hardcode scalar value for A
    A = 2.0;

    printf("DAXPY Program - C and Assembly Kernel Comparison\n");
    printf("------------------------------------------------\n");

    for (int test = 0; test < num_tests; test++) {
        n = sizes[test];
        printf("\nTesting for n = %d\n", n);

        // Allocate memory
        X = (double *)malloc(n * sizeof(double));
        Y = (double *)malloc(n * sizeof(double));
        Z = (double *)malloc(n * sizeof(double));
        Z_c = (double *)malloc(n * sizeof(double));

        if (!X || !Y || !Z || !Z_c) {
            printf("Memory allocation failed.\n");
            free(X);
            free(Y);
            free(Z);
            free(Z_c);
            return -1;
        }

        // Initialize X and Y
        for (i = 0; i < n; i++) {
            X[i] = (double)i;
            Y[i] = (double)(i + 10);
        }

        // Test C implementation
        total_time_c = 0.0;
        for (j = 0; j < 30; j++) {
            start = clock();
            daxpy_c(X, Y, Z_c, n, A);
            end = clock();
            total_time_c += (double)(end - start) / CLOCKS_PER_SEC;
        }
        avg_time_c = total_time_c / 30.0;
        times_c[test] = avg_time_c;
        printf("Average execution time (C Kernel): %.6f seconds\n", avg_time_c);

        // Test Assembly implementation
        total_time_sasm = 0.0;
        for (j = 0; j < 30; j++) {
            start = clock();
            daxpy_sasm(X, Y, Z, n, A);
            end = clock();
            total_time_sasm += (double)(end - start) / CLOCKS_PER_SEC;
        }
        avg_time_sasm = total_time_sasm / 30.0;
        times_sasm[test] = avg_time_sasm;
        printf("Average execution time (SASM Kernel): %.6f seconds\n", avg_time_sasm);

        // Verify correctness
        int correct = 1;
        for (i = 0; i < n; i++) {
            if (Z[i] != Z_c[i]) {
                printf("Mismatch at index %d: SASM Z[%d] = %.2lf, C Z[%d] = %.2lf\n",
                       i, i, Z[i], i, Z_c[i]);
                correct = 0;
                break;
            }
        }

        if (correct) {
            printf("SASM output matches C output for n = %d.\n", n);
        } else {
            printf("SASM output does not match C output for n = %d.\n", n);
        }

        // Clean up
        free(X);
        free(Y);
        free(Z);
        free(Z_c);
    }

    // Print summary of execution times
    print_summary(times_c, times_sasm, sizes, num_tests);

    return 0;
}

// C implementation of DAXPY for verification
void daxpy_c(double *X, double *Y, double *Z, int n, double A) {
    for (int i = 0; i < n; i++) {
        Z[i] = A * X[i] + Y[i];
    }
}

// Print summary table of execution times
void print_summary(double *times_c, double *times_sasm, int *sizes, int num_tests) {
    printf("\nExecution Time Summary:\n");
    printf("---------------------------------------------------\n");
    printf("| Vector Size | Avg Time (C) | Avg Time (SASM) |\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < num_tests; i++) {
        printf("| %10d | %12.6f | %14.6f |\n", sizes[i], times_c[i], times_sasm[i]);
    }
    printf("---------------------------------------------------\n");
}

