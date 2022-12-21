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

std::list<int> *merge(std::list<int> *p1, std::list<int> *p2)
{
	std::list<int> *ptr;
	if(p1 == NULL)
		return p2;
	if(p2 == NULL)
		return p1;
	ptr = p1;
	ptr->merge(*(p2));
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
	ptr->merge(*(p2));
	ptr->merge(*(p3));
	return ptr;
}

std::list<CONST_DATA *> *merge(std::list<CONST_DATA *> *p1, std::list<CONST_DATA *> *p2)
{   std::list<CONST_DATA *> *ptr;
	if(p1 == NULL)
		return p2;
	if(p2 == NULL)
		return p1;
	ptr = p1;
	ptr->merge(*(p2));
	return ptr;
}

std::list<CASE_DATA *> *merge(std::list<CASE_DATA *> *p1, std::list<CASE_DATA *> *p2)
{   std::list<CASE_DATA *> *ptr;
	if(p1 == NULL)
		return p2;
	if(p2 == NULL)
		return p1;
	ptr = p1;
	ptr->merge(*(p2));
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

void setargs() 
{
	std::list<symrec *>::iterator it = sym_table->begin();
	while(it != sym_table->end())
	{
		(*it)->typ |= ARG_SPEC;
		it++;
	}
}

std::list<CASE_DATA *> *makecaselist(VALUE val, int typ, int addr){
	CASE_DATA *newstruc = new CASE_DATA();
	newstruc->val = val;
	newstruc->typ = typ;
	newstruc->addr = addr;
	return new std::list<CASE_DATA *>(1,newstruc);
}

std::list<CASE_DATA *> *makecaselist(int addr){
	CASE_DATA *newstruc = new CASE_DATA();
	newstruc->typ = VOIDVAL;
	newstruc->addr = addr;
	return new std::list<CASE_DATA *>(1,newstruc);
}

void print_icode()
{
	int i = 0;
	std::cout << std::endl;
	while (i < nextinstr) {
		switch(code[i].op)
		{
			case STORE_IR:
				std::cout << i << ": " << code[i].result->name << " = " << code[i].arg1->name << std::endl;
				break;
			case STOREA_IR:
				std::cout << i << ": " << code[i].result->name << "[" << code[i].arg2->name << "] = " << code[i].arg1->name << std::endl;
				break;
			case LOADA_IR:
				std::cout << i << ": " << code[i].result->name << " = " << code[i].arg1->name << "[" << code[i].arg2->name << "]\n";
				break;
			case IF_LT_IR:
				std::cout << i << ": IF " << code[i].arg1->name << " < " << code[i].arg2->name << " GOTO " << code[i].result->offset << std::endl;
				break;
			case IF_LE_IR:
				std::cout << i << ": IF " << code[i].arg1->name << " <= " << code[i].arg2->name << " GOTO " << code[i].result->offset << std::endl;
				break;
			case IF_GT_IR:
				std::cout << i << ": IF " << code[i].arg1->name << " > " << code[i].arg2->name << " GOTO " << code[i].result->offset << std::endl;
				break;
			case IF_GE_IR:
				std::cout << i << ": IF " << code[i].arg1->name << " >= " << code[i].arg2->name << " GOTO " << code[i].result->offset << std::endl;
				break;
			case IF_EQ_IR:
				std::cout << i << ": IF " << code[i].arg1->name << " == " << code[i].arg2->name << " GOTO " << code[i].result->offset << std::endl;
				break;
			case IF_NE_IR:
				std::cout << i << ": IF " << code[i].arg1->name << " != " << code[i].arg2->name << " GOTO " << code[i].result->offset << std::endl;
				break;
			case GOTO_IR:
				std::cout << i << ": GOTO " << code[i].result->offset << std::endl;
				break;
			case ADD_IR:
				std::cout << i << ": " << code[i].result->name << " = " << code[i].arg1->name << " + " << code[i].arg2->name << std::endl;
				break;
			case SUB_IR:
				std::cout << i << ": " << code[i].result->name << " = " << code[i].arg1->name << " - " << code[i].arg2->name << std::endl;
				break;
			case MULT_IR:
				std::cout << i << ": " << code[i].result->name << " = " << code[i].arg1->name << " * " << code[i].arg2->name << std::endl;
				break;
			case DIV_IR:
				std::cout << i << ": " << code[i].result->name << " = " << code[i].arg1->name << " / " << code[i].arg2->name << std::endl;
				break;
			case MINUS_IR:
				std::cout << i << ": " << code[i].result->name << " = MINUS " << code[i].arg1->name << std::endl;
				break;
			case MOD_IR:
				std::cout << i << ": " << code[i].result->name << " = " << code[i].arg1->name << " % " << code[i].arg2->name << std::endl;
				break;
			case INC_IR:
				std::cout << i << ": " << code[i].result->name << " = " << code[i].arg1->name << " + 1" << std::endl;
				break;
			case DEC_IR:
				std::cout << i << ": " << code[i].result->name << " = " << code[i].arg1->name << " - 1" << std::endl;
				break;
			case ADDRESS_IR:
				break;
			case DEREF_IR:
				break;
			case TWOCOMP_IR:
				break;
			case NOT_IR:
				std::cout << i << ": " << code[i].result->name << " = NOT " << code[i].arg1->name << std::endl;
				break;
			case INT_IR:
				std::cout << i << ": " << code[i].result->name << " = (int)" << code[i].arg1->name << std::endl;
				break;
			case FLOAT_IR:
				std::cout << i << ": " << code[i].result->name << " = (float)" << code[i].arg1->name << std::endl;
				break;
			case LSHIFT_IR:
				break;
			case RSHIFT_IR:
				break;
			case AND_IR:
				std::cout << i << ": " << code[i].result->name << " = " << code[i].arg1->name << " AND " << code[i].arg2->name << std::endl;
				break;
            case OR_IR:
				std::cout << i << ": " << code[i].result->name << " = " << code[i].arg1->name << " OR " << code[i].arg2->name << std::endl;
				break;
			case XOR_IR:
				std::cout << i << ": " << code[i].result->name << " = " << code[i].arg1->name << " XOR " << code[i].arg2->name << std::endl;
				break;
			case RET_IR:
				if(code[i].arg1 != NULL)
					std::cout << i << ": RETURN " << code[i].arg1->name << std::endl;
				else
					std::cout << i << ": RETURN" << std::endl;
				break;
			case PROC_IR:
				if(code[i].arg1 != NULL)
					std::cout << i << ": PROC " << code[i].arg1->name << std::endl;
				break;
			case ENDPROC_IR:
				if(code[i].arg1 != NULL)
					std::cout << i << ": ENDPROC " << code[i].arg1->name << std::endl;
				break;
			case CALL_IR:
				if(code[i].arg2 == NULL)
					std::cout << i << ": " << code[i].result->name << " = CALL " << code[i].arg1->name << std::endl;
				else
					std::cout << i << ": " << code[i].result->name << " = CALL " << code[i].arg1->name << ", " << code[i].arg2->offset << std::endl;
				break;
			case PARAM_IR:
				std::cout << i << ": PARAM " << code[i].arg1->name << std::endl;
				break;
		}
		i++;
	}
	std::cout << std::endl;
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
	if(!ofh.is_open()) {
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
		if(code[i].op >= IF_EQ_IR && code[i].op <= GOTO_IR) 
		{
			j = code[i].result;
			if(j->offset >= nextinstr){
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
	for(it = sym_table->begin(); it != sym_table->end(); it++)
	{
		if((((*it)->typ) & VAR_SPEC) != 0)
		{
			if(isarray((*it)->typ))
			{
				if(ischar((*it)->typ)) 
				{
					ofh << "COMM	_" << (*it)->name << ":BYTE:0" << std::hex << (*it)->size << "H\n";
				}
				if(isinteger((*it)->typ)) 
				{
					ofh << "COMM	_" << (*it)->name << ":DWORD:0" << std::hex << (*it)->size/4 << "H\n";
				}
				if(isfloat((*it)->typ))
				{
					ofh << "COMM	_" << (*it)->name << ":DWORD:0" << std::hex << (*it)->size/4 << "H\n";
				}
			}
			else
			{
				if(ischar((*it)->typ)) 
				{
					if((*it)->init)
						ofh << "_" << (*it)->name << "\tDB\t0" << std::hex << *(unsigned char *)((char *)datablock+(*it)->offset) << std::dec << "H\n";
					else
						ofh << "COMM	_" << (*it)->name << ":DBYTE\n";
				}
				if(isinteger((*it)->typ)) 
				{
					if((*it)->init)
						ofh << "_" << (*it)->name << "\tDD\t0" << std::hex << *(unsigned int *)((char *)datablock+(*it)->offset) << std::dec << "H\n";
					else
						ofh << "COMM	_" << (*it)->name << ":DWORD\n";
				}
				if(isfloat((*it)->typ))
				{
					if((*it)->init)
						ofh << "_" << (*it)->name << "\tDD\t0" << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+(*it)->offset) << std::dec << "r\n";
					else
						ofh << "COMM	_" << (*it)->name << ":DWORD\n";
				}
			}
		}
	}
	ofh << "_DATA	ENDS\n";
	ofh << "_CONST	SEGMENT\n";
	/* Buscar constantes float */
	for(it = sym_table->begin(); it != sym_table->end(); it++)
	{
		if(isconstant((*it)->typ))
		{
			if(isfloat((*it)->typ))
			{
				unsigned int val = *(unsigned int *)((char *)datablock+(*it)->offset);
				ofh << "__real@" << std::setfill('0') << std::setw(8) << std::hex << val << "	DD	0" << std::setfill('0') << std::setw(8) << val << std::dec << "r\n";
			}
		}
		if(isfunction((*it)->typ))
		{
			std::list<symrec *>::iterator itt;
			symtable = (*it)->func_desc.sym_table;
			if(symtable != NULL)
			{
				for(itt = symtable->begin(); itt != symtable->end(); itt++) 
				{
					if(isconstant((*itt)->typ))
					{
						if(isfloat((*itt)->typ))
						{
							unsigned int val = *(unsigned int *)((char *)datablock+(*itt)->offset);
							ofh << "__real@" << std::setfill('0') << std::setw(8) << std::hex << val << "	DD	0" << std::setfill('0') << std::setw(8) << val << std::dec << "r\n";
						}
						if(isstring((*itt)->typ)) 
						{
							unsigned char *s = ((unsigned char *)datablock+(*itt)->offset);
							int i = 0;
							ofh << "_" << (*itt)->name << "$	DB	";
							while (s[i] != 0)
							{
								if(i>0)
									ofh << ", ";
								if(!iscntrl(s[i]))
								{
									ofh << "\'";
									while(!iscntrl(s[i]))
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
		if(labels[i])
			ofh << "$LN" << i << "@" << currfunc->name << ":\n";
		switch(code[i].op) {
			case STORE_IR:
				if(isfloat(code[i].result->typ)){
					if(isconstant(code[i].arg1->typ))
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
					else
						ofh << "	movss	xmm0, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
					ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0\n";
				}
				else 
				{
					if(isconstant(code[i].arg1->typ))
						ofh << "	mov	DWORD PTR _" << code[i].result->name << "$[ebp], " << *(int *)((char *)datablock+code[i].arg1->offset) << "\n";
					else
					{
						ofh << "	mov	eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
						ofh << "	mov	DWORD PTR _" << code[i].result->name << "$[ebp], eax\n";
					}
				}
				break;
			case STOREA_IR:
				if(isfloat(code[i].result->typ)){
					if(isconstant(code[i].arg1->typ))
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
					else
						ofh << "	movss	xmm0, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
					ofh << "	mov	eax, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
					ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp+eax], xmm0\n";
				}
				else 
				{
					if(isconstant(code[i].arg1->typ)) 
					{
						ofh << "	mov	eax, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
						ofh << "	mov	DWORD PTR _" << code[i].result->name << "$[ebp+eax], " << *(int *)((char *)datablock+code[i].arg1->offset) << "\n";
					}
					else
					{
						ofh << "	mov	eax, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
						ofh << "	mov	ebx, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
						ofh << "	mov	DWORD PTR _" << code[i].result->name << "$[ebp+eax], ebx\n";
					}
				}
				break;
			case LOADA_IR:
				if(isfloat(code[i].result->typ)){
					ofh << "	mov	eax, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
					ofh << "	movss	xmm0, DWORD PTR _" << code[i].arg1->name << "$[ebp+eax]\n";
					ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0\n";
				}
				else 
				{
					ofh << "	mov	eax, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
					ofh << "	mov	ebx, DWORD PTR _" << code[i].arg1->name << "$[ebp+eax]\n";
					ofh << "	mov	DWORD PTR _" << code[i].result->name << "$[ebp], ebx\n";
				}
				break;
			case IF_EQ_IR:
				if(isfloat(code[i].arg1->typ)){
					if(isconstant(code[i].arg1->typ)) 
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg2->offset) << std::dec << "\n";
							ofh << "	je	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
						else
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	je	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
					}
					else 
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg2->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	jne	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
						else
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	je	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
					}
				}
				else 
				{
					if(isconstant(code[i].arg1->typ))
					{
						if(isconstant(code[i].arg2->typ)) {
							ofh << "	mov	eax, " << *(int *)((char *)datablock+code[i].arg1->offset) << "\n";
							ofh << "	cmp	eax, " << *(int *)((char *)datablock+code[i].arg2->offset) << "\n";
							ofh << "	je	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
						else
						{
							ofh << "	cmp	DWORD PTR _" << code[i].arg2->name << "$[ebp], " << *(int *)((char *)datablock+code[i].arg1->offset) << "\n";
							ofh << "	jne	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
					}
					else
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	cmp	DWORD PTR _" << code[i].arg1->name << "$[ebp], " << *(int *)((char *)datablock+code[i].arg2->offset) << "\n";
						}
						else
						{
							ofh << "	mov	eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	cmp	eax, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
						}
						ofh << "	je	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
				break;
			case IF_NE_IR:
				if(isfloat(code[i].arg1->typ)){
					if(isconstant(code[i].arg1->typ)) 
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg2->offset) << std::dec << "\n";
							ofh << "	jne	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
						else
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	jne	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
					}
					else 
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg2->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	je	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
						else
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	jne	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
					}
				}
				else 
				{
					if(isconstant(code[i].arg1->typ))
					{
						if(isconstant(code[i].arg2->typ)) {
							ofh << "	mov	eax, " << *(int *)((char *)datablock+code[i].arg1->offset) << "\n";
							ofh << "	cmp	eax, " << *(int *)((char *)datablock+code[i].arg2->offset) << "\n";
							ofh << "	jne	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
						else
						{
							ofh << "	cmp	DWORD PTR _" << code[i].arg2->name << "$[ebp], " << *(int *)((char *)datablock+code[i].arg1->offset) << "\n";
							ofh << "	je	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
					}
					else
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	cmp	DWORD PTR _" << code[i].arg1->name << "$[ebp], " << *(int *)((char *)datablock+code[i].arg2->offset) << "\n";
						}
						else
						{
							ofh << "	mov	eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	cmp	eax, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
						}
						ofh << "	jne	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
				break;
			case IF_LT_IR:
				if(isfloat(code[i].arg1->typ)){
					if(isconstant(code[i].arg1->typ)) 
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg2->offset) << std::dec << "\n";
							ofh << "	jl	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
						else
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	jl	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
					}
					else 
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg2->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	jnl	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
						else
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	jl	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
					}
				}
				else 
				{
					if(isconstant(code[i].arg1->typ))
					{
						if(isconstant(code[i].arg2->typ)) {
							ofh << "	mov	eax, " << *(int *)((char *)datablock+code[i].arg1->offset) << "\n";
							ofh << "	cmp	eax, " << *(int *)((char *)datablock+code[i].arg2->offset) << "\n";
							ofh << "	jl	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
						else
						{
							ofh << "	cmp	DWORD PTR _" << code[i].arg2->name << "$[ebp], " << *(int *)((char *)datablock+code[i].arg1->offset) << "\n";
							ofh << "	jnl	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
					}
					else
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	cmp	DWORD PTR _" << code[i].arg1->name << "$[ebp], " << *(int *)((char *)datablock+code[i].arg2->offset) << "\n";
						}
						else
						{
							ofh << "	mov	eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	cmp	eax, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
						}
						ofh << "	jl	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
				break;
			case IF_GT_IR:
				if(isfloat(code[i].arg1->typ))
				{
					if(isconstant(code[i].arg1->typ)) 
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg2->offset) << std::dec << "\n";
							ofh << "	jg	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
						else
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	jg	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
					}
					else 
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg2->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	jng	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
						else
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	jg	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
					}
				}
				else 
				{
					if(isconstant(code[i].arg2->typ))
					{
						if(isconstant(code[i].arg2->typ)) {
							ofh << "	mov	eax, " << *(int *)((char *)datablock+code[i].arg1->offset) << "\n";
							ofh << "	cmp	eax, " << *(int *)((char *)datablock+code[i].arg2->offset) << "\n";
							ofh << "	jg	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
						else
						{
							ofh << "	cmp	DWORD PTR _" << code[i].arg2->name << "$[ebp], " << *(int *)((char *)datablock+code[i].arg1->offset) << "\n";
							ofh << "	jng	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
					}
					else
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	cmp	DWORD PTR _" << code[i].arg1->name << "$[ebp], " << *(int *)((char *)datablock+code[i].arg2->offset) << "\n";
						}
						else
						{
							ofh << "	mov	eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	cmp	eax, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
						}
						ofh << "	jg	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
				break;
			case IF_LE_IR:
				if(isfloat(code[i].arg1->typ)){
					if(isconstant(code[i].arg1->typ)) 
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg2->offset) << std::dec << "\n";
							ofh << "	jle	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
						else
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	jle	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
					}
					else 
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg2->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	jnle	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
						else
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	jle	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
					}
				}
				else 
				{
					if(isconstant(code[i].arg1->typ))
					{
						if(isconstant(code[i].arg2->typ)) {
							ofh << "	mov	eax, " << *(int *)((char *)datablock+code[i].arg1->offset) << "\n";
							ofh << "	cmp	eax, " << *(int *)((char *)datablock+code[i].arg2->offset) << "\n";
							ofh << "	jle	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
						else
						{
							ofh << "	cmp	DWORD PTR _" << code[i].arg2->name << "$[ebp], " << *(int *)((char *)datablock+code[i].arg1->offset) << "\n";
							ofh << "	jnle	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
					}
					else
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	cmp	DWORD PTR _" << code[i].arg1->name << "$[ebp], " << *(int *)((char *)datablock+code[i].arg2->offset) << "\n";
						}
						else
						{
							ofh << "	mov	eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	cmp	eax, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
						}
						ofh << "	jle	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
				break;
			case IF_GE_IR:
				if(isfloat(code[i].arg1->typ)){
					if(isconstant(code[i].arg1->typ)) 
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg2->offset) << std::dec << "\n";
							ofh << "	jge	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
						else
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	jge	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
					}
					else 
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg2->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	jnge	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
						else
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	comiss	xmm0, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	jge	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
					}
				}
				else 
				{
					if(isconstant(code[i].arg1->typ))
					{
						if(isconstant(code[i].arg2->typ)) {
							ofh << "	mov	eax, " << *(int *)((char *)datablock+code[i].arg1->offset) << "\n";
							ofh << "	cmp	eax, " << *(int *)((char *)datablock+code[i].arg2->offset) << "\n";
							ofh << "	jge	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
						else
						{
							ofh << "	cmp	DWORD PTR _" << code[i].arg2->name << "$[ebp], " << *(int *)((char *)datablock+code[i].arg1->offset) << "\n";
							ofh << "	jnge	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
						}
					}
					else
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	cmp	DWORD PTR _" << code[i].arg1->name << "$[ebp], " << *(int *)((char *)datablock+code[i].arg2->offset) << "\n";
						}
						else
						{
							ofh << "	mov	eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	cmp	eax, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
						}
						ofh << "	jge	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
					}
				}
				break;
			case ADD_IR:
				if(isfloat(code[i].result->typ)){
					if(isconstant(code[i].arg1->typ)) 
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	addss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg2->offset) << std::dec << "\n";
							ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
						}
						else
						{
							ofh << "	movss	xmm0, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	addss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
						}
					}
					else 
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	movss	xmm0, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	addss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg2->offset) << std::dec << "\n";
							ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
						}
						else
						{
							ofh << "	movss	xmm0, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	addss	xmm0, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
						}
					}
				}
				else 
				if(isinteger(code[i].result->typ)) {
					if(isconstant(code[i].arg1->typ))
					{
						if(isconstant(code[i].arg2->typ)) {
							ofh << "	mov	eax, " << *(int *)((char *)datablock+code[i].arg1->offset)+*(int *)((char *)datablock+code[i].arg1->offset);
							ofh << "	add	eax, " << *(int *)((char *)datablock+code[i].arg1->offset)+*(int *)((char *)datablock+code[i].arg2->offset);
							ofh << "	mov	 DWORD PTR _" << code[i].result->name << "$[ebp], eax" << "\n";
						}
						else
						{
							ofh << "	mov	eax, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	add	eax, " << *(int *)((char *)datablock+code[i].arg1->offset) << "\n";
							ofh << "	mov	 DWORD PTR _" << code[i].result->name << "$[ebp], eax" << "\n";
						}
					}
					else
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	mov	eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	add	eax, " << *(int *)((char *)datablock+code[i].arg2->offset) << "\n";
							ofh << "	mov	 DWORD PTR _" << code[i].result->name << "$[ebp], eax" << "\n";
						}
						else
						{
							ofh << "	mov	eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	add	eax, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	mov	 DWORD PTR _" << code[i].result->name << "$[ebp], eax" << "\n";
						}
					}
				}
				break;
			case SUB_IR:
				if(isfloat(code[i].result->typ)){
					if(isconstant(code[i].arg1->typ)) 
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	subss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg2->offset) << std::dec << "\n";
							ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
						}
						else
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	subss	xmm0, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
						}
					}
					else 
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg2->offset) << std::dec << "\n";
							ofh << "	subss	xmm0, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
						}
						else
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	subss	xmm0, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
						}
					}
				}
				else 
				{
					if(isconstant(code[i].arg1->typ))
					{
						if(isconstant(code[i].arg2->typ)) {
							ofh << "	mov	DWORD PTR _" << code[i].result->name << "$[ebp], " << *(int *)((char *)datablock+code[i].arg1->offset) - *(int *)((char *)datablock+code[i].arg2->offset) << "\n";
						}
						else
						{
							ofh << "	mov	eax, " << *(int *)((char *)datablock+code[i].arg1->offset) << "\n";
							ofh << "	sub	eax, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	mov	 DWORD PTR _" << code[i].result->name << "$[ebp], eax" << "\n";
						}
					}
					else
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	mov	eax, " << *(int *)((char *)datablock+code[i].arg2->offset) << "\n";
							ofh << "	sub	eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	mov	 DWORD PTR _" << code[i].result->name << "$[ebp], eax" << "\n";
						}
						else
						{
							ofh << "	mov	eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	sub	eax, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	mov	 DWORD PTR _" << code[i].result->name << "$[ebp], eax" << "\n";
						}
					}
				}
				break;
			case MULT_IR:
				if(isfloat(code[i].result->typ)){
					if(isconstant(code[i].arg1->typ)) 
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	mulss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg2->offset) << std::dec << "\n";
							ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
						}
						else
						{
							ofh << "	movss	xmm0, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	mulss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
						}
					}
					else 
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	movss	xmm0, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	mulss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg2->offset) << std::dec << "\n";
							ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
						}
						else
						{
							ofh << "	movss	xmm0, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	mulss	xmm0, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
						}
					}
				}
				else 
				if(isinteger(code[i].result->typ))
				{
					if(isconstant(code[i].arg1->typ))
					{
						if(isconstant(code[i].arg2->typ)) {
							ofh << "	mov	DWORD PTR _" << code[i].result->name << "$[ebp], " << (*(int *)((char *)datablock+code[i].arg1->offset)) * (*(int *)((char *)datablock+code[i].arg2->offset)) << "\n";
						}
						else
						{
							ofh << "	mov	eax, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	mul	" << *(int *)((char *)datablock+code[i].arg1->offset) << "\n";
							ofh << "	mov	 DWORD PTR _" << code[i].result->name << "$[ebp], eax" << "\n";
						}
					}
					else
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	mov	eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	mul	" << *(int *)((char *)datablock+code[i].arg2->offset) << "\n";
							ofh << "	mov	 DWORD PTR _" << code[i].result->name << "$[ebp], eax" << "\n";
						}
						else
						{
							ofh << "	mov	eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	mul	DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	mov	 DWORD PTR _" << code[i].result->name << "$[ebp], eax" << "\n";
						}
					}
				}
				break;
			case DIV_IR:
				if(isfloat(code[i].result->typ)){
					if(isconstant(code[i].arg1->typ)) 
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	divss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg2->offset) << std::dec << "\n";
							ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
						}
						else
						{
							ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
							ofh << "	divss	xmm0, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
						}
					}
					else 
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	movss	xmm0, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	divss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg2->offset) << std::dec << "\n";
							ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
						}
						else
						{
							ofh << "	movss	xmm0, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	divss	xmm0, DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
						}
					}
				}
				else 
				if(isinteger(code[i].result->typ)){
					if(isconstant(code[i].arg1->typ))
					{
						if(isconstant(code[i].arg2->typ)) {
							ofh << "	mov	DWORD PTR _" << code[i].result->name << "$[ebp], " << (*(int *)((char *)datablock+code[i].arg1->offset)) / (*(int *)((char *)datablock+code[i].arg2->offset)) << "\n";
						}
						else
						{
							ofh << "	xor	edx, edx\n";
							ofh << "	mov	eax, " << *(int *)((char *)datablock+code[i].arg1->offset) << "\n";
							ofh << "	div	DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	mov	 DWORD PTR _" << code[i].result->name << "$[ebp], eax" << "\n";
						}
					}
					else
					{
						if(isconstant(code[i].arg2->typ)) 
						{
							ofh << "	xor	edx, edx\n";
							ofh << "	mov	eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	div	" << *(int *)((char *)datablock+code[i].arg2->offset) << "\n";
							ofh << "	mov	 DWORD PTR _" << code[i].result->name << "$[ebp], eax" << "\n";
						}
						else
						{
							ofh << "	xor	edx, edx\n";
							ofh << "	mov	eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
							ofh << "	div	DWORD PTR _" << code[i].arg2->name << "$[ebp]\n";
							ofh << "	mov	 DWORD PTR _" << code[i].result->name << "$[ebp], eax" << "\n";
						}
					}
				}
				break;
			case FLOAT_IR:
				if(isconstant(code[i].arg1->typ)) 
				{
					float v1 = (float)(*(int *)((char *)datablock+code[i].arg1->offset));
					ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << (unsigned int)v1 << std::dec << "\n";
					ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
				}
				else
				{
					ofh << "	cvtsi2ss	xmm0, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
					ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
				}
				break;
			case INC_IR:
				if(isfloat(code[i].result->typ)){
					if(isconstant(code[i].arg1->typ)) 
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << (unsigned int)1.0f << std::dec << "\n";
						ofh << "	addss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
						ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
					}
					else 
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << (unsigned int)1.0f << std::dec << "\n";
						ofh << "	addss	xmm0, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
						ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
					}
				}
				else 
				{
					if(isconstant(code[i].arg1->typ))
					{
						ofh << "	mov	DWORD PTR _" << code[i].result->name << "$[ebp], " << *(int *)((char *)datablock+code[i].arg1->offset) + 1 << "\n";
					}
					else
					{
						ofh << "	mov	eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
						ofh << "	add	eax, 1\n";
						ofh << "	mov	 DWORD PTR _" << code[i].result->name << "$[ebp], eax" << "\n";
					}
				}
				break;
			case DEC_IR:
				if(isfloat(code[i].result->typ)){
					if(isconstant(code[i].arg1->typ)) 
					{
						ofh << "	movss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << "\n";
						ofh << "	subss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << (unsigned int)1.0f << std::dec << "\n";
						ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
					}
					else 
					{
						ofh << "	movss	xmm0, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
						ofh << "	subss	xmm0, DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << (unsigned int)1.0f << std::dec << "\n";
						ofh << "	movss	DWORD PTR _" << code[i].result->name << "$[ebp], xmm0" << "\n";
					}
				}
				else 
				{
					if(isconstant(code[i].arg1->typ))
					{
						ofh << "	mov	DWORD PTR _" << code[i].result->name << "$[ebp], " << *(int *)((char *)datablock+code[i].arg1->offset) - 1 << "\n";
					}
					else
					{
						ofh << "	mov	eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
						ofh << "	sub	eax, 1\n";
						ofh << "	mov	 DWORD PTR _" << code[i].result->name << "$[ebp], eax" << "\n";
					}
				}
				break;
			case GOTO_IR:
				ofh << "	jmp	SHORT $LN" << code[i].result->offset << "@" << currfunc->name << "\n";
				break;
			case PROC_IR:
				ofh << "_TEXT	SEGMENT\n";
				symtable = code[i].arg1->func_desc.sym_table;
				offset = 4;
				it = symtable->begin();
				while(it != symtable->end())
				{
					if(((*it)->typ & ARG_SPEC) != 0)
					{	
						offset += 4;
					}
					else
						break;
					ofh << "_" << (*it)->name << "$ = " << offset << std::endl;
					it++;
				}
				offset = 0;
				while(it != symtable->end())
				{	
					if(!isconstant((*it)->typ))
					{
						offset -= (*it)->size;
						ofh << "_" << (*it)->name << "$ = " << offset << std::endl;
					}
					it++;
				}
				ofh << "_" << code[i].arg1->name << "	PROC\n";
				ofh << "	push	ebp\n";
				ofh << "	mov		ebp, esp\n";
				ofh << "	sub		esp, " << 64-(offset/4)*4 << "\n";
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
				if(code[i].arg1 != NULL)
				{
					if(isconstant(code[i].arg1->typ))
					{
						int val;
						float fval;
						if(ischar(code[i].arg1->typ))
							val = *((char *)datablock+code[i].arg1->offset);
						if(isinteger(code[i].arg1->typ))
							val = *(int *)((char *)datablock+code[i].arg1->offset);
						if(isfloat(code[i].arg1->typ))
							fval = *(float *)((char *)datablock+code[i].arg1->offset);
						if(ischar(currfunc->typ)) 
						{
							if(ischar(code[i].arg1->typ) || isinteger(code[i].arg1->typ))
								ofh << "	movzx	eax, " << val << "\n";
							if(isfloat(code[i].arg1->typ))
								ofh << "	movzx	eax, " << (int)fval << "\n";
						}
						if(isinteger(currfunc->typ))
						{
							if(ischar(code[i].arg1->typ) || isinteger(code[i].arg1->typ))
								ofh << "	mov	eax, " << val << "\n";
							if(isfloat(code[i].arg1->typ))
								ofh << "	mov	eax, " << (int)fval << "\n";
						}
						if(isfloat(currfunc->typ))
						{
							if(ischar(code[i].arg1->typ) || isinteger(code[i].arg1->typ))
								fval = (float)val;
							ofh << "	fld	DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)&fval << std::dec << "\n";
						}
					}
					else 
					{
						if(ischar(currfunc->typ))
						{
							if(ischar(code[i].arg1->typ))
								ofh << "	movzx	eax, BYTE PTR _" << code[i].arg1->name << "$[ebp]" << std::endl;
							if(isinteger(code[i].arg1->typ))
								ofh << "	mov	eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]" << std::endl;
							if(isfloat(code[i].arg1->typ)) 
							{
								ofh << "	cvtss2si	eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]" << std::endl;
							}
						}
						if(isinteger(currfunc->typ))
						{
							if(ischar(code[i].arg1->typ))
								ofh << "	movzx eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]" << std::endl;
							if(isinteger(code[i].arg1->typ))
								ofh << "	mov eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]" << std::endl;
							if(isfloat(code[i].arg1->typ)) 
							{
								ofh << "	cvtss2si	eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]" << std::endl;
							}
						}
						if(isfloat(currfunc->typ)) 
						{
							if(ischar(code[i].arg1->typ)) {
								ofh << "	movzx eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]" << std::endl;
								ofh << "	fld eax\n";
							}
							if(isinteger(code[i].arg1->typ)) 
							{
								ofh << "	mov eax, DWORD PTR _" << code[i].arg1->name << "$[ebp]" << std::endl;
								ofh << "	fld eax\n";
							}
							if(isfloat(code[i].arg1->typ))
								ofh << "	fld DWORD PTR _" << code[i].arg1->name << "$[ebp]" << std::endl;
						}
					}
				}
				ofh << "	jmp SHORT $exit" << "@" << currfunc->name << std::endl;
				break;
			case PARAM_IR:
				if(isconstant(code[i].arg1->typ))
				{	
					if(ischar(code[i].arg1->typ))  
					{
						int val = *(char *)((char *)datablock+code[i].arg1->offset);
						ofh << "	push " << val << std::endl;
					}
					if(isinteger(code[i].arg1->typ)) 
						ofh << "	push " << *(int *)((char *)datablock+code[i].arg1->offset) << std::endl;
					if(isfloat(code[i].arg1->typ)) 
						ofh << "	push DWORD PTR __real@" << std::setfill('0') << std::setw(8) << std::hex << *(unsigned int *)((char *)datablock+code[i].arg1->offset) << std::dec << std::endl;
					if(isstring(code[i].arg1->typ))
						ofh << "	push OFFSET _"  << code[i].arg1->name << std::endl;
				}
				else
				{
					if(ischar(code[i].arg1->typ)) 
					{
						ofh << "	movzx	eax, BYTE PTR _" << code[i].arg1->name << "$[ebp]\n";
						ofh << "	push	eax\n";
					}
					if(isinteger(code[i].arg1->typ) || isfloat(code[i].arg1->typ))
						ofh << "	push	DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
					if(isfloat(code[i].arg1->typ))
					{
						ofh << "	sub	esp, 4\n";
						ofh << "	fld	DWORD PTR _" << code[i].arg1->name << "$[ebp]\n";
						ofh << "	fstp	DWORD PTR [esp]\n";
					}
				}
				break;
			case CALL_IR:
				ofh << "	call	_" << code[i].arg1->name << "\n";
				if(code[i].arg2 != NULL)
					ofh << "	add	esp, " << sizeof(int)*code[i].arg2->offset << "\n";
				if(isinteger(code[i].result->typ))
					ofh << "	mov	_" << code[i].result->name << "$[ebp], eax\n";
				if(isfloat(code[i].result->typ))
					ofh << "	fstp	_" << code[i].result->name << "$[ebp]\n";
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
