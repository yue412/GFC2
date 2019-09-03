#include "StdAfx.h"
#include "Gfc2SizeMark.h"
#include "Gfc2SizeMarkBinarySerializer.h"
#include "Gfc2SizeMarkTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2SizeMark,"Gfc2SizeMark",0)

OBJECTBUF_IMP_OBJECT(Gfc2SizeMarkFieldCacheInitializer,"Gfc2SizeMark",0)

Gfc2SizeMark::Gfc2SizeMark()
{
    m_nSizeMarkType = (Gfc2SizeMarkType)0;
    m_nStartLine = 0;
    m_nEndLine = 0;
}

bool Gfc2SizeMark::isInitialized() const
{
    if ((_has_bits_[0] & 0xe5) != 0xe5) return false;

    return true;
}

int Gfc2SizeMark::typeId() const
{
    return 118;
}

glodon::objectbuf::EntitySchema* Gfc2SizeMark::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(118))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Entity::createSchema());
    pSchema->setName("Gfc2SizeMark");
    pSchema->setId(118);
    m_pDocument->addSchema(pSchema, 118);

    pSchema->addAttribNames("SizeMarkType");
    pSchema->addAttribIds(6);

    pSchema->addAttribNames("StartLine");
    pSchema->addAttribIds(7);

    pSchema->addAttribNames("EndLine");
    pSchema->addAttribIds(8);

    return pSchema;
}

std::string Gfc2SizeMark::entityName() const
{
    return "Gfc2SizeMark";
}

void Gfc2SizeMarkFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2SizeMark_SizeMarkType = getFieldId(oFieldIdMap, "Gfc2SizeMark::SizeMarkType");
    _FieldCache->_Gfc2SizeMark_StartLine = getFieldId(oFieldIdMap, "Gfc2SizeMark::StartLine");
    _FieldCache->_Gfc2SizeMark_EndLine = getFieldId(oFieldIdMap, "Gfc2SizeMark::EndLine");
}

