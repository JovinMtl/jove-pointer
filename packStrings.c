#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char ** packStrings(size_t n, char *s[]){
	size_t length = 0;

	for (size_t i = 0; i < n; i++){
		length += strlen(s[i]) + 1;
	}

	char **s2 = malloc(sizeof(char *) * n + length);

	char *top = (char *) (s2 + n);

	for(size_t i = 0; i < n; i++){
		strcpy(top, s[i]);
		s2[i] = top;
		top += strlen(s[i]) + 1;
	}
	
	return s2;
}

void freePackedString(char **s){
	free(s);
}

int main(int argc, char **argv){

	char **argv2 = packStrings(argc, argv);
	
	for (int i = 0; i < argc; i++){
		puts(argv2[i]);
	}

	freePackedString(argv2);

	return 0;
}
