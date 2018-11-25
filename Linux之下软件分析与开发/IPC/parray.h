#ifndef PARRAY_H_INCLUDED
#define PARRAY_H_INCLUDED
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define NELEM   5
int data[NELEM];
void write_array_into_pipe(int f_des);
void read_array_from_pipe(int f_des);
void fill_data();
void test_parray();



#endif // PARRAY_H_INCLUDED
