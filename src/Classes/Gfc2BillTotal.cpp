#include "StdAfx.h"
#include "Gfc2BillTotal.h"
#include "Gfc2BillTotalBinarySerializer.h"
#include "Gfc2BillTotalTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2BillTotal,"Gfc2BillTotal",0)

OBJECTBUF_IMP_OBJECT(Gfc2BillTotalFieldCacheInitializer,"Gfc2BillTotal",0)

Gfc2BillTotal::Gfc2BillTotal()
{
    m_nCode = 0;
    m_nName = 0;
    m_nAttr = 0;
    m_nQuantityType = 0;
    m_nUnit = 0;
    m_nQuantity = 0;
    m_nMemo = 0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2BillTotal::isInitialized() const
{
    if ((_has_bits_[0] & 0x7f) != 0x7f) return false;

    return true;
}

int Gfc2BillTotal::typeId() const
{
    return 12;
}

glodon::objectbuf::EntitySchema* Gfc2BillTotal::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(12))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2BillTotal");
    pSchema->setId(12);
    m_pDocument->addSchema(pSchema, 12);

    pSchema->addAttribNames("Code");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Name");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Attr");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("QuantityType");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("Unit");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("Quantity");
    pSchema->addAttribIds(6);

    pSchema->addAttribNames("Memo");
    pSchema->addAttribIds(7);

    return pSchema;
}

std::string Gfc2BillTotal::entityName() const
{
    return "Gfc2BillTotal";
}

void Gfc2BillTotalFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2BillTotal_Code = getFieldId(oFieldIdMap, "Gfc2BillTotal::Code");
    _FieldCache->_Gfc2BillTotal_Name = getFieldId(oFieldIdMap, "Gfc2BillTotal::Name");
    _FieldCache->_Gfc2BillTotal_Attr = getFieldId(oFieldIdMap, "Gfc2BillTotal::Attr");
    _FieldCache->_Gfc2BillTotal_QuantityType = getFieldId(oFieldIdMap, "Gfc2BillTotal::QuantityType");
    _FieldCache->_Gfc2BillTotal_Unit = getFieldId(oFieldIdMap, "Gfc2BillTotal::Unit");
    _FieldCache->_Gfc2BillTotal_Quantity = getFieldId(oFieldIdMap, "Gfc2BillTotal::Quantity");
    _FieldCache->_Gfc2BillTotal_Memo = getFieldId(oFieldIdMap, "Gfc2BillTotal::Memo");
}

