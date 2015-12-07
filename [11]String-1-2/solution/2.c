#include <stdio.h>
int get_length(char *s) {
    int ret = 0;
    char *p = s;
    while ( *p != '\0' ) ret++,p++;
    return ret;
}
int is_only_number(char *s) {
    char *p = s;
    while ( *p != '\0' ) {
        if ( !(*p >= '0' && *p <= '9') )
            return 0;
        p++;
    }
    return 1;
}
int main() {
    char *key = "BKMGTP";
    char s[22];
    scanf("%16s",s);
    int len = get_length(s);
    if ( is_only_number(s) ) {
        int next = (len-1)/3;
        if ( next == 0 ) {
            printf("%s\n",s);        
        } else {
            char c = key[next];
            int end = len-next*3;
            for ( int i = 0 ; i < end ; i++ ) 
                printf("%c",s[i]);
            printf("%c\n",c);
        }
    } else {
        printf("%s\n",s);
    }
    return 0;
}
