#include "StdAfx.h"
#include "Gfc2AxisGrid.h"
#include "Gfc2AxisGridBinarySerializer.h"
#include "Gfc2AxisGridTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2AxisGrid,"Gfc2AxisGrid",0)

int Gfc2AxisGrid::typeId() const
{
    return 8;
}

glodon::objectbuf::EntitySchema* Gfc2AxisGrid::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(8))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Entity::createSchema());
    pSchema->setName("Gfc2AxisGrid");
    pSchema->setId(8);
    m_pDocument->addSchema(pSchema, 8);

    return pSchema;
}

std::string Gfc2AxisGrid::entityName() const
{
    return "Gfc2AxisGrid";
}

