#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "libs/matfun.h"
#include "libs/geofun.h"

/*
void horizontal_parabola_gen(FILE *fptr, double a, int num_points, double **vertex) {
    // Generate points for x from 0 to 11
    for (int i = 0; i <= num_points; i++) {
        double x = (11.0 * i) / num_points; // Scale x from 0 to 11
        double **output = createMat(2, 1);
        
        // Calculate y using the equation y^2 = 9x -> y = ±sqrt(9x)
        output[0][0] = x;                      // x value
        output[1][0] = vertex[1][0] + sqrt(9 * x); // Positive y value
        fprintf(fptr, "%lf,%lf\n", output[0][0], output[1][0]);
        
        output[1][0] = vertex[1][0] - sqrt(9 * x); // Negative y value
        fprintf(fptr, "%lf,%lf\n", output[0][0], output[1][0]);
        
        freeMat(output, 2);
    }
}


void horizontal_parabola_gen(FILE *fptr, double a, int num_points, double **vertex) {
    // Generate points for x from 0 to 11
    for (int i = 0; i <= num_points; i++) {
        double x = (11.0 * i) / num_points; // Scale x from 0 to 11
        double **output = createMat(2, 1);
        
        // Calculate y using the equation y^2 = 9x -> y = ±sqrt(9x)
        output[0][0] = x;                      // x value
        output[1][0] = vertex[1][0] + sqrt(9 * x); // Positive y value
        fprintf(fptr, "%lf,%lf\n", output[0][0], output[1][0]);
        
        output[1][0] = vertex[1][0] - sqrt(9 * x); // Negative y value
        fprintf(fptr, "%lf,%lf\n", output[0][0], output[1][0]);
        
        freeMat(output, 2);
    }
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void horizontal_parabola_gen(FILE *fptr, double num_points) {
    for (int i = 0; i <= num_points; i++) {
        double x = (11.0 * i) / num_points; // Scale x from 0 to 11
        double y_pos = sqrt(9 * x); // Positive y value
        double y_neg = -sqrt(9 * x); // Negative y value

        // Output the points for the upper and lower curves
        fprintf(fptr, "%lf,%lf\n", x, y_pos); // Upper
        fprintf(fptr, "%lf,%lf\n", x, y_neg); // Lower
    }
}


int main() {
    double x1, y1;
    x1 = 0; y1 = 0;  // Vertex of the parabola at the origin
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

    double a = 9.0;  // For y^2 = 9x, we have 4a = 9, thus a = 9/4
    //horizontal_parabola_gen(fptr, a, 1000, vertex);
	horizontal_parabola_gen(fptr, 1000);

    fclose(fptr);
    freeMat(vertex, 2);  // Freeing the dynamically allocated memory
    return 0;
}

