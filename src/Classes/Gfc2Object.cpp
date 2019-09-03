#include "StdAfx.h"
#include "Gfc2Object.h"
#include "Gfc2ObjectBinarySerializer.h"
#include "Gfc2ObjectTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Object,"Gfc2Object",0)

OBJECTBUF_IMP_OBJECT(Gfc2ObjectFieldCacheInitializer,"Gfc2Object",0)

Gfc2Object::Gfc2Object()
{
    m_nName = 0;
}

bool Gfc2Object::isInitialized() const
{
    if ((_has_bits_[0] & 0x1) != 0x1) return false;

    return true;
}

int Gfc2Object::typeId() const
{
    return 73;
}

glodon::objectbuf::EntitySchema* Gfc2Object::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(73))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Root::createSchema());
    pSchema->setName("Gfc2Object");
    pSchema->setId(73);
    m_pDocument->addSchema(pSchema, 73);

    pSchema->addAttribNames("ID");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Name");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2Object::entityName() const
{
    return "Gfc2Object";
}

void Gfc2ObjectFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Object_ID = getFieldId(oFieldIdMap, "Gfc2Object::ID");
    _FieldCache->_Gfc2Object_Name = getFieldId(oFieldIdMap, "Gfc2Object::Name");
}

