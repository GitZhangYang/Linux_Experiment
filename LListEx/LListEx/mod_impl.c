#include "modify.h"
void insert(ListNodePtr* sPtr,char value)
{
    ListNodePtr newPtr;
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;
    newPtr=(ListNodePtr)malloc(sizeof(ListNode));
    if(newPtr!=NULL)
    {
        newPtr->data=value;
        newPtr->nextPtr=NULL;
        previousPtr=NULL;
        currentPtr=*sPtr;
        while(currentPtr!=NULL&&value>currentPtr->data)
        {
            previousPtr=currentPtr;
            currentPtr=currentPtr->nextPtr;
        }
        if(previousPtr==NULL)
        {
            newPtr->nextPtr=*sPtr;
            *sPtr=newPtr;
        }
        else
        {

            previousPtr->nextPtr=newPtr;
            newPtr->nextPtr=currentPtr;
        }
    }
    else
    {

        printf("%c not inserted. No memory available.\n",value);
    }
}
char delete(ListNodePtr *sPtr,char value)
{

    ListNodePtr previousPtr;
    ListNodePtr currentPtr;
    ListNodePtr tempPtr;
    if(value==(*sPtr)->data)
    {
        tempPtr=*sPtr;
        *sPtr=(*sPtr)->nextPtr;
        free(tempPtr);
        return value;
    }
    else
    {
        previousPtr=*sPtr;
        currentPtr=(*sPtr)->nextPtr;
        while(currentPtr!=NULL && currentPtr->data!=value)
        {
            previousPtr=currentPtr;
            currentPtr=currentPtr->nextPtr;
        }
        if(currentPtr!=NULL)
        {
            tempPtr=currentPtr;
            previousPtr->nextPtr=currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }
    return '\0';
}
