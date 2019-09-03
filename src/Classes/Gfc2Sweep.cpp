#include "StdAfx.h"
#include "Gfc2Sweep.h"
#include "Gfc2SweepBinarySerializer.h"
#include "Gfc2SweepTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Sweep,"Gfc2Sweep",0)

OBJECTBUF_IMP_OBJECT(Gfc2SweepFieldCacheInitializer,"Gfc2Sweep",0)

Gfc2Sweep::Gfc2Sweep()
{
    m_nProfile = 0;
    m_nSpine3d = 0;
    m_nReferenceVector = 0;
}

bool Gfc2Sweep::isInitialized() const
{
    if ((_has_bits_[0] & 0x7) != 0x7) return false;

    return true;
}

int Gfc2Sweep::typeId() const
{
    return 130;
}

glodon::objectbuf::EntitySchema* Gfc2Sweep::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(130))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Surface::createSchema());
    pSchema->setName("Gfc2Sweep");
    pSchema->setId(130);
    m_pDocument->addSchema(pSchema, 130);

    pSchema->addAttribNames("Profile");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Spine3d");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("ReferenceVector");
    pSchema->addAttribIds(3);

    return pSchema;
}

std::string Gfc2Sweep::entityName() const
{
    return "Gfc2Sweep";
}

void Gfc2SweepFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Sweep_Profile = getFieldId(oFieldIdMap, "Gfc2Sweep::Profile");
    _FieldCache->_Gfc2Sweep_Spine3d = getFieldId(oFieldIdMap, "Gfc2Sweep::Spine3d");
    _FieldCache->_Gfc2Sweep_ReferenceVector = getFieldId(oFieldIdMap, "Gfc2Sweep::ReferenceVector");
}

