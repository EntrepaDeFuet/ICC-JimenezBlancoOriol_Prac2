#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include"Interp.h"


double fun(double x){
    return exp(x);
}
char* primerDocument(char c){
    return "documents/trapez/trapez_naive.dat";
}
double primerValor(){
    return 0;
}
double segonValor(){
    return 1;
}
double integral(){
    return exp(1) -1;
}
char* segonDocument(char c){
    return "documents/trapez/trapez_2n.dat";
}
