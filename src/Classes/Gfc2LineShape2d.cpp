#include "StdAfx.h"
#include "Gfc2LineShape2d.h"
#include "Gfc2LineShape2dBinarySerializer.h"
#include "Gfc2LineShape2dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2LineShape2d,"Gfc2LineShape2d",0)

OBJECTBUF_IMP_OBJECT(Gfc2LineShape2dFieldCacheInitializer,"Gfc2LineShape2d",0)

Gfc2LineShape2d::Gfc2LineShape2d()
{
    m_nLine = 0;
}

bool Gfc2LineShape2d::isInitialized() const
{
    if ((_has_bits_[0] & 0xd) != 0xd) return false;

    return true;
}

int Gfc2LineShape2d::typeId() const
{
    return 67;
}

glodon::objectbuf::EntitySchema* Gfc2LineShape2d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(67))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Shape2d::createSchema());
    pSchema->setName("Gfc2LineShape2d");
    pSchema->setId(67);
    m_pDocument->addSchema(pSchema, 67);

    pSchema->addAttribNames("Line");
    pSchema->addAttribIds(4);

    return pSchema;
}

std::string Gfc2LineShape2d::entityName() const
{
    return "Gfc2LineShape2d";
}

void Gfc2LineShape2dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2LineShape2d_Line = getFieldId(oFieldIdMap, "Gfc2LineShape2d::Line");
}

