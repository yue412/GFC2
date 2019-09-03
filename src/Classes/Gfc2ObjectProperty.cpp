#include "StdAfx.h"
#include "Gfc2ObjectProperty.h"
#include "Gfc2ObjectPropertyBinarySerializer.h"
#include "Gfc2ObjectPropertyTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2ObjectProperty,"Gfc2ObjectProperty",0)

OBJECTBUF_IMP_OBJECT(Gfc2ObjectPropertyFieldCacheInitializer,"Gfc2ObjectProperty",0)

Gfc2ObjectProperty::Gfc2ObjectProperty()
{
    m_nValue = 0;
}

bool Gfc2ObjectProperty::isInitialized() const
{
    if ((_has_bits_[0] & 0x3) != 0x3) return false;

    return true;
}

int Gfc2ObjectProperty::typeId() const
{
    return 74;
}

glodon::objectbuf::EntitySchema* Gfc2ObjectProperty::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(74))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Property::createSchema());
    pSchema->setName("Gfc2ObjectProperty");
    pSchema->setId(74);
    m_pDocument->addSchema(pSchema, 74);

    pSchema->addAttribNames("Value");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2ObjectProperty::entityName() const
{
    return "Gfc2ObjectProperty";
}

void Gfc2ObjectPropertyFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2ObjectProperty_Value = getFieldId(oFieldIdMap, "Gfc2ObjectProperty::Value");
}

