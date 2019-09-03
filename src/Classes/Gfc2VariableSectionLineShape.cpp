#include "StdAfx.h"
#include "Gfc2VariableSectionLineShape.h"
#include "Gfc2VariableSectionLineShapeBinarySerializer.h"
#include "Gfc2VariableSectionLineShapeTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2VariableSectionLineShape,"Gfc2VariableSectionLineShape",0)

OBJECTBUF_IMP_OBJECT(Gfc2VariableSectionLineShapeFieldCacheInitializer,"Gfc2VariableSectionLineShape",0)

Gfc2VariableSectionLineShape::Gfc2VariableSectionLineShape()
{
    m_nEndPoly = 0;
}

bool Gfc2VariableSectionLineShape::isInitialized() const
{
    if ((_has_bits_[0] & 0x4ff1) != 0x4ff1) return false;

    return true;
}

int Gfc2VariableSectionLineShape::typeId() const
{
    return 135;
}

glodon::objectbuf::EntitySchema* Gfc2VariableSectionLineShape::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(135))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2SectionLineShape::createSchema());
    pSchema->setName("Gfc2VariableSectionLineShape");
    pSchema->setId(135);
    m_pDocument->addSchema(pSchema, 135);

    pSchema->addAttribNames("EndPoly");
    pSchema->addAttribIds(15);

    return pSchema;
}

std::string Gfc2VariableSectionLineShape::entityName() const
{
    return "Gfc2VariableSectionLineShape";
}

void Gfc2VariableSectionLineShapeFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2VariableSectionLineShape_EndPoly = getFieldId(oFieldIdMap, "Gfc2VariableSectionLineShape::EndPoly");
}

