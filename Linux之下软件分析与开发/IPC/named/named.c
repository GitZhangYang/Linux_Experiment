#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
int main ()
{
    int pid;
    char *namedpipe = "/home/PipeFile.data";

 /* Create a fifo. */
    mkfifo(namedpipe, 0660);
/* Fork a child process.  */
    pid = fork ();
    if (pid == (pid_t) 0)
    {
        /* This is the child process.   */
        FILE *input;
        char str[256];
	int i;

        input = fopen(namedpipe, "r");  /* Open the fifo just like any FILE and read from it */
	for(i=0;i<4;i++)
	{
		fscanf(input,"%s",str);
		printf("Child: %s\n",str);
	}
	/**
        while(fscanf(input,"%s",str))
        {
            printf("CHILD: %s\n", str);
        }
	*/
        fclose(input);
    }
    else
    {
        /* This is the parent process.  */
        FILE* stream;

        stream = fopen (namedpipe, "w"); /* Open the fifo just like any FILE and write to it */
        fprintf (stream, "This is a test.\n");
        fprintf (stream, "Hello, world.\n");
        fprintf (stream, "My dog has fleas.\n");
        fprintf (stream, "This program is great.\n");
        fprintf (stream, "One fish, two fish.\n");
        fflush (stream);
        fclose (stream);

        waitpid (pid, NULL, 0);  /* Wait for the child process to finish.  */
    }
    return 0;
}
