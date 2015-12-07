#include <stdio.h>
void swap(int *a,int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int* f(int *a,int *b,int *c) {
    if ( (*a) > (*b) ) 
        swap(a,b);
    if ( (*b) > (*c) ) 
        swap(b,c);
    if ( (*a) > (*b) ) 
        swap(a,b);
    return b;
}
int main() {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);

    int *mid = f(&a,&b,&c);
    printf("%d\n",*mid);
    printf("%d %d %d\n",a,b,c);
    return 0;
}
