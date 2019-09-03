#include "StdAfx.h"
#include "Gfc2PlaneInfo.h"
#include "Gfc2PlaneInfoBinarySerializer.h"
#include "Gfc2PlaneInfoTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2PlaneInfo,"Gfc2PlaneInfo",0)

OBJECTBUF_IMP_OBJECT(Gfc2PlaneInfoFieldCacheInitializer,"Gfc2PlaneInfo",0)

Gfc2PlaneInfo::Gfc2PlaneInfo()
{
    m_nDirX = 0;
    m_nDirY = 0;
    m_nPos = 0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2PlaneInfo::isInitialized() const
{
    if ((_has_bits_[0] & 0x7) != 0x7) return false;

    return true;
}

int Gfc2PlaneInfo::typeId() const
{
    return 81;
}

glodon::objectbuf::EntitySchema* Gfc2PlaneInfo::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(81))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2PlaneInfo");
    pSchema->setId(81);
    m_pDocument->addSchema(pSchema, 81);

    pSchema->addAttribNames("DirX");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("DirY");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Pos");
    pSchema->addAttribIds(3);

    return pSchema;
}

std::string Gfc2PlaneInfo::entityName() const
{
    return "Gfc2PlaneInfo";
}

void Gfc2PlaneInfoFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2PlaneInfo_DirX = getFieldId(oFieldIdMap, "Gfc2PlaneInfo::DirX");
    _FieldCache->_Gfc2PlaneInfo_DirY = getFieldId(oFieldIdMap, "Gfc2PlaneInfo::DirY");
    _FieldCache->_Gfc2PlaneInfo_Pos = getFieldId(oFieldIdMap, "Gfc2PlaneInfo::Pos");
}

