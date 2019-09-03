#include "StdAfx.h"
#include "Gfc2NurbsCurve3d.h"
#include "Gfc2NurbsCurve3dBinarySerializer.h"
#include "Gfc2NurbsCurve3dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2NurbsCurve3d,"Gfc2NurbsCurve3d",0)

OBJECTBUF_IMP_OBJECT(Gfc2NurbsCurve3dFieldCacheInitializer,"Gfc2NurbsCurve3d",0)

Gfc2NurbsCurve3d::Gfc2NurbsCurve3d()
{
    m_nDegree = 0;
}

bool Gfc2NurbsCurve3d::isInitialized() const
{
    if ((_has_bits_[0] & 0x1) != 0x1) return false;

    return true;
}

int Gfc2NurbsCurve3d::typeId() const
{
    return 71;
}

glodon::objectbuf::EntitySchema* Gfc2NurbsCurve3d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(71))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Curve3d::createSchema());
    pSchema->setName("Gfc2NurbsCurve3d");
    pSchema->setId(71);
    m_pDocument->addSchema(pSchema, 71);

    pSchema->addAttribNames("Degree");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("CtrlPts");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Knots");
    pSchema->addAttribIds(3);

    return pSchema;
}

std::string Gfc2NurbsCurve3d::entityName() const
{
    return "Gfc2NurbsCurve3d";
}

void Gfc2NurbsCurve3dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2NurbsCurve3d_Degree = getFieldId(oFieldIdMap, "Gfc2NurbsCurve3d::Degree");
    _FieldCache->_Gfc2NurbsCurve3d_CtrlPts = getFieldId(oFieldIdMap, "Gfc2NurbsCurve3d::CtrlPts");
    _FieldCache->_Gfc2NurbsCurve3d_Knots = getFieldId(oFieldIdMap, "Gfc2NurbsCurve3d::Knots");
}

