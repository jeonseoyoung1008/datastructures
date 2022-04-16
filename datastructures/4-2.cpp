#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
    char data[4];
    struct ListNode* link;
} listNode;

typedef struct {
    listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void) {
    linkedList_h* L;
    L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L->head = NULL;
    return L;
}

void freelinkedList_h(linkedList_h* L) {
    listNode* p;
    while (L->head != NULL) {
        p = L->head;
        L->head = L->head->link;
        free(p);
        p = NULL;
    }
}

void printList(linkedList_h* L) {
    listNode* p;
    printf("L = (");
    p = L->head;
    while (p != NULL) {
        printf("%s", p->data);
        p = p->link;
        if (p != NULL) printf(",");
    }
    printf(") \n");
}

void insertFirstNode(linkedList_h* L, char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    newNode->link = L->head;
    L->head = newNode;
}

void insertMiddeNode(linkedList_h* L, listNode* pre, char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    if (L == NULL) {
        newNode->link = NULL;
        L->head = newNode;
    }
    else if (pre == NULL) {
        L->head = newNode;
    }
    else {
        newNode->link = pre->link;
        pre->link = newNode;
    }
}

void insertLastNode(linkedList_h* L, char* x) {
    listNode* newNode;
    listNode* temp;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    newNode->link = NULL;
    if (L->head == NULL) {
        L->head = newNode;
        return;
    }

    temp = L->head;
    while (temp->link != NULL) temp = temp->link;
    temp->link = newNode;
}