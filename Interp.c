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
    for (int i = n-1; i >= 0; i--){
        sum = sum*(z-x[i]) + c[i];
    }
    
    return sum;
}
int difdiv(int n, double *x, double *y){
    double tol = 1.e-12;
    /*
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
                if (fabs(x[i]-x[i-j])< tol){
                    return -1;
                }
				a[i][j] = (a[i][j-1]-a[i-1][j-1])/(x[i]-x[i-j]);
			}

		}
	}
	for (int i =0; i<=n; i++){
		y[i]=a[i][i];
	}*/
    for (int i = 1; i<= n;i++){
        for(int j = 0; j<n-i+1;j++){
            y[n-j] = (y[n-j] - y[n-j-1])/(x[n-j] - x[n-i]);
        }
    }


	return 0;
}
double trap_full(int n, double a, double b){
    double res,h;
    h = (b-a)/n;
    res = 0;
    for (int i = 1; i<n; i++){
        res += fun(a+i*h);
    }
    res += (fun(a)/2) + (fun(b)/2);
    res = res*h;

    return res;
}
double trap_refined(double Tn, int n, double a, double b){
    double res;
    res = 0;
    res =((3*integral()) -Tn)/4;



    return res;
}
