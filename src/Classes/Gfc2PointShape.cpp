#include "StdAfx.h"
#include "Gfc2PointShape.h"
#include "Gfc2PointShapeBinarySerializer.h"
#include "Gfc2PointShapeTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2PointShape,"Gfc2PointShape",0)

OBJECTBUF_IMP_OBJECT(Gfc2PointShapeFieldCacheInitializer,"Gfc2PointShape",0)

Gfc2PointShape::Gfc2PointShape()
{
    m_dHeight = 0.0;
    m_nObliqueDir = 0;
    m_nTopPoly = 0;
}

bool Gfc2PointShape::isInitialized() const
{
    if ((_has_bits_[0] & 0x7f1) != 0x7f1) return false;

    return true;
}

int Gfc2PointShape::typeId() const
{
    return 83;
}

glodon::objectbuf::EntitySchema* Gfc2PointShape::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(83))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2SectionPointShape::createSchema());
    pSchema->setName("Gfc2PointShape");
    pSchema->setId(83);
    m_pDocument->addSchema(pSchema, 83);

    pSchema->addAttribNames("Height");
    pSchema->addAttribIds(10);

    pSchema->addAttribNames("ObliqueDir");
    pSchema->addAttribIds(11);

    pSchema->addAttribNames("TopPoly");
    pSchema->addAttribIds(12);

    return pSchema;
}

std::string Gfc2PointShape::entityName() const
{
    return "Gfc2PointShape";
}

void Gfc2PointShapeFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2PointShape_Height = getFieldId(oFieldIdMap, "Gfc2PointShape::Height");
    _FieldCache->_Gfc2PointShape_ObliqueDir = getFieldId(oFieldIdMap, "Gfc2PointShape::ObliqueDir");
    _FieldCache->_Gfc2PointShape_TopPoly = getFieldId(oFieldIdMap, "Gfc2PointShape::TopPoly");
}

