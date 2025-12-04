#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define M_PI 3.14159265358979323846
#include"Interp.h"

int lagrange_eval(double z, int n,double *x,double *y, double *pz){
    double tol,actual;
    tol = 1.e-12;
    *pz = 0;
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
    return 0;
}
double horner(double z, int n, double *x, double *c){
    double sum = c[n];
    double *a;
    a = (double *) malloc(n*sizeof(double));
    if(a == NULL){
        printf("Error de memòria a Horner.");
        return -1;
    }
    for (int i = 1; i < n+1; i++){
        a[i] = c[i];
        for (int j = i+1; j<n+1; j++){
            for(int k = 0; k < n; k++){
                a[i] -= c[j]*x[k];
            }
        }
    }
    for (int i = n-1; i <= 0; i--){
        sum = sum*z + a[i];
    }
    free(a);
    return sum;
}
int difdiv(int n, double *x, double *y){

	double **a = (double**) malloc ((n+1)*sizeof(double*));
	if (a == NULL){
		return -1;
	}
	for(int i = 0; i < n+1; i++){

		a[i] = (double *) malloc((n+1)*sizeof(double));

		if (a[i] == NULL){
			return-1;
		}
	}
	for (int i =0 ; i<= n ; i++){

		for (int j =0;j<=i;j++){
			if(j == 0){
				a[i][j] = y[i];
			} else {
				a[i][j] = (a[i][j-1]-a[i-1][j-1])/(x[i]-x[i-j]);
			}

		}
	}
	for (int i =0; i<=n; i++){
		y[i]=a[i][i];
	}	

	return 0;
}
