#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main(void){

	
	double BC;
	double BA;
	double angleB;

	printf("Enter the side BC : ");
	scanf("%lf",&BC);

	printf("Enter the side AB : ");
	scanf("%lf",&BA);

	printf("Enter the angle B (in degrees) : ");
	scanf("%lf",&angleB);
	const char* filename = "output.txt";

	FILE *file = fopen(filename, "w");
	
	fprintf(file, "%.2f\n", BA);
	fprintf(file, "%.2f\n", BC);
	fprintf(file, "%.2f\n", angleB);
	
	fclose(file);

	printf("Values written to %s\n", filename);

	return 0;



}
