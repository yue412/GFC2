#include "StdAfx.h"
#include "Gfc2String.h"
#include "Gfc2StringBinarySerializer.h"
#include "Gfc2StringTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2String,"Gfc2String",0)

OBJECTBUF_IMP_OBJECT(Gfc2StringFieldCacheInitializer,"Gfc2String",0)

Gfc2String::Gfc2String()
{
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2String::isInitialized() const
{
    if ((_has_bits_[0] & 0x1) != 0x1) return false;

    return true;
}

int Gfc2String::typeId() const
{
    return 127;
}

glodon::objectbuf::EntitySchema* Gfc2String::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(127))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2String");
    pSchema->setId(127);
    m_pDocument->addSchema(pSchema, 127);

    pSchema->addAttribNames("Value");
    pSchema->addAttribIds(1);

    return pSchema;
}

std::string Gfc2String::entityName() const
{
    return "Gfc2String";
}

void Gfc2StringFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2String_Value = getFieldId(oFieldIdMap, "Gfc2String::Value");
}

