#include "job.h"
int dojob()
{
    int i;
    fill_data();
    if(pthread_mutex_init(&lock,NULL)<0)
    {
        perror("Cannot initialize the mutex");
        exit(1);
    }

       for(i=0;i<NROW;i++)
       {
           if(pthread_create(&tworkers[i],NULL,thread_func,(void*)i)!=0)
           {
               perror("Cannot create threads");
               exit(2);
           }
       }
       for(i=0;i<NROW;i++)
       {
           pthread_join(tworkers[i],NULL);
       }
       pthread_mutex_destroy(&lock);
       print_vec(NROW,v1);

       return 0;

}
