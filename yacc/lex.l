%{
	#include "y.tab.h"
	#include <stdlib.h>
	void yyerror(char *s);
%}
%%
[0-9]+		{yylval = atoi(yytext);
			 return INTEGER;
			}
[-+*/\n]	{return *yytext;
			}
[ \t]		;
.			yyerror("unknown character");
%%
int yywrap(void)
{
	return 1;
}