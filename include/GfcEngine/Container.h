#ifndef CONTAINER_H
#define CONTAINER_H

#include "GfcEngine\GfcEngine.h"
#include "GfcEngine\Iterator.h"
#include "Entity.h"

GFCENGINE_NAMESPACE_BEGIN

class EntityIterator;
typedef std::shared_ptr<Iterator<EntityPtr>> EntityIteratorPtr;

class GFCENGINE_API IContainer
{
public:
    virtual ~IContainer() {}
    virtual EntityPtr getEntity(EntityRef nId) = 0;
    virtual EntityIteratorPtr getEntities(const std::string& nType, bool bIncludeSubType = false) = 0;
    virtual EntityIteratorPtr getIterator() = 0;
};

GFCENGINE_NAMESPACE_END

#endif // !CONTAINER_H

