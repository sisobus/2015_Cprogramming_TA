#include <stdio.h>
#include <stdlib.h>
int **get_new_2d_array(int n,int m) {
    int **ret = (int **)malloc(sizeof(int*)*n);
    for ( int i = 0 ; i < n ; i++ ) 
        ret[i] = (int*)malloc(sizeof(int)*m);
    return ret;
}
int solve(int **a,int n,int m) {
    int ret = 0;
    for ( int i = 0 ; i < n ; i++ ) 
        while ( a[i][ret] != 0 ) ret++;
    return ret+1;
}
int main() {
    int N,M;
    scanf("%d%d",&N,&M);
    int **a = get_new_2d_array(N,M);
    for ( int i = 0 ; i < N ; i++ ) 
        for ( int j = 0 ; j < M ; j++ ) 
            scanf("%d",&a[i][j]);
    printf("%d\n",solve(a,N,M));    
    return 0;
}
