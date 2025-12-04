#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"Interp.h"




int  calcul_coef(int n,double *x,double*y){
    double * a;
     a = (double *) malloc(1000*sizeof(double));
     if(a == NULL){
         printf("Error de memòria a Horner.");
         return -1;
     }
     for (int i = 1; i < n; i++){
         a[i] = y[i];
         for (int j = i+1; j<=n; j++){
             for(int k = 0; k < n; k++){
                 a[i] -= y[j]*x[k];
              }
         }
     }
     a[n]= y[n];
     return 0;

}

int main(){

    double *x,*y,*copiay ,pz,a,b;
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
    copiay = (double*) malloc(1000*sizeof(double));
    if (copiay == NULL){
        free(x);
        free(y);
        printf("Memory allocation failed i main()\n");
    }


    FILE *ftpr;
    ftpr = fopen(primerDocument('n'),"w");

    if(equidistants(n,a,b,x) == -1){
        printf("No s'ha pogut calcular els punts equidistant del interval [%20.16e,%20.16e]\n",a,b);
        return -1;
    }else{
        for (int i = 0; i <= n ; i++){
            y[i] = fun(x[i]);
        }
        for (int i = 0; i <= n ; i++){
            copiay[i] = y[i];
        }
        if (difdiv(n,x,y) == -1){
            printf("S'ha superat la tolerància calculant les diferències dividides\n");
            return -1;
        }
        if(calcul_coef(n,x,y)== -1){
            printf("Error fent el càlcul de coeficients.\n");
            return -1;
        }
        for (int j = 0; j <= n; j++){
            pz =  horner(x[j],n,x,y);
            fprintf(ftpr,"%20.16e %20.16e %20.16e %20.16e\n",x[j],copiay[j],pz,y[j]-pz);
            
        }
    }
    fclose(ftpr);
    ftpr = fopen(segonDocument('n'), "w");


    if(chebsyev(n,a,b,x)== -1){
        printf("No s'ha pogut calcular els punts de Chebsyev del interval [%20.16e,%20.16e]\n",a,b);
        return -1;
    }else{

        for (int i = 0; i <= n ; i++){
            y[i] = fun(x[i]);
        }
        for (int i = 0; i<= n ; i++){
            copiay[i] = y[i];
        }
        if(difdiv(n,x,y)){
                printf("S'ha superat la tolerància calculant les diferències dividides.\n");
        }
        if(calcul_coef(n,x,y) == -1){
            printf("Error fent el càlcul de coeficients.\n");
            return -1;
        }
        for(int j = 0; j <= n; j++){
            pz = horner(x[j],n,x,y);
            fprintf(ftpr,"%20.16e %20.16e %20.16e %20.16e\n",x[j],copiay[j],pz,y[j]-pz);
        }
    }
    free(x);
    free(y);
    free(copiay);
    return 0;

}
