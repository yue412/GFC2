#include "StdAfx.h"
#include "Gfc2SpatialStructureElement.h"
#include "Gfc2SpatialStructureElementBinarySerializer.h"
#include "Gfc2SpatialStructureElementTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2SpatialStructureElement,"Gfc2SpatialStructureElement",0)

int Gfc2SpatialStructureElement::typeId() const
{
    return 120;
}

glodon::objectbuf::EntitySchema* Gfc2SpatialStructureElement::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(120))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Object::createSchema());
    pSchema->setName("Gfc2SpatialStructureElement");
    pSchema->setId(120);
    m_pDocument->addSchema(pSchema, 120);

    return pSchema;
}

std::string Gfc2SpatialStructureElement::entityName() const
{
    return "Gfc2SpatialStructureElement";
}

