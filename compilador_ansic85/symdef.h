int ntemp = 0;
	
std::string *newtemp(void)
{
	std::string *name = new std::string("@" + std::to_string(ntemp++));
	return name;
}

/* Determinar tamaño en bytes de un tipo de datos */
int getsizeof(int typ)
{
	typ &= 0x1F;
	switch(typ)
	{
		case SHORTVAL:
			return sizeof(short);
			break;
		case USHORTVAL:
			return sizeof(unsigned short);
			break;
		case INTVAL:
			return sizeof(int);
			break;
		case UINTVAL:
			return sizeof(unsigned int);
			break;
		case LONGVAL:
			return sizeof(long);
			break;
		case ULONGVAL:
			return sizeof(unsigned long);
			break;
		case FVAL:
			return sizeof(float);
			break;
		case DOUBLEVAL:
			return sizeof(double);
			break;
		case LDOUBLEVAL:
			return sizeof(long double);
			break;
		case CHARVAL:
			return sizeof(char);
			break;
		case UCHARVAL:
			return sizeof(unsigned char);
			break;
		case SCHARVAL:
			return sizeof(signed char);
			break;
		case VOIDVAL:
			return 0;
			break;
	}
	return 0;
}

int get_type(std::list<int> *sqlist)
{
	int t = 0, s;
	std::list<int>::iterator it;
	for(it = sqlist->begin();it!=sqlist->end();it++)
	{
		if((t & *it) != 0)
			yyerror("Error in type specification!");
		t = t | *it;
	}
	s = t & 0xFFC000; /* Extraer modificadores */
	if((t & VOID_SPEC) != 0)
	{
		return VOIDVAL + s;
	}
	if((t & CHAR_SPEC) != 0)
	{
		if((t & (0x3FFF & ~CHAR_SPEC)) != 0)
			yyerror("Error in char type specification!");
		if((t & SIGNED_SPEC) > 0)
			return SCHARVAL + s;
		if((t & UNSIGNED_SPEC) > 0)
			return UCHARVAL + s;
		return CHARVAL + s;
	}
	if((t & SHORT_SPEC) != 0) 
	{
		if((t & (0x3FFF & ~(SHORT_SPEC | INT_SPEC))) != 0)
			yyerror("Error in short type specification!");
		if((t & UNSIGNED_SPEC) > 0)
			return USHORTVAL + s;
		return SHORTVAL + s;
	}
	if(((t & INT_SPEC) != 0) && ((t & LONG_SPEC) == 0)) 
	{
		if((t & (0x3FFF & ~INT_SPEC)) != 0)
			yyerror("Error in int type specification!");
		if((t & UNSIGNED_SPEC) > 0)
			return UINTVAL + s;
		return INTVAL + s;
	}
	if(((t & LONG_SPEC) != 0) && ((t & DOUBLE_SPEC) == 0)) 
	{
		if((t & (0x3FFF & ~(LONG_SPEC | INT_SPEC))) != 0)
			yyerror("Error in long type specification!");
		if((t & UNSIGNED_SPEC) > 0)
			return ULONGVAL + s;
		return LONGVAL + s;
	}
	if((t & FLOAT_SPEC) != 0) 
	{
		if((t & (0x3FFF & ~FLOAT_SPEC)) != 0)
			yyerror("Error in float type specification!");
		return FVAL + s;
	}
	if((t & DOUBLE_SPEC) != 0) 
	{
		if((t & (0x3FFF & ~(DOUBLE_SPEC | LONG_SPEC))) != 0)
			yyerror("Error in double type specification!");
		if((t & LONG_SPEC) != 0)
			return LDOUBLEVAL + s;
		return DOUBLEVAL + s;
	}
	return INTVAL + s;
}

int data_location(int sz) /* Reserva espacio para dato */
{
	data_offset += sz;
	return data_offset-sz;
}

int isfunction(int typ)
{
	return (typ & FUNC_SPEC) != 0;
}

int isarray(int typ)
{
	return (typ & ARRAY_SPEC) != 0;
}

int isconstant(int typ)
{
	return (typ & CONST_SPEC) != 0;
}

int isvar(int typ)
{
	return (typ & VAR_SPEC) != 0;
}

int isintegral(int typ)
{   typ &= 0x1F;
	return (typ >= CHARVAL && typ <= ULONGVAL);
}

int isinteger(int typ)
{   typ &= 0x1F;
	return (typ == INTVAL || typ == UINTVAL);
}

int ischar(int typ)
{   typ &= 0x1F;
	return (typ >= CHARVAL && typ <= SCHARVAL);
}

int isfloat(int typ)
{   typ &= 0x1F;
	return (typ >= FVAL && typ <= LDOUBLEVAL);
}

int ispointer(int typ)
{
	return (typ & POINTER_SPEC) != 0;
}


int isstring(int typ)
{   typ &= 0x1F;
	return (typ == STRVAL) != 0;
}

int gettype(int typ1, int typ2)
{
    int sz1, sz2;
    sz1 = getsizeof(typ1);
    sz2 = getsizeof(typ1);
    if(sz1>sz2)
        return typ1;
    return typ2;
}

/* Agregar símbolo en ambito local */
symrec *putsym(const std::string *sym_name, int typ)
{
	symrec *ptr;
	ptr = new symrec();
	ptr->name = *sym_name;
	ptr->size = getsizeof(typ);
	ptr->typ = typ;
	ptr->offset = data_location(ptr->size);
	sym_table->push_back(ptr);
	return ptr;
}


/* Agregar arreglo a tabla de símbolos local */
symrec *putarrsym(const std::string *sym_name, int typ, int ndim)
{
	symrec *ptr;
	ptr = new symrec();
	ptr->name = *sym_name;
	ptr->size = getsizeof(typ)*ndim;
	ptr->typ = typ;
	ptr->offset = data_location(ptr->size);
	sym_table->push_back(ptr);
	return ptr;
}

/* Buscar variable en tabla de ámbito local 
   Si no es encontrada, buscar en tablas guardadas en el stack */
symrec *getsym (const std::string *sym_name)
{
	std::list<symrec *>::iterator ptr = sym_table->begin();	// Obtener inicio de tabla de simbolos locales
	std::list<symrec *>::iterator endptr = sym_table->end(); // Obtener fin de tabla de simbolos locales
	std::list<std::list<symrec *> *>::iterator it = scopes.begin();
	while(1) {
		while(ptr != endptr){
			if ((*ptr)->name.compare(*sym_name) == 0)
				return *ptr;
			ptr++;
		}
		if(it == scopes.end())
			break;
		ptr = (*it)->begin();
		endptr = (*it)->end();
		it++;
	};
	return NULL;
}


/* Buscar variable en ámbito local */
symrec *getlocalsym (const std::string *sym_name)
{
	std::list<symrec *>::iterator ptr = sym_table->begin();
	std::list<symrec *>::iterator endptr = sym_table->end();
	while(ptr != endptr){
		if ((*ptr)->name.compare(*sym_name) == 0)
			return *ptr;
		ptr++;
	}
	return NULL;
}

/* Agregar simbolo a tabla de símbolos local */
symrec *install(const std::string *sym_name, int typ)
{
	symrec *s;
	s = getlocalsym (sym_name);
	if (s == 0)
		s = putsym (sym_name, typ);
	else { 
			/*printf("%s is already defined\n", sym_name);*/
			yyerror("Symbol already defined!");
	}
	return s;
}

symrec *installarg(std::list<VAR_DATA *> *arglist)
{
	symrec *s;
	std::list<VAR_DATA *>::iterator it;
	if(arglist == NULL)
		return NULL;
	for(it = arglist->begin(); it != arglist->end(); it++)
	{	
		s = getlocalsym ((*it)->name);
		if(s == NULL) {
			if(!isarray((*it)->typ))
				s = putsym((*it)->name, (*it)->typ);
			else
				s = putarrsym((*it)->name, (*it)->typ | ARRAY_SPEC, (*it)->val.intval);
		}
		else { 
				yyerror("Argument symbol already defined");
		}
	}
	return NULL;
}

void installarray(const std::string *sym_name, int typ, int ndim)
{
	symrec *s;
	s = getsym (sym_name);
	if (s == 0)
		s = putarrsym(sym_name, typ | ARRAY_SPEC, ndim);
	else { 
			/*printf("%s is already defined\n", sym_name);*/
			yyerror("Symbol already defined!");
	}
}

void enter_scope()
{
	scopes.push_front(sym_table);   // Guardar tabla de símbolos activa
	sym_table = new symboltable();	// Crear nueva tabla
	currscope++;					// Incrementar el nivel de ámbito
}

void exit_scope()
{
	sym_table->splice(sym_table->end(), *localsyms); // Agregar simbolos locales a tabla de función
	localsyms = sym_table;
	sym_table = scopes.front();					    // Restaurar tabla de simbolos anterior
	scopes.pop_front();							    // Remover tabla del stack
	currscope--;									// Decrementar nivel de scope
}

void printlocalvars()
{
	std::list<symrec *>::iterator ptr = sym_table->begin();	// Obtener inicio de tabla de simbolos locales
	std::list<symrec *>::iterator endptr = sym_table->end(); // Obtener fin de tabla de simbolos locales
	if(ptr==endptr)
		return;
	cout << "Tabla de variables locales ámbito " << currscope << endl;
	cout << "Name" << endl;
	while(ptr != endptr)
	{
		cout << (*ptr)->name;
		if(isfunction((*ptr)->typ))
			cout << " FUNC" << endl;
		else
			if(isconstant((*ptr)->typ))
				cout << " CONST" << endl;
			else
				cout << " VAR" << endl;
		ptr++;
	}
}

void printvars()
{
	std::list<symrec *>::iterator ptr = sym_table->begin();	// Obtener inicio de tabla de simbolos locales
	std::list<symrec *>::iterator endptr = sym_table->end(); // Obtener fin de tabla de simbolos locales
	std::list<std::list<symrec *> *>::iterator it = scopes.begin();
	if(currscope==0)
		cout << "Tabla de variables globales" << endl;
	else
		cout << "Tabla de variables locales ámbito " << currscope << endl;
	cout << "Name" << endl;
	while(1) {
		while(ptr != endptr){
			cout << (*ptr)->name;
			if(isfunction((*ptr)->typ))
				cout << " FUNC" << endl;
			else
				if(isconstant((*ptr)->typ))
					cout << " CONST" << endl;
				else
					cout << " VAR" << endl;
			ptr++;
		}
		if(it == scopes.end())
			break;
		ptr = (*it)->begin();
		endptr = (*it)->end();
		it++;
	};
}


