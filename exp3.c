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
char* primerDocument(char c){
    if(c == 'n'){
        return "newton/exp3eq.txt";
    }else {
        return "lagrange/exp3eq.txt";
    }
}
char* segonDocument(char c){
    if(c == 'n'){
        return "newton/exp3eq,txt";
    } else {
        return "exp3cheb.txt";
    }
}
