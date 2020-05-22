#ifndef GLODON_EXPRESS_ENTITY_H
#define GLODON_EXPRESS_ENTITY_H

#include <vector>
#include <string>
#include "GfcEngine\GfcEngine.h"
#include "GfcEngine\Property.h"

namespace gfc2 {
    namespace schema {
        class CClass;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class Document;

class GFCENGINE_API Entity
{
public:
    Entity(void);
    virtual ~Entity(void);
    void setDocument(Document* pDocument);
    void setSchema(gfc2::schema::CClass* pClass);
    gfc2::schema::CClass* getSchema() const { return m_pClass; }

    std::string entityName() const;
    bool isInitialized() const;
public:
    int getPropCount() const;
    PropertyPtr getProps(int nIndex) const;
    bool isNull(const std::string& sPropName) const;

    std::string asString(const std::string& sPropName) const;
    int asInteger(const std::string& sPropName) const;
    double asDouble(const std::string& sPropName) const;
    bool asBoolean(const std::string& sPropName) const;
    EntityRef asEntityRef(const std::string& sPropName) const;
    Entity* asEntity(const std::string& sPropName) const;

    void setAsString(const std::string& sPropName, const std::string& sValue);
    void setAsInteger(const std::string& sPropName, const int& nValue);
    void setAsDouble(const std::string& sPropName, const double& dValue);
    void setAsBoolean(const std::string& sPropName, const bool& bValue);
    void setAsEntityRef(const std::string& sPropName, const EntityRef& nValue);

    std::vector<std::string>& asStringList(const std::string& sPropName) const;
    std::vector<int>& asIntegerList(const std::string& sPropName) const;
    std::vector<double>& asDoubleList(const std::string& sPropName) const;
    std::vector<bool>& asBooleanList(const std::string& sPropName) const;
    std::vector<EntityRef>& asEntityRefList(const std::string& sPropName) const;
    //std::vector<Entity*>& asEntityList(const std::string& sPropName) const;
protected:
    Document* m_pDocument;
    gfc2::schema::CClass* m_pClass;
    char* m_pData;
private:
    void init();
    void free();
};

GFCENGINE_NAMESPACE_END

#endif
