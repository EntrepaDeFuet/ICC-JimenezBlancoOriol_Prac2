#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"Interp.h"

int lagrange_eval(double z, int n,double *x,double *y, double *pz){

    double tol,actual;
    tol =1e-12;


    for (int i= 0; i < n+1; i++){
        actual = 1;
        for(int j = 0; j < n+1; j++){

            if(j != i){
                if((x[i]-x[j]) < tol)
                

            }
        }
    }

}