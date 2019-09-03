#include "StdAfx.h"
#include "Gfc2SteelDetail.h"
#include "Gfc2SteelDetailBinarySerializer.h"
#include "Gfc2SteelDetailTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2SteelDetail,"Gfc2SteelDetail",0)

OBJECTBUF_IMP_OBJECT(Gfc2SteelDetailFieldCacheInitializer,"Gfc2SteelDetail",0)

Gfc2SteelDetail::Gfc2SteelDetail()
{
    m_nEntityID = 0;
    m_nName = 0;
    m_nDesc = 0;
    m_nLevel = 0;
    m_nDia = 0;
    m_nNum = 0;
    m_nLength = 0;
    m_dSingleWeight = 0.0;
    m_dTotalWeight = 0.0;
    m_nTieinNum = 0;
    m_nTieinType = 0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2SteelDetail::isInitialized() const
{
    if ((_has_bits_[0] & 0x7ff) != 0x7ff) return false;

    return true;
}

int Gfc2SteelDetail::typeId() const
{
    return 125;
}

glodon::objectbuf::EntitySchema* Gfc2SteelDetail::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(125))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2SteelDetail");
    pSchema->setId(125);
    m_pDocument->addSchema(pSchema, 125);

    pSchema->addAttribNames("EntityID");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Name");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Desc");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("Level");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("Dia");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("Num");
    pSchema->addAttribIds(6);

    pSchema->addAttribNames("Length");
    pSchema->addAttribIds(7);

    pSchema->addAttribNames("SingleWeight");
    pSchema->addAttribIds(8);

    pSchema->addAttribNames("TotalWeight");
    pSchema->addAttribIds(9);

    pSchema->addAttribNames("TieinNum");
    pSchema->addAttribIds(10);

    pSchema->addAttribNames("TieinType");
    pSchema->addAttribIds(11);

    return pSchema;
}

std::string Gfc2SteelDetail::entityName() const
{
    return "Gfc2SteelDetail";
}

void Gfc2SteelDetailFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2SteelDetail_EntityID = getFieldId(oFieldIdMap, "Gfc2SteelDetail::EntityID");
    _FieldCache->_Gfc2SteelDetail_Name = getFieldId(oFieldIdMap, "Gfc2SteelDetail::Name");
    _FieldCache->_Gfc2SteelDetail_Desc = getFieldId(oFieldIdMap, "Gfc2SteelDetail::Desc");
    _FieldCache->_Gfc2SteelDetail_Level = getFieldId(oFieldIdMap, "Gfc2SteelDetail::Level");
    _FieldCache->_Gfc2SteelDetail_Dia = getFieldId(oFieldIdMap, "Gfc2SteelDetail::Dia");
    _FieldCache->_Gfc2SteelDetail_Num = getFieldId(oFieldIdMap, "Gfc2SteelDetail::Num");
    _FieldCache->_Gfc2SteelDetail_Length = getFieldId(oFieldIdMap, "Gfc2SteelDetail::Length");
    _FieldCache->_Gfc2SteelDetail_SingleWeight = getFieldId(oFieldIdMap, "Gfc2SteelDetail::SingleWeight");
    _FieldCache->_Gfc2SteelDetail_TotalWeight = getFieldId(oFieldIdMap, "Gfc2SteelDetail::TotalWeight");
    _FieldCache->_Gfc2SteelDetail_TieinNum = getFieldId(oFieldIdMap, "Gfc2SteelDetail::TieinNum");
    _FieldCache->_Gfc2SteelDetail_TieinType = getFieldId(oFieldIdMap, "Gfc2SteelDetail::TieinType");
}

