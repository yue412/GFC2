#include "StdAfx.h"
#include "Gfc2HermiteCurve2d.h"
#include "Gfc2HermiteCurve2dBinarySerializer.h"
#include "Gfc2HermiteCurve2dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2HermiteCurve2d,"Gfc2HermiteCurve2d",0)

OBJECTBUF_IMP_OBJECT(Gfc2HermiteCurve2dFieldCacheInitializer,"Gfc2HermiteCurve2d",0)

Gfc2HermiteCurve2d::Gfc2HermiteCurve2d()
{
}

bool Gfc2HermiteCurve2d::isInitialized() const
{

    return true;
}

int Gfc2HermiteCurve2d::typeId() const
{
    return 55;
}

glodon::objectbuf::EntitySchema* Gfc2HermiteCurve2d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(55))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Curve2d::createSchema());
    pSchema->setName("Gfc2HermiteCurve2d");
    pSchema->setId(55);
    m_pDocument->addSchema(pSchema, 55);

    pSchema->addAttribNames("CtrlPts");
    pSchema->addAttribIds(1);

    return pSchema;
}

std::string Gfc2HermiteCurve2d::entityName() const
{
    return "Gfc2HermiteCurve2d";
}

void Gfc2HermiteCurve2dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2HermiteCurve2d_CtrlPts = getFieldId(oFieldIdMap, "Gfc2HermiteCurve2d::CtrlPts");
}

