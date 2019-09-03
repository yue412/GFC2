#include "StdAfx.h"
#include "Gfc2FaceConeInfo.h"
#include "Gfc2FaceConeInfoBinarySerializer.h"
#include "Gfc2FaceConeInfoTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2FaceConeInfo,"Gfc2FaceConeInfo",0)

OBJECTBUF_IMP_OBJECT(Gfc2FaceConeInfoFieldCacheInitializer,"Gfc2FaceConeInfo",0)

Gfc2FaceConeInfo::Gfc2FaceConeInfo()
{
    m_dHeight = 0.0;
    m_dChord = 0.0;
    m_nCenterPoint = 0;
    m_bCheckInnerChord = false;
}

bool Gfc2FaceConeInfo::isInitialized() const
{
    if ((_has_bits_[0] & 0xf) != 0xf) return false;

    return true;
}

int Gfc2FaceConeInfo::typeId() const
{
    return 44;
}

glodon::objectbuf::EntitySchema* Gfc2FaceConeInfo::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(44))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2FaceInfo::createSchema());
    pSchema->setName("Gfc2FaceConeInfo");
    pSchema->setId(44);
    m_pDocument->addSchema(pSchema, 44);

    pSchema->addAttribNames("Height");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Chord");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("CenterPoint");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("CheckInnerChord");
    pSchema->addAttribIds(4);

    return pSchema;
}

std::string Gfc2FaceConeInfo::entityName() const
{
    return "Gfc2FaceConeInfo";
}

void Gfc2FaceConeInfoFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2FaceConeInfo_Height = getFieldId(oFieldIdMap, "Gfc2FaceConeInfo::Height");
    _FieldCache->_Gfc2FaceConeInfo_Chord = getFieldId(oFieldIdMap, "Gfc2FaceConeInfo::Chord");
    _FieldCache->_Gfc2FaceConeInfo_CenterPoint = getFieldId(oFieldIdMap, "Gfc2FaceConeInfo::CenterPoint");
    _FieldCache->_Gfc2FaceConeInfo_CheckInnerChord = getFieldId(oFieldIdMap, "Gfc2FaceConeInfo::CheckInnerChord");
}

