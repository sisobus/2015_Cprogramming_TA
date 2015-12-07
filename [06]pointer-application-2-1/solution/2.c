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
void all_sort(int a[][111],int n,int m) {
    int i;
    for ( i = 0 ; i < n ; i++ ) 
        sort(&a[i][0],m);
}
int binary_search(int *a,int *endPtr,int key,int **findPtr) {
    int *le = a;
    int *ri = endPtr;
    int *mid;
    while ( le <= ri ) {
        mid = le + (ri-le)/2;
        if ( *mid == key ) {
            *findPtr = mid;
            return 1;
        } else if ( *mid < key ) {
            le = mid + 1;
        } else if ( *mid > key ) {
            ri = mid - 1;
        }
    }
    findPtr = NULL;
    return 0;
}
int all_binary_search(int a[][111],int n,int m,int key,int **findPtr) {
    int i;
    for ( i = 0 ; i < n ; i++ ) 
        if ( binary_search(&a[i][0],&a[i][0]+m,key,findPtr) ) return 1;
    return 0;
}
int main() {
    int n,m,k,i,j;
    int a[111][111];
    int *findPtr;
    scanf("%d %d %d",&n,&m,&k);
    for ( i = 0 ; i < n ; i++ ) 
        for ( j = 0 ; j < m ; j++ ) 
            scanf("%d",&a[i][j]);
    all_sort(a,n,m);
    if ( all_binary_search(a,n,m,k,&findPtr) ) {
        printf("%d\n",1);
        printf("%p\n",findPtr);
    } else {
        printf("%d\n",0);
    }
    return 0;
}
