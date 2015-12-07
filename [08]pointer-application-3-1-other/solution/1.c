#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d",&n);
    int *a = (int*)calloc(n,sizeof(int));
    for ( int i = 0 ; i < n ; i++ ) 
        scanf("%d",&a[i]);
    int *b = (int*)calloc(10000,sizeof(int));
    for ( int i = 0 ; i < n ; i++ ) 
        b[a[i]]++;
    for ( int i = 0 ; i < 10000 ; i++ ) 
        if ( b[i] != 0 ) 
            printf("%d %d\n",i,b[i]);
    return 0;
}
