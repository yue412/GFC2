#include "StdAfx.h"
#include "Gfc2AbnormityLineArchInfo.h"
#include "Gfc2AbnormityLineArchInfoBinarySerializer.h"
#include "Gfc2AbnormityLineArchInfoTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2AbnormityLineArchInfo,"Gfc2AbnormityLineArchInfo",0)

OBJECTBUF_IMP_OBJECT(Gfc2AbnormityLineArchInfoFieldCacheInitializer,"Gfc2AbnormityLineArchInfo",0)

Gfc2AbnormityLineArchInfo::Gfc2AbnormityLineArchInfo()
{
    m_dTopArchStartT = 0.0;
    m_dTopArchEndT = 0.0;
    m_bTopDefineByRadius = false;
    m_dTopArchHeight = 0.0;
    m_dTopArchRadius = 0.0;
    m_dDownArchStartT = 0.0;
    m_dDownArchEndT = 0.0;
    m_bDownDefineByRadius = false;
    m_dDownArchHeight = 0.0;
    m_dDownArchRadius = 0.0;
}

bool Gfc2AbnormityLineArchInfo::isInitialized() const
{
    if ((_has_bits_[0] & 0x3ff) != 0x3ff) return false;

    return true;
}

int Gfc2AbnormityLineArchInfo::typeId() const
{
    return 2;
}

glodon::objectbuf::EntitySchema* Gfc2AbnormityLineArchInfo::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(2))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2BaseLineArcInfo::createSchema());
    pSchema->setName("Gfc2AbnormityLineArchInfo");
    pSchema->setId(2);
    m_pDocument->addSchema(pSchema, 2);

    pSchema->addAttribNames("TopArchStartT");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("TopArchEndT");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("TopDefineByRadius");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("TopArchHeight");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("TopArchRadius");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("DownArchStartT");
    pSchema->addAttribIds(6);

    pSchema->addAttribNames("DownArchEndT");
    pSchema->addAttribIds(7);

    pSchema->addAttribNames("DownDefineByRadius");
    pSchema->addAttribIds(8);

    pSchema->addAttribNames("DownArchHeight");
    pSchema->addAttribIds(9);

    pSchema->addAttribNames("DownArchRadius");
    pSchema->addAttribIds(10);

    return pSchema;
}

std::string Gfc2AbnormityLineArchInfo::entityName() const
{
    return "Gfc2AbnormityLineArchInfo";
}

void Gfc2AbnormityLineArchInfoFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2AbnormityLineArchInfo_TopArchStartT = getFieldId(oFieldIdMap, "Gfc2AbnormityLineArchInfo::TopArchStartT");
    _FieldCache->_Gfc2AbnormityLineArchInfo_TopArchEndT = getFieldId(oFieldIdMap, "Gfc2AbnormityLineArchInfo::TopArchEndT");
    _FieldCache->_Gfc2AbnormityLineArchInfo_TopDefineByRadius = getFieldId(oFieldIdMap, "Gfc2AbnormityLineArchInfo::TopDefineByRadius");
    _FieldCache->_Gfc2AbnormityLineArchInfo_TopArchHeight = getFieldId(oFieldIdMap, "Gfc2AbnormityLineArchInfo::TopArchHeight");
    _FieldCache->_Gfc2AbnormityLineArchInfo_TopArchRadius = getFieldId(oFieldIdMap, "Gfc2AbnormityLineArchInfo::TopArchRadius");
    _FieldCache->_Gfc2AbnormityLineArchInfo_DownArchStartT = getFieldId(oFieldIdMap, "Gfc2AbnormityLineArchInfo::DownArchStartT");
    _FieldCache->_Gfc2AbnormityLineArchInfo_DownArchEndT = getFieldId(oFieldIdMap, "Gfc2AbnormityLineArchInfo::DownArchEndT");
    _FieldCache->_Gfc2AbnormityLineArchInfo_DownDefineByRadius = getFieldId(oFieldIdMap, "Gfc2AbnormityLineArchInfo::DownDefineByRadius");
    _FieldCache->_Gfc2AbnormityLineArchInfo_DownArchHeight = getFieldId(oFieldIdMap, "Gfc2AbnormityLineArchInfo::DownArchHeight");
    _FieldCache->_Gfc2AbnormityLineArchInfo_DownArchRadius = getFieldId(oFieldIdMap, "Gfc2AbnormityLineArchInfo::DownArchRadius");
}

