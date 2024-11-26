#include <stdio.h>
#include <immintrin.h>

extern void daxpy(int n, double A, double *X, double *Y, double *Z);

int main() {
	//from example, added more to fit 10 elems
    int n = 10;
    double A = 2.0;
    double X[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    double Y[] = {11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0};
    double Z[10] = {0};

    daxpy(n, A, X, Y, Z);

	int i;
    printf("Z: ");
    for (i = 0; i < n; i++) {
        printf("%.1f ", Z[i]);
    }
    return 0;
}

