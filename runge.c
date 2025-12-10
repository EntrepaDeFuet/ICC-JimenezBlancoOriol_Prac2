#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"Interp.h"

double fun(double x){
    double res;
    res = 1/(1+25*pow(x,2));
    return res;
}
double primerValor(){
    return -5;
}
double segonValor(){
    return 5;
}
char* primerDocument(char c){
    if( c =='n'){
        return "documents/newton/rungeeq.txt";
    }else{
        return "documents/lagrange/rungeeq.txt";
    }
}
char* segonDocument(char c){
    if(c == 'l'){
        return "documents/lagrange/rungecheb.txt";
    }else{
        return "documents/newton/rungecheb.txt";
    }
}
char * documentComparador(char c){
    if(c =='c'){
        return "documents/compare/runge_cheb_compare.txt";
    }else{
        return "documents/compare/runge_eq_compare.txt";
    }
}
