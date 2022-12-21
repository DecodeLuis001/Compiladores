%{
#include <stdio.h>
#include <string>
#include <list>

struct symrec{
		std::string name; /*name of symbol*/
		int size;	/*Indicar el tamano en bytes que ocupa de espacio la variable*/
		int init;	/*si el simbolo es inicializado*/
		int typ;	/*indicar tipo de la variable o funcion*/
		int offset;	/*offset en bloque de datos donde estan los datos de la variable*/
		struct{		/*Guardar informacion sobre argumentos de entrada de una funcion*/
			int func_type;	/*Indicar el tipo de valor de retorno*/
			std::list<struct symrec *> *sym_table;
		} func_desc;
	};

	typedef struct symrec symrec;

    typedef union VALUE{
		char charval;
		int intval;
		float floatval;
		double doubleval;
	} VALUE;

	typedef struct VAR_DATA{
	std::string *name;
	VALUE val;
	int init;
	int typ;
	symrec *var;
	symrec *var2;
	std::list<int> *truelist;
	std::list<int> *falselist;
	std::list<VAR_DATA *> *arglist;
	} VAR_DATA;

    typedef struct CASE_DATA{
		VALUE val;
		int typ;
		int addr;
	} CASE_DATA;

#include "y.tab.h"
#include<ctype.h>
#include<malloc.h>
int yylex();
void comment();
int check_type();
/*Para el tipo del token CONSTANT*/
/*#define INTVAL 0
#define DOUBLEVAL 1
#define CHARVAL 2*/
/*Definir los tipos de variables*/
enum VARTYPES{
		VOIDVAL = 1,
		CHARVAL,
		UCHARVAL,
		SCHARVAL,
		SHORTVAL,
		USHIRTVAL,
		INTVAL,
		UINTVAL,
		LONGVAL,
		ULONGVAL,
		FVAL,
		DOUBLEVAL,
		LDOUBLEVAL,
		STRVAL,
		STRUCVAL,
		UNIONVAL,
		ENUMVAL,
		TYPENM
	};

    

char *buffer = NULL;
int buffer_size = 0;
#define isodigit(x) ((x) >= '0' && (x) <='7')
#define hextoint(x) (isdigit((x)) ? (x) - '0' : ((x) - 'A') + 10)
extern void yyerror(const char *message);
#define YY_USER_ACTION {yylloc.first_column = yylloc.last_column + 1; yylloc.last_column = yylloc.first_column + yyleng - 1;}
%}

D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*
hex         (x|X)[0-9a-fA-F]{1,2}
oct         [0-7]{1,3}
%x INSTRING INCHAR

%%
"/*"			{ comment(); }

"auto"			{return(AUTO); }
"break"			{return(BREAK); }
"case"			{return(CASE); }
"char"			{return(CHAR); }
"const"			{return(CONST); }
"continue"		{return(CONTINUE); }
"default"		{return(DEFAULT); }
"do"			{return(DO); }
"double"		{return(DOUBLE); }
"else"			{return(ELSE); }
"enum"			{return(ENUM); }
"extern"		{return(EXTERN); }
"float"			{return(FLOAT); }
"for"			{return(FOR); }
"goto"			{return(GOTO); }
"if"			{return(IF); }
"int"			{return(INT); }
"long"			{return(LONG); }
"register"		{return(REGISTER); }
"return"		{return(RETURN); }
"short"			{return(SHORT); }
"signed"		{return(SIGNED); }
"sizeof"		{return(SIZEOF); }
"static"		{return(STATIC); }
"struct"		{return(STRUCT); }
"switch"		{return(SWITCH); }
"typedef"		{return(TYPEDEF); }
"union"			{return(UNION); }
"unsigned"		{return(UNSIGNED); }
"void"			{return(VOID); }
"volatile"		{return(VOLATILE); }
"while"			{return(WHILE); }

{L}({L}|{D})*		    {   yylval.token.name = strdup(yytext); 
                            
                            return(check_type()); 
                        }

0[xX]{H}+{IS}?		    {   yylval.token.ival = strtol(yytext,NULL,16); 
                            yylval.token.type = INTVAL;

                            return(CONSTANT); 
                        }

0{D}+{IS}?		        {   yylval.token.ival = strtol(yytext,NULL,8);
                            yylval.token.type = INTVAL;
                            
                            return(CONSTANT); 
                        }
{D}+{IS}?		        {   yylval.token.ival = atol(yytext);
                            yylval.token.type = INTVAL; 

                            return(CONSTANT); 
                        }

{D}+{E}{FS}?		    {   yylval.token.dval = atof(yytext);
                            yylval.token.type = DOUBLEVAL;

                            return(CONSTANT); 
                        }

{D}*"."{D}+({E})?{FS}?	{   yylval.token.dval = atof(yytext);
                            yylval.token.type = DOUBLEVAL;

                            return(CONSTANT); 
                        }

{D}+"."{D}*({E})?{FS}?	{   yylval.token.dval = atof(yytext);
                            yylval.token.type = DOUBLEVAL;

                            return(CONSTANT); 
                        }

L?\"                    {   buffer = (char *)malloc(1);
                            buffer_size = 1; 
                            strcpy(buffer,""); 
                            BEGIN(INSTRING);
                        }

L?\'                    {   buffer = (char *)malloc(1);
                            buffer_size = 1; 
                            strcpy(buffer,""); 
                            BEGIN(INCHAR);
                        }

<INSTRING,INCHAR>\n     {   yyerror("Unterminates character or string literal");
                            free(buffer);
                            BEGIN(INITIAL);
                        }

<INSTRING,INCHAR><<EOF>> {   yyerror("EOF in string");
                            free(buffer);
                            BEGIN(INITIAL);
                        }

<INSTRING,INCHAR>[^\\\n"'] {buffer = (char *)realloc(buffer,buffer_size+yyleng+1);
                            buffer_size += yyleng;
                            strcat(buffer,yytext);
                            if(YY_START==INCHAR && buffer_size>2)
                                yyerror("Illegal length of character literal");
                            }
<INSTRING>\\\n          /*Ignore this*/

<INSTRING,INCHAR>\\{hex} {  int temp = 0, loop = 0;
                            for(loop=yyleng-2; loop>0; loop--){
                                temp <<= 4;
                                temp += hextoint(toupper(yytext[yyleng-loop]));
                            }
                            buffer = (char *)realloc(buffer,buffer_size+1);
                            buffer[buffer_size-1] = temp;
                            buffer[buffer_size] = '\0';
                            buffer_size += 1;
                            if(YY_START==INCHAR && buffer_size>2)
                                yyerror("Illegal length of character literal");
                            }

<INSTRING,INCHAR>\\{oct} {  int temp = 0, loop = 0;
                            for(loop=yyleng-1; loop>0; loop--){
                                temp <<= 3;
                                temp += (yytext[yyleng-loop] - '0');
                            }
                            buffer = (char *)realloc(buffer,buffer_size+1);
                            buffer[buffer_size-1] = temp;
                            buffer[buffer_size] = '\0';
                            buffer_size += 1;
                            if(YY_START==INCHAR && buffer_size>2)
                                yyerror("Illegal length of character literal");
                            }

<INSTRING,INCHAR>\\[^\n] {  buffer = (char *)realloc(buffer, buffer_size+1);
                            switch(yytext[yyleng-1]){
                                case 'b' : buffer[buffer_size-1] = '\b'; break;
                                case 't' : buffer[buffer_size-1] = '\t'; break;
                                case 'n' : buffer[buffer_size-1] = '\n'; break;
                                case 'v' : buffer[buffer_size-1] = '\v'; break;
                                case 'f' : buffer[buffer_size-1] = '\f'; break;
                                case 'r' : buffer[buffer_size-1] = '\r'; break;
                                default  : buffer[buffer_size-1] = yytext[yyleng-1]; 
                            }
                            buffer[buffer_size] = '\0';
                            buffer_size += 1;
                            if(YY_START==INCHAR && buffer_size>2)
                                yyerror("Illegal length of character literal");
                        }

<INSTRING,INCHAR>\"     {   if(YY_START==INSTRING){
                                yylval.token.str = buffer;
                                yylval.token.type = STRVAL;

                                BEGIN(INITIAL);
                                return(STRING_LITERAL);
                            }
                            buffer = (char *)realloc(buffer,buffer_size+yyleng+1);
                            buffer_size += yyleng;
                            strcat(buffer,yytext);
                            if(buffer_size>2)
                                yyerror("Illegal length of character literal");
                        }

<INSTRING,INCHAR>\'     {   if(YY_START==INCHAR){
                                yylval.token.cval = buffer[0];
                                if(buffer_size>2)
                                    yyerror("Illegal length of character literal");
                                yylval.token.type = CHARVAL;

                                free(buffer);
                                BEGIN(INITIAL);
                                return(CONSTANT);
                            }
                            buffer = (char *)realloc(buffer,buffer_size+yyleng+1);
                            buffer_size += yyleng;
                            strcat(buffer,yytext);
                        }    


"..."			{   return(ELLIPSIS); }
">>="			{   return(RIGHT_ASSIGN); }
"<<="			{   return(LEFT_ASSIGN); }
"+="			{   return(ADD_ASSIGN); }
"-="			{   return(SUB_ASSIGN); }
"*="			{   return(MUL_ASSIGN); }
"/="			{   return(DIV_ASSIGN); }
"%="			{   return(MOD_ASSIGN); }
"&="			{   return(AND_ASSIGN); }
"^="			{   return(XOR_ASSIGN); }
"|="			{   return(OR_ASSIGN); }
">>"			{   return(RIGHT_OP); }
"<<"			{   return(LEFT_OP); }
"++"			{   return(INC_OP); }
"--"			{   return(DEC_OP); }
"->"			{   return(PTR_OP); }
"&&"			{   return(AND_OP); }
"||"			{   return(OR_OP); }
"<="			{   return(LE_OP); }
">="			{   return(GE_OP); }
"=="			{   return(EQ_OP); }
"!="			{   return(NE_OP); }
";"			    {   return(';'); }
("{"|"<%")		{   return('{'); }
("}"|"%>")		{   return('}'); }
","			    {   return(','); }
":"			    {   return(':'); }
"="			    {   return('='); }
"("			    {   return('('); }
")"			    {   return(')'); }
("["|"<:")		{   return('['); }
("]"|":>")		{   return(']'); }
"."			    {   return('.'); }
"&"			    {   return('&'); }
"!"			    {   return('!'); }
"~"			    {   return('~'); }
"-"			    {   return('-'); }
"+"			    {   return('+'); }
"*"			    {   return('*'); }
"/"			    {   return('/'); }
"%"			    {   return('%'); }
"<"			    {   return('<'); }
">"			    {   return('>'); }
"^"			    {   return('^'); }
"|"			    {   return('|'); }
"?"			    {   return('?'); }

[ \t\v\f\r]		{
                }
\n              {   yylloc.first_line++;
                    yylloc.first_column = yylloc.last_column = 0;
                }                
.			{ /* ignore bad characters */ }

%%

int yywrap()
{
	return(1);
}


void comment()
{
	char c, c1;

loop:
	while ((c = yyinput()) != '*' && c != 0)
		if(c=='\n'){
            yylloc.first_line++;
            yylloc.first_column = 0;
        }

	if ((c1 = yyinput()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}

	if (c != 0 && c=='\n'){
        yylloc.first_line++;
        yylloc.first_column = 0;
    }
}


int check_type()
{
/*
* pseudo code --- this is what it should check
*
*	if (yytext == type_name)
*		return(TYPE_NAME);
*
*	return(IDENTIFIER);
*/

/*
*	it actually will only return IDENTIFIER
*/

	return(IDENTIFIER);
}

void printchr(char c){
    if(c == '\a'){
        printf("\\a");
    }
    else if(c == '\b'){
        printf("\\b");
    }
    else if(c == '\f'){
        printf("\\f");
    }
    else if(c == '\n'){
        printf("\\n");
    }
    else if(c == '\r'){
        printf("\\r");
    }
    else if(c == '\t'){
        printf("\\t");
    }
    else if(c == '\v'){
        printf("\\v");
    }
    else
        printf("%c",c);
}

void printstr(char *str){
    char c;
    while((c = *str++) != '\0'){
        printchr(c);
    }
}

const char *stoken[] = {
    "IDENTIFIER",
    "CONSTANT",
    "STRING_LITERAL",
    "SIZEOF",
    "PTR_OP",
    "INC_OP",
    "DEC_OP",
    "LEFT_OP",
    "RIGHT_OP",
    "LE_OP",
    "GE_OP",
    "EQ_OP",
    "NE_OP",
    "AND_OP",
    "OR_OP",
    "MUL_ASSIGN",
    "DIV_ASSIGN",
    "MOD_ASSIGN",
    "ADD_ASSIGN",
    "SUB_ASSIGN",
    "LEFT_ASSIGN",
    "RIGHT_ASSIGN",
    "AND_ASSIGN",
    "XOR_ASSIGN",
    "OR_ASSIGN",
    "TYPE_NAME",
    "TYPEDEF",
    "EXTERN",
    "STATIC",
    "AUTO",
    "REGISTER",
    "CHAR",
    "SHORT",
    "INT",
    "LONG",
    "SIGNED",
    "UNSIGNED",
    "FLOAT",
    "DOUBLE",
    "CONST",
    "VOLATILE",
    "VOID",
    "STRUCT",
    "UNION",
    "ENUM",
    "ELLIPSIS",
    "CASE",
    "DEFAULT",
    "IF",
    "ELSE",
    "SWITCH",
    "WHILE",
    "DO",
    "FOR",
    "GOTO",
    "CONTINUE",
    "BREAK",
    "RETURN"
};
