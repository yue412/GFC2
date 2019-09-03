#include "StdAfx.h"
#include "Gfc2Curve2d.h"
#include "Gfc2Curve2dBinarySerializer.h"
#include "Gfc2Curve2dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Curve2d,"Gfc2Curve2d",0)

int Gfc2Curve2d::typeId() const
{
    return 29;
}

glodon::objectbuf::EntitySchema* Gfc2Curve2d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(29))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Geometry::createSchema());
    pSchema->setName("Gfc2Curve2d");
    pSchema->setId(29);
    m_pDocument->addSchema(pSchema, 29);

    return pSchema;
}

std::string Gfc2Curve2d::entityName() const
{
    return "Gfc2Curve2d";
}

