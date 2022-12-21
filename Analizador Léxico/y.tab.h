enum yytokentype
    {
        AUTO = 258, 
        BREAK,
        CASE,
        CHAR,
        CONST,
        CONTINUE,
        DEFAULT,
        DO,
        DOUBLE,
        ELSE,
        ENUM,
        EXTERN,
        FLOAT,
        FOR,
        GOTO,
        IF,
        INT,
        LONG,
        REGISTER,
        RETURN,
        SHORT,
        SIGNED,
        SIZEOF,
        STATIC,
        STRUCT,
        SWITCH,
        TYPEDEF,
        UNION,
        UNSIGNED,
        VOID,
        VOLATILE,
        WHILE,
        IDENTIFIER,
        CONSTANT,
        STRING_LITERAL, 
        ELLIPSIS,
        RIGHT_ASSIGN,
        LEFT_ASSIGN,
        ADD_ASSIGN,
        SUB_ASSIGN,
        MUL_ASSIGN,
        DIV_ASSIGN,
        MOD_ASSIGN,
        AND_ASSIGN,
        XOR_ASSIGN,
        OR_ASSIGN,
        RIGHT_OP,
        LEFT_OP,
        INC_OP,
        DEC_OP,
        PTR_OP,
        AND_OP,
        OR_OP,
        LE_OP,
        GE_OP,
        EQ_OP,
        NE_OP
    };

    union  YYSTYPE
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
};
typedef union YYSTYPE YYSTYPE;