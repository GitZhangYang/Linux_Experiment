#include "pipe.h"
void anonym_pipe()
{
    int fda[2];		// file descriptors [0] : read end, [1] write end
    char buf[1];	// data buffer
    if(pipe(fda)< 0)
        fprintf(stderr,"create pipe failed\n");
    switch ( fork() )
    {
                              // fork an identical sub-process
        case -1 : fprintf (stderr,"fork failed\n");
        case 0:	              // child process is pipe reader
            close ( fda[1] ); // close write of pipe
            read ( fda[0], buf, 1 );		// read a character
            printf ("%c\n", buf[0] );
            break;
        default:	// parent process is pipe writer
        close ( fda[0] );				// close read end of pipe
        write (fda[1], "a", 1);		// write a character
        break;
    }

}
