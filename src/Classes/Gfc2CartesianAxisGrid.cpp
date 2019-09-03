#include "StdAfx.h"
#include "Gfc2CartesianAxisGrid.h"
#include "Gfc2CartesianAxisGridBinarySerializer.h"
#include "Gfc2CartesianAxisGridTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2CartesianAxisGrid,"Gfc2CartesianAxisGrid",0)

OBJECTBUF_IMP_OBJECT(Gfc2CartesianAxisGridFieldCacheInitializer,"Gfc2CartesianAxisGrid",0)

Gfc2CartesianAxisGrid::Gfc2CartesianAxisGrid()
{
    m_nInsertPt = 0;
    m_dAxisAngle = 0.0;
}

bool Gfc2CartesianAxisGrid::isInitialized() const
{
    if ((_has_bits_[0] & 0x65) != 0x65) return false;

    return true;
}

int Gfc2CartesianAxisGrid::typeId() const
{
    return 18;
}

glodon::objectbuf::EntitySchema* Gfc2CartesianAxisGrid::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(18))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2AxisGrid::createSchema());
    pSchema->setName("Gfc2CartesianAxisGrid");
    pSchema->setId(18);
    m_pDocument->addSchema(pSchema, 18);

    pSchema->addAttribNames("InsertPt");
    pSchema->addAttribIds(6);

    pSchema->addAttribNames("AxisAngle");
    pSchema->addAttribIds(7);

    pSchema->addAttribNames("SKJ");
    pSchema->addAttribIds(8);

    pSchema->addAttribNames("ZJS");
    pSchema->addAttribIds(9);

    pSchema->addAttribNames("YJS");
    pSchema->addAttribIds(10);

    pSchema->addAttribNames("XKJ");
    pSchema->addAttribIds(11);

    return pSchema;
}

std::string Gfc2CartesianAxisGrid::entityName() const
{
    return "Gfc2CartesianAxisGrid";
}

void Gfc2CartesianAxisGridFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2CartesianAxisGrid_InsertPt = getFieldId(oFieldIdMap, "Gfc2CartesianAxisGrid::InsertPt");
    _FieldCache->_Gfc2CartesianAxisGrid_AxisAngle = getFieldId(oFieldIdMap, "Gfc2CartesianAxisGrid::AxisAngle");
    _FieldCache->_Gfc2CartesianAxisGrid_SKJ = getFieldId(oFieldIdMap, "Gfc2CartesianAxisGrid::SKJ");
    _FieldCache->_Gfc2CartesianAxisGrid_ZJS = getFieldId(oFieldIdMap, "Gfc2CartesianAxisGrid::ZJS");
    _FieldCache->_Gfc2CartesianAxisGrid_YJS = getFieldId(oFieldIdMap, "Gfc2CartesianAxisGrid::YJS");
    _FieldCache->_Gfc2CartesianAxisGrid_XKJ = getFieldId(oFieldIdMap, "Gfc2CartesianAxisGrid::XKJ");
}

