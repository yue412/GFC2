

#if !defined(gfc2_COCO_PARSER_H__)
#define gfc2_COCO_PARSER_H__

#include <string>
#include <vector>
#include "AttributeValue.h"


#include "Scanner.h"

namespace gfc {


class Errors {
public:
	int count;			// number of errors detected

	Errors();
	void SynErr(int line, int col, int n);
	void Error(int line, int col, const wchar_t *s);
	void Warning(int line, int col, const wchar_t *s);
	void Warning(const wchar_t *s);
	void Exception(const wchar_t *s);

}; // Errors

class Parser {
private:
	enum {
		_EOF=0,
		_ident=1,
		_integer=2,
		_real=3,
		_string=4,
		_instance_name=5,
		_enumeration=6
	};
	int maxT;

	Token *dummyToken;
	int errDist;
	int minErrDist;

	void SynErr(int n);
	void Get();
	void Expect(int n);
	bool StartOf(int s);
	void ExpectWeak(int n, int follow);
	bool WeakSeparator(int n, int syFol, int repFol);

public:
	Scanner *scanner;
	Errors  *errors;

	Token *t;			// last recognized token
	Token *la;			// lookahead token

std::wstring m_sEntityName;
std::wstring m_sInstance;
//typedef std::vector<std::wstring> CStringList;
gfc::schema::CCompositeAttributeValue m_oParameterList;



	Parser(Scanner *scanner);
	~Parser();
	void SemErr(const wchar_t* msg);

	void GfcEntity();
	void Entity();
	void ParameterList(gfc::schema::CAttributeValue* pParameterList);
	void Parameter(gfc::schema::CAttributeValuePtr& pValue);
	void List(gfc::schema::CAttributeValuePtr& pValue);

	void Parse();

}; // end Parser

} // namespace


#endif

