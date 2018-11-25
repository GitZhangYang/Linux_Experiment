#include <stdio.h>
#include <stdlib.h>
void write_data(FILE *stream)
{
     int i;
/** Write the two first hundreds of integers into the pipe, one integer per line, so it depasses one
 * page.
 */
     for(i=0;i<200;i++)
     fprintf(stream,"%d\n",i);
     if(ferror(stream))
     {
                       fprintf(stderr,"Output to stream failed.\n");
                       exit(EXIT_FAILURE);
     }
}
int main(void)
{
    FILE *output;
/**Open a pipe that connects the shell command more which will read data from the pipe and
 * display the paged data into screen.
 */
    output = popen("more","w");
    if(!output)
    {
         fprintf(stderr,"Pipe failed.\n");
         return EXIT_FAILURE;
     }
     write_data(output);
     if(pclose(output)!=0)
     {
             fprintf(stderr,"Could not close the pipe.\n");
             return EXIT_FAILURE;
     }
     return EXIT_SUCCESS;
}
