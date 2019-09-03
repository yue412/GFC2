#include "StdAfx.h"
#include "Gfc2PolyhedralLoop.h"
#include "Gfc2PolyhedralLoopBinarySerializer.h"
#include "Gfc2PolyhedralLoopTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2PolyhedralLoop,"Gfc2PolyhedralLoop",0)

OBJECTBUF_IMP_OBJECT(Gfc2PolyhedralLoopFieldCacheInitializer,"Gfc2PolyhedralLoop",0)

Gfc2PolyhedralLoop::Gfc2PolyhedralLoop()
{
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2PolyhedralLoop::isInitialized() const
{

    return true;
}

int Gfc2PolyhedralLoop::typeId() const
{
    return 90;
}

glodon::objectbuf::EntitySchema* Gfc2PolyhedralLoop::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(90))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2PolyhedralLoop");
    pSchema->setId(90);
    m_pDocument->addSchema(pSchema, 90);

    pSchema->addAttribNames("Edges");
    pSchema->addAttribIds(1);

    return pSchema;
}

std::string Gfc2PolyhedralLoop::entityName() const
{
    return "Gfc2PolyhedralLoop";
}

void Gfc2PolyhedralLoopFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2PolyhedralLoop_Edges = getFieldId(oFieldIdMap, "Gfc2PolyhedralLoop::Edges");
}

