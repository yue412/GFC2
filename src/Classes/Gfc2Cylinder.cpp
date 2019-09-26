#include "StdAfx.h"
#include "Gfc2Cylinder.h"
#include "Gfc2CylinderBinarySerializer.h"
#include "Gfc2CylinderTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Cylinder,"Gfc2Cylinder",0)

OBJECTBUF_IMP_OBJECT(Gfc2CylinderFieldCacheInitializer,"Gfc2Cylinder",0)

Gfc2Cylinder::Gfc2Cylinder()
{
    m_nRangeV = 0;
    m_nCurve = 0;
    m_nDirX = 0;
    m_nDirY = 0;
    m_nDirZ = 0;
    m_nPos = 0;
}

bool Gfc2Cylinder::isInitialized() const
{
    if ((_has_bits_[0] & 0x3f) != 0x3f) return false;

    return true;
}

int Gfc2Cylinder::typeId() const
{
    return 33;
}

glodon::objectbuf::EntitySchema* Gfc2Cylinder::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(33))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Surface::createSchema());
    pSchema->setName("Gfc2Cylinder");
    pSchema->setId(33);
    m_pDocument->addSchema(pSchema, 33);

    pSchema->addAttribNames("RangeV");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Curve");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("DirX");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("DirY");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("DirZ");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("Pos");
    pSchema->addAttribIds(6);

    return pSchema;
}

std::string Gfc2Cylinder::entityName() const
{
    return "Gfc2Cylinder";
}

void Gfc2CylinderFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Cylinder_RangeV = getFieldId(oFieldIdMap, "Gfc2Cylinder::RangeV");
    _FieldCache->_Gfc2Cylinder_Curve = getFieldId(oFieldIdMap, "Gfc2Cylinder::Curve");
    _FieldCache->_Gfc2Cylinder_DirX = getFieldId(oFieldIdMap, "Gfc2Cylinder::DirX");
    _FieldCache->_Gfc2Cylinder_DirY = getFieldId(oFieldIdMap, "Gfc2Cylinder::DirY");
    _FieldCache->_Gfc2Cylinder_DirZ = getFieldId(oFieldIdMap, "Gfc2Cylinder::DirZ");
    _FieldCache->_Gfc2Cylinder_Pos = getFieldId(oFieldIdMap, "Gfc2Cylinder::Pos");
}

