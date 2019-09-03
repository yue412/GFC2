#include "StdAfx.h"
#include "Gfc2AxisDataItem.h"
#include "Gfc2AxisDataItemBinarySerializer.h"
#include "Gfc2AxisDataItemTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2AxisDataItem,"Gfc2AxisDataItem",0)

OBJECTBUF_IMP_OBJECT(Gfc2AxisDataItemFieldCacheInitializer,"Gfc2AxisDataItem",0)

Gfc2AxisDataItem::Gfc2AxisDataItem()
{
    m_nAxisNo = 0;
    m_dDistance = 0.0;
    m_nLevel = 0;
    m_nAxisNoPos = (Gfc2AxisNoPosEnum)0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2AxisDataItem::isInitialized() const
{
    if ((_has_bits_[0] & 0xf) != 0xf) return false;

    return true;
}

int Gfc2AxisDataItem::typeId() const
{
    return 7;
}

glodon::objectbuf::EntitySchema* Gfc2AxisDataItem::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(7))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2AxisDataItem");
    pSchema->setId(7);
    m_pDocument->addSchema(pSchema, 7);

    pSchema->addAttribNames("AxisNo");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Distance");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Level");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("AxisNoPos");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("TrimPoints");
    pSchema->addAttribIds(5);

    return pSchema;
}

std::string Gfc2AxisDataItem::entityName() const
{
    return "Gfc2AxisDataItem";
}

void Gfc2AxisDataItemFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2AxisDataItem_AxisNo = getFieldId(oFieldIdMap, "Gfc2AxisDataItem::AxisNo");
    _FieldCache->_Gfc2AxisDataItem_Distance = getFieldId(oFieldIdMap, "Gfc2AxisDataItem::Distance");
    _FieldCache->_Gfc2AxisDataItem_Level = getFieldId(oFieldIdMap, "Gfc2AxisDataItem::Level");
    _FieldCache->_Gfc2AxisDataItem_AxisNoPos = getFieldId(oFieldIdMap, "Gfc2AxisDataItem::AxisNoPos");
    _FieldCache->_Gfc2AxisDataItem_TrimPoints = getFieldId(oFieldIdMap, "Gfc2AxisDataItem::TrimPoints");
}

