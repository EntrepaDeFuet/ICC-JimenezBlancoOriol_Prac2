#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int lagrange_eval(double z, int n,double *x,double *y, double *pz);
int equidistants(int n, double a, double b,double *x);
int chebsyev(int n, double a, double b, double *x);
double fun(double x);
double primerValor();
double segonValor();
char* primerDocument(char c);
char* segonDocument(char c);
double horner(double z, int n, double *x, double *c);
int difdiv(int n, double *x, double *y);
char* documentComparador(char c);
double trap_full(int n, double a, double b);
double integral();
double trap_refined(double Tn, int n, double a,double b);
