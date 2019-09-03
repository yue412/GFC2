#include "StdAfx.h"
#include "Gfc2StringProperty.h"
#include "Gfc2StringPropertyBinarySerializer.h"
#include "Gfc2StringPropertyTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2StringProperty,"Gfc2StringProperty",0)

OBJECTBUF_IMP_OBJECT(Gfc2StringPropertyFieldCacheInitializer,"Gfc2StringProperty",0)

Gfc2StringProperty::Gfc2StringProperty()
{
    m_nValue = 0;
}

bool Gfc2StringProperty::isInitialized() const
{
    if ((_has_bits_[0] & 0x3) != 0x3) return false;

    return true;
}

int Gfc2StringProperty::typeId() const
{
    return 128;
}

glodon::objectbuf::EntitySchema* Gfc2StringProperty::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(128))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Property::createSchema());
    pSchema->setName("Gfc2StringProperty");
    pSchema->setId(128);
    m_pDocument->addSchema(pSchema, 128);

    pSchema->addAttribNames("Value");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2StringProperty::entityName() const
{
    return "Gfc2StringProperty";
}

void Gfc2StringPropertyFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2StringProperty_Value = getFieldId(oFieldIdMap, "Gfc2StringProperty::Value");
}

