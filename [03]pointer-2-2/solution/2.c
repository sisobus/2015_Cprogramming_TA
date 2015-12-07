#include <stdio.h>
void *f(void *pa,void *pb,int option) {
    if ( option == 0 ) {
        return *(int*)pa < *(int*)pb ? pa : pb;
    } else if ( option == 1) {
        return *(float*)pa < *(float*)pb ? pa : pb;
    } else if ( option == 2 ) {
        return *(double*)pa < *(double*)pb ? pa : pb;
    }
    return NULL;
}
int main() {
    int option;
    int a,b;
    float fa,fb;
    double da,db;
    void *pa,*pb,*ans;
    
    scanf("%d",&option);
    if ( option == 0 ) {
        scanf("%d %d",&a,&b);
        pa = &a;
        pb = &b;
        ans = f(pa,pb,option);
        printf("%d\n",*(int*)ans);
    } else if ( option == 1 ) {
        scanf("%f %f",&fa,&fb);
        pa = &fa;
        pb = &fb;
        ans = f(pa,pb,option);
        printf("%f\n",*(float*)ans);
    } else if ( option == 2 ) {
        scanf("%lf %lf",&da,&db);
        pa = &da;
        pb = &db;
        ans = f(pa,pb,option);
        printf("%lf\n",*(double*)ans);
    }
    return 0;
}
