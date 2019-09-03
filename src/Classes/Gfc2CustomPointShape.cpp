#include "StdAfx.h"
#include "Gfc2CustomPointShape.h"
#include "Gfc2CustomPointShapeBinarySerializer.h"
#include "Gfc2CustomPointShapeTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2CustomPointShape,"Gfc2CustomPointShape",0)

OBJECTBUF_IMP_OBJECT(Gfc2CustomPointShapeFieldCacheInitializer,"Gfc2CustomPointShape",0)

Gfc2CustomPointShape::Gfc2CustomPointShape()
{
    m_nInsertPt = 0;
    m_nBaseInsertPt = 0;
    m_dAngle = 0.0;
    m_bMirrorFlag = false;
}

bool Gfc2CustomPointShape::isInitialized() const
{
    if ((_has_bits_[0] & 0xf1) != 0xf1) return false;

    return true;
}

int Gfc2CustomPointShape::typeId() const
{
    return 32;
}

glodon::objectbuf::EntitySchema* Gfc2CustomPointShape::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(32))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2SolidShape::createSchema());
    pSchema->setName("Gfc2CustomPointShape");
    pSchema->setId(32);
    m_pDocument->addSchema(pSchema, 32);

    pSchema->addAttribNames("InsertPt");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("BaseInsertPt");
    pSchema->addAttribIds(6);

    pSchema->addAttribNames("Angle");
    pSchema->addAttribIds(7);

    pSchema->addAttribNames("MirrorFlag");
    pSchema->addAttribIds(8);

    return pSchema;
}

std::string Gfc2CustomPointShape::entityName() const
{
    return "Gfc2CustomPointShape";
}

void Gfc2CustomPointShapeFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2CustomPointShape_InsertPt = getFieldId(oFieldIdMap, "Gfc2CustomPointShape::InsertPt");
    _FieldCache->_Gfc2CustomPointShape_BaseInsertPt = getFieldId(oFieldIdMap, "Gfc2CustomPointShape::BaseInsertPt");
    _FieldCache->_Gfc2CustomPointShape_Angle = getFieldId(oFieldIdMap, "Gfc2CustomPointShape::Angle");
    _FieldCache->_Gfc2CustomPointShape_MirrorFlag = getFieldId(oFieldIdMap, "Gfc2CustomPointShape::MirrorFlag");
}

