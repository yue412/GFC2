#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
#include <vector>
#include <memory>
#include "GfcEngine\GfcEngine.h"

namespace gfc2 {
    namespace schema {
        class CAttribute;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class Entity;
class EntityAttributeDataHandler;

class GFCENGINE_API Property
{
public:
    Property(char* pData, gfc2::schema::CAttribute* pAttribute);
    ~Property();
    gfc2::schema::CAttribute* getSchema() const { return m_pAttribute; }

    std::string propName() const;
public:
    bool isNull() const;

    std::string asString() const;
    int asInteger() const;
    double asDouble() const;
    bool asBoolean() const;
    EntityRef asEntityRef() const;
    Entity* asEntity() const;

    void setAsString(const std::string& sValue);
    void setAsInteger(const int& nValue);
    void setAsDouble(const double& dValue);
    void setAsBoolean(const bool& bValue);
    void setAsEntityRef(const EntityRef& nValue);

    std::vector<std::string>& asStringList() const;
    std::vector<int>& asIntegerList() const;
    std::vector<double>& asDoubleList() const;
    std::vector<bool>& asBooleanList() const;
    std::vector<EntityRef>& asEntityRefList() const;
private:
    EntityAttributeDataHandler* getDataHandler() const;
    char* m_pData;
    gfc2::schema::CAttribute* m_pAttribute;
};

typedef std::shared_ptr<Property> PropertyPtr;

GFCENGINE_NAMESPACE_END

#endif // !PROPERTY_H