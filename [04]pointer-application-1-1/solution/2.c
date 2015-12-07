#include<stdio.h>
void swap(int *a,int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void sort(int *a,int n) {
    int i,j;
    for ( i = 0 ; i < n ; i++ ) 
        for ( j = 1 ; j < n-i ; j++ ) 
            if ( *(a+j-1) > *(a+j) ) 
                swap((a+j-1),(a+j));
}
void print_array(int *a,int n) {
    int i;
    for ( i = 0 ; i < n ; i++ ) 
        printf("%d ",*(a+i));
    printf("\n");
}
int main() {
    int n, i, a[111];
    scanf("%d",&n);
    for ( i = 0 ; i < n ; i++ ) 
        scanf("%d",a+i);
    sort(a,n);
    print_array(a,n);
    return 0;
}
