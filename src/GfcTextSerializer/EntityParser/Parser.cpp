

#include <wchar.h>
#include "Parser.h"
#include "Scanner.h"


namespace gfc2 {


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

void Parser::GfcEntity() {
		Expect(_instance_name);
		m_sInstance = t->val; 
		Expect(7 /* "=" */);
		Entity();
}

void Parser::Entity() {
		Expect(_ident);
		m_sEntityName = t->val; 
		Expect(8 /* "(" */);
		if (StartOf(1)) {
			ParameterList(&m_oParameterList);
		}
		Expect(9 /* ")" */);
		Expect(10 /* ";" */);
}

void Parser::ParameterList(gfc2::schema::CAttributeValue* pParameterList) {
		gfc2::schema::CAttributeValuePtr pValue = nullptr; 
		Parameter(pValue);
		if(pParameterList) pParameterList->add(pValue); 
		while (la->kind == 11 /* "," */) {
			Get();
			Parameter(pValue);
			if(pParameterList) pParameterList->add(pValue); 
		}
}

void Parser::Parameter(gfc2::schema::CAttributeValuePtr& pValue) {
		if (StartOf(2)) {
			switch (la->kind) {
			case 12 /* "$" */: {
				Get();
				break;
			}
			case _integer: {
				Get();
				break;
			}
			case _real: {
				Get();
				break;
			}
			case _string: {
				Get();
				break;
			}
			case _instance_name: {
				Get();
				break;
			}
			case _enumeration: {
				Get();
				break;
			}
			case 13 /* "*" */: {
				Get();
				break;
			}
			}
			pValue = gfc2::schema::CAttributeValuePtr(new gfc2::schema::CLeafAttributeValue(t->val)); 
		} else if (la->kind == 8 /* "(" */) {
			List(pValue);
		} else SynErr(15);
}

void Parser::List(gfc2::schema::CAttributeValuePtr& pValue) {
		pValue = gfc2::schema::CAttributeValuePtr(new gfc2::schema::CCompositeAttributeValue); 
		Expect(8 /* "(" */);
		if (StartOf(1)) {
			ParameterList(pValue.get());
		}
		Expect(9 /* ")" */);
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
	GfcEntity();
	Expect(0);
}

Parser::Parser(Scanner *scanner) {
	maxT = 14;

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

	static bool set[3][16] = {
		{T,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,x,T,T, T,T,T,x, T,x,x,x, T,T,x,x},
		{x,x,T,T, T,T,T,x, x,x,x,x, T,T,x,x}
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
			case 2: s = coco_string_create(L"integer expected"); break;
			case 3: s = coco_string_create(L"real expected"); break;
			case 4: s = coco_string_create(L"string expected"); break;
			case 5: s = coco_string_create(L"instance_name expected"); break;
			case 6: s = coco_string_create(L"enumeration expected"); break;
			case 7: s = coco_string_create(L"\"=\" expected"); break;
			case 8: s = coco_string_create(L"\"(\" expected"); break;
			case 9: s = coco_string_create(L"\")\" expected"); break;
			case 10: s = coco_string_create(L"\";\" expected"); break;
			case 11: s = coco_string_create(L"\",\" expected"); break;
			case 12: s = coco_string_create(L"\"$\" expected"); break;
			case 13: s = coco_string_create(L"\"*\" expected"); break;
			case 14: s = coco_string_create(L"??? expected"); break;
			case 15: s = coco_string_create(L"invalid Parameter"); break;

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

} // namespace

