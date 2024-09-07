#include <stdio.h>

int main() {
    // Coordinates of A and B
    int x1 = -4, y1 = 0;  // Coordinates of A
    int x2 = 0, y2 = 6;   // Coordinates of B

    // The ratio AR : RB = 3 : 1 (AR = 3/4 AB)
    int m = 3, n = 1;

    // Coordinates of point R using the section formula
    // R(x, y) = [(m*x2 + n*x1) / (m+n), (m*y2 + n*y1) / (m+n)]
    float xR = (float)(m*x2 + n*x1) / (m+n);
    float yR = (float)(m*y2 + n*y1) / (m+n);

    // Printing the coordinates of points A, B, and R
    printf("(%d, %d)\n", x1, y1);
    printf("(%d, %d)\n", x2, y2);
    printf("(%.2f, %.2f)\n", xR, yR);

    // Writing the coordinates to a file named "output.txt"
    FILE *file = fopen("output", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    fprintf(file, "(%d, %d)\n", x1, y1);
    fprintf(file, "(%d, %d)\n", x2, y2);
    fprintf(file, "(%.2f, %.2f)\n", xR, yR);

    fclose(file);
    printf("Coordinates have been saved to output.txt\n");

    return 0;
}

