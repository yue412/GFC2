#include "StdAfx.h"
#include "Gfc2Plane.h"
#include "Gfc2PlaneBinarySerializer.h"
#include "Gfc2PlaneTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Plane,"Gfc2Plane",0)

OBJECTBUF_IMP_OBJECT(Gfc2PlaneFieldCacheInitializer,"Gfc2Plane",0)

Gfc2Plane::Gfc2Plane()
{
    m_nPos = 0;
    m_nDirU = 0;
    m_nDirV = 0;
    m_nRangeU = 0;
    m_nRangeV = 0;
}

bool Gfc2Plane::isInitialized() const
{
    if ((_has_bits_[0] & 0x1f) != 0x1f) return false;

    return true;
}

int Gfc2Plane::typeId() const
{
    return 78;
}

glodon::objectbuf::EntitySchema* Gfc2Plane::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(78))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Surface::createSchema());
    pSchema->setName("Gfc2Plane");
    pSchema->setId(78);
    m_pDocument->addSchema(pSchema, 78);

    pSchema->addAttribNames("Pos");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("DirU");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("DirV");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("RangeU");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("RangeV");
    pSchema->addAttribIds(5);

    return pSchema;
}

std::string Gfc2Plane::entityName() const
{
    return "Gfc2Plane";
}

void Gfc2PlaneFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Plane_Pos = getFieldId(oFieldIdMap, "Gfc2Plane::Pos");
    _FieldCache->_Gfc2Plane_DirU = getFieldId(oFieldIdMap, "Gfc2Plane::DirU");
    _FieldCache->_Gfc2Plane_DirV = getFieldId(oFieldIdMap, "Gfc2Plane::DirV");
    _FieldCache->_Gfc2Plane_RangeU = getFieldId(oFieldIdMap, "Gfc2Plane::RangeU");
    _FieldCache->_Gfc2Plane_RangeV = getFieldId(oFieldIdMap, "Gfc2Plane::RangeV");
}

