#include "test.h"
void test()
{
    ListNodePtr head=NULL;
    int choice;
    char item;
    instructions();
    printf("?");
    scanf("%d",&choice);
    while(choice!=3)
    {
        switch(choice)
        {
        case 1:
            printf("Enter a character:");
            scanf("\n%c",&item);
            insert(&head,item);
            printList(head);
            break;
        case 2:
            if(!isEmpty(head))
            {
                printf("Enter character to be deleted:");
                scanf("\n%c",&item);
                if(delete(&head,item))
                {
                    printf("%c deleted.\n",item);
                    printList(head);
                }
                else
                {
                    printf("%c not found.\n\n",item);
                }
            }
            else
            {
                printf("List is empty.\n\n");
            }
            break;
        default:
            printf("Invalid choice.\n\n");
            instructions();
            break;
        }
        printf("?");
        scanf("%d",&choice);
    }
    printf("End of run.\n");
}
