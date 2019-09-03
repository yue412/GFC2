#include "StdAfx.h"
#include "Gfc2SimpleLoop.h"
#include "Gfc2SimpleLoopBinarySerializer.h"
#include "Gfc2SimpleLoopTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2SimpleLoop,"Gfc2SimpleLoop",0)

OBJECTBUF_IMP_OBJECT(Gfc2SimpleLoopFieldCacheInitializer,"Gfc2SimpleLoop",0)

Gfc2SimpleLoop::Gfc2SimpleLoop()
{
    memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Gfc2SimpleLoop::isInitialized() const
{

    return true;
}

int Gfc2SimpleLoop::typeId() const
{
    return 114;
}

glodon::objectbuf::EntitySchema* Gfc2SimpleLoop::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(114))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(glodon::objectbuf::Entity::createSchema());
    pSchema->setName("Gfc2SimpleLoop");
    pSchema->setId(114);
    m_pDocument->addSchema(pSchema, 114);

    pSchema->addAttribNames("Vertexes");
    pSchema->addAttribIds(1);

    return pSchema;
}

std::string Gfc2SimpleLoop::entityName() const
{
    return "Gfc2SimpleLoop";
}

void Gfc2SimpleLoopFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2SimpleLoop_Vertexes = getFieldId(oFieldIdMap, "Gfc2SimpleLoop::Vertexes");
}

