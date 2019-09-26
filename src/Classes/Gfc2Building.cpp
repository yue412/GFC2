#include "StdAfx.h"
#include "Gfc2Building.h"
#include "Gfc2BuildingBinarySerializer.h"
#include "Gfc2BuildingTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Building,"Gfc2Building",0)

int Gfc2Building::typeId() const
{
    return 17;
}

glodon::objectbuf::EntitySchema* Gfc2Building::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(17))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2SpatialStructureEntity::createSchema());
    pSchema->setName("Gfc2Building");
    pSchema->setId(17);
    m_pDocument->addSchema(pSchema, 17);

    return pSchema;
}

std::string Gfc2Building::entityName() const
{
    return "Gfc2Building";
}

