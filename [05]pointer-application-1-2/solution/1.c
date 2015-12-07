#include <stdio.h>
void mat_mul(int a[111][111],int b[111][111],int c[111][111],int n) {
    for ( int i = 0 ; i < n ; i++ ) 
        for ( int j = 0 ; j < n ; j++ ) 
            *(*(c+i)+j) = 0;
    for ( int i = 0 ; i < n ; i++ ) 
        for ( int j = 0 ; j < n ; j++ ) 
            for ( int k = 0 ; k < n ; k++ ) 
                *(*(c+i)+j) += (*(*(a+i)+k)) * (*(*(b+k)+j));
}
void print_mat(int c[111][111],int n) {
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) 
            printf("%d ",c[i][j]);
        puts("");
    }
}
int main() {
    int n;
    int a[111][111],b[111][111],c[111][111];
    scanf("%d",&n);
    for ( int i = 0 ; i < n ; i++ ) 
        for ( int j = 0 ; j < n ; j++ ) 
            scanf("%d",(*(a+i)+j));
    for ( int i = 0 ; i < n ; i++ ) 
        for ( int j = 0 ; j < n ; j++ ) 
            scanf("%d",(*(b+i)+j));
    mat_mul(a,b,c,n);
    print_mat(c,n);
    return 0;
}
