#include "StdAfx.h"
#include "Gfc2Torus.h"
#include "Gfc2TorusBinarySerializer.h"
#include "Gfc2TorusTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Torus,"Gfc2Torus",0)

OBJECTBUF_IMP_OBJECT(Gfc2TorusFieldCacheInitializer,"Gfc2Torus",0)

Gfc2Torus::Gfc2Torus()
{
    m_nCoord = 0;
    m_dRadius = 0.0;
    m_nClockSign = 0;
    m_nRangeV = 0;
    m_nCurve = 0;
}

bool Gfc2Torus::isInitialized() const
{
    if ((_has_bits_[0] & 0x1f) != 0x1f) return false;

    return true;
}

int Gfc2Torus::typeId() const
{
    return 133;
}

glodon::objectbuf::EntitySchema* Gfc2Torus::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(133))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Surface::createSchema());
    pSchema->setName("Gfc2Torus");
    pSchema->setId(133);
    m_pDocument->addSchema(pSchema, 133);

    pSchema->addAttribNames("Coord");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Radius");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("ClockSign");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("RangeV");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("Curve");
    pSchema->addAttribIds(5);

    return pSchema;
}

std::string Gfc2Torus::entityName() const
{
    return "Gfc2Torus";
}

void Gfc2TorusFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Torus_Coord = getFieldId(oFieldIdMap, "Gfc2Torus::Coord");
    _FieldCache->_Gfc2Torus_Radius = getFieldId(oFieldIdMap, "Gfc2Torus::Radius");
    _FieldCache->_Gfc2Torus_ClockSign = getFieldId(oFieldIdMap, "Gfc2Torus::ClockSign");
    _FieldCache->_Gfc2Torus_RangeV = getFieldId(oFieldIdMap, "Gfc2Torus::RangeV");
    _FieldCache->_Gfc2Torus_Curve = getFieldId(oFieldIdMap, "Gfc2Torus::Curve");
}

