#include "StdAfx.h"
#include "Gfc2Face.h"
#include "Gfc2FaceBinarySerializer.h"
#include "Gfc2FaceTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2Face,"Gfc2Face",0)

OBJECTBUF_IMP_OBJECT(Gfc2FaceFieldCacheInitializer,"Gfc2Face",0)

Gfc2Face::Gfc2Face()
{
    m_nSurface = 0;
    m_nBox = 0;
    m_bSameDir = false;
    m_nIndex = 0;
}

bool Gfc2Face::isInitialized() const
{
    if ((_has_bits_[0] & 0x1e) != 0x1e) return false;

    return true;
}

int Gfc2Face::typeId() const
{
    return 42;
}

glodon::objectbuf::EntitySchema* Gfc2Face::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(42))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2CommonPolygonEx::createSchema());
    pSchema->setName("Gfc2Face");
    pSchema->setId(42);
    m_pDocument->addSchema(pSchema, 42);

    pSchema->addAttribNames("Surface");
    pSchema->addAttribIds(2);

    pSchema->addAttribNames("Box");
    pSchema->addAttribIds(3);

    pSchema->addAttribNames("SameDir");
    pSchema->addAttribIds(4);

    pSchema->addAttribNames("Index");
    pSchema->addAttribIds(5);

    return pSchema;
}

std::string Gfc2Face::entityName() const
{
    return "Gfc2Face";
}

void Gfc2FaceFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2Face_Surface = getFieldId(oFieldIdMap, "Gfc2Face::Surface");
    _FieldCache->_Gfc2Face_Box = getFieldId(oFieldIdMap, "Gfc2Face::Box");
    _FieldCache->_Gfc2Face_SameDir = getFieldId(oFieldIdMap, "Gfc2Face::SameDir");
    _FieldCache->_Gfc2Face_Index = getFieldId(oFieldIdMap, "Gfc2Face::Index");
}

