#include "tfunc.h"
void* thread_func(void* tdata)
{
    int i,j;
    i=(int)tdata;
    //pthread_t actualThread;
    //actualThread=pthread_self();
    //if(actualThread!=tworkers[i]) return;
    pthread_mutex_lock(&lock);
    v1[i]=0;
    for(j=0;j<NCOL;j++)
    {
        v1[i]+=mx[i][j]*v2[j];

    }
    //print_mx();
    //print_vec(NCOL,v2);
    printf("v1[%d]=%lf\n",i,v1[i]);
    pthread_mutex_unlock(&lock);
}
