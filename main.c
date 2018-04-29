#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <string.h>
#define PLATFORM_ID "_WIN32"
static char buffer[2048];
char* readline(char* prompt){
	fputs(prompt,stdout);
	fgets(buffer,2048,stdin);
	char* cpy=malloc(strlen(buffer)+1);
	strcpy(cpy,buffer);
	cpy[strlen(cpy)-1]='\0';
	return cpy;
}

void add_history(char* unused) {
	//TODO
}
#endif
#ifdef __linux
#define PLATFORM_ID "__linux"
#include <editline/readline.h>
/*
*use -ledit to link to this program
*/
//#include <editline/history.h>
#endif



int main(int argc,char** argv){
	puts("Lay Plus Plus Language Version 0.0.0.1 running on:");
	puts(PLATFORM_ID);
	puts("Press Ctrl+C to exit\n");

	while(1){
		char *input=readline("LPPL> ");
		add_history(input);

		printf("U puts %s on the display\n ", input);
		free(input);
	}
	return 0;
}
