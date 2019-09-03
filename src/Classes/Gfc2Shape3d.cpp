#include "StdAfx.h"
#include "Gfc2Shape3d.h"
#include "Gfc2Shape3dBinarySerializer.h"
#include "Gfc2Shape3dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Shape3d,"Gfc2Shape3d",0)

int Gfc2Shape3d::typeId() const
{
    return 113;
}

glodon::objectbuf::EntitySchema* Gfc2Shape3d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(113))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2ParametricShape::createSchema());
    pSchema->setName("Gfc2Shape3d");
    pSchema->setId(113);
    m_pDocument->addSchema(pSchema, 113);

    return pSchema;
}

std::string Gfc2Shape3d::entityName() const
{
    return "Gfc2Shape3d";
}

