#include "StdAfx.h"
#include "Gfc2ExtrudedBody.h"
#include "Gfc2ExtrudedBodyBinarySerializer.h"
#include "Gfc2ExtrudedBodyTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2ExtrudedBody,"Gfc2ExtrudedBody",0)

OBJECTBUF_IMP_OBJECT(Gfc2ExtrudedBodyFieldCacheInitializer,"Gfc2ExtrudedBody",0)

Gfc2ExtrudedBody::Gfc2ExtrudedBody()
{
    m_nCoordinate = 0;
    m_dLength = 0.0;
    m_nSection = 0;
}

bool Gfc2ExtrudedBody::isInitialized() const
{
    if ((_has_bits_[0] & 0x7) != 0x7) return false;

    return true;
}

int Gfc2ExtrudedBody::typeId() const
{
    return 41;
}

glodon::objectbuf::EntitySchema* Gfc2ExtrudedBody::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(41))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Body::createSchema());
    pSchema->setName("Gfc2ExtrudedBody");
    pSchema->setId(41);
    m_pDocument->addSchema(pSchema, 41);

    pSchema->addAttribNames("Coordinate");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Length");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Section");
    pSchema->addAttribIds(3);

    return pSchema;
}

std::string Gfc2ExtrudedBody::entityName() const
{
    return "Gfc2ExtrudedBody";
}

void Gfc2ExtrudedBodyFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2ExtrudedBody_Coordinate = getFieldId(oFieldIdMap, "Gfc2ExtrudedBody::Coordinate");
    _FieldCache->_Gfc2ExtrudedBody_Length = getFieldId(oFieldIdMap, "Gfc2ExtrudedBody::Length");
    _FieldCache->_Gfc2ExtrudedBody_Section = getFieldId(oFieldIdMap, "Gfc2ExtrudedBody::Section");
}

