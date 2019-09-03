#include "StdAfx.h"
#include "Gfc2AxisAngleAssitAxis.h"
#include "Gfc2AxisAngleAssitAxisBinarySerializer.h"
#include "Gfc2AxisAngleAssitAxisTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2AxisAngleAssitAxis,"Gfc2AxisAngleAssitAxis",0)

OBJECTBUF_IMP_OBJECT(Gfc2AxisAngleAssitAxisFieldCacheInitializer,"Gfc2AxisAngleAssitAxis",0)

Gfc2AxisAngleAssitAxis::Gfc2AxisAngleAssitAxis()
{
    m_nRefAxisNo = 0;
    m_nRefPoint = 0;
    m_dAngle = 0.0;
    m_nRefAxisIndex = 0;
    m_nRefAxisType = (Gfc2AxisType)0;
}

bool Gfc2AxisAngleAssitAxis::isInitialized() const
{
    if ((_has_bits_[0] & 0x1f65) != 0x1f65) return false;

    return true;
}

int Gfc2AxisAngleAssitAxis::typeId() const
{
    return 6;
}

glodon::objectbuf::EntitySchema* Gfc2AxisAngleAssitAxis::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(6))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2AssitAxis::createSchema());
    pSchema->setName("Gfc2AxisAngleAssitAxis");
    pSchema->setId(6);
    m_pDocument->addSchema(pSchema, 6);

    pSchema->addAttribNames("RefAxisNo");
    pSchema->addAttribIds(9);

    pSchema->addAttribNames("RefPoint");
    pSchema->addAttribIds(10);

    pSchema->addAttribNames("Angle");
    pSchema->addAttribIds(11);

    pSchema->addAttribNames("RefAxisIndex");
    pSchema->addAttribIds(12);

    pSchema->addAttribNames("RefAxisType");
    pSchema->addAttribIds(13);

    return pSchema;
}

std::string Gfc2AxisAngleAssitAxis::entityName() const
{
    return "Gfc2AxisAngleAssitAxis";
}

void Gfc2AxisAngleAssitAxisFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2AxisAngleAssitAxis_RefAxisNo = getFieldId(oFieldIdMap, "Gfc2AxisAngleAssitAxis::RefAxisNo");
    _FieldCache->_Gfc2AxisAngleAssitAxis_RefPoint = getFieldId(oFieldIdMap, "Gfc2AxisAngleAssitAxis::RefPoint");
    _FieldCache->_Gfc2AxisAngleAssitAxis_Angle = getFieldId(oFieldIdMap, "Gfc2AxisAngleAssitAxis::Angle");
    _FieldCache->_Gfc2AxisAngleAssitAxis_RefAxisIndex = getFieldId(oFieldIdMap, "Gfc2AxisAngleAssitAxis::RefAxisIndex");
    _FieldCache->_Gfc2AxisAngleAssitAxis_RefAxisType = getFieldId(oFieldIdMap, "Gfc2AxisAngleAssitAxis::RefAxisType");
}

