#ifndef TFUNC_H_INCLUDED
#define TFUNC_H_INCLUDED
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include "pthreaddef.h"
pthread_t tworkers[NROW];
pthread_mutex_t lock;
void *thread_func(void* tdata);


#endif // TFUNC_H_INCLUDED
