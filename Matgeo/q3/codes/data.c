#include <stdio.h>
#include "libs/matfun.h"
#include "libs/geofun.h"
#include <math.h>

int main(void) {
	double angle = (30 * M_PI)/180;

	double x = cos(angle);
	double y = sin(angle);

	//saving to the files

	FILE *file = fopen("output", "w");

	fprintf(file, "(%.2lf,%.2lf)\n", x, y);

	fclose(file);

	
	printf("Coordinates have been saved to output.txt\n");
	return 0;

}

