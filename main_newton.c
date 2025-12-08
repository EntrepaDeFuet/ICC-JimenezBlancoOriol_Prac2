#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"Interp.h"




int  calcul_coef(int n,double *x,double*y){
    double * a;
    int nodes = n+1;
     a = (double *) malloc(nodes*sizeof(double));
     if(a == NULL){
         printf("Error de memòria a Horner.");
         return -1;
     }
     for (int i = 0; i < n; i++){
         a[i] = y[i];
         for (int j = i+1; j<=n; j++){
             for(int k = 0; k < n; k++){
                 a[i] -= y[j]*x[k];
              }
         }
     }
     a[n]= y[n];
     for (int i = 0; i<nodes ; i++){
         y[i]=a[i];
     }
     return 0;

}

int main(){

    double *x,*y,*copiay,*z ,pz,a,b,actual;
    int n,nodes;
    printf("Siusplau introdueix el número de nodes a avaluar: \n");
    scanf("%d",&n);
    nodes = n+1;
    a = primerValor();
    b = segonValor();

    
    x = (double *)malloc(nodes*sizeof(double));
    if(x==NULL){
        printf("Memory allocation failed in main()\n");
        return -1;
    }
    y = (double *)malloc(nodes*sizeof(double));
    if(y==NULL){
        printf("Memory allocation failed in main()\n");
        return -1;
        free(x);
    }
    copiay = (double*) malloc(nodes*sizeof(double));
    if (copiay == NULL){
        free(x);
        free(y);
        printf("Memory allocation failed i main()\n");
    }
    z = (double*) malloc (1000*sizeof(double));
    if(z == NULL){
        printf("Memory allocation failed in main()\n");
        free(x);
        free(y);
        free(copiay);
        return -1;
    }
    if (equidistants(999,a,b,z) == -1){
        printf("Error calculant els punts equidistants al main()\n");
        free(x);
        free(y);
        free(copiay);
        free(z);
        return -1;
    }

    FILE *ftpr;
    ftpr = fopen(primerDocument('n'),"w");

    if(equidistants(n,a,b,x) == -1){
        printf("No s'ha pogut calcular els punts equidistant del interval [%20.16e,%20.16e]\n",a,b);
        fclose(ftpr);
        free(x);
        free(y);
        free(z);
        free(copiay);
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
            fclose(ftpr);
            free(x);
            free(y);
            free(z);
            free(copiay);
            return -1;
        }
        if(calcul_coef(n,x,y)== -1){
            printf("Error fent el càlcul de coeficients.\n");
            fclose(ftpr);
            free(x);
            free(y);
            free(z);
            free(copiay);
            return -1;
        }
        for (int j = 0; j < 1000; j++){
            pz =  horner(z[j],n,x,y);
            actual = fun(z[j]);
            fprintf(ftpr,"%20.16e %20.16e %20.16e %20.16e\n",z[j],actual,pz,actual-pz);
            
        }
    }
    fclose(ftpr);
    ftpr = fopen(segonDocument('n'), "w");


    if(chebsyev(n,a,b,x)== -1){
        printf("No s'ha pogut calcular els punts de Chebsyev del interval [%20.16e,%20.16e]\n",a,b);
        free(x);
        free(y);
        free(z);
        free(copiay);
        fclose(ftpr);
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
                free(x);
                free(y);
                free(copiay);
                free(z);
                fclose(ftpr);
                return -1;
        }
        if(calcul_coef(n,x,y) == -1){
            printf("Error fent el càlcul de coeficients.\n");
            free(x);
            free(y);
            free(copiay);
            free(z);
            fclose(ftpr);
            return -1;
        }
        for(int j = 0; j <1000; j++){
            pz = horner(z[j],n,x,y);
            actual = fun(z[j]);
            fprintf(ftpr,"%20.16e %20.16e %20.16e %20.16e\n",z[j],actual,pz,actual-pz);
        }
    }
    free(x);
    free(y);
    free(copiay);
    free(z);
    fclose(ftpr);
    return 0;

}
