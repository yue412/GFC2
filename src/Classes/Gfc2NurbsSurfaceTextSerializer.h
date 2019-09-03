#ifndef GFC2NURBSSURFACETEXTSERIALIZER_H
#define GFC2NURBSSURFACETEXTSERIALIZER_H

#include "Gfc2SurfaceTextSerializer.h"

class Gfc2NurbsSurfaceTextSerializer: public Gfc2SurfaceTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2NurbsSurfaceTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif
