#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"Interp.h"
#define M_PI 3.14159265358979323846

double fun(double x){
    double res;
    res = pow((sin(x)),2);
    return res;
}
double primerValor(){
    return 0;
}
double segonValor(){
    return M_PI;
}
char* primerDocument(){
    return "sin2eq.txt";
}
char* segonDocument(){
    return "sin2cheb.txt";
}