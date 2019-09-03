#include "StdAfx.h"
#include "Gfc2Representation.h"
#include "Gfc2RepresentationBinarySerializer.h"
#include "Gfc2RepresentationTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Representation,"Gfc2Representation",0)

OBJECTBUF_IMP_OBJECT(Gfc2RepresentationFieldCacheInitializer,"Gfc2Representation",0)

Gfc2Representation::Gfc2Representation()
{
    m_nIdentifier = 0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2Representation::isInitialized() const
{
    if ((_has_bits_[0] & 0x1) != 0x1) return false;

    return true;
}

int Gfc2Representation::typeId() const
{
    return 105;
}

glodon::objectbuf::EntitySchema* Gfc2Representation::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(105))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2Representation");
    pSchema->setId(105);
    m_pDocument->addSchema(pSchema, 105);

    pSchema->addAttribNames("Identifier");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("items");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2Representation::entityName() const
{
    return "Gfc2Representation";
}

void Gfc2RepresentationFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Representation_Identifier = getFieldId(oFieldIdMap, "Gfc2Representation::Identifier");
    _FieldCache->_Gfc2Representation_items = getFieldId(oFieldIdMap, "Gfc2Representation::items");
}

