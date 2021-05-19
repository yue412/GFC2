#include <Windows.h>
#include <string>
#include <assert.h>
#include "GfcEngine/Entity.h"
#include "GfcEngine/EngineException.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/Property.h"
#include "GfcEngine\PropValue.h"
#include "GfcSchema\EntityClass.h"
#include "GfcSchema\EntityAttribute.h"
#include "Common.h"

GFCENGINE_NAMESPACE_BEGIN

GFCENGINE_IMP_FACTORY(CEntity, 0)

CEntity::CEntity(void): m_pContainer(nullptr), m_pSchema(nullptr), m_pProps(nullptr), m_refId(-1)
{
    m_pProps = new std::vector<CProperty*>();
}

CEntity::~CEntity(void)
{
    free();
    delete m_pProps;
}

void CEntity::setContainer( IContainer* pContainer )
{
    m_pContainer = pContainer;
}

void CEntity::setRef(EntityRef refId) {
	m_refId = refId;
}

void CEntity::setSchema(gfc::schema::CTypeObject * pType)
{
    assert(pType);
    assert(pType->getDataType() == gfc::schema::EDT_ENTITY);
    if (pType != m_pSchema && pType->getDataType() == gfc::schema::EDT_ENTITY)
    {
        free();
        m_pSchema = pType;
        init();
    }
}

gfc::schema::CClass * CEntity::getClass() const
{
    if (m_pSchema)
    {
        return (gfc::schema::CClass *)m_pSchema->getBaseType();
    }
    return nullptr;
}

bool CEntity::isInitialized() const
{
    if (m_pSchema)
    {
        for (int i = 0; i < getClass()->getAttributeCount(); i++)
        {
            auto pAttr = getClass()->getAttribute(i);
            if (!pAttr->getOptionalFlag() && !pAttr->getRepeatFlag() && getProps(i)->value()->isNull())
                return false;
        }
    }
    return true;
}

int CEntity::getPropCount() const
{
    return (int)m_pProps->size();
}

CProperty* CEntity::getProps(int nIndex) const
{
    if (nIndex < (int)m_pProps->size() && nIndex >= 0)
        return (*m_pProps)[nIndex];
    else
        return nullptr;
}

CProperty * CEntity::propByName(const std::wstring sPropName) const
{
    if (m_pSchema)
    {
        auto pClass = getClass();
        int nIndex = -1;
        while (pClass)
        {
            auto pParent = pClass->getParent();
            nIndex = pClass->attributeIndexByName(sPropName);
            if (nIndex >= 0)
            {
                nIndex += pParent ? pParent->getTotalAttributeCount() : 0;
                break;
            }
            pClass = pParent;
        }
        return getProps(nIndex);
    }
    return nullptr;
}

bool CEntity::isNull(const std::wstring& sPropName) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->isNull();
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return true;
}

void CEntity::assignValue(const std::wstring sPropName, CPropValue * pValue)
{
    assert(pValue);
    auto pProperty = propByName(sPropName);
    if (pProperty)
    {
        pProperty->value()->assign(pValue);
    }
}

CPropValue * CEntity::valueByName(const std::wstring sPropName) const
{
    auto pProperty = propByName(sPropName);
    if (pProperty)
        return pProperty->value();
    else
        return nullptr;
}

std::wstring CEntity::entityName() const
{
    assert(m_pSchema);
    return m_pSchema->getName();
}

void CEntity::init()
{
    initProps(getClass());
}

void CEntity::initProps(gfc::schema::CClass* pClass)
{
    if (pClass)
    {
        initProps(pClass->getParent());
        for (int i = 0; i < pClass->getAttributeCount(); i++)
        {
            auto pAttr = pClass->getAttribute(i);
            if (pAttr->getRepeatFlag())
            {
                m_pProps->push_back(new CProperty(pAttr, new CCompositePropValue));
            }
            else
            {
                m_pProps->push_back(new CProperty(pAttr, CProperty::createValue(pAttr->getType())));
            }
        }
    }
}

void CEntity::free()
{
    for each (auto pProp in *m_pProps)
    {
        delete pProp;
    }
    m_pProps->clear();
}

std::wstring CEntity::asString(const std::wstring& sPropName) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->asString();
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return L"";
}

int CEntity::asInteger(const std::wstring& sPropName) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->asInteger();
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return 0;
}

double CEntity::asDouble(const std::wstring& sPropName) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->asDouble();
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return 0.0;
}

bool CEntity::asBoolean(const std::wstring& sPropName) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->asBoolean();
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return false;
}

EntityRef CEntity::asEntityRef(const std::wstring& sPropName) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->asEntityRef();
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return -1;
}

EntityPtr CEntity::asEntity(const std::wstring& sPropName) const
{
    if (m_pSchema && m_pContainer)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return m_pContainer->getEntity(pValue->asEntityRef());
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return nullptr;
}

void CEntity::setAsString(const std::wstring& sPropName, const std::wstring& sValue)
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->setAsString(sValue);
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

void CEntity::setAsInteger(const std::wstring& sPropName, const int& nValue)
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->setAsInteger(nValue);
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

void CEntity::setAsDouble(const std::wstring& sPropName, const double& dValue)
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->setAsDouble(dValue);
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

void CEntity::setAsBoolean(const std::wstring& sPropName, const bool& bValue)
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->setAsBoolean(bValue);
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

void CEntity::setAsEntityRef(const std::wstring& sPropName, const EntityRef& nValue)
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->setAsEntityRef(nValue);
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

int CEntity::getArrayCount(const std::wstring& sPropName) const
{
    if (m_pSchema)
        return getArrayCount(valueByName(sPropName));
    else
        return 0;
}

void CEntity::addEntityRef(const std::wstring& sPropName, const EntityRef& nValue)
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->add(new CEntityRefValue(nValue));
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

void CEntity::addString(const std::wstring& sPropName, const std::wstring& sValue)
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->add(new CStringValue(sValue));
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

void CEntity::addInteger(const std::wstring& sPropName, const int& nValue)
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->add(new CIntegerValue(nValue));
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

void CEntity::addDouble(const std::wstring& sPropName, const double& dValue)
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->add(new CDoubleValue(dValue));
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

void CEntity::addBoolean(const std::wstring& sPropName, const bool& bValue)
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            return pValue->add(new CBooleanValue(bValue));
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
}

std::wstring CEntity::getString(const std::wstring& sPropName, int nIndex) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            auto pVal = pValue->getItems(nIndex);
            return pVal ? pVal->asString() : L"";
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return L"";
}

int CEntity::getInteger(const std::wstring& sPropName, int nIndex) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            auto pVal = pValue->getItems(nIndex);
            return pVal ? pVal->asInteger() : 0;
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return 0;
}

double CEntity::getDouble(const std::wstring& sPropName, int nIndex) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            auto pVal = pValue->getItems(nIndex);
            return pVal ? pVal->asDouble() : 0.0;
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return 0.0;
}

bool CEntity::getBoolean(const std::wstring& sPropName, int nIndex) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            auto pVal = pValue->getItems(nIndex);
            return pVal ? pVal->asBoolean() : false;
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return false;
}

EntityRef CEntity::getEntityRef(const std::wstring& sPropName, int nIndex) const
{
    if (m_pSchema)
    {
        auto pValue = valueByName(sPropName);
        if (pValue)
        {
            auto pVal = pValue->getItems(nIndex);
            return pVal ? pVal->asEntityRef() : -1;
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return -1;
}

EntityPtr CEntity::getEntity(const std::wstring& sPropName, int nIndex) const
{
    if (m_pSchema && m_pContainer)
        return getEntity(valueByName(sPropName), nIndex);
    else
        return nullptr;
}

int CEntity::getArrayCount(CPropValue * pValue) const
{
    if (pValue)
    {
        return pValue->getCount();
    }
    else
    {
        throw EMissMatchProperty();
    }
}

EntityPtr CEntity::getEntity(CPropValue * pValue, int nIndex) const
{
    if (m_pContainer)
    {
        if (pValue)
        {
            auto pVal = pValue->getItems(nIndex);
            return m_pContainer->getEntity(pVal ? pVal->asEntityRef() : -1);
        }
        else
        {
            throw EMissMatchProperty();
        }
    }
    return nullptr;

}

bool CEntity::isNull(CPropValue * pValue, int nIndex) const
{
    if (pValue)
    {
        auto pVal = pValue->getItems(nIndex);
        return pVal ? pVal->isNull() : true;
    }
    else
    {
        throw EMissMatchProperty();
    }
}

std::wstring CEntity::toString() const
{
    std::wstring sResult = entityName() + L"#";
    for (std::size_t i = 0; i < m_pProps->size(); i++)
    {
        sResult += (*m_pProps)[i]->value()->toString() + L"@";
    }
    return sResult;
}

GFCENGINE_NAMESPACE_END