#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void read_from_pipe(int f_des)
{
     FILE *stream;
     int c;
     double data;
     stream = fdopen(f_des,"r");
     do
     {
         fscanf(stream,"%lf",&data);
         printf("%lf\t",data);
     }while(data!=-9999);

     fclose(stream);
}
void write_to_pipe(int f_des)
{
     FILE *stream;
     int c,i,x;
     double data;
     stream = fdopen(f_des,"w");
     for(i=0;;i++)
     {
         x=scanf("%lf",&data);
         if(!x)break;
         else
         fprintf(stream,"%lf",data);
     }
     fprintf(stream,"%lf",-9999);
     fclose(stream);
}
int main(void)
{
    pid_t pid;
    int p_des[2];
    if(pipe(p_des))
    {
                   fprintf(stderr,"Pipe failed.\n");
                   return EXIT_FAILURE;
    }
    pid = fork();
    if(pid==(pid_t)0)
    {
					//In the child process. At first close writing pipe descriptor
                     close(p_des[1]);
                     read_from_pipe(p_des[0]);
                     return EXIT_SUCCESS;
    }
    else if(pid<(pid_t)0)
    {

                   fprintf(stderr,"Fork failed.\n");
                   return EXIT_FAILURE;
    }
    else
    {
					//In the super process. At first close the reading pipe descriptor
                     close(p_des[0]);
                     write_to_pipe(p_des[1]);
                     return EXIT_SUCCESS;
    }
}
