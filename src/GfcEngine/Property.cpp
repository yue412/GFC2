#include "GfcEngine\Property.h"
#include "GfcEngine\PropValue.h"
#include "EntityAttribute.h"
#include "TypeObject.h"
#include "Common.h"
#include <assert.h>

GFCENGINE_NAMESPACE_BEGIN

Property::Property(gfc2::schema::CAttribute* pAttribute, PropValue* pValue): m_pValue(pValue), m_pAttribute(pAttribute)
{
}

Property::~Property()
{
    delete m_pValue;
}

std::string Property::name() const
{
    return toString(m_pAttribute->getName());
}

PropValue * Property::value() const
{
    return m_pValue;
}

PropValue * Property::createValue(gfc2::schema::CTypeObject * pType)
{
    PropValue* pResult;
    switch (pType->getDataType())
    {
    case gfc2::schema::EDT_BOOLEAN:
        pResult = new BooleanValue;
        break;
    case gfc2::schema::EDT_INTEGER:
        pResult = new IntegerValue;
        break;
    case gfc2::schema::EDT_DOUBLE:
        pResult = new DoubleValue;
        break;
    case gfc2::schema::EDT_STRING:
        pResult = new StringValue;
        break;
    case gfc2::schema::EDT_ENUM:
        pResult = new IntegerValue;
        break;
    case gfc2::schema::EDT_ENTITY:
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