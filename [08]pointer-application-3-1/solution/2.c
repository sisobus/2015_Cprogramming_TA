#include <stdio.h>
#include <stdlib.h>
void push_back(int **a,int *size,int value);
// 이 함수는 크기가 size인 a배열의 가장 뒤에 value를 추가한다.
// realloc을 통하여 항상 원소의 개수만큼만 동적할당을 해야한다.
void pop_back(int **a,int *size);
// 이 함수는 크기가 size인 a배열의 가장 뒤를 삭제한다.
// realloc을 통하여 배열의 크기를 하나 줄인다.
double average(int *a,int size);
// a배열의 평균을 구하여 반환한다.
double variance(int *a,int size);
// a배열의 분산을 구하여 반환한다.

void push_back(int **a,int *size,int value) {
    if ( (*a) == NULL ) (*a) = (int*)calloc(*size,sizeof(int));
    *a = (int*)realloc(*a,((*size)+1)*sizeof(int));
    (*a)[(*size)++] = value;
}
int empty(int size) {
    return size == 0;
}
void pop_back(int **a,int *size) {
    if ( empty(*size) ) return ;
    (*size)--;
    *a = (int*)realloc(*a,(*size)*sizeof(int));
}
double average(int *a,int size) {
    int s = 0;
    for ( int i = 0 ; i < size ; i++ ) 
        s += a[i];
    return (double)s / size;
}
double variance(int *a,int size) {
    int s = 0;
    for ( int i = 0 ; i < size ; i++ ) 
        s += a[i]*a[i];
    double av = average(a,size);
    return (double)s/size - av*av;
}
void print_all(int *a,int size) {
    for ( int i = 0 ; i < size; i ++ ) 
        printf("%d ",a[i]);
    puts("");
}
int main() {
    int *a, size;    
    a = NULL, size = 0;
    int N;
    scanf("%d",&N);
    while ( N-- ) {
        int t;
        scanf("%d",&t);
        if ( t == 1 ) {
            int tt;
            scanf("%d",&tt);
            push_back(&a,&size,tt);
        } else if ( t == 2 ) {
            pop_back(&a,&size);
        }
        print_all(a,size);
        printf("%lf %lf\n",average(a,size),variance(a,size));
    }
    return 0;
}
