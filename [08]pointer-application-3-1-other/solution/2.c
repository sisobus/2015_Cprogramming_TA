#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand((unsigned)time(NULL));
    int size = 5;
    int *a = (int *)malloc(sizeof(int)*size);
    int cnt = 0;
    while ( 1 ) {
        int t = rand()%10;
        if ( cnt >= size ) {
            size += 5;
            a = (int*)realloc(a,sizeof(int)*(size));
        }
        a[cnt++] = t;
        if ( t == 5 ) {
            for ( int i = 0 ; i < cnt ; i++ ) 
                printf("%d",a[i]);
            puts("");
            for ( int i = cnt-1 ; i >= 0 ; i-- ) 
                printf("%d",a[i]);
            puts("");
            break;
        }
    }
    return 0;
}
