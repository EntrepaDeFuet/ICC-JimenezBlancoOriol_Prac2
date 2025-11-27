#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"Interp.h"

double fun(double x){
    double res;
    res = 1/(1+25*pow(x,2));
    return res;
}