%{
	#include <stdio.h>
	void yyerror(char const* s){printf("ERROR %s\n",s);}
%}

%token token_class token_string_literal token_bool_literal PROGRAM CHAR_LITERAL token_decimal_literal FOR HEX_LITERAL
%token IF ELSE CONTINUE TYPE ASSIGNMENT_OPERATOR RETURN token_identifier BREAK CALLOUT VOID

%left '+' '-'
%left '*' '/' '%'
%nonassoc '!'

%%

program: 				CLASS token_program  '{' multiple_decleration_field multiple_decleration_method '}'

multiple_decleration_field:
							     |multiple_decleration_fiels field_decl_single ';'

multiple_decleration_method:
                		|method_decl_single multiple_decleration_method

method_decl_single: 		TYPE token_identifier argumentList block
                        |VOID token_identifier argumentList block

argumentList:   '(' ')'
                |'(' TYPE token_identifier arg ')'

arg:
                |',' TYPE token_identifier arg

else_block:
          |ELSE block

condition:      '(' epxpression ')'

return_epxpression:
           |epxpression

arithmetic_exp:					epxpression '*' epxpression
          				  |epxpression '/' epxpression
          				  |epxpression '%' epxpression
          				  |epxpression '+' epxpression
          				  |epxpression '-' epxpression

relational_epxp:					epxpression '<' epxpression
          				|epxpression '>' epxpression
          				|epxpression LESS_EQUAL epxpression
          				|epxpression GREATER_EQUAL epxpression

function_name:    token_identifier

pparList:
                | epxpression ppar

par:
					    	|',' epxpression par

lit:                    int_lit
						    |CHAR_LITERAL
						    |token_bool_literal

int_lit:				token_decimal_literal
			     |HEX_LITERAL

%%

int main(){
	int a = yyparse();
    if(!a)
        printf("Valid Code.\n");
    else
        printf("Not Valid Code.\n");
}
