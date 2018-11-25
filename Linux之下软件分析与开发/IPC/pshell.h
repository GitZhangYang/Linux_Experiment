#ifndef PSHELL_H_INCLUDED
#define PSHELL_H_INCLUDED
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
//#define EXIT_FAILURE -99
//#define EXIT_SUCCESS 0
void write_data_into_spipe(FILE* os);
int test_spipe();

#endif // PSHELL_H_INCLUDED
