#include "StdAfx.h"
#include "Gfc2Box3d.h"
#include "Gfc2Box3dBinarySerializer.h"
#include "Gfc2Box3dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Box3d,"Gfc2Box3d",0)

OBJECTBUF_IMP_OBJECT(Gfc2Box3dFieldCacheInitializer,"Gfc2Box3d",0)

Gfc2Box3d::Gfc2Box3d()
{
    m_nMin = 0;
    m_nMax = 0;
}

bool Gfc2Box3d::isInitialized() const
{
    if ((_has_bits_[0] & 0x3) != 0x3) return false;

    return true;
}

int Gfc2Box3d::typeId() const
{
    return 15;
}

glodon::objectbuf::EntitySchema* Gfc2Box3d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(15))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Geometry::createSchema());
    pSchema->setName("Gfc2Box3d");
    pSchema->setId(15);
    m_pDocument->addSchema(pSchema, 15);

    pSchema->addAttribNames("Min");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Max");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2Box3d::entityName() const
{
    return "Gfc2Box3d";
}

void Gfc2Box3dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Box3d_Min = getFieldId(oFieldIdMap, "Gfc2Box3d::Min");
    _FieldCache->_Gfc2Box3d_Max = getFieldId(oFieldIdMap, "Gfc2Box3d::Max");
}

