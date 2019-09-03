#include "StdAfx.h"
#include "Gfc2NurbsCtrlPt2d.h"
#include "Gfc2NurbsCtrlPt2dBinarySerializer.h"
#include "Gfc2NurbsCtrlPt2dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2NurbsCtrlPt2d,"Gfc2NurbsCtrlPt2d",0)

OBJECTBUF_IMP_OBJECT(Gfc2NurbsCtrlPt2dFieldCacheInitializer,"Gfc2NurbsCtrlPt2d",0)

Gfc2NurbsCtrlPt2d::Gfc2NurbsCtrlPt2d()
{
    m_nPoint = 0;
    m_dWeight = 0.0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2NurbsCtrlPt2d::isInitialized() const
{
    if ((_has_bits_[0] & 0x3) != 0x3) return false;

    return true;
}

int Gfc2NurbsCtrlPt2d::typeId() const
{
    return 68;
}

glodon::objectbuf::EntitySchema* Gfc2NurbsCtrlPt2d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(68))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2NurbsCtrlPt2d");
    pSchema->setId(68);
    m_pDocument->addSchema(pSchema, 68);

    pSchema->addAttribNames("Point");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Weight");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2NurbsCtrlPt2d::entityName() const
{
    return "Gfc2NurbsCtrlPt2d";
}

void Gfc2NurbsCtrlPt2dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2NurbsCtrlPt2d_Point = getFieldId(oFieldIdMap, "Gfc2NurbsCtrlPt2d::Point");
    _FieldCache->_Gfc2NurbsCtrlPt2d_Weight = getFieldId(oFieldIdMap, "Gfc2NurbsCtrlPt2d::Weight");
}

