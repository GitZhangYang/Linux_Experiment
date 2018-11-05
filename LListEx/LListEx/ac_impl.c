#include "access.h"
int isEmpty(ListNodePtr sPtr)
{
    return sPtr==NULL;
}
void printList(ListNodePtr currentPtr)
{
    if(currentPtr==NULL)
    {
        printf("List is empty.\n\n");
    }
    else
    {
        printf("The list is:\n");
        while(currentPtr!=NULL)
        {
            printf("%c->",currentPtr->data);
            currentPtr=currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}
void instructions(void)
{
    printf("Enter your choice:\n"
           "\t 1 to insert an element into the list.\n"
           "\t 2 to delete an element from the list.\n"
           "\t 3 to end.\n"
           );
}
