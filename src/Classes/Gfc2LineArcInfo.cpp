#include "StdAfx.h"
#include "Gfc2LineArcInfo.h"
#include "Gfc2LineArcInfoBinarySerializer.h"
#include "Gfc2LineArcInfoTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2LineArcInfo,"Gfc2LineArcInfo",0)

OBJECTBUF_IMP_OBJECT(Gfc2LineArcInfoFieldCacheInitializer,"Gfc2LineArcInfo",0)

Gfc2LineArcInfo::Gfc2LineArcInfo()
{
    m_nBasePoint = 0;
    m_dArchHeight = 0.0;
    m_dHalfChordLength = 0.0;
    m_dRadius = 0.0;
    m_bDefineByRadius = false;
}

bool Gfc2LineArcInfo::isInitialized() const
{
    if ((_has_bits_[0] & 0x1f) != 0x1f) return false;

    return true;
}

int Gfc2LineArcInfo::typeId() const
{
    return 65;
}

glodon::objectbuf::EntitySchema* Gfc2LineArcInfo::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(65))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2BaseLineArcInfo::createSchema());
    pSchema->setName("Gfc2LineArcInfo");
    pSchema->setId(65);
    m_pDocument->addSchema(pSchema, 65);

    pSchema->addAttribNames("BasePoint");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("ArchHeight");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("HalfChordLength");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("Radius");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("DefineByRadius");
    pSchema->addAttribIds(5);

    return pSchema;
}

std::string Gfc2LineArcInfo::entityName() const
{
    return "Gfc2LineArcInfo";
}

void Gfc2LineArcInfoFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2LineArcInfo_BasePoint = getFieldId(oFieldIdMap, "Gfc2LineArcInfo::BasePoint");
    _FieldCache->_Gfc2LineArcInfo_ArchHeight = getFieldId(oFieldIdMap, "Gfc2LineArcInfo::ArchHeight");
    _FieldCache->_Gfc2LineArcInfo_HalfChordLength = getFieldId(oFieldIdMap, "Gfc2LineArcInfo::HalfChordLength");
    _FieldCache->_Gfc2LineArcInfo_Radius = getFieldId(oFieldIdMap, "Gfc2LineArcInfo::Radius");
    _FieldCache->_Gfc2LineArcInfo_DefineByRadius = getFieldId(oFieldIdMap, "Gfc2LineArcInfo::DefineByRadius");
}

