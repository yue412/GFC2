#include "StdAfx.h"
#include "Gfc2FaceShape.h"
#include "Gfc2FaceShapeBinarySerializer.h"
#include "Gfc2FaceShapeTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2FaceShape,"Gfc2FaceShape",0)

OBJECTBUF_IMP_OBJECT(Gfc2FaceShapeFieldCacheInitializer,"Gfc2FaceShape",0)

Gfc2FaceShape::Gfc2FaceShape()
{
    m_dThickness = 0.0;
    m_nPoly = 0;
    m_bMirrorFlag = false;
    m_nFaceInfo = 0;
}

bool Gfc2FaceShape::isInitialized() const
{
    if ((_has_bits_[0] & 0x31) != 0x31) return false;

    return true;
}

int Gfc2FaceShape::typeId() const
{
    return 46;
}

glodon::objectbuf::EntitySchema* Gfc2FaceShape::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(46))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2SolidShape::createSchema());
    pSchema->setName("Gfc2FaceShape");
    pSchema->setId(46);
    m_pDocument->addSchema(pSchema, 46);

    pSchema->addAttribNames("Thickness");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("Poly");
    pSchema->addAttribIds(6);

    pSchema->addAttribNames("MirrorFlag");
    pSchema->addAttribIds(7);

    pSchema->addAttribNames("FaceInfo");
    pSchema->addAttribIds(8);

    return pSchema;
}

std::string Gfc2FaceShape::entityName() const
{
    return "Gfc2FaceShape";
}

void Gfc2FaceShapeFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2FaceShape_Thickness = getFieldId(oFieldIdMap, "Gfc2FaceShape::Thickness");
    _FieldCache->_Gfc2FaceShape_Poly = getFieldId(oFieldIdMap, "Gfc2FaceShape::Poly");
    _FieldCache->_Gfc2FaceShape_MirrorFlag = getFieldId(oFieldIdMap, "Gfc2FaceShape::MirrorFlag");
    _FieldCache->_Gfc2FaceShape_FaceInfo = getFieldId(oFieldIdMap, "Gfc2FaceShape::FaceInfo");
}

