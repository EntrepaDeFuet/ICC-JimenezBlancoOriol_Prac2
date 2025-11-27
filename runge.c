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
char* primerDocument(){
    return "rungeeq.txt";
}
char* segonDocument(){
    return "rungecheb.txt";
}