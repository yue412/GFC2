#include "StdAfx.h"
#include "Gfc2NurbsCtrlPt3d.h"
#include "Gfc2NurbsCtrlPt3dBinarySerializer.h"
#include "Gfc2NurbsCtrlPt3dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2NurbsCtrlPt3d,"Gfc2NurbsCtrlPt3d",0)

OBJECTBUF_IMP_OBJECT(Gfc2NurbsCtrlPt3dFieldCacheInitializer,"Gfc2NurbsCtrlPt3d",0)

Gfc2NurbsCtrlPt3d::Gfc2NurbsCtrlPt3d()
{
    m_nPoint = 0;
    m_dWeight = 0.0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2NurbsCtrlPt3d::isInitialized() const
{
    if ((_has_bits_[0] & 0x3) != 0x3) return false;

    return true;
}

int Gfc2NurbsCtrlPt3d::typeId() const
{
    return 69;
}

glodon::objectbuf::EntitySchema* Gfc2NurbsCtrlPt3d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(69))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2NurbsCtrlPt3d");
    pSchema->setId(69);
    m_pDocument->addSchema(pSchema, 69);

    pSchema->addAttribNames("Point");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Weight");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2NurbsCtrlPt3d::entityName() const
{
    return "Gfc2NurbsCtrlPt3d";
}

void Gfc2NurbsCtrlPt3dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2NurbsCtrlPt3d_Point = getFieldId(oFieldIdMap, "Gfc2NurbsCtrlPt3d::Point");
    _FieldCache->_Gfc2NurbsCtrlPt3d_Weight = getFieldId(oFieldIdMap, "Gfc2NurbsCtrlPt3d::Weight");
}

