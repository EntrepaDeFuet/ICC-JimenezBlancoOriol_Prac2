#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"Interp.h"

int main(){

    double *x,*y,*pz,a,b,*z;
    int n;

    printf("Introdueix el grau del polinomi: \n");
    scanf("%d",n);
    printf("Introdueix la cota inferior del interval: \n");
    scanf("%20.14e",a);
    printf("Introdueix la cota superior del interval: \n");
    scanf("%20.14e",b);
    if(a > b){
        printf("El valor de la cota inferior no pot ser superior al de la cota superior. \n");
        double aux;
        aux = b;
        b = a;
        a = aux;
    }

    x = (double *)malloc((n+1)*sizeof(double));
    if(x==NULL){
        printf("Memory allocation failed in main()\n");
        return -1;
    }
    y = (double *)malloc((n+1)*sizeof(double));
    if(y==NULL){
        printf("Memory allocation failed in main()\n");
        return -1;
        free(x);
    }



}