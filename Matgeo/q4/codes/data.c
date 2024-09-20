#include <stdio.h>

int main(void){

	
	double altitude1 = 5;
	double altitude2 = 12;

	const char* filename = "output.txt";

	FILE *file = fopen(filename, "w");
	
	fprintf(file, "%.2f\n", altitude1);
	fprintf(file, "%.2f\n", altitude2);
	
	fclose(file);

	printf("Altitudes written to %s\n", filename);

	return 0;



}
