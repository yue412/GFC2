#include "StdAfx.h"
#include "Gfc2PolyhedralFace.h"
#include "Gfc2PolyhedralFaceBinarySerializer.h"
#include "Gfc2PolyhedralFaceTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2PolyhedralFace,"Gfc2PolyhedralFace",0)

OBJECTBUF_IMP_OBJECT(Gfc2PolyhedralFaceFieldCacheInitializer,"Gfc2PolyhedralFace",0)

Gfc2PolyhedralFace::Gfc2PolyhedralFace()
{
    m_nPlane = 0;
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2PolyhedralFace::isInitialized() const
{
    if ((_has_bits_[0] & 0x2) != 0x2) return false;

    return true;
}

int Gfc2PolyhedralFace::typeId() const
{
    return 89;
}

glodon::objectbuf::EntitySchema* Gfc2PolyhedralFace::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(89))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2PolyhedralFace");
    pSchema->setId(89);
    m_pDocument->addSchema(pSchema, 89);

    pSchema->addAttribNames("Loops");
    pSchema->addAttribIds(1);

    pSchema->addAttribNames("Plane");
    pSchema->addAttribIds(2);

    return pSchema;
}

std::string Gfc2PolyhedralFace::entityName() const
{
    return "Gfc2PolyhedralFace";
}

void Gfc2PolyhedralFaceFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2PolyhedralFace_Loops = getFieldId(oFieldIdMap, "Gfc2PolyhedralFace::Loops");
    _FieldCache->_Gfc2PolyhedralFace_Plane = getFieldId(oFieldIdMap, "Gfc2PolyhedralFace::Plane");
}

