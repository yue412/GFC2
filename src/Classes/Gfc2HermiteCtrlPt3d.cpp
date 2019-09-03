#include "StdAfx.h"
#include "Gfc2HermiteCtrlPt3d.h"
#include "Gfc2HermiteCtrlPt3dBinarySerializer.h"
#include "Gfc2HermiteCtrlPt3dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2HermiteCtrlPt3d,"Gfc2HermiteCtrlPt3d",0)

OBJECTBUF_IMP_OBJECT(Gfc2HermiteCtrlPt3dFieldCacheInitializer,"Gfc2HermiteCtrlPt3d",0)

Gfc2HermiteCtrlPt3d::Gfc2HermiteCtrlPt3d()
{
    m_nPoint = 0;
    m_nTangent = 0;
    m_dParameter = 0.0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2HermiteCtrlPt3d::isInitialized() const
{
    if ((_has_bits_[0] & 0x7) != 0x7) return false;

    return true;
}

int Gfc2HermiteCtrlPt3d::typeId() const
{
    return 54;
}

glodon::objectbuf::EntitySchema* Gfc2HermiteCtrlPt3d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(54))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2HermiteCtrlPt3d");
    pSchema->setId(54);
    m_pDocument->addSchema(pSchema, 54);

    pSchema->addAttribNames("Point");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Tangent");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Parameter");
    pSchema->addAttribIds(3);

    return pSchema;
}

std::string Gfc2HermiteCtrlPt3d::entityName() const
{
    return "Gfc2HermiteCtrlPt3d";
}

void Gfc2HermiteCtrlPt3dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2HermiteCtrlPt3d_Point = getFieldId(oFieldIdMap, "Gfc2HermiteCtrlPt3d::Point");
    _FieldCache->_Gfc2HermiteCtrlPt3d_Tangent = getFieldId(oFieldIdMap, "Gfc2HermiteCtrlPt3d::Tangent");
    _FieldCache->_Gfc2HermiteCtrlPt3d_Parameter = getFieldId(oFieldIdMap, "Gfc2HermiteCtrlPt3d::Parameter");
}

