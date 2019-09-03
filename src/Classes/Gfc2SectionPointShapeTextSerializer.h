#ifndef GFC2SECTIONPOINTSHAPETEXTSERIALIZER_H
#define GFC2SECTIONPOINTSHAPETEXTSERIALIZER_H

#include "Gfc2CustomPointShapeTextSerializer.h"

class Gfc2SectionPointShapeTextSerializer: public Gfc2CustomPointShapeTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2SectionPointShapeTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif
