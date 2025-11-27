#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"Interp.h"

double fun(double x){
    double res;
    res = exp(3*x);
    return res;
}
double primerValor(){
    return 0;
}
double segonValor(){
    return 1;
}
char* primerDocument(){
    return "exp3eq.txt";
}
char* segonDocument(){
    return "exp3cheb.txt";
}