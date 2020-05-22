

#include <wchar.h>
#include "Parser.h"
#include "Scanner.h"




void Parser::SynErr(int n) {
	if (errDist >= minErrDist) errors->SynErr(la->line, la->col, n);
	errDist = 0;
}

void Parser::SemErr(const wchar_t* msg) {
	if (errDist >= minErrDist) errors->Error(t->line, t->col, msg);
	errDist = 0;
}

void Parser::Get() {
	for (;;) {
		t = la;
		la = scanner->Scan();
		if (la->kind <= maxT) { ++errDist; break; }

		if (dummyToken != t) {
			dummyToken->kind = t->kind;
			dummyToken->pos = t->pos;
			dummyToken->col = t->col;
			dummyToken->line = t->line;
			dummyToken->next = NULL;
			coco_string_delete(dummyToken->val);
			dummyToken->val = coco_string_create(t->val);
			t = dummyToken;
		}
		la = t;
	}
}

void Parser::Expect(int n) {
	if (la->kind==n) Get(); else { SynErr(n); }
}

void Parser::ExpectWeak(int n, int follow) {
	if (la->kind == n) Get();
	else {
		SynErr(n);
		while (!StartOf(follow)) Get();
	}
}

bool Parser::WeakSeparator(int n, int syFol, int repFol) {
	if (la->kind == n) {Get(); return true;}
	else if (StartOf(repFol)) {return false;}
	else {
		SynErr(n);
		while (!(StartOf(syFol) || StartOf(repFol) || StartOf(0))) {
			Get();
		}
		return StartOf(syFol);
	}
}

void Parser::ExpFile() {
		Expect(3 /* "SCHEMA" */);
		Expect(_ident);
		m_sName = t->val; 
		Expect(4 /* ";" */);
		while (la->kind == 6 /* "TYPE" */ || la->kind == 14 /* "ENTITY" */) {
			if (la->kind == 6 /* "TYPE" */) {
				TypedefOrEnum();
			} else {
				Entity();
			}
			Expect(4 /* ";" */);
		}
		Expect(5 /* "END_SCHEMA" */);
		Expect(4 /* ";" */);
		finalize(); 
}

void Parser::TypedefOrEnum() {
		Expect(6 /* "TYPE" */);
		Expect(_ident);
		std::wstring sTypeName = t->val; 
		Expect(7 /* "=" */);
		if (la->kind == _ident) {
			Get();
			gfc2::schema::CTypeDef* pTypeDef = new gfc2::schema::CTypeDef(sTypeName);
			m_pModel->addTypeObject(pTypeDef); 
			auto pRefType = findType(t->val);
			pTypeDef->SetRefType(pRefType);
			
		} else if (la->kind == 8 /* "ENUMERATION" */) {
			Get();
			Expect(9 /* "OF" */);
			Expect(10 /* "(" */);
			CStringList oEnumList; 
			IdentList(oEnumList);
			gfc2::schema::CEnumType* pEnumType = new gfc2::schema::CEnumType(sTypeName);
			m_pModel->addTypeObject(pEnumType); 
			for each (auto sEnum in oEnumList)
			{
			   pEnumType->addEnum(sEnum, L"");
			}
			
			Expect(11 /* ")" */);
		} else SynErr(27);
		Expect(4 /* ";" */);
		Expect(12 /* "END_TYPE" */);
}

void Parser::Entity() {
		Expect(14 /* "ENTITY" */);
		Expect(_ident);
		auto pClass = getClass(t->val);
		pClass->setIsValid(true);
		
		if (la->kind == 16 /* "ABSTRACT" */ || la->kind == 17 /* "SUPERTYPE" */ || la->kind == 19 /* "SUBTYPE" */) {
			if (la->kind == 16 /* "ABSTRACT" */ || la->kind == 17 /* "SUPERTYPE" */) {
				SuperType(pClass);
				if (la->kind == 19 /* "SUBTYPE" */) {
					SubType(pClass);
				}
			} else {
				SubType(pClass);
				if (la->kind == 16 /* "ABSTRACT" */ || la->kind == 17 /* "SUPERTYPE" */) {
					SuperType(pClass);
				}
			}
		}
		Expect(4 /* ";" */);
		while (la->kind == _ident) {
			gfc2::schema::CAttribute* pAttribute = new gfc2::schema::CAttribute; 
			Attribute(pAttribute);
			pClass->addAttribute(pAttribute); 
			Expect(4 /* ";" */);
		}
		Expect(15 /* "END_ENTITY" */);
}

void Parser::IdentList(CStringList& oStringList) {
		Expect(_ident);
		oStringList.push_back(t->val); 
		while (la->kind == 13 /* "," */) {
			Get();
			Expect(_ident);
			oStringList.push_back(t->val); 
		}
}

void Parser::SuperType(gfc2::schema::CClass* pClass) {
		if (la->kind == 16 /* "ABSTRACT" */) {
			Get();
			pClass->setIsAbstract(true); 
		}
		Expect(17 /* "SUPERTYPE" */);
		Expect(9 /* "OF" */);
		Expect(10 /* "(" */);
		Expect(18 /* "ONEOF" */);
		Expect(10 /* "(" */);
		CStringList oChildList; 
		IdentList(oChildList);
		for each (auto sName in oChildList)
		{
		   auto pChild = getClass(sName);
		   pClass->addChild(pChild);
		}
		
		Expect(11 /* ")" */);
		Expect(11 /* ")" */);
}

void Parser::SubType(gfc2::schema::CClass* pClass) {
		Expect(19 /* "SUBTYPE" */);
		Expect(9 /* "OF" */);
		Expect(10 /* "(" */);
		Expect(_ident);
		auto pParent = getClass(t->val);
		pClass->setParent(pParent);
		
		Expect(11 /* ")" */);
}

void Parser::Attribute(gfc2::schema::CAttribute* pAttribute) {
		Expect(_ident);
		pAttribute->SetName(t->val); 
		Expect(20 /* ":" */);
		AttributeType(pAttribute);
}

void Parser::AttributeType(gfc2::schema::CAttribute* pAttribute) {
		if (la->kind == _ident || la->kind == 21 /* "OPTIONAL" */) {
			if (la->kind == 21 /* "OPTIONAL" */) {
				Get();
				pAttribute->SetOptionalFlag(true); 
			}
			Expect(_ident);
			auto pType = findType(t->val);
			pAttribute->SetType(pType);
			
		} else if (la->kind == 22 /* "LIST" */) {
			Get();
			Expect(23 /* "[" */);
			Expect(_number);
			Expect(20 /* ":" */);
			if (la->kind == _number) {
				Get();
			} else if (la->kind == 24 /* "?" */) {
				Get();
			} else SynErr(28);
			Expect(25 /* "]" */);
			Expect(9 /* "OF" */);
			Expect(_ident);
			auto pType = findType(t->val);
			pAttribute->SetType(pType);
			pAttribute->SetRepeatFlag(true);
			
		} else SynErr(29);
}




// If the user declared a method Init and a mehtod Destroy they should
// be called in the contructur and the destructor respctively.
//
// The following templates are used to recognize if the user declared
// the methods Init and Destroy.

template<typename T>
struct ParserInitExistsRecognizer {
	template<typename U, void (U::*)() = &U::Init>
	struct ExistsIfInitIsDefinedMarker{};

	struct InitIsMissingType {
		char dummy1;
	};
	
	struct InitExistsType {
		char dummy1; char dummy2;
	};

	// exists always
	template<typename U>
	static InitIsMissingType is_here(...);

	// exist only if ExistsIfInitIsDefinedMarker is defined
	template<typename U>
	static InitExistsType is_here(ExistsIfInitIsDefinedMarker<U>*);

	enum { InitExists = (sizeof(is_here<T>(NULL)) == sizeof(InitExistsType)) };
};

template<typename T>
struct ParserDestroyExistsRecognizer {
	template<typename U, void (U::*)() = &U::Destroy>
	struct ExistsIfDestroyIsDefinedMarker{};

	struct DestroyIsMissingType {
		char dummy1;
	};
	
	struct DestroyExistsType {
		char dummy1; char dummy2;
	};

	// exists always
	template<typename U>
	static DestroyIsMissingType is_here(...);

	// exist only if ExistsIfDestroyIsDefinedMarker is defined
	template<typename U>
	static DestroyExistsType is_here(ExistsIfDestroyIsDefinedMarker<U>*);

	enum { DestroyExists = (sizeof(is_here<T>(NULL)) == sizeof(DestroyExistsType)) };
};

// The folloing templates are used to call the Init and Destroy methods if they exist.

// Generic case of the ParserInitCaller, gets used if the Init method is missing
template<typename T, bool = ParserInitExistsRecognizer<T>::InitExists>
struct ParserInitCaller {
	static void CallInit(T *t) {
		// nothing to do
	}
};

// True case of the ParserInitCaller, gets used if the Init method exists
template<typename T>
struct ParserInitCaller<T, true> {
	static void CallInit(T *t) {
		t->Init();
	}
};

// Generic case of the ParserDestroyCaller, gets used if the Destroy method is missing
template<typename T, bool = ParserDestroyExistsRecognizer<T>::DestroyExists>
struct ParserDestroyCaller {
	static void CallDestroy(T *t) {
		// nothing to do
	}
};

// True case of the ParserDestroyCaller, gets used if the Destroy method exists
template<typename T>
struct ParserDestroyCaller<T, true> {
	static void CallDestroy(T *t) {
		t->Destroy();
	}
};

void Parser::Parse() {
	t = NULL;
	la = dummyToken = new Token();
	la->val = coco_string_create(L"Dummy Token");
	Get();
	ExpFile();
	Expect(0);
}

Parser::Parser(Scanner *scanner) {
	maxT = 26;

	ParserInitCaller<Parser>::CallInit(this);
	dummyToken = NULL;
	t = la = NULL;
	minErrDist = 2;
	errDist = minErrDist;
	this->scanner = scanner;
	errors = new Errors();
}

bool Parser::StartOf(int s) {
	const bool T = true;
	const bool x = false;

	static bool set[1][28] = {
		{T,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x}
	};



	return set[s][la->kind];
}

Parser::~Parser() {
	ParserDestroyCaller<Parser>::CallDestroy(this);
	delete errors;
	delete dummyToken;
}

Errors::Errors() {
	count = 0;
}

void Errors::SynErr(int line, int col, int n) {
	wchar_t* s;
	switch (n) {
			case 0: s = coco_string_create(L"EOF expected"); break;
			case 1: s = coco_string_create(L"ident expected"); break;
			case 2: s = coco_string_create(L"number expected"); break;
			case 3: s = coco_string_create(L"\"SCHEMA\" expected"); break;
			case 4: s = coco_string_create(L"\";\" expected"); break;
			case 5: s = coco_string_create(L"\"END_SCHEMA\" expected"); break;
			case 6: s = coco_string_create(L"\"TYPE\" expected"); break;
			case 7: s = coco_string_create(L"\"=\" expected"); break;
			case 8: s = coco_string_create(L"\"ENUMERATION\" expected"); break;
			case 9: s = coco_string_create(L"\"OF\" expected"); break;
			case 10: s = coco_string_create(L"\"(\" expected"); break;
			case 11: s = coco_string_create(L"\")\" expected"); break;
			case 12: s = coco_string_create(L"\"END_TYPE\" expected"); break;
			case 13: s = coco_string_create(L"\",\" expected"); break;
			case 14: s = coco_string_create(L"\"ENTITY\" expected"); break;
			case 15: s = coco_string_create(L"\"END_ENTITY\" expected"); break;
			case 16: s = coco_string_create(L"\"ABSTRACT\" expected"); break;
			case 17: s = coco_string_create(L"\"SUPERTYPE\" expected"); break;
			case 18: s = coco_string_create(L"\"ONEOF\" expected"); break;
			case 19: s = coco_string_create(L"\"SUBTYPE\" expected"); break;
			case 20: s = coco_string_create(L"\":\" expected"); break;
			case 21: s = coco_string_create(L"\"OPTIONAL\" expected"); break;
			case 22: s = coco_string_create(L"\"LIST\" expected"); break;
			case 23: s = coco_string_create(L"\"[\" expected"); break;
			case 24: s = coco_string_create(L"\"?\" expected"); break;
			case 25: s = coco_string_create(L"\"]\" expected"); break;
			case 26: s = coco_string_create(L"??? expected"); break;
			case 27: s = coco_string_create(L"invalid TypedefOrEnum"); break;
			case 28: s = coco_string_create(L"invalid AttributeType"); break;
			case 29: s = coco_string_create(L"invalid AttributeType"); break;

		default:
		{
			wchar_t format[20];
			coco_swprintf(format, 20, L"error %d", n);
			s = coco_string_create(format);
		}
		break;
	}
	wprintf(L"-- line %d col %d: %ls\n", line, col, s);
	coco_string_delete(s);
	count++;
}

void Errors::Error(int line, int col, const wchar_t *s) {
	wprintf(L"-- line %d col %d: %ls\n", line, col, s);
	count++;
}

void Errors::Warning(int line, int col, const wchar_t *s) {
	wprintf(L"-- line %d col %d: %ls\n", line, col, s);
}

void Errors::Warning(const wchar_t *s) {
	wprintf(L"%ls\n", s);
}

void Errors::Exception(const wchar_t* s) {
	wprintf(L"%ls", s); 
	exit(1);
}


