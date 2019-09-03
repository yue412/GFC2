#include "StdAfx.h"
#include "Gfc2CustomLineShape.h"
#include "Gfc2CustomLineShapeBinarySerializer.h"
#include "Gfc2CustomLineShapeTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2CustomLineShape,"Gfc2CustomLineShape",0)

OBJECTBUF_IMP_OBJECT(Gfc2CustomLineShapeFieldCacheInitializer,"Gfc2CustomLineShape",0)

Gfc2CustomLineShape::Gfc2CustomLineShape()
{
    m_dWidth = 0.0;
    m_dLeftWidth = 0.0;
    m_nLine = 0;
    m_dE_S_Elevation = 0.0;
}

bool Gfc2CustomLineShape::isInitialized() const
{
    if ((_has_bits_[0] & 0xf1) != 0xf1) return false;

    return true;
}

int Gfc2CustomLineShape::typeId() const
{
    return 31;
}

glodon::objectbuf::EntitySchema* Gfc2CustomLineShape::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(31))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2SolidShape::createSchema());
    pSchema->setName("Gfc2CustomLineShape");
    pSchema->setId(31);
    m_pDocument->addSchema(pSchema, 31);

    pSchema->addAttribNames("Width");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("LeftWidth");
    pSchema->addAttribIds(6);

    pSchema->addAttribNames("Line");
    pSchema->addAttribIds(7);

    pSchema->addAttribNames("E_S_Elevation");
    pSchema->addAttribIds(8);

    return pSchema;
}

std::string Gfc2CustomLineShape::entityName() const
{
    return "Gfc2CustomLineShape";
}

void Gfc2CustomLineShapeFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2CustomLineShape_Width = getFieldId(oFieldIdMap, "Gfc2CustomLineShape::Width");
    _FieldCache->_Gfc2CustomLineShape_LeftWidth = getFieldId(oFieldIdMap, "Gfc2CustomLineShape::LeftWidth");
    _FieldCache->_Gfc2CustomLineShape_Line = getFieldId(oFieldIdMap, "Gfc2CustomLineShape::Line");
    _FieldCache->_Gfc2CustomLineShape_E_S_Elevation = getFieldId(oFieldIdMap, "Gfc2CustomLineShape::E_S_Elevation");
}

