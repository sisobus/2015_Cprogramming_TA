#include <stdio.h>
int main() {
    int H,W,N;
    int a[11][111],r=1;
    scanf("%d%d%d",&H,&W,&N);
    for ( int i = 1 ; i <= W ; i++ ) 
        for ( int j = 1 ; j <= H ; j++ ) 
            *(*(a+j)+i) = r++;
    for ( int i = 1 ; i <= H ; i++ ) 
        for ( int j = 1 ; j <= W ; j++ ) 
            if ( *(*(a+i)+j) == N ) {
                printf("%d%02d\n",i,j);
                return 0;
            }
    return 0;
}
