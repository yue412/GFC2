#ifndef GFC2PARALLELASSITAXISTEXTSERIALIZER_H
#define GFC2PARALLELASSITAXISTEXTSERIALIZER_H

#include "Gfc2AssitAxisTextSerializer.h"

class Gfc2ParallelAssitAxisTextSerializer: public Gfc2AssitAxisTextSerializer
{
OBJECTBUF_DEC_OBJECT(Gfc2ParallelAssitAxisTextSerializer,glodon::objectbuf::EntitySerializer)
public:
    virtual std::string serialize(glodon::objectbuf::Entity* pEntity) const;

protected:
    virtual glodon::objectbuf::EnParseFieldState parseField(const std::string& input, int nFieldNum, glodon::objectbuf::Entity* pEntity);

};
#endif