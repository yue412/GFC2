#include "StdAfx.h"
#include "Gfc2Line3d.h"
#include "Gfc2Line3dBinarySerializer.h"
#include "Gfc2Line3dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Line3d,"Gfc2Line3d",0)

OBJECTBUF_IMP_OBJECT(Gfc2Line3dFieldCacheInitializer,"Gfc2Line3d",0)

Gfc2Line3d::Gfc2Line3d()
{
    m_nStartPt = 0;
    m_nEndPt = 0;
}

bool Gfc2Line3d::isInitialized() const
{
    if ((_has_bits_[0] & 0x3) != 0x3) return false;

    return true;
}

int Gfc2Line3d::typeId() const
{
    return 64;
}

glodon::objectbuf::EntitySchema* Gfc2Line3d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(64))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Curve3d::createSchema());
    pSchema->setName("Gfc2Line3d");
    pSchema->setId(64);
    m_pDocument->addSchema(pSchema, 64);

    pSchema->addAttribNames("StartPt");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("EndPt");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2Line3d::entityName() const
{
    return "Gfc2Line3d";
}

void Gfc2Line3dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Line3d_StartPt = getFieldId(oFieldIdMap, "Gfc2Line3d::StartPt");
    _FieldCache->_Gfc2Line3d_EndPt = getFieldId(oFieldIdMap, "Gfc2Line3d::EndPt");
}

