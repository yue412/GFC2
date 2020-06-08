#ifndef GLODON_EXPRESS_ENTITY_H
#define GLODON_EXPRESS_ENTITY_H

#include <vector>
#include <string>
#include "GfcEngine\GfcEngine.h"
#include "GfcEngine\Property.h"
#include "GfcEngine\Object.h"
#include "GfcEngine\SysMarco.h"

namespace gfc {
    namespace schema {
        class CClass;
        class CTypeObject;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class CDocument;
class CProperty;
class CPropValue;
class IContainer;

typedef std::shared_ptr<CEntity> EntityPtr;

class GFCENGINE_API CEntity: public CObject
{
    GFCENGINE_DEC_FACTORY(CEntity, 0, std::wstring)
public:
    CEntity(void);
    virtual ~CEntity(void);
    void setContainer(IContainer* pContainer);
    void setSchema(gfc::schema::CTypeObject* pType);
    gfc::schema::CTypeObject* getSchema() const { return m_pSchema; }
    gfc::schema::CClass* getClass() const;

    std::wstring entityName() const;
    bool isInitialized() const;
public:
    int getPropCount() const;
    CProperty* getProps(int nIndex) const;
    CProperty* propByName(const std::wstring sPropName) const;
    CPropValue* valueByName(const std::wstring sPropName) const;
    bool isNull(const std::wstring& sPropName) const;

    std::string asString(const std::wstring& sPropName) const;
    int asInteger(const std::wstring& sPropName) const;
    double asDouble(const std::wstring& sPropName) const;
    bool asBoolean(const std::wstring& sPropName) const;
    EntityRef asEntityRef(const std::wstring& sPropName) const;
    EntityPtr asEntity(const std::wstring& sPropName) const;

    void setAsString(const std::wstring& sPropName, const std::string& sValue);
    void setAsInteger(const std::wstring& sPropName, const int& nValue);
    void setAsDouble(const std::wstring& sPropName, const double& dValue);
    void setAsBoolean(const std::wstring& sPropName, const bool& bValue);
    void setAsEntityRef(const std::wstring& sPropName, const EntityRef& nValue);

    // �������Զ�д����
    int getArrayCount(const std::wstring& sPropName) const;

    void addEntityRef(const std::wstring& sPropName, const EntityRef& nValue);
    void addString(const std::wstring& sPropName, const std::string& sValue);
    void addInteger(const std::wstring& sPropName, const int& nValue);
    void addDouble(const std::wstring& sPropName, const double& dValue);
    void addBoolean(const std::wstring& sPropName, const bool& bValue);

    std::string getString(const std::wstring& sPropName, int nIndex) const;
    int getInteger(const std::wstring& sPropName, int nIndex) const;
    double getDouble(const std::wstring& sPropName, int nIndex) const;
    bool getBoolean(const std::wstring& sPropName, int nIndex) const;
    EntityRef getEntityRef(const std::wstring& sPropName, int nIndex) const;
    EntityPtr getEntity(const std::wstring& sPropName, int nIndex) const;
protected:
    IContainer* getContainer() { return m_pContainer; }
private:
    void init();
    void free();
    void initProps(gfc::schema::CClass* pClass);

    IContainer* m_pContainer;
    gfc::schema::CTypeObject* m_pSchema;
    std::vector<CProperty*>* m_pProps;
};

GFCENGINE_NAMESPACE_END

#endif