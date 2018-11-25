#ifndef NPIPE_H_INCLUDED
#define NPIPE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#define NMESSAGE   5
char* sData[NMESSAGE];
void fill_messages();
void fill_messageex();
int read_data_from_fifo(char* npipe);
int write_data_into_fifo(char* npipe);
void test_npipe();

#endif // NPIPE_H_INCLUDED
