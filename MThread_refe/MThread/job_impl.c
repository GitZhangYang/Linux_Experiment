#include "job.h"
#include<time.h>
int dojob()
{
    clock_t start2,finish2;
    double totaltime;
    int i,j;
    fill_data();//填充数据
    //该函数用于C函数的多线程编程中，互斥锁的初始化
    //pthread_mutexattr_init()函数成功完成之后会返回零，其他任何返回值都表示出现了错误。
    start2=clock();
    if(pthread_mutex_init(&lock,NULL)<0)
    {
        perror("Cannot initialize the mutex");
        exit(1);
    }
       for(i=0;i<NROW;i++)
       {
           //创建线程
           /*第一个参数：指向线程标示符pthread_t的指针；

             第二个参数：设置线程的属性

             第三个参数：线程运行函数的起始地址

             第四个参数：运行函数的参数*/


             //则实验中创建的线程数为为NROW个
           if(pthread_create(&tworkers[i],NULL,thread_func,(void*)i)!=0)
           {
               perror("Cannot create threads");
               exit(2);
           }
       }
       for(i=0;i<NROW;i++)
       {
           //确保主线程等到子线程执行完成之后才退出

           pthread_join(tworkers[i],NULL);
       }
       pthread_mutex_destroy(&lock);   //互斥锁销毁函数
       print_vec(NROW,v1);             //打印整体结果
       finish2=clock();
       totaltime=(double)(finish2-start2);
       printf("\n此程序多线程的运行时间为:%lf ms\n",totaltime);
       return 0;

}






int dojob1()
{
    clock_t start1,finish1;
    double totaltime;
    int i,j;
    start1=clock();
    //不用多线程求解情况
    for(i=0;i<NROW;i++)
    {
       for(j=0;j<NCOL;j++)
       {
           v1[i]+=mx[i][j]*v2[j];
       }
    }
    print_vec(NROW,v1);             //打印整体结果
    finish1=clock();
    totaltime=(double)(finish1-start1);
    printf("\n此程序非多线程的运行时间为:%lf ms\n",totaltime);

}
