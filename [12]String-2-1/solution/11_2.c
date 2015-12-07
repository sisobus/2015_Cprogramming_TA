#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *my_strncpy(char *a, char *b,int n);
void initialization(char *a,int n);

int main(int argc, char **argv)
{
    char *str1;
    char str[20];
    int i,n;

	printf("input str : ");
	scanf("%30[^\n]",str);

	n = (int)strlen(str);
	str1 = (char*)malloc(sizeof(char)*(n+1));
	    
    strcpy(str1, str);

	for (i=0;i<strlen(str1)+1;i++)
	{
		initialization(str,strlen(str));
		my_strncpy(str, str1, i);
        printf("%s\n", str);
	}

    return 0;
}

char *my_strncpy(char *a, char *b, int n)
{
   char *ret = a;
   int i;

   for(i = 0; i<n ; i++)
   {
       if((*a++ = *b++) == 0)
       {
           while(++i < n)
           {
               *a++ = 0;
           }
           return ret;
       }
   }
   return ret;

}

void initialization(char *a,int n){

	int i;
	for(i=0;i<n;i++) a[i]='*';

}


