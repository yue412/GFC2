#ifndef NGFC2CONNECTIONSURFACEGEOMETRY_H
#define NGFC2CONNECTIONSURFACEGEOMETRY_H

#include "NGfc2ConnectionGeometry.h"
#include "Gfc2ConnectionSurfaceGeometry.h"
#include "NGfc2Surface.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2ConnectionSurfaceGeometry: public NGfc2ConnectionGeometry
{
public:
    NGfc2ConnectionSurfaceGeometry();
    NGfc2ConnectionSurfaceGeometry(void* pEntity, bool bOwner);
    void setSurfaceOnRelatingElement(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getSurfaceOnRelatingElement();
    bool hasSurfaceOnRelatingElement();
    NGfc2Surface^ getSurfaceOnRelatingElementPtr();
    void setSurfaceOnRelatedElement(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getSurfaceOnRelatedElement();
    bool hasSurfaceOnRelatedElement();
    NGfc2Surface^ getSurfaceOnRelatedElementPtr();

};
#endif
