#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void split(char *string, char *string_1, char *string_2);

void main(){
	char *string_1, *string_2;
	char input[30];
	int n;
	printf("input str : ");
	scanf("%30[^\n]", input);
	n = (int)strlen(input)/2;

	string_1 = (char*)malloc(sizeof(char)*(n+1));
	string_2 = (char*)malloc(sizeof(char)*(n+2));
	split(input, string_1, string_2);

	printf("[%s] -> [%s] [%s]\n", input, string_1, string_2);

        free(string_1); free(string_2);
}

void split(char *string, char *string_1, char *string_2){
	int i, n = (int)strlen(string);

	if (n%2 ==0){
		for(i=0; i<n/2; i++) string_1[i] = string[i];
	    string_1[n/2] = '\0';
	    for(i=n/2; i<n; i++) string_2[i-n/2] = string[i];
	    string_2[n-n/2] = '\0';
	}else{
		for(i=0; i<n/2; i++) string_1[i] = string[i];
	    string_1[n/2] = '\0';
	    for(i=(n/2); i<n-1; i++) string_2[i-n/2] = string[i];
	    string_2[n-n/2-1] = '\0';
	}
}
