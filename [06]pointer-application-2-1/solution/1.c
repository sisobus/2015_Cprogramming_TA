#include <stdio.h>
void swap(int *a,int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void sort(int *a,int m) {
    int i,j;
    for ( i = 0 ; i < m ; i++ ) 
        for ( int j = 1 ; j < m-i ; j++ ) 
            if ( a[j-1] > a[j] ) 
                swap((a+j-1),(a+j));
}
void print_array(int *a,int m) {
    int i;
    for ( i = 0 ; i < m ; i++ ) 
        printf("%d ",a[i]);
    puts("");
}
void all_sort(int a[][111],int n,int m) {
    int i;
    for ( i = 0 ; i < n ; i++ ) 
        sort(&a[i][0],m);
}
void print_all_array(int a[][111],int n,int m) {
    int i;
    for ( i = 0 ; i < n ; i++ ) 
        print_array(&a[i][0],m);
}
int main() {
    int n,m,i,j;
    int a[111][111];
    scanf("%d %d",&n,&m);
    for ( i = 0 ; i < n ; i++ ) 
        for ( j = 0 ; j < m ; j++ ) 
            scanf("%d",&a[i][j]);
    all_sort(a,n,m);
    print_all_array(a,n,m);
    return 0;
}
