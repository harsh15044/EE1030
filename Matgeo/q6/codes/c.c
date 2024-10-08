#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "libs/matfun.h"
#include "libs/geofun.h"

void vertical_parabola_gen(FILE *fptr, int num_points) {
    // Generate points for x from -3 to 2
    for (int i = 0; i <= num_points; i++) {
        double x = (-3.0 + 5.0 * i / num_points); // Scale x from -3 to 2
        double y = x * x;  // Calculate y = x^2

        // Output the points for the curve
        fprintf(fptr, "%lf,%lf\n", x, y);
    }
}

int main() {
    double x1, y1;
    x1 = -3; y1 = 0;  // Starting point for x at -3
    int m = 2, n = 1;
    double **vertex = createMat(m, n);
    vertex[0][0] = x1;
    vertex[1][0] = y1;

    FILE *fptr;
    fptr = fopen("points.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    vertical_parabola_gen(fptr, 1000);  // Generate 1000 points for smooth curve

    fclose(fptr);
    freeMat(vertex, 2);  // Freeing the dynamically allocated memory
    return 0;
}

