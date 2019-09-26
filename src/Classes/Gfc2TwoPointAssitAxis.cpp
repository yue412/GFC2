#include "StdAfx.h"
#include "Gfc2TwoPointAssitAxis.h"
#include "Gfc2TwoPointAssitAxisBinarySerializer.h"
#include "Gfc2TwoPointAssitAxisTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2TwoPointAssitAxis,"Gfc2TwoPointAssitAxis",0)

OBJECTBUF_IMP_OBJECT(Gfc2TwoPointAssitAxisFieldCacheInitializer,"Gfc2TwoPointAssitAxis",0)

Gfc2TwoPointAssitAxis::Gfc2TwoPointAssitAxis()
{
    m_nStartPt = 0;
    m_nEndPt = 0;
}

bool Gfc2TwoPointAssitAxis::isInitialized() const
{
    if ((_has_bits_[0] & 0x365) != 0x365) return false;

    return true;
}

int Gfc2TwoPointAssitAxis::typeId() const
{
    return 134;
}

glodon::objectbuf::EntitySchema* Gfc2TwoPointAssitAxis::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(134))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2AssitAxis::createSchema());
    pSchema->setName("Gfc2TwoPointAssitAxis");
    pSchema->setId(134);
    m_pDocument->addSchema(pSchema, 134);

    pSchema->addAttribNames("StartPt");
    pSchema->addAttribIds(9);

    pSchema->addAttribNames("EndPt");
    pSchema->addAttribIds(10);

    return pSchema;
}

std::string Gfc2TwoPointAssitAxis::entityName() const
{
    return "Gfc2TwoPointAssitAxis";
}

void Gfc2TwoPointAssitAxisFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2TwoPointAssitAxis_StartPt = getFieldId(oFieldIdMap, "Gfc2TwoPointAssitAxis::StartPt");
    _FieldCache->_Gfc2TwoPointAssitAxis_EndPt = getFieldId(oFieldIdMap, "Gfc2TwoPointAssitAxis::EndPt");
}

