#include "GfcEngine\Property.h"
#include "GfcEngine\PropValue.h"
#include "GfcSchema\EntityAttribute.h"
#include "GfcSchema\TypeObject.h"
#include "Common.h"
#include <assert.h>

GFCENGINE_NAMESPACE_BEGIN

Property::Property(gfc::schema::CAttribute* pAttribute, PropValue* pValue): m_pValue(pValue), m_pAttribute(pAttribute)
{
}

Property::~Property()
{
    delete m_pValue;
}

std::wstring Property::name() const
{
    return m_pAttribute->getName();
}

PropValue * Property::value() const
{
    return m_pValue;
}

PropValue * Property::createValue(gfc::schema::CTypeObject * pType)
{
    PropValue* pResult;
    switch (pType->getDataType())
    {
    case gfc::schema::EDT_BOOLEAN:
        pResult = new BooleanValue;
        break;
    case gfc::schema::EDT_INTEGER:
        pResult = new IntegerValue;
        break;
    case gfc::schema::EDT_DOUBLE:
        pResult = new DoubleValue;
        break;
    case gfc::schema::EDT_STRING:
        pResult = new StringValue;
        break;
    case gfc::schema::EDT_ENUM:
        pResult = new IntegerValue;
        break;
    case gfc::schema::EDT_ENTITY:
        pResult = new EntityRefValue;
        break;
    default:
        assert(false);
        pResult = new LeafPropValue;
        break;
    }
    return pResult;
}

GFCENGINE_NAMESPACE_END