#include <stdio.h>
#include <stdlib.h>
#ifndef false
#define false 0
#endif
#ifndef true
#define true !(false)
#endif
typedef int DATA_TYPE;
typedef struct _NODE {
    DATA_TYPE value;
    struct _NODE *link;
} NODE;
NODE* getNewNode() {
    NODE *ret = (NODE*)malloc(sizeof(NODE));
    ret->value = 0;
    ret->link = NULL;
    return ret;
}
int isListEmpty(NODE* head) {
    return head == NULL;
}
int getListSize(NODE* head) {
    int ret = 0;
    NODE *p;
    for ( p = head ; p ; p=p->link ) 
        ret++;
    return ret;
}
NODE* findNodeWithValue(NODE* head,DATA_TYPE key) {
    NODE* ret = NULL;
    for ( ret = head ; ret ; ret=ret->link ) 
        if ( ret->value == key ) return ret;
    return ret;
}
NODE *findNodeAtEnd(NODE* head) {
    if ( isListEmpty(head) ) return NULL;
    NODE* ret = NULL;
    for ( ret = head ; ret->link ; ret=ret->link );
    return ret;
}
NODE *findNodeAtEndPrevNode(NODE* head) {
    if ( getListSize(head) <= 1 ) return NULL;
    if ( head->link == NULL ) return NULL;
    NODE * ret = NULL;
    for ( ret = head ; ret->link->link ; ret=ret->link );
    return ret;
}
void insertNodeAtFront(NODE **head,DATA_TYPE value) {
    NODE* newNode = getNewNode();
    newNode->value = value;
    newNode->link = *head;
    *head = newNode;
}
void insertNodeAtBack(NODE **head,DATA_TYPE value) {
    NODE* newNode = getNewNode();
    newNode->value = value;
    newNode->link = NULL;
    NODE* endNode = findNodeAtEnd(*head);
    if ( endNode == NULL ) {
        *head = newNode;
    } else {
        endNode->link = newNode;
    }
}
int removeNodeAtFront(NODE **head) {
    if ( isListEmpty(*head) ) return false;
    if ( getListSize(*head) == 1 ) {
        free(*head);
        *head = NULL;
        return true;
    }
    NODE* p = *head;
    *head = (*head)->link;
    free(p);
    return true;
}
int removeNodeAtBack(NODE **head) {
    if ( isListEmpty(*head) ) return false;
    if ( getListSize(*head) == 1 ) {
        free(*head);
        return true;
    }
    NODE* p = findNodeAtEndPrevNode(*head);
    free(p->link);
    p->link = NULL;
    return true;
}
void printIntegerList(NODE* head) {
    if ( isListEmpty(head) ) {
        puts("list is empty");
    } else {
        for ( NODE* p=head ; p ; p=p->link ) 
            printf("%d ",p->value);
        puts("");
    }
}
void printCharacterList(NODE *head) {
    if ( isListEmpty(head) ) {
        puts("list is empty");
    } else {
        for ( NODE* p=head ; p ; p=p->link ) 
            printf("%c",p->value);
        puts("");
    }
}
void freeList(NODE **head) {
    if ( isListEmpty(*head) ) return;
    do {
        NODE *p = *head;
        *head = (*head)->link;
        free(p);
    } while ( *head != NULL );
}
void f21_1() {
    typedef int DATA_TYPE;
    NODE* head = NULL;
    DATA_TYPE A[]={3,9,8,2,5,10,7,1,4,6};
    for ( int i = 0 ; i < 10 ; i++ ) 
        insertNodeAtFront(&head,A[i]);
    printIntegerList(head);
}
void f21_2() {
    typedef char DATA_TYPE;
    NODE* head = NULL;
    insertNodeAtFront(&head,'p');
    insertNodeAtFront(&head,'p');
    insertNodeAtFront(&head,'a');
    insertNodeAtBack(&head,'l');
    insertNodeAtBack(&head,'e');
    printCharacterList(head);
}
void f22_1() {
    typedef int DATA_TYPE;
    NODE* head = NULL;
    DATA_TYPE A[]={3,9,8,2,5,10,7,1,4,6};
    for ( int i = 0 ; i < 10 ; i++ ) 
        insertNodeAtBack(&head,A[i]);
    printIntegerList(head);
    for ( int i = 0 ; i < 10 ; i++ ) {
        removeNodeAtFront(&head);
        printIntegerList(head);
    }
    freeList(&head);
}
void f22_2() {
    typedef char DATA_TYPE;
    NODE *head = NULL;
    insertNodeAtFront(&head,'n');
    insertNodeAtFront(&head,'e');
    insertNodeAtFront(&head,'p');
    insertNodeAtBack(&head,'l');
    insertNodeAtFront(&head,'o');
    insertNodeAtBack(&head,'a');
    insertNodeAtBack(&head,'b');
    printCharacterList(head);
    removeNodeAtFront(&head);
    removeNodeAtBack(&head);
    removeNodeAtBack(&head);
    removeNodeAtBack(&head);
    printCharacterList(head);
    freeList(&head);
}
int main() {
    f21_1();
//    f21_2();
//    f22_1();
//    f22_2();
    return 0;
}
