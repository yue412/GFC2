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
class IContainer;

typedef std::shared_ptr<Entity> EntityPtr;

class GFCENGINE_API Entity
{
public:
    Entity(void);
    virtual ~Entity(void);
    void setContainer(IContainer* pContainer);
    void setSchema(gfc2::schema::CTypeObject* pType);
    gfc2::schema::CTypeObject* getSchema() const { return m_pSchema; }
    gfc2::schema::CClass* getClass() const;

    std::string entityName() const;
    bool isInitialized() const;
public:
    int getPropCount() const;
    Property* getProps(int nIndex) const;
    Property* propByName(const std::string sPropName) const;
    PropValue* valueByName(const std::string sPropName) const;
    bool isNull(const std::string& sPropName) const;

    std::string asString(const std::string& sPropName) const;
    int asInteger(const std::string& sPropName) const;
    double asDouble(const std::string& sPropName) const;
    bool asBoolean(const std::string& sPropName) const;
    EntityRef asEntityRef(const std::string& sPropName) const;
    EntityPtr asEntity(const std::string& sPropName) const;

    void setAsString(const std::string& sPropName, const std::string& sValue);
    void setAsInteger(const std::string& sPropName, const int& nValue);
    void setAsDouble(const std::string& sPropName, const double& dValue);
    void setAsBoolean(const std::string& sPropName, const bool& bValue);
    void setAsEntityRef(const std::string& sPropName, const EntityRef& nValue);

    // 数组属性读写方法
    int getArrayCount(const std::string& sPropName) const;

    void addEntityRef(const std::string& sPropName, const EntityRef& nValue);
    void addString(const std::string& sPropName, const std::string& sValue);
    void addInteger(const std::string& sPropName, const int& nValue);
    void addDouble(const std::string& sPropName, const double& dValue);
    void addBoolean(const std::string& sPropName, const bool& bValue);

    std::string getString(const std::string& sPropName, int nIndex) const;
    int getInteger(const std::string& sPropName, int nIndex) const;
    double getDouble(const std::string& sPropName, int nIndex) const;
    bool getBoolean(const std::string& sPropName, int nIndex) const;
    EntityRef getEntityRef(const std::string& sPropName, int nIndex) const;
    EntityPtr getEntity(const std::string& sPropName, int nIndex) const;
private:
    void init();
    void free();
    void initProps(gfc2::schema::CClass* pClass);

    IContainer* m_pContainer;
    gfc2::schema::CTypeObject* m_pSchema;
    std::vector<Property*>* m_pProps;
};

GFCENGINE_NAMESPACE_END

#endif
