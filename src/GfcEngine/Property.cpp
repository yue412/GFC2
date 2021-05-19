#include "GfcEngine\Property.h"
#include "GfcEngine\PropValue.h"
#include "GfcSchema\EntityAttribute.h"
#include "GfcSchema\TypeObject.h"
#include "Common.h"
#include <assert.h>

GFCENGINE_NAMESPACE_BEGIN

CProperty::CProperty(gfc::schema::CAttribute* pAttribute, CPropValue* pValue): m_pValue(pValue), m_pAttribute(pAttribute)
{
}

CProperty::~CProperty()
{
    delete m_pValue;
}

std::wstring CProperty::name() const
{
    return m_pAttribute->getName();
}

CPropValue * CProperty::value() const
{
    return m_pValue;
}

CPropValue * CProperty::createValue(gfc::schema::CTypeObject * pType)
{
    CPropValue* pResult = nullptr;
    switch (pType->getDataType())
    {
    case gfc::schema::EDT_BOOLEAN:
        pResult = new CBooleanValue;
        break;
    case gfc::schema::EDT_INTEGER:
        pResult = new CIntegerValue;
        break;
    case gfc::schema::EDT_DOUBLE:
        pResult = new CDoubleValue;
        break;
    case gfc::schema::EDT_STRING:
        pResult = new CStringValue;
        break;
    case gfc::schema::EDT_ENUM:
        pResult = new CIntegerValue;
        break;
    case gfc::schema::EDT_ENTITY:
        pResult = new CEntityRefValue;
        break;
    default:
        assert(false);
        //pResult = new CLeafPropValue;
        break;
    }
    return pResult;
}

GFCENGINE_NAMESPACE_END