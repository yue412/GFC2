#include "StdAfx.h"
#include "Gfc2Surface.h"
#include "Gfc2SurfaceBinarySerializer.h"
#include "Gfc2SurfaceTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Surface,"Gfc2Surface",0)

int Gfc2Surface::typeId() const
{
    return 129;
}

glodon::objectbuf::EntitySchema* Gfc2Surface::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(129))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Geometry::createSchema());
    pSchema->setName("Gfc2Surface");
    pSchema->setId(129);
    m_pDocument->addSchema(pSchema, 129);

    return pSchema;
}

std::string Gfc2Surface::entityName() const
{
    return "Gfc2Surface";
}

