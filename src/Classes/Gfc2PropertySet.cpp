#include "StdAfx.h"
#include "Gfc2PropertySet.h"
#include "Gfc2PropertySetBinarySerializer.h"
#include "Gfc2PropertySetTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2PropertySet,"Gfc2PropertySet",0)

OBJECTBUF_IMP_OBJECT(Gfc2PropertySetFieldCacheInitializer,"Gfc2PropertySet",0)

Gfc2PropertySet::Gfc2PropertySet()
{
    m_nIdentifier = 0;
}

bool Gfc2PropertySet::isInitialized() const
{

    return true;
}

int Gfc2PropertySet::typeId() const
{
    return 95;
}

glodon::objectbuf::EntitySchema* Gfc2PropertySet::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(95))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Root::createSchema());
    pSchema->setName("Gfc2PropertySet");
    pSchema->setId(95);
    m_pDocument->addSchema(pSchema, 95);

    pSchema->addAttribNames("Identifier");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("HasProperties");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2PropertySet::entityName() const
{
    return "Gfc2PropertySet";
}

void Gfc2PropertySetFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2PropertySet_Identifier = getFieldId(oFieldIdMap, "Gfc2PropertySet::Identifier");
    _FieldCache->_Gfc2PropertySet_HasProperties = getFieldId(oFieldIdMap, "Gfc2PropertySet::HasProperties");
}

