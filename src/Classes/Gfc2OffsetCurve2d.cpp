#include "StdAfx.h"
#include "Gfc2OffsetCurve2d.h"
#include "Gfc2OffsetCurve2dBinarySerializer.h"
#include "Gfc2OffsetCurve2dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2OffsetCurve2d,"Gfc2OffsetCurve2d",0)

OBJECTBUF_IMP_OBJECT(Gfc2OffsetCurve2dFieldCacheInitializer,"Gfc2OffsetCurve2d",0)

Gfc2OffsetCurve2d::Gfc2OffsetCurve2d()
{
    m_dOffDist = 0.0;
    m_nInitCurve = 0;
}

bool Gfc2OffsetCurve2d::isInitialized() const
{
    if ((_has_bits_[0] & 0x3) != 0x3) return false;

    return true;
}

int Gfc2OffsetCurve2d::typeId() const
{
    return 75;
}

glodon::objectbuf::EntitySchema* Gfc2OffsetCurve2d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(75))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Curve2d::createSchema());
    pSchema->setName("Gfc2OffsetCurve2d");
    pSchema->setId(75);
    m_pDocument->addSchema(pSchema, 75);

    pSchema->addAttribNames("OffDist");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("InitCurve");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2OffsetCurve2d::entityName() const
{
    return "Gfc2OffsetCurve2d";
}

void Gfc2OffsetCurve2dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2OffsetCurve2d_OffDist = getFieldId(oFieldIdMap, "Gfc2OffsetCurve2d::OffDist");
    _FieldCache->_Gfc2OffsetCurve2d_InitCurve = getFieldId(oFieldIdMap, "Gfc2OffsetCurve2d::InitCurve");
}

