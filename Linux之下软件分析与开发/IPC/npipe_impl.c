#include "npipe.h"
/**
void fill_messages()
{
    int i;
    char str1[10],str2[]="Message No ";
    for(i=0;i<NMESSAGE;i++)
    {
        itoa(i,str1,10);
        strcat(str2,str1);
        strcpy(sData[i],str2);
    }
}
***/
void fill_messageex()
{
    sData[0]="I am happy";
    sData[1]="You are happy";
    sData[2]="Happy every one";
    sData[3]="Good Morning";
    sData[4]="Good Evening";
}
int read_data_from_fifo(char* npipe)
{
    FILE* is;
    int i;
    char buf[256];
    is=fopen(npipe,"r");
    if(is==NULL)
    {
        fprintf(stderr,"Open fifo failed!\n");
        exit(1);
    }
    //for(i=0;i<NMESSAGE;i++)
    //{
        fscanf(is,"%s",buf);
        printf("%s\n",buf);
    //}
     pclose(is);
}
int write_data_into_fifo(char* npipe)
{
    FILE* os;
    int i;
    os=fopen(npipe,"w");
    if(os==NULL)
    {
        fprintf(stderr,"Open fifo failed!\n");
        exit(2);
    }
    //for(i=0;i<NMESSAGE;i++)
    //{
        fprintf(os,"%s\n","Notification_from_me");
    //}
    pclose(os);
}
void test_npipe()
{
    pid_t pid;
    char *namedpipe = "/home/Administrator/IPC/miaham.data";
    //fill_messageex();

 /* Create a fifo. */
    mkfifo(namedpipe, 0660);
 /* Fork a child process.  */
    pid = fork ();
    switch(pid)
    {
        case -1:fprintf(stderr,"Forking child process failed\n");
                break;
        case  0: /*This is the child process*/
                read_data_from_fifo(namedpipe);
                break;
        default: /*This is parent process*/
                 write_data_into_fifo(namedpipe);
                 /*Wait for the child process to finish.  */
                 waitpid (pid, NULL, 0);
                 break;
    }
}
