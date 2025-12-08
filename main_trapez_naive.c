#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"Interp.h"

int main(){
    
    double a,b,tol,actual, anterior;
    a = primerValor();
    b = segonValor();
    tol = 1.e-6;
    anterior = 0;
    FILE *ftpr;
    ftpr = fopen(primerDocument('t'),"w");
    for (int n = 1; n<= 1024; n++){
        actual = trap_full(n,a,b);
        if(fabs(actual - anterior)< tol){
            printf("S'ha superat la tolerància en el càlcul de |Tn - Tn-1|\n");
            printf("L'error observat en aquesta iteració és de %20.16e \n",fabs(integral()-actual));
            fclose(ftpr);
            return 0;
        }
        fprintf(ftpr,"%d %20.16e %20.16e %20.16e",n,actual,fabs(actual-anterior),fabs(integral()-actual));
        anterior = actual;
    } 
    printf("L'algorisme ha arribat satisfactòriament a les 1024 iteracions.\n");
    printf("|I - T1024| = %20.16e \n",fabs(integral()-anterior));
    fclose(ftpr);

    return 0;
}
