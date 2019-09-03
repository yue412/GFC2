#include "StdAfx.h"
#include "Gfc2SectionLineShape.h"
#include "Gfc2SectionLineShapeBinarySerializer.h"
#include "Gfc2SectionLineShapeTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2SectionLineShape,"Gfc2SectionLineShape",0)

OBJECTBUF_IMP_OBJECT(Gfc2SectionLineShapeFieldCacheInitializer,"Gfc2SectionLineShape",0)

Gfc2SectionLineShape::Gfc2SectionLineShape()
{
    m_nPoly = 0;
    m_nBaseInsertPt = 0;
    m_dAngle = 0.0;
    m_bMirrorFlag = false;
    m_nArcInfo = 0;
    m_bIsSpiral = false;
}

bool Gfc2SectionLineShape::isInitialized() const
{
    if ((_has_bits_[0] & 0xff1) != 0xff1) return false;

    return true;
}

int Gfc2SectionLineShape::typeId() const
{
    return 109;
}

glodon::objectbuf::EntitySchema* Gfc2SectionLineShape::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(109))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2CustomLineShape::createSchema());
    pSchema->setName("Gfc2SectionLineShape");
    pSchema->setId(109);
    m_pDocument->addSchema(pSchema, 109);

    pSchema->addAttribNames("Poly");
    pSchema->addAttribIds(9);

    pSchema->addAttribNames("BaseInsertPt");
    pSchema->addAttribIds(10);

    pSchema->addAttribNames("Angle");
    pSchema->addAttribIds(11);

    pSchema->addAttribNames("MirrorFlag");
    pSchema->addAttribIds(12);

    pSchema->addAttribNames("ArcInfo");
    pSchema->addAttribIds(13);

    pSchema->addAttribNames("IsSpiral");
    pSchema->addAttribIds(14);

    return pSchema;
}

std::string Gfc2SectionLineShape::entityName() const
{
    return "Gfc2SectionLineShape";
}

void Gfc2SectionLineShapeFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2SectionLineShape_Poly = getFieldId(oFieldIdMap, "Gfc2SectionLineShape::Poly");
    _FieldCache->_Gfc2SectionLineShape_BaseInsertPt = getFieldId(oFieldIdMap, "Gfc2SectionLineShape::BaseInsertPt");
    _FieldCache->_Gfc2SectionLineShape_Angle = getFieldId(oFieldIdMap, "Gfc2SectionLineShape::Angle");
    _FieldCache->_Gfc2SectionLineShape_MirrorFlag = getFieldId(oFieldIdMap, "Gfc2SectionLineShape::MirrorFlag");
    _FieldCache->_Gfc2SectionLineShape_ArcInfo = getFieldId(oFieldIdMap, "Gfc2SectionLineShape::ArcInfo");
    _FieldCache->_Gfc2SectionLineShape_IsSpiral = getFieldId(oFieldIdMap, "Gfc2SectionLineShape::IsSpiral");
}

