#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
#include <vector>
#include <memory>
#include "GfcEngine\GfcEngine.h"

namespace gfc {
    namespace schema {
        class CAttribute;
        class CTypeObject;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class CEntity;
class CPropValue;

class GFCENGINE_API CProperty
{
public:
    CProperty(gfc::schema::CAttribute* pAttribute, CPropValue* pValue);
    ~CProperty();

    gfc::schema::CAttribute* schema() const { return m_pAttribute; }
    std::wstring name() const;
    CPropValue* value() const;
    static CPropValue* createValue(gfc::schema::CTypeObject* pType);
private:
    CPropValue* m_pValue;
    gfc::schema::CAttribute* m_pAttribute;
};

GFCENGINE_NAMESPACE_END

#endif // !PROPERTY_H