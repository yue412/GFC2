#include "StdAfx.h"
#include "Gfc2PolarAngleAssitAxis.h"
#include "Gfc2PolarAngleAssitAxisBinarySerializer.h"
#include "Gfc2PolarAngleAssitAxisTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2PolarAngleAssitAxis,"Gfc2PolarAngleAssitAxis",0)

OBJECTBUF_IMP_OBJECT(Gfc2PolarAngleAssitAxisFieldCacheInitializer,"Gfc2PolarAngleAssitAxis",0)

Gfc2PolarAngleAssitAxis::Gfc2PolarAngleAssitAxis()
{
    m_nRefAxisNo = 0;
    m_dAngle = 0.0;
    m_nRefAxisIndex = 0;
}

bool Gfc2PolarAngleAssitAxis::isInitialized() const
{
    if ((_has_bits_[0] & 0x765) != 0x765) return false;

    return true;
}

int Gfc2PolarAngleAssitAxis::typeId() const
{
    return 85;
}

glodon::objectbuf::EntitySchema* Gfc2PolarAngleAssitAxis::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(85))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2AssitAxis::createSchema());
    pSchema->setName("Gfc2PolarAngleAssitAxis");
    pSchema->setId(85);
    m_pDocument->addSchema(pSchema, 85);

    pSchema->addAttribNames("RefAxisNo");
    pSchema->addAttribIds(9);

    pSchema->addAttribNames("Angle");
    pSchema->addAttribIds(10);

    pSchema->addAttribNames("RefAxisIndex");
    pSchema->addAttribIds(11);

    return pSchema;
}

std::string Gfc2PolarAngleAssitAxis::entityName() const
{
    return "Gfc2PolarAngleAssitAxis";
}

void Gfc2PolarAngleAssitAxisFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2PolarAngleAssitAxis_RefAxisNo = getFieldId(oFieldIdMap, "Gfc2PolarAngleAssitAxis::RefAxisNo");
    _FieldCache->_Gfc2PolarAngleAssitAxis_Angle = getFieldId(oFieldIdMap, "Gfc2PolarAngleAssitAxis::Angle");
    _FieldCache->_Gfc2PolarAngleAssitAxis_RefAxisIndex = getFieldId(oFieldIdMap, "Gfc2PolarAngleAssitAxis::RefAxisIndex");
}

