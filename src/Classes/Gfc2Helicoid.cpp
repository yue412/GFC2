#include "StdAfx.h"
#include "Gfc2Helicoid.h"
#include "Gfc2HelicoidBinarySerializer.h"
#include "Gfc2HelicoidTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Helicoid,"Gfc2Helicoid",0)

OBJECTBUF_IMP_OBJECT(Gfc2HelicoidFieldCacheInitializer,"Gfc2Helicoid",0)

Gfc2Helicoid::Gfc2Helicoid()
{
    m_nCoord = 0;
    m_dRadius = 0.0;
    m_nRangeV = 0;
    m_nClockSign = 0;
    m_dHeightCoef = 0.0;
    m_dRadiusCoef = 0.0;
    m_nCurve = 0;
}

bool Gfc2Helicoid::isInitialized() const
{
    if ((_has_bits_[0] & 0x7f) != 0x7f) return false;

    return true;
}

int Gfc2Helicoid::typeId() const
{
    return 52;
}

glodon::objectbuf::EntitySchema* Gfc2Helicoid::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(52))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Surface::createSchema());
    pSchema->setName("Gfc2Helicoid");
    pSchema->setId(52);
    m_pDocument->addSchema(pSchema, 52);

    pSchema->addAttribNames("Coord");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Radius");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("RangeV");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("ClockSign");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("HeightCoef");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("RadiusCoef");
    pSchema->addAttribIds(6);

    pSchema->addAttribNames("Curve");
    pSchema->addAttribIds(7);

    return pSchema;
}

std::string Gfc2Helicoid::entityName() const
{
    return "Gfc2Helicoid";
}

void Gfc2HelicoidFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Helicoid_Coord = getFieldId(oFieldIdMap, "Gfc2Helicoid::Coord");
    _FieldCache->_Gfc2Helicoid_Radius = getFieldId(oFieldIdMap, "Gfc2Helicoid::Radius");
    _FieldCache->_Gfc2Helicoid_RangeV = getFieldId(oFieldIdMap, "Gfc2Helicoid::RangeV");
    _FieldCache->_Gfc2Helicoid_ClockSign = getFieldId(oFieldIdMap, "Gfc2Helicoid::ClockSign");
    _FieldCache->_Gfc2Helicoid_HeightCoef = getFieldId(oFieldIdMap, "Gfc2Helicoid::HeightCoef");
    _FieldCache->_Gfc2Helicoid_RadiusCoef = getFieldId(oFieldIdMap, "Gfc2Helicoid::RadiusCoef");
    _FieldCache->_Gfc2Helicoid_Curve = getFieldId(oFieldIdMap, "Gfc2Helicoid::Curve");
}

