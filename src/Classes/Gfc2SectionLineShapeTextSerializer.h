#ifndef GFC2SECTIONLINESHAPETEXTSERIALIZER_H
#define GFC2SECTIONLINESHAPETEXTSERIALIZER_H

#include "Gfc2CustomLineShapeTextSerializer.h"

class Gfc2SectionLineShapeTextSerializer: public Gfc2CustomLineShapeTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2SectionLineShapeTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif
