#include "tfunc.h"
void* thread_func(void* tdata)
{
    int i,j;
    i=(int)tdata;                          //传递过来的参数
    pthread_t actualThread;                //定义承接线程号的符号，类型为unsigned long int型
    actualThread=pthread_self();           //得到子线程自身参数号
    if(actualThread!=tworkers[i]) return;  //用于验证该线程是否正确
    pthread_mutex_lock(&lock);

    //矩阵乘法

    v1[i]=0;
    for(j=0;j<NCOL;j++)
    {
        v1[i]+=mx[i][j]*v2[j];

    }
    //print_mx();                           //打印二维矩阵

    //print_vec(NCOL,v2);                   //打印用于乘法的一维矩阵v2

    //printf("v1[%d]=%lf\n",i,v1[i]);       //打印结果


    pthread_mutex_unlock(&lock);
}
