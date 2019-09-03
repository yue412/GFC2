#include "StdAfx.h"
#include "Gfc2Entity.h"
#include "Gfc2EntityBinarySerializer.h"
#include "Gfc2EntityTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Entity,"Gfc2Entity",0)

OBJECTBUF_IMP_OBJECT(Gfc2EntityFieldCacheInitializer,"Gfc2Entity",0)

Gfc2Entity::Gfc2Entity()
{
    m_nType = 0;
}

bool Gfc2Entity::isInitialized() const
{
    if ((_has_bits_[0] & 0x5) != 0x5) return false;

    return true;
}

int Gfc2Entity::typeId() const
{
    return 39;
}

glodon::objectbuf::EntitySchema* Gfc2Entity::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(39))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Object::createSchema());
    pSchema->setName("Gfc2Entity");
    pSchema->setId(39);
    m_pDocument->addSchema(pSchema, 39);

    pSchema->addAttribNames("Type");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("Representations");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("Shapes");
    pSchema->addAttribIds(5);

    return pSchema;
}

std::string Gfc2Entity::entityName() const
{
    return "Gfc2Entity";
}

void Gfc2EntityFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Entity_Type = getFieldId(oFieldIdMap, "Gfc2Entity::Type");
    _FieldCache->_Gfc2Entity_Representations = getFieldId(oFieldIdMap, "Gfc2Entity::Representations");
    _FieldCache->_Gfc2Entity_Shapes = getFieldId(oFieldIdMap, "Gfc2Entity::Shapes");
}

