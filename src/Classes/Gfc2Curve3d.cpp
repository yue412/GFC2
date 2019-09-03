#include "StdAfx.h"
#include "Gfc2Curve3d.h"
#include "Gfc2Curve3dBinarySerializer.h"
#include "Gfc2Curve3dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Curve3d,"Gfc2Curve3d",0)

int Gfc2Curve3d::typeId() const
{
    return 30;
}

glodon::objectbuf::EntitySchema* Gfc2Curve3d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(30))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Geometry::createSchema());
    pSchema->setName("Gfc2Curve3d");
    pSchema->setId(30);
    m_pDocument->addSchema(pSchema, 30);

    return pSchema;
}

std::string Gfc2Curve3d::entityName() const
{
    return "Gfc2Curve3d";
}

