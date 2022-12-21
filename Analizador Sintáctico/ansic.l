%{
#include <stdio.h>
#include <ctype.h>
#include "ansic.tab.h"
 
//Se aggrean las constantes del switch
enum ATTRTYPES
{
    CHARVAL,
    INTVAL,
    DOUBLEVAL
};
 
void count();
void comment();
void yyerror(char *);
 
YYSTYPE yylval;
int lineno = 0;
/*Sirve para contar la cantidad de columnas.*/
int column = 0; /* Contiene el numero de la columna donde encontro el token. */
 
/*	Count: cuenta todos los carcateres que vaya encpontrnado. */
/* atol: comvierte de texto a numero */
/* strtol: convierte de cualquier base a decimal */
/* atof: convierte de texto a float */
 
//Guardar la cadena que resulta de la conversion
char *buffer = NULL;
int buffer_size = 0;
 
/*#define isdigit(x) ((x) >= '0' && (x) <= '7')*/
/*Convertir un carcater a su equivalente en decimal*/
#define hextoint(x) (isdigit((x)) ? (x) - '0' : ((x) - 'A') + 10)
 
/* Usamos count en todas las reglas para poder localizar con mas precicion un error.*/
%}
 
D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)* 
hex         [0-9a-fA-F]{1,2}
oct         [0-7]{1,3} 

%x INSTRING INCHAR
%option noyywrap 
 
%%
 
"/*"			    { comment(); /* bUSCA EL FIN DE COMENTARIO. */}
^#.*                {   /*IGNORA EL AVANZE DE LINEA*/   }                     
"auto"			    { count(); return(AUTO); }
"break"			    { count(); return(BREAK); }
"case"			    { count(); return(CASE); }
"char"			    { count(); return(CHAR); }
"const"			    { count(); return(CONST); }
"continue"		    { count(); return(CONTINUE); }
"default"		    { count(); return(DEFAULT); }
"do"			    { count(); return(DO); }
"double"		    { count(); return(DOUBLE); }
"else"			    { count(); return(ELSE); }
"enum"			    { count(); return(ENUM); }
"extern"		    { count(); return(EXTERN); }
"float"			    { count(); return(FLOAT); }
"for"			    { count(); return(FOR); }
"goto"			    { count(); return(GOTO); }
"if"			    { count(); return(IF); }
"int"			    { count(); return(INT); }
"long"			    { count(); return(LONG); }
"register"		    { count(); return(REGISTER); }
"return"		    { count(); return(RETURN); }
"short"			    { count(); return(SHORT); }
"signed"		    { count(); return(SIGNED); }
"sizeof"		    { count(); return(SIZEOF); }
"static"		    { count(); return(STATIC); }
"struct"		    { count(); return(STRUCT); }
"switch"		    { count(); return(SWITCH); }
"typedef"		    { count(); return(TYPEDEF); }
"union"			    { count(); return(UNION); }
"unsigned"		    { count(); return(UNSIGNED); }
"void"			    { count(); return(VOID); }
"volatile"		    { count(); return(VOLATILE); }
"while"			    { count(); return(WHILE); }
 
{L}({L}|{D})*		{ count(); yylval.name = strdup(yytext); return(IDENTIFIER); /*Contiene el lexema que fue encontrado*/}
 
0[xX]{H}+{IS}?		{ count(); yylval.ival = strtol(yytext, NULL, 16); yylval.type = INTVAL; return(CONSTANT);}   /*Formato hexadecimal*/   	 
0{D}+{IS}?		    { count(); yylval.ival = strtol(yytext, NULL, 8);  yylval.type = INTVAL; return(CONSTANT);}   /*Constante octal*/             
{D}+{IS}?		    { count(); yylval.ival = atol(yytext); yylval.type = INTVAL; return(CONSTANT);}               /*Constante entera decimal.*/               
L?'             	{   /* se busca el inicio de la constante char. */
                        /*Solo es para un carcater.*/
                        count();
                        buffer = malloc(1);
                        buffer_size = 1;
                        buffer[0] = 0; /*Se limpia el espacio donde esta el carcater*/
                        BEGIN(INCHAR); /*Se inicia que todos los carcateres seguidos del apostrofe se capturen*/
                    }
L?\"                    {
                            count();
                            buffer = malloc(1);
                            buffer_size = 1;
                            strcpy(buffer, "");
                            BEGIN(INSTRING); /*Se inicia que todos los carcateres seguidos del apostrofe se capturen*/
                            printf("Start of  the string\n");
                        }                    
<INCHAR,INSTRING>\n    {
                            count();
                            yyerror("Undeterminated characters of string literal");     
                            free(buffer); /* Se libera el buffer */
                            BEGIN(INITIAL); /* Se regresa al estado inicial */
                        }
<INCHAR,INSTRING><<EOF>>   {
                                count();
                                yyerror("EOF in string literal"); /*Fin de archivo en cadena */ 
                                free(buffer); /* Se libera el buffer */
                                BEGIN(INITIAL); /* Se regresa al estado inicial */
                            }               
<INCHAR,INSTRING>[^\\\n"'] {
                                /*Se busca cualquier carcater alfanumerico, se exculen apostorfes, comillas, saltos de linea, carcateres doble o triples.*/
                                count();
                                buffer = realloc(buffer, buffer_size + yyleng + 1);
                                buffer_size += yyleng; /*Se incrementa el tamaño del buffer*/
                                strcat(buffer, yytext);
                                if(YY_START == INCHAR && buffer_size > 2) /*Si se agrega un carcater demas*/
                                    yyerror("Caracter o literal ilegal.");
                            }
<INSTRING>\\\n              /* ingnore this */                            
<INCHAR,INSTRING>\\{hex}   {
                                count();
                                int temp = 0, loop = 0;
                                for(loop=yyleng-2; loop>0; loop--) /*procesaro digitio a digito*/
                                {
                                    temp <<= 4; /* Recorrimiento de 3 bits */
                                    temp += hextoint(toupper(yytext[yyleng-loop]));
                                }
                                buffer = realloc(buffer, buffer_size+1);
                                buffer[buffer_size-1] = temp;
                                buffer[buffer_size] = '\0';
                                buffer_size += 1;
                                if(YY_START == INCHAR && buffer_size > 2) /*Si se agrega un carcater demas*/
                                    yyerror("Caracter o literal ilegal.");
                            }                   
<INCHAR,INSTRING>\\{oct}   {
                                count();
                                int temp = 0, loop = 0;
                                for(loop=yyleng-2; loop>0; loop--) /*procesaro digitio a digito*/
                                {
                                    temp <<= 4; /* Recorrimiento de 3 bits */
                                    temp += (yytext[yyleng-loop] - '0');
                                }
                                buffer = realloc(buffer, buffer_size+1);
                                buffer[buffer_size-1] = temp;
                                buffer[buffer_size] = '\0';
                                buffer_size += 1;
                                if(YY_START == INCHAR && buffer_size > 2) /*Si se agrega un carcater demas*/
                                    yyerror("Caracter o literal ilegal.");
                            }                               
<INCHAR,INSTRING>\\[^\n]   {
                                count();
                                buffer = realloc(buffer, buffer_size+1); /*Incrementa el tamaño del buffer*/
                                switch(yytext[yyleng-1])
                                {
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
                                if(YY_START == INCHAR && buffer_size > 2)
                                    yyerror("Ilegal lenght of characters constants");
                            }
<INCHAR,INSTRING>'     {
                            count();
                            if(YY_START == INCHAR)
                            {
                                yylval.cval = buffer[0];
                                if(buffer_size > 2)
                                {
                                    yyerror("Ilegal lenght of characters constants");
                                }
                                yylval.type = CHARVAL;
                                free(buffer);
                                BEGIN(INITIAL);
                                return(CONSTANT);
                            }
                            buffer = realloc(buffer, buffer_size + yyleng + 1);
                            buffer_size += yyleng;
                            strcat(buffer, yytext);
                        }
<INSTRING,INCHAR>\"    {
                            count();
                            if(YY_START == INSTRING)
                            {
                                yylval.str = buffer;
                                /*free(buffer);*/
                                BEGIN(INITIAL);
                                return(STRING_LITERAL);
                            }
                            buffer = realloc(buffer, buffer_size + yyleng + 1);
                            buffer_size += yyleng;
                            strcat(buffer, yytext);
                            if(buffer_size > 2)
                                yyerror("Ilegal lenght of characters constants");
                            printf("End of the string\n");
                        }                          
 
{D}+{E}{FS}?		    { count(); yylval.dval = atof(yytext); yylval.type = DOUBLEVAL; return(CONSTANT);    /* constante floar o double. */  }              
{D}*"."{D}+({E})?{FS}?	{ count(); yylval.dval = atof(yytext); yylval.type = DOUBLEVAL; return(CONSTANT);    /* constante floar o double. */}            
{D}+"."{D}*({E})?{FS}?	{ count(); yylval.dval = atof(yytext); yylval.type = DOUBLEVAL; return(CONSTANT); }
 
"..."			{ count(); return(ELLIPSIS); }
">>="			{ count(); return(RIGHT_ASSIGN); }
"<<="			{ count(); return(LEFT_ASSIGN); }
"+="			{ count(); return(ADD_ASSIGN); }
"-="			{ count(); return(SUB_ASSIGN); }
"*="			{ count(); return(MUL_ASSIGN); }
"/="			{ count(); return(DIV_ASSIGN); }
"%="			{ count(); return(MOD_ASSIGN); }
"&="			{ count(); return(AND_ASSIGN); }
"^="			{ count(); return(XOR_ASSIGN); }
"|="			{ count(); return(OR_ASSIGN); }
">>"			{ count(); return(RIGHT_OP); }
"<<"			{ count(); return(LEFT_OP); }
"++"			{ count(); return(INC_OP); }
"--"			{ count(); return(DEC_OP); }
"->"			{ count(); return(PTR_OP); }
"&&"			{ count(); return(AND_OP); }
"||"			{ count(); return(OR_OP); }
"<="			{ count(); return(LE_OP); }
">="			{ count(); return(GE_OP); }
"=="			{ count(); return(EQ_OP); }
"!="			{ count(); return(NE_OP); }
";"			    { count(); return(';'); }
("{"|"<%")		{ count(); return('{'); }
("}"|"%>")		{ count(); return('}'); }
","			    { count(); return(','); }
":"			    { count(); return(':'); }
"="			    { count(); return('='); }
"("			    { count(); return('('); }
")"			    { count(); return(')'); }
("["|"<:")		{ count(); return('['); }
("]"|":>")		{ count(); return(']'); }
"."			    { count(); return('.'); }
"&"			    { count(); return('&'); }
"!"			    { count(); return('!'); }
"~"			    { count(); return('~'); }
"-"			    { count(); return('-'); }
"+"			    { count(); return('+'); }
"*"			    { count(); return('*'); }
"/"			    { count(); return('/'); }
"%"			    { count(); return('%'); }
"<"			    { count(); return('<'); }
">"			    { count(); return('>'); }
"^"			    { count(); return('^'); }
"|"			    { count(); return('|'); }
"?"			    { count(); return('?'); }
[ \t\v\n\f]		{ 
                    count(); 
                    if(yytext[0]=='\n')
                    lineno++;
                    /* Cuando se encuentre uno de esos carcateres se checa cual es */  
                }  
.			    { /* ignore bad characters */ } 
%%
 
void yyerror(char *msg)
{
    printf("\n\t Errror lexico: %s en linea: %d, columna: %d\n", msg, lineno+1, column+1);
    exit(1);
} 

/* Busca el fin de comentario y no escirbe nada en consola */
void comment()
{
	char c, c1;

loop:
	while ((c = input()) != '*' && c != 0)
		;

	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}
}

void count()
{
    int i;
    
    for (i = 0; yytext[i] != '\0'; i++)
        if (yytext[i] == '\n')
            column = 0;
        else if (yytext[i] == '\t')
            column += 8 - (column % 8);
        else
            column++;
    
    /* ECHO; */ /*Equivale a un pronft*/
}
