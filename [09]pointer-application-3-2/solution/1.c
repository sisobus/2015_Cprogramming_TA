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
    int I,J,X,Y;
    scanf("%d%d%d%d",&I,&J,&X,&Y);
    for ( int i = I-1 ; i < X ; i++ ) 
        for ( int j = J-1 ; j < Y ; j++ ) 
            ret += a[i][j];
    return ret;
}
int main() {
    int N,M;
    scanf("%d%d",&N,&M);
    int **matrix = get_new_2d_array(N,M);
    for ( int i = 0 ; i < N ; i++ ) 
        for ( int j = 0 ; j < M ; j++ ) 
            scanf("%d",&matrix[i][j]);
    printf("%d\n",solve(matrix,N,M));    
    return 0;
}
