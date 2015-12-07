#include <stdio.h>
int is_prime(int ***a) {
    int i;
    if ( (***a) <= 1 ) return 0;
    for ( i = 2 ; i*i <= (***a) ; i++ ) 
        if ( (***a)%i == 0 ) return 0;
    return 1;
}
int main() {
    int a;
    int *pa;
    int **ppa;

    scanf("%d",&a);
    pa = &a;
    ppa = &pa;
    printf("%d\n",is_prime(&ppa));
    return 0;
}
