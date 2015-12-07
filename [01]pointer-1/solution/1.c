#include <stdio.h>
int main() {
    int a,b;
    int *pa, *pb, *pt;
    scanf("%d %d",&a,&b);

    pa = &a;
    pb = &b;
    if ( (*pa) > (*pb) ) {
        pt = pa;
        pa = pb;
        pb = pt;
    }

    printf("%d %d\n",*pa,*pb);
    printf("%p %p\n",pa,pb);
    return 0;
}
