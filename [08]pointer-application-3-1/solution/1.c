#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void bubble_sort(int *a,int size) {
    for ( int i = 0 ; i < size ; i++ ) 
        for ( int j = 1 ; j < size-i ; j++ ) 
            if ( a[j-1] > a[j] ) 
                swap((a+j-1),(a+j));
}
int *get_new_array(int size) {
    int *ret = (int *)calloc(size,sizeof(int));
    return ret;
}
void double_double(int **a,int *size) {
    (*a) = (int*)realloc(*a,((*size)*2)*sizeof(int));
    for ( int i = 0 ; i < *size ; i++ ) 
        (*a)[i+(*size)] = (*a)[i]*2;
    (*size) *= 2;
    bubble_sort(*a,*size);
}
void print_all(int *a,int size) {
    for ( int i = 0 ; i < size ; i++ ) 
        printf("%d ",a[i]);
    puts("");
}
int main() {
    int N;
    scanf("%d",&N);
    int *a = get_new_array(N);
    for ( int i = 0 ; i < N ; i++ ) 
        scanf("%d",&a[i]);
    for ( int i = 0 ; i < 3 ; i++ ) {
        double_double(&a,&N);
        print_all(a,N);
    }
    return 0;
}
