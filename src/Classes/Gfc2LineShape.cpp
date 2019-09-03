#include "StdAfx.h"
#include "Gfc2LineShape.h"
#include "Gfc2LineShapeBinarySerializer.h"
#include "Gfc2LineShapeTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2LineShape,"Gfc2LineShape",0)

OBJECTBUF_IMP_OBJECT(Gfc2LineShapeFieldCacheInitializer,"Gfc2LineShape",0)

Gfc2LineShape::Gfc2LineShape()
{
    m_dTilt = 0.0;
    m_dStartPtHeight = 0.0;
    m_dEndPtHeight = 0.0;
    m_nArcInfo = 0;
    m_bIsSpiralTop = false;
    m_bIsSpiralBtm = false;
}

bool Gfc2LineShape::isInitialized() const
{
    if ((_has_bits_[0] & 0x6f1) != 0x6f1) return false;

    return true;
}

int Gfc2LineShape::typeId() const
{
    return 66;
}

glodon::objectbuf::EntitySchema* Gfc2LineShape::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(66))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2CustomLineShape::createSchema());
    pSchema->setName("Gfc2LineShape");
    pSchema->setId(66);
    m_pDocument->addSchema(pSchema, 66);

    pSchema->addAttribNames("Tilt");
    pSchema->addAttribIds(9);

    pSchema->addAttribNames("StartPtHeight");
    pSchema->addAttribIds(10);

    pSchema->addAttribNames("EndPtHeight");
    pSchema->addAttribIds(11);

    pSchema->addAttribNames("ArcInfo");
    pSchema->addAttribIds(12);

    pSchema->addAttribNames("IsSpiralTop");
    pSchema->addAttribIds(13);

    pSchema->addAttribNames("IsSpiralBtm");
    pSchema->addAttribIds(14);

    return pSchema;
}

std::string Gfc2LineShape::entityName() const
{
    return "Gfc2LineShape";
}

void Gfc2LineShapeFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2LineShape_Tilt = getFieldId(oFieldIdMap, "Gfc2LineShape::Tilt");
    _FieldCache->_Gfc2LineShape_StartPtHeight = getFieldId(oFieldIdMap, "Gfc2LineShape::StartPtHeight");
    _FieldCache->_Gfc2LineShape_EndPtHeight = getFieldId(oFieldIdMap, "Gfc2LineShape::EndPtHeight");
    _FieldCache->_Gfc2LineShape_ArcInfo = getFieldId(oFieldIdMap, "Gfc2LineShape::ArcInfo");
    _FieldCache->_Gfc2LineShape_IsSpiralTop = getFieldId(oFieldIdMap, "Gfc2LineShape::IsSpiralTop");
    _FieldCache->_Gfc2LineShape_IsSpiralBtm = getFieldId(oFieldIdMap, "Gfc2LineShape::IsSpiralBtm");
}

