#include <stdio.h>
void shift_left(int *a) {
    int t = *a;
    int i;
    for ( i = 0 ; i < 9 ; i++ ) 
        *(a+i) = *(a+i+1);
    *(a+9) = t;
}
void shift_n_left(int *a,int n) {
    int i;
    for ( i = 0 ; i < n ; i++ ) 
        shift_left(a);
}
void print_array(int *a) {
    int i;
    for ( i = 0 ; i < 10 ; i++ ) 
        printf("%d ",*(a+i));
    puts("");
}
int main() {
    int a[11]={1,2,3,4,5,6,7,8,9,10};
    int n;
    scanf("%d",&n);

    shift_n_left(a,n);
    print_array(a);
    return 0;
}
