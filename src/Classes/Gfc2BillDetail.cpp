#include "StdAfx.h"
#include "Gfc2BillDetail.h"
#include "Gfc2BillDetailBinarySerializer.h"
#include "Gfc2BillDetailTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2BillDetail,"Gfc2BillDetail",0)

OBJECTBUF_IMP_OBJECT(Gfc2BillDetailFieldCacheInitializer,"Gfc2BillDetail",0)

Gfc2BillDetail::Gfc2BillDetail()
{
    m_nFloorNum = 0;
    m_nEntityID = 0;
    m_nUnit = 0;
    m_nExpress = 0;
    m_nQuantity = 0;
    m_nMemo = 0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2BillDetail::isInitialized() const
{
    if ((_has_bits_[0] & 0x3f) != 0x3f) return false;

    return true;
}

int Gfc2BillDetail::typeId() const
{
    return 11;
}

glodon::objectbuf::EntitySchema* Gfc2BillDetail::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(11))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2BillDetail");
    pSchema->setId(11);
    m_pDocument->addSchema(pSchema, 11);

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

std::string Gfc2BillDetail::entityName() const
{
    return "Gfc2BillDetail";
}

void Gfc2BillDetailFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2BillDetail_FloorNum = getFieldId(oFieldIdMap, "Gfc2BillDetail::FloorNum");
    _FieldCache->_Gfc2BillDetail_EntityID = getFieldId(oFieldIdMap, "Gfc2BillDetail::EntityID");
    _FieldCache->_Gfc2BillDetail_Unit = getFieldId(oFieldIdMap, "Gfc2BillDetail::Unit");
    _FieldCache->_Gfc2BillDetail_Express = getFieldId(oFieldIdMap, "Gfc2BillDetail::Express");
    _FieldCache->_Gfc2BillDetail_Quantity = getFieldId(oFieldIdMap, "Gfc2BillDetail::Quantity");
    _FieldCache->_Gfc2BillDetail_Memo = getFieldId(oFieldIdMap, "Gfc2BillDetail::Memo");
}

