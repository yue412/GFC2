#include "StdAfx.h"
#include "Gfc2Line2d.h"
#include "Gfc2Line2dBinarySerializer.h"
#include "Gfc2Line2dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Line2d,"Gfc2Line2d",0)

OBJECTBUF_IMP_OBJECT(Gfc2Line2dFieldCacheInitializer,"Gfc2Line2d",0)

Gfc2Line2d::Gfc2Line2d()
{
    m_nStartPt = 0;
    m_nEndPt = 0;
}

bool Gfc2Line2d::isInitialized() const
{
    if ((_has_bits_[0] & 0x3) != 0x3) return false;

    return true;
}

int Gfc2Line2d::typeId() const
{
    return 63;
}

glodon::objectbuf::EntitySchema* Gfc2Line2d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(63))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Curve2d::createSchema());
    pSchema->setName("Gfc2Line2d");
    pSchema->setId(63);
    m_pDocument->addSchema(pSchema, 63);

    pSchema->addAttribNames("StartPt");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("EndPt");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2Line2d::entityName() const
{
    return "Gfc2Line2d";
}

void Gfc2Line2dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Line2d_StartPt = getFieldId(oFieldIdMap, "Gfc2Line2d::StartPt");
    _FieldCache->_Gfc2Line2d_EndPt = getFieldId(oFieldIdMap, "Gfc2Line2d::EndPt");
}

