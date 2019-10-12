#include "StdAfx.h"
#include "Gfc2SpatialStructureEntity.h"
#include "Gfc2SpatialStructureEntityBinarySerializer.h"
#include "Gfc2SpatialStructureEntityTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2SpatialStructureEntity,"Gfc2SpatialStructureEntity",0)

int Gfc2SpatialStructureEntity::typeId() const
{
    return 139;
}

glodon::objectbuf::EntitySchema* Gfc2SpatialStructureEntity::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(139))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Object::createSchema());
    pSchema->setName("Gfc2SpatialStructureEntity");
    pSchema->setId(139);
    m_pDocument->addSchema(pSchema, 139);

    return pSchema;
}

std::string Gfc2SpatialStructureEntity::entityName() const
{
    return "Gfc2SpatialStructureEntity";
}

