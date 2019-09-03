#include "StdAfx.h"
#include "Gfc2RelDefines.h"
#include "Gfc2RelDefinesBinarySerializer.h"
#include "Gfc2RelDefinesTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2RelDefines,"Gfc2RelDefines",0)

OBJECTBUF_IMP_OBJECT(Gfc2RelDefinesFieldCacheInitializer,"Gfc2RelDefines",0)

Gfc2RelDefines::Gfc2RelDefines()
{
}

bool Gfc2RelDefines::isInitialized() const
{

    return true;
}

int Gfc2RelDefines::typeId() const
{
    return 100;
}

glodon::objectbuf::EntitySchema* Gfc2RelDefines::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(100))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2RelationShip::createSchema());
    pSchema->setName("Gfc2RelDefines");
    pSchema->setId(100);
    m_pDocument->addSchema(pSchema, 100);

    pSchema->addAttribNames("RelatedObjects");
    pSchema->addAttribIds(1);

    return pSchema;
}

std::string Gfc2RelDefines::entityName() const
{
    return "Gfc2RelDefines";
}

void Gfc2RelDefinesFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2RelDefines_RelatedObjects = getFieldId(oFieldIdMap, "Gfc2RelDefines::RelatedObjects");
}

