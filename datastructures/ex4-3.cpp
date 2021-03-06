#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct ListNode
{
    char data[4];
    struct ListNode* link;
} listNode;

typedef struct
{
    listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void)
{
    linkedList_h* CL;
    CL = (linkedList_h*)malloc(sizeof(linkedList_h));
    CL->head = NULL;
    return CL;
}

void printList(linkedList_h* CL)
{
    listNode* p;
    printf(" CL = (");
    p = CL->head;
    do
    {
        printf("%s", p->data);
        p = p->link;
        if (p != CL->head) printf(", ");
    } while (p != CL->head);
    printf(") \n");
}

void insertFirstNode(linkedList_h* CL, char* x)
{
    listNode* newNode, * temp;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy_s(newNode->data, x);
    if (CL->head == NULL)
    {
        CL->head = newNode;
        newNode->link = newNode;
    }
    else
    {
        temp = CL->head;
        while (temp->link != CL->head)
            temp = temp->link;
        newNode->link = temp->link;
        temp->link = newNode;
        CL->head = newNode;
    }
}

void insertMiddleNode(linkedList_h* CL, listNode* pre, char* x)
{
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy_s(newNode->data, x);
    if (CL == NULL)
    {
        CL->head = newNode;
        newNode->link = newNode;
    }
    else
    {
        newNode->link = pre->link;
        pre->link = newNode;
    }
}

void deleteNode(linkedList_h* CL, listNode* old)
{
    listNode* pre;
    if (CL->head == NULL)return;
    if (CL->head->link == CL->head)
    {
        free(CL->head);
        CL->head = NULL;
        return;
    }
    else if (old == NULL) return;
    else
    {
        pre = CL->head;
        while (pre->link != old)
        {
            pre = pre->link;
        }
        pre->link = old->link;
        if (old == CL->head)
            CL->head = old->link;
        free(old);
    }
}

listNode* searchNode(linkedList_h* CL, char* x)
{
    listNode* temp;
    temp = CL->head;
    if (temp == NULL) return NULL;
    do
    {
        if (strcmp(temp->data, x) == 0) return temp;
        else temp = temp->link;
    } while (temp != CL->head);
    return NULL;
}

int main()
{
    linkedList_h* CL;
    listNode* p;
    CL = createLinkedList_h();
    printf("(1) ???? ???? ?????? ????????! \n");
    getchar();

    printf("(2) ???? ???? ???????? [??] ???? ????????! \n");
    insertFirstNode(CL, (char*)"??");
    printList(CL); getchar();

    printf("(3) ???? ???? ???????? [??] ???? ???? [??] ???? ????????! \n");
    p = searchNode(CL, (char*)"??"); insertMiddleNode(CL, p, (char*)"??");
    printList(CL); getchar();

    printf("(4) ???? ???? ???????? [??] ???? ???? [??] ???? ????????! \n");
    p = searchNode(CL, (char*)"??"); insertMiddleNode(CL, p, (char*)"??");
    printList(CL); getchar();

    printf("(5) ???? ???? ?????????? [??] ???? ????????! \n");
    p = searchNode(CL, (char*)"??"); deleteNode(CL, p);
    printList(CL); getchar();

    return 0;;
}