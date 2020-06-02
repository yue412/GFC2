#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
#include <vector>
#include <memory>
#include "GfcEngine\GfcEngine.h"

namespace gfc2 {
    namespace schema {
        class CAttribute;
        class CTypeObject;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class Entity;
class PropValue;

class GFCENGINE_API Property
{
public:
    Property(gfc2::schema::CAttribute* pAttribute, PropValue* pValue);
    ~Property();

    gfc2::schema::CAttribute* schema() const { return m_pAttribute; }
    std::wstring name() const;
    PropValue* value() const;
    static PropValue* createValue(gfc2::schema::CTypeObject* pType);
private:
    PropValue* m_pValue;
    gfc2::schema::CAttribute* m_pAttribute;
};

GFCENGINE_NAMESPACE_END

#endif // !PROPERTY_H