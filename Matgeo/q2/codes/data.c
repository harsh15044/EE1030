#include <stdio.h>
#include <math.h>


//defining a new data type which will simplify my code
typedef struct {
    double x;
    double y;
} point;

double distance(point p1, point p2){
    double a = sqrt(pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2));
    return a;
} 



point findPoint(point p1, point p2) {
    point third;


    double midx = (p1.x + p2.x)/2;
    double midy = (p1.y + p2.y)/2;

    third.y = midy;
    third.x = 2*third.y;

    //now to ensure the midpoint condition, i will slowly go through the line x=2y and look for a point which satisfies my condition with a satisficatory tolerance
    while (fabs(distance(p1,third)-distance(p2,third)) >0.0001){
        third.y += 0.01;
        third.x = 2*third.y;
    }

    return third;

}



int main(void) {
    //points
    point q = {2,-5};
    point r = {-3,6};

    point third = findPoint(q,r);


    //print the points once to ensure correct or not
    printf("Point Q is (%.2f,%.2f)\n", q.x , q.y);
    printf("Point R is (%.2f,%.2f)\n", r.x , r.y );
    printf("The required point P is (%.2f,%.2f)\n", third.x , third.y);


    //now we have the points, we will now write them in the file

    FILE *file = fopen("output", "w");

    fprintf(file, "(%.2f,%.2f)\n", q.x,q.y);
    fprintf(file, "(%.2f,%.2f)\n", r.x,r.y);
    fprintf(file, "(%.2f,%.2f)\n", third.x,third.y);

    fclose(file);
    
    //final message which confirms that the points are successfully outputted to the required file
    printf("Coordinates have been saved to output.txt\n");

    return 0;

}
