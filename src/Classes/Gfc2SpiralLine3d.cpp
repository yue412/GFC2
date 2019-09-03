#include "StdAfx.h"
#include "Gfc2SpiralLine3d.h"
#include "Gfc2SpiralLine3dBinarySerializer.h"
#include "Gfc2SpiralLine3dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2SpiralLine3d,"Gfc2SpiralLine3d",0)

OBJECTBUF_IMP_OBJECT(Gfc2SpiralLine3dFieldCacheInitializer,"Gfc2SpiralLine3d",0)

Gfc2SpiralLine3d::Gfc2SpiralLine3d()
{
    m_nCoord = 0;
    m_dRadius = 0.0;
    m_nRange = 0;
    m_nClockSign = 0;
    m_dHeightCoef = 0.0;
    m_dRadiusCoef = 0.0;
}

bool Gfc2SpiralLine3d::isInitialized() const
{
    if ((_has_bits_[0] & 0x3f) != 0x3f) return false;

    return true;
}

int Gfc2SpiralLine3d::typeId() const
{
    return 123;
}

glodon::objectbuf::EntitySchema* Gfc2SpiralLine3d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(123))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Curve3d::createSchema());
    pSchema->setName("Gfc2SpiralLine3d");
    pSchema->setId(123);
    m_pDocument->addSchema(pSchema, 123);

    pSchema->addAttribNames("Coord");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Radius");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Range");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("ClockSign");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("HeightCoef");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("RadiusCoef");
    pSchema->addAttribIds(6);

    return pSchema;
}

std::string Gfc2SpiralLine3d::entityName() const
{
    return "Gfc2SpiralLine3d";
}

void Gfc2SpiralLine3dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2SpiralLine3d_Coord = getFieldId(oFieldIdMap, "Gfc2SpiralLine3d::Coord");
    _FieldCache->_Gfc2SpiralLine3d_Radius = getFieldId(oFieldIdMap, "Gfc2SpiralLine3d::Radius");
    _FieldCache->_Gfc2SpiralLine3d_Range = getFieldId(oFieldIdMap, "Gfc2SpiralLine3d::Range");
    _FieldCache->_Gfc2SpiralLine3d_ClockSign = getFieldId(oFieldIdMap, "Gfc2SpiralLine3d::ClockSign");
    _FieldCache->_Gfc2SpiralLine3d_HeightCoef = getFieldId(oFieldIdMap, "Gfc2SpiralLine3d::HeightCoef");
    _FieldCache->_Gfc2SpiralLine3d_RadiusCoef = getFieldId(oFieldIdMap, "Gfc2SpiralLine3d::RadiusCoef");
}

