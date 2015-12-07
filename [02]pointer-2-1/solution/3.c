#include <stdio.h>
void f(int *H,int *M,int *S,int T) {
    int tot = (*H)*60*60 + (*M)*60 + (*S);
    tot += T;
    *S = tot % 60;
    tot /= 60;
    *M = tot % 60;
    tot /= 60;
    *H = tot % 24;
}
int main() {
    int H,M,S,T;
    scanf("%d %d %d %d",&H,&M,&S,&T);
    f(&H,&M,&S,T);
    printf("%02d:%02d:%02d\n",H,M,S);
    return 0;
}
