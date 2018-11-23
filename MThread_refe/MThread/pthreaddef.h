#ifndef PTHREADDEF_H_INCLUDED
#define PTHREADDEF_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#define NROW    2000
#define NCOL    2000
double v1[NROW];
double v2[NCOL];
double mx[NROW][NCOL];
void fill_data();
void print_vec(int,double*);
void print_mx();
void test_data();

#endif // PTHREADDEF_H_INCLUDED
