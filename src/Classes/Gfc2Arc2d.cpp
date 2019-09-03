#include "StdAfx.h"
#include "Gfc2Arc2d.h"
#include "Gfc2Arc2dBinarySerializer.h"
#include "Gfc2Arc2dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Arc2d,"Gfc2Arc2d",0)

OBJECTBUF_IMP_OBJECT(Gfc2Arc2dFieldCacheInitializer,"Gfc2Arc2d",0)

Gfc2Arc2d::Gfc2Arc2d()
{
    m_nCenterPt = 0;
    m_dRadius = 0.0;
    m_nRange = 0;
    m_nClockSign = 0;
}

bool Gfc2Arc2d::isInitialized() const
{
    if ((_has_bits_[0] & 0xf) != 0xf) return false;

    return true;
}

int Gfc2Arc2d::typeId() const
{
    return 3;
}

glodon::objectbuf::EntitySchema* Gfc2Arc2d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(3))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Curve2d::createSchema());
    pSchema->setName("Gfc2Arc2d");
    pSchema->setId(3);
    m_pDocument->addSchema(pSchema, 3);

    pSchema->addAttribNames("CenterPt");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Radius");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Range");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("ClockSign");
    pSchema->addAttribIds(4);

    return pSchema;
}

std::string Gfc2Arc2d::entityName() const
{
    return "Gfc2Arc2d";
}

void Gfc2Arc2dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Arc2d_CenterPt = getFieldId(oFieldIdMap, "Gfc2Arc2d::CenterPt");
    _FieldCache->_Gfc2Arc2d_Radius = getFieldId(oFieldIdMap, "Gfc2Arc2d::Radius");
    _FieldCache->_Gfc2Arc2d_Range = getFieldId(oFieldIdMap, "Gfc2Arc2d::Range");
    _FieldCache->_Gfc2Arc2d_ClockSign = getFieldId(oFieldIdMap, "Gfc2Arc2d::ClockSign");
}

