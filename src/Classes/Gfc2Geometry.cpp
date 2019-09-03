#include "StdAfx.h"
#include "Gfc2Geometry.h"
#include "Gfc2GeometryBinarySerializer.h"
#include "Gfc2GeometryTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Geometry,"Gfc2Geometry",0)

Gfc2Geometry::Gfc2Geometry()
{
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

int Gfc2Geometry::typeId() const
{
    return 50;
}

glodon::objectbuf::EntitySchema* Gfc2Geometry::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(50))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2Geometry");
    pSchema->setId(50);
    m_pDocument->addSchema(pSchema, 50);

    return pSchema;
}

std::string Gfc2Geometry::entityName() const
{
    return "Gfc2Geometry";
}

