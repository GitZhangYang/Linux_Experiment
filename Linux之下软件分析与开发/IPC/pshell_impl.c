#include "pshell.h"
#include "parray.h"
void write_data_into_spipe(FILE* os)
{
    int i;
    for(i=0;i<NELEM;i++)
    {
        fprintf(os,"%d\n",data[i]);
    }
    if(ferror(os))
    {
        fprintf(stderr,"Output failed!\n");
        exit(-1);
    }
    fclose(os);
}
int test_spipe()
{
     FILE *output;
/**Open a pipe that connects the shell
 * command more which will read data from the pipe and
 * display the paged data into screen.
 */
    fill_data();
    output = popen("wc -l","w");
    if(!output)
    {
         fprintf(stderr,"Pipe failed.\n");
         return -1;
     }
     write_data_into_spipe(output);
     if(pclose(output)!=0)
     {
             fprintf(stderr,"Could not close the pipe.\n");
             return -1;
     }
     return 0;
}
