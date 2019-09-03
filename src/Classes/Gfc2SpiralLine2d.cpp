#include "StdAfx.h"
#include "Gfc2SpiralLine2d.h"
#include "Gfc2SpiralLine2dBinarySerializer.h"
#include "Gfc2SpiralLine2dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2SpiralLine2d,"Gfc2SpiralLine2d",0)

OBJECTBUF_IMP_OBJECT(Gfc2SpiralLine2dFieldCacheInitializer,"Gfc2SpiralLine2d",0)

Gfc2SpiralLine2d::Gfc2SpiralLine2d()
{
    m_nCoord = 0;
    m_dRadius = 0.0;
    m_nRange = 0;
    m_nClockSign = 0;
    m_dRadiusCoef = 0.0;
}

bool Gfc2SpiralLine2d::isInitialized() const
{
    if ((_has_bits_[0] & 0x1f) != 0x1f) return false;

    return true;
}

int Gfc2SpiralLine2d::typeId() const
{
    return 122;
}

glodon::objectbuf::EntitySchema* Gfc2SpiralLine2d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(122))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Curve2d::createSchema());
    pSchema->setName("Gfc2SpiralLine2d");
    pSchema->setId(122);
    m_pDocument->addSchema(pSchema, 122);

    pSchema->addAttribNames("Coord");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Radius");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Range");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("ClockSign");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("RadiusCoef");
    pSchema->addAttribIds(5);

    return pSchema;
}

std::string Gfc2SpiralLine2d::entityName() const
{
    return "Gfc2SpiralLine2d";
}

void Gfc2SpiralLine2dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2SpiralLine2d_Coord = getFieldId(oFieldIdMap, "Gfc2SpiralLine2d::Coord");
    _FieldCache->_Gfc2SpiralLine2d_Radius = getFieldId(oFieldIdMap, "Gfc2SpiralLine2d::Radius");
    _FieldCache->_Gfc2SpiralLine2d_Range = getFieldId(oFieldIdMap, "Gfc2SpiralLine2d::Range");
    _FieldCache->_Gfc2SpiralLine2d_ClockSign = getFieldId(oFieldIdMap, "Gfc2SpiralLine2d::ClockSign");
    _FieldCache->_Gfc2SpiralLine2d_RadiusCoef = getFieldId(oFieldIdMap, "Gfc2SpiralLine2d::RadiusCoef");
}

