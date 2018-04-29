#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>
//#include <editline/history.h>

int main(int argc,char** argv){
	puts("Lay Plus Plus Language Version 0.0.0.1");
	puts("Press Ctrl+C to exit\n");

	while(1){
		char *input=readline("LPPL> ");
		add_history(input);

		printf("U puts %s on the display\n ", input);
		free(input);
	}
	return 0;
}
