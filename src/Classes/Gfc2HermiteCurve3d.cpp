#include "StdAfx.h"
#include "Gfc2HermiteCurve3d.h"
#include "Gfc2HermiteCurve3dBinarySerializer.h"
#include "Gfc2HermiteCurve3dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2HermiteCurve3d,"Gfc2HermiteCurve3d",0)

OBJECTBUF_IMP_OBJECT(Gfc2HermiteCurve3dFieldCacheInitializer,"Gfc2HermiteCurve3d",0)

Gfc2HermiteCurve3d::Gfc2HermiteCurve3d()
{
}

bool Gfc2HermiteCurve3d::isInitialized() const
{

    return true;
}

int Gfc2HermiteCurve3d::typeId() const
{
    return 56;
}

glodon::objectbuf::EntitySchema* Gfc2HermiteCurve3d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(56))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Curve3d::createSchema());
    pSchema->setName("Gfc2HermiteCurve3d");
    pSchema->setId(56);
    m_pDocument->addSchema(pSchema, 56);

    pSchema->addAttribNames("CtrlPts");
    pSchema->addAttribIds(1);

    return pSchema;
}

std::string Gfc2HermiteCurve3d::entityName() const
{
    return "Gfc2HermiteCurve3d";
}

void Gfc2HermiteCurve3dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2HermiteCurve3d_CtrlPts = getFieldId(oFieldIdMap, "Gfc2HermiteCurve3d::CtrlPts");
}

