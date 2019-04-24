%{
int key=0, op=0, id=0, relop=0;
%}
letter[a-zA-Z]
digit[0-9]
%%
(begin|if|while|do|else) {key++;}
("+"|"-"|"*"|"/"|"%") {op++;}
("<"|">"|"<="|">="|"!=") {relop++;}
({letter}({letter})|{digit})* {id++;}
%%
int yywrap() {}
void main()
{
	yylex();
	printf("keyword: %d\nOperator: %d\nRelational Operator: %d\nIdentifier: %d",key,op,relp,id);
}