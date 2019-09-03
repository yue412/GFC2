#include "StdAfx.h"
#include "Gfc2PointAngleAssitAxis.h"
#include "Gfc2PointAngleAssitAxisBinarySerializer.h"
#include "Gfc2PointAngleAssitAxisTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2PointAngleAssitAxis,"Gfc2PointAngleAssitAxis",0)

OBJECTBUF_IMP_OBJECT(Gfc2PointAngleAssitAxisFieldCacheInitializer,"Gfc2PointAngleAssitAxis",0)

Gfc2PointAngleAssitAxis::Gfc2PointAngleAssitAxis()
{
    m_nRefPoint = 0;
    m_dAngle = 0.0;
}

bool Gfc2PointAngleAssitAxis::isInitialized() const
{
    if ((_has_bits_[0] & 0x365) != 0x365) return false;

    return true;
}

int Gfc2PointAngleAssitAxis::typeId() const
{
    return 82;
}

glodon::objectbuf::EntitySchema* Gfc2PointAngleAssitAxis::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(82))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2AssitAxis::createSchema());
    pSchema->setName("Gfc2PointAngleAssitAxis");
    pSchema->setId(82);
    m_pDocument->addSchema(pSchema, 82);

    pSchema->addAttribNames("RefPoint");
    pSchema->addAttribIds(9);

    pSchema->addAttribNames("Angle");
    pSchema->addAttribIds(10);

    return pSchema;
}

std::string Gfc2PointAngleAssitAxis::entityName() const
{
    return "Gfc2PointAngleAssitAxis";
}

void Gfc2PointAngleAssitAxisFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2PointAngleAssitAxis_RefPoint = getFieldId(oFieldIdMap, "Gfc2PointAngleAssitAxis::RefPoint");
    _FieldCache->_Gfc2PointAngleAssitAxis_Angle = getFieldId(oFieldIdMap, "Gfc2PointAngleAssitAxis::Angle");
}

