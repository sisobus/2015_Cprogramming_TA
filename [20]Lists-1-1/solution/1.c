#include <stdio.h>
#include <stdlib.h>
typedef struct _NODE {
    int value;
    struct _NODE *link;
} NODE;
void Insert(NODE *head,int a) {
    NODE* now = (NODE*)malloc(sizeof(NODE));
    now->value = a;
    now->link = NULL;
    NODE* p = head;
    for ( ; p->link ; p=p->link );
    p->link = now;
}
void PrintAll(NODE* head) {
    for ( NODE* p = head ; p ; p=p->link ) 
        printf("%d " ,p->value);
    puts("");
}
int main() {
    int A[10] = { 3, 9, 8, 2, 5, 10, 7, 1, 4, 6 };
    NODE* head = (NODE*)malloc(sizeof(NODE));
    head->value = A[0];
    head->link = NULL;
    for ( int i = 1 ; i < 10 ; i++ ) 
        Insert(head,A[i]);
    PrintAll(head);
    return 0;
}
