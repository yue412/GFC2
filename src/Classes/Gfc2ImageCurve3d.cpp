#include "StdAfx.h"
#include "Gfc2ImageCurve3d.h"
#include "Gfc2ImageCurve3dBinarySerializer.h"
#include "Gfc2ImageCurve3dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2ImageCurve3d,"Gfc2ImageCurve3d",0)

OBJECTBUF_IMP_OBJECT(Gfc2ImageCurve3dFieldCacheInitializer,"Gfc2ImageCurve3d",0)

Gfc2ImageCurve3d::Gfc2ImageCurve3d()
{
    m_nCurve = 0;
    m_nSurface = 0;
}

bool Gfc2ImageCurve3d::isInitialized() const
{
    if ((_has_bits_[0] & 0x3) != 0x3) return false;

    return true;
}

int Gfc2ImageCurve3d::typeId() const
{
    return 57;
}

glodon::objectbuf::EntitySchema* Gfc2ImageCurve3d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(57))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Curve3d::createSchema());
    pSchema->setName("Gfc2ImageCurve3d");
    pSchema->setId(57);
    m_pDocument->addSchema(pSchema, 57);

    pSchema->addAttribNames("Curve");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Surface");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2ImageCurve3d::entityName() const
{
    return "Gfc2ImageCurve3d";
}

void Gfc2ImageCurve3dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2ImageCurve3d_Curve = getFieldId(oFieldIdMap, "Gfc2ImageCurve3d::Curve");
    _FieldCache->_Gfc2ImageCurve3d_Surface = getFieldId(oFieldIdMap, "Gfc2ImageCurve3d::Surface");
}

