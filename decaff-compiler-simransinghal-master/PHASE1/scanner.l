%{
  #include "parser.tab.h"
%}

%%

[ \t\n]*
\/\/.*$
"class"             return token_class;
"Program"           return token_program;
"for"               return token_for;
"break"             return token_break;
"return"            return token_return;
"continue"          return token_continue;
"void"				return token_void;
"if"                return token_if;
"else"              return token_else;
"int"|"boolean"	    return token_type;
"true"|"false"		return token_bool_literal;
"callout"			return token_callout;
'(\\.|[^\\'])+'     return token_char_literal;
"="|"+="|"-="		return token_assignment_operator;
"||"				return token_or;
  "&&"				return token_and;
[0-9]+				return token_decimal_literal;
0x[0-9a-fA-F]+		return token_hex_literal;
"=="				return token_equal_equal;
"<="				return token_less_equal;
"!="				return token_not_equal;
">="				return token_greater_equal;
\"(\\.|[^\\"])*\"   return token_string_literal;
[_a-zA-Z]+[_a-zA-Z0-9]*		return token_identifier;
.	                return *yytext;

%%
