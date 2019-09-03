#include "StdAfx.h"
#include "Gfc2Cylinder.h"
#include "Gfc2CylinderBinarySerializer.h"
#include "Gfc2CylinderTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Cylinder,"Gfc2Cylinder",0)

OBJECTBUF_IMP_OBJECT(Gfc2CylinderFieldCacheInitializer,"Gfc2Cylinder",0)

Gfc2Cylinder::Gfc2Cylinder()
{
    m_nCoord = 0;
    m_nRangeV = 0;
    m_nCurve = 0;
}

bool Gfc2Cylinder::isInitialized() const
{
    if ((_has_bits_[0] & 0x7) != 0x7) return false;

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

    pSchema->addAttribNames("Coord");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("RangeV");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Curve");
    pSchema->addAttribIds(3);

    return pSchema;
}

std::string Gfc2Cylinder::entityName() const
{
    return "Gfc2Cylinder";
}

void Gfc2CylinderFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Cylinder_Coord = getFieldId(oFieldIdMap, "Gfc2Cylinder::Coord");
    _FieldCache->_Gfc2Cylinder_RangeV = getFieldId(oFieldIdMap, "Gfc2Cylinder::RangeV");
    _FieldCache->_Gfc2Cylinder_Curve = getFieldId(oFieldIdMap, "Gfc2Cylinder::Curve");
}

