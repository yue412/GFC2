#include "StdAfx.h"
#include "Gfc2PolarAxisGrid.h"
#include "Gfc2PolarAxisGridBinarySerializer.h"
#include "Gfc2PolarAxisGridTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2PolarAxisGrid,"Gfc2PolarAxisGrid",0)

OBJECTBUF_IMP_OBJECT(Gfc2PolarAxisGridFieldCacheInitializer,"Gfc2PolarAxisGrid",0)

Gfc2PolarAxisGrid::Gfc2PolarAxisGrid()
{
    m_nInsertPt = 0;
    m_dStartRadius = 0.0;
    m_bClockwise = false;
}

bool Gfc2PolarAxisGrid::isInitialized() const
{
    if ((_has_bits_[0] & 0xe5) != 0xe5) return false;

    return true;
}

int Gfc2PolarAxisGrid::typeId() const
{
    return 86;
}

glodon::objectbuf::EntitySchema* Gfc2PolarAxisGrid::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(86))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2AxisGrid::createSchema());
    pSchema->setName("Gfc2PolarAxisGrid");
    pSchema->setId(86);
    m_pDocument->addSchema(pSchema, 86);

    pSchema->addAttribNames("InsertPt");
    pSchema->addAttribIds(6);

    pSchema->addAttribNames("StartRadius");
    pSchema->addAttribIds(7);

    pSchema->addAttribNames("Clockwise");
    pSchema->addAttribIds(8);

    pSchema->addAttribNames("XKJ");
    pSchema->addAttribIds(9);

    pSchema->addAttribNames("ZJS");
    pSchema->addAttribIds(10);

    return pSchema;
}

std::string Gfc2PolarAxisGrid::entityName() const
{
    return "Gfc2PolarAxisGrid";
}

void Gfc2PolarAxisGridFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2PolarAxisGrid_InsertPt = getFieldId(oFieldIdMap, "Gfc2PolarAxisGrid::InsertPt");
    _FieldCache->_Gfc2PolarAxisGrid_StartRadius = getFieldId(oFieldIdMap, "Gfc2PolarAxisGrid::StartRadius");
    _FieldCache->_Gfc2PolarAxisGrid_Clockwise = getFieldId(oFieldIdMap, "Gfc2PolarAxisGrid::Clockwise");
    _FieldCache->_Gfc2PolarAxisGrid_XKJ = getFieldId(oFieldIdMap, "Gfc2PolarAxisGrid::XKJ");
    _FieldCache->_Gfc2PolarAxisGrid_ZJS = getFieldId(oFieldIdMap, "Gfc2PolarAxisGrid::ZJS");
}

