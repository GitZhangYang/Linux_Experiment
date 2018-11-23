#include "tfunc.h"
void* thread_func(void* tdata)
{
    int i,j;
    i=(int)tdata;                          //���ݹ����Ĳ���
    pthread_t actualThread;                //����н��̺߳ŵķ��ţ�����Ϊunsigned long int��
    actualThread=pthread_self();           //�õ����߳����������
    if(actualThread!=tworkers[i]) return;  //������֤���߳��Ƿ���ȷ
    pthread_mutex_lock(&lock);

    //����˷�

    v1[i]=0;
    for(j=0;j<NCOL;j++)
    {
        v1[i]+=mx[i][j]*v2[j];

    }
    //print_mx();                           //��ӡ��ά����

    //print_vec(NCOL,v2);                   //��ӡ���ڳ˷���һά����v2

    //printf("v1[%d]=%lf\n",i,v1[i]);       //��ӡ���


    pthread_mutex_unlock(&lock);
}
