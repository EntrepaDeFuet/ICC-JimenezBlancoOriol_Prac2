#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"Interp.h"

int main(){

    double *x,*y,pz,a,b,z;
    int n;
    n = 999;
    a = primerValor();
    b = segonValor();


    x = (double *)malloc(1000*sizeof(double));
    if(x==NULL){
        printf("Memory allocation failed in main()\n");
        return -1;
    }
    y = (double *)malloc(1000*sizeof(double));
    if(y==NULL){
        printf("Memory allocation failed in main()\n");
        return -1;
        free(x);
    }

    FILE *ftpr;
    ftpr = fopen(primerDocument(),"w");

    if(equidistants(n,a,b,x) == -1){
        printf("No s'ha pogut calcular els punts equidistant del interval [%20.16e,%20.16e]\n",a,b);

    }else{
        for (int i = 0; i < n+1 ; i++){
            y[i] = fun(x[i]);
        }
        for (int j = 0; j <= n; j++){
            if(lagrange_eval(x[j],n,x,y,&pz) == -1){
                printf("Es supera la tolerància en el càlcul de Lagrange dels punts equidistants.\n");
                break;
            } else {
                fprintf(ftpr,"%20.16e %20.16e %20.16e %20.16e\n",x[j],y[j],pz,y[j]-pz);
            }
        }
    }
    fclose(ftpr);
    ftpr = fopen(segonDocument(), "w");


    if(chebsyev(n,a,b,x)== -1){
        printf("No s'ha pogut calcular els punts de Chebsyev del interval [%20.16e,%20.16e]\n",a,b);
        return -1;
    }else{

        for (int i = 0; i < n+1 ; i++){
            y[i] = fun(x[i]);
        }

        for(int j = 0; j <= n; j++){
            if(lagrange_eval(x[j],n,x,y,&pz) == -1){
                printf("Es supera la tolerància en el càlcul de Lagrange dels punts de Chebsyev.\n");
                break;
            } else {
                fprintf(ftpr,"%20.16e %20.16e %20.16e %20.16e\n",x[j],y[j],pz,y[j]-pz);
            }
        }
    }
    free(x);
    free(y);
    return 0;

}