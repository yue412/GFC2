#include "StdAfx.h"
#include "Gfc2EdgeData.h"
#include "Gfc2EdgeDataBinarySerializer.h"
#include "Gfc2EdgeDataTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2EdgeData,"Gfc2EdgeData",0)

OBJECTBUF_IMP_OBJECT(Gfc2EdgeDataFieldCacheInitializer,"Gfc2EdgeData",0)

Gfc2EdgeData::Gfc2EdgeData()
{
    m_nEdgeIndex = 0;
    m_nLoopIndex = 0;
    m_nType = 0;
    m_nEdgeInfo = 0;
    m_nParam = 0;
    m_nBaseType = 0;
    m_nSlopePoly = 0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2EdgeData::isInitialized() const
{
    if ((_has_bits_[0] & 0x3f) != 0x3f) return false;

    return true;
}

int Gfc2EdgeData::typeId() const
{
    return 36;
}

glodon::objectbuf::EntitySchema* Gfc2EdgeData::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(36))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2EdgeData");
    pSchema->setId(36);
    m_pDocument->addSchema(pSchema, 36);

    pSchema->addAttribNames("EdgeIndex");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("LoopIndex");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Type");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("EdgeInfo");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("Param");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("BaseType");
    pSchema->addAttribIds(6);

    pSchema->addAttribNames("SlopePoly");
    pSchema->addAttribIds(7);

    return pSchema;
}

std::string Gfc2EdgeData::entityName() const
{
    return "Gfc2EdgeData";
}

void Gfc2EdgeDataFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2EdgeData_EdgeIndex = getFieldId(oFieldIdMap, "Gfc2EdgeData::EdgeIndex");
    _FieldCache->_Gfc2EdgeData_LoopIndex = getFieldId(oFieldIdMap, "Gfc2EdgeData::LoopIndex");
    _FieldCache->_Gfc2EdgeData_Type = getFieldId(oFieldIdMap, "Gfc2EdgeData::Type");
    _FieldCache->_Gfc2EdgeData_EdgeInfo = getFieldId(oFieldIdMap, "Gfc2EdgeData::EdgeInfo");
    _FieldCache->_Gfc2EdgeData_Param = getFieldId(oFieldIdMap, "Gfc2EdgeData::Param");
    _FieldCache->_Gfc2EdgeData_BaseType = getFieldId(oFieldIdMap, "Gfc2EdgeData::BaseType");
    _FieldCache->_Gfc2EdgeData_SlopePoly = getFieldId(oFieldIdMap, "Gfc2EdgeData::SlopePoly");
}

