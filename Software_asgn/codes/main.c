//Code by AI24BTECH11015 - Harshvardhan Patidar
//implements QR Algorithm to find eigenvalues
//uses householders transformations for decomposition of Matrix
#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <stdlib.h>
#define TOLERANCE 1e-15


typedef struct{
    int size;
    long double complex ** data;
} Matrix;


Matrix createMat(int size){
    Matrix matrix;
    matrix.size = size;
    matrix.data = malloc(size * sizeof(long double complex *));
    for(int i=0; i<size; i++){
        matrix.data[i] = malloc(size * sizeof(long double complex));
    }
    return matrix;
}

void freeMat(Matrix *matrix){
    for(int i=0; i<matrix->size; i++){
        free(matrix->data[i]);
    }

    free(matrix->data);
    matrix->data = NULL;
}

int checkComplex(Matrix * matrix){ // function to check if the matrix has any complex entries currently
    int isComplex = 0;
    int n = matrix->size;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(fabsl(cimagl(matrix->data[i][j])) > TOLERANCE){
                isComplex = 1;
                break;
            }
        }
        if(isComplex) break;
    }

    return isComplex;
}

void printMat(Matrix * matrix){
    int isComplex = checkComplex(matrix);
    if(isComplex){ //print in a complex fashion if the entries are complex
        for(int i=0; i<matrix->size; i++){
            for(int j=0; j<matrix->size; j++){
                printf("(%10.3Lf + %10.3Lfi) ", creall(matrix->data[i][j]), cimagl(matrix->data[i][j]));
            }
            printf("\n");
        }
    }
    else{
        for(int i=0; i< matrix->size; i++){
            for(int j=0; j<matrix->size; j++){
                printf("%10.3Lf ", creall(matrix->data[i][j]));
            }
            printf("\n");
        }
    }
}

void scanMat(Matrix * matrix, int isComplex){
    if(isComplex){
        printf("Enter the contents of matrix. Separate the real and complex entries by a space:\n");
        for(int i=0; i<matrix->size; i++){
            for(int j=0; j<matrix->size; j++){
                long double temp, temp2;
                printf("Element a{%d,%d}: ", i+1, j+1);
                scanf("%Lf%Lf", &temp, &temp2);
                matrix->data[i][j] = temp + temp2*I;
            }
        }
    }
    else{
        printf("Enter the contents of matrix:\n");
        for(int i=0; i<matrix->size; i++){
            for(int j=0; j<matrix->size; j++){
                long double temp;
                printf("Element a{%d,%d}: ", i+1, j+1);
                scanf("%Lf", &temp);
                matrix->data[i][j] = temp + 0*I;
            }
        }
    }

    printMat(matrix);
    printf("The Matrix has been succesfully initialized.\n");
}

//function to calculate the norm of vector v
//norm = v * v^H 
long double normCalculate(long double complex *v, int size){
    long double norm = 0;

    for(int i=0; i<size; i++){
        norm += cabsl(v[i]) * cabsl(v[i]);
    }
    return sqrtl(norm);
}

//calculates the householder vector to generate the householder MAtrix (H)
void householderVector(long double complex * x, int size, long double complex *v, int k){
    long double norm = normCalculate(x,size);

    for(int i=0; i<size; i++){
        v[i] = x[i];
    }

    if(creall(v[k])>0){
        v[k] += norm;
    }
    else{
        v[k] -= norm;
    }

    long double vNorm = normCalculate(v,size);
    if(fabsl(vNorm) < TOLERANCE){
        for(int i=0; i<size; i++){
            v[i] = 0;
        }//check
    }
    else{ //making norm of the vector =1
        for(int i=0; i<size; i++){
            v[i] = v[i]/vNorm;
        }
    }
    return;
}

//calculates H = I - 2*v*v^H
// R<- H*R
// Q<- Q*H^H
void householderApplication(Matrix * Q, Matrix * R, int k, long double complex *v){
    int n = R->size;

    Matrix H = createMat(n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                H.data[i][j] = 1.0 - 2.0 * v[i] * conjl(v[j]);
            }
            else{
                H.data[i][j] = - 2.0 * v[i] * conjl(v[j]);
            }
        }
    }


    //R = H*R    
    Matrix HA = createMat(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            HA.data[i][j] = 0;
            for(int t=0; t<n; t++){
                HA.data[i][j] += H.data[i][t] * (R->data[t][j]);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            R->data[i][j] = HA.data[i][j];
        }
    }
    freeMat(&HA);


    //Q = Q * H^H
    Matrix HB = createMat(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            HB.data[i][j] = 0;
            for(int t=0; t<n; t++){
                HB.data[i][j] += Q->data[i][t] * conjl(H.data[j][t]);
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            Q->data[i][j] = HB.data[i][j];
        }
    }

    freeMat(&H);
    freeMat(&HB);
}

void qrAlgorithm(Matrix * A){
    int n=A->size;
    Matrix R = createMat(n);
    Matrix Q = createMat(n);

    //starting with R = A and Q = I
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            R.data[i][j] = A->data[i][j];
            if(i==j){
                Q.data[i][j]= 1 + 0*I;
            }
            else{
                Q.data[i][j] = 0 + 0*I;
            } 
        }
    }

    //decomposing by iterating over all columns (except the last one )
    for(int k=0; k<n-1; k++){
        long double complex *x = malloc((n) * sizeof(long double complex));
        long double complex *v = malloc((n) * sizeof(long double complex));

        for(int i=0; i<n; i++){ //copying the required elements of kth column of matrix to x
            if(i<k){
                x[i] = 0;
            }
            else{
                x[i] = R.data[i][k];
            }
        }

        householderVector(x,n,v, k); //calculating v
        householderApplication(&Q, &R, k, v); //updating R and Q 

        free(x);
        free(v);
    }

    //for every iteration A <- R*Q
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            A->data[i][j] = 0;
            for(int t=0; t<n; t++){
                A->data[i][j] += R.data[i][t] * Q.data[t][j];
            }
        }
    }

}

void printEigenValues(Matrix *A) {
    int isComplex = checkComplex(A);
    printf("\nEigenvalues:\n");
    
    if(!isComplex){//all values are real => either real eigenvalues or conjugates
        for (int i = 0; i < A->size; i++) {
            if (i < A->size - 1 && cabsl(A->data[i][i + 1]) > TOLERANCE) {//2x2 block exists
                
                long double a = creall(A->data[i][i]);
                long double b = creall(A->data[i][i + 1]);
                long double c = creall(A->data[i + 1][i]);
                long double d = creall(A->data[i + 1][i + 1]);

                long double trace = a+d;
                long double det = a*d -b*c;
                long double D = powl(trace,2) - 4*det;

                if(D>= 0){//real solutions
                    printf("Eigenvalue %d: %10.5Lf\n", i + 1, (trace + sqrtl(D))/2 );
                    printf("Eigenvalue %d: %10.5Lf\n", i + 2, (trace - sqrtl(D))/2);
                }
                else{//comple values
                    long double real = trace / 2;
                    long double img = sqrtl(-D) / 2;

                    printf("Eigenvalue %d: %10.5Lf + %10.5Lfi\n", i + 1, real, img);
                    printf("Eigenvalue %d: %10.5Lf - %10.5Lfi\n", i + 2, real, img);
                }

                i++; //skipping next value of i (to go to next block)
            }
            else{ // only 1 entry left (n = odd)
                printf("Eigenvalue %d: %10.5Lf\n", i + 1, creall(A->data[i][i])); //needs to be real;
            }
        }
    }
    else{
        for(int i=0; i<A->size; i++){
            printf("Eigenvalue %d: %10.5Lf + %10.5Lfi\n", i+1, creall(A->data[i][i]), cimagl( A->data[i][i]));
        }
    }
}

//to check if matrix has converged or not
int isConverged(Matrix *A) {
    int n= A->size;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n ; j++) {
            if (i != j && i>j) {//checking lower triangle values (except diagonal valeus)
                if (cabsl(A->data[i][j]) > TOLERANCE) {
                    return 0;
                }
            }
        }
    }
    return 1;
}


int main(void){
    int size, isComplex;
    printf("Enter the size of the Matrix: ");
    scanf("%d", &size);
    printf("\nIf your entries are complex, please enter 1, else press 0: ");
    scanf("%d", &isComplex);

    if(isComplex!=1 && isComplex !=0){
        printf("\nNot a valid input. Assuming Real entries.\n");
        isComplex = 0;
    }

    Matrix A = createMat(size);
    scanMat(&A, isComplex);

    int max_iterations = 10000;

    for(int i=0; i<max_iterations; i++){//applying iteratively (not more than max_iterations times)
        qrAlgorithm(&A);
        if(isConverged(&A)) break;
    }

    printEigenValues(&A);

}
