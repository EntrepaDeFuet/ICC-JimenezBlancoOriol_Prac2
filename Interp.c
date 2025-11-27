#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define M_PI 3.14159265358979323846
#include"Interp.h"

int lagrange_eval(double z, int n,double *x,double *y, double *pz){
    double tol,actual;
    tol =pow(10,-12);

    for (int i= 0; i < n+1; i++){
        actual = 1;
        for(int j = 0; j < n+1; j++){

            if(j != i){
                if(fabs(x[i]-x[j]) < tol){
                    return -1;

                }
                actual = actual * (z-x[j]) / (x[i]-x[j]);
            }
        }
        *pz += actual*y[i];
    }
    return 0;
}
int equidistants(int n, double a, double b,double *x){

    if((b-a) < 1e-12){
        return -1;
    } else {
        for (int i = 0; i < n+1; i++){
            x[i] = a + i*((b-a)/n);
        }
    }
    return 0;
}
int chebsyev(int n, double a, double b, double *x){
    if((b-a) < 1e-12){
        return -1;
    } else {
        for(int i = 0; i < n+1 ; i++){
            x[i] = ((a+b)/2) + ((b-a)/2)*cos( ((2*i + 1)*M_PI)/(2*(n+1)) );
        }
    }
}