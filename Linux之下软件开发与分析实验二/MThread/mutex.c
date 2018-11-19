#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t mutex;
int x = 0;

void *MyThread(void *arg)
{
    char *sbName;

    sbName = (char *)arg;
    pthread_mutex_lock(&mutex);
    x = x + 1;
   pthread_mutex_unlock(&mutex);
    printf("X = %d in Thread %s\n", x, sbName);
}
int main()
{
    pthread_t idA, idB;

    if (pthread_mutex_init(&mutex, NULL) < 0)
    {
          perror("pthread_mutex_init");
          exit(1);
    }
    if (pthread_create(&idA, NULL, MyThread, (void *)"A") != 0)
    {
       perror("pthread_create");
       exit(1);
    }

    if (pthread_create(&idB, NULL, MyThread, (void *)"B") != 0)
    {
        perror("pthread_create");
        exit(1);
     }
    pthread_join(idA, NULL);
    pthread_join(idB, NULL);

    pthread_mutex_destroy(&mutex);
}

