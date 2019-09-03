#include "StdAfx.h"
#include "Gfc2Arc3d.h"
#include "Gfc2Arc3dBinarySerializer.h"
#include "Gfc2Arc3dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Arc3d,"Gfc2Arc3d",0)

int Gfc2Arc3d::typeId() const
{
    return 4;
}

glodon::objectbuf::EntitySchema* Gfc2Arc3d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(4))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2PlaneCurve3d::createSchema());
    pSchema->setName("Gfc2Arc3d");
    pSchema->setId(4);
    m_pDocument->addSchema(pSchema, 4);

    return pSchema;
}

std::string Gfc2Arc3d::entityName() const
{
    return "Gfc2Arc3d";
}

