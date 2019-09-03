#include "StdAfx.h"
#include "Gfc2PreimageCurve2d.h"
#include "Gfc2PreimageCurve2dBinarySerializer.h"
#include "Gfc2PreimageCurve2dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2PreimageCurve2d,"Gfc2PreimageCurve2d",0)

OBJECTBUF_IMP_OBJECT(Gfc2PreimageCurve2dFieldCacheInitializer,"Gfc2PreimageCurve2d",0)

Gfc2PreimageCurve2d::Gfc2PreimageCurve2d()
{
    m_nRange = 0;
    m_bReversed = false;
    m_nBase = 0;
    m_nCurve = 0;
    m_dTolerance = 0.0;
}

bool Gfc2PreimageCurve2d::isInitialized() const
{
    if ((_has_bits_[0] & 0x1f) != 0x1f) return false;

    return true;
}

int Gfc2PreimageCurve2d::typeId() const
{
    return 92;
}

glodon::objectbuf::EntitySchema* Gfc2PreimageCurve2d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(92))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Curve2d::createSchema());
    pSchema->setName("Gfc2PreimageCurve2d");
    pSchema->setId(92);
    m_pDocument->addSchema(pSchema, 92);

    pSchema->addAttribNames("Range");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Reversed");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Base");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("Curve");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("Tolerance");
    pSchema->addAttribIds(5);

    return pSchema;
}

std::string Gfc2PreimageCurve2d::entityName() const
{
    return "Gfc2PreimageCurve2d";
}

void Gfc2PreimageCurve2dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2PreimageCurve2d_Range = getFieldId(oFieldIdMap, "Gfc2PreimageCurve2d::Range");
    _FieldCache->_Gfc2PreimageCurve2d_Reversed = getFieldId(oFieldIdMap, "Gfc2PreimageCurve2d::Reversed");
    _FieldCache->_Gfc2PreimageCurve2d_Base = getFieldId(oFieldIdMap, "Gfc2PreimageCurve2d::Base");
    _FieldCache->_Gfc2PreimageCurve2d_Curve = getFieldId(oFieldIdMap, "Gfc2PreimageCurve2d::Curve");
    _FieldCache->_Gfc2PreimageCurve2d_Tolerance = getFieldId(oFieldIdMap, "Gfc2PreimageCurve2d::Tolerance");
}

