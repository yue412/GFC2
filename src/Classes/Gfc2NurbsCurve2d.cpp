#include "StdAfx.h"
#include "Gfc2NurbsCurve2d.h"
#include "Gfc2NurbsCurve2dBinarySerializer.h"
#include "Gfc2NurbsCurve2dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2NurbsCurve2d,"Gfc2NurbsCurve2d",0)

OBJECTBUF_IMP_OBJECT(Gfc2NurbsCurve2dFieldCacheInitializer,"Gfc2NurbsCurve2d",0)

Gfc2NurbsCurve2d::Gfc2NurbsCurve2d()
{
    m_nDegree = 0;
}

bool Gfc2NurbsCurve2d::isInitialized() const
{
    if ((_has_bits_[0] & 0x1) != 0x1) return false;

    return true;
}

int Gfc2NurbsCurve2d::typeId() const
{
    return 70;
}

glodon::objectbuf::EntitySchema* Gfc2NurbsCurve2d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(70))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Curve2d::createSchema());
    pSchema->setName("Gfc2NurbsCurve2d");
    pSchema->setId(70);
    m_pDocument->addSchema(pSchema, 70);

    pSchema->addAttribNames("Degree");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("CtrlPts");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Knots");
    pSchema->addAttribIds(3);

    return pSchema;
}

std::string Gfc2NurbsCurve2d::entityName() const
{
    return "Gfc2NurbsCurve2d";
}

void Gfc2NurbsCurve2dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2NurbsCurve2d_Degree = getFieldId(oFieldIdMap, "Gfc2NurbsCurve2d::Degree");
    _FieldCache->_Gfc2NurbsCurve2d_CtrlPts = getFieldId(oFieldIdMap, "Gfc2NurbsCurve2d::CtrlPts");
    _FieldCache->_Gfc2NurbsCurve2d_Knots = getFieldId(oFieldIdMap, "Gfc2NurbsCurve2d::Knots");
}

