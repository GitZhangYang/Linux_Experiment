#include "job.h"
#include<time.h>
int dojob()
{
    clock_t start2,finish2;
    double totaltime;
    int i,j;
    fill_data();//�������
    //�ú�������C�����Ķ��̱߳���У��������ĳ�ʼ��
    //pthread_mutexattr_init()�����ɹ����֮��᷵���㣬�����κη���ֵ����ʾ�����˴���
    start2=clock();
    if(pthread_mutex_init(&lock,NULL)<0)
    {
        perror("Cannot initialize the mutex");
        exit(1);
    }
       for(i=0;i<NROW;i++)
       {
           //�����߳�
           /*��һ��������ָ���̱߳�ʾ��pthread_t��ָ�룻

             �ڶ��������������̵߳�����

             �������������߳����к�������ʼ��ַ

             ���ĸ����������к����Ĳ���*/


             //��ʵ���д������߳���ΪΪNROW��
           if(pthread_create(&tworkers[i],NULL,thread_func,(void*)i)!=0)
           {
               perror("Cannot create threads");
               exit(2);
           }
       }
       for(i=0;i<NROW;i++)
       {
           //ȷ�����̵߳ȵ����߳�ִ�����֮����˳�

           pthread_join(tworkers[i],NULL);
       }
       pthread_mutex_destroy(&lock);   //���������ٺ���
       print_vec(NROW,v1);             //��ӡ������
       finish2=clock();
       totaltime=(double)(finish2-start2);
       printf("\n�˳�����̵߳�����ʱ��Ϊ:%lf ms\n",totaltime);
       return 0;

}






int dojob1()
{
    clock_t start1,finish1;
    double totaltime;
    int i,j;
    start1=clock();
    //���ö��߳�������
    for(i=0;i<NROW;i++)
    {
       for(j=0;j<NCOL;j++)
       {
           v1[i]+=mx[i][j]*v2[j];
       }
    }
    print_vec(NROW,v1);             //��ӡ������
    finish1=clock();
    totaltime=(double)(finish1-start1);
    printf("\n�˳���Ƕ��̵߳�����ʱ��Ϊ:%lf ms\n",totaltime);

}
