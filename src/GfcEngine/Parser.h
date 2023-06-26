

#if !defined(COCO_PARSER_H__)
#define COCO_PARSER_H__

#include <string>
#include "GfcSchema/Model.h"
#include "GfcSchema/TypeDefine.h"
#include "GfcSchema/EnumType.h"
#include "GfcSchema/EntityClass.h"
#include "GfcSchema/EntityAttribute.h"
#include "GfcSchema/UndefineType.h"


#include "Scanner.h"



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
		_number=2
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

gfc::schema::CModel* m_pModel;
gfc::schema::CModel* m_pTempModel;
typedef std::vector<std::wstring> CStringList;
std::wstring m_sName;

void throwException(const std::wstring& sMsg)
{
    errors->Error(t->line, t->col, sMsg.c_str());
    throw std::runtime_error(coco_string_create_char(sMsg.c_str()));
}

void canNotFindEntity(const std::wstring& sName)
{
    std::wstring sMsg = L"Can not find Entity: " + sName;
    throwException(sMsg);
}

void canNotFindType(const std::wstring& sName)
{
    std::wstring sMsg = L"Can not find type: " + sName;
    throwException(sMsg);
}

gfc::schema::CTypeObject* findType(const std::wstring& sName)
{
    auto pType = m_pModel->findTypeObject(sName);
    if(pType == nullptr)
    {
        pType = new gfc::schema::CUndefineType(sName);
        //m_pModel->addTypeObject(pType);
        m_pTempModel->addTypeObject(pType);
    }
    return pType;
}

gfc::schema::CClass* getClass(const std::wstring& sName)
{
    auto pType = m_pModel->findTypeObject(sName);
    if(pType == nullptr)
    {
        auto pClass = new gfc::schema::CClass(sName);
        pClass->setIsValid(false);
        m_pModel->addTypeObject(pClass);
        return pClass;
    }
    else 
    {
        auto pClass = dynamic_cast<gfc::schema::CClass*>(pType);
        if (pClass == nullptr)
            canNotFindEntity(sName);
        return pClass;
    }
}

void finalize()
{
    for (int i = 0; i < m_pModel->getTypeObjectCount(); i++)
    {
        auto pType = m_pModel->getTypeObject(i);
        switch (pType->getType())
        {
        case gfc::schema::TOE_TYPE: {
            auto pTypeDef = dynamic_cast<gfc::schema::CTypeDef*>(pType);
            if (pTypeDef->getRefType()->getType() == gfc::schema::TOE_UNDEFINE)
            {
                auto sName = pTypeDef->getRefType()->getName();
                auto pRefType = m_pModel->findTypeObject(sName);
                if (pRefType == nullptr)
                    canNotFindType(sName);
                else
                    pTypeDef->SetRefType(pRefType);
            }
            break;
        }
        case gfc::schema::TOE_CLASS: {
            auto pClass = dynamic_cast<gfc::schema::CClass*>(pType);
            if (pClass->getParent() && !pClass->getParent()->getIsValid())
                canNotFindEntity(pClass->getParent()->getName());
            for (int i = 0; i < pClass->getChildCount(); i++)
            {
                auto pChild = pClass->getChild(i);
                if (!pChild->getIsValid())
                    canNotFindEntity(pChild->getName());
            }
            for (int i = 0; i < pClass->getAttributeCount(); i++)
            {
                auto pAttribute = pClass->getAttribute(i);
                if (pAttribute->getType()->getType() == gfc::schema::TOE_UNDEFINE)
                {
                    auto sName = pAttribute->getType()->getName();
                    auto pRefType = m_pModel->findTypeObject(sName);
                    if (pRefType == nullptr)
                        canNotFindType(sName);
                    else
                        pAttribute->SetType(pRefType);
                }
            }
            break;
        }
        default:
            break;
        }
    }
}



	Parser(Scanner *scanner);
	~Parser();
	void SemErr(const wchar_t* msg);

	void ExpFile();
	void TypedefOrEnum();
	void Entity();
	void IdentList(CStringList& oStringList);
	void SuperType(gfc::schema::CClass* pClass);
	void SubType(gfc::schema::CClass* pClass);
	void Attribute(gfc::schema::CAttribute* pAttribute);
	void AttributeType(gfc::schema::CAttribute* pAttribute);

	void Parse();

}; // end Parser



#endif

