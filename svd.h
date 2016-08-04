/*************************************************************
 * 一般实矩阵的奇异值分解，参见《c 常用算法程序集》徐世良P169
 *************************************************************/
#ifndef _SVD_H
#define _SVD_H
#define MAX_ITERA 60
#define MIN_DOUBLE (1e-30)

#include "stdlib.h"
#include "math.h"

int dluav(double a[],int m,int n,double u[],double v[],double eps,int ka);
void damul(double a[],double b[],int m,int n,int k,double c[]);
void ppp(double a[],double e[],double s[],double v[],int m,int n);
void sss(double fg[2],double cs[2]);

#endif