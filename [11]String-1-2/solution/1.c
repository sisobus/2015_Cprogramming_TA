#include <stdio.h>
int get_length(char *s) {
    int ret = 0;
    char *p = s;
    while ( *p != '\0' ) ret++,p++;
    return ret;
}
int main() {
    char s[1111];
    gets(s);
    int len = get_length(s);
    int ans = 0;
    for ( int i = 0 ; i < len ; i++ ) {
        if ( s[i] != ' ' ) {
            ans++;
            while ( s[i] != ' ' ) i++;
            i--;
        }
    }
    printf("%d\n",ans);
    return 0;
}
