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
    int n, nodes;
    double *x,*y,*copiay, *z, nz,lz,actual,maxl,maxn,a,b;
    char c;
    printf("Siusplau digues el grau del polinomi desitjat: \n");
    scanf("%d",&n);
    nodes = n+1;
    printf("Siusplau digues si prefereixes fer servir punts equidistants 'e' o bé punts de Chebyshev 'c'\n");
    scanf("%c",&c);
    if(c!= 'c' || c!= 'e'){
        printf("No t'entenc, calcularé per defecte el Chebyshev \n");
        c = 'c';
    }
    x = (double *) malloc(nodes*sizeof(double));
    if(x == NULL){
        printf("Errror de memòria al main()\n");
        return -1;
    }
    y = (double*)malloc(nodes*sizeof(double));
    if(y==NULL){
        printf("Error de memòria al main()\n");
        free(x);
        return -1;
    }
    copiay = (double*)malloc(nodes*sizeof(double));
    if(copiay == NULL){
        printf("Error de memòria a main()\n");
        free(x);
        free(y);
        return-1;
    }
    z = (double*)malloc(1000*sizeof(double));
    if(z == NULL){
        printf("Error de memòria al main()\n");
        free(x);
        free(y);
        free(copiay);
        return -1;
    }
    a = primerValor();
    b = segonValor();
    if(c == 'c'){
        if(chebsyev(n,a,b,x)==-1){
            printf("Error calculant els punts de Chebyshev\n");
            return -1;
        }
    }else{
        if(equidistants(n,a,b,x)==-1){
            printf("Error a l'hora de calcular els punts equidistants\n");
            free(x);
            free(y);
            free(z);
            free(copiay);
            return -1;
        }
    }

    for(int i = 0; i <= n; i++){
        y[i] = fun(x[i]);
        copiay[i] = y[i];
    }
    if(equidistants(999,a,b,z)==-1){
        printf("Error a l'hora de calcular els z punts equidistants\n");
        free(x);
        free(y);
        free(z);
        free(copiay);
        return -1;
    }
    FILE *ftpr;
    ftpr = fopen(documentComparador(c),"w");

    if(difdiv(n,x,y)== -1){
        printf("Error calculant les diferències dividides\n");
        free(x);
        free(y);
        free(z);
        free(copiay);
    }
    if(calcul_coef(n,x,y)==-1){
        printf("Error calculant els coeficients del polinomi de Newton\n");
        free(x);
        free(y);
        free(z);
        free(copiay);
    }
    maxl = 0;
    maxn = 0;
    for(int i = 0; i<1000;i++){
        nz = horner(z[i],n,x,y);
        if(lagrange_eval(z[i],n,x,copiay,&lz) == -1){
            printf("El valor del polinomi de lagrange en el punt %20.16e no es pot calcular \n",z[i]);
            free(x);
            free(y);
            free(z);
            free(copiay);
            return -1;
        }
        actual = fun(z[i]);
        fprintf(ftpr,"%20.16e %20.16e %20.16e %20.16e %20.16e %20.16e \n",z[i],actual,lz,fabs(actual - lz),nz,fabs(actual - nz));
        if(maxl<fabs(actual-lz)){
            maxl = fabs(actual - lz);
        }
        if(maxn < fabs(actual - nz)){
            maxn = fabs(actual -nz);
        }
    }
    printf("El error màxim del polinomi de Lagrange és: %20.16e i el error màxim del polinomi de Newton és: %20.16e \n",maxl,maxn);


    return 0;
}
