%{
#include<stdio.h>
void yyerror(char *);
int yylex(void);
char p='A'-1;
%}

%token INTEGER
%left "+" "-"
%left "*" "/"

%%
program: program expr '\n'	{printf("%d\n",$2);}
				|
				;
expr:
	INTEGER
		| expr "+" expr	{p++, printf("%c=%d+%d\n",p,$1,$3); $$ = $1 + $3;}
		| expr "-" expr	{p++, printf("%c=%d-%d\n",p,$1,$3); $$ = $1 - $3;}
		| expr "*" expr	{p++, printf("%c=%d*%d\n",p,$1,$3); $$ = $1 * $3;}
		| expr "/" expr	{p++, printf("%c=%d/%d\n",p,$1,$3); $$ = $1 / $3;}
		;
%%

void yyerror(char *s)
{
	fprintf(stdder,"%s\n",p);
}

int yylex(void)
{
	yyparse(); return 0;
}