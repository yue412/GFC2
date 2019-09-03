#include "StdAfx.h"
#include "Gfc2HermiteCtrlPt2d.h"
#include "Gfc2HermiteCtrlPt2dBinarySerializer.h"
#include "Gfc2HermiteCtrlPt2dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2HermiteCtrlPt2d,"Gfc2HermiteCtrlPt2d",0)

OBJECTBUF_IMP_OBJECT(Gfc2HermiteCtrlPt2dFieldCacheInitializer,"Gfc2HermiteCtrlPt2d",0)

Gfc2HermiteCtrlPt2d::Gfc2HermiteCtrlPt2d()
{
    m_nPoint = 0;
    m_nTangent = 0;
    m_dParameter = 0.0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2HermiteCtrlPt2d::isInitialized() const
{
    if ((_has_bits_[0] & 0x7) != 0x7) return false;

    return true;
}

int Gfc2HermiteCtrlPt2d::typeId() const
{
    return 53;
}

glodon::objectbuf::EntitySchema* Gfc2HermiteCtrlPt2d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(53))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2HermiteCtrlPt2d");
    pSchema->setId(53);
    m_pDocument->addSchema(pSchema, 53);

    pSchema->addAttribNames("Point");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Tangent");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Parameter");
    pSchema->addAttribIds(3);

    return pSchema;
}

std::string Gfc2HermiteCtrlPt2d::entityName() const
{
    return "Gfc2HermiteCtrlPt2d";
}

void Gfc2HermiteCtrlPt2dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2HermiteCtrlPt2d_Point = getFieldId(oFieldIdMap, "Gfc2HermiteCtrlPt2d::Point");
    _FieldCache->_Gfc2HermiteCtrlPt2d_Tangent = getFieldId(oFieldIdMap, "Gfc2HermiteCtrlPt2d::Tangent");
    _FieldCache->_Gfc2HermiteCtrlPt2d_Parameter = getFieldId(oFieldIdMap, "Gfc2HermiteCtrlPt2d::Parameter");
}

