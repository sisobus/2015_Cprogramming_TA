#include <stdio.h>
#include <math.h>
int main() {
    double a,b,c,d;
    double *pa,*pb,*pc,*pd;
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);

    pa = &a;
    pb = &b;
    pc = &c;
    pd = &d;

    printf("%lf\n",sqrt(((*pa)-(*pc))*((*pa)-(*pc))+((*pb)-(*pd))*((*pb)-(*pd))));
    return 0;
}
