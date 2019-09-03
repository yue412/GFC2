#include "StdAfx.h"
#include "Gfc2Sphere.h"
#include "Gfc2SphereBinarySerializer.h"
#include "Gfc2SphereTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Sphere,"Gfc2Sphere",0)

OBJECTBUF_IMP_OBJECT(Gfc2SphereFieldCacheInitializer,"Gfc2Sphere",0)

Gfc2Sphere::Gfc2Sphere()
{
    m_dRadius = 0.0;
    m_nCoords = 0;
    m_nRangeU = 0;
    m_nRangeV = 0;
}

bool Gfc2Sphere::isInitialized() const
{
    if ((_has_bits_[0] & 0xf) != 0xf) return false;

    return true;
}

int Gfc2Sphere::typeId() const
{
    return 121;
}

glodon::objectbuf::EntitySchema* Gfc2Sphere::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(121))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Surface::createSchema());
    pSchema->setName("Gfc2Sphere");
    pSchema->setId(121);
    m_pDocument->addSchema(pSchema, 121);

    pSchema->addAttribNames("Radius");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Coords");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("RangeU");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("RangeV");
    pSchema->addAttribIds(4);

    return pSchema;
}

std::string Gfc2Sphere::entityName() const
{
    return "Gfc2Sphere";
}

void Gfc2SphereFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Sphere_Radius = getFieldId(oFieldIdMap, "Gfc2Sphere::Radius");
    _FieldCache->_Gfc2Sphere_Coords = getFieldId(oFieldIdMap, "Gfc2Sphere::Coords");
    _FieldCache->_Gfc2Sphere_RangeU = getFieldId(oFieldIdMap, "Gfc2Sphere::RangeU");
    _FieldCache->_Gfc2Sphere_RangeV = getFieldId(oFieldIdMap, "Gfc2Sphere::RangeV");
}

