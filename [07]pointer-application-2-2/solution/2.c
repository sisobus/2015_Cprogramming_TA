#include <stdio.h>
#include <stdlib.h>
int *get_new_array(int size) {
    int *ret = (int*)malloc(sizeof(int)*size);
    for ( int i = 0 ; i < size ; i++ ) 
        ret[i] = 0;
    return ret;
}
int get_max_element(int *a,int size) {
    int mx = -12345,mx_idx = 0;
    for ( int i = 0 ; i < size ; i++ ) {
        if ( a[i] > mx ) {
            mx = a[i];
            mx_idx = i;
        }
    }
    a[mx_idx] = -1;
    return mx;
}
//int *get_next_process(int *prev_pointer,int size) {
//    int next_size;
//    int *next_pointer;
    /*
     * calculate next_size
     * next_pointer memory allocation 
     * generate next level
     * ex) prev_pointer = {1,2,3,4,5,6}
     *     next_pointer = {11,7,3}
     */
//    return next_pointer;
//}
int *get_next_process(int *prev,int size) {
    int next_size   = (size+1)/2;
    int *next       = get_new_array(next_size);
    for ( int i = 0 ; i < next_size ; i++ ) {
        int first   = get_max_element(prev,size);
        int second  = get_max_element(prev,size);
        if ( second == -1 ) {
            next[i] = first;
        } else {
            next[i] = first + second;
        }
    }
    return next;
}
void print_array(int *a,int size) {
    for ( int i = 0 ; i < size; i++ ) 
        printf("%d ",a[i]);
    puts("");
}
int main() {
    int N;
    scanf("%d",&N);
    int *a = get_new_array(N);
    for ( int i = 0 ; i < N ; i++ ) 
        scanf("%d",&a[i]);
    int size = N;
    while ( size != 1 ) {
        a = get_next_process(a,size);
        size = (size+1)/2;
        print_array(a,size);
    }
    return 0;
}
