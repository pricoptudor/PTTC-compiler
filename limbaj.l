%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
%}
%x comm pass 
%option noyywrap
%%

"<prog>"            { return PROG_BEGIN; }
"</prog>"           { return PROG_END; }

"<comm>"            { BEGIN comm; }
<comm>"</comm>"     { BEGIN 0; return COMMENT; }
<comm>(\n|[^\n])    { }

"\""                { strcpy(yylval.sir_var, ""); BEGIN pass; }
<pass>"\""          { BEGIN 0; return ANYTHING; }
<pass>(\n|[^\n])    { strcat(yylval.sir_var, yytext); }

"<global>"          { return GLOBAL_BEGIN; }
"</global>"         { return GLOBAL_END; }

"<fnc&str>"         { return FNC_STR_BEGIN; }
"</fnc&str>"        { return FNC_STR_END; }

"<main>"            { return MAIN_BEGIN; }
"</main>"           { return MAIN_END; }

"struct"            { return STRUCT_TYPE; }
"<struct>"          { return STRUCT_BEGIN; }
"</struct>"         { return STRUCT_END; }

"print"             { return PRINT; }

"const"             { return CONST; }
"int"               { return INT; }
"float"             { return FLOAT; }
"char"              { return CHAR; }
"string"            { return STRING; }
"bool"              { return BOOL; } 

"+"                 { return ADUNARE; }
"-"                 { return SCADERE; }
"++"                { return INCREMENT; }
"--"                { return DECREMENT; }
"*"                 { return INMULTIRE; }
"/"                 { return IMPARTIRE; }
"="                 { return ASSIGN; }
"=="                { return EQUAL; }
"!="                { return NEQUAL; }
"<"                 { return LOWER; }
"<="                { return LEQ; }
">"                 { return GREATER; }
">="                { return GEQ; }
"&&"                { return AND; }            
"||"                { return OR; }

"array"             { return ARRAY; }
".insert"           { return ARRAY_INSERT; }
".delete"           { return ARRAY_DELETE; }
".get"              { return ARRAY_GET; }
".size"             { return ARRAY_SIZE; }

"func"              { return FUNCTION_TYPE; }
"<func>"            { return FUNCTION_BEGIN; }
"</func>"           { return FUNCTION_END; }
"return"            { return RETURN; }

"<if>"              { return IF_BEGIN; }
"</if>"             { return IF_END; }

"<else>"            { return ELSE_BEGIN; }
"</else>"           { return ELSE_END; }

"<while>"           { return WHILE_BEGIN; }
"</while>"          { return WHILE_END; }

"<for>"             { return FOR_BEGIN; }
"</for>"            { return FOR_END; }

\'[a-zA-Z]\'                          { yylval.sir_var[0]=yytext[1]; yylval.sir_var[1]=0; return VALUE_CHR; }

[_a-zA-Z][_a-zA-Z0-9]*                { strcpy(yylval.nume_var, yytext); return ID; }    

[0]|[1-9][0-9]*     	              { yylval.num = atof(yytext); return NUMBER; }
[0]|[1-9][0-9]*\.[0-9]+               { yylval.num = atof(yytext); return NUMBER_FLOAT; }

[ \t] ;

\n {yylineno++;}
. {return yytext[0];}








 
