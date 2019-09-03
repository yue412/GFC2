#ifndef GFC2ELLIPSE3D_H
#define GFC2ELLIPSE3D_H

#include "GfcClasses.h"
#include "Gfc2PlaneCurve3d.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2Ellipse3d: public Gfc2PlaneCurve3d
{
OBJECTBUF_DEC_OBJECT(Gfc2Ellipse3d,glodon::objectbuf::Entity)
public:
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;

};
#endif
