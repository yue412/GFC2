#include "StdAfx.h"
#include "Gfc2CoedgeList.h"
#include "Gfc2CoedgeListBinarySerializer.h"
#include "Gfc2CoedgeListTextSerializer.h"

OBJECTBUF_IMP_OBJECT(Gfc2CoedgeList,"Gfc2CoedgeList",0)

OBJECTBUF_IMP_OBJECT(Gfc2CoedgeListFieldCacheInitializer,"Gfc2CoedgeList",0)

Gfc2CoedgeList::Gfc2CoedgeList()
{
}

bool Gfc2CoedgeList::isInitialized() const
{

    return true;
}

int Gfc2CoedgeList::typeId() const
{
    return 22;
}

glodon::objectbuf::EntitySchema* Gfc2CoedgeList::createSchema() const
{
    if (glodon::objectbuf::EntitySchema* pSchema = m_pDocument->findSchemaByID(22))
        return pSchema;

    glodon::objectbuf::EntitySchema* pSchema = new glodon::objectbuf::EntitySchema();
    pSchema->setParent(Gfc2Geometry::createSchema());
    pSchema->setName("Gfc2CoedgeList");
    pSchema->setId(22);
    m_pDocument->addSchema(pSchema, 22);

    pSchema->addAttribNames("Coedges");
    pSchema->addAttribIds(1);

    return pSchema;
}

std::string Gfc2CoedgeList::entityName() const
{
    return "Gfc2CoedgeList";
}

void Gfc2CoedgeListFieldCacheInitializer::init(const std::map<std::string, int>& oFieldIdMap)
{
    _FieldCache->_Gfc2CoedgeList_Coedges = getFieldId(oFieldIdMap, "Gfc2CoedgeList::Coedges");
}

