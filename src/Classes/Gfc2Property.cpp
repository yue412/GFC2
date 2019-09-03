#include "StdAfx.h"
#include "Gfc2Property.h"
#include "Gfc2PropertyBinarySerializer.h"
#include "Gfc2PropertyTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Property,"Gfc2Property",0)

OBJECTBUF_IMP_OBJECT(Gfc2PropertyFieldCacheInitializer,"Gfc2Property",0)

Gfc2Property::Gfc2Property()
{
    m_nName = 0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2Property::isInitialized() const
{
    if ((_has_bits_[0] & 0x1) != 0x1) return false;

    return true;
}

int Gfc2Property::typeId() const
{
    return 94;
}

glodon::objectbuf::EntitySchema* Gfc2Property::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(94))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2Property");
    pSchema->setId(94);
    m_pDocument->addSchema(pSchema, 94);

    pSchema->addAttribNames("Name");
    pSchema->addAttribIds(1);

    return pSchema;
}

std::string Gfc2Property::entityName() const
{
    return "Gfc2Property";
}

void Gfc2PropertyFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Property_Name = getFieldId(oFieldIdMap, "Gfc2Property::Name");
}

