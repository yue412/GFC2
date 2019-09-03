#include "StdAfx.h"
#include "Gfc2IntegerProperty.h"
#include "Gfc2IntegerPropertyBinarySerializer.h"
#include "Gfc2IntegerPropertyTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2IntegerProperty,"Gfc2IntegerProperty",0)

OBJECTBUF_IMP_OBJECT(Gfc2IntegerPropertyFieldCacheInitializer,"Gfc2IntegerProperty",0)

Gfc2IntegerProperty::Gfc2IntegerProperty()
{
    m_nValue = 0;
}

bool Gfc2IntegerProperty::isInitialized() const
{
    if ((_has_bits_[0] & 0x3) != 0x3) return false;

    return true;
}

int Gfc2IntegerProperty::typeId() const
{
    return 58;
}

glodon::objectbuf::EntitySchema* Gfc2IntegerProperty::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(58))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Property::createSchema());
    pSchema->setName("Gfc2IntegerProperty");
    pSchema->setId(58);
    m_pDocument->addSchema(pSchema, 58);

    pSchema->addAttribNames("Value");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2IntegerProperty::entityName() const
{
    return "Gfc2IntegerProperty";
}

void Gfc2IntegerPropertyFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2IntegerProperty_Value = getFieldId(oFieldIdMap, "Gfc2IntegerProperty::Value");
}

