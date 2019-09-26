#include "StdAfx.h"
#include "Gfc2Polygon.h"
#include "Gfc2PolygonBinarySerializer.h"
#include "Gfc2PolygonTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Polygon,"Gfc2Polygon",0)

int Gfc2Polygon::typeId() const
{
    return 87;
}

glodon::objectbuf::EntitySchema* Gfc2Polygon::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(87))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Geometry::createSchema());
    pSchema->setName("Gfc2Polygon");
    pSchema->setId(87);
    m_pDocument->addSchema(pSchema, 87);

    return pSchema;
}

std::string Gfc2Polygon::entityName() const
{
    return "Gfc2Polygon";
}

