typedef struct CONST_DATA {
	VALUE val;
	int typ;
} CONST_DATA;

struct labrec
{   std::string name; /* name of label */
	int instr;   /* instruction offset */
};
std::list<labrec *> lab_table;

// Definir operadores de código de representación intermedia
// y = x				STORE_IR
// y[i] = x				STOREA_IR
// y = x[i]				LOADA_IR
// z = x + y    		ADD_IR
// z = x - y    		SUB_IR
// z = x * y    		MULT_IR
// z = x / y    		DIV_IR
// y = - x				MINUS_IR
// z = x % y    		MOD_IR
// x = ++ x				INC_IR
// x = -- x				DEC_IR
// y = &x				ADDRESS_IR
// y = * x				DEREF_IR
// y = ~ x				TWOCOMP_IR
// y = ! x 				NOT_IR
// y = (int) x			INT_IR
// y = (float) x		FLOAT_IR
// y = (char) x			CHAR_IR
// z = x << y			LSHIFT_IR
// z = x >> y			RSHIFT_IR
// z = x & y			AND_IR
// z = x | y			OR_IR
// z = x ^ y			XOR_IR
// ret x				RET_IR
// proc x				PROC_IR
// endproc				ENDPROC_IR
// y = call p,n			CALL_IR
// param x				PARAM_IR
// if x == y GOTO L		IF_EQ_IR
// if x != y GOTO L		IF_NE_IR
// if x < y GOTO L		IF_LT_IR
// if x <= y GOTO L		IF_LE_IR
// if x > y GOTO L		IF_GT_IR
// if x >= y GOTO L		IF_GE_IR
// GOTO L				GOTO_IR

/* Códigos de representación intermedia */
enum code_ops { STORE_IR, STOREA_IR, LOADA_IR, IF_EQ_IR, IF_NE_IR, IF_LT_IR, IF_GT_IR, IF_LE_IR, IF_GE_IR, GOTO_IR,
                ADD_IR, SUB_IR, MULT_IR, DIV_IR, 
                MINUS_IR, MOD_IR, INC_IR, DEC_IR, ADDRESS_IR,
                DEREF_IR, TWOCOMP_IR, NOT_IR, INT_IR, FLOAT_IR, CHAR_IR, DOUBLE_IR,
                LSHIFT_IR, RSHIFT_IR, AND_IR, OR_IR, XOR_IR, RET_IR, PROC_IR, ENDPROC_IR, CALL_IR, PARAM_IR
};

typedef struct 
{
    enum code_ops op;
    symrec *arg1;
    symrec *arg2;
    symrec *result;
} quad;

/* Arreglo para almacenar código intermedio */
quad code[999];

int nextinstr = 0; /* Initial offset in code array */

/* Generar código intermedio para instrucción de la forma 
   "result = arg1 operation arg2"
   La instrucción es generada como un cuádrupe y es colocada en el arreglo code.
   arg1, arg2 y result deben ser punteros a estructuras symrec de la tabla de símbolos
  */
void gencode(enum code_ops operation, symrec *arg1, symrec *arg2, symrec *result)
{ 
	code[nextinstr].op = operation;
	code[nextinstr].arg1 = arg1;
	code[nextinstr].arg2 = arg2;
	code[nextinstr++].result = result;
}

/* Generar código intermedio para instrucción de la forma 
   "operation arg"
   La instrucción es generada como un cuádrupe y es colocada en el arreglo code.
   arg debe ser puntero a una estructura symrec de la tabla de símbolos
  */
void gencode(enum code_ops operation, symrec *arg)
{ 
	code[nextinstr].op = operation;
	code[nextinstr].arg1 = arg;
	code[nextinstr].arg2 = NULL;
	code[nextinstr++].result = NULL;
}

/* Generar código intermedio para instrucción de la forma 
   "IF arg1 GOTO lbl"
   La instrucción es generada como un cuádrupe y es colocada en el arreglo code.
   arg1 debe ser puntero a una estructura symrec de la tabla de símbolos
   lbl debe ser una posición en el arreglo code
  */
void gencode(enum code_ops operation, symrec *arg1, int lbl)
{ 
	symrec *ptr;
	ptr = (symrec *) malloc (sizeof(symrec));
	ptr->name = "";
	ptr->offset = lbl;
	code[nextinstr].op = operation;
	code[nextinstr].arg1 = arg1;
	code[nextinstr].arg2 = NULL;
	code[nextinstr++].result = ptr;
}

/* Generar código intermedio para instrucción de la forma:
    "IF arg1 op arg2 GOTO lbl"
   La instrucción es generada como un cuádrupe y es colocada en el arreglo code.
   arg1 y arg2 deben ser punteros a estructuras symrec de la tabla de símbolos
   lbl debe ser una posición en el arreglo code
  */
void gencode(enum code_ops operation, symrec *arg1, symrec *arg2, int lbl)
{ 
	symrec *ptr;
	ptr = new symrec();
	ptr->name = "";
	ptr->offset = lbl;
	code[nextinstr].op = operation;
	code[nextinstr].arg1 = arg1;
	code[nextinstr].arg2 = arg2;
	code[nextinstr++].result = ptr;
}

/* Generar código intermedio para instrucción de la forma "GOTO lbl"
   La instrucción es generada como un cuádrupe y es colocada en el arreglo code.
   lbl debe ser una posición en el arreglo code
  */
void gencode(enum code_ops operation, int lbl)
{ 
	symrec *ptr;
	ptr = new symrec();
	ptr->name = "";
	ptr->offset = lbl;
	code[nextinstr].op = operation;
	code[nextinstr].arg1 = NULL;
	code[nextinstr].arg2 = NULL;
	code[nextinstr++].result = ptr;
}

void gencode(enum code_ops operation)
{ 
	code[nextinstr].op = operation;
	code[nextinstr].arg1 = NULL;
	code[nextinstr].arg2 = NULL;
	code[nextinstr++].result = NULL;
}

/* Generates code at a reserved location */
void backpatch(int addr, enum code_ops operation, symrec *arg, int lbl)
{
	symrec *ptr = code[addr].result;
	if(ptr == NULL) {
		ptr = new symrec();
		ptr->name = "";
	}
	ptr->offset = lbl;
	code[addr].op = operation;
	code[addr].arg1 = arg;
	/*code[addr].arg2 = NULL;*/
	code[addr].result = ptr;
}

void backpatch(int addr, enum code_ops operation, int lbl)
{
	symrec *ptr = code[addr].result;
	if(ptr == NULL) {
		ptr = new symrec();
		ptr->name = "";
	}
	ptr->offset = lbl;
	code[addr].op = operation;
	/*code[addr].arg1 = NULL;
	code[addr].arg2 = NULL;*/
	code[addr].result = ptr;
}

void backpatch(std::list<int> *addrlist, enum code_ops operation, int lbl)
{
	symrec *ptr;
	int addr;
	std::list<int>::iterator it;
	if(addrlist != NULL) 
	{
		for(it = addrlist->begin(); it != addrlist->end(); it++) 
		{
			addr = *it;
			symrec *ptr = code[addr].result;
			if(ptr == NULL) {
				ptr = new symrec();
				ptr->name = "";
			}
			ptr->offset = lbl;
			code[addr].op = operation;
			/*code[addr].arg1 = NULL;
			code[addr].arg2 = NULL;*/
			code[addr].result = ptr;
		}
	}
}

void backpatch(std::list<int> *addrlist, int lbl)
{
	symrec *ptr;
	int addr;
	std::list<int>::iterator it;
	if(addrlist != NULL) 
	{
		for(it = addrlist->begin(); it != addrlist->end(); it++) 
		{
			addr = *it;
			symrec *ptr = code[addr].result;
			if(ptr == NULL) {
				ptr = new symrec();
				ptr->name = "";
			}
			ptr->offset = lbl;
			code[addr].result = ptr;
		}
	}
}

std::list<int> *makelist(int i)
{
	return new std::list<int>(1, i);

}

std::list<GOTO_DATA *> *makelist(string *name, int i)
{
	GOTO_DATA *el = new GOTO_DATA;
	el->name = name;
	el->addr = i;
	return new std::list<GOTO_DATA *>(1, el);
}

std::list<int> *merge(std::list<int> *p1, std::list<int> *p2)
{
	std::list<int> *ptr;
	if(p1 == NULL)
		return p2;
	if(p2 == NULL)
		return p1;
	ptr = p1;
	ptr->insert(ptr->end(), p2->begin(), p2->end());
	return ptr;
}

std::list<int> *merge(std::list<int> *p1, std::list<int> *p2, std::list<int> *p3)
{   std::list<int> *ptr;
	if(p1 == NULL)
		return merge(p2, p3);
	if(p2 == NULL)
		return merge(p1, p3);
	if(p3 == NULL)
		return merge(p1, p2);
	ptr = p1;
	ptr->insert(ptr->end(), p2->begin(), p2->end());
	ptr->insert(ptr->end(), p3->begin(), p3->end());
	return ptr;
}

std::list<CONST_DATA *> *merge(std::list<CONST_DATA *> *p1, std::list<CONST_DATA *> *p2)
{   std::list<CONST_DATA *> *ptr;
	if(p1 == NULL)
		return p2;
	if(p2 == NULL)
		return p1;
	ptr = p1;
	ptr->insert(ptr->end(), p2->begin(), p2->end());
	return ptr;
}

std::list<CASE_DATA *> *merge(std::list<CASE_DATA *> *p1, std::list<CASE_DATA *> *p2)
{   std::list<CASE_DATA *> *ptr;
	if(p1 == NULL)
		return p2;
	if(p2 == NULL)
		return p1;
	ptr = p1;
	ptr->insert(ptr->end(), p2->begin(), p2->end());
	return ptr;
}

std::list<GOTO_DATA *> *merge(std::list<GOTO_DATA *> *p1, std::list<GOTO_DATA *> *p2)
{
	std::list<GOTO_DATA *> *ptr;
	if (p1 == NULL)
		return p2;
	if (p2 == NULL)
		return p1;
	ptr = p1;
	ptr->insert(ptr->end(), p2->begin(), p2->end());
	return ptr;
}

/* Buscar etiqueta en entorno local */
labrec *getlab(const std::string *lab_name)
{
	std::list<labrec *>::iterator it;
	for(it = lab_table.begin(); it != lab_table.end(); it++) 
	{
		if((*it)->name == *lab_name)
			return *it;
	}
	return NULL;
}

labrec *putlab(const std::string *lab_name)
{
	labrec *lbl = new labrec();
	lbl->name = *lab_name;
	lbl->instr = nextinstr;
	lab_table.push_back(lbl);
	return lbl;
}

labrec *putlab(const std::string *lab_name, int i)
{
	labrec *lbl = new labrec();
	lbl->name = *lab_name;
	lbl->instr = i;
	lab_table.push_back(lbl);
	return lbl;
}

void patch_gotos(std::list<GOTO_DATA *> *gotolist)
{
	std::list<GOTO_DATA *>::iterator it;
	labrec *lbl;
	symrec *ptr;
	if (gotolist != NULL) {
		for (it = gotolist->begin(); it != gotolist->end(); it++)
		{
			lbl = getlab((*it)->name);
			if (lbl == nullptr)
				yyerror("GOTO label not found!");
			ptr = new symrec();
			ptr->name = "";
			ptr->offset = lbl->instr;
			code[(*it)->addr].result = ptr;
		}
	}
}


std::list<CASE_DATA *> *makecaselist(VALUE val, int typ, int addr)
{
    CASE_DATA *newstruc = new CASE_DATA();
    newstruc->val = val;
    newstruc->typ = typ;
    newstruc->addr = addr;
    return new std::list<CASE_DATA *>(1, newstruc);
}

std::list<CASE_DATA *> *makecaselist(int addr)
{
    CASE_DATA *newstruc = new CASE_DATA();
    newstruc->typ = VOIDVAL;
    newstruc->addr = addr;
    return new std::list<CASE_DATA *>(1, newstruc);
}


string getname(symrec *sym)
{
	if (isconstant(sym->typ)) {
		int typ = sym->typ & 0x1F;
		switch (typ) {
		case INTVAL:
			return to_string(*(int *)((char *)datablock + sym->offset));
		case FVAL:
			return to_string(*(float *)((char *)datablock + sym->offset));
		case DOUBLEVAL:
			return to_string(*(double *)((char *)datablock + sym->offset));
		default:
			return sym->name;
		}
	}
	else
		return sym->name;
}

void print_icode()
{
	int i = 0;
	std::cout << std::endl;
	while (i < nextinstr) {
		switch(code[i].op)
		{
			case STORE_IR:
				std::cout << i << ": " << code[i].result->name << " = " << getname(code[i].arg1) << std::endl;
				break;
			case STOREA_IR:
				std::cout << i << ": " << code[i].result->name << "[" << getname(code[i].arg2) << "] = " << getname(code[i].arg1) << std::endl;
				break;
			case LOADA_IR:
				std::cout << i << ": " << code[i].result->name << " = " << getname(code[i].arg1) << "[" << getname(code[i].arg2) << "]\n";
				break;
			case IF_LT_IR:
				std::cout << i << ": IF " << getname(code[i].arg1) << " < " << getname(code[i].arg2) << " GOTO " << code[i].result->offset << std::endl;
				break;
			case IF_LE_IR:
				std::cout << i << ": IF " << getname(code[i].arg1) << " <= " << getname(code[i].arg2) << " GOTO " << code[i].result->offset << std::endl;
				break;
			case IF_GT_IR:
				std::cout << i << ": IF " << getname(code[i].arg1) << " > " << getname(code[i].arg2) << " GOTO " << code[i].result->offset << std::endl;
				break;
			case IF_GE_IR:
				std::cout << i << ": IF " << getname(code[i].arg1) << " >= " << getname(code[i].arg2) << " GOTO " << code[i].result->offset << std::endl;
				break;
			case IF_EQ_IR:
				std::cout << i << ": IF " << getname(code[i].arg1) << " == " << getname(code[i].arg2) << " GOTO " << code[i].result->offset << std::endl;
				break;
			case IF_NE_IR:
				std::cout << i << ": IF " << getname(code[i].arg1) << " != " << getname(code[i].arg2) << " GOTO " << code[i].result->offset << std::endl;
				break;
			case GOTO_IR:
				std::cout << i << ": GOTO " << code[i].result->offset << std::endl;
				break;
			case ADD_IR:
				std::cout << i << ": " << code[i].result->name << " = " << getname(code[i].arg1) << " + " << getname(code[i].arg2) << std::endl;
				break;
			case SUB_IR:
				std::cout << i << ": " << code[i].result->name << " = " << getname(code[i].arg1) << " - " << getname(code[i].arg2) << std::endl;
				break;
			case MULT_IR:
				std::cout << i << ": " << code[i].result->name << " = " << getname(code[i].arg1) << " * " << getname(code[i].arg2) << std::endl;
				break;
			case DIV_IR:
				std::cout << i << ": " << code[i].result->name << " = " << getname(code[i].arg1) << " / " << getname(code[i].arg2) << std::endl;
				break;
			case MINUS_IR:
				std::cout << i << ": " << code[i].result->name << " = MINUS " << getname(code[i].arg1) << std::endl;
				break;
			case MOD_IR:
				std::cout << i << ": " << code[i].result->name << " = " << getname(code[i].arg1) << " % " << getname(code[i].arg2) << std::endl;
				break;
			case INC_IR:
				std::cout << i << ": " << code[i].result->name << " = " << getname(code[i].arg1) << " + 1" << std::endl;
				break;
			case DEC_IR:
				std::cout << i << ": " << code[i].result->name << " = " << getname(code[i].arg1) << " - 1" << std::endl;
				break;
			case ADDRESS_IR:
				std::cout << i << ": " << code[i].result->name << " = &" << getname(code[i].arg1) << std::endl;
				break;
			case DEREF_IR:
				std::cout << i << ": " << code[i].result->name << " = *" << getname(code[i].arg1) << std::endl;
				break;
			case TWOCOMP_IR:
				std::cout << i << ": " << code[i].result->name << " = ~" << getname(code[i].arg1) << std::endl;
				break;
			case NOT_IR:
				std::cout << i << ": " << code[i].result->name << " = NOT " << getname(code[i].arg1) << std::endl;
				break;
			case INT_IR:
				std::cout << i << ": " << code[i].result->name << " = (int)" << getname(code[i].arg1) << std::endl;
				break;
			case FLOAT_IR:
				std::cout << i << ": " << code[i].result->name << " = (float)" << getname(code[i].arg1) << std::endl;
				break;
			case LSHIFT_IR:
                std::cout << i << ": " << code[i].result->name << " = " << getname(code[i].arg1) << " << " << getname(code[i].arg2) << std::endl;
				break;
			case RSHIFT_IR:
                std::cout << i << ": " << code[i].result->name << " = " << getname(code[i].arg1) << " >> " << getname(code[i].arg2) << std::endl;
				break;
			case AND_IR:
				std::cout << i << ": " << code[i].result->name << " = " << getname(code[i].arg1) << " AND " << getname(code[i].arg2) << std::endl;
				break;
            case OR_IR:
				std::cout << i << ": " << code[i].result->name << " = " << getname(code[i].arg1) << " OR " << getname(code[i].arg2) << std::endl;
				break;
			case XOR_IR:
				std::cout << i << ": " << code[i].result->name << " = " << getname(code[i].arg1) << " XOR " << code[i].arg2->name << std::endl;
				break;
			case RET_IR:
				if(code[i].arg1 != NULL)
					std::cout << i << ": RETURN " << getname(code[i].arg1) << std::endl;
				else
					std::cout << i << ": RETURN" << std::endl;
				break;
			case PROC_IR:
				if(code[i].arg1 != NULL)
					std::cout << i << ": PROC " << getname(code[i].arg1) << std::endl;
				break;
			case ENDPROC_IR:
				if(code[i].arg1 != NULL)
					std::cout << i << ": ENDPROC " << getname(code[i].arg1) << std::endl;
				break;
			case CALL_IR:
				if(code[i].arg2 == NULL)
					std::cout << i << ": " << code[i].result->name << " = CALL " << getname(code[i].arg1) << std::endl;
				else
					std::cout << i << ": " << code[i].result->name << " = CALL " << getname(code[i].arg1) << ", " << code[i].arg2->offset << std::endl;
				break;
			case PARAM_IR:
				std::cout << i << ": PARAM " << getname(code[i].arg1) << std::endl;
				break;
			default:
				break;
		}
		i++;
	}
	std::cout << std::endl;
}

std::string formatname(std::string name, std::string suffix = "$[ebp]")
{
	if (name[0] != '?')
		return '_' + name + suffix;
	return name;
}

void print_code(std::string iname)
{
	int i, lbl = 0, offset;
	symrec *j;
	unsigned char *labels;
	symrec *ptr;
	char *source;
	symrec * currfunc = NULL;
	std::list<symrec *>::iterator it;
	symboltable *symtable;
	std::ofstream ofh;
	std::string oname;
	std::size_t found;
	found = iname.find_last_of(".");
	oname = iname.substr(0, found);
	oname += ".asm";
	ofh.open(oname);
	if (!ofh.is_open()) {
		std::cout << "Error: Cannot open file " << iname << "for writing\n";
		return;
	}
	ofh << "TITLE	" << iname << "\n";
	ofh << ".686\n";
	ofh << ".XMM\n";
	ofh << ".model 	flat\n";
	/* Buscar posiciones de salto */
	labels = new unsigned char[nextinstr]();
	i = 0;
	while (i < nextinstr) {
		if (code[i].op >= IF_EQ_IR && code[i].op <= GOTO_IR)
		{
			j = code[i].result;
			if (j->offset >= nextinstr) {
				ofh << "ERR invalid jump offset (" << j->offset << ")\n";
				labels[j->offset] = 0;
			}
			else
				labels[j->offset] = 1;
		}
		i++;
	}
	ofh << "_DATA	SEGMENT\n";
	/* Buscar variables globales */
	for (it = sym_table->begin(); it != sym_table->end(); it++)
	{
		if ((((*it)->typ) & VAR_SPEC) != 0)
		{
			(*it)->name = '?' + (*it)->name + "@@";
			if (isarray((*it)->typ))
			{
				if (ischar((*it)->typ))
				{
					ofh << "COMM	" << (*it)->name << ":BYTE:0" << std::hex << (*it)->size << "H\n";
				}
				if (isinteger((*it)->typ))
				{
					ofh << "COMM	" << (*it)->name << ":DWORD:0" << std::hex << (*it)->size / 4 << "H\n";
				}
				if (isfloat((*it)->typ))
				{
					ofh << "COMM	" << (*it)->name << ":DWORD:0" << std::hex << (*it)->size / 4 << "H\n";
				}
			}
			else
			{
				if (ischar((*it)->typ))
				{
					if ((*it)->init)
						ofh << (*it)->name << "\tDB\t0" << std::hex << *(unsigned char *)((char *)datablock + (*it)->offset) << std::dec << "H\n";
					else
						ofh << "COMM	" << (*it)->name << ":DBYTE\n";
				}
				if (isinteger((*it)->typ))
				{
					if ((*it)->init)
						ofh << (*it)->name << "\tDD\t0" << std::hex << *(unsigned int *)((char *)datablock + (*it)->offset) << std::dec << "H\n";
					else
						ofh << "COMM	" << (*it)->name << ":DWORD\n";
				}
				if (isfloat((*it)->typ))
				{
					if ((*it)->init)
						ofh << (*it)->name << "\tDD\t0" << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + (*it)->offset) << std::dec << "r\n";
					else
						ofh << "COMM	" << (*it)->name << ":DWORD\n";
				}
			}
		}
	}
	ofh << "_DATA	ENDS\n";
	ofh << "_CONST	SEGMENT\n";
	/* Buscar constantes float */
	for (it = sym_table->begin(); it != sym_table->end(); it++)
	{
		if (isconstant((*it)->typ))
		{
			if (isfloat((*it)->typ))
			{
				unsigned int val = *(unsigned int *)((char *)datablock + (*it)->offset);
				ofh << "__real@" << std::setfill('0') << std::setw(8) << std::hex << val << "	DD	0" << std::setfill('0') << std::setw(8) << val << std::dec << "r\n";
			}
		}
		if (isfunction((*it)->typ))
		{
			std::list<symrec *>::iterator itt;
			symtable = (*it)->func_desc.sym_table;
			if (symtable != NULL)
			{
				for (itt = symtable->begin(); itt != symtable->end(); itt++)
				{
					if (isconstant((*itt)->typ))
					{
						if (isfloat((*itt)->typ))
						{
							unsigned int val = *(unsigned int *)((char *)datablock + (*itt)->offset);
							ofh << "__real@" << std::setfill('0') << std::setw(8) << std::hex << val << "	DD	0" << std::setfill('0') << std::setw(8) << val << std::dec << "r\n";
						}
						if (isstring((*itt)->typ))
						{
							unsigned char *s = ((unsigned char *)datablock + (*itt)->offset);
							int i = 0;
							(*itt)->name = "??" + (*itt)->name + "@@";
							ofh << (*itt)->name << "	DB	";
							while (s[i] != 0)
							{
								if (i>0)
									ofh << ", ";
								if (!iscntrl(s[i]))
								{
									ofh << "\'";
									while (!iscntrl(s[i]))
										ofh << s[i++];
									ofh << "\'";
								}
								else
									ofh << "0" << std::hex << (int)s[i++] << std::dec << "H";
							}
							ofh << ", 00H\n";
						}
					}
				}
			}
		}
	}
	ofh << "_CONST	ENDS\n";
	i = 0;
	while (i < nextinstr) {
		if (labels[i])
			ofh << "$LN" << i << "@" << currfunc->name << ":\n";
		switch (code[i].op) {
		case STORE_IR:
			if (ispointer(code[i].result->typ)) {
				ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << ", OFFSET _" << code[i].arg1->name << "\n";
			}
			else
			if (isfloat(code[i].result->typ)) {
				if (isconstant(code[i].arg1->typ))
					ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
				else
					ofh << "	movss	xmm0, DWORD PTR " << formatname(code[i].arg1->name) << "\n";
				ofh << "	movss	DWORD PTR " << formatname(code[i].result->name) << ", xmm0\n";
			}
			else
			{
				if (isconstant(code[i].arg1->typ))
					ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << ", " << *(int *)((char *)datablock + code[i].arg1->offset) << "\n";
				else
				{
					ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg1->name) << "\n";
					ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << ", eax\n";
				}
			}
			break;
		
		case STOREA_IR:
			if (isfloat(code[i].result->typ)) {
				if (isconstant(code[i].arg1->typ))
					ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
				else
					ofh << "	movss	xmm0, DWORD PTR " << formatname(code[i].arg1->name) << "\n";
				ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
				ofh << "	movss	DWORD PTR " << formatname(code[i].result->name, "$[ebp+eax]") << ", xmm0\n";
			}
			else
			{
				if (isconstant(code[i].arg1->typ))
				{
					ofh << "	mov		eax, DWORD PTR " << formatname(getname(code[i].arg2)) << "\n";
					ofh << "	mov		DWORD PTR " << formatname(code[i].result->name, "$[ebp+eax]") << ", " << *(int *)((char *)datablock + code[i].arg1->offset) << "\n";
				}
				else
				{
					ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
					ofh << "	mov		ebx, DWORD PTR " << formatname(code[i].arg1->name) << "\n";
					ofh << "	mov		DWORD PTR " << formatname(code[i].result->name, "$[ebp+eax]") << ", ebx\n";
				}
			}
			break;
		
		case LOADA_IR:
			if (isfloat(code[i].result->typ)) {
				ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
				ofh << "	movss	xmm0, DWORD PTR _" << code[i].arg1->name << "$[ebp+eax]\n";
				ofh << "	movss	DWORD PTR " << formatname(code[i].result->name) << ", xmm0\n";
			}
			else
			{
				ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
				ofh << "	mov		ebx, DWORD PTR _" << code[i].arg1->name << "$[ebp+eax]\n";
				ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << ", ebx\n";
			}
			break;
		
		case IF_EQ_IR:
			if (isfloat(code[i].arg1->typ)) {
				if (isconstant(code[i].arg1->typ))
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg2->offset) << std::dec << "\n";
						ofh << "	je		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
					else
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	je	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
				else
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg2->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	jne		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
					else
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	je		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
			}
			else
			{
				if (isconstant(code[i].arg1->typ))
				{
					if (isconstant(code[i].arg2->typ)) {
						ofh << "	mov		eax, " << *(int *)((char *)datablock + code[i].arg1->offset) << "\n";
						ofh << "	cmp		eax, " << *(int *)((char *)datablock + code[i].arg2->offset) << "\n";
						ofh << "	je		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
					else
					{
						ofh << "	cmp		DWORD PTR " << formatname(code[i].arg2->name) << ", " << *(int *)((char *)datablock + code[i].arg1->offset) << "\n";
						ofh << "	jne		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
				else
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	cmp		DWORD PTR " << formatname(code[i].arg2->name) << ", " << *(int *)((char *)datablock + code[i].arg2->offset) << "\n";
					}
					else
					{
						ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	cmp		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
					}
					ofh << "	je		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
				}
			}
			break;
		
		case IF_NE_IR:
			if (isfloat(code[i].arg1->typ)) {
				if (isconstant(code[i].arg1->typ))
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg2->offset) << std::dec << "\n";
						ofh << "	jne		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
					else
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	jne		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
				else
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg2->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	je		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
					else
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	jne		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
			}
			else
			{
				if (isconstant(code[i].arg1->typ))
				{
					if (isconstant(code[i].arg2->typ)) {
						ofh << "	mov		eax, " << *(int *)((char *)datablock + code[i].arg1->offset) << "\n";
						ofh << "	cmp		eax, " << *(int *)((char *)datablock + code[i].arg2->offset) << "\n";
						ofh << "	jne		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
					else
					{
						ofh << "	cmp		DWORD PTR " << formatname(code[i].arg2->name) << ", " << *(int *)((char *)datablock + code[i].arg1->offset) << "\n";
						ofh << "	je		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
				else
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	cmp		DWORD PTR " << formatname(code[i].arg2->name) << ", " << *(int *)((char *)datablock + code[i].arg2->offset) << "\n";
					}
					else
					{
						ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	cmp		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
					}
					ofh << "	jne		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
				}
			}
			break;
		
		case IF_LT_IR:
			if (isfloat(code[i].arg1->typ)) {
				if (isconstant(code[i].arg1->typ))
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg2->offset) << std::dec << "\n";
						ofh << "	jl		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
					else
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	jl		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
				else
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg2->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	jnl		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
					else
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	jl		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
			}
			else
			{
				if (isconstant(code[i].arg1->typ))
				{
					if (isconstant(code[i].arg2->typ)) {
						ofh << "	mov		eax, " << *(int *)((char *)datablock + code[i].arg1->offset) << "\n";
						ofh << "	cmp		eax, " << *(int *)((char *)datablock + code[i].arg2->offset) << "\n";
						ofh << "	jl		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
					else
					{
						ofh << "	cmp		DWORD PTR " << formatname(code[i].arg2->name) << ", " << *(int *)((char *)datablock + code[i].arg1->offset) << "\n";
						ofh << "	jnl		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
				else
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	cmp		DWORD PTR " << formatname(code[i].arg2->name) << ", " << *(int *)((char *)datablock + code[i].arg2->offset) << "\n";
					}
					else
					{
						ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	cmp		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
					}
					ofh << "	jl		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
				}
			}
			break;
		
		case IF_GT_IR:
			if (isfloat(code[i].arg1->typ))
			{
				if (isconstant(code[i].arg1->typ))
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg2->offset) << std::dec << "\n";
						ofh << "	jg		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
					else
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	jg		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
				else
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg2->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	jng		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
					else
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	jg		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
			}
			else
			{
				if (isconstant(code[i].arg2->typ))
				{
					if (isconstant(code[i].arg2->typ)) {
						ofh << "	mov		eax, " << *(int *)((char *)datablock + code[i].arg1->offset) << "\n";
						ofh << "	cmp		eax, " << *(int *)((char *)datablock + code[i].arg2->offset) << "\n";
						ofh << "	jg		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
					else
					{
						ofh << "	cmp		DWORD PTR " << formatname(code[i].arg2->name) << ", " << *(int *)((char *)datablock + code[i].arg1->offset) << "\n";
						ofh << "	jng		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
				else
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	cmp		DWORD PTR " << formatname(code[i].arg2->name) << ", " << *(int *)((char *)datablock + code[i].arg2->offset) << "\n";
					}
					else
					{
						ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	cmp		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
					}
					ofh << "	jg		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
				}
			}
			break;
		
		case IF_LE_IR:
			if (isfloat(code[i].arg1->typ)) {
				if (isconstant(code[i].arg1->typ))
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg2->offset) << std::dec << "\n";
						ofh << "	jle		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
					else
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	jle		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
				else
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg2->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	jnle	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
					else
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	jle		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
			}
			else
			{
				if (isconstant(code[i].arg1->typ))
				{
					if (isconstant(code[i].arg2->typ)) {
						ofh << "	mov		eax, " << *(int *)((char *)datablock + code[i].arg1->offset) << "\n";
						ofh << "	cmp		eax, " << *(int *)((char *)datablock + code[i].arg2->offset) << "\n";
						ofh << "	jle		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
					else
					{
						ofh << "	cmp		DWORD PTR " << formatname(code[i].arg2->name) << ", " << *(int *)((char *)datablock + code[i].arg1->offset) << "\n";
						ofh << "	jnle	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
				else
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	cmp		DWORD PTR " << formatname(code[i].arg2->name) << ", " << *(int *)((char *)datablock + code[i].arg2->offset) << "\n";
					}
					else
					{
						ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	cmp		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
					}
					ofh << "	jle		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
				}
			}
			break;
		
		case IF_GE_IR:
			if (isfloat(code[i].arg1->typ)) {
				if (isconstant(code[i].arg1->typ))
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg2->offset) << std::dec << "\n";
						ofh << "	jge		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
					else
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	jge		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
				else
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg2->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	jnge	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
					else
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	comiss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	jge		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
			}
			else
			{
				if (isconstant(code[i].arg1->typ))
				{
					if (isconstant(code[i].arg2->typ)) {
						ofh << "	mov		eax, " << *(int *)((char *)datablock + code[i].arg1->offset) << "\n";
						ofh << "	cmp		eax, " << *(int *)((char *)datablock + code[i].arg2->offset) << "\n";
						ofh << "	jge		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
					else
					{
						ofh << "	cmp		DWORD PTR " << formatname(code[i].arg2->name) << ", " << *(int *)((char *)datablock + code[i].arg1->offset) << "\n";
						ofh << "	jnge	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
				else
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	cmp		DWORD PTR " << formatname(code[i].arg2->name) << ", " << *(int *)((char *)datablock + code[i].arg2->offset) << "\n";
					}
					else
					{
						ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	cmp		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
					}
					ofh << "	jge		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
				}
			}
			break;
		
		case ADD_IR:
			if (isfloat(code[i].result->typ)) {
				if (isconstant(code[i].arg1->typ))
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	addss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg2->offset) << std::dec << "\n";
						ofh << "	movss	DWORD PTR " << formatname(code[i].arg2->name) << ", xmm0" << "\n";
					}
					else
					{
						ofh << "	movss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	addss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	movss	DWORD PTR " << formatname(code[i].arg2->name) << ", xmm0" << "\n";
					}
				}
				else
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	movss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	addss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg2->offset) << std::dec << "\n";
						ofh << "	movss	DWORD PTR " << formatname(code[i].arg2->name) << ", xmm0" << "\n";
					}
					else
					{
						ofh << "	movss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	addss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	movss	DWORD PTR " << formatname(code[i].arg2->name) << ", xmm0" << "\n";
					}
				}
			}
			else
				if (isinteger(code[i].result->typ)) {
					if (isconstant(code[i].arg1->typ))
					{
						if (isconstant(code[i].arg2->typ)) {
							ofh << "	mov		eax, " << *(int *)((char *)datablock + code[i].arg1->offset) + *(int *)((char *)datablock + code[i].arg1->offset) << "\n";
							ofh << "	add		eax, " << *(int *)((char *)datablock + code[i].arg1->offset) + *(int *)((char *)datablock + code[i].arg2->offset) << "\n";
							ofh << "	mov		DWORD PTR " << formatname(code[i].arg2->name) << ", eax" << "\n";
						}
						else
						{
							ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
							ofh << "	add		eax, " << *(int *)((char *)datablock + code[i].arg1->offset) << "\n";
							ofh << "	mov		DWORD PTR " << formatname(code[i].arg2->name) << ", eax" << "\n";
						}
					}
					else
					{
						if (isconstant(code[i].arg2->typ))
						{
							ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
							ofh << "	add		eax, " << *(int *)((char *)datablock + code[i].arg2->offset) << "\n";
							ofh << "	mov		DWORD PTR " << formatname(code[i].arg2->name) << ", eax" << "\n";
						}
						else
						{
							ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
							ofh << "	add		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
							ofh << "	mov		DWORD PTR " << formatname(code[i].arg2->name) << ", eax" << "\n";
						}
					}
				}
			break;
		
		case SUB_IR:
			if (isfloat(code[i].result->typ)) {
				if (isconstant(code[i].arg1->typ))
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	subss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg2->offset) << std::dec << "\n";
						ofh << "	movss	DWORD PTR " << formatname(code[i].arg2->name) << ", xmm0" << "\n";
					}
					else
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	subss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	movss	DWORD PTR " << formatname(code[i].arg2->name) << ", xmm0" << "\n";
					}
				}
				else
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg2->offset) << std::dec << "\n";
						ofh << "	subss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	movss	DWORD PTR " << formatname(code[i].arg2->name) << ", xmm0" << "\n";
					}
					else
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	subss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	movss	DWORD PTR " << formatname(code[i].arg2->name) << ", xmm0" << "\n";
					}
				}
			}
			else
			{
				if (isconstant(code[i].arg1->typ))
				{
					if (isconstant(code[i].arg2->typ)) {
						ofh << "	mov		DWORD PTR " << formatname(code[i].arg2->name) << ", " << *(int *)((char *)datablock + code[i].arg1->offset) - *(int *)((char *)datablock + code[i].arg2->offset) << "\n";
					}
					else
					{
						ofh << "	mov		eax, " << *(int *)((char *)datablock + code[i].arg1->offset) << "\n";
						ofh << "	sub		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	mov		DWORD PTR " << formatname(code[i].arg2->name) << ", eax" << "\n";
					}
				}
				else
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	mov		eax, " << *(int *)((char *)datablock + code[i].arg2->offset) << "\n";
						ofh << "	sub		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	mov		DWORD PTR " << formatname(code[i].arg2->name) << ", eax" << "\n";
					}
					else
					{
						ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	sub		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	mov		DWORD PTR " << formatname(code[i].arg2->name) << ", eax" << "\n";
					}
				}
			}
			break;
		
		case MULT_IR:
			if (isfloat(code[i].result->typ)) {
				if (isconstant(code[i].arg1->typ))
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	mulss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg2->offset) << std::dec << "\n";
						ofh << "	movss	DWORD PTR " << formatname(code[i].arg2->name) << ", xmm0" << "\n";
					}
					else
					{
						ofh << "	movss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	mulss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	movss	DWORD PTR " << formatname(code[i].arg2->name) << ", xmm0" << "\n";
					}
				}
				else
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	movss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	mulss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg2->offset) << std::dec << "\n";
						ofh << "	movss	DWORD PTR " << formatname(code[i].arg2->name) << ", xmm0" << "\n";
					}
					else
					{
						ofh << "	movss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	mulss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	movss	DWORD PTR " << formatname(code[i].arg2->name) << ", xmm0" << "\n";
					}
				}
			}
			else
				if (isinteger(code[i].result->typ))
				{
					if (isconstant(code[i].arg1->typ))
					{
						if (isconstant(code[i].arg2->typ)) {
							ofh << "	mov		DWORD PTR " << formatname(code[i].arg2->name) << ", " << (*(int *)((char *)datablock + code[i].arg1->offset)) * (*(int *)((char *)datablock + code[i].arg2->offset)) << "\n";
						}
						else
						{
							ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
							ofh << "	mul		" << *(int *)((char *)datablock + code[i].arg1->offset) << "\n";
							ofh << "	mov		DWORD PTR " << formatname(code[i].arg2->name) << ", eax" << "\n";
						}
					}
					else
					{
						if (isconstant(code[i].arg2->typ))
						{
							ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
							ofh << "	mul		" << *(int *)((char *)datablock + code[i].arg2->offset) << "\n";
							ofh << "	mov		DWORD PTR " << formatname(code[i].arg2->name) << ", eax" << "\n";
						}
						else
						{
							ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
							ofh << "	mul		DWORD PTR " << formatname(code[i].arg2->name) << "\n";
							ofh << "	mov		DWORD PTR " << formatname(code[i].arg2->name) << ", eax" << "\n";
						}
					}
				}
			break;
		
		case DIV_IR:
			if (isfloat(code[i].result->typ)) {
				if (isconstant(code[i].arg1->typ))
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	divss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg2->offset) << std::dec << "\n";
						ofh << "	movss	DWORD PTR " << formatname(code[i].arg2->name) << ", xmm0" << "\n";
					}
					else
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
						ofh << "	divss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	movss	DWORD PTR " << formatname(code[i].arg2->name) << ", xmm0" << "\n";
					}
				}
				else
				{
					if (isconstant(code[i].arg2->typ))
					{
						ofh << "	movss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	divss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg2->offset) << std::dec << "\n";
						ofh << "	movss	DWORD PTR " << formatname(code[i].arg2->name) << ", xmm0" << "\n";
					}
					else
					{
						ofh << "	movss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	divss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	movss	DWORD PTR " << formatname(code[i].arg2->name) << ", xmm0" << "\n";
					}
				}
			}
			else
				if (isinteger(code[i].result->typ)) {
					if (isconstant(code[i].arg1->typ))
					{
						if (isconstant(code[i].arg2->typ)) {
							ofh << "	mov		DWORD PTR " << formatname(code[i].arg2->name) << ", " << (*(int *)((char *)datablock + code[i].arg1->offset)) / (*(int *)((char *)datablock + code[i].arg2->offset)) << "\n";
						}
						else
						{
							ofh << "	xor		edx, edx\n";
							ofh << "	mov		eax, " << *(int *)((char *)datablock + code[i].arg1->offset) << "\n";
							ofh << "	div		DWORD PTR " << formatname(code[i].arg2->name) << "\n";
							ofh << "	mov		DWORD PTR " << formatname(code[i].arg2->name) << ", eax" << "\n";
						}
					}
					else
					{
						if (isconstant(code[i].arg2->typ))
						{
							ofh << "	xor		edx, edx\n";
							ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
							ofh << "	div		" << *(int *)((char *)datablock + code[i].arg2->offset) << "\n";
							ofh << "	mov		DWORD PTR " << formatname(code[i].arg2->name) << ", eax" << "\n";
						}
						else
						{
							ofh << "	xor		edx, edx\n";
							ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
							ofh << "	div		DWORD PTR " << formatname(code[i].arg2->name) << "\n";
							ofh << "	mov		DWORD PTR " << formatname(code[i].arg2->name) << ", eax" << "\n";
						}
					}
				}
			break;
		
		case MOD_IR:
			if (isinteger(code[i].result->typ)) {
				if (isconstant(code[i].arg1->typ))
				{
					if (isconstant(code[i].arg2->typ)) {
						ofh << "	mov		DWORD PTR " << formatname(code[i].arg2->name) << ", " << (*(int *)((char *)datablock + code[i].arg1->offset)) % (*(int *)((char *)datablock + code[i].arg2->offset)) << "\n";
					}
					else
					{
						ofh << "	mov		eax, " << *(int *)((char *)datablock + code[i].arg1->offset) << "\n";
						ofh << "	cdq\n";
						ofh << "	idiv	DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	mov		DWORD PTR " << formatname(code[i].arg2->name) << ", edx" << "\n";
					}
				}
				else
				{
					if (isconstant(code[i].arg2->typ))
					{

						ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	cdq\n";
						ofh << "	idiv	" << *(int *)((char *)datablock + code[i].arg2->offset) << "\n";
						ofh << "	mov		DWORD PTR " << formatname(code[i].arg2->name) << ", edx" << "\n";
					}
					else
					{
						ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	cdq\n";
						ofh << "	idiv	DWORD PTR " << formatname(code[i].arg2->name) << "\n";
						ofh << "	mov		DWORD PTR " << formatname(code[i].arg2->name) << ", edx" << "\n";
					}
				}
			}
			break;
		
		case INT_IR:
			if (isconstant(code[i].arg1->typ))
			{
				if (isfloat(code[i].arg1->typ)) {
					int v1 = (int)(*(float *)((char *)datablock + code[i].arg1->offset));
					ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << "," << v1 << "\n";
				}
				else
					if (isfloat(code[i].arg1->typ)) {
						int v1 = (int)(*(char *)((char *)datablock + code[i].arg1->offset));
						ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << "," << v1 << "\n";
					}
					else
						if (isinteger(code[i].arg1->typ)) {
							int v1 = (int)(*(int *)((char *)datablock + code[i].arg1->offset));
							ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << "," << v1 << "\n";
						}
			}
			else
			{
				if (isfloat(code[i].arg1->typ)) {
					ofh << "	cvttsd2si	eax, QWORD PTR " << formatname(code[i].arg1->name) << "\n";
					ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << ", eax" << "\n";
				}
				else
					if (ischar(code[i].arg1->typ)) {
						ofh << "	movsx	eax, BYTE PTR " << formatname(code[i].arg1->name) << "\n";
						ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << ", eax" << "\n";
					}
					else
						if (isinteger(code[i].arg1->typ)) {
							ofh << "	mov		eax, WORD PTR " << formatname(code[i].arg1->name) << "\n";
							ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << ", eax" << "\n";
						}
			}
			break;
		
		case FLOAT_IR:
			if (isconstant(code[i].arg1->typ))
			{
				if (isinteger(code[i].arg1->typ)) {
					float v1 = (float)(*(int *)((char *)datablock + code[i].arg1->offset));
					ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << (unsigned int)v1 << std::dec << "\n";
					ofh << "	movss	DWORD PTR " << formatname(code[i].result->name) << ", xmm0" << "\n";
				}
				else
					if (ischar(code[i].arg1->typ)) {
						float v1 = (float)(*(char *)((char *)datablock + code[i].arg1->offset));
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << (unsigned int)v1 << std::dec << "\n";
						ofh << "	movss	DWORD PTR " << formatname(code[i].result->name) << ", xmm0" << "\n";
					}
					else
						if (isfloat(code[i].arg1->typ)) {
							float v1 = (float)(*(float *)((char *)datablock + code[i].arg1->offset));
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << (unsigned int)v1 << std::dec << "\n";
							ofh << "	movss	DWORD PTR " << formatname(code[i].result->name) << ", xmm0" << "\n";
						}
			}
			else
			{
				if (isinteger(code[i].arg1->typ)) {
					ofh << "	cvtsi2ss	xmm0, DWORD PTR " << formatname(code[i].arg1->name) << "\n";
					ofh << "	movss		DWORD PTR " << formatname(code[i].result->name) << ", xmm0" << "\n";
				}
				else
					if (ischar(code[i].arg1->typ)) {
						ofh << "	movsx		eax, BYTE PTR " << formatname(code[i].arg1->name) << "\n";
						ofh << "	cvtsi2ss	xmm0, eax\n";
						ofh << "	cvtss2sd	xmm0, xmm0\n";
						ofh << "	movss		DWORD PTR " << formatname(code[i].result->name) << ", xmm0" << "\n";
					}
					else
						if (isfloat(code[i].arg1->typ)) {
							ofh << "	movss	xmm0, DWORD PTR " << formatname(code[i].arg1->name) << "\n";
							ofh << "	movss	DWORD PTR " << formatname(code[i].result->name) << ", xmm0" << "\n";
						}
			}
			break;

		case INC_IR:
			if (isfloat(code[i].result->typ)) {
				if (isconstant(code[i].arg1->typ))
				{
					ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << (unsigned int)1.0f << std::dec << "\n";
					ofh << "	addss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
					ofh << "	movss	DWORD PTR " << formatname(code[i].result->name) << ", xmm0" << "\n";
				}
				else
				{
					ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << (unsigned int)1.0f << std::dec << "\n";
					ofh << "	addss	xmm0, DWORD PTR " << formatname(code[i].arg1->name) << "\n";
					ofh << "	movss	DWORD PTR " << formatname(code[i].result->name) << ", xmm0" << "\n";
				}
			}
			else
			{
				if (isconstant(code[i].arg1->typ))
				{
					ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << ", " << *(int *)((char *)datablock + code[i].arg1->offset) + 1 << "\n";
				}
				else
				{
					ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg1->name) << "\n";
					ofh << "	add		eax, 1\n";
					ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << ", eax" << "\n";
				}
			}
			break;

		case DEC_IR:
			if (isfloat(code[i].result->typ)) {
				if (isconstant(code[i].arg1->typ))
				{
					ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << "\n";
					ofh << "	subss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << (unsigned int)1.0f << std::dec << "\n";
					ofh << "	movss	DWORD PTR " << formatname(code[i].result->name) << ", xmm0" << "\n";
				}
				else
				{
					ofh << "	movss	xmm0, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
					ofh << "	subss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << (unsigned int)1.0f << std::dec << "\n";
					ofh << "	movss	DWORD PTR " << formatname(code[i].result->name) << ", xmm0" << "\n";
				}
			}
			else
			{
				if (isconstant(code[i].arg1->typ))
				{
					ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << ", " << *(int *)((char *)datablock + code[i].arg1->offset) - 1 << "\n";
				}
				else
				{
					ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg1->name) << "\n";
					ofh << "	sub		eax, 1\n";
					ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << ", eax" << "\n";
				}
			}
			break;

		case AND_IR:
			if (isconstant(code[i].arg1->typ))
			{
				if (isconstant(code[i].arg2->typ)) {
					int v = (*(int *)((char *)datablock + code[i].arg1->offset)) & (*(int *)((char *)datablock + code[i].arg2->offset));
					ofh << "	mov		eax, " << v << "\n";
					ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << ", eax" << "\n";
				}
				else
				{
					int v = (*(int *)((char *)datablock + code[i].arg1->offset));
					ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
					ofh << "	and		eax, " << v << "\n";
					ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << ", eax" << "\n";
				}
			}
			else
			{
				if (isconstant(code[i].arg2->typ)) {
					int v = (*(int *)((char *)datablock + code[i].arg2->offset));
					ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
					ofh << "	and		eax, " << v << "\n";
					ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << ", eax" << "\n";
				}
				else
				{
					ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
					ofh << "	and		eax, " << code[i].arg2->name << "\n";
					ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << ", eax" << "\n";
				}
			}
			break;
		
		case OR_IR:
			if (isconstant(code[i].arg1->typ))
			{
				if (isconstant(code[i].arg2->typ)) {
					int v = (*(int *)((char *)datablock + code[i].arg1->offset)) | (*(int *)((char *)datablock + code[i].arg2->offset));
					ofh << "	mov		eax, " << v << "\n";
					ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << ", eax" << "\n";
				}
				else
				{
					int v = (*(int *)((char *)datablock + code[i].arg1->offset));
					ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
					ofh << "	or		eax, " << v << "\n";
					ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << ", eax" << "\n";
				}
			}
			else
			{
				if (isconstant(code[i].arg2->typ)) {
					int v = (*(int *)((char *)datablock + code[i].arg2->offset));
					ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
					ofh << "	or		eax, " << v << "\n";
					ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << ", eax" << "\n";
				}
				else
				{
					ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg2->name) << "\n";
					ofh << "	or		eax, " << code[i].arg2->name << "\n";
					ofh << "	mov		DWORD PTR " << formatname(code[i].result->name) << ", eax" << "\n";
				}
			}
			break;
		
		case GOTO_IR:
			ofh << "	jmp		SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
			break;
		
		case PROC_IR:
			ofh << "_TEXT	SEGMENT\n";
			symtable = code[i].arg1->func_desc.sym_table;
			offset = 4;
			it = symtable->begin();
			while (it != symtable->end())
			{
				if (((*it)->typ & ARG_SPEC) != 0)
				{
					offset += 4;
				}
				else
					break;
				ofh << "_" << (*it)->name << "$ = " << offset << std::endl;
				it++;
			}
			offset = 0;
			while (it != symtable->end())
			{
				if (!isconstant((*it)->typ))
				{
					offset -= (*it)->size;
					ofh << "_" << (*it)->name << "$ = " << offset << std::endl;
				}
				it++;
			}
			ofh << "_" << code[i].arg1->name << "	PROC\n";
			ofh << "	push	ebp\n";
			ofh << "	mov		ebp, esp\n";
			ofh << "	sub		esp, " << 64 - (offset / 4) * 4 << "\n";
			ofh << "	push	ebx	\n";
			ofh << "	push	esi	\n";
			ofh << "	push	edi	\n";
			currfunc = code[i].arg1;
			/*it = symtable->begin();
			while(it != symtable->end())
			{
			if(((*it)->typ & ARG_SPEC) == 0 && (*it)->init)
			{
			if(ischar((*it)->typ))
			ofh << "	mov	BYTE PTR _" << (*it)->name << "$[ebp], " << *(unsigned char *)((char *)datablock+(*it)->offset) << std::endl;
			if(isinteger((*it)->typ))
			ofh << "	mov	DWORD PTR _" << (*it)->name << "$[ebp], " << *(int *)((char *)datablock+(*it)->offset) << std::endl;
			if(isfloat((*it)->typ))
			{
			ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+(*it)->offset) << std::dec << std::endl;
			ofh << "	movss	DWORD PTR _" << (*it)->name << "$[ebp], xmm0" << std::endl;
			}
			}
			it++;
			}*/
			break;
		
		case ENDPROC_IR:
			ofh << "$exit@" << currfunc->name << ":\n";
			ofh << "	pop		edi\n";
			ofh << "	pop		esi\n";
			ofh << "	pop		ebx\n";
			ofh << "	mov		esp, ebp\n";
			ofh << "	pop		ebp\n";
			ofh << "	ret		0\n";
			ofh << "_" << code[i].arg1->name << "	ENDP\n";
			ofh << "_TEXT	ENDS\n";
			break;
		
		case RET_IR:
			if (code[i].arg1 != NULL)
			{
				if (isconstant(code[i].arg1->typ))
				{
					int val;
					float fval;
					if (ischar(code[i].arg1->typ))
						val = *((char *)datablock + code[i].arg1->offset);
					if (isinteger(code[i].arg1->typ))
						val = *(int *)((char *)datablock + code[i].arg1->offset);
					if (isfloat(code[i].arg1->typ))
						fval = *(float *)((char *)datablock + code[i].arg1->offset);
					if (ischar(currfunc->typ))
					{
						if (ischar(code[i].arg1->typ) || isinteger(code[i].arg1->typ))
							ofh << "	movzx	eax, " << val << "\n";
						if (isfloat(code[i].arg1->typ))
							ofh << "	movzx	eax, " << (int)fval << "\n";
					}
					if (isinteger(currfunc->typ))
					{
						if (ischar(code[i].arg1->typ) || isinteger(code[i].arg1->typ))
							ofh << "	mov		eax, " << val << "\n";
						if (isfloat(code[i].arg1->typ))
							ofh << "	mov		eax, " << (int)fval << "\n";
					}
					if (isfloat(currfunc->typ))
					{
						if (ischar(code[i].arg1->typ) || isinteger(code[i].arg1->typ))
							fval = (float)val;
						ofh << "	fld		DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)&fval << std::dec << "\n";
					}
				}
				else
				{
					if (ischar(currfunc->typ))
					{
						if (ischar(code[i].arg1->typ))
							ofh << "	movzx	eax, BYTE PTR " << formatname(code[i].arg1->name) << "" << std::endl;
						if (isinteger(code[i].arg1->typ))
							ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg1->name) << "" << std::endl;
						if (isfloat(code[i].arg1->typ))
						{
							ofh << "	cvtss2si	eax, DWORD PTR " << formatname(code[i].arg1->name) << "" << std::endl;
						}
					}
					if (isinteger(currfunc->typ))
					{
						if (ischar(code[i].arg1->typ))
							ofh << "	movzx	eax, DWORD PTR " << formatname(code[i].arg1->name) << "" << std::endl;
						if (isinteger(code[i].arg1->typ))
							ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg1->name) << "" << std::endl;
						if (isfloat(code[i].arg1->typ))
						{
							ofh << "	cvtss2si	eax, DWORD PTR " << formatname(code[i].arg1->name) << "" << std::endl;
						}
					}
					if (isfloat(currfunc->typ))
					{
						if (ischar(code[i].arg1->typ)) {
							ofh << "	movzx	eax, DWORD PTR " << formatname(code[i].arg1->name) << "" << std::endl;
							ofh << "	fld		eax\n";
						}
						if (isinteger(code[i].arg1->typ))
						{
							ofh << "	mov		eax, DWORD PTR " << formatname(code[i].arg1->name) << "" << std::endl;
							ofh << "	fld		eax\n";
						}
						if (isfloat(code[i].arg1->typ))
							ofh << "	fld		DWORD PTR " << formatname(code[i].arg1->name) << "" << std::endl;
					}
				}
			}
			ofh << "	jmp		SHORT $exit" << "@" << currfunc->name << std::endl;
			break;
		
		case PARAM_IR:
			if (isconstant(code[i].arg1->typ))
			{
				if (ischar(code[i].arg1->typ))
				{
					int val = *(char *)((char *)datablock + code[i].arg1->offset);
					ofh << "	push	" << val << std::endl;
				}
				if (isinteger(code[i].arg1->typ))
					ofh << "	push	" << *(int *)((char *)datablock + code[i].arg1->offset) << std::endl;
				if (isfloat(code[i].arg1->typ))
					ofh << "	push	DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock + code[i].arg1->offset) << std::dec << std::endl;
				if (isstring(code[i].arg1->typ))
					ofh << "	push	OFFSET _" << code[i].arg1->name << std::endl;
			}
			else
			{
				if (ischar(code[i].arg1->typ))
				{
					ofh << "	movzx	eax, BYTE PTR " << formatname(code[i].arg1->name) << "\n";
					ofh << "	push	eax\n";
				}
				if (isinteger(code[i].arg1->typ) || isfloat(code[i].arg1->typ))
					ofh << "	push	DWORD PTR " << formatname(code[i].arg1->name) << "\n";
				if (isfloat(code[i].arg1->typ))
				{
					ofh << "	sub		esp, 4\n";
					ofh << "	fld		DWORD PTR " << formatname(code[i].arg1->name) << "\n";
					ofh << "	fstp	DWORD PTR [esp]\n";
				}
			}
			break;
		
		case CALL_IR:
			ofh << "	call	_" << code[i].arg1->name << "\n";
			if (code[i].arg2 != NULL)
				ofh << "	add		esp, " << sizeof(int)*code[i].arg2->offset << "\n";
			if (isinteger(code[i].result->typ))
				ofh << "	mov		" << formatname(code[i].arg2->name) << ", eax\n";
			if (isfloat(code[i].result->typ))
				ofh << "	fstp	" << formatname(code[i].arg2->name) << "\n";
			break;
		default:
			std::cout << "Unknown IR instruction\n";
			break;
		}
		i++;
	}
	ofh << "END\n\n";
	ofh.close();
	free(labels);
}