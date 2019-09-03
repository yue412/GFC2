#include "StdAfx.h"
#include "Gfc2FaceShape2d.h"
#include "Gfc2FaceShape2dBinarySerializer.h"
#include "Gfc2FaceShape2dTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2FaceShape2d,"Gfc2FaceShape2d",0)

OBJECTBUF_IMP_OBJECT(Gfc2FaceShape2dFieldCacheInitializer,"Gfc2FaceShape2d",0)

Gfc2FaceShape2d::Gfc2FaceShape2d()
{
    m_nPoly = 0;
}

bool Gfc2FaceShape2d::isInitialized() const
{
    if ((_has_bits_[0] & 0xd) != 0xd) return false;

    return true;
}

int Gfc2FaceShape2d::typeId() const
{
    return 47;
}

glodon::objectbuf::EntitySchema* Gfc2FaceShape2d::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(47))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Shape2d::createSchema());
    pSchema->setName("Gfc2FaceShape2d");
    pSchema->setId(47);
    m_pDocument->addSchema(pSchema, 47);

    pSchema->addAttribNames("Poly");
    pSchema->addAttribIds(4);

    return pSchema;
}

std::string Gfc2FaceShape2d::entityName() const
{
    return "Gfc2FaceShape2d";
}

void Gfc2FaceShape2dFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2FaceShape2d_Poly = getFieldId(oFieldIdMap, "Gfc2FaceShape2d::Poly");
}

