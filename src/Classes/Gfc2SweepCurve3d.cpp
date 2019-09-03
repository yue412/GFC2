#include "StdAfx.h"
#include "Gfc2SweepCurve3d.h"
#include "Gfc2SweepCurve3dBinarySerializer.h"
#include "Gfc2SweepCurve3dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2SweepCurve3d,"Gfc2SweepCurve3d",0)

OBJECTBUF_IMP_OBJECT(Gfc2SweepCurve3dFieldCacheInitializer,"Gfc2SweepCurve3d",0)

Gfc2SweepCurve3d::Gfc2SweepCurve3d()
{
    m_nSpine3d = 0;
    m_nReferenceVector = 0;
    m_nPoint = 0;
}

bool Gfc2SweepCurve3d::isInitialized() const
{
    if ((_has_bits_[0] & 0x7) != 0x7) return false;

    return true;
}

int Gfc2SweepCurve3d::typeId() const
{
    return 131;
}

glodon::objectbuf::EntitySchema* Gfc2SweepCurve3d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(131))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Curve3d::createSchema());
    pSchema->setName("Gfc2SweepCurve3d");
    pSchema->setId(131);
    m_pDocument->addSchema(pSchema, 131);

    pSchema->addAttribNames("Spine3d");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("ReferenceVector");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Point");
    pSchema->addAttribIds(3);

    return pSchema;
}

std::string Gfc2SweepCurve3d::entityName() const
{
    return "Gfc2SweepCurve3d";
}

void Gfc2SweepCurve3dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2SweepCurve3d_Spine3d = getFieldId(oFieldIdMap, "Gfc2SweepCurve3d::Spine3d");
    _FieldCache->_Gfc2SweepCurve3d_ReferenceVector = getFieldId(oFieldIdMap, "Gfc2SweepCurve3d::ReferenceVector");
    _FieldCache->_Gfc2SweepCurve3d_Point = getFieldId(oFieldIdMap, "Gfc2SweepCurve3d::Point");
}

