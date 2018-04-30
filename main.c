#include <stdio.h>
#include <stdlib.h>

#include "mpc.h"


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


	/********************/
	//mpc lang
	mpc_parser_t* Number=mpc_new("number");
	mpc_parser_t* Numberq=mpc_new("numberq");
	mpc_parser_t* Operator=mpc_new("operator");
	mpc_parser_t* Express=mpc_new("express");
	mpc_parser_t* Lppl=mpc_new("lppl");
	mpc_parser_t* Numbers=mpc_new("numbers");

	mpca_lang(MPCA_LANG_DEFAULT,
		"																																					\
			number	:/-?[0-9]+[.][0-9]+/;																						\
			numberq	:/-?[0-9]+/;																										\
			numbers	:<number> | <numberq>;																					\
			operator:'+' | '-' | '*' | '/' | '%' | \"add\" | \"sub\" | \"mul\" | \"div\" ;	\
			express	:<numbers> | '(' <operator> <express>+ ')';											\
			lppl		:/^/ <operator> <express>+ /$/;																	\
		",
		Number,Numberq,Numbers,Operator,Express,Lppl);

	/********************/

	puts("Lay Plus Plus Language Version 0.0.0.4 running on:");
	puts(PLATFORM_ID);
	puts("Press Ctrl+C to exit\n");

	while(1){
		char *input=readline("LPPL> ");
		add_history(input);
		/*mpc output*/
		mpc_result_t r;
		if(mpc_parse("<stdin>",input,Lppl,&r)){
			mpc_ast_print(r.output);
			mpc_ast_delete(r.output);
		}else{
			mpc_err_print(r.error);
			mpc_err_delete(r.error);
		}

		free(input);
	}
	return 0;
}
