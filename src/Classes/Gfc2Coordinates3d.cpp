#include "StdAfx.h"
#include "Gfc2Coordinates3d.h"
#include "Gfc2Coordinates3dBinarySerializer.h"
#include "Gfc2Coordinates3dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Coordinates3d,"Gfc2Coordinates3d",0)

OBJECTBUF_IMP_OBJECT(Gfc2Coordinates3dFieldCacheInitializer,"Gfc2Coordinates3d",0)

Gfc2Coordinates3d::Gfc2Coordinates3d()
{
    m_nOrigin = 0;
    m_nX = 0;
    m_nY = 0;
    m_nZ = 0;
}

bool Gfc2Coordinates3d::isInitialized() const
{
    if ((_has_bits_[0] & 0xf) != 0xf) return false;

    return true;
}

int Gfc2Coordinates3d::typeId() const
{
    return 27;
}

glodon::objectbuf::EntitySchema* Gfc2Coordinates3d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(27))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Geometry::createSchema());
    pSchema->setName("Gfc2Coordinates3d");
    pSchema->setId(27);
    m_pDocument->addSchema(pSchema, 27);

    pSchema->addAttribNames("Origin");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("X");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Y");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("Z");
    pSchema->addAttribIds(4);

    return pSchema;
}

std::string Gfc2Coordinates3d::entityName() const
{
    return "Gfc2Coordinates3d";
}

void Gfc2Coordinates3dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Coordinates3d_Origin = getFieldId(oFieldIdMap, "Gfc2Coordinates3d::Origin");
    _FieldCache->_Gfc2Coordinates3d_X = getFieldId(oFieldIdMap, "Gfc2Coordinates3d::X");
    _FieldCache->_Gfc2Coordinates3d_Y = getFieldId(oFieldIdMap, "Gfc2Coordinates3d::Y");
    _FieldCache->_Gfc2Coordinates3d_Z = getFieldId(oFieldIdMap, "Gfc2Coordinates3d::Z");
}

