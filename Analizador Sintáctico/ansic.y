%{
#include <stdio.h>
#include <stdlib.h> 
extern int yylex();//ya que es una funcion en archivo externo y esta es usada en el analizador sintactico
extern void yyerror(char *);
extern FILE *yyin;

%}
%union
{
    struct
    {
        char cval;
        long int ival;
        double dval;
        char *str;
        char *name;
        int type;
    };
}

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

//Declaracion de las prioridades para el if else
%nonassoc NO_ELSE
%nonassoc ELSE

%start translation_unit
%%

primary_expression
: IDENTIFIER            {printf("primary_expression: IDENTIFIER \n");}
| CONSTANT              {printf("primary_expression: CONSTANT \n");}
| STRING_LITERAL        {printf("primary_expression: STRING_LITERAL \n");}
| '(' expression ')'    {printf("primary_expression: '(' expression ')' \n");}
;

postfix_expression
: primary_expression                                    {printf("postfix_expression: primary_expression \n");}
| postfix_expression '[' expression ']'                 {printf("postfix_expression: postfix_expression '[' expression ']' \n");}
| postfix_expression '(' ')'                            {printf("postfix_expression: postfix_expression '(' ')' \n");}
| postfix_expression '(' argument_expression_list ')'   {printf("postfix_expression: postfix_expression '(' argument_expression_list ')' \n");}
| postfix_expression '.' IDENTIFIER                     {printf("postfix_expression: postfix_expression '.' IDENTIFIER \n");}
| postfix_expression PTR_OP IDENTIFIER                  {printf("postfix_expression: postfix_expression PTR_OP IDENTIFIER \n");}
| postfix_expression INC_OP                             {printf("postfix_expression: postfix_expression INC_OP \n");}
| postfix_expression DEC_OP                             {printf("postfix_expression: postfix_expression DEC_OP \n");}
;

argument_expression_list
: assignment_expression                                 {printf("argument_expression_list: assignment_expression \n");}
| argument_expression_list ',' assignment_expression    {printf("argument_expression_list: argument_expression_list ',' assignment_expression \n");}
;

unary_expression
: postfix_expression                        {printf("unary_expression: postfix_expression \n");}
| INC_OP unary_expression                   {printf("unary_expression: INC_OP unary_expression \n");}
| DEC_OP unary_expression                   {printf("unary_expression: DEC_OP unary_expression \n");}
| unary_operator cast_expression            {printf("unary_expression: unary_operator cast_expression \n");}
| SIZEOF unary_expression                   {printf("unary_expression: SIZEOF unary_expression \n");}
| SIZEOF '(' type_name ')'                  {printf("unary_expression: SIZEOF '(' type_name ')' \n");}
;

unary_operator
: '&' {printf("unary_operator: '&' \n");}
| '*' {printf("unary_operator: '*' \n");}
| '+' {printf("unary_operator: '+' \n");}
| '-' {printf("unary_operator: '-' \n");}
| '~' {printf("unary_operator: '~' \n");}
| '!' {printf("unary_operator: '!' \n");}
;

cast_expression
: unary_expression                          {printf("cast_expression: unary_expression \n");}
| '(' type_name ')' cast_expression         {printf("cast_expression: '(' type_name ')' cast_expression \n");}
;

multiplicative_expression
: cast_expression                               {printf("multiplicative_expression: cast_expression \n");}
| multiplicative_expression '*' cast_expression {printf("multiplicative_expression: multiplicative_expression '*' cast_expression \n");}
| multiplicative_expression '/' cast_expression {printf("multiplicative_expression: multiplicative_expression '/' cast_expression \n");}
| multiplicative_expression '%' cast_expression {printf("multiplicative_expression: multiplicative_expression '%' cast_expression \n");}
;

additive_expression
: multiplicative_expression                         {printf("additive_expression: multiplicative_expression \n");}
| additive_expression '+' multiplicative_expression {printf("additive_expression: additive_expression '+' multiplicative_expression \n");}
| additive_expression '-' multiplicative_expression {printf("additive_expression: additive_expression '-' multiplicative_expression \n");}
;

shift_expression
: additive_expression                               {printf("shift_expression: additive_expression \n");}
| shift_expression LEFT_OP additive_expression      {printf("shift_expression: shift_expression LEFT_OP additive_expression \n");}
| shift_expression RIGHT_OP additive_expression     {printf("shift_expression: shift_expression RIGHT_OP additive_expression \n");}
;

relational_expression
: shift_expression                                  {printf("relational_expression: shift_expression \n");}
| relational_expression '<' shift_expression        {printf("relational_expression: relational_expression '<' shift_expression \n");}
| relational_expression '>' shift_expression        {printf("relational_expression: relational_expression '>' shift_expression \n");}
| relational_expression LE_OP shift_expression      {printf("relational_expression: relational_expression LE_OP shift_expression \n");}
| relational_expression GE_OP shift_expression      {printf("relational_expression: relational_expression GE_OP shift_expression \n");}
;

equality_expression
: relational_expression                             {printf("equality_expression: relational_expression \n");}
| equality_expression EQ_OP relational_expression   {printf("equality_expression: equality_expression EQ_OP relational_expression \n");}
| equality_expression NE_OP relational_expression   {printf("equality_expression: equality_expression NE_OP relational_expression \n");}
;

and_expression
: equality_expression                       {printf("and_expression: equality_expression \n");}
| and_expression '&' equality_expression    {printf("and_expression: and_expression '&' equality_expression \n");}
;

exclusive_or_expression
: and_expression                                {printf("exclusive_or_expression: and_expression \n");}
| exclusive_or_expression '^' and_expression    {printf("exclusive_or_expression: exclusive_or_expression '^' and_expression \n");}
;

inclusive_or_expression
: exclusive_or_expression                               {printf("inclusive_or_expression: exclusive_or_expression \n");}
| inclusive_or_expression '|' exclusive_or_expression   {printf("inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression \n");}
;

logical_and_expression
: inclusive_or_expression                                   {printf("logical_and_expression: inclusive_or_expression \n");}
| logical_and_expression AND_OP inclusive_or_expression     {printf("logical_and_expression: logical_and_expression AND_OP inclusive_or_expression \n");}
; 

logical_or_expression
: logical_and_expression                                {printf("logical_or_expression: logical_and_expression \n");}
| logical_or_expression OR_OP logical_and_expression    {printf("logical_or_expression: logical_or_expression OR_OP logical_and_expression \n");}
;

conditional_expression
: logical_or_expression                                             {printf("conditional_expression: logical_or_expression \n");}
| logical_or_expression '?' expression ':' conditional_expression   {printf("conditional_expression: logical_or_expression '?' expression ':' conditional_expression \n");}
;

assignment_expression
: conditional_expression                                        {printf("assignment_expression: conditional_expression \n");}
| unary_expression assignment_operator assignment_expression    {printf("assignment_expression: unary_expression assignment_operator assignment_expression \n");}
;

assignment_operator
: '='                   {printf("assignment_operator: '=' \n");}
| MUL_ASSIGN            {printf("assignment_operator: MUL_ASSIGN \n");}
| DIV_ASSIGN            {printf("assignment_operator: DIV_ASSIGN \n");}
| MOD_ASSIGN            {printf("assignment_operator: MOD_ASSIGN \n");}
| ADD_ASSIGN            {printf("assignment_operator: ADD_ASSIGN \n");}
| SUB_ASSIGN            {printf("assignment_operator: SUB_ASSIGN \n");}
| LEFT_ASSIGN           {printf("assignment_operator: LEFT_ASSIGN \n");}
| RIGHT_ASSIGN          {printf("assignment_operator: RIGHT_ASSIGN \n");}
| AND_ASSIGN            {printf("assignment_operator: AND_ASSIGN \n");}
| XOR_ASSIGN            {printf("assignment_operator: XOR_ASSIGN \n");}
| OR_ASSIGN             {printf("assignment_operator: OR_ASSIGN \n");}
;

expression
: assignment_expression                 {printf("expression: assignment_expression \n");}
| expression ',' assignment_expression  {printf("expression: expression ',' assignment_expression \n");}
;

constant_expression
: conditional_expression    {printf("constant_expression: conditional_expression \n");}
;

declaration
: declaration_specifiers ';'                        {printf("declaration: declaration_specifiers ';' \n");}
| declaration_specifiers init_declarator_list ';'   {printf("declaration: declaration_specifiers init_declarator_list ';' \n");}
;

declaration_specifiers
: storage_class_specifier                           {printf("declaration_specifiers: storage_class_specifier \n");}
| storage_class_specifier declaration_specifiers    {printf("declaration_specifiers: storage_class_specifier declaration_specifiers \n");}
| type_specifier                                    {printf("declaration_specifiers: type_specifier \n");}
| type_specifier declaration_specifiers             {printf("declaration_specifiers: type_specifier declaration_specifiers \n");}
| type_qualifier                                    {printf("declaration_specifiers: type_qualifier \n");}
| type_qualifier declaration_specifiers             {printf("declaration_specifiers: type_qualifier declaration_specifiers \n");}
;

init_declarator_list
: init_declarator                           {printf("init_declarator_list: init_declarator \n");}
| init_declarator_list ',' init_declarator  {printf("init_declarator_list: init_declarator_list ',' init_declarator \n");}
;

init_declarator
: declarator                        {printf("init_declarator: declarator \n");}
| declarator '=' initializer        {printf("init_declarator: declarator '=' initializer \n");}
;

storage_class_specifier
: TYPEDEF                   {printf("storage_class_specifier: TYPEDEF \n");}
| EXTERN                    {printf("storage_class_specifier: EXTERN \n");}
| STATIC                    {printf("storage_class_specifier: STATIC \n");}
| AUTO                      {printf("storage_class_specifier: AUTO \n");}
| REGISTER                  {printf("storage_class_specifier: REGISTER \n");}
;

type_specifier
: VOID                      {printf("type_specifier: VOID \n");}
| CHAR                      {printf("type_specifier: CHAR \n");}
| SHORT                     {printf("type_specifier: SHORT \n");}
| INT                       {printf("type_specifier: INT \n");}
| LONG                      {printf("type_specifier: LONG \n");}
| FLOAT                     {printf("type_specifier: FLOAT \n");}
| DOUBLE                    {printf("type_specifier: DOUBLE \n");}
| SIGNED                    {printf("type_specifier: SIGNED \n");}
| UNSIGNED                  {printf("type_specifier: UNSIGNED \n");}
| struct_or_union_specifier {printf("type_specifier: struct_or_union_specifier \n");}
| enum_specifier            {printf("type_specifier: enum_specifier \n");}
| TYPE_NAME                 {printf("type_specifier: TYPE_NAME \n");}
;

struct_or_union_specifier
: struct_or_union IDENTIFIER '{' struct_declaration_list '}'    {printf("struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}' \n");}
| struct_or_union '{' struct_declaration_list '}'               {printf("struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}' \n");}
| struct_or_union IDENTIFIER                                    {printf("struct_or_union_specifier: struct_or_union IDENTIFIER \n");}
;

struct_or_union
: STRUCT    {printf("struct_or_union: STRUCT \n");}
| UNION     {printf("struct_or_union: UNION \n");}
;

struct_declaration_list
: struct_declaration                            {printf("struct_declaration_list: struct_declaration \n");}
| struct_declaration_list struct_declaration    {printf("struct_declaration_list: struct_declaration_list struct_declaration \n");}
;

struct_declaration
: specifier_qualifier_list struct_declarator_list ';' {printf("struct_declaration: specifier_qualifier_list struct_declarator_list ';' \n");}
;

specifier_qualifier_list
: type_specifier specifier_qualifier_list   {printf("specifier_qualifier_list: type_specifier specifier_qualifier_list \n");}
| type_specifier                            {printf("specifier_qualifier_list: type_specifier \n");}
| type_qualifier specifier_qualifier_list   {printf("specifier_qualifier_list: type_qualifier specifier_qualifier_list \n");}
| type_qualifier                            {printf("specifier_qualifier_list: type_qualifier \n");}
;

struct_declarator_list
: struct_declarator                                     {printf("struct_declarator_list: struct_declarator \n");}
| struct_declarator_list ',' struct_declarator          {printf("struct_declarator_list: struct_declarator_list ',' struct_declarator \n");}
;

struct_declarator
: declarator                                {printf("struct_declarator: declarator \n");}
| ':' constant_expression                   {printf("struct_declarator: ':' constant_expression \n");}
| declarator ':' constant_expression        {printf("struct_declarator: declarator ':' constant_expression \n");}
;

enum_specifier
: ENUM '{' enumerator_list '}'              {printf("enum_specifier: ENUM '{' enumerator_list '}' \n");}
| ENUM IDENTIFIER '{' enumerator_list '}'   {printf("enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}' \n");}
| ENUM IDENTIFIER                           {printf("enum_specifier: ENUM IDENTIFIER \n");}
;

enumerator_list
: enumerator                        {printf("enumerator_list: enumerator \n");}
| enumerator_list ',' enumerator    {printf("enumerator_list: enumerator_list ',' enumerator \n");}
;

enumerator
: IDENTIFIER                            {printf("enumerator: IDENTIFIER \n");}
| IDENTIFIER '=' constant_expression    {printf("enumerator: IDENTIFIER '=' constant_expression \n");}
;

type_qualifier
: CONST         {printf("type_qualifier: CONST \n");}
| VOLATILE      {printf("type_qualifier: VOLATILE \n");}
;

declarator
: pointer direct_declarator {printf("declarator: pointer direct_declarator \n");}
| direct_declarator         {printf("declarator: direct_declarator \n");}
;

direct_declarator
: IDENTIFIER                                    {printf("direct_declarator: IDENTIFIER \n");}
| '(' declarator ')'                            {printf("direct_declarator: '(' declarator ')' \n");}
| direct_declarator '[' constant_expression ']' {printf("direct_declarator: direct_declarator '[' constant_expression ']' \n");}
| direct_declarator '[' ']'                     {printf("direct_declarator: direct_declarator '[' ']' \n");}
| direct_declarator '(' parameter_type_list ')' {printf("direct_declarator: direct_declarator '(' parameter_type_list ')' \n");}
| direct_declarator '(' identifier_list ')'     {printf("direct_declarator: direct_declarator '(' identifier_list ')' \n");}
| direct_declarator '(' ')'                     {printf("direct_declarator: direct_declarator '(' ')' \n");}
;

pointer
: '*'                               {printf("pointer: '*' \n");}
| '*' type_qualifier_list           {printf("pointer: '*' type_qualifier_list \n");}
| '*' pointer                       {printf("pointer: '*' pointer \n");}
| '*' type_qualifier_list pointer   {printf("pointer: '*' type_qualifier_list pointer \n");}
;

type_qualifier_list
: type_qualifier                        {printf("type_qualifier_list: type_qualifier \n");}
| type_qualifier_list type_qualifier    {printf("type_qualifier_list: type_qualifier_list type_qualifier \n");}
;

parameter_type_list
: parameter_list                    {printf("parameter_type_list: parameter_list \n");}
| parameter_list ',' ELLIPSIS       {printf("parameter_type_list: parameter_list ',' ELLIPSIS \n");}
;

parameter_list
: parameter_declaration                     {printf("parameter_list: parameter_declaration \n");}
| parameter_list ',' parameter_declaration  {printf("parameter_list: parameter_list ',' parameter_declaration \n");}
;

parameter_declaration
: declaration_specifiers declarator             {printf("parameter_declaration: declaration_specifiers declarator \n");}
| declaration_specifiers abstract_declarator    {printf("parameter_declaration: declaration_specifiers abstract_declarator \n");}
| declaration_specifiers                        {printf("parameter_declaration: declaration_specifiers \n");}
;

identifier_list
: IDENTIFIER                        {printf("identifier_list: IDENTIFIER \n");}
| identifier_list ',' IDENTIFIER    {printf("identifier_list: identifier_list ',' IDENTIFIER \n");}
;

type_name
: specifier_qualifier_list                      {printf("type_name: pecifier_qualifier_list \n");}
| specifier_qualifier_list abstract_declarator  {printf("type_name: specifier_qualifier_list abstract_declarator \n");}
;

abstract_declarator
: pointer                                   {printf("abstract_declarator: pointer \n");}
| direct_abstract_declarator                {printf("abstract_declarator: direct_abstract_declarator \n");}
| pointer direct_abstract_declarator        {printf("abstract_declarator: pointer direct_abstract_declarator \n");}
;

direct_abstract_declarator
: '(' abstract_declarator ')'                               {printf("direct_abstract_declarator: '(' abstract_declarator ')' \n");}
| '[' ']'                                                   {printf("direct_abstract_declarator: '[' ']' \n");}
| '[' constant_expression ']'                               {printf("direct_abstract_declarator: '[' constant_expression ']' \n");}
| direct_abstract_declarator '[' ']'                        {printf("direct_abstract_declarator: direct_abstract_declarator '[' ']' \n");}
| direct_abstract_declarator '[' constant_expression ']'    {printf("direct_abstract_declarator: direct_abstract_declarator '[' constant_expression ']' \n");}
| '(' ')'                                                   {printf("direct_abstract_declarator: '(' ')' \n");}
| '(' parameter_type_list ')'                               {printf("direct_abstract_declarator: '(' parameter_type_list ')' \n");}
| direct_abstract_declarator '(' ')'                        {printf("direct_abstract_declarator: direct_abstract_declarator '(' ')' \n");}
| direct_abstract_declarator '(' parameter_type_list ')'    {printf("direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')' \n");}
;

initializer
: assignment_expression             {printf("initializer: assignment_expression \n");}
| '{' initializer_list '}'          {printf("initializer: '{' initializer_list '}' \n");}
| '{' initializer_list ',' '}'      {printf("initializer: '{' initializer_list ',' '}' \n");}
;

initializer_list
: initializer                       {printf("initializer_list: initializer \n");}
| initializer_list ',' initializer  {printf("initializer_list: initializer_list ',' initializer \n");}
;

statement
: labeled_statement             {printf("statement: labeled_statement \n");}
| compound_statement            {printf("statement: compound_statement \n");}
| expression_statement          {printf("statement: expression_statement \n");}
| selection_statement           {printf("statement: selection_statement \n");}
| iteration_statement           {printf("statement: iteration_statement \n");}
| jump_statement                {printf("statement: jump_statement \n");}
;

labeled_statement
: IDENTIFIER ':' statement                  {printf("labeled_statement: IDENTIFIER ':' statement \n");}
| CASE constant_expression ':' statement    {printf("labeled_statement: CASE constant_expression ':' statement \n");}
| DEFAULT ':' statement                     {printf("labeled_statement: DEFAULT ':' statement \n");}
;

compound_statement
: '{' '}'                                   {printf("compound_statement: '{' '}' \n");}
| '{' statement_list '}'                    {printf("compound_statement: '{' statement_list '}' \n");}
| '{' declaration_list '}'                  {printf("compound_statement: '{' declaration_list '}' \n");}
| '{' declaration_list statement_list '}'   {printf("compound_statement: '{' declaration_list statement_list '}' \n");}
;

declaration_list
: declaration                       {printf("declaration_list: declaration \n");}
| declaration_list declaration      {printf("declaration_list: declaration_list declaration \n");}
;

statement_list
: statement                     {printf("statement_list: statement \n");}
| statement_list statement      {printf("statement_list: statement_list statement \n");}
;

expression_statement
: ';'               {printf("expression_statement: ';' \n");}
| expression ';'    {printf("expression_statement: expression ';' \n");}
;

selection_statement
: IF '(' expression ')' statement %prec NO_ELSE     {printf("selection_statement: IF '(' expression ')' statement \n");}
| IF '(' expression ')' statement ELSE statement    {printf("selection_statement: IF '(' expression ')' statement ELSE statement \n");}
| SWITCH '(' expression ')' statement               {printf("selection_statement: SWITCH '(' expression ')' statement \n");}
;


iteration_statement
: WHILE '(' expression ')' statement                                            {printf("iteration_statement: WHILE '(' expression ')' statement \n");}
| DO statement WHILE '(' expression ')' ';'                                     {printf("iteration_statement: DO statement WHILE '(' expression ')' ';' \n");}
| FOR '(' expression_statement expression_statement ')' statement               {printf("iteration_statement: FOR '(' expression_statement expression_statement ')' statement \n");}
| FOR '(' expression_statement expression_statement expression ')' statement    {printf("iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement \n");}
;

jump_statement
: GOTO IDENTIFIER ';'       {printf("jump_statement: GOTO IDENTIFIER ';' \n");}
| CONTINUE ';'              {printf("jump_statement: CONTINUE ';' \n");}
| BREAK ';'                 {printf("jump_statement: BREAK ';' \n");}
| RETURN ';'                {printf("jump_statement: RETURN ';' \n");}
| RETURN expression ';'     {printf("jump_statement: RETURN expression ';' \n");}
;

translation_unit
: external_declaration                      {printf("translation_unit: external_declaration \n");}
| translation_unit external_declaration     {printf("translation_unit: translation_unit external_declaration \n");}
;

external_declaration
: function_definition               {printf("external_declaration: function_definition \n");}
| declaration                       {printf("external_declaration: declaration \n");}
;

function_definition
: declaration_specifiers declarator declaration_list compound_statement {printf("function_definition: declaration_specifiers declarator declaration_list compound_statement\n");}
| declaration_specifiers declarator compound_statement                  {printf("function_definition: declaration_specifiers declarator compound_statement \n");}
| declarator declaration_list compound_statement                        {printf("function_definition: declarator declaration_list compound_statement \n");}
| declarator compound_statement                                         {printf("function_definition: declarator compound_statement \n");}
;
%%

int main(int argc, char *argv[])
{
    if(argc>1)
    {
        yyin = fopen(argv[1],"rt");
    }
    yyparse();
}

