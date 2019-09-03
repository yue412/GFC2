#include "StdAfx.h"
#include "Gfc2Intervald.h"
#include "Gfc2IntervaldBinarySerializer.h"
#include "Gfc2IntervaldTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Intervald,"Gfc2Intervald",0)

OBJECTBUF_IMP_OBJECT(Gfc2IntervaldFieldCacheInitializer,"Gfc2Intervald",0)

Gfc2Intervald::Gfc2Intervald()
{
    m_dMin = 0.0;
    m_dMax = 0.0;
}

bool Gfc2Intervald::isInitialized() const
{
    if ((_has_bits_[0] & 0x3) != 0x3) return false;

    return true;
}

int Gfc2Intervald::typeId() const
{
    return 62;
}

glodon::objectbuf::EntitySchema* Gfc2Intervald::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(62))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Geometry::createSchema());
    pSchema->setName("Gfc2Intervald");
    pSchema->setId(62);
    m_pDocument->addSchema(pSchema, 62);

    pSchema->addAttribNames("Min");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Max");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2Intervald::entityName() const
{
    return "Gfc2Intervald";
}

void Gfc2IntervaldFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Intervald_Min = getFieldId(oFieldIdMap, "Gfc2Intervald::Min");
    _FieldCache->_Gfc2Intervald_Max = getFieldId(oFieldIdMap, "Gfc2Intervald::Max");
}

