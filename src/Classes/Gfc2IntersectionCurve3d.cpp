#include "StdAfx.h"
#include "Gfc2IntersectionCurve3d.h"
#include "Gfc2IntersectionCurve3dBinarySerializer.h"
#include "Gfc2IntersectionCurve3dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2IntersectionCurve3d,"Gfc2IntersectionCurve3d",0)

OBJECTBUF_IMP_OBJECT(Gfc2IntersectionCurve3dFieldCacheInitializer,"Gfc2IntersectionCurve3d",0)

Gfc2IntersectionCurve3d::Gfc2IntersectionCurve3d()
{
    m_nBases1 = 0;
    m_nBases2 = 0;
    m_nRange = 0;
    m_nChart = 0;
}

bool Gfc2IntersectionCurve3d::isInitialized() const
{
    if ((_has_bits_[0] & 0xf) != 0xf) return false;

    return true;
}

int Gfc2IntersectionCurve3d::typeId() const
{
    return 61;
}

glodon::objectbuf::EntitySchema* Gfc2IntersectionCurve3d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(61))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Curve3d::createSchema());
    pSchema->setName("Gfc2IntersectionCurve3d");
    pSchema->setId(61);
    m_pDocument->addSchema(pSchema, 61);

    pSchema->addAttribNames("Bases1");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Bases2");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Range");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("Chart");
    pSchema->addAttribIds(4);

    return pSchema;
}

std::string Gfc2IntersectionCurve3d::entityName() const
{
    return "Gfc2IntersectionCurve3d";
}

void Gfc2IntersectionCurve3dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2IntersectionCurve3d_Bases1 = getFieldId(oFieldIdMap, "Gfc2IntersectionCurve3d::Bases1");
    _FieldCache->_Gfc2IntersectionCurve3d_Bases2 = getFieldId(oFieldIdMap, "Gfc2IntersectionCurve3d::Bases2");
    _FieldCache->_Gfc2IntersectionCurve3d_Range = getFieldId(oFieldIdMap, "Gfc2IntersectionCurve3d::Range");
    _FieldCache->_Gfc2IntersectionCurve3d_Chart = getFieldId(oFieldIdMap, "Gfc2IntersectionCurve3d::Chart");
}

