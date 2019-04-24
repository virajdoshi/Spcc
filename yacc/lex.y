%{
	#include<stdio.h>
	void yyerror(char *)
	int yylex(void)
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
		| expr '+' expr	{$$ = $1 + $3;}
		| expr '-' expr	{$$ = $1 - $3;}
		| expr '*' expr	{$$ = $1 * $3;}
		| expr '/' expr	{$$ = $1 / $3;}
		;
%%

void yyerror(char *s)
{
	fprintf("stdder","%s\n",s);
}
int main(void)
{
	yyparse();return 0;
}