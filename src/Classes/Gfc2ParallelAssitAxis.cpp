#include "StdAfx.h"
#include "Gfc2ParallelAssitAxis.h"
#include "Gfc2ParallelAssitAxisBinarySerializer.h"
#include "Gfc2ParallelAssitAxisTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2ParallelAssitAxis,"Gfc2ParallelAssitAxis",0)

OBJECTBUF_IMP_OBJECT(Gfc2ParallelAssitAxisFieldCacheInitializer,"Gfc2ParallelAssitAxis",0)

Gfc2ParallelAssitAxis::Gfc2ParallelAssitAxis()
{
    m_nRefAxisNo = 0;
    m_dOffset = 0.0;
    m_nRefAxisIndex = 0;
    m_nRefAxisType = (Gfc2AxisType)0;
}

bool Gfc2ParallelAssitAxis::isInitialized() const
{
    if ((_has_bits_[0] & 0xf65) != 0xf65) return false;

    return true;
}

int Gfc2ParallelAssitAxis::typeId() const
{
    return 76;
}

glodon::objectbuf::EntitySchema* Gfc2ParallelAssitAxis::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(76))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2AssitAxis::createSchema());
    pSchema->setName("Gfc2ParallelAssitAxis");
    pSchema->setId(76);
    m_pDocument->addSchema(pSchema, 76);

    pSchema->addAttribNames("RefAxisNo");
    pSchema->addAttribIds(9);

    pSchema->addAttribNames("Offset");
    pSchema->addAttribIds(10);

    pSchema->addAttribNames("RefAxisIndex");
    pSchema->addAttribIds(11);

    pSchema->addAttribNames("RefAxisType");
    pSchema->addAttribIds(12);

    return pSchema;
}

std::string Gfc2ParallelAssitAxis::entityName() const
{
    return "Gfc2ParallelAssitAxis";
}

void Gfc2ParallelAssitAxisFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2ParallelAssitAxis_RefAxisNo = getFieldId(oFieldIdMap, "Gfc2ParallelAssitAxis::RefAxisNo");
    _FieldCache->_Gfc2ParallelAssitAxis_Offset = getFieldId(oFieldIdMap, "Gfc2ParallelAssitAxis::Offset");
    _FieldCache->_Gfc2ParallelAssitAxis_RefAxisIndex = getFieldId(oFieldIdMap, "Gfc2ParallelAssitAxis::RefAxisIndex");
    _FieldCache->_Gfc2ParallelAssitAxis_RefAxisType = getFieldId(oFieldIdMap, "Gfc2ParallelAssitAxis::RefAxisType");
}

