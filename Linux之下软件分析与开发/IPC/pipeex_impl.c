#include "pipeex.h"
void read_from_pipe(int f_des)
{
    FILE *stream;
     int c;
     stream = fdopen(f_des,"r");
     while((c=fgetc(stream))!=EOF)
     putchar(c);
     fclose(stream);
}
void write_to_pipe(int f_des)
{
    FILE *stream;
     int c;
     stream = fdopen(f_des,"w");
     fprintf(stream,"I'm an anonymous pipe.\n");
     fclose(stream);
}
int anonym_pipeex()
{
pid_t pid;
    int p_des[2];
    if(pipe(p_des))
    {
                   fprintf(stderr,"Pipe failed.\n");
                   return -1;
    }
    pid = fork();
    if(pid==(pid_t)0)
    {
					//In the child process. At first close writing pipe descriptor
                     close(p_des[1]);
                     read_from_pipe(p_des[0]);
                     return 0;
    }
    else if(pid<(pid_t)0)
    {

                   fprintf(stderr,"Fork failed.\n");
                   return -1;
    }
    else
    {
					//In the super process. At first close the reading pipe descriptor
                     close(p_des[0]);
                     write_to_pipe(p_des[1]);
                     return 0;
    }
}
