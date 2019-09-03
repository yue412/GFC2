#include "StdAfx.h"
#include "Gfc2FaceArchInfo.h"
#include "Gfc2FaceArchInfoBinarySerializer.h"
#include "Gfc2FaceArchInfoTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2FaceArchInfo,"Gfc2FaceArchInfo",0)

OBJECTBUF_IMP_OBJECT(Gfc2FaceArchInfoFieldCacheInitializer,"Gfc2FaceArchInfo",0)

Gfc2FaceArchInfo::Gfc2FaceArchInfo()
{
    m_nAxialLine = 0;
    m_dHeight = 0.0;
    m_dChord = 0.0;
    m_dRadius = 0.0;
    m_bDefineByRadius = false;
    m_bCheckInnerChord = false;
}

bool Gfc2FaceArchInfo::isInitialized() const
{
    if ((_has_bits_[0] & 0x3f) != 0x3f) return false;

    return true;
}

int Gfc2FaceArchInfo::typeId() const
{
    return 43;
}

glodon::objectbuf::EntitySchema* Gfc2FaceArchInfo::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(43))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2FaceInfo::createSchema());
    pSchema->setName("Gfc2FaceArchInfo");
    pSchema->setId(43);
    m_pDocument->addSchema(pSchema, 43);

    pSchema->addAttribNames("AxialLine");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Height");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Chord");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("Radius");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("DefineByRadius");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("CheckInnerChord");
    pSchema->addAttribIds(6);

    return pSchema;
}

std::string Gfc2FaceArchInfo::entityName() const
{
    return "Gfc2FaceArchInfo";
}

void Gfc2FaceArchInfoFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2FaceArchInfo_AxialLine = getFieldId(oFieldIdMap, "Gfc2FaceArchInfo::AxialLine");
    _FieldCache->_Gfc2FaceArchInfo_Height = getFieldId(oFieldIdMap, "Gfc2FaceArchInfo::Height");
    _FieldCache->_Gfc2FaceArchInfo_Chord = getFieldId(oFieldIdMap, "Gfc2FaceArchInfo::Chord");
    _FieldCache->_Gfc2FaceArchInfo_Radius = getFieldId(oFieldIdMap, "Gfc2FaceArchInfo::Radius");
    _FieldCache->_Gfc2FaceArchInfo_DefineByRadius = getFieldId(oFieldIdMap, "Gfc2FaceArchInfo::DefineByRadius");
    _FieldCache->_Gfc2FaceArchInfo_CheckInnerChord = getFieldId(oFieldIdMap, "Gfc2FaceArchInfo::CheckInnerChord");
}

