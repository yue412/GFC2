#include "StdAfx.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3dBinarySerializer.h"
#include "Gfc2Vector3dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Vector3d,"Gfc2Vector3d",0)

OBJECTBUF_IMP_OBJECT(Gfc2Vector3dFieldCacheInitializer,"Gfc2Vector3d",0)

Gfc2Vector3d::Gfc2Vector3d()
{
    m_dX = 0.0;
    m_dY = 0.0;
    m_dZ = 0.0;
}

bool Gfc2Vector3d::isInitialized() const
{
    if ((_has_bits_[0] & 0x7) != 0x7) return false;

    return true;
}

int Gfc2Vector3d::typeId() const
{
    return 137;
}

glodon::objectbuf::EntitySchema* Gfc2Vector3d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(137))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Geometry::createSchema());
    pSchema->setName("Gfc2Vector3d");
    pSchema->setId(137);
    m_pDocument->addSchema(pSchema, 137);

    pSchema->addAttribNames("X");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Y");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Z");
    pSchema->addAttribIds(3);

    return pSchema;
}

std::string Gfc2Vector3d::entityName() const
{
    return "Gfc2Vector3d";
}

void Gfc2Vector3dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Vector3d_X = getFieldId(oFieldIdMap, "Gfc2Vector3d::X");
    _FieldCache->_Gfc2Vector3d_Y = getFieldId(oFieldIdMap, "Gfc2Vector3d::Y");
    _FieldCache->_Gfc2Vector3d_Z = getFieldId(oFieldIdMap, "Gfc2Vector3d::Z");
}

