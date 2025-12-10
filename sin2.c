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
char* primerDocument(char c){
    if(c == 'l'){
        return "documents/lagrange/sin2eq.txt";
    }else{
        return "documents/newton/sin2eq.txt";
    }
}
char* segonDocument(char c){
    if(c == 'l'){
        return "documents/lagrange/sin2cheb.txt";
    }else{
        return "documents/newton/sin2cheb.txt";
    }
}
char* documentComparador(char c){
    if(c == 'e'){
        return "documents/compare/n2eq_compare.txt";
    }else {
        return"documents/compare/n2Cheb_compare.txt";
    }
}
double integral(){
    return 0.0;
}
