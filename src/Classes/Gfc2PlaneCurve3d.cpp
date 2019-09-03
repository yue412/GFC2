#include "StdAfx.h"
#include "Gfc2PlaneCurve3d.h"
#include "Gfc2PlaneCurve3dBinarySerializer.h"
#include "Gfc2PlaneCurve3dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2PlaneCurve3d,"Gfc2PlaneCurve3d",0)

OBJECTBUF_IMP_OBJECT(Gfc2PlaneCurve3dFieldCacheInitializer,"Gfc2PlaneCurve3d",0)

Gfc2PlaneCurve3d::Gfc2PlaneCurve3d()
{
    m_nPlaneCurve = 0;
    m_nPlane = 0;
}

bool Gfc2PlaneCurve3d::isInitialized() const
{
    if ((_has_bits_[0] & 0x3) != 0x3) return false;

    return true;
}

int Gfc2PlaneCurve3d::typeId() const
{
    return 80;
}

glodon::objectbuf::EntitySchema* Gfc2PlaneCurve3d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(80))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Curve3d::createSchema());
    pSchema->setName("Gfc2PlaneCurve3d");
    pSchema->setId(80);
    m_pDocument->addSchema(pSchema, 80);

    pSchema->addAttribNames("PlaneCurve");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Plane");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2PlaneCurve3d::entityName() const
{
    return "Gfc2PlaneCurve3d";
}

void Gfc2PlaneCurve3dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2PlaneCurve3d_PlaneCurve = getFieldId(oFieldIdMap, "Gfc2PlaneCurve3d::PlaneCurve");
    _FieldCache->_Gfc2PlaneCurve3d_Plane = getFieldId(oFieldIdMap, "Gfc2PlaneCurve3d::Plane");
}

