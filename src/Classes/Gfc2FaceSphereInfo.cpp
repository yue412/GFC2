#include "StdAfx.h"
#include "Gfc2FaceSphereInfo.h"
#include "Gfc2FaceSphereInfoBinarySerializer.h"
#include "Gfc2FaceSphereInfoTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2FaceSphereInfo,"Gfc2FaceSphereInfo",0)

OBJECTBUF_IMP_OBJECT(Gfc2FaceSphereInfoFieldCacheInitializer,"Gfc2FaceSphereInfo",0)

Gfc2FaceSphereInfo::Gfc2FaceSphereInfo()
{
    m_nCenterPoint = 0;
    m_dHeight = 0.0;
    m_dChord = 0.0;
    m_bCheckInnerChord = false;
}

bool Gfc2FaceSphereInfo::isInitialized() const
{
    if ((_has_bits_[0] & 0xf) != 0xf) return false;

    return true;
}

int Gfc2FaceSphereInfo::typeId() const
{
    return 48;
}

glodon::objectbuf::EntitySchema* Gfc2FaceSphereInfo::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(48))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2FaceInfo::createSchema());
    pSchema->setName("Gfc2FaceSphereInfo");
    pSchema->setId(48);
    m_pDocument->addSchema(pSchema, 48);

    pSchema->addAttribNames("CenterPoint");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Height");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Chord");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("CheckInnerChord");
    pSchema->addAttribIds(4);

    return pSchema;
}

std::string Gfc2FaceSphereInfo::entityName() const
{
    return "Gfc2FaceSphereInfo";
}

void Gfc2FaceSphereInfoFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2FaceSphereInfo_CenterPoint = getFieldId(oFieldIdMap, "Gfc2FaceSphereInfo::CenterPoint");
    _FieldCache->_Gfc2FaceSphereInfo_Height = getFieldId(oFieldIdMap, "Gfc2FaceSphereInfo::Height");
    _FieldCache->_Gfc2FaceSphereInfo_Chord = getFieldId(oFieldIdMap, "Gfc2FaceSphereInfo::Chord");
    _FieldCache->_Gfc2FaceSphereInfo_CheckInnerChord = getFieldId(oFieldIdMap, "Gfc2FaceSphereInfo::CheckInnerChord");
}

