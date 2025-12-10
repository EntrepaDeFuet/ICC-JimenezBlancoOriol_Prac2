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
        return "documents/newton/exp3eq.txt";
    }else {
        return "documents/lagrange/exp3eq.txt";
    }
}
char* segonDocument(char c){
    if(c == 'n'){
        return "documents/newton/exp3cheb.txt";
    } else {
        return "documents/lagrange/exp3cheb.txt";
    }
}
char* documentComparador(char c){
    if(c == 'c'){
        return "documents/compare/exp3_Cheb_compare.txt";
    } else {
        return "documents/compare/exp3_eq_compare.txt";
    }
}
double integral(){
    return 0.0;
}
