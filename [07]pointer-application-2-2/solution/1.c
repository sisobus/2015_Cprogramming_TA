#include <stdio.h>
#include <stdlib.h>

int *get_new_array(int size);
// 크기가 size인 int type을 할당하여 반환한다.
void get_new_array_call_by_value(int *a,int size);
// 입력으로 들어온 a를 int type으로 할당한다.
void get_new_array_call_by_reference(int **a,int size);
// 입력으로 들어온 a를 int type으로 할당한다.
void print_state(int *a);
// a가 NULL이면 not allocated를, 아니면 allocated를 출력한다.


int *get_new_array(int size) {
    int *new_array = (int*)malloc(sizeof(int)*size);
    for ( int i = 0 ; i < size; i++ ) 
        new_array[i] = 0;
    return new_array;
}
void get_new_array_call_by_value(int *a,int size) {
    a = (int *)malloc(sizeof(int)*size);
}
void get_new_array_call_by_reference(int **a,int size) {
    *a = (int *)malloc(sizeof(int)*size);
}
void print_state(int *a) {
    if ( a == NULL ) {
        printf("not allocated\n");
    } else {
        printf("allocated\n");
    }
}
void print_array(int *a,int size) {
    for ( int i = 0 ; i < size; i++ ) 
        printf("%d ",a[i]);
    puts("");
}
int main() {
    int *a = NULL;
    print_state(a);
    
    get_new_array_call_by_value(a,10);
    print_state(a);
    free(a);

    get_new_array_call_by_reference(&a,10);
    print_state(a);
    free(a);

    a = get_new_array(10);
    print_state(a);
    free(a);
    return 0;
}
