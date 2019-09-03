#include "StdAfx.h"
#include "Gfc2QuotaTotal.h"
#include "Gfc2QuotaTotalBinarySerializer.h"
#include "Gfc2QuotaTotalTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2QuotaTotal,"Gfc2QuotaTotal",0)

OBJECTBUF_IMP_OBJECT(Gfc2QuotaTotalFieldCacheInitializer,"Gfc2QuotaTotal",0)

Gfc2QuotaTotal::Gfc2QuotaTotal()
{
    m_nCode = 0;
    m_nSubCode = 0;
    m_nName = 0;
    m_nContent = 0;
    m_nUnit = 0;
    m_nQuantity = 0;
    m_nMemo = 0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2QuotaTotal::isInitialized() const
{
    if ((_has_bits_[0] & 0x7f) != 0x7f) return false;

    return true;
}

int Gfc2QuotaTotal::typeId() const
{
    return 97;
}

glodon::objectbuf::EntitySchema* Gfc2QuotaTotal::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(97))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2QuotaTotal");
    pSchema->setId(97);
    m_pDocument->addSchema(pSchema, 97);

    pSchema->addAttribNames("Code");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("SubCode");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Name");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("Content");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("Unit");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("Quantity");
    pSchema->addAttribIds(6);

    pSchema->addAttribNames("Memo");
    pSchema->addAttribIds(7);

    return pSchema;
}

std::string Gfc2QuotaTotal::entityName() const
{
    return "Gfc2QuotaTotal";
}

void Gfc2QuotaTotalFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2QuotaTotal_Code = getFieldId(oFieldIdMap, "Gfc2QuotaTotal::Code");
    _FieldCache->_Gfc2QuotaTotal_SubCode = getFieldId(oFieldIdMap, "Gfc2QuotaTotal::SubCode");
    _FieldCache->_Gfc2QuotaTotal_Name = getFieldId(oFieldIdMap, "Gfc2QuotaTotal::Name");
    _FieldCache->_Gfc2QuotaTotal_Content = getFieldId(oFieldIdMap, "Gfc2QuotaTotal::Content");
    _FieldCache->_Gfc2QuotaTotal_Unit = getFieldId(oFieldIdMap, "Gfc2QuotaTotal::Unit");
    _FieldCache->_Gfc2QuotaTotal_Quantity = getFieldId(oFieldIdMap, "Gfc2QuotaTotal::Quantity");
    _FieldCache->_Gfc2QuotaTotal_Memo = getFieldId(oFieldIdMap, "Gfc2QuotaTotal::Memo");
}

