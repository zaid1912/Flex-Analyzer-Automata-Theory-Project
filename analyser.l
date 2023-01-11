%option noyywrap

%{
	/*definitions*/
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	int lineno = 1; // initialize to 1
	FILE *OUT;
	void output(char *token_type);
	void yyerror();
%}

%x ML_COMMENT

alpha 		[a-zA-Z]
digit 		[0-9]
alnum 		{alpha}|{digit}
print		[ -~]


float		{digit}*"."{digit}*
IDENTIFIER 			{alpha}+{alnum}*
ICONST		"0"|[0-9]{digit}*
FCONST		"0"|{digit}*"."{digit}
CCONST		(\'{print}\')|(\'\\[nftrbv]\')
STRING		\"{print}*\"
HEADER 		"include <"{alpha}*">"|"#include \""{alpha}*".h\""

%%

"//".*					{ printf("Eat up comment at line %d\n", lineno); } 

"/*"					{ printf("Eat up comment from line %d ", lineno); BEGIN(ML_COMMENT); }
<ML_COMMENT>"*/" 		{ printf("to line %d\n", lineno); BEGIN(INITIAL); }
<ML_COMMENT>[^*\n]+		
<ML_COMMENT>"*"			
<ML_COMMENT>"\n"		{ lineno += 1; }



"cin"					{ output("INPUT"); }
"cout"					{ output("OUTPUT"); }
"endl"					{ output("ENDLINE"); }
"close"					{ output("FILE_CLOSE"); }
"delete"				{ output("KEYWORD_DELETE"); }
"const"					{ output("KEYWORD_CONST"); }
"static"				{ output("KEYWORD_STATIC"); }
"protected:"|"private:"|"public:"			{ output("ACCESS_MODIFIER"); }
"struct"				{ output("STRUCT_DECLARATION"); }
"class"					{ output("CLASS_DECLARATION"); }
"char"       			{ output("DATATYPE_CHAR"); }
"int"					{ output("DATATYPE_INT"); }
"float"					{ output("DATATYPE_FLOAT"); }
"double"				{ output("DATATYPE_DOUBLE"); }
"long"					{ output("DATATYPE_LONG"); }
"if"					{ output("KEYWORD_IF"); }
"else"					{ output("KEYWORD_ELSE"); }
"switch"				{ output("KEYWORD_SWITCH"); }
"case"					{ output("KEYWORD_CASE"); }
"default"				{ output("KEYWORD_DEFAULT"); }
"NULL"					{ output("KEYWORD_NULL"); }
"while"					{ output("KEYWORD_WHILE"); }
"do"					{ output("KEYWORD_DO"); }
"for"					{ output("KEYWORD_FOR"); }
"continue"				{ output("KEYWORD_CONTINUE"); }
"break"					{ output("KEYWORD_BREAK"); }
"friend"				{ output("FRIEND_CLASS/FUNCTION"); }
"void"					{ output("KEYWORD_VOID"); }
"return"				{ output("KEYWORD_RETURN"); }



"+"						{ output("ADD"); }
"-"						{ output("MINUS"); }
"*"						{ output("MULTIPLY/POINTER"); }
"\\"					{ output("ESCAPE_SEQUENCE"); }
"/"						{ output("DIVISION"); }
"%"						{ output("MOD"); }
"++"					{ output("INCRIMENT"); }
"--"					{ output("DECRIMENT"); }
"||"					{ output("OR"); }
"&&"					{ output("AND"); }
"!"						{ output("NOT"); }
"+="					{ output("ADDITION_AND_ASSIGNMENT"); }
"-="					{ output("SUBTRACTION_AND_ASSIGNMENT"); }
"=="					{ output("EQUALITY"); }
"!="					{ output("NOT_EQUAL"); }
"->"					{ output("SELF_REFERENCE"); }
"<<"|">>"				{ output("INSERTION_OPERATOR"); }
">"|"<"|">="|"<="		{ output("RELATIONAL_OPERATOR"); }


"'"				{ output("CHARACTER_START/END"); }
":"				{ output("COLON"); }
"("				{ output("LEFT_PARANTHESIS"); }
"_"				{ output("UNDERSCORE");}
")"				{ output("RIGHT_PARANTHESIS"); }
"]"				{ output("LEFT_BRACKET"); }
"["				{ output("RIGHT_BRACKET"); }
"{"				{ output("LEFT_BRACES"); }
"}"				{ output("RIGHT_BRACES"); }
";"				{ output("SEMI-COLON"); }
"."				{ output("DOT/DECIMAL"); }
","				{ output("COMMA"); }
"="				{ output("ASSIGNMENT"); }
"&"				{ output("REFERENCE"); }
"~"				{ output("DESTRUCTOR_CALL"); }


{float} 		{ output("FLOATING_NUMBER"); }
{IDENTIFIER} 	{ output("IDENTIFIER"); }
{ICONST} 		{ output("INT_CONST"); }
{FCONST} 		{ output("FLOAT_CONST"); }
{CCONST} 		{ output("CHAR_CONST"); }
{STRING} 		{ output("STRING"); }
{HEADER} 		{ output("HEADER_FILE"); }


"\n"			{ lineno += 1; }
[ \t\r\f]+			/* eat up whitespace */

.				{ yyerror("Unrecognized character"); }

%%

void output(char *token_type){
	fprintf(OUT, "yytext: %s\ttoken: %s\tlineno: %d\n", yytext, token_type, lineno);
	printf("yytext: %s\ttoken: %s\tlineno: %d\n", yytext, token_type, lineno);

	// fclose(out);
}

void yyerror(char *message){
	printf("Error: \"%s\" in line %d. Token = %s\n", message, lineno, yytext);
	exit(1); 
}

int main(int argc, char *argv[]){
	yyin=fopen("OOP.cpp","r");
	OUT = fopen("output.txt", "w");

	yylex();

	fclose(yyin);

	return 0;
}