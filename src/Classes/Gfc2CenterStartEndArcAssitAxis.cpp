#include "StdAfx.h"
#include "Gfc2CenterStartEndArcAssitAxis.h"
#include "Gfc2CenterStartEndArcAssitAxisBinarySerializer.h"
#include "Gfc2CenterStartEndArcAssitAxisTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2CenterStartEndArcAssitAxis,"Gfc2CenterStartEndArcAssitAxis",0)

OBJECTBUF_IMP_OBJECT(Gfc2CenterStartEndArcAssitAxisFieldCacheInitializer,"Gfc2CenterStartEndArcAssitAxis",0)

Gfc2CenterStartEndArcAssitAxis::Gfc2CenterStartEndArcAssitAxis()
{
    m_nCenter = 0;
    m_nStartPoint = 0;
    m_nEndPoint = 0;
}

bool Gfc2CenterStartEndArcAssitAxis::isInitialized() const
{
    if ((_has_bits_[0] & 0x765) != 0x765) return false;

    return true;
}

int Gfc2CenterStartEndArcAssitAxis::typeId() const
{
    return 19;
}

glodon::objectbuf::EntitySchema* Gfc2CenterStartEndArcAssitAxis::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(19))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2AssitAxis::createSchema());
    pSchema->setName("Gfc2CenterStartEndArcAssitAxis");
    pSchema->setId(19);
    m_pDocument->addSchema(pSchema, 19);

    pSchema->addAttribNames("Center");
    pSchema->addAttribIds(9);

    pSchema->addAttribNames("StartPoint");
    pSchema->addAttribIds(10);

    pSchema->addAttribNames("EndPoint");
    pSchema->addAttribIds(11);

    return pSchema;
}

std::string Gfc2CenterStartEndArcAssitAxis::entityName() const
{
    return "Gfc2CenterStartEndArcAssitAxis";
}

void Gfc2CenterStartEndArcAssitAxisFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2CenterStartEndArcAssitAxis_Center = getFieldId(oFieldIdMap, "Gfc2CenterStartEndArcAssitAxis::Center");
    _FieldCache->_Gfc2CenterStartEndArcAssitAxis_StartPoint = getFieldId(oFieldIdMap, "Gfc2CenterStartEndArcAssitAxis::StartPoint");
    _FieldCache->_Gfc2CenterStartEndArcAssitAxis_EndPoint = getFieldId(oFieldIdMap, "Gfc2CenterStartEndArcAssitAxis::EndPoint");
}

