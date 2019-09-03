#include "StdAfx.h"
#include "Gfc2StateSet.h"
#include "Gfc2StateSetBinarySerializer.h"
#include "Gfc2StateSetTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2StateSet,"Gfc2StateSet",0)

OBJECTBUF_IMP_OBJECT(Gfc2StateSetFieldCacheInitializer,"Gfc2StateSet",0)

Gfc2StateSet::Gfc2StateSet()
{
    m_nAmbient = 0;
    m_nDiffuse = 0;
    m_nSourceBlendFactor = (Gfc2SceneBlendFactor)0;
    m_nDestBlendFactor = (Gfc2SceneBlendFactor)0;
    m_bDepthTestEnabled = false;
    m_bDepthWriteEnabled = false;
    m_nDepthTestFunction = (Gfc2FragTestFunc)0;
    m_dPolygonOffsetFactor = 0.0;
    m_dPolygonOffsetUnits = 0.0;
    m_nPolygonStipple = 0;
    m_nLineStipplePattern = 0;
    m_nLineStippleFactor = 0;
    m_nFaceMode = (Gfc2FaceMode)0;
    m_bLightingEnabled = false;
    m_bLightModelTwoSided = false;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2StateSet::isInitialized() const
{
    if ((_has_bits_[0] & 0x7fff) != 0x7fff) return false;

    return true;
}

int Gfc2StateSet::typeId() const
{
    return 124;
}

glodon::objectbuf::EntitySchema* Gfc2StateSet::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(124))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2StateSet");
    pSchema->setId(124);
    m_pDocument->addSchema(pSchema, 124);

    pSchema->addAttribNames("Ambient");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Diffuse");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("SourceBlendFactor");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("DestBlendFactor");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("DepthTestEnabled");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("DepthWriteEnabled");
    pSchema->addAttribIds(6);

    pSchema->addAttribNames("DepthTestFunction");
    pSchema->addAttribIds(7);

    pSchema->addAttribNames("PolygonOffsetFactor");
    pSchema->addAttribIds(8);

    pSchema->addAttribNames("PolygonOffsetUnits");
    pSchema->addAttribIds(9);

    pSchema->addAttribNames("PolygonStipple");
    pSchema->addAttribIds(10);

    pSchema->addAttribNames("LineStipplePattern");
    pSchema->addAttribIds(11);

    pSchema->addAttribNames("LineStippleFactor");
    pSchema->addAttribIds(12);

    pSchema->addAttribNames("FaceMode");
    pSchema->addAttribIds(13);

    pSchema->addAttribNames("LightingEnabled");
    pSchema->addAttribIds(14);

    pSchema->addAttribNames("LightModelTwoSided");
    pSchema->addAttribIds(15);

    return pSchema;
}

std::string Gfc2StateSet::entityName() const
{
    return "Gfc2StateSet";
}

void Gfc2StateSetFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2StateSet_Ambient = getFieldId(oFieldIdMap, "Gfc2StateSet::Ambient");
    _FieldCache->_Gfc2StateSet_Diffuse = getFieldId(oFieldIdMap, "Gfc2StateSet::Diffuse");
    _FieldCache->_Gfc2StateSet_SourceBlendFactor = getFieldId(oFieldIdMap, "Gfc2StateSet::SourceBlendFactor");
    _FieldCache->_Gfc2StateSet_DestBlendFactor = getFieldId(oFieldIdMap, "Gfc2StateSet::DestBlendFactor");
    _FieldCache->_Gfc2StateSet_DepthTestEnabled = getFieldId(oFieldIdMap, "Gfc2StateSet::DepthTestEnabled");
    _FieldCache->_Gfc2StateSet_DepthWriteEnabled = getFieldId(oFieldIdMap, "Gfc2StateSet::DepthWriteEnabled");
    _FieldCache->_Gfc2StateSet_DepthTestFunction = getFieldId(oFieldIdMap, "Gfc2StateSet::DepthTestFunction");
    _FieldCache->_Gfc2StateSet_PolygonOffsetFactor = getFieldId(oFieldIdMap, "Gfc2StateSet::PolygonOffsetFactor");
    _FieldCache->_Gfc2StateSet_PolygonOffsetUnits = getFieldId(oFieldIdMap, "Gfc2StateSet::PolygonOffsetUnits");
    _FieldCache->_Gfc2StateSet_PolygonStipple = getFieldId(oFieldIdMap, "Gfc2StateSet::PolygonStipple");
    _FieldCache->_Gfc2StateSet_LineStipplePattern = getFieldId(oFieldIdMap, "Gfc2StateSet::LineStipplePattern");
    _FieldCache->_Gfc2StateSet_LineStippleFactor = getFieldId(oFieldIdMap, "Gfc2StateSet::LineStippleFactor");
    _FieldCache->_Gfc2StateSet_FaceMode = getFieldId(oFieldIdMap, "Gfc2StateSet::FaceMode");
    _FieldCache->_Gfc2StateSet_LightingEnabled = getFieldId(oFieldIdMap, "Gfc2StateSet::LightingEnabled");
    _FieldCache->_Gfc2StateSet_LightModelTwoSided = getFieldId(oFieldIdMap, "Gfc2StateSet::LightModelTwoSided");
}

