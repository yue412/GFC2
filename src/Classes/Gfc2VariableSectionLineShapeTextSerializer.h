#ifndef GFC2VARIABLESECTIONLINESHAPETEXTSERIALIZER_H
#define GFC2VARIABLESECTIONLINESHAPETEXTSERIALIZER_H

#include "Gfc2SectionLineShapeTextSerializer.h"

class Gfc2VariableSectionLineShapeTextSerializer: public Gfc2SectionLineShapeTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2VariableSectionLineShapeTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif
