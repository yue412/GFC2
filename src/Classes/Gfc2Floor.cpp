#include "StdAfx.h"
#include "Gfc2Floor.h"
#include "Gfc2FloorBinarySerializer.h"
#include "Gfc2FloorTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Floor,"Gfc2Floor",0)

OBJECTBUF_IMP_OBJECT(Gfc2FloorFieldCacheInitializer,"Gfc2Floor",0)

Gfc2Floor::Gfc2Floor()
{
    m_bFirstFloorFlag = false;
    m_dHeight = 0.0;
    m_nStdFloorCount = 0;
    m_dStructuralElevation = 0.0;
    m_nStartFloorNo = 0;
    m_nRemark = 0;
}

bool Gfc2Floor::isInitialized() const
{
    if ((_has_bits_[0] & 0xfd) != 0xfd) return false;

    return true;
}

int Gfc2Floor::typeId() const
{
    return 49;
}

glodon::objectbuf::EntitySchema* Gfc2Floor::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(49))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2SpatialStructureEntity::createSchema());
    pSchema->setName("Gfc2Floor");
    pSchema->setId(49);
    m_pDocument->addSchema(pSchema, 49);

    pSchema->addAttribNames("FirstFloorFlag");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("Height");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("StdFloorCount");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("StructuralElevation");
    pSchema->addAttribIds(6);

    pSchema->addAttribNames("StartFloorNo");
    pSchema->addAttribIds(7);

    pSchema->addAttribNames("Remark");
    pSchema->addAttribIds(8);

    return pSchema;
}

std::string Gfc2Floor::entityName() const
{
    return "Gfc2Floor";
}

void Gfc2FloorFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Floor_FirstFloorFlag = getFieldId(oFieldIdMap, "Gfc2Floor::FirstFloorFlag");
    _FieldCache->_Gfc2Floor_Height = getFieldId(oFieldIdMap, "Gfc2Floor::Height");
    _FieldCache->_Gfc2Floor_StdFloorCount = getFieldId(oFieldIdMap, "Gfc2Floor::StdFloorCount");
    _FieldCache->_Gfc2Floor_StructuralElevation = getFieldId(oFieldIdMap, "Gfc2Floor::StructuralElevation");
    _FieldCache->_Gfc2Floor_StartFloorNo = getFieldId(oFieldIdMap, "Gfc2Floor::StartFloorNo");
    _FieldCache->_Gfc2Floor_Remark = getFieldId(oFieldIdMap, "Gfc2Floor::Remark");
}

