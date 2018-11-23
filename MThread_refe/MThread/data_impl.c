#include "pthreaddef.h"
#include<math.h>
void fill_data()
{
    int i,j;
    for(i=0;i<NCOL;i++)
    {
        v2[i]=(double)rand();//5;//(double)rand();
    }

    for(i=0;i<NROW;i++)
    {
        for(j=0;j<NCOL;j++)
        {
            //if(i==j)mx[i][j]=1;
           // else
               // mx[i][j]=0;
            mx[i][j]=(double)rand();
        }
    }
}
void print_mx()
{
    int i,j;
     for(i=0;i<NROW;i++)
    {
        for(j=0;j<NCOL;j++)
        {
            printf("%f\t",mx[i][j]);;
        }
        printf("\n");
    }
}
void print_vec(int nelm,double * arr)
{
    int i;
    for(i=0;i<nelm;i++)
    {
        printf("%f\t",*(arr+i));
    }
    printf("---\n");
}
void test_data()
{
    fill_data();
    print_mx();
    print_vec(NROW,v1);
    print_vec(NCOL,v2);
}
