#ifndef CONVERTER_H
#define CONVERTER_H

#include "GfcEngine/GfcEngine.h"
#include <string>
//#include "AttributeValue.h"

namespace gfc {
    namespace schema {
        class CEnumType;
        class CTypeObject;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class CPropValue;
class CEntity;
// 责任链
class GFCENGINE_API CConverter
{
public:
    CConverter() : m_pNext(nullptr), m_pFrom(nullptr), m_pTo(nullptr){}
    virtual ~CConverter();
    virtual void transform(CPropValue* pFrom, CPropValue* pTo);
    virtual void doTransform(CPropValue* pFrom, CPropValue* pTo) = 0;
    virtual CConverter* clone() = 0;
    void setNext(CConverter* pNext);
    CConverter* next() { return m_pNext; }
    void init(gfc::schema::CTypeObject* pFrom, gfc::schema::CTypeObject* pTo);
protected:
    CConverter* m_pNext;
    gfc::schema::CTypeObject* m_pFrom;
    gfc::schema::CTypeObject* m_pTo;
    CEntity* m_pFromEntity;
};


class GFCENGINE_API CEntityRefConverter : public CConverter
{
public:
    virtual void doTransform(CPropValue* pFrom, CPropValue* pTo);
    virtual CConverter* clone() { return new CEntityRefConverter(*this); }
};



GFCENGINE_NAMESPACE_END

#endif // !CONVERTER_H
