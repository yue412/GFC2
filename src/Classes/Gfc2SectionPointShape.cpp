#include "StdAfx.h"
#include "Gfc2SectionPointShape.h"
#include "Gfc2SectionPointShapeBinarySerializer.h"
#include "Gfc2SectionPointShapeTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2SectionPointShape,"Gfc2SectionPointShape",0)

OBJECTBUF_IMP_OBJECT(Gfc2SectionPointShapeFieldCacheInitializer,"Gfc2SectionPointShape",0)

Gfc2SectionPointShape::Gfc2SectionPointShape()
{
    m_nPoly = 0;
}

bool Gfc2SectionPointShape::isInitialized() const
{
    if ((_has_bits_[0] & 0x1f1) != 0x1f1) return false;

    return true;
}

int Gfc2SectionPointShape::typeId() const
{
    return 110;
}

glodon::objectbuf::EntitySchema* Gfc2SectionPointShape::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(110))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2CustomPointShape::createSchema());
    pSchema->setName("Gfc2SectionPointShape");
    pSchema->setId(110);
    m_pDocument->addSchema(pSchema, 110);

    pSchema->addAttribNames("Poly");
    pSchema->addAttribIds(9);

    return pSchema;
}

std::string Gfc2SectionPointShape::entityName() const
{
    return "Gfc2SectionPointShape";
}

void Gfc2SectionPointShapeFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2SectionPointShape_Poly = getFieldId(oFieldIdMap, "Gfc2SectionPointShape::Poly");
}

