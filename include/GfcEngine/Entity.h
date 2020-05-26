#ifndef GLODON_EXPRESS_ENTITY_H
#define GLODON_EXPRESS_ENTITY_H

#include <vector>
#include <string>
#include "GfcEngine\GfcEngine.h"
#include "GfcEngine\Property.h"

namespace gfc2 {
    namespace schema {
        class CClass;
        class CTypeObject;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class Document;
class Property;
class PropValue;

class GFCENGINE_API Entity
{
public:
    Entity(void);
    virtual ~Entity(void);
    void setDocument(Document* pDocument);
    void setSchema(gfc2::schema::CTypeObject* pType);
    gfc2::schema::CTypeObject* getSchema() const { return m_pSchema; }
    gfc2::schema::CClass* getClass() const;

    std::string entityName() const;
    bool isInitialized() const;
public:
    int getPropCount() const;
    Property* getProps(int nIndex) const;
    bool isNull(const std::string& sPropName) const;
    PropValue* valueByName(const std::string sPropName) const;

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
protected:
    Document* m_pDocument;
    gfc2::schema::CTypeObject* m_pSchema;
private:
    void init();
    void free();
    std::vector<Property*> m_oProps;
};

typedef std::shared_ptr<Entity> EntityPtr;

GFCENGINE_NAMESPACE_END

#endif
