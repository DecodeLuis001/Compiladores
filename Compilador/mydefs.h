	enum VARTYPES{
		VOIDVAL = 1,
		CHARVAL,
		UCHARVAL,
		SCHARVAL,
		SHORTVAL,
		USHORTVAL,
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
	
    typedef union VALUE
    {
        char charval;
        int intval;
        float floatval;
        double doubleval;
    } VALUE;
    

    typedef struct VAR_DATA
    {
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
    