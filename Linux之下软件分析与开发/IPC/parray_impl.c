#include "parray.h"
void fill_data()
{
    int i;
    for(i=0;i<NELEM;i++)data[i]=i*i;
}
void write_array_into_pipe(int f_des)
{
    FILE* os;
    int i;
    os=fdopen(f_des,"w");
    for(i=0;i<NELEM;i++)
        fprintf(os,"%d",data[i]);
    fclose(os);
}
void read_array_from_pipe(int f_des)
{
    FILE* is;
    int i,n;
    is=fdopen(f_des,"r");
    for(i=0;i<NELEM;i++)
    {
        fscanf(is,"%d",&n);
        printf("%d\t",n);
    }
    fclose(is);
}
void test_parray()
{
    pid_t pid;
    int ppid[2];
    fill_data();
    if(pipe(ppid)<0)
    {
        printf("Pipe descriptor creation failed.\n");
        exit(1);
    }
    pid=fork();
    switch(pid)
    {
        case -1:printf("Forking failed\n");break;
        case 0:close(ppid[1]);
               read_array_from_pipe(ppid[0]);
               break;
        default:
               close(ppid[0]);
               write_array_into_pipe(ppid[1]);
               break;
    }
}
