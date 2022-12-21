/* Definir los tipos de variables y símbolos */
struct symrec
	{	
		std::string name; /* name of symbol */
		int size;
		int init;
		int typ;
		int offset; /* data offset */
		struct {
			int func_type;
			std::list<struct symrec *> *sym_table;
		} func_desc;
		std::list<int > *dimlist;
	};

typedef struct symrec symrec;

enum VARTYPES
	{
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

typedef union VALUE {
		char charval;
		int intval;
		float floatval;
		double doubleval;
	} VALUE;

typedef struct VAR_DATA {
	std::string *name;
	VALUE val;
	int init;
	int typ;
	symrec *var;
	symrec *var2;
	int plevel;
	std::list<int> *truelist;
	std::list<int> *falselist;
	std::list<VAR_DATA *> *arglist;
	std::list<int > *dimlist;
} VAR_DATA;

typedef struct CASE_DATA {
	VALUE val;
	int typ;
	int addr;
} CASE_DATA;

typedef struct GOTO_DATA {
	std::string *name;
	int addr;
} GOTO_DATA;
