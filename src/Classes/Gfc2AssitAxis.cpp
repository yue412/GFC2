#include "StdAfx.h"
#include "Gfc2AssitAxis.h"
#include "Gfc2AssitAxisBinarySerializer.h"
#include "Gfc2AssitAxisTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2AssitAxis,"Gfc2AssitAxis",0)

OBJECTBUF_IMP_OBJECT(Gfc2AssitAxisFieldCacheInitializer,"Gfc2AssitAxis",0)

Gfc2AssitAxis::Gfc2AssitAxis()
{
    m_nAxisNo = 0;
    m_nAxisNoPos = (Gfc2AxisNoPosEnum)0;
}

bool Gfc2AssitAxis::isInitialized() const
{
    if ((_has_bits_[0] & 0x65) != 0x65) return false;

    return true;
}

int Gfc2AssitAxis::typeId() const
{
    return 5;
}

glodon::objectbuf::EntitySchema* Gfc2AssitAxis::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(5))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Entity::createSchema());
    pSchema->setName("Gfc2AssitAxis");
    pSchema->setId(5);
    m_pDocument->addSchema(pSchema, 5);

    pSchema->addAttribNames("AxisNo");
    pSchema->addAttribIds(6);

    pSchema->addAttribNames("AxisNoPos");
    pSchema->addAttribIds(7);

    pSchema->addAttribNames("TrimPoints");
    pSchema->addAttribIds(8);

    return pSchema;
}

std::string Gfc2AssitAxis::entityName() const
{
    return "Gfc2AssitAxis";
}

void Gfc2AssitAxisFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2AssitAxis_AxisNo = getFieldId(oFieldIdMap, "Gfc2AssitAxis::AxisNo");
    _FieldCache->_Gfc2AssitAxis_AxisNoPos = getFieldId(oFieldIdMap, "Gfc2AssitAxis::AxisNoPos");
    _FieldCache->_Gfc2AssitAxis_TrimPoints = getFieldId(oFieldIdMap, "Gfc2AssitAxis::TrimPoints");
}

