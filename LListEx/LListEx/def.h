#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct listNode {
    char data;
    struct listNode *nextPtr;
};
typedef struct listNode ListNode;
typedef ListNode* ListNodePtr;


#endif // DEF_H_INCLUDED
