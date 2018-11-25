#ifndef PIPEEX_H_INCLUDED
#define PIPEEX_H_INCLUDED
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
void read_from_pipe(int f_des);
void write_to_pipe(int f_des);
int anonym_pipeex();
#endif // PIPEEX_H_INCLUDED
