#include "StdAfx.h"
#include "Gfc2InternalChart.h"
#include "Gfc2InternalChartBinarySerializer.h"
#include "Gfc2InternalChartTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2InternalChart,"Gfc2InternalChart",0)

OBJECTBUF_IMP_OBJECT(Gfc2InternalChartFieldCacheInitializer,"Gfc2InternalChart",0)

Gfc2InternalChart::Gfc2InternalChart()
{
    m_dTra1 = 0.0;
    m_dTra2 = 0.0;
    m_dTra3 = 0.0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2InternalChart::isInitialized() const
{
    if ((_has_bits_[0] & 0x7) != 0x7) return false;

    return true;
}

int Gfc2InternalChart::typeId() const
{
    return 59;
}

glodon::objectbuf::EntitySchema* Gfc2InternalChart::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(59))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2InternalChart");
    pSchema->setId(59);
    m_pDocument->addSchema(pSchema, 59);

    pSchema->addAttribNames("Tra1");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Tra2");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Tra3");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("IPS");
    pSchema->addAttribIds(4);

    return pSchema;
}

std::string Gfc2InternalChart::entityName() const
{
    return "Gfc2InternalChart";
}

void Gfc2InternalChartFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2InternalChart_Tra1 = getFieldId(oFieldIdMap, "Gfc2InternalChart::Tra1");
    _FieldCache->_Gfc2InternalChart_Tra2 = getFieldId(oFieldIdMap, "Gfc2InternalChart::Tra2");
    _FieldCache->_Gfc2InternalChart_Tra3 = getFieldId(oFieldIdMap, "Gfc2InternalChart::Tra3");
    _FieldCache->_Gfc2InternalChart_IPS = getFieldId(oFieldIdMap, "Gfc2InternalChart::IPS");
}

