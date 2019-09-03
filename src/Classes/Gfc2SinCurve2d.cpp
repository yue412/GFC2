#include "StdAfx.h"
#include "Gfc2SinCurve2d.h"
#include "Gfc2SinCurve2dBinarySerializer.h"
#include "Gfc2SinCurve2dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2SinCurve2d,"Gfc2SinCurve2d",0)

OBJECTBUF_IMP_OBJECT(Gfc2SinCurve2dFieldCacheInitializer,"Gfc2SinCurve2d",0)

Gfc2SinCurve2d::Gfc2SinCurve2d()
{
    m_nPos = 0;
    m_nDirX = 0;
    m_dA = 0.0;
    m_dB = 0.0;
    m_nRange = 0;
    m_nClockSign = 0;
}

bool Gfc2SinCurve2d::isInitialized() const
{
    if ((_has_bits_[0] & 0x3f) != 0x3f) return false;

    return true;
}

int Gfc2SinCurve2d::typeId() const
{
    return 117;
}

glodon::objectbuf::EntitySchema* Gfc2SinCurve2d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(117))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Curve2d::createSchema());
    pSchema->setName("Gfc2SinCurve2d");
    pSchema->setId(117);
    m_pDocument->addSchema(pSchema, 117);

    pSchema->addAttribNames("Pos");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("DirX");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("A");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("B");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("Range");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("ClockSign");
    pSchema->addAttribIds(6);

    return pSchema;
}

std::string Gfc2SinCurve2d::entityName() const
{
    return "Gfc2SinCurve2d";
}

void Gfc2SinCurve2dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2SinCurve2d_Pos = getFieldId(oFieldIdMap, "Gfc2SinCurve2d::Pos");
    _FieldCache->_Gfc2SinCurve2d_DirX = getFieldId(oFieldIdMap, "Gfc2SinCurve2d::DirX");
    _FieldCache->_Gfc2SinCurve2d_A = getFieldId(oFieldIdMap, "Gfc2SinCurve2d::A");
    _FieldCache->_Gfc2SinCurve2d_B = getFieldId(oFieldIdMap, "Gfc2SinCurve2d::B");
    _FieldCache->_Gfc2SinCurve2d_Range = getFieldId(oFieldIdMap, "Gfc2SinCurve2d::Range");
    _FieldCache->_Gfc2SinCurve2d_ClockSign = getFieldId(oFieldIdMap, "Gfc2SinCurve2d::ClockSign");
}

