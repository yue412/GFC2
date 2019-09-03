#include "StdAfx.h"
#include "Gfc2InternalPt.h"
#include "Gfc2InternalPtBinarySerializer.h"
#include "Gfc2InternalPtTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2InternalPt,"Gfc2InternalPt",0)

OBJECTBUF_IMP_OBJECT(Gfc2InternalPtFieldCacheInitializer,"Gfc2InternalPt",0)

Gfc2InternalPt::Gfc2InternalPt()
{
    m_nP = 0;
    m_nTVec = 0;
    m_dT = 0.0;
    m_nUV = 0;
    m_nST = 0;
    m_nUVDir = 0;
    m_nSTDir = 0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2InternalPt::isInitialized() const
{
    if ((_has_bits_[0] & 0x7f) != 0x7f) return false;

    return true;
}

int Gfc2InternalPt::typeId() const
{
    return 60;
}

glodon::objectbuf::EntitySchema* Gfc2InternalPt::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(60))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2InternalPt");
    pSchema->setId(60);
    m_pDocument->addSchema(pSchema, 60);

    pSchema->addAttribNames("P");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("TVec");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("T");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("UV");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("ST");
    pSchema->addAttribIds(5);

    pSchema->addAttribNames("UVDir");
    pSchema->addAttribIds(6);

    pSchema->addAttribNames("STDir");
    pSchema->addAttribIds(7);

    return pSchema;
}

std::string Gfc2InternalPt::entityName() const
{
    return "Gfc2InternalPt";
}

void Gfc2InternalPtFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2InternalPt_P = getFieldId(oFieldIdMap, "Gfc2InternalPt::P");
    _FieldCache->_Gfc2InternalPt_TVec = getFieldId(oFieldIdMap, "Gfc2InternalPt::TVec");
    _FieldCache->_Gfc2InternalPt_T = getFieldId(oFieldIdMap, "Gfc2InternalPt::T");
    _FieldCache->_Gfc2InternalPt_UV = getFieldId(oFieldIdMap, "Gfc2InternalPt::UV");
    _FieldCache->_Gfc2InternalPt_ST = getFieldId(oFieldIdMap, "Gfc2InternalPt::ST");
    _FieldCache->_Gfc2InternalPt_UVDir = getFieldId(oFieldIdMap, "Gfc2InternalPt::UVDir");
    _FieldCache->_Gfc2InternalPt_STDir = getFieldId(oFieldIdMap, "Gfc2InternalPt::STDir");
}

