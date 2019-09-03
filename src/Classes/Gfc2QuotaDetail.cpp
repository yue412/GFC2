#include "StdAfx.h"
#include "Gfc2QuotaDetail.h"
#include "Gfc2QuotaDetailBinarySerializer.h"
#include "Gfc2QuotaDetailTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2QuotaDetail,"Gfc2QuotaDetail",0)

OBJECTBUF_IMP_OBJECT(Gfc2QuotaDetailFieldCacheInitializer,"Gfc2QuotaDetail",0)

Gfc2QuotaDetail::Gfc2QuotaDetail()
{
    m_nFloorNum = 0;
    m_nEntityID = 0;
    m_nUnit = 0;
    m_nExpress = 0;
    m_nQuantity = 0;
    m_nMemo = 0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2QuotaDetail::isInitialized() const
{
    if ((_has_bits_[0] & 0x3f) != 0x3f) return false;

    return true;
}

int Gfc2QuotaDetail::typeId() const
{
    return 96;
}

glodon::objectbuf::EntitySchema* Gfc2QuotaDetail::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(96))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2QuotaDetail");
    pSchema->setId(96);
    m_pDocument->addSchema(pSchema, 96);

    pSchema->addAttribNames("FloorNum");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("EntityID");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Unit");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("Express");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("Quantity");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("Memo");
    pSchema->addAttribIds(6);

    return pSchema;
}

std::string Gfc2QuotaDetail::entityName() const
{
    return "Gfc2QuotaDetail";
}

void Gfc2QuotaDetailFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2QuotaDetail_FloorNum = getFieldId(oFieldIdMap, "Gfc2QuotaDetail::FloorNum");
    _FieldCache->_Gfc2QuotaDetail_EntityID = getFieldId(oFieldIdMap, "Gfc2QuotaDetail::EntityID");
    _FieldCache->_Gfc2QuotaDetail_Unit = getFieldId(oFieldIdMap, "Gfc2QuotaDetail::Unit");
    _FieldCache->_Gfc2QuotaDetail_Express = getFieldId(oFieldIdMap, "Gfc2QuotaDetail::Express");
    _FieldCache->_Gfc2QuotaDetail_Quantity = getFieldId(oFieldIdMap, "Gfc2QuotaDetail::Quantity");
    _FieldCache->_Gfc2QuotaDetail_Memo = getFieldId(oFieldIdMap, "Gfc2QuotaDetail::Memo");
}

