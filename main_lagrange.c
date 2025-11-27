#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"Interp.h"

int main(){

    double *x,*y,pz,a,b,z;
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
    printf("Introdueix el valor a evaluar.\n");
    scanf("%20.16e", z);

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
    if(equidistants(n,a,b,x) == -1){
        printf("No s'ha pogut calcular els punts equidistant del interval [%20.16e,%20.16e]\n",a,b);

    }else{

        printf("Donades les dades amb punts equidistants:\n|| x || f(x) ||\n");
        for (int i = 0; i < n+1 ; i++){
            printf(" ______________\n");
            y[i] = fun(x[i]);
            printf(" || %20.16e || %20.16e ||\n",x[i],y[i]);
        }
        if(lagrange_eval(z,n,x,y,&pz) == -1){
            printf("Es supera la tolerància en el càlcul de Lagrange dels punts equidistants.\n");
        } else {
            printf("El resultat P(z) = %20.16e \n", pz);
        }

    }
    if(chebsyev(n,a,b,x)== -1){
        printf("No s'ha pogut calcular els punts de Chebsyev del interval [%20.16e,%20.16e]\n",a,b);
        free(x);
        free(y);
        return 1;
    }else{
        printf("Donades les dades amb punts de Chebsyev:\n|| x || f(x) ||\n");
        for (int i = 0; i < n+1 ; i++){
            printf(" ______________\n");
            y[i] = fun(x[i]);
            printf(" || %20.16e || %20.16e ||\n",x[i],y[i]);
        }
        if(lagrange_eval(z,n,x,y,&pz) == -1){
            printf("Es supera la tolerància en el càlcul de Lagrange dels punts de Chebsyev.\n");
            free(x);
            free(y);
            return 1;
        } else {
            printf("El resultat P(z) = %20.16e \n", pz);
        }
    }
    free(x);
    free(y);


}