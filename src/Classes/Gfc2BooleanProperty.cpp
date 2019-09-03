#include "StdAfx.h"
#include "Gfc2BooleanProperty.h"
#include "Gfc2BooleanPropertyBinarySerializer.h"
#include "Gfc2BooleanPropertyTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2BooleanProperty,"Gfc2BooleanProperty",0)

OBJECTBUF_IMP_OBJECT(Gfc2BooleanPropertyFieldCacheInitializer,"Gfc2BooleanProperty",0)

Gfc2BooleanProperty::Gfc2BooleanProperty()
{
    m_bValue = false;
}

bool Gfc2BooleanProperty::isInitialized() const
{
    if ((_has_bits_[0] & 0x3) != 0x3) return false;

    return true;
}

int Gfc2BooleanProperty::typeId() const
{
    return 14;
}

glodon::objectbuf::EntitySchema* Gfc2BooleanProperty::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(14))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Property::createSchema());
    pSchema->setName("Gfc2BooleanProperty");
    pSchema->setId(14);
    m_pDocument->addSchema(pSchema, 14);

    pSchema->addAttribNames("Value");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2BooleanProperty::entityName() const
{
    return "Gfc2BooleanProperty";
}

void Gfc2BooleanPropertyFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2BooleanProperty_Value = getFieldId(oFieldIdMap, "Gfc2BooleanProperty::Value");
}

