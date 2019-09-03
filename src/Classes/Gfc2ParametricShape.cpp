#include "StdAfx.h"
#include "Gfc2ParametricShape.h"
#include "Gfc2ParametricShapeBinarySerializer.h"
#include "Gfc2ParametricShapeTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2ParametricShape,"Gfc2ParametricShape",0)

int Gfc2ParametricShape::typeId() const
{
    return 77;
}

glodon::objectbuf::EntitySchema* Gfc2ParametricShape::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(77))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Shape::createSchema());
    pSchema->setName("Gfc2ParametricShape");
    pSchema->setId(77);
    m_pDocument->addSchema(pSchema, 77);

    return pSchema;
}

std::string Gfc2ParametricShape::entityName() const
{
    return "Gfc2ParametricShape";
}

