#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"Interp.h"

int main(){
    int n;
    double a,b,actualtn,actualt2n,tol;
    a = primerValor();
    b = segonValor();
    n = 1024;
    tol = 1.e-6;
    FILE* ftpr;
    ftpr = fopen(segonDocument('t'),"w");
    for (int i = 1; i<= 1024 ; i++){
        actualtn = trap_full(i,a,b);
        actualt2n = trap_refined(actualtn,n,a,b);
        if(fabs(actualt2n - actualtn) < tol){
            printf("El càlcul del error de |T2n - Tn| ha superat la tolerància\n");
            printf("|T2n - Tn| = %20.16e  |T2n - I| = %20.16e \n",fabs(actualtn - actualt2n),fabs(integral()-actualt2n));
            fclose(ftpr);
            return 0;
        }
        fprintf(ftpr,"%d %20.16e %20.16e %20.16e \n",2*i,actualt2n, fabs(actualt2n -actualtn),fabs(actualt2n -integral()));
    }
    fclose(ftpr);
        

    return 0;
}
